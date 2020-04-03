#pragma once
#include <thread>
#include <future>
#include <functional>

class Thread
{
private:
	using promistPtr = std::unique_ptr<std::promise<bool>>;
	static promistPtr d_threadPromisePtr;
	std::unique_ptr<std::thread> d_thread;
	std::function<void()> d_fun;
	void realThread();
	bool d_threadRun;
public:
	template <typename T>
	Thread(T&& in_function, bool& in_threadRun);
	~Thread();
	bool join();
	bool detach();
	bool stopThread();
};

bool Thread::join()
{
	if (d_threadPromisePtr->get_future().get() == false)
	{
		std::function<void()> sendThreadFun = std::bind(&Thread::realThread, this);
		d_thread.reset(new std::thread(sendThreadFun));
		d_thread->join();
		return true;
	}

	return false;
}

bool Thread::detach()
{
	if (d_threadPromisePtr->get_future().get() == false)
	{
		std::function<void()> sendThreadFun = std::bind(&Thread::realThread, this);
		d_thread.reset(new std::thread(sendThreadFun));
		d_thread->join();
		return true;
	}

	return false;
}

template<typename T>
inline Thread::Thread(T && in_function, bool& in_threadRun)
{
	d_threadRun = in_threadRun;
	d_fun = in_function;
	d_threadPromisePtr.reset(new std::promise<bool>(false));
}
