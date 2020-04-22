#pragma once
#include <queue>
#include <mutex>
using std::queue;
template<typename T>
class TheQueue
{
private:
    std::queue<T> d_queue;
    mutable std::mutex d_hmtxQ;
    std::condition_variable d_con;
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

    bool push(T& in_cmd, int in_timeOut = 0)
    {
        std::lock_guard<std::mutex> lk(d_hmtxQ);
        d_queue.push(in_cmd);
        d_con.notify_all();
        return true;
    }

    bool pop(T& in_cmd, int in_timeOut = 0)
    {
        std::unique_lock<std::mutex> lk(d_hmtxQ);
        int size = d_queue.size();
        d_con.wait(lk, [&] { return size != 0; });
        in_cmd = d_queue.front();
        d_queue.pop();
        return true;
    }

    void clear()
    {
        std::lock_guard<std::mutex> lk(d_hmtxQ);
        
        while(d_queue.size() != 0)
            d_queue.pop();
    }

};