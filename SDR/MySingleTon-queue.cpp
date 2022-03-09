#include"MySingleTon-queue.h"

/*添加事件数据*/
void  MySingleTon_queue::add_event(const std::string &new_event) {

	std::lock_guard<std::mutex> m_lk(m_mutex_messege);
	m_queue.push_back(new_event);
}

/*获取事件数据*/
std::string MySingleTon_queue::get_event() {
	std::string result="";
	std::lock_guard<std::mutex> m_lk(m_mutex_messege);
	if (m_queue.empty()) {
		std::cout << "the queue is empty" << std::endl;
	}
	else {
		result = m_queue.front();
		m_queue.pop_front();
	}
	return result;
}

/*清除队列*/
void MySingleTon_queue::clear_event() {
	std::lock_guard<std::mutex> m_lk(m_mutex_messege);
	m_queue.clear();
}

bool MySingleTon_queue::is_empty() {
	return m_queue.empty();
}