#include "../Vector.hpp"
#include <vector>
#include <iostream>
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define VIOLET "\033[35m"

int main()
{
	std::cout << RED << "\t=====VECTOR TEST=====" << RESET << std::endl;
	std::vector<int> vec(3, 100);
	ft::vector<int> my_vec(3, 100);

	std::cout << YELLOW << "  =====CONSTRUCTOR=====" << RESET << std::endl;
	std::vector<int>::iterator itr = vec.begin();
	std::vector<int>::iterator ite = vec.end();
	ft::vector<int>::iterator my_itr = my_vec.begin();
	ft::vector<int>::iterator my_ite = my_vec.end();
	std::cout << GREEN << "ORIGINAL = " << RESET;
	while (itr != ite)
	{
		std::cout << *itr << " ";
		itr++;
	}
	std::cout << std::endl;
	std::cout << GREEN << "MY       = " << RESET;
	while (my_itr != my_ite)
	{
		std::cout << *my_itr << " ";
		my_itr++;
	}
	std::cout << std::endl;
	std::cout << YELLOW << "  =====CONSTRUCTOR COPY=====" << RESET << std::endl;
	std::vector<int> vec_cpy(vec);
	ft::vector<int> my_vec_cpy(my_vec);
	itr = vec_cpy.begin();
	ite = vec_cpy.end();
	my_itr = my_vec_cpy.begin();
	my_ite = my_vec_cpy.end();
	std::cout << GREEN << "ORIGINAL = " << RESET;
	while (itr != ite)
	{
		std::cout << *itr << " ";
		itr++;
	}
	std::cout << std::endl;
	std::cout << GREEN << "MY       = " << RESET;
	while (my_itr != my_ite)
	{
		std::cout << *my_itr << " ";
		my_itr++;
	}
	std::cout << std::endl;
	std::cout << YELLOW << "  =====PUSH BACK=====" << RESET << std::endl;
	for (size_t i = 0; i < 10; i++)
	{
		vec.push_back(i);
		my_vec.push_back(i);
	}
	itr = vec.begin();
	ite = vec.end();
	my_itr = my_vec.begin();
	my_ite = my_vec.end();
	std::cout << GREEN << "ORIGINAL = " << RESET;
	while (itr != ite)
	{
		std::cout << *itr << " ";
		itr++;
	}
	std::cout << std::endl;
	std::cout << GREEN << "MY       = " << RESET;
	while (my_itr != my_ite)
	{
		std::cout << *my_itr << " ";
		my_itr++;
	}
	std::cout << std::endl;
	std::cout << GREEN << "ORIGINAL CAPACITY = " << RESET << vec.capacity() << std::endl;
	std::cout << GREEN << "MY CAPACITY       = " << RESET << my_vec.capacity() << std::endl;
	std::cout << YELLOW << "  =====POP BACK=====" << RESET << std::endl;
	vec.pop_back();
	my_vec.pop_back();
	itr = vec.begin();
	ite = vec.end();
	my_itr = my_vec.begin();
	my_ite = my_vec.end();
	std::cout << GREEN << "ORIGINAL = " << RESET;
	while (itr != ite)
	{
		std::cout << *itr << " ";
		itr++;
	}
	std::cout << std::endl;
	std::cout << GREEN << "MY       = " << RESET;
	while (my_itr != my_ite)
	{
		std::cout << *my_itr << " ";
		my_itr++;
	}
	std::cout << std::endl;

	std::cout << YELLOW << "  =====ASSIGN=====" << RESET << std::endl;
	vec.assign(5, 10);
	my_vec.assign(5, 10);
	itr = vec.begin();
	ite = vec.end();
	my_itr = my_vec.begin();
	my_ite = my_vec.end();
	std::cout << GREEN << "ORIGINAL = " << RESET;
	while (itr != ite)
	{
		std::cout << *itr << " ";
		itr++;
	}
	std::cout << std::endl;
	std::cout << GREEN << "MY       = " << RESET;
	while (my_itr != my_ite)
	{
		std::cout << *my_itr << " ";
		my_itr++;
	}
	std::cout << std::endl;

	std::cout << YELLOW << "  =====INSERT=====" << RESET << std::endl;
	vec.insert(++vec.begin(), 20);
	my_vec.insert(++my_vec.begin(), 20);
	itr = vec.begin();
	ite = vec.end();
	my_itr = my_vec.begin();
	my_ite = my_vec.end();
	std::cout << GREEN << "ORIGINAL = " << RESET;
	while (itr != ite)
	{
		std::cout << *itr << " ";
		itr++;
	}
	std::cout << std::endl;
	std::cout << GREEN << "MY       = " << RESET;
	while (my_itr != my_ite)
	{
		std::cout << *my_itr << " ";
		my_itr++;
	}
	std::cout << std::endl;
	vec.insert(vec.end(), 3, 50);
	my_vec.insert(my_vec.end(), 3, 50);
	itr = vec.begin();
	ite = vec.end();
	my_itr = my_vec.begin();
	my_ite = my_vec.end();
	std::cout << GREEN << "ORIGINAL = " << RESET;
	while (itr != ite)
	{
		std::cout << *itr << " ";
		itr++;
	}
	std::cout << std::endl;
	std::cout << GREEN << "MY       = " << RESET;
	while (my_itr != my_ite)
	{
		std::cout << *my_itr << " ";
		my_itr++;
	}
	std::cout << std::endl;
	vec.insert(vec.begin(), vec.begin(), vec.end());
	my_vec.insert(my_vec.begin(), my_vec.begin(), my_vec.end());
		itr = vec.begin();
	ite = vec.end();
	my_itr = my_vec.begin();
	my_ite = my_vec.end();
	std::cout << GREEN << "ORIGINAL = " << RESET;
	while (itr != ite)
	{
		std::cout << *itr << " ";
		itr++;
	}
	std::cout << std::endl;
	std::cout << GREEN << "MY       = " << RESET;
	while (my_itr != my_ite)
	{
		std::cout << *my_itr << " ";
		my_itr++;
	}
	std::cout << std::endl;

	std::cout << YELLOW << "  =====ERASE=====" << RESET << std::endl;
	vec.erase(vec.begin());
	my_vec.erase(my_vec.begin());
	itr = vec.begin();
	ite = vec.end();
	my_itr = my_vec.begin();
	my_ite = my_vec.end();
	std::cout << GREEN << "ORIGINAL = " << RESET;
	while (itr != ite)
	{
		std::cout << *itr << " ";
		itr++;
	}
	std::cout << std::endl;
	std::cout << GREEN << "MY       = " << RESET;
	while (my_itr != my_ite)
	{
		std::cout << *my_itr << " ";
		my_itr++;
	}
	std::cout << std::endl;
	vec.erase(++vec.begin(), --vec.end());
	my_vec.erase(++my_vec.begin(), --my_vec.end());
		itr = vec.begin();
	ite = vec.end();
	my_itr = my_vec.begin();
	my_ite = my_vec.end();
	std::cout << GREEN << "ORIGINAL = " << RESET;
	while (itr != ite)
	{
		std::cout << *itr << " ";
		itr++;
	}
	std::cout << std::endl;
	std::cout << GREEN << "MY       = " << RESET;
	while (my_itr != my_ite)
	{
		std::cout << *my_itr << " ";
		my_itr++;
	}
	std::cout << std::endl;

	std::cout << YELLOW << "  =====SWAP=====" << RESET << std::endl;
	itr = vec.begin();
	ite = vec.end();
	std::cout << GREEN << "ORIGINAL 1 = " << RESET;
	while (itr != ite)
	{
		std::cout << *itr << " ";
		itr++;
	}
	itr = vec_cpy.begin();
	ite = vec_cpy.end();
		std::cout << GREEN << "ORIGINAL 2 = " << RESET;
	while (itr != ite)
	{
		std::cout << *itr << " ";
		itr++;
	}
	std::cout << std::endl;
	vec.swap(vec_cpy);
		itr = vec.begin();
	ite = vec.end();
	std::cout << GREEN << "ORIGINAL SWAP 1 = " << RESET;
	while (itr != ite)
	{
		std::cout << *itr << " ";
		itr++;
	}
	itr = vec_cpy.begin();
	ite = vec_cpy.end();
		std::cout << GREEN << "ORIGINAL SWAP 2 = " << RESET;
	while (itr != ite)
	{
		std::cout << *itr << " ";
		itr++;
	}
	std::cout << std::endl;

	my_itr = my_vec.begin();
	my_ite = my_vec.end();
	std::cout << GREEN << "MY       1 = " << RESET;
	while (my_itr != my_ite)
	{
		std::cout << *my_itr << " ";
		my_itr++;
	}
	my_itr = my_vec_cpy.begin();
	my_ite = my_vec_cpy.end();
	std::cout << GREEN << "MY       2 = " << RESET;
	while (my_itr != my_ite)
	{
		std::cout << *my_itr << " ";
		my_itr++;
	}
	std::cout << std::endl;
	my_vec.swap(my_vec_cpy);
	my_itr = my_vec.begin();
	my_ite = my_vec.end();
	std::cout << GREEN << "MY       SWAP 1 = " << RESET;
	while (my_itr != my_ite)
	{
		std::cout << *my_itr << " ";
		my_itr++;
	}
	my_itr = my_vec_cpy.begin();
	my_ite = my_vec_cpy.end();
	std::cout << GREEN << "MY       SWAP 2 = " << RESET;
	while (my_itr != my_ite)
	{
		std::cout << *my_itr << " ";
		my_itr++;
	}
	std::cout << std::endl;

	std::cout << YELLOW << "  =====SIZE=====" << RESET << std::endl;
	std::cout << GREEN << "ORIGINAL = " << RESET << vec.size() << std::endl;
	std::cout << GREEN << "MY       = " << RESET << my_vec.size() << std::endl;

	std::cout << YELLOW << "  =====MAX SIZE=====" << RESET << std::endl;
	std::cout << GREEN << "ORIGINAL = " << RESET << vec.max_size() << std::endl;
	std::cout << GREEN << "MY       = " << RESET << my_vec.max_size() << std::endl;

	std::cout << YELLOW << "  =====RESIZE=====" << RESET << std::endl;
	vec.resize(5);
	my_vec.resize(5);
	itr = vec.begin();
	ite = vec.end();
	my_itr = my_vec.begin();
	my_ite = my_vec.end();
	std::cout << GREEN << "ORIGINAL = " << RESET;
	while (itr != ite)
	{
		std::cout << *itr << " ";
		itr++;
	}
	std::cout << std::endl;
	std::cout << GREEN << "MY       = " << RESET;
	while (my_itr != my_ite)
	{
		std::cout << *my_itr << " ";
		my_itr++;
	}
	std::cout << std::endl;
	vec.resize(8, 33);
	my_vec.resize(8, 33);
	itr = vec.begin();
	ite = vec.end();
	my_itr = my_vec.begin();
	my_ite = my_vec.end();
	std::cout << GREEN << "ORIGINAL = " << RESET;
	while (itr != ite)
	{
		std::cout << *itr << " ";
		itr++;
	}
	std::cout << std::endl;
	std::cout << GREEN << "MY       = " << RESET;
	while (my_itr != my_ite)
	{
		std::cout << *my_itr << " ";
		my_itr++;
	}
	std::cout << std::endl;
	vec.resize(2);
	my_vec.resize(2);
	itr = vec.begin();
	ite = vec.end();
	my_itr = my_vec.begin();
	my_ite = my_vec.end();
	std::cout << GREEN << "ORIGINAL = " << RESET;
	while (itr != ite)
	{
		std::cout << *itr << " ";
		itr++;
	}
	std::cout << std::endl;
	std::cout << GREEN << "MY       = " << RESET;
	while (my_itr != my_ite)
	{
		std::cout << *my_itr << " ";
		my_itr++;
	}
	std::cout << std::endl;

	std::cout << YELLOW << "  =====EMPTY=====" << RESET << std::endl;
	std::cout << GREEN << "ORIGINAL = " << RESET << vec.empty() << std::endl;
	std::cout << GREEN << "MY       = " << RESET << my_vec.empty() << std::endl;

	std::cout << YELLOW << "  =====RESERVE AND CAPASITY=====" << RESET << std::endl;
	vec.reserve(100);
	my_vec.reserve(100);
	std::cout << GREEN << "ORIGINAL = " << RESET << vec.capacity() << std::endl;
	std::cout << GREEN << "MY       = " << RESET << my_vec.capacity() << std::endl;

	std::cout << YELLOW << "  =====FRONT AND BACK=====" << RESET << std::endl;
	vec.push_back(33);
	my_vec.push_back(33);
	itr = vec.begin();
	ite = vec.end();
	my_itr = my_vec.begin();
	my_ite = my_vec.end();
	std::cout << GREEN << "ORIGINAL = " << RESET;
	while (itr != ite)
	{
		std::cout << *itr << " ";
		itr++;
	}
	std::cout << std::endl;
	std::cout << GREEN << "MY       = " << RESET;
	while (my_itr != my_ite)
	{
		std::cout << *my_itr << " ";
		my_itr++;
	}
	std::cout << std::endl;
	std::cout << GREEN << "ORIGINAL FRONT = " << RESET << vec.front() << std::endl;
	std::cout << GREEN << "MY FRONT       = " << RESET << my_vec.front() << std::endl;

	std::cout << GREEN << "ORIGINAL BACK = " << RESET << vec.back() << std::endl;
	std::cout << GREEN << "MY BACK       = " << RESET << my_vec.back() << std::endl;

	std::cout << YELLOW << "  =====OPERATOR []=====" << RESET << std::endl;
	std::cout << GREEN << "ORIGINAL = " << RESET << vec[0] << std::endl;
	std::cout << GREEN << "MY       = " << RESET << my_vec[0] << std::endl;
	std::cout << GREEN << "ORIGINAL = " << RESET << vec[2] << std::endl;
	std::cout << GREEN << "MY       = " << RESET << my_vec[2] << std::endl;

	std::cout << YELLOW << "  =====CLEAR=====" << RESET << std::endl;
	vec.clear();
	my_vec.clear();
	itr = vec.begin();
	ite = vec.end();
	my_itr = my_vec.begin();
	my_ite = my_vec.end();
	std::cout << GREEN << "ORIGINAL = " << RESET;
	while (itr != ite)
	{
		std::cout << *itr << " ";
		itr++;
	}
	std::cout << std::endl;
	std::cout << GREEN << "MY       = " << RESET;
	while (my_itr != my_ite)
	{
		std::cout << *my_itr << " ";
		my_itr++;
	}
	std::cout << std::endl;
}
