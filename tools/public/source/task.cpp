// this file you need to fill
// этот файл вам нужно заполнить
#include "task.h"
#include <unordered_map>
#include<thread>
#include<mutex>


std::string Task::findMostCommonFile(std::vector<std::string> input)
{
	std::unordered_map<std::string, int> rep_numb_map;
	rep_numb_map.reserve(input.size());
	int max_repeat_numb = 1;
	std::string max_repeat_key;
	std::mutex th_mutex;

	auto thread_lambda = [&](size_t begin, size_t end)
	{	
		bool isDot = false;
		std::string curr_filename;
		size_t curr_rep_numb;
		for (size_t i = begin; i < end; i++)
		{
			for (auto it = input[i].rbegin(); it != input[i].rend();++it)
			{
				if (*it == '/')
				{
					if (isDot)
					{
						isDot = false;
						curr_filename = std::string(it.base(), input[i].end());
						std::lock_guard<std::mutex> lock(th_mutex);
						curr_rep_numb = ++rep_numb_map[curr_filename];
						if (curr_rep_numb > max_repeat_numb)
						{
							max_repeat_key = curr_filename;
							max_repeat_numb = curr_rep_numb;
						}

						break;
					}
					else
					{
						break;
					}

				}
				if (*it == '.')
				{
					isDot = true;

				}
			}
		}

	};

	std::thread thread1(thread_lambda, 0, input.size()/2);
	thread_lambda(input.size() / 2, input.size());
	
	thread1.join();

	return max_repeat_key;
}
