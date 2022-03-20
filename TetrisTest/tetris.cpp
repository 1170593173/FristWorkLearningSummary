#include "tetris.h"

Tetris::Tetris(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	mm = new Mainblock_Area(parent);
	nn = new Nextblock_Area(parent);
	timer = new QTimer(this);
	//connect();
	bool isok=connect(mm, SIGNAL(OnTheBottom()), this, SLOT(createNewBlock()));
	isok=connect(mm, SIGNAL(OnTheBottom()), nn, SLOT(SetFlag()));
	isok=connect(mm, SIGNAL(SingelGetScope(int )), this, SLOT(SlotGetScope(int )));

	isok = connect(timer, SIGNAL(timeout()), this, SLOT(DownBlockAuto()));
	timer->start(1000);
	isok = true;
}

Tetris::~Tetris()
{

}

void Tetris::createNewBlock() {
	Mainblock_Area::flag = Nextblock_Area::previouFlag;
	Mainblock_Area::block_x = 3;//设置的宽度就是18个格子
	Mainblock_Area::block_y = 0;
}

void Tetris::on_pushButton_clicked() {
	mm->rotate();
}

void Tetris::on_pushButton_overturn_clicked(){
	mm->overturn();
}

void Tetris::on_pushButton_left_clicked() {
	mm->translationtoLeft();
}

void Tetris::on_pushButton_right_clicked() {
	mm->translationtoRight();
}

void Tetris::on_pushButton_down_clicked() {
	mm->down();
}

void Tetris::DownBlockAuto(){
	mm->down();
}

void Tetris::SlotGetScope(int addScope) {
	QString t=ui.label_scope->text();
	int Scope = t.toInt()+ addScope;
	ui.label_scope->setText(QString::number(Scope));
}