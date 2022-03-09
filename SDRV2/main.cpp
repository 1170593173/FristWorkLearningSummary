#include "SDR.h"
#include <QtWidgets/QApplication>
#include"MySingleTon-queue.h"
#include"thread_test.h"
#include "MySingleTon-queue.h"
#include "MySingleTon.h"
#include "thread_pool.h"

#include "thread_pool2.h"
#include <iostream> 
#include <random>


/*********************************************�����������ԣ�ʵ���������ʹ�ã�����֤����Ψһ����˶����������룬��ʵ�����ȼ�����********************************************/

/*���������е�Ԫ�ؽṹ��*/
//struct Queue_Element
//{
//	string queue_name;
//	Queue_ElementPtr m_Queue_ElementPtr;
//	mutex *m_queue_mutex;
//};
MySingleTon_queue::Ptr MySingleTon_queue::m_instance_ptr = nullptr;
std::mutex MySingleTon_queue::m_mutex;
//std::mutex MySingleTon_queue::m_mutex_messege;
std::mutex MySingleTon_queue::m_mutex_queue_vector;

std::mutex MySingleTon::m_mutex_messege;
/*��Ŷ��е�����*/
//MySingleTon_queue::Queue_ElementPtr MySingleTon_queue::this_Queue_ElementPtr;
//std::mutex * MySingleTon_queue::this_queue_mutex;

//
void func1(string str) {
	MySingleTon_queue::Queue_Element m_queue;
	//�ڶ�Ӧ�߳��ڴ������ն���Ԫ�ص�ջ��
	//Queue_Element temp
	MySingleTon_queue::Ptr instance = MySingleTon_queue::get_instance();
	m_queue = instance->create_queue("queue2");
	for (int i = 0; i < 1000; ++i) {
		instance->add_event(str, m_queue);
		_sleep(500);
	}

}

void func() {
	MySingleTon_queue::Queue_Element m_queue;
	//�ڶ�Ӧ�߳��ڴ������ն���Ԫ�ص�ջ��
	//Queue_Element temp
	MySingleTon_queue::Ptr instance = MySingleTon_queue::get_instance();
	m_queue = instance->create_queue("queue2");
	for (int i = 0; i < 1000; ++i) {
		instance->add_event("func", m_queue);
		_sleep(500);
	}
	
}


void funcqueueinput1() {
	MySingleTon_queue::Ptr instance = MySingleTon_queue::get_instance();
	MySingleTon_queue::Queue_Element m_queue = instance->create_queue("queue1");
	for (int i = 0; i < 1000; ++i) {
		instance->add_event("funcqueueinput1", m_queue);
		_sleep(10);
	}
}

void funcqueueinput2() {
	MySingleTon_queue::Ptr instance = MySingleTon_queue::get_instance();
	MySingleTon_queue::Queue_Element m_queue = instance->create_queue("queue1");
	for (int i = 0; i < 1000; ++i) {
		instance->add_event("funcqueueinput2", m_queue);
		_sleep(10);
	}
}

void funcqueueoutput() {
	MySingleTon_queue::Ptr m_singleTon = MySingleTon_queue::get_instance();
	MySingleTon_queue::Queue_Element m_queue = m_singleTon->create_queue("queue1");

	for (int i = 0; i < 50;++i)
	{
		string getstr = m_singleTon->get_event(m_queue);
		if (getstr != "")
		{
			cout << m_queue.queue_name + "_" + getstr << endl;
		}

		_sleep(100);
	}

}

//int main(int argc, char *argv[])
//{
//	thread_pool m_thread_pool(3);//�����̳߳��е��߳�����
//	thread_test testitem;
//	m_thread_pool.add_task(func1); //��ͨ���������̳߳صķ���
//	//m_thread_pool.add_task(testitem);//()���غ��������̳߳صķ���
//	m_thread_pool.add_task(bind(&thread_test::testFunc_input, testitem));//������ͨ���������̳߳صķ���
//	m_thread_pool.add_task(bind(&thread_test::testFunc_output, testitem));
//

//	///*֮ǰ���ڹ�һ�����⣺��ʹ�ö��е�ʱ��������������ܻ�ȡ��������Ϊ�߳�ִ�е�˳��̫�̶�*/
//
//	///**************************************************************************
//	//Author: chuck.liu
//	//Date:2021-08-19
//	//Description:
//	//���Ե���ģʽ�����Ķ������������Ȳ����˶��������һ��ָ�����ƵĶ��У����ж�ȡ��ɾ����
//	//Ȼ������������߶��ָ�����ƵĶ��У����̵߳ĶԶ�����н��ж�ȡ��ɾ����
//	//**************************************************************************/
//	//thread_test test1;
//	//thread m_thread4(func);
//	//thread m_thread1(test1);
//	//thread m_thread2(&thread_test::testFunc_input, &test1);
//	//thread m_thread3(&thread_test::testFunc_output, &test1);
//	//
//	//thread m_thread5(funcqueueinput1);
//	//thread m_thread6(funcqueueinput2);
//	//thread m_thread7(funcqueueoutput);
//
//	//m_thread4.join();
//	//m_thread1.join();
//	//m_thread2.join();
//	//m_thread3.join();
//	//
//	//m_thread5.join();
//	//m_thread6.join();
//	//m_thread7.join();
//	///***************************************************************************/
//
//
//	///**************************************************************************
//	//Author: chuck.liu
//	//Date:2021-08-19
//	//Description:
//	//����ʹ�ö��У��û�����������������Ϣͬʱ��Ϊ�����ߣ�
//	//�����趨�û�����Ϊ�����ȼ������ȴ����Ӧ���¼���
//	//**************************************************************************/
//	//SDR_Engine SDR_Engine_test1;
//	//thread m_thread(&SDR_Engine::run, &SDR_Engine_test1);
//	//if (m_thread.joinable()) {
//	//	m_thread.detach();
//	//	//m_thread.join();
//	//}
//	///***************************************************************************/
//
//
//	QApplication a(argc, argv);
//	SDR w;
//	w.show();
//	return a.exec();
//
//	//return 0;
//	
//}
/*********************************************�����������ԣ�ʵ���������ʹ�ã�����֤����Ψһ����˶����������룬��ʵ�����ȼ�����********************************************/



/*************************************************************************�̳߳ز���*************************************************************************************/
std::random_device rd; //��ʵ�����������
std::mt19937 mt(rd()); //���ɼ��������mt;

std::uniform_int_distribution<int> dist(-1000, 1000);//����-1000��1000֮�����ɢ���ȷֲ���
auto rnd = std::bind(dist, mt);


//
void testjj(int i,string te) {
	std::cout << te << "_" << to_string(i) << endl;
}
 
//�����߳�˯��ʱ��
void simulate_hard_computation() {
	std::this_thread::sleep_for(std::chrono::milliseconds(2000 + rnd()));
}

// ����������ֵļ򵥺�������ӡ���
void multiply(const int a, const int b) {
	simulate_hard_computation();
	const int res = a * b;
	std::cout << a << " * " << b << " = " << res << std::endl;
}

//��Ӳ�������
void multiply_output(int & out, const int a, const int b) {
	simulate_hard_computation();
	out = a * b;
	std::cout << a << " * " << b << " = " << out << std::endl;
}

// �������
int multiply_return(const int a, const int b) {
	simulate_hard_computation();
	const int res = a * b;
	std::cout << a << " * " << b << " = " << res << std::endl;
	return res;
}


int main() {
	// ����3���̵߳��̳߳�
	ThreadPool pool(3);

	// ��ʼ���̳߳�
	pool.init();

	// �ύ�˷��������ܹ�30��
	for (int i = 1; i < 3; ++i) {
		for (int j = 1; j < 10; ++j) {
			pool.submit(multiply, i, j);
			pool.submit(testjj, j, "testjj");
		}
	}

	// ʹ��ref���ݵ���������ύ����
	int output_ref;
	auto future1 = pool.submit(multiply_output, std::ref(output_ref), 5, 6);

	// �ȴ��˷�������
	future1.get();
	std::cout << "Last operation result is equals to " << output_ref << std::endl;

	/*************************************************************************************/

	// ʹ��return�����ύ����
	auto future2 = pool.submit(multiply_return, 5, 3);
	// �ȴ��˷�������
	int res = future2.get();
	std::cout << "Last operation result is equals to " << res << std::endl;

	//�ر��̳߳�
	pool.shutdown();
	getchar();
	return 0;
}
/*************************************************************************�̳߳ز���*************************************************************************************/