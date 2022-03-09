#include "threadpool.h"
#include <QtWidgets/QApplication>
#include "PoolCore.h"


#include <iostream>       // std::cout
#include <thread>         // std::thread
#include <mutex>          // std::mutex

#include <future>       // std::packaged_task, std::future
#include <chrono>       // std::chrono::seconds

using namespace std;

volatile int counter(0); // non-atomic counter
std::mutex mtx;           // locks access to counter

//void attempt_10k_increases() {
//	for (int i = 0; i < 10000; ++i) {
//		if (mtx.try_lock()) {   // only increase if currently not locked:
//			++counter;
//			//std::cout << counter << std::endl;
//			mtx.unlock();
//
//		}
//	}
//}
//
//// count down taking a second for each value:
//int countdown(int from, int to) {
//	for (int i = from; i != to; --i) {
//		std::cout << i << '\n';
//		std::this_thread::sleep_for(std::chrono::seconds(1));
//	}
//	std::cout << "Finished!\n";
//	return from - to;
//}



/*��Ҫ֪ʶ�㣺

C++ explicit��ָ�����캯����ת������ (C++11��)Ϊ��ʽ, ��������������ʽת���͸��Ƴ�ʼ��.

std::function����ģ��std::function��һ��ͨ�á���̬�ĺ�����װ��std::function��ʵ�����Զ��κο��Ե��õ�Ŀ��ʵ����д洢�����ơ��͵��ò�����
��ЩĿ��ʵ�������ͨ������Lambda���ʽ������ָ�롢�Լ�������������ȡ�

std::forwardͨ������������ת���ģ����Ὣ����Ĳ���ԭ�ⲻ���ش��ݵ���һ�������У������ԭ�ⲻ����ָ���ǣ��������Ĳ�������ֵ����ô���ݸ���һ�������Ĳ�����Ҳ����ֵ��
�������Ĳ�������ֵ����ô���ݸ���һ�������Ĳ�����Ҳ����ֵ��

std::bind��bind������һ�ֻ��ƣ�������Ԥ�Ȱ�ָ���ɵ���ʵ���ĳЩ�����󶨵����еı���������һ���µĿɵ� ��ʵ��

std::��������ģ�塢�������ͺ���

std::future ->promise��packaged_taskh��futrue
	promise��������Ա���ĳһ���� T ��ֵ����ֵ�ɱ� future �����ȡ������������һ���߳��У���
��� promise Ҳ�ṩ��һ���߳�ͬ�����ֶΡ��� promise ������ʱ���Ժ�һ������״̬��ͨ����std::future���������
��������������Ĺ���״̬(std::future)�ϱ���һ������Ϊ T ��ֵ��
	std::packaged_task����װһ���ɵ��õĶ��󣬲��������첽��ȡ�ÿɵ��ö�������Ľ����
	�Ӱ�װ�ɵ��ö���������������std::packaged_task �� std::function ���ƣ�
	ֻ���� std::packaged_task �����װ�Ŀɵ��ö����ִ�н�����ݸ�һ�� std::future ����
	���ö���ͨ��������һ���߳��л�ȡ std::packaged_task �����ִ�н������

std::condition_variable ��unique_lock���߳���

decltype�ؼ��֣�����Ӧ�ĺ����������ͱ��������ƶϣ��ж���������ʲô

*/


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	ThreadPool w;
	w.show();


	//std::packaged_task<int(int, int)> task(countdown); // ���� packaged_task
	//std::future<int> ret = task.get_future(); // ����� packaged_task ����״̬������� future ����.

	//std::thread th(std::move(task), 10, 0);   //����һ�����߳���ɼ�������.

	//int value = ret.get();                    // �ȴ�������ɲ���ȡ���.

	//std::cout << "The countdown lasted for " << value << " seconds.\n";

	//th.join();




	//std::thread threads[10];
	//for (int i = 0; i < 10; ++i)
	//	threads[i] = std::thread(attempt_10k_increases);

	//for (auto& th : threads) th.join();
	//std::cout << counter << " successful increases of the counter.\n";

	//PoolCore pool(4);
	//std::vector<std::future<int>> results;
	//for (int i = 0; i < 8; ++i) {
	//	results.emplace_back(pool.submit([]() {
	//		// computing task and return result

	//		for (int i = 0; i < 1000;++i)
	//		{
	//			std::cout << i << std::endl;
	//		}
	//	}));
	//}
	//for (auto && result : results)
	//	std::cout << result.get() << ' ';



	//PoolCore pool(4);
	//std::vector<future<int>>res;

	//for (int i = 0; i < 8;++i)
	//{
	//	//res.emplace_back(pool.submit(countdown(10, 0)));
	//	res.push_back(pool.submit(countdown, 10, 0));
	//}
	//for (int i = 0; i < res.size();++i)
	//{
	//	cout << res[i].get() << endl;
	//}


	return a.exec();
}
