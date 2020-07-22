#include "stdafx.h"
#include "thread.h"

Thread::Thread(std::function<void()>  in_function, bool& in_threadRun)
{
	d_threadRun = in_threadRun;
	d_fun = in_function;
	d_threadPromisePtr.reset(new std::promise<bool>());
}

Thread::~Thread()
{

}
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
		d_thread->detach();
		return true;
	}

	return false;
}



Thread::promistPtr Thread::d_threadPromisePtr = nullptr;
void Thread::realThread()
{
	d_threadPromisePtr->set_value_at_thread_exit(true);
	d_fun();
}



void Thread::stopThread()
{
	d_threadRun = false;
	d_threadPromisePtr->get_future().get();
}

