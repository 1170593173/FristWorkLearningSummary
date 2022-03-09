#设置cmake版本号
cmake_minimum_required(VERSION 3.4.0)

# remove last end of "/"
string(REGEX REPLACE "/$" "" CURRENT_FOLDER_ABSOLUTE ${CMAKE_CURRENT_SOURCE_DIR})

# get current relative dir name and set target name
string(REGEX REPLACE ".*/(.*)" "\\1" CURRENT_FOLDER ${CURRENT_FOLDER_ABSOLUTE})
set (TARGET_NAME ${CURRENT_FOLDER})

project (${TARGET_NAME})

SET(PRODUCT_NAME ${TARGET_NAME})

#设置工程包含当前目录，非必须
set(CMAKE_INCLUDE_CURRENT_DIR ON) 

#设置自动生成moc文件，一定要设置
set(CMAKE_AUTOMOC ON) 

#查找需要的Qt库文件，最好每一个库都要写，Qt也会根据依赖关系自动添加
find_package(Qt5Widgets)  
find_package(Qt5Core)
find_package(Qt5Gui)

#查找当前文件夹中的所有源代码文件，也可以通过Set命令将所有文件设置为一个变量
FILE(GLOB SRC_FILES "./*.cpp") 
#同理，查找当前文件夹中所有的头文件
FILE(GLOB HEAD_FILES "./*.h") 
#同理，查找当前文件夹中所有的ui文件
FILE(GLOB UI_FILES "./*.ui") 

#通过Ui文件生成对应的头文件，一定要添加
qt5_wrap_ui(WRAP_FILES ${UI_FILES})

#添加资源文件
##set(RCC_FILES rcc.qrc)

#将ui文件和生成文件整理在一个文件夹中，非必须
source_group("Ui" FILES ${UI_FILES} ${WRAP_FILES} )

#创建工程文件
##add_executable(${PROJECT_NAME} ${SRC_FILES} ${HEAD_FILES} ${RCC_FILES} ${WRAP_FILES})
add_executable(${PROJECT_NAME} ${SRC_FILES} ${HEAD_FILES} ${WRAP_FILES})

#添加Qt5依赖项
target_link_libraries(${PROJECT_NAME} Qt5::Widgets Qt5::Core Qt5::Gui)