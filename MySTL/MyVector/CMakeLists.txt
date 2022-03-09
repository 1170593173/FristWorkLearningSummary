cmake_minimum_required (VERSION 2.6)
project (DecoratorMode)

set (TestCmake_VERSION_MAHOR 1)
set (TestCMake_VERSION_MINOR 0)

configure_file(
    "${PROJECT_SOURCE_DIR}/Version.h.in"
    "${PROJECT_SOURCE_DIR}/Version.h"
)

##add_library(MathFunctions MathFunctions.cpp)

include_directories("${PROJECT_BINARY_DIR}")
include_directories("${PROJECT_SOURCE_DIR}")
##add_subdirectory(MathFunctions)


FILE(GLOB SC_FILES "*.cpp" "*.h")


add_executable(${PROJECT_NAME} ${SC_FILES})
##target_link_libraries(TestCmake MathFunctions)

