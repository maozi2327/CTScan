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
	Thread(std::function<void()> in_function, bool& in_threadRun);
	~Thread();
	bool join();
	bool detach();
	void stopThread();
};

