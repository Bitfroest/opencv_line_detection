#ifndef OPENCV_LINE_DETECTION_H
#define OPENCV_LINE_DETECTION_H

#include <lms/datamanager.h>
#include <lms/module.h>

class OpencvLineDetection : public lms::Module {
public:
    bool initialize();
    bool deinitialize();
    bool cycle();
};

#endif // OPENCV_LINE_DETECTION_H
