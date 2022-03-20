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
	virtual void overturn(int &block_x, int &block_y, int &swicth ) {};
	virtual void setFull(int mswitch) {};
	virtual ~blocks() {};
	void setCoordinate(int x, int y, int width, int hight);
	virtual int getState();
	virtual bool isInrange(int mswitch) { return false; };

	int grid_x, grid_y;//��¼��grid�еĺ�������
	std::vector<std::vector<OneBlock>> grid;
	int state;
protected:
	int m_x, m_y, m_width, m_hight;
private: 
	
};

//����
class OneGlyph:public blocks
{
public:
	OneGlyph::OneGlyph(int x, int y, OneBlock &oneblock, std::vector<std::vector<OneBlock>> &m_grid) : blocks(x, y, oneblock ,m_grid){}
	OneGlyph::~OneGlyph(){}
	void CreateBlocks(QPainter &painter, int m_switch = 0);
	void rotate(int &block_x, int &block_y, int &swicth);
	bool isInrange(int mswitch/*const std::vector<std::vector<OneBlock>> &grid*/);
	void setFull(int mswitch/*const std::vector<std::vector<OneBlock>> &grid)*/);
	//int grid_x, grid_y;//��¼��grid�еĺ�������
private:
	//int state = 0;//��¼��ǰ��״��״̬���������Ż�������
};

//����
class SevenGlyph :public blocks
{
public:
	SevenGlyph::SevenGlyph(int x, int y, OneBlock &oneblock, std::vector<std::vector<OneBlock>> &m_grid) : blocks(x, y, oneblock, m_grid) {}
	SevenGlyph::~SevenGlyph()
	{
	}
	void CreateBlocks(QPainter &painter, int m_switch = 0);
	bool isInrange(int mswitch/*const std::vector<std::vector<OneBlock>> &grid*/);
	void rotate(int &block_x, int &block_y, int &swicth);
	void setFull(int mswitch/*const std::vector<std::vector<OneBlock>> &grid)*/);
	void overturn(int &block_x, int &block_y, int &swicth);
};


////���־���
//class SevenGlyphOverTurn :public blocks
//{
//public:
//	SevenGlyphOverTurn::SevenGlyphOverTurn(int x, int y, OneBlock &oneblock, std::vector<std::vector<OneBlock>> &m_grid) : blocks(x, y, oneblock, m_grid) {}
//	SevenGlyphOverTurn::~SevenGlyphOverTurn()
//	{
//	}
//	void CreateBlocks(QPainter &painter, int m_switch = 0);
//	bool isInrange(int mswitch/*const std::vector<std::vector<OneBlock>> &grid*/);
//	void rotate(int &block_x, int &block_y, int &swicth);
//	void setFull(int mswitch/*const std::vector<std::vector<OneBlock>> &grid)*/);
//	void overturn(int &block_x, int &block_y, int &swicth);
//};

//����
class SoilGlyph :public blocks
{
public:
	SoilGlyph::SoilGlyph(int x, int y, OneBlock &oneblock, std::vector<std::vector<OneBlock>> &m_grid) : blocks(x, y, oneblock, m_grid) {}
	SoilGlyph::~SoilGlyph()
	{
	}
	void CreateBlocks(QPainter &painter, int m_switch = 0);
	bool isInrange(int mswitch/*const std::vector<std::vector<OneBlock>> &grid*/);
	void rotate(int &block_x, int &block_y, int &swicth);
	void setFull(int mswitch/*const std::vector<std::vector<OneBlock>> &grid)*/);
};

//̨����
class StepGlyph :public blocks
{
public:
	StepGlyph::StepGlyph(int x, int y, OneBlock &oneblock, std::vector<std::vector<OneBlock>> &m_grid) : blocks(x, y, oneblock, m_grid) {}
	StepGlyph::~StepGlyph(){}
	void CreateBlocks(QPainter &painter, int m_switch = 0);
	bool isInrange(int mswitch/*const std::vector<std::vector<OneBlock>> &grid*/);
	void rotate(int &block_x, int &block_y, int &swicth);
	void setFull(int mswitch/*const std::vector<std::vector<OneBlock>> &grid)*/);
	void overturn(int &block_x, int &block_y, int &swicth);
};


//̨���־���
class StepGlyphOverTurn :public blocks
{
public:
	StepGlyphOverTurn::StepGlyphOverTurn(int x, int y, OneBlock &oneblock, std::vector<std::vector<OneBlock>> &m_grid) : blocks(x, y, oneblock, m_grid) {}
	StepGlyphOverTurn::~StepGlyphOverTurn(){}
	void CreateBlocks(QPainter &painter, int m_switch = 0);
	bool isInrange(int mswitch/*const std::vector<std::vector<OneBlock>> &grid*/);
	void rotate(int &block_x, int &block_y, int &swicth);
	void setFull(int mswitch/*const std::vector<std::vector<OneBlock>> &grid)*/);
};

//����
class FieldGlyph :public blocks
{
public:
	FieldGlyph::FieldGlyph(int x, int y, OneBlock &oneblock, std::vector<std::vector<OneBlock>> &m_grid) : blocks(x, y, oneblock, m_grid) {}
	FieldGlyph::~FieldGlyph(){}
	void CreateBlocks(QPainter &painter, int m_switch = 0);
	bool isInrange(int mswitch/*const std::vector<std::vector<OneBlock>> &grid*/);
	void rotate(int &block_x, int &block_y, int &swicth);
	void setFull(int mswitch/*const std::vector<std::vector<OneBlock>> &grid)*/);
};


//��������
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



