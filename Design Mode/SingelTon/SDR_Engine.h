#pragma once
#include"MySingleTon.h"
#include<iostream>
#include<thread>
using namespace std;

class SDR_Engine
{
public:
	SDR_Engine();
	~SDR_Engine();
	void run();
	void Core(string );
};

