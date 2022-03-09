#include "SDR_Engine.h"
#include "MyContext.h"
#include "MySwitch.h"

SDR_Engine::SDR_Engine()
{
}
SDR_Engine::~SDR_Engine()
{
}

/*�߳̿�����ں���1*/
void SDR_Engine::run() {

	/*ȫ�ֱ�������*/
	MySingleTon_queue::Ptr instance = MySingleTon_queue::get_instance();
	string str_event = "";
	MyContext *m_context;
	while (true)
	{
		str_event = instance->get_event();
		m_context = new MyContext(str_event);
		m_context->DO_GetResult();

		//Core(str_event);
		if (str_event == "Cancel") {
			break;
		}
		_sleep(500);
	}
}