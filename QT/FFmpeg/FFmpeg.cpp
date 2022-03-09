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

	// rtsp����ַ
	const char RtspAddress[] = { "rtsp://192.168.43.194:9001" };
	//const char RtspAddress[] = { "rtsp://wowzaec2demo.streamlock.net/vod/mp4:BigBuckBunny_115k.mov" };


	// ffmpegע��
	av_register_all();
	avformat_network_init();

	// ��ʼ��������
	AVFormatContext *avFormatContext = avformat_alloc_context();

	// �����Ż�
	AVDictionary *avDictionary = nullptr;
	av_dict_set(&avDictionary, "buffer_size", "1024000", 0);	// ����ͼ�����buf����
	av_dict_set(&avDictionary, "max_delay", "500000", 0);		// ����ͼ����󻺳�
	av_dict_set(&avDictionary, "rtsp_transport", "tcp", 0);  	// ����ʹ��tcp����,��udp��1080p�»ᶪ�����»���

	int result = avformat_open_input(&avFormatContext, RtspAddress, nullptr, &avDictionary);
	if (result < 0)
	{
		std::cout << "����rtsp����:" << result << std::endl;
		failflag= -1;
	}

	// ������Ƶ������Ϣ
	result = avformat_find_stream_info(avFormatContext, nullptr);
	if (result < 0)
	{
		std::cout << "������Ƶ��������:" << result << std::endl;
		failflag= -2;
	}

	// ������Ƶ����
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
		std::cout << "������Ƶ����ʧ�ܡ�" << std::endl;
		failflag = -3;
	}

	// ������Ƶ������
	AVCodecContext *avCodecContext = avFormatContext->streams[VideoStream]->codec;
	AVCodec *avCodec = avcodec_find_decoder(avCodecContext->codec_id);
	if (!avCodec)
	{
		std::cout << "������Ƶ��������" << std::endl;
		failflag = -4;
	}

	// �򿪽�����
	result = avcodec_open2(avCodecContext, avCodec, NULL);
	if (result < 0)
	{
		std::cout << "�򿪽���������:" << result << std::endl;
		failflag = -5;
	}

	// ������ʼ�������
	AVPacket *avPacket = av_packet_alloc();
	av_init_packet(avPacket);

	// ����Դ��Ŀ��֡
	AVFrame *sFrame = av_frame_alloc();
	AVFrame *dFrame = av_frame_alloc();

	// ��ȡͼ��ߴ粢������ڴ�
	int PictureSize = avpicture_get_size(AV_PIX_FMT_RGB32, avCodecContext->width, avCodecContext->height);
	unsigned char *pBuffer = (unsigned char *)av_malloc(PictureSize * sizeof(unsigned char));

	//	ͼ�����
	avpicture_fill((AVPicture *)dFrame,
		pBuffer,
		AV_PIX_FMT_RGB32,
		avCodecContext->width,
		avCodecContext->height);

	// ��������ת������
	struct SwsContext *swsContext = sws_getContext(avCodecContext->width,
		avCodecContext->height,
		avCodecContext->pix_fmt,
		avCodecContext->width,
		avCodecContext->height,
		AV_PIX_FMT_RGB32,
		SWS_BICUBIC,
		NULL, NULL, NULL);

	// ��Ƶ����״̬
	int DecodePictureState = -1;

	// ѭ����ȡ����(�˴���ѭ����ʵ��������,��������������)
	while (1)
	{
		// ��ȡһ������
		result = av_read_frame(avFormatContext, avPacket);

		// ���ð�����Ϊ��Ƶ��
		if (avPacket->stream_index == VideoStream)
		{
			// ����һ֡ͼ��
			result = avcodec_decode_video2(avCodecContext, sFrame, &DecodePictureState, avPacket);
			if (result < 0)
			{
				std::cout << "decode error :" << result << std::endl;
				break;
			}

			// ����ɹ�
			if (DecodePictureState)
			{
				// ��Ƭ
				sws_scale(swsContext,
					(const uint8_t* const*)sFrame->data,
					sFrame->linesize,
					0,
					avCodecContext->height,
					dFrame->data,
					dFrame->linesize);

				/////////////////////////// תcv::Mat
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

				///////////////////////// תQImage
				QImage qimage((uchar *)pBuffer, avCodecContext->width, avCodecContext->height, QImage::Format_RGB32);
				if (!qimage.isNull())
				{
					qimage.save("test1111.jpg", "JPG", 100);
					ui.label->setPixmap(QPixmap::fromImage(qimage));
					int aa = 1;
				}
				/////////////////////////

				// �����Ѿ�����,�����ý����ͼ����������������..
			}
		}
	}

	// �ͷ�ͼ���Ż�
	if (avDictionary)
	{
		av_dict_free(&avDictionary);
	}
	avDictionary = nullptr;

	// �ͷ�ͼƬ�ڴ�
	if (pBuffer)
	{
		delete[]pBuffer;
	}
	pBuffer = nullptr;

	// �ͷŽ��뻷��
	if (avCodecContext)
	{
		avcodec_close(avCodecContext);
		avCodecContext = NULL;
	}

	// �ͷ�������
	if (avFormatContext)
	{
		avformat_close_input(&avFormatContext);
		avFormatContext = NULL;
	}

	// �ͷ�����
	avformat_network_deinit();
}
