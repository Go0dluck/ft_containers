#include "../Queue.hpp"
#include <queue>
#include <iostream>

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define VIOLET "\033[35m"

int main()
{
	std::cout << RED << "\t=====QUEUE TEST=====" << RESET << std::endl;
	std::cout << YELLOW << "  =====ALL METHOD=====" << RESET << std::endl;
	std::queue<int> que;
	ft::queue<int> my_que;
	for (size_t i = 0; i < 10; i++)
	{
		que.push(i);
		my_que.push(i);
	}
	std::cout << GREEN << "ORIGINAL SIZE = " << RESET << que.size() << std::endl;
	std::cout << GREEN << "MY SIZE       = " << RESET << my_que.size() << std::endl;
	std::cout << GREEN << "ORIGINAL = " << RESET;
	while (!que.empty())
	{
		std::cout << que.front() << " ";
		que.pop();
	}
	std::cout << std::endl;
	std::cout << GREEN << "MY       = " << RESET;
	while (!my_que.empty())
	{
		std::cout << my_que.front() << " ";
		my_que.pop();
	}
	std::cout << std::endl;
}
