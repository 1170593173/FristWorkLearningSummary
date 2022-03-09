#pragma once
#include <iostream>

/*类的模板的使用：
最大的注意点：一定要注意在.h与.cpp必须在同一个文件中*/

template<typename T1,typename T2>
class Point
{
public:
	Point(T1 x, T2 y) :m_x(x), m_y(y) {};
	//~Point(){}

	T1 getX() const;
	void setX(T1 x);
	T2 getY() const;
	void setY(T2 y);

private:
	T1 m_x;
	T2 m_y;
};


template<typename T1, typename T2>
T1 Point<T1, T2>::getX()const {
	return m_x;
}

template<typename T1, typename T2>
void Point<T1, T2>::setX(T1 x) {
	m_x = x;
}

template<typename T1, typename T2>
T2 Point<T1, T2>::getY()const {
	return m_y;
}

template<typename T1, typename T2>
void Point<T1, T2>::setY(T2 y) {
	m_y = y;
}