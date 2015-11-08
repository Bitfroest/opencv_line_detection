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
    cv::blur(imagen, edge, cv::Size(3,3));

    // Run the edge detector on grayscale
    cv::Canny(edge, edge, edgeThresh, edgeThresh*3, 3);
    cedge = cv::Scalar::all(0);

    imagen.copyTo(cedge, edge);
    cv_utils::croppResizeCentered(cedge,640,480);
    cv::imshow("bla",cedge);
    cv::waitKey(1);
    return true;
}
