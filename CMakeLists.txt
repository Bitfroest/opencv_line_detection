set(SOURCES
    "src/opencv_line_detection.cpp"
    "src/interface.cpp"
)

set(HEADERS
    "include/opencv_line_detection.h"
)

include_directories(include)
add_library(opencv_line_detection MODULE ${SOURCES} ${HEADERS})
target_link_libraries(opencv_line_detection PRIVATE lmscore)
