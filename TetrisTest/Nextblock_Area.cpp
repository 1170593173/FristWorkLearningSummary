#include "Nextblock_Area.h"


Nextblock_Area::Nextblock_Area(QWidget* m_widget)
{
	/*srand((unsigned)time(NULL));
	flag = rand() % 5;*/
	//timer = new QTimer(this);
	//bool isok =connect(timer, SIGNAL(timeout()), this, SLOT(SetFlag()));
	//bool isok = connect(timer, SIGNAL(timeout()), this, SLOT(SetFlag()));
	//timer->start(100);
	//SetFlag(100);
}


Nextblock_Area::~Nextblock_Area()
{
}

void Nextblock_Area::paintEvent(QPaintEvent *event) {
	draw_frame();					//绘制边框
	draw_block();					//绘制下一个方块
	//draw_droppingBlocks();        //正在下落的方块
	//draw_fixedBlocks();           //固定住的方块
	update();
	previouFlag = flag;
}

void Nextblock_Area::draw_frame()
{

	QPainter painter(this);
	//painter.setPen(QPen(QColor(0, 160, 100),4));
	painter.setPen(Qt::SolidLine);
	QLineF pointL[4];
	int m_width = this->width()-5;
	int m_high = this->height()-5;
	pointL[0].setLine(0, 0, m_width, 0);
	pointL[1].setLine(0, 0, 0, m_high);
	pointL[2].setLine(m_width, 0, m_width, m_high);
	pointL[3].setLine(0, m_high, m_width, m_high);
	painter.drawLines(pointL, 4);

}

void Nextblock_Area::draw_block()
{
	QPainter painter(this);
	int m_width = this->width() - 5;
	int m_high = this->height() - 5;
	OneBlock oneblock;
	g_ptr = std::make_shared<DrawGrid>();
	group =g_ptr->CreateGrid(m_width, m_high,6,5);

	int a, b;
	switch (flag)
	{
	default://case 0
		a = 1; b = 2;
		oneblock = group[a][b];
		b_ptr = std::make_shared<OneGlyph>(a,b,oneblock, group);
		break;
	case 1:
		a = 1; b = 1;
		oneblock = group[a][b];
		b_ptr = std::make_shared<SevenGlyph>(a, b, oneblock, group);
		break;
	case 2:
		a = 3; b = 2;
		oneblock = group[a][b];
		b_ptr = std::make_shared<SoilGlyph>(a, b, oneblock, group);
		break;
	case 3:
		a = 2; b = 1;
		oneblock = group[a][b];
		b_ptr = std::make_shared<StepGlyph>(a, b, oneblock, group);
		break;
	case 4:
		a = 2; b = 1;
		oneblock = group[a][b];
		b_ptr = std::make_shared<FieldGlyph>(a, b, oneblock,group);
		break;
	}
	b_ptr->CreateBlocks(painter);
	
	group.clear();
}

void Nextblock_Area::SetFlag() {
	srand((unsigned)time(NULL));
	flag = rand()%5;
	//flag = 4;
}