#include "testtask.h"

TestTask::TestTask(int infrom,int into)
{
	this->from = from;
	this->to = to;

}

TestTask::TestTask()
{
	this->from = 10;
	this->to = 0;

}

TestTask::~TestTask()
{

}

int Kcountdown(int from, int to)
{
	for (int i = from; i != to; --i) {
		std::cout << i << '\n';
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
	std::cout << "Finished!\n";
	return from - to;
}


//void TestTask::threadTest(int from, int to) {
//
//}

void TestTask::run() {
	PoolCore pool(4);
	std::vector<future<int>>res;
	for (int i = 0; i < 8; ++i)
	{
		//res.emplace_back(pool.submit(countdown(10, 0)));
		res.push_back(pool.submit(Kcountdown, from, to));
	}
	for (int i = 0; i < res.size(); ++i)
	{
		emit sendData(res[i].get());
		//cout << res[i].get() << endl;
	}
}
