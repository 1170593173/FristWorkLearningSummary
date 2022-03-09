#include "FFmpeg.h"

#pragma comment (lib, "avcodec.lib")
#pragma comment (lib, "avdevice.lib")
#pragma comment (lib, "avfilter.lib")
#pragma comment (lib, "avformat.lib")
#pragma comment (lib, "avutil.lib")
#pragma comment (lib, "postproc.lib")
#pragma comment (lib, "swresample.lib")
#pragma comment (lib, "swscale.lib")

FFmpeg::FFmpeg(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	int failflag = 0;
	//qDebug() << avcodec_configuration() << endl;
	//unsigned version = avcodec_version();
	//string ch = to_string(version);
	////qDebug() << ch << endl;

	// rtsp流地址
	const char RtspAddress[] = { "rtsp://192.168.43.194:9001" };
	//const char RtspAddress[] = { "rtsp://wowzaec2demo.streamlock.net/vod/mp4:BigBuckBunny_115k.mov" };


	// ffmpeg注册
	av_register_all();
	avformat_network_init();

	// 初始化上下文
	AVFormatContext *avFormatContext = avformat_alloc_context();

	// 画质优化
	AVDictionary *avDictionary = nullptr;
	av_dict_set(&avDictionary, "buffer_size", "1024000", 0);	// 设置图像最大buf长度
	av_dict_set(&avDictionary, "max_delay", "500000", 0);		// 设置图像最大缓冲
	av_dict_set(&avDictionary, "rtsp_transport", "tcp", 0);  	// 设置使用tcp传输,因udp在1080p下会丢包导致花屏

	int result = avformat_open_input(&avFormatContext, RtspAddress, nullptr, &avDictionary);
	if (result < 0)
	{
		std::cout << "开打rtsp错误:" << result << std::endl;
		failflag= -1;
	}

	// 查找视频码流信息
	result = avformat_find_stream_info(avFormatContext, nullptr);
	if (result < 0)
	{
		std::cout << "查找视频码流错误:" << result << std::endl;
		failflag= -2;
	}

	// 查找视频码流
	int VideoStream = -1;
	for (int index = 0; index < avFormatContext->nb_streams; ++index)
	{
		if (avFormatContext->streams[index]->codec->codec_type == AVMEDIA_TYPE_VIDEO)
		{
			VideoStream = index;
			break;
		}
	}
	if (VideoStream == -1)
	{
		std::cout << "查找视频码流失败。" << std::endl;
		failflag = -3;
	}

	// 查找视频解码器
	AVCodecContext *avCodecContext = avFormatContext->streams[VideoStream]->codec;
	AVCodec *avCodec = avcodec_find_decoder(avCodecContext->codec_id);
	if (!avCodec)
	{
		std::cout << "查找视频解码器。" << std::endl;
		failflag = -4;
	}

	// 打开解码器
	result = avcodec_open2(avCodecContext, avCodec, NULL);
	if (result < 0)
	{
		std::cout << "打开解码器错误:" << result << std::endl;
		failflag = -5;
	}

	// 创建初始化解码包
	AVPacket *avPacket = av_packet_alloc();
	av_init_packet(avPacket);

	// 创建源、目标帧
	AVFrame *sFrame = av_frame_alloc();
	AVFrame *dFrame = av_frame_alloc();

	// 获取图像尺寸并分配出内存
	int PictureSize = avpicture_get_size(AV_PIX_FMT_RGB32, avCodecContext->width, avCodecContext->height);
	unsigned char *pBuffer = (unsigned char *)av_malloc(PictureSize * sizeof(unsigned char));

	//	图像填充
	avpicture_fill((AVPicture *)dFrame,
		pBuffer,
		AV_PIX_FMT_RGB32,
		avCodecContext->width,
		avCodecContext->height);

	// 设置数据转换参数
	struct SwsContext *swsContext = sws_getContext(avCodecContext->width,
		avCodecContext->height,
		avCodecContext->pix_fmt,
		avCodecContext->width,
		avCodecContext->height,
		AV_PIX_FMT_RGB32,
		SWS_BICUBIC,
		NULL, NULL, NULL);

	// 视频解码状态
	int DecodePictureState = -1;

	// 循环读取处理(此处死循环在实际生产中,可做出其他控制)
	while (1)
	{
		// 读取一包数据
		result = av_read_frame(avFormatContext, avPacket);

		// 若该包数据为视频流
		if (avPacket->stream_index == VideoStream)
		{
			// 解码一帧图像
			result = avcodec_decode_video2(avCodecContext, sFrame, &DecodePictureState, avPacket);
			if (result < 0)
			{
				std::cout << "decode error :" << result << std::endl;
				break;
			}

			// 解码成功
			if (DecodePictureState)
			{
				// 切片
				sws_scale(swsContext,
					(const uint8_t* const*)sFrame->data,
					sFrame->linesize,
					0,
					avCodecContext->height,
					dFrame->data,
					dFrame->linesize);

				/////////////////////////// 转cv::Mat
				//cv::Mat mat;
				//int width = sFrame->width;
				//int height = sFrame->height;
				//if (mat.rows != height || mat.cols != width || mat.type() != CV_8UC3)
				//{
				//	mat = cv::Mat(height, width, CV_8UC3);
				//}
				//int cvLinesizes[1];
				//cvLinesizes[0] = mat.step1();
				//SwsContext* conversion = sws_getContext(width,
				//	height,
				//	(AVPixelFormat)sAVFrame->format,
				//	width,
				//	height,
				//	AVPixelFormat::AV_PIX_FMT_BGR24,
				//	SWS_FAST_BILINEAR,
				//	NULL, NULL, NULL);
				//sws_scale(conversion,
				//	sAVFrame->data,
				//	sAVFrame->linesize,
				//	0,
				//	height,
				//	&mat.data,
				//	cvLinesizes);
				//sws_freeContext(conversion);
				//cv::imshow("mat",mat);
				/////////////////////////

				///////////////////////// 转QImage
				QImage qimage((uchar *)pBuffer, avCodecContext->width, avCodecContext->height, QImage::Format_RGB32);
				if (!qimage.isNull())
				{
					qimage.save("test1111.jpg", "JPG", 100);
					ui.label->setPixmap(QPixmap::fromImage(qimage));
					int aa = 1;
				}
				/////////////////////////

				// 至此已经结束,可利用解码后图像数据做其他操作..
			}
		}
	}

	// 释放图像优化
	if (avDictionary)
	{
		av_dict_free(&avDictionary);
	}
	avDictionary = nullptr;

	// 释放图片内存
	if (pBuffer)
	{
		delete[]pBuffer;
	}
	pBuffer = nullptr;

	// 释放解码环境
	if (avCodecContext)
	{
		avcodec_close(avCodecContext);
		avCodecContext = NULL;
	}

	// 释放上下文
	if (avFormatContext)
	{
		avformat_close_input(&avFormatContext);
		avFormatContext = NULL;
	}

	// 释放网络
	avformat_network_deinit();
}
