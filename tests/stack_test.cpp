#include "../Stack.hpp"
#include <stack>
#include <iostream>

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define VIOLET "\033[35m"

int main()
{
	std::cout << RED << "\t=====STACK TEST=====" << RESET << std::endl;
	std::cout << YELLOW << "  =====ALL METHOD=====" << RESET << std::endl;
	std::stack<int> stk;
	ft::stack<int> my_stk;
	for (size_t i = 0; i < 10; i++)
	{
		stk.push(i);
		my_stk.push(i);
	}
	std::cout << GREEN << "ORIGINAL SIZE = " << RESET << stk.size() << std::endl;
	std::cout << GREEN << "MY SIZE       = " << RESET << my_stk.size() << std::endl;
	std::cout << GREEN << "ORIGINAL = " << RESET;
	while (!stk.empty())
	{
		std::cout << stk.top() << " ";
		stk.pop();
	}
	std::cout << std::endl;
	std::cout << GREEN << "MY       = " << RESET;
	while (!my_stk.empty())
	{
		std::cout << my_stk.top() << " ";
		my_stk.pop();
	}
	std::cout << std::endl;
}
