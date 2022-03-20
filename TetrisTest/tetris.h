#ifndef TETRIS_H
#define TETRIS_H

#include <QtWidgets/QMainWindow>
#include "ui_tetris.h"
#include "Mainblock_Area.h"
#include "Nextblock_Area.h"

class Tetris : public QMainWindow
{
	Q_OBJECT

public:
	Tetris(QWidget *parent = 0);
	~Tetris();
	Mainblock_Area *mm;
	Nextblock_Area *nn;

private:
	Ui::TetrisClass ui;
	QTimer *timer;
	//test 

	public slots:
	void on_pushButton_clicked();
	void on_pushButton_left_clicked();
	void on_pushButton_right_clicked();
	void on_pushButton_down_clicked();
	void on_pushButton_overturn_clicked();
	void createNewBlock();

	void SlotGetScope(int addScope);

	void DownBlockAuto();
	
};

#endif // TETRIS_H
