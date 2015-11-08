#ifndef OPENCV_LINE_DETECTION_H
#define OPENCV_LINE_DETECTION_H

#include <lms/datamanager.h>
#include <lms/module.h>
#include <lms/imaging/image.h>
#include "lms/module_config.h"
#include "opencv2/opencv.hpp"

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

    cv::Mat edge, cedge;
    int edgeThresh = 1;
};

#endif // OPENCV_LINE_DETECTION_H
