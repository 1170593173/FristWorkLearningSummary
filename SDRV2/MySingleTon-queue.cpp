#include"MySingleTon-queue.h"

/*队列操作：添加事件数据*/
bool  MySingleTon_queue::add_event(const std::string &new_event, const std::string &queue_name, int priority) {
	bool isSucceed = false;
	Queue_Element temp = get_queue(queue_name);
	isSucceed=temp.queue_name != "";
	//isSucceed = get_queue(queue_name);
	if (isSucceed) {
		std::lock_guard<std::mutex> m_lk(*temp.m_queue_mutex);
		if (priority==1)
		{
			(*temp.m_Queue_ElementPtr).push_front(new_event);
		}
		else {
			(*temp.m_Queue_ElementPtr).push_back(new_event);
		}
	}
	return isSucceed;
}

/*队列操作：获取事件数据*/
std::string MySingleTon_queue::get_event(const std::string &queue_name) {
	std::string result = "";

	bool isSucceed = false;
	Queue_Element temp = get_queue(queue_name);
	isSucceed = temp.queue_name != "";
	if (isSucceed) {
		std::lock_guard<std::mutex> m_lk(*temp.m_queue_mutex);
		if ((*temp.m_Queue_ElementPtr).empty()) {
			//std::cout << "the queue is empty" << std::endl;
		}
		else {
			result = (*temp.m_Queue_ElementPtr).front();
			(*temp.m_Queue_ElementPtr).pop_front();
		}
		//(*this_Queue_ElementPtr).push_back(new_event);
		result = queue_name + result;
	}
	return result;
}

/*队列操作：清除队列*/
bool MySingleTon_queue::clear_event(const std::string &queue_name) {
	bool isSucceed = false;
	Queue_Element temp = get_queue(queue_name);
	isSucceed = temp.queue_name != "";
	if (isSucceed) {
		std::lock_guard<std::mutex> m_lk(*temp.m_queue_mutex);
		(*temp.m_Queue_ElementPtr).clear();
		isSucceed = true;
	}
	return isSucceed;
}

bool MySingleTon_queue::is_empty(const std::string &queue_name) {
	bool isSucceed = false;
	Queue_Element temp = get_queue(queue_name);
	isSucceed = temp.queue_name != "";
	if (isSucceed) {
		isSucceed = (*temp.m_Queue_ElementPtr).empty();
	}
	return isSucceed;
}




/*******************************************************************************************************/
/*队列操作：添加事件数据*/
bool  MySingleTon_queue::add_event(const std::string &new_event, const Queue_Element &m_queue,int priority) {
	bool isSucceed = false;
	//Queue_Element temp = get_queue(queue_name);
	isSucceed = m_queue.queue_name != "";
	//isSucceed = get_queue(queue_name);
	if (isSucceed) {
		//std::lock_guard<std::mutex> m_lk(*m_queue.m_queue_mutex);
		m_queue.m_queue_mutex->lock();
		if (priority == 1) {
			(*m_queue.m_Queue_ElementPtr).push_front(new_event);
		}
		else
		{
			(*m_queue.m_Queue_ElementPtr).push_back(new_event);
		}
		
		m_queue.m_queue_mutex->unlock();
	}
	return isSucceed;
}

//bool MySingleTon_queue::priority_add_event(const std::string &new_event, const Queue_Element &m_queue) {
//	bool isSucceed = false;
//	//Queue_Element temp = get_queue(queue_name);
//	isSucceed = m_queue.queue_name != "";
//	//isSucceed = get_queue(queue_name);
//	if (isSucceed) {
//		//std::lock_guard<std::mutex> m_lk(*m_queue.m_queue_mutex);
//		m_queue.m_queue_mutex->lock();
//		(*m_queue.m_Queue_ElementPtr).push_front(new_event);
//		m_queue.m_queue_mutex->unlock();
//	}
//	return isSucceed;
//}

/*队列操作：获取事件数据*/
std::string MySingleTon_queue::get_event(const Queue_Element &m_queue) {
	std::string result = "";

	bool isSucceed = false;
	//Queue_Element m_queue = get_queue(queue_name);
	isSucceed = m_queue.queue_name != "";
	if (isSucceed) {
		m_queue.m_queue_mutex->lock();
		//std::lock_guard<std::mutex> m_lk(*m_queue.m_queue_mutex);
		if (!(*m_queue.m_Queue_ElementPtr).empty()) {
			result = (*m_queue.m_Queue_ElementPtr).front();
			(*m_queue.m_Queue_ElementPtr).pop_front();
		}
		m_queue.m_queue_mutex->unlock();
		//(*this_Queue_ElementPtr).push_back(new_event);
		//result = m_queue.queue_name + result;
	}
	return result;
}

/*队列操作：清除队列*/
bool MySingleTon_queue::clear_event(const Queue_Element &m_queue) {
	bool isSucceed = false;
	//Queue_Element temp = get_queue(queue_name);
	isSucceed = m_queue.queue_name != "";
	if (isSucceed) {
		m_queue.m_queue_mutex->lock();
		//std::lock_guard<std::mutex> m_lk(*m_queue.m_queue_mutex);
		(*m_queue.m_Queue_ElementPtr).clear();
		m_queue.m_queue_mutex->unlock();
		isSucceed = true;
	}
	return isSucceed;
}

bool MySingleTon_queue::is_empty(const Queue_Element &m_queue) {
	bool isSucceed = false;
	//Queue_Element m_queue = get_queue(queue_name);
	isSucceed = m_queue.queue_name != "";
	if (isSucceed) {
		m_queue.m_queue_mutex->lock();
		isSucceed = (*m_queue.m_Queue_ElementPtr).empty();
		m_queue.m_queue_mutex->unlock();
	}
	return isSucceed;
}


/*队列容器操作：创建队列元素入队*/
MySingleTon_queue::Queue_Element MySingleTon_queue::create_queue(const std::string & queue_name)
{

	bool isExist = false;
	Queue_Element one_element;
	std::list<Queue_Element>::iterator it;
	//std::unique_lock <std::mutex>m_ulk(m_mutex_queue_vector);
	////std::lock(m_ulk);
	//m_ulk.lock();

	//std::lock_guard<std::mutex> m_lk(m_mutex_queue_vector);
	m_mutex_queue_vector.lock();
	for (it = Queue_List.begin(); it != Queue_List.end(); ++it) {
		if ((*it).queue_name == queue_name) {
			one_element = (*it);
			isExist = true;
			break;
		}
	}
	
	if (!isExist) {
		one_element.queue_name = queue_name;
		one_element.m_queue_mutex = new mutex();
		one_element.m_Queue_ElementPtr = new deque<std::string>();

		/*在创建队列时对存放队里的容器加锁*/
		//std::lock_guard<std::mutex> m_lk(m_mutex_queue_vector);
		Queue_List.push_back(one_element);
		isExist = true;
	}
	m_mutex_queue_vector.unlock();
	//this->this_Queue_ElementPtr = one_element.m_Queue_ElementPtr;
	return one_element;
}
/*队列容器操作：删除容器中的元素*/
bool MySingleTon_queue::delete_queue(const std::string & queue_name)
{
	bool isSucceed = false;
	std::list<Queue_Element>::iterator it;

	//std::unique_lock <std::mutex>m_ulk(m_mutex_queue_vector);
	//m_ulk.lock();

	//std::lock_guard<std::mutex> m_lk(m_mutex_queue_vector);
	m_mutex_queue_vector.lock();
	for (it = Queue_List.begin(); it != Queue_List.end(); ++it) {
		if ((*it).queue_name == queue_name) {
			//std::lock_guard<std::mutex> m_lk(m_mutex_queue_vector);
			delete (*it).m_Queue_ElementPtr;
			delete (*it).m_queue_mutex;
			Queue_List.erase(it);
			isSucceed = true;
			break;
		}
	}
	m_mutex_queue_vector.unlock();
	return isSucceed;//返回false代表容器内没有对应的队列
}

/*队列容器操作：获取容器中的元素*/
MySingleTon_queue::Queue_Element MySingleTon_queue::get_queue(const std::string & queue_name)
{
	Queue_Element temp;
	bool isExist = false;
	std::list<Queue_Element>::iterator it;
	m_mutex_queue_vector.lock();
	for (it = Queue_List.begin(); it != Queue_List.end(); ++it) {
		if ((*it).queue_name == queue_name) {
			//std::lock_guard<std::mutex> m_lk(m_this_mutex);
			temp.queue_name = (*it).queue_name;
			temp.m_Queue_ElementPtr = (*it).m_Queue_ElementPtr;
			temp.m_queue_mutex= (*it).m_queue_mutex;
			/*this->this_Queue_ElementPtr = (*it).m_Queue_ElementPtr;
			this->this_queue_mutex = (*it).m_queue_mutex;*/
			isExist = true;
			break;
		}
	}
	m_mutex_queue_vector.unlock();
	return temp;
}

/*析构函数：需要将所有的指针析构*/
MySingleTon_queue::~MySingleTon_queue() {
	std::list<Queue_Element>::iterator it;
	for (it = Queue_List.begin(); it != Queue_List.end(); ++it) {
		delete (*it).m_Queue_ElementPtr;
		delete (*it).m_queue_mutex;
		Queue_List.erase(it);
	}
}