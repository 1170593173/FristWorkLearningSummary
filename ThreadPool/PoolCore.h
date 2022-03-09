#pragma once
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <future>

class PoolCore
{
public:
	//explicitָ�����캯����ת������ (C++11��)Ϊ��ʽ, ��������������ʽת���͸��Ƴ�ʼ��.
	explicit PoolCore(size_t threadNum);
	~PoolCore();

	//����ģ�塢�ɱ����ģ��
	template<typename F, typename... Args>
	//�������ͺ��ã�auto getSum(int a, int b)->int;����ķ������ͺ��÷��ص���future����future����Ĳ���ʹ�ú����ƶϱ�ʶ����f(args...)�����ƶ�
	auto submit(F&& f, Args&&... args) -> std::future<decltype(f(args...))> {
		//����ʹ��packaged_task��f(args...)����ֵ���ͽ��з�װ��Ŀ������������߳����첽�Ļ�ȡ�������ĺ�������ֵ��
		//Ȼ���packaged_task��������ָ�룬Ŀ���Ǳ��ڸ�ֵ��������������
		//ʹ��bind�Ժ�����������а󶨣�����һ���µĿɵ���ʵ��
		auto taskPtr = std::make_shared<std::packaged_task<decltype(f(args...))()>>(
			std::bind(std::forward<F>(f), std::forward<Args>(args)...)
			);
		{
			//���Ի�ȡ�����̵߳��߳������Ե��õľ��taskPtr���з�װ����װΪvoid ()���ͣ��������Ӧ���������
			std::unique_lock<std::mutex> ul(mtx_);
			if (stop_) { throw std::runtime_error("submit on stopped ThreadPool"); }
			tasks_.emplace([taskPtr]() { (*taskPtr)(); });
			//�뿪������unique_lock���������Զ���������ҪĿ���Ƿ�ֹ ��Ϊ���ǽ���������쳣�������ǽ���
		}
		//��������֪ͨ�����߳̿��Խ������ľ���
		cv_.notify_one();
		//taskPtr��������futrue<>���͵ģ�����ͨ��get_future����ȡ��Ӧ�İ󶨵�promise�Ľ������packed_task�ķ��ؽ��
		return taskPtr->get_future();
	}

private:
	bool stop_;
	std::vector<std::thread>workers_;//�������У��ɶ���߳���ɵĶ���
	std::queue<std::function<void()>>tasks_;//�������
	std::mutex mtx_;
	std::condition_variable cv_;
};

