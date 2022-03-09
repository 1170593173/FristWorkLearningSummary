#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_FFmpeg.h"
#include <iostream>
#include <QDebug>
using namespace  std;

extern "C" 
{
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#include <libswscale/swscale.h>
#include <libavdevice/avdevice.h>
#include <libavformat/version.h>
#include <libavutil/time.h>
#include <libavutil/mathematics.h>
}

class FFmpeg : public QMainWindow
{
	Q_OBJECT

public:
	FFmpeg(QWidget *parent = Q_NULLPTR);

private:
	Ui::FFmpegClass ui;
};
