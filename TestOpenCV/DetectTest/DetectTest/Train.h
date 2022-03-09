#pragma once

#ifndef _TRAIN_H
#define _TRAIN_H
#include <iostream>
#include <opencv.hpp>
#include <iostream>
#include <sstream>
#include <fstream>




using namespace std;
using namespace cv;

class Train
{
public:
	Train(std::string txtpath);
	~Train();
	void read_csv();
private:
	std::string csvPath = "E:\\性别识别数据库—CAS-PEAL\\at.txt";
	std::vector<cv::Mat> images;
	std::vector<int> labels;

};
#endif /* _TRAIN_H */

