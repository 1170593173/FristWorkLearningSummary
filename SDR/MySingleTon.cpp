#include "MySingleTon.h"

/*添加事件数据*/
void  MySingleTon::add_event(const std::string &new_event) {
	if (messege_size - 1 != _in) {//当out不等于size-1时
		if (_in == _out - 1) {//如果out+1=in就代表满了；
			std::cout << "queue is full!";
			return;
		}
		else {
			std::lock_guard<std::mutex> m_lk(m_mutex_messege);
			messege_queue[_in] = new_event;
			++_in;
		}
	}
	else {
		if (_out != 0) {
			std::lock_guard<std::mutex> m_lk(m_mutex_messege);
			messege_queue[_in] = new_event;
			_in=0;
		}
		else {
			std::cout << "queue is full!" << std::endl;
			return;
		}
	}
}

/*获取事件数据*/
std::string MySingleTon::get_event() {
	std::string result="";
	if (_out!=_in) {
		result = messege_queue[_out];
		if (_out == messege_size - 1) {
			_out = 0;
		}
		else {
			_out++;
		}
	}
	else {
		//std::cout << "the queue is empty" << std::endl;
		result = "the queue is empty";
	}
	return result;
}

/*清除队列*/
void MySingleTon::clear_event() {
	std::lock_guard<std::mutex> m_lk(m_mutex_messege);
	messege_queue.clear();
	_out = 0;
	_in = 0;
}

bool MySingleTon::is_empty() {
	return _out == _in;
}