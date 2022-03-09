#include<iostream>
#include <queue>
#include"thread_poolV2.h"


std::mutex g_mutex;

void priorityFunc() {
	for (int i = 1; i < 4; ++i) {
		std::this_thread::sleep_for(std::chrono::seconds(1));
		std::lock_guard<std::mutex> lock(g_mutex);
		std::cout << "priorityFunc() [" << i << "] at thread [ " << std::this_thread::get_id() << "] " << std::endl;
	}
}
void testFunc()
{   
	// loop to print character after a random period of time   
	for (int i = 1; i < 4; ++i)   
	{       
		std::this_thread::sleep_for(std::chrono::seconds(1));       
		std::lock_guard<std::mutex> lock(g_mutex); 
		std::cout << "testFunc() [" << i << "] at thread [ " << std::this_thread::get_id() << "] " << std::endl;
	} 
}

int main() {
	ThreadPool threadPool;   
	threadPool.start();
	for (int i = 0; i < 5; i++)     
		threadPool.addTask(testFunc);
	std::this_thread::sleep_for(std::chrono::seconds(1));
	threadPool.addTask(ThreadPool::TaskPair(ThreadPool::level2, priorityFunc));
	getchar();
	return 0;
}