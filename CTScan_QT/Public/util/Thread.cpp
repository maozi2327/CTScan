#include "stdafx.h"
#include "Thread.h"

Thread::promistPtr Thread::d_threadPromisePtr = nullptr;
void Thread::realThread()
{
	d_threadPromisePtr->set_value_at_thread_exit(true);
	d_fun();
}


Thread::~Thread()
{

}

void Thread::stopThread()
{
	d_threadRun = false;
	d_threadPromisePtr->get_future().get();
}

