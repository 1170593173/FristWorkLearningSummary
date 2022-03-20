#include "tetris.h"
#include <QtWidgets/QApplication>
#include "Mainblock_Area.h"

int Mainblock_Area::block_x = 3;//设置的宽度就是18个格子，这里配置的是起始的方块的位置
int Mainblock_Area::block_y = 0;
int Mainblock_Area::flag = 3;//设置起始方块的类型是什么样的
int Mainblock_Area::swicth = 0;
std::vector<std::vector<OneBlock>> Mainblock_Area::MainGroup;
std::vector<std::vector<OneBlock>> Mainblock_Area::OldMainGroup;

std::shared_ptr<blocks> Mainblock_Area::b_ptr;
std::shared_ptr<DrawGrid> Mainblock_Area::g_ptr;



int Nextblock_Area::previouFlag = 0;
int Nextblock_Area::flag = 0;

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Tetris w;
	w.show();
	return a.exec();
}
