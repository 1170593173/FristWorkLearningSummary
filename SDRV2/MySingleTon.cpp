#include "MySingleTon.h"

/*����¼�����*/
void  MySingleTon::add_event(const std::string &new_event) {
	if (messege_size - 1 != _in) {//��out������size-1ʱ
		if (_in == _out - 1) {//���out+1=in�ʹ������ˣ�
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

/*��ȡ�¼�����*/
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

/*�������*/
void MySingleTon::clear_event() {
	std::lock_guard<std::mutex> m_lk(m_mutex_messege);
	messege_queue.clear();
	_out = 0;
	_in = 0;
}

bool MySingleTon::is_empty() {
	return _out == _in;
}