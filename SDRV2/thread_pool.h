#pragma once
#include <vector>
#include <deque>
#include <thread>
#include <functional>
#include <mutex>
#include <condition_variable>

#define __SOLA_LOG(level, msg)

//class logger_iface {
//public:
//	//! ctor
//	logger_iface(void) = default;
//	//! dtor
//	virtual ~logger_iface(void) = default;
//
//	//! copy ctor
//	logger_iface(const logger_iface&) = default;
//	//! assignment operator
//	logger_iface& operator=(const logger_iface&) = default;
//
//public:
//	//!
//	//! debug logging
//	//!
//	//! \param msg message to be logged
//	//! \param file file from which the message is coming
//	//! \param line line in the file of the message
//	//!
//	virtual void debug(const std::string& msg, const std::string& file, std::size_t line) = 0;
//
//	//!
//	//! info logging
//	//!
//	//! \param msg message to be logged
//	//! \param file file from which the message is coming
//	//! \param line line in the file of the message
//	//!
//	virtual void info(const std::string& msg, const std::string& file, std::size_t line) = 0;
//
//	//!
//	//! warn logging
//	//!
//	//! \param msg message to be logged
//	//! \param file file from which the message is coming
//	//! \param line line in the file of the message
//	//!
//	virtual void warn(const std::string& msg, const std::string& file, std::size_t line) = 0;
//
//	//!
//	//! error logging
//	//!
//	//! \param msg message to be logged
//	//! \param file file from which the message is coming
//	//! \param line line in the file of the message
//	//!
//	virtual void error(const std::string& msg, const std::string& file, std::size_t line) = 0;
//};
//
////!
////! default logger class provided by the library
////!
//class logger : public logger_iface {
//public:
//	//!
//	//! log level
//	//!
//	enum class log_level {
//		error = 0,
//		warn = 1,
//		info = 2,
//		debug = 3
//	};
//
//public:
//	//! ctor
//	logger(log_level level = log_level::info);
//	//! dtor
//	~logger(void) = default;
//
//	//! copy ctor
//	logger(const logger&) = default;
//	//! assignment operator
//	logger& operator=(const logger&) = default;
//
//public:
//	//!
//	//! debug logging
//	//!
//	//! \param msg message to be logged
//	//! \param file file from which the message is coming
//	//! \param line line in the file of the message
//	//!
//	void debug(const std::string& msg, const std::string& file, std::size_t line);
//
//	//!
//	//! info logging
//	//!
//	//! \param msg message to be logged
//	//! \param file file from which the message is coming
//	//! \param line line in the file of the message
//	//!
//	void info(const std::string& msg, const std::string& file, std::size_t line);
//
//	//!
//	//! warn logging
//	//!
//	//! \param msg message to be logged
//	//! \param file file from which the message is coming
//	//! \param line line in the file of the message
//	//!
//	void warn(const std::string& msg, const std::string& file, std::size_t line);
//
//	//!
//	//! error logging
//	//!
//	//! \param msg message to be logged
//	//! \param file file from which the message is coming
//	//! \param line line in the file of the message
//	//!
//	void error(const std::string& msg, const std::string& file, std::size_t line);
//
//private:
//	//!
//	//! current log level in use
//	//!
//	log_level m_level;
//
//	//!
//	//! mutex used to serialize logs in multithreaded environment
//	//!
//	std::mutex m_mutex;
//};
////!
////! variable containing the current logger
////! by default, not set (no logs)
////!
//extern std::unique_ptr<logger_iface> active_logger;
//
////!
////! debug logging
////! convenience function used internally to call the logger
////!
////! \param msg message to be logged
////! \param file file from which the message is coming
////! \param line line in the file of the message
////!
//void debug(const std::string& msg, const std::string& file, std::size_t line);
//
////!
////! info logging
////! convenience function used internally to call the logger
////!
////! \param msg message to be logged
////! \param file file from which the message is coming
////! \param line line in the file of the message
////!
//void info(const std::string& msg, const std::string& file, std::size_t line);
//
////!
////! warn logging
////! convenience function used internally to call the logger
////!
////! \param msg message to be logged
////! \param file file from which the message is coming
////! \param line line in the file of the message
////!
//void warn(const std::string& msg, const std::string& file, std::size_t line);
//
////!
////! error logging
////! convenience function used internally to call the logger
////!
////! \param msg message to be logged
////! \param file file from which the message is coming
////! \param line line in the file of the message
////!
//void error(const std::string& msg, const std::string& file, std::size_t line);




class thread_pool
{
public:
	//模板类：限定为返回值为void，参数为空任务函数
	typedef std::function<void()> task_t;
	typedef std::function<void(std::string)>task_s;
	thread_pool(int init_size = 3);
	~thread_pool();

	void stop();
	void add_task(const task_t&);  //thread safe;
	//void add_task(const task_s&);  //thread safe;
private:
	//thread_pool(const thread_pool&);//禁止复制拷贝.
	//const thread_pool& operator=(const thread_pool&);

	bool is_started() { return m_is_started; }
	void start();

	void thread_loop();
	task_t take();

	//线程队列
	typedef std::vector<std::thread*> threads_t;
	//任务缓冲队列，线程会执行任务缓冲队列中的任务
	typedef std::deque<task_t> tasks_t;
	//typedef std::deque<tasks_t> taskss_t;
	int m_init_threads_size;

	threads_t m_threads;

	tasks_t m_tasks;
	//taskss_t m_taskss;

	std::mutex m_mutex;
	std::condition_variable m_cond;
	bool m_is_started;
};

