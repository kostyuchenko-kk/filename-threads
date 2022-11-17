// THIS FILE IS STUB FOR INPUT AND OUTPUT DATA
// DO NOT MODIFICATE IT - IT`S PART OF ANOTHER PROJECT

// это файл-заглушка, для демонстрации как метод будет вызван.
// не модифицируйте его - возможно это часть другого проекта

#include <iostream>
#include <fstream>
#include <chrono>

#include "task.h"

int main()
{
	std::vector<std::string> input;
	std::ifstream in("input.txt");
	if (in.is_open())
	{
		std::string filepath;
		while(std::getline(in, filepath))
		{
			input.push_back(filepath);
		}
	}
	else
	{
		std::cout << "Internal Error: Can not open input file." << std::endl;
		return -1;
	}
	std::string output;
	auto start = std::chrono::high_resolution_clock::now();
	output = Task::findMostCommonFile(input);
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<float> duration = end - start;
	std::cout << "Execution time: " << duration.count() << std::endl;


	// output
	std::ofstream out;
	out.open("output.txt");
	if (out.is_open())
	{
			out << output << std::endl;
			out.close();
	}
	else
	{
		std::cout << "Internal Error: Can not open output file." << std::endl;
		return -1;
	}
	std::string yo;
	std::cin >> yo;
	return 0;
}
