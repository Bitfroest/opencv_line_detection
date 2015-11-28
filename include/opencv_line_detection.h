#ifndef OPENCV_LINE_DETECTION_H
#define OPENCV_LINE_DETECTION_H

#include <lms/datamanager.h>
#include <lms/module.h>
#include <lms/imaging/image.h>
#include "lms/module_config.h"
#include "opencv2/opencv.hpp"

#include "opencv2/core/utility.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"

#include <stdio.h>

#include <opencv_utils.h>

class OpencvLineDetection : public lms::Module {
public:
    bool initialize();
    bool deinitialize();
    bool cycle();
    const lms::ModuleConfig *config;
    /**
     * @brief image the image to work with
     */
    const lms::imaging::Image* image;
    lms::imaging::Image *outputImage;
    cv::Mat edge, cedge;
    int edgeThresh = 100;
};

#endif // OPENCV_LINE_DETECTION_H
