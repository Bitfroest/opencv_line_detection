#include "opencv_line_detection.h"
#include <lms/imaging/converter.h>

bool OpencvLineDetection::initialize() {
    //get the default config
    config = getConfig();


    image = datamanager()->readChannel<lms::imaging::Image>(this,"IMAGE");
    outputImage = datamanager()->writeChannel<lms::imaging::Image>(this,"WINDOW_IMAGE");

    return true;
}

bool OpencvLineDetection::deinitialize() {
    return true;
}

bool OpencvLineDetection::cycle() {

    cv::Mat imagen = image->convertToOpenCVMat();
    cv::Mat roiImg;
    cv::Rect roi(0, 380, 640, 100);
    imagen(roi).copyTo(roiImg);
    cv::blur(roiImg, edge, cv::Size(3,3));

    // Run the edge detector on grayscale
    cv::Canny(edge, edge, edgeThresh, edgeThresh*3, 3);
    cedge = cv::Scalar::all(0);

    roiImg.copyTo(cedge, edge);
    cv_utils::croppResizeCentered(cedge,640,100);
    double thresh = 100;
    //cv::threshold(cedge,cedge,thresh,255,0);

    std::vector<std::vector<cv::Point> > contours;
    std::vector<cv::Vec4i> hierarchy;
    cv::RNG rng(12345);

    findContours( cedge, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, cv::Point(0, 0) );

    cv::Mat drawing = cv::Mat::zeros( cedge.size(), CV_8UC3 );
    cv::cvtColor(roiImg, roiImg, CV_GRAY2RGB);
      for( int i = 0; i< contours.size(); i++ )
         {
           //set colors
           cv::Scalar color = cv::Scalar( rng.uniform(0, 255), rng.uniform(0,255), rng.uniform(0,255) );

           //draw different contours
           cv::drawContours( drawing, contours, i, color, 2, 8, hierarchy, 0, cv::Point() );

           //Approximate Poly Lines with Douglas Peucker alg
           cv::approxPolyDP(cv::Mat(contours[i]), contours[i], 10, true);
            logger.info("line_detection")<< "Points:";
           for(unsigned int j=0;j<contours[i].size();j++)
              {
              logger.info("line_detection") << "Point(x,y)=" << contours[i][j].x << "," << contours[i][j].y;
              //draw circles
              cv::circle( roiImg, contours[i][j], 3, cv::Scalar(0,0,255), cv::FILLED, cv::LINE_AA );
              }

         }






    cv::imshow("blaasd",drawing);
    cv::waitKey(1);
    cv::imshow("bla",roiImg);
    cv::waitKey(1);
    return true;
}
