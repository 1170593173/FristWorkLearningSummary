#include "detecttest.h"
#include <QtWidgets/QApplication>
#include <opencv.hpp>
#include <iostream>
#include "Train.h"
using namespace std;
using namespace cv;
CascadeClassifier faceCascade;
CascadeClassifier eyes_Cascade;

void DetectFace(Mat, Mat);


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	DetectTest w;
	w.show();

	Train *test = new Train("test");

	test->read_csv();
	//Mat I = imread("C://Users//chuck.liu//Desktop//HTTPS.png");
	//imshow("test", I);
	//waitKey();
	VideoCapture cap;
	if (!cap.open(0)) {
		cout << "摄像头打开失败!!" << endl;
		return -1;
	}

	if (!faceCascade.load("E:\\OpenCV_3.4.1\\opencv\\sources\\data\\haarcascades_cuda\\haarcascade_frontalface_alt2.xml")) {
		cout << "人脸检测级联分类器没找到！！" << endl;
		return -1;
	}

	if (!eyes_Cascade.load("E:\\OpenCV_3.4.1\\opencv\\sources\\data\\haarcascades_cuda\\haarcascade_eye_tree_eyeglasses.xml")) {
		cout << "眼睛检测级联分类器没找到！！" << endl;
		return -1;
	}
	Mat img, imgGray;
	int fps = 120;
	while (true) {
		cap >> img;
		cvtColor(img, imgGray, CV_BGR2GRAY);
		equalizeHist(imgGray, imgGray);//直方图均匀化
		DetectFace(img, imgGray);
		waitKey(1000 / fps);
	}

	return a.exec();
}

void DetectFace(Mat img, Mat imgGray) {
	namedWindow("src", WINDOW_AUTOSIZE);
	vector<Rect> faces, eyes;
	faceCascade.detectMultiScale(imgGray, faces, 1.2, 5, 0, Size(30, 30));
	for (auto b : faces) {
		cout << "输出一张人脸位置：(x,y):" << "(" << b.x << "," << b.y << ") , (width,height):(" << b.width << "," << b.height << ")" << endl;
	}
	if (faces.size() > 0) {
		for (size_t i = 0; i < faces.size(); i++) {
			putText(img, "ugly girl!", cvPoint(faces[i].x, faces[i].y - 10), FONT_HERSHEY_PLAIN, 2.0, Scalar(0, 0, 255));

			rectangle(img, Point(faces[i].x, faces[i].y), Point(faces[i].x + faces[i].width, faces[i].y + faces[i].height), Scalar(0, 0, 255), 1, 8);
			cout << faces[i] << endl;
			//将人脸从灰度图中抠出来
			Mat face_ = imgGray(faces[i]);
			eyes_Cascade.detectMultiScale(face_, eyes, 1.2, 2, 0, Size(30, 30));
			for (size_t j = 0; j < eyes.size(); j++) {
				Point eye_center(faces[i].x + eyes[j].x + eyes[j].width / 2, faces[i].y + eyes[j].y + eyes[j].height / 2);
				int radius = cvRound((eyes[j].width + eyes[j].height)*0.25);
				circle(img, eye_center, radius, Scalar(65, 105, 255), 4, 8, 0);
			}
		}
	}
	imshow("src", img);
}

