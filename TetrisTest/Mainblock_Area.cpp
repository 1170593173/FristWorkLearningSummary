#include "Mainblock_Area.h"


Mainblock_Area::Mainblock_Area(QWidget* m_widget)
{
	timer = new QTimer(this);

	int m_width = this->width() - 5;
	int m_high = this->height() - 5;
	g_ptr = std::make_shared<DrawGrid>();
	
	//block_x =1, block_y =2;
	//static  int ii = 0;
	//
	//int m_width = this->width() - 5;
	//int m_high = this->height() - 5;
	//OneBlock oneblock;
	//g_ptr = std::make_shared<DrawGrid>();
	//g_ptr->CreateGrid(MainGroup, m_width, m_high, 18, 25);

	//int a, b;
	//a = 1; b = 2;
	//oneblock = MainGroup[a][b];
	//b_ptr = std::make_shared<OneGlyph>(a, b, oneblock, MainGroup);
	//ui.setupUi(this);
	//bool isok = connect(timer, SIGNAL(timeout()), this, SLOT(MainUpdate()));
	//timer->start(1000);
}


Mainblock_Area::~Mainblock_Area()
{
}

void Mainblock_Area::paintEvent(QPaintEvent *event) {
	QPainter painter(this);

	MainGroup.clear();	//清除上次的网格数据
	painter.setPen(Qt::SolidLine);
	QLineF pointL[4];
	int m_width = this->width() - 5;//根据当前窗口的长宽设定网格大小
	int m_high = this->height() - 5;

	MainGroup = g_ptr->CreateGrid(m_width, m_high, 10, 12);//创建网格，有18个列，20个行
	
	/*根据当前创建的网格，绘制游戏的主边界*/
	int lowline = MainGroup.back().back().p_start.y() + MainGroup.back().back().h;
	int rightline = MainGroup.back().back().p_start.x() + MainGroup.back().back().w;
	pointL[0].setLine(0, 0, rightline, 0);
	pointL[1].setLine(0, 0, 0, lowline);
	pointL[2].setLine(rightline, 0, rightline, lowline);
	pointL[3].setLine(0, lowline, rightline, lowline);
	painter.drawLines(pointL, 4);


	//根据原有的下落到底的方块，绘制下落的方块形状
	painter.setRenderHint(QPainter::Antialiasing, true);
	painter.setPen(QPen(QColor(0, 160, 230), 1));
	painter.setBrush(QColor(200, 200, 200));
	for (int i = 0; i < OldMainGroup.size(); ++i)
	{
		for (int j = 0; j < OldMainGroup[i].size(); ++j)
		{
			MainGroup[i][j].isfull = OldMainGroup[i][j].isfull;
			if (MainGroup[i][j].isfull)
			{
				painter.drawRect(MainGroup[i][j].p_start.x(), MainGroup[i][j].p_start.y(), MainGroup[i][j].w, MainGroup[i][j].h);
			}
		}
	}


	//以网格为整体坐标系，绘制对应的形状
	OneBlock oneblock;
	oneblock = MainGroup[block_x][block_y];
	switch (flag)
	{
	default://case 0
		b_ptr = std::make_shared<OneGlyph>(block_x, block_y, oneblock, MainGroup);
		break;
	case 1:
		b_ptr = std::make_shared<SevenGlyph>(block_x, block_y, oneblock, MainGroup);
		break;
	case 2:
		b_ptr = std::make_shared<SoilGlyph>(block_x, block_y, oneblock, MainGroup);
		break;
	case 3:
		b_ptr = std::make_shared<StepGlyph>(block_x, block_y, oneblock, MainGroup);
		break;
	case 4:
		b_ptr = std::make_shared<FieldGlyph>(block_x, block_y, oneblock, MainGroup);
		break;
	//case 5:
	//	b_ptr = std::make_shared<SevenGlyphOverTurn>(block_x, block_y, oneblock, MainGroup);
	//	break;
	}
	b_ptr->CreateBlocks(painter, swicth);
	update();
}

void Mainblock_Area::GetScope() {
	if (OldMainGroup.empty())
		return;
	bool isgetscope = true;
	//int k=OldMainGroup[0].size()-1;
	//for (int i = 0; i < OldMainGroup.size();++i)
	//{
	//	isgetscope = OldMainGroup[i][k].isfull && isgetscope;
	//}
	//if (isgetscope)
	//{
	//	for (int i = 0; i < OldMainGroup.size(); ++i)
	//	{
	//		OldMainGroup[i][k].isfull = false;
	//	}

	//	for (int i = 0; i < OldMainGroup.size(); ++i)
	//	{
	//		for (int j = OldMainGroup[i].size() - 2; j >= 0; --j)
	//		{
	//			if (OldMainGroup[i][j].isfull)
	//			{
	//				OldMainGroup[i][j + 1].isfull = true;
	//				OldMainGroup[i][j].isfull = false;
	//				//painter.drawRect(MainGroup[i][j].p_start.x(), MainGroup[i][j].p_start.y(), MainGroup[i][j].w, MainGroup[i][j].h);
	//			}
	//		}
	//	}

	//	for (int j = OldMainGroup[0].size()-1; j >=0;--j)
	//	{
	//		isgetscope = true;
	//		for (int i = 0; i < OldMainGroup.size();++i)
	//		{
	//			isgetscope = isgetscope&&OldMainGroup[i][j].isfull;
	//		}
	//		if (isgetscope)
	//		{
	//			for (int i = 0; i < OldMainGroup.size(); ++i)
	//			{
	//				OldMainGroup[i][j].isfull = false;
	//			}
	//		}
	//	}
	//	
	//}



	vector<bool>test;
	test.resize(OldMainGroup[0].size());

	std::vector<std::vector<OneBlock>> TempGroup = OldMainGroup;

	for (int j = 0; j < OldMainGroup[0].size(); ++j)
	{
		isgetscope = true;
		for (int i = 0; i < OldMainGroup.size(); ++i)
		{
			isgetscope = isgetscope&&OldMainGroup[i][j].isfull;
			OldMainGroup[i][j].isfull = false;
		}
		test[j] = isgetscope;
	}

	
	int	k= test.size() - 1;
	int j = k;
	int addScope = 0;
	isgetscope = false;
	while (j>=0)
	{
		if (test[j])
		{
			j--;
			addScope++;
			isgetscope = true;
			continue;
		}
		for (int i = 0; i < OldMainGroup.size(); ++i)
		{
			OldMainGroup[i][k] = TempGroup[i][j];
		}
		k--; j--;
	}
	if (isgetscope)
	{
		emit SingelGetScope(addScope);
	}
}

void Mainblock_Area::rotate() {
	b_ptr->rotate(block_x, block_y, swicth);
}

void Mainblock_Area::overturn(){
	b_ptr->overturn(block_x, block_y, swicth);
}

void Mainblock_Area::down() {
	b_ptr->grid = MainGroup;

	b_ptr->grid_x = b_ptr->grid_x;
	b_ptr->grid_y = b_ptr->grid_y+1;
	if ((b_ptr->getState() == 1 && b_ptr->isInrange(1))
		|| (b_ptr->getState() == 0 && b_ptr->isInrange(0))
		|| (b_ptr->getState() == 2 && b_ptr->isInrange(2))
		|| (b_ptr->getState() == 3 && b_ptr->isInrange(3))
		|| (b_ptr->getState() == 4 && b_ptr->isInrange(4))
		|| (b_ptr->getState() == 5 && b_ptr->isInrange(5))
		|| (b_ptr->getState() == 6 && b_ptr->isInrange(6))
		|| (b_ptr->getState() == 7 && b_ptr->isInrange(7)))
	{
		block_x = b_ptr->grid_x;
		block_y = b_ptr->grid_y;

	}
	else
	{
		b_ptr->grid_x = b_ptr->grid_x;
		b_ptr->grid_y = b_ptr->grid_y - 1;
		b_ptr->setFull(b_ptr->getState());
		emit OnTheBottom();
		OldMainGroup = b_ptr->grid;
		GetScope();
	}
	return;
}

void Mainblock_Area::translationtoLeft() {
	b_ptr->grid = MainGroup;
	b_ptr->grid_x = b_ptr->grid_x - 1;
	b_ptr->grid_y = b_ptr->grid_y;
	if ((b_ptr->getState() == 1 && b_ptr->isInrange(1))
		|| (b_ptr->getState() == 0 && b_ptr->isInrange(0))
		|| (b_ptr->getState() == 2 && b_ptr->isInrange(2))
		|| (b_ptr->getState() == 3 && b_ptr->isInrange(3))
		|| (b_ptr->getState() == 4 && b_ptr->isInrange(4))
		|| (b_ptr->getState() == 5 && b_ptr->isInrange(5))
		|| (b_ptr->getState() == 6 && b_ptr->isInrange(6))
		|| (b_ptr->getState() == 7 && b_ptr->isInrange(7)))
	{
		block_x = b_ptr->grid_x;
		block_y = b_ptr->grid_y;
		return;
		//swicth = 1;
	}
	b_ptr->grid_x = b_ptr->grid_x + 1;
}

void Mainblock_Area::translationtoRight() {
	b_ptr->grid = MainGroup;
	b_ptr->grid_x = b_ptr->grid_x +1;
	b_ptr->grid_y = b_ptr->grid_y;
	if((b_ptr->getState() == 1 && b_ptr->isInrange(1)) 
		|| (b_ptr->getState() == 0 && b_ptr->isInrange(0))
		|| (b_ptr->getState() == 2 && b_ptr->isInrange(2))
		|| (b_ptr->getState() == 3 && b_ptr->isInrange(3))
		|| (b_ptr->getState() == 4 && b_ptr->isInrange(4))
		|| (b_ptr->getState() == 5 && b_ptr->isInrange(5))
		|| (b_ptr->getState() == 6 && b_ptr->isInrange(6))
		|| (b_ptr->getState() == 7 && b_ptr->isInrange(7)))
	{
		block_x = b_ptr->grid_x;
		block_y = b_ptr->grid_y;
		return;
		//swicth = 1;
	}
	b_ptr->grid_x = b_ptr->grid_x - 1;
	//MainGroup.clear();
}

void Mainblock_Area::MainUpdate() {

}