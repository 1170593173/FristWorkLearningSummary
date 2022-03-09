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



/*主要知识点：

C++ explicit：指定构造函数或转换函数 (C++11起)为显式, 即它不能用于隐式转换和复制初始化.

std::function：类模版std::function是一种通用、多态的函数封装。std::function的实例可以对任何可以调用的目标实体进行存储、复制、和调用操作，
这些目标实体包括普通函数、Lambda表达式、函数指针、以及其它函数对象等。

std::forward通常是用于完美转发的，它会将输入的参数原封不动地传递到下一个函数中，这个“原封不动”指的是，如果输入的参数是左值，那么传递给下一个函数的参数的也是左值；
如果输入的参数是右值，那么传递给下一个函数的参数的也是右值。

std::bind：bind是这样一种机制，它可以预先把指定可调用实体的某些参数绑定到已有的变量，产生一个新的可调 用实体

std::不定参数模板、返回类型后置

std::future ->promise、packaged_taskh、futrue
	promise：对象可以保存某一类型 T 的值，该值可被 future 对象读取（可能在另外一个线程中），
因此 promise 也提供了一种线程同步的手段。在 promise 对象构造时可以和一个共享状态（通常是std::future）相关联，
并可以在相关联的共享状态(std::future)上保存一个类型为 T 的值。
	std::packaged_task：包装一个可调用的对象，并且允许异步获取该可调用对象产生的结果，
	从包装可调用对象意义上来讲，std::packaged_task 与 std::function 类似，
	只不过 std::packaged_task 将其包装的可调用对象的执行结果传递给一个 std::future 对象
	（该对象通常在另外一个线程中获取 std::packaged_task 任务的执行结果）。

std::condition_variable 和unique_lock，线程锁

decltype关键字：对相应的函数或者类型变量进行推断，判断其类型是什么

*/


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	ThreadPool w;
	w.show();


	//std::packaged_task<int(int, int)> task(countdown); // 设置 packaged_task
	//std::future<int> ret = task.get_future(); // 获得与 packaged_task 共享状态相关联的 future 对象.

	//std::thread th(std::move(task), 10, 0);   //创建一个新线程完成计数任务.

	//int value = ret.get();                    // 等待任务完成并获取结果.

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
