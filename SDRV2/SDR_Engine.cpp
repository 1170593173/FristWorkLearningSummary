#include "SDR_Engine.h"
#include "MyContext.h"
#include "MySwitch.h"

SDR_Engine::SDR_Engine()
{
}
SDR_Engine::~SDR_Engine()
{
}

/*线程开启入口函数1*/
void SDR_Engine::run() {

	/*全局变量对象*/
	MySingleTon_queue::Ptr instance = MySingleTon_queue::get_instance();
	//m_singleTon = MySingleTon_queue::get_instance();
	MySingleTon_queue::Queue_Element m_queue = instance->create_queue("queue1");
	//MySingleTon_queue::Queue_Element m_queue = instance->get_queue("queue1");
	string str_event = "";
	MyContext *m_context;
	while (true)
	{
		str_event = instance->get_event(m_queue);
		if (str_event!="")
		{
			cout << m_queue.queue_name + "_" + str_event << endl;
		}
		
		/*m_context = new MyContext(str_event);
		m_context->DO_GetResult();*/

		//Core(str_event);
		if (str_event == "Cancel") {
			break;
		}
		_sleep(500);
	}
}