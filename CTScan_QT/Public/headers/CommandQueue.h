#pragma once
#include <queue>
#include <mutex>
#include <chrono>
using std::queue;
template<typename T>
class TheQueue
{
private:
    std::queue<T> d_queue;
    mutable std::mutex d_hmtxQ;
    std::condition_variable d_con;
	using millseconds = std::chrono::duration < long, std::ratio<1, 1000>>;
public:
    TheQueue()
    {

    }
    ~TheQueue()
    {
		clear();
    }
    size_t size() 
    {
        std::lock_guard<std::mutex> lk(d_hmtxQ);
        return d_queue.size();
    }

	size_t getQueueSize() { return d_queue.size(); }

    bool push(T& in_cmd, millseconds in_timeOut = millseconds(10))
    {
        std::lock_guard<std::mutex> lk(d_hmtxQ);
        d_queue.push(in_cmd);
        d_con.notify_all();
        return true;
    }

    bool pop(T& in_cmd, millseconds in_timeOut = millseconds(10))
    {
        std::unique_lock<std::mutex> lk(d_hmtxQ);

		if (d_con.wait_for(lk, in_timeOut, [=] { return getQueueSize() != 0; }))
		{
			in_cmd = d_queue.front();
			d_queue.pop();
			return true;
		}

		return false;
    }

    void clear()
    {
        std::lock_guard<std::mutex> lk(d_hmtxQ);
        
        while(d_queue.size() != 0)
            d_queue.pop();
    }

};