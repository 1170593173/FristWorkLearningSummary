#pragma once
//#include "C:\Qt\Qt5.11.3\5.11.3\msvc2015_64\include\QtWidgets\qwidget.h"
#include "QtWidgets/qwidget.h"
#include <QPainter>

struct OneBlock
{
	QPoint p_start;
	float w, h;
	bool isfull;
	OneBlock() {};
};

class blocks
{
public:
	blocks(int x, int y, OneBlock &oneblock,std::vector<std::vector<OneBlock>> &m_grid) :
		grid_x(x),grid_y(y),
		m_x(oneblock.p_start.x()), m_y(oneblock.p_start.y()), m_width(oneblock.w), m_hight(oneblock.h),
		grid(m_grid){};

	virtual void CreateBlocks(QPainter &painter,int m_switch=0) {};
	virtual void rotate(int &block_x, int &block_y, int &swicth) {};
	virtual void setFull(int mswitch) {};
	virtual ~blocks() {};
	void setCoordinate(int x, int y, int width, int hight);
	virtual int getState();
	virtual bool isInrange(int mswitch) { return false; };

	int grid_x, grid_y;//记录在grid中的横纵坐标
	std::vector<std::vector<OneBlock>> grid;
	int state;
protected:
	int m_x, m_y, m_width, m_hight;
private: 
	
};

//横条
class shape1:public blocks
{
public:
	shape1::shape1(int x, int y, OneBlock &oneblock, std::vector<std::vector<OneBlock>> &m_grid) : blocks(x, y, oneblock ,m_grid){}
	shape1::~shape1(){}
	void CreateBlocks(QPainter &painter, int m_switch = 0);
	void rotate(int &block_x, int &block_y, int &swicth);
	bool isInrange(int mswitch/*const std::vector<std::vector<OneBlock>> &grid*/);
	void setFull(int mswitch/*const std::vector<std::vector<OneBlock>> &grid)*/);
	//int grid_x, grid_y;//记录在grid中的横纵坐标
private:
	//int state = 0;//记录当前形状的状态，横着竖着或者其他
};

//七字
class shape2 :public blocks
{
public:
	shape2::shape2(int x, int y, OneBlock &oneblock, std::vector<std::vector<OneBlock>> &m_grid) : blocks(x, y, oneblock, m_grid) {}
	shape2::~shape2()
	{
	}
	void CreateBlocks(QPainter &painter, int m_switch = 0);
	bool isInrange(int mswitch/*const std::vector<std::vector<OneBlock>> &grid*/);
	void rotate(int &block_x, int &block_y, int &swicth);
	void setFull(int mswitch/*const std::vector<std::vector<OneBlock>> &grid)*/);
};

//土字
class shape3 :public blocks
{
public:
	shape3::shape3(int x, int y, OneBlock &oneblock, std::vector<std::vector<OneBlock>> &m_grid) : blocks(x, y, oneblock, m_grid) {}
	shape3::~shape3()
	{
	}
	void CreateBlocks(QPainter &painter, int m_switch = 0);
	bool isInrange(int mswitch/*const std::vector<std::vector<OneBlock>> &grid*/);
	void rotate(int &block_x, int &block_y, int &swicth);
	void setFull(int mswitch/*const std::vector<std::vector<OneBlock>> &grid)*/);
};

//台阶字
class shape4 :public blocks
{
public:
	shape4::shape4(int x, int y, OneBlock &oneblock, std::vector<std::vector<OneBlock>> &m_grid) : blocks(x, y, oneblock, m_grid) {}
	shape4::~shape4(){}
	void CreateBlocks(QPainter &painter, int m_switch = 0);
	bool isInrange(int mswitch/*const std::vector<std::vector<OneBlock>> &grid*/);
	void rotate(int &block_x, int &block_y, int &swicth);
	void setFull(int mswitch/*const std::vector<std::vector<OneBlock>> &grid)*/);
};

//田字
class shape5 :public blocks
{
public:
	shape5::shape5(int x, int y, OneBlock &oneblock, std::vector<std::vector<OneBlock>> &m_grid) : blocks(x, y, oneblock, m_grid) {}
	shape5::~shape5(){}
	void CreateBlocks(QPainter &painter, int m_switch = 0);
	bool isInrange(int mswitch/*const std::vector<std::vector<OneBlock>> &grid*/);
	void rotate(int &block_x, int &block_y, int &swicth);
	void setFull(int mswitch/*const std::vector<std::vector<OneBlock>> &grid)*/);
};


//绘制网格
class DrawGrid
{
public:
	//DrawGrid::DrawGrid(int x, int y, OneBlock &oneblock) : blocks(x, y, oneblock) {}
	DrawGrid::DrawGrid()  {}
	DrawGrid::~DrawGrid() {}
	std::vector<std::vector<OneBlock>> CreateGrid( int m_width, int m_high,int col,int row);
private:
	//std::vector<std::vector<OneBlock>> Group;
};



