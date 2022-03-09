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
	std::string csvPath = "E:\\�Ա�ʶ�����ݿ⡪CAS-PEAL\\at.txt";
	std::vector<cv::Mat> images;
	std::vector<int> labels;

};
#endif /* _TRAIN_H */

