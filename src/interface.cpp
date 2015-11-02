#include "opencv_line_detection.h"

extern "C" {
void* getInstance () {
    return new OpencvLineDetection();
}
}
