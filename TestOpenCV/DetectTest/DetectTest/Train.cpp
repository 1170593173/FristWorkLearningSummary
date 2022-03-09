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
	ifstream file(csvPath.c_str(), ifstream::in);    //�Զ���ķ�ʽ���ļ�
	string line, path, label;
	while (getline(file, line))                       //���ı��ļ��ж�ȡһ���ַ���δָ���޶���Ĭ���޶���Ϊ��/n��
	{
		stringstream lines(line);
		getline(lines, path, separator);               //����ָ���ָ�����зָ��Ϊ��·��+��š�
		getline(lines, label);
		if (!path.empty() && !label.empty())           //�����ȡ�ɹ�����ͼƬ�Ͷ�Ӧ��ǩѹ���Ӧ������ 
		{
			images.push_back(imread(path, 0));        //��ȡѵ������
			labels.push_back(atoi(label.c_str()));   //��ȡѵ���������
		}
	}

	//Ptr<FaceRecognizer> modelPCA = createEigenFaceRecognizer();
	Ptr<FaceRecognizer> modelPCA = EigenFaceRecognizer::create();
	modelPCA->train(images, labels);
	modelPCA->save("E:\\�Ա�ʶ�����ݿ⡪CAS-PEAL\\PCA_Model.xml");

	//Ptr<FaceRecognizer> modelFisher = createFisherFaceRecognizer();
	//modelFisher->train(images, labels);
	//modelFisher->save("E:\\�Ա�ʶ�����ݿ⡪CAS-PEAL\\Fisher_Model.xml");

	//Ptr<FaceRecognizer> modelLBP = createLBPHFaceRecognizer();
	//modelLBP->train(images, labels);
	//modelLBP->save("E:\\�Ա�ʶ�����ݿ⡪CAS-PEAL\\LBP_Model.xml");

	//Ptr<FaceRecognizer> modelPCA = createEigenFaceRecognizer();
	//Ptr<FaceRecognizer> modelFisher = createFisherFaceRecognizer();
	//Ptr<FaceRecognizer> modelLBP = createLBPHFaceRecognizer();

	Mat img;
	modelPCA->read("D:\\OpenCV\\MyFacePCAModel.xml");
	modelPCA->predict(img);
	//modelFisher->load("E:\\�Ա�ʶ�����ݿ⡪CAS-PEAL\\Fisher_Model.xml");
	//modelLBP->load("E:\\�Ա�ʶ�����ݿ⡪CAS-PEAL\\LBP_Model.xml");

	Mat testImage = imread("E:\\�Ա�ʶ�����ݿ⡪CAS-PEAL\\��������\\���Բ�������\\face_480.bmp", 0);
	int predictPCA = modelPCA->predict(testImage);
	//int predictLBP = modelLBP->predict(testImage);
	//int predictFisher = modelFisher->predict(testImage);




}


