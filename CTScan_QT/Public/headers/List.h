#pragma once
#include <list>
#include <mutex>
#include <queue>

template<typename T>
class List
{
private:
	std::list<T> d_consistCmd;
	std::list<T> d_oneTimeCmd;
	typename std::list<T>::iterator d_consistIndex;
	mutable std::mutex d_consistMutex;
	mutable std::mutex d_oneTimeMutex;
	std::condition_variable d_conConsist;
	std::condition_variable d_conOneTime;
	const bool CHOOSECONSISIT = true;
	const bool CHOOSEONETIME = false;
	bool cmdSelect;
public:
	List()
	{
		cmdSelect = CHOOSEONETIME;
	}
	~List()
	{
		{
			std::lock_guard<std::mutex> lk(d_consistMutex);
			d_consistCmd.clear();
		}

		d_consistCmd.clear();
		std::lock_guard<std::mutex> lk(d_oneTimeMutex);

		while (d_oneTimeCmd.size() != 0)
			d_oneTimeCmd.pop_front();
	}
	size_t size()
	{
		std::lock_guard<std::mutex> lk(d_consistMutex);
		return d_consistCmd.size();
	}

	bool pushBack(T& in_cmd, bool in_consist, int in_timeOut = 0)
	{
		if (in_consist)
		{
			std::lock_guard<std::mutex> lk(d_consistMutex);

			if (std::find(d_consistCmd.begin(), d_consistCmd.end(), in_cmd) == d_consistCmd.end())
			{
				d_consistCmd.push_back(in_cmd);
				d_conConsist.notify_all();
				d_consistIndex = d_consistCmd.begin();
			}
		}
		else
		{
			std::lock_guard<std::mutex> lk(d_oneTimeMutex);
			
			if (std::find(d_oneTimeCmd.begin(), d_oneTimeCmd.end(), in_cmd) == d_oneTimeCmd.end())
			{
				d_oneTimeCmd.push_back(in_cmd);
				d_conOneTime.notify_all();
			}
		}
		return true;
	}

	bool deleteNode(T& in_cmd, int in_timeOut = 0)
	{
		std::lock_guard<std::mutex> lk(d_consistMutex);
		
		if (auto itr = std::find(d_consistCmd.begin(), d_consistCmd.end(), in_cmd) != d_consistCmd.end())
		{
			d_consistCmd.erase(itr);
			d_index = d_consistCmd.begin();
			return true;
		}

		return false;
	}

	void clear()
	{
		std::lock_guard<std::mutex> lk(d_consistMutex);
		d_consistCmd.clear();
		d_index = d_consistCmd.end();
	}

	bool getNext(T& in_cmd, int in_timeOut = 0)
	{
		cmdSelect = !cmdSelect;

		if (cmdSelect == CHOOSECONSISIT)
		{
			std::unique_lock<std::mutex> lk(d_consistMutex);
			
			if (d_conConsist.wait_for(lk, std::chrono::milliseconds{10}, [=]() {	return d_consistCmd.size() != 0; }))
			{
				in_cmd = *d_consistIndex;

				if (++d_consistIndex == d_consistCmd.end())
					d_consistIndex = d_consistCmd.begin();

				return true;
			};
		}
		else if (cmdSelect == CHOOSEONETIME)
		{
			std::unique_lock<std::mutex> lk(d_oneTimeMutex);

			if (d_conOneTime.wait_for(lk, std::chrono::milliseconds{ 10 }, [=]() {	return d_oneTimeCmd.size() != 0; }))
			{
				in_cmd = d_oneTimeCmd.front();
				d_oneTimeCmd.pop_front();
				return true;
			}
		}

		return false;
	}
};