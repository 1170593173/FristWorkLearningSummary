#include<iostream>
#include<vector>
#include<windows.h>  // ������� windows.h
//#include "QtUiDll.h"
#pragma comment(lib,"dllTest.lib")
#pragma comment(lib,"DLL_Class.lib")
#pragma comment(lib,"WIFI_V1_Test.lib")
using namespace std;

extern "C" _declspec(dllimport) int Add(int a, int b);
extern "C" _declspec(dllimport) int Add__(int a, int b);
extern "C" _declspec(dllimport) string GetALLV1Cmd(string path);
//extern "C" _declspec(dllimport) std::vector<AllConfig>  getallConfigArr(std::string inipath);
extern "C" _declspec(dllimport) int exportDate();
void main()
{
	//HINSTANCE dllDemo = LoadLibrary("QtUiDll.dll");
	//QWidget * obj = (QWidget*)GetProcAddress(dllDemo, "getObj");
	//int rrr=obj->add(1, 2);
	int a, b;
	//cout << exportDate() << endl;//���ú������666 
	//
	//dog dog;//ʵ����dog���󡢸�ֵ���������
	//dog.getHigh(5);
	//dog.getWide(6);
	//cout << dog.outDate() << endl;

	//cat cat;//ʵ����cat���󡢸�ֵ�������
	//cat.getHigh(16);
	//cat.getWide(4);
	//cout << cat.outDate() << endl;

	while (1)
	{
		cin >> a >> b;
		cout << Add__(a, b) << endl;

		string tttt = GetALLV1Cmd("E:\\learning\\C++\\C++ ABC\\WIFI_V1_Test\\Debug\\WifiSetting.ini");
		std::vector<uint8_t> vec(tttt.begin(), tttt.end());
		//vector<uint8_t> v(tttt, tttt + sizeof(tttt));
		//std::vector<uint8_t>ttt = tttt;
		int kkk = 0;
	}
}