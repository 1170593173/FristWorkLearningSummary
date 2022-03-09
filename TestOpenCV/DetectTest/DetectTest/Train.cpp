#include "Train.h"
//#include <opencv2/objdetect/detection_based_tracker.hpp>
#include <opencv2/core.hpp>
#include <opencv2/face/include/opencv2/face.hpp>
using namespace cv::face;

Train::Train(string txt)
{
	csvPath = txt;
}


Train::~Train()
{
}

void Train::read_csv()
{
	char separator = ' ';
	ifstream file(csvPath.c_str(), ifstream::in);    //以读入的方式打开文件
	string line, path, label;
	while (getline(file, line))                       //从文本文件中读取一行字符，未指定限定符默认限定符为“/n”
	{
		stringstream lines(line);
		getline(lines, path, separator);               //根据指定分割符进行分割，分为“路径+标号”
		getline(lines, label);
		if (!path.empty() && !label.empty())           //如果读取成功，则将图片和对应标签压入对应容器中 
		{
			images.push_back(imread(path, 0));        //读取训练样本
			labels.push_back(atoi(label.c_str()));   //读取训练样本标号
		}
	}

	//Ptr<FaceRecognizer> modelPCA = createEigenFaceRecognizer();
	Ptr<FaceRecognizer> modelPCA = EigenFaceRecognizer::create();
	modelPCA->train(images, labels);
	modelPCA->save("E:\\性别识别数据库—CAS-PEAL\\PCA_Model.xml");

	//Ptr<FaceRecognizer> modelFisher = createFisherFaceRecognizer();
	//modelFisher->train(images, labels);
	//modelFisher->save("E:\\性别识别数据库—CAS-PEAL\\Fisher_Model.xml");

	//Ptr<FaceRecognizer> modelLBP = createLBPHFaceRecognizer();
	//modelLBP->train(images, labels);
	//modelLBP->save("E:\\性别识别数据库—CAS-PEAL\\LBP_Model.xml");

	//Ptr<FaceRecognizer> modelPCA = createEigenFaceRecognizer();
	//Ptr<FaceRecognizer> modelFisher = createFisherFaceRecognizer();
	//Ptr<FaceRecognizer> modelLBP = createLBPHFaceRecognizer();

	Mat img;
	modelPCA->read("D:\\OpenCV\\MyFacePCAModel.xml");
	modelPCA->predict(img);
	//modelFisher->load("E:\\性别识别数据库—CAS-PEAL\\Fisher_Model.xml");
	//modelLBP->load("E:\\性别识别数据库—CAS-PEAL\\LBP_Model.xml");

	Mat testImage = imread("E:\\性别识别数据库—CAS-PEAL\\测试样本\\男性测试样本\\face_480.bmp", 0);
	int predictPCA = modelPCA->predict(testImage);
	//int predictLBP = modelLBP->predict(testImage);
	//int predictFisher = modelFisher->predict(testImage);




}


