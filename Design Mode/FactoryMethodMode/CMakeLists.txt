cmake_minimum_required (VERSION 2.6)

# remove last end of "/"
string(REGEX REPLACE "/$" "" CURRENT_FOLDER_ABSOLUTE ${CMAKE_CURRENT_SOURCE_DIR})

# get current relative dir name and set target name
string(REGEX REPLACE ".*/(.*)" "\\1" CURRENT_FOLDER ${CURRENT_FOLDER_ABSOLUTE})
set (TARGET_NAME ${CURRENT_FOLDER})

project (${TARGET_NAME})

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
#add_executable(TestCMake main.cpp BeDescription.h BeDescription.cpp BeDescripDrinks.h BeDescripDrinks.cpp Descriptions.h Descriptions.cpp Drinks.h Drinks.cpp)
##target_link_libraries(TestCmake MathFunctions)

