#include "../List.hpp"
#include <list>
#include <iostream>

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define VIOLET "\033[35m"

bool single_digit (const int& value)
{
	return (value<70);
}

int main()
{
	std::cout << RED << "\t=====LIST TEST=====" << RESET << std::endl;
	std::cout << YELLOW << "  =====CONSTRUCTOR=====" << RESET << std::endl;
	std::list<char> lst(5, 'a');
	ft::list<char> my_lst(5, 'a');
	std::list<char>::iterator itr = lst.begin();
	std::list<char>::iterator ite = lst.end();
	ft::list<char>::iterator my_itr = my_lst.begin();
	ft::list<char>::iterator my_ite = my_lst.end();
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
	std::list<char> lst_cpy(lst);
	ft::list<char> my_lst_cpy(my_lst);
	itr = lst.begin();
	ite = lst.end();
	my_itr = my_lst.begin();
	my_ite = my_lst.end();
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
		lst.push_back(i + 65);
		my_lst.push_back(i + 65);
	}
	itr = lst.begin();
	ite = lst.end();
	my_itr = my_lst.begin();
	my_ite = my_lst.end();
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

	std::cout << YELLOW << "  =====POP BACK=====" << RESET << std::endl;
	lst.pop_back();
	my_lst.pop_back();
	itr = lst.begin();
	ite = lst.end();
	my_itr = my_lst.begin();
	my_ite = my_lst.end();
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

	std::cout << YELLOW << "  =====PUSH FRONT=====" << RESET << std::endl;
	for (size_t i = 0; i < 10; i++)
	{
		lst.push_front(i + 48);
		my_lst.push_front(i + 48);
	}
	itr = lst.begin();
	ite = lst.end();
	my_itr = my_lst.begin();
	my_ite = my_lst.end();
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

	std::cout << YELLOW << "  =====POP FRONT=====" << RESET << std::endl;
	lst.pop_front();
	my_lst.pop_front();
	itr = lst.begin();
	ite = lst.end();
	my_itr = my_lst.begin();
	my_ite = my_lst.end();
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
	std::cout << GREEN << "ORIGINAL = " << RESET << lst.empty() << std::endl;
	std::cout << GREEN << "MY       = " << RESET << my_lst.empty() << std::endl;

	std::cout << YELLOW << "  =====SIZE=====" << RESET << std::endl;
	std::cout << GREEN << "ORIGINAL = " << RESET << lst.size() << std::endl;
	std::cout << GREEN << "MY       = " << RESET << my_lst.size() << std::endl;

	std::cout << YELLOW << "  =====MAX SIZE=====" << RESET << std::endl;
	std::cout << GREEN << "ORIGINAL = " << RESET << lst.max_size() << std::endl;
	std::cout << GREEN << "MY       = " << RESET << my_lst.max_size() << std::endl;

	std::cout << YELLOW << "  =====FRONT=====" << RESET << std::endl;
	std::cout << GREEN << "ORIGINAL = " << RESET << lst.front() << std::endl;
	std::cout << GREEN << "MY       = " << RESET << my_lst.front() << std::endl;

	std::cout << YELLOW << "  =====BACK=====" << RESET << std::endl;
	std::cout << GREEN << "ORIGINAL = " << RESET << lst.back() << std::endl;
	std::cout << GREEN << "MY       = " << RESET << my_lst.back() << std::endl;

	std::cout << YELLOW << "  =====ASSIGN=====" << RESET << std::endl;
	lst.assign(5, 'G');
	my_lst.assign(5, 'G');
	itr = lst.begin();
	ite = lst.end();
	my_itr = my_lst.begin();
	my_ite = my_lst.end();
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
	lst.insert(++lst.begin(), 'a');
	my_lst.insert(++my_lst.begin(), 'a');
	itr = lst.begin();
	ite = lst.end();
	my_itr = my_lst.begin();
	my_ite = my_lst.end();
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
	lst.insert(--lst.end(), 4, 's');
	my_lst.insert(--my_lst.end(), 4, 's');
	itr = lst.begin();
	ite = lst.end();
	my_itr = my_lst.begin();
	my_ite = my_lst.end();
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
	lst.insert(lst.end(), ++lst.begin(), --lst.end());
	my_lst.insert(my_lst.end(), ++my_lst.begin(), --my_lst.end());
	itr = lst.begin();
	ite = lst.end();
	my_itr = my_lst.begin();
	my_ite = my_lst.end();
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
	lst.erase(lst.begin());
	my_lst.erase(my_lst.begin());
	itr = lst.begin();
	ite = lst.end();
	my_itr = my_lst.begin();
	my_ite = my_lst.end();
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
	lst.erase(++lst.begin(), --lst.end());
	my_lst.erase(++my_lst.begin(), --my_lst.end());
	itr = lst.begin();
	ite = lst.end();
	my_itr = my_lst.begin();
	my_ite = my_lst.end();
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
	itr = lst.begin();
	ite = lst.end();
	std::cout << GREEN << "ORIGINAL 1 = " << RESET;
	while (itr != ite)
	{
		std::cout << *itr << " ";
		itr++;
	}
	itr = lst_cpy.begin();
	ite = lst_cpy.end();
	std::cout << GREEN << " ORIGINAL 2 = " << RESET;
	while (itr != ite)
	{
		std::cout << *itr << " ";
		itr++;
	}
	std::cout << std::endl;

	my_itr = my_lst.begin();
	my_ite = my_lst.end();
	std::cout << GREEN << "MY 1       = " << RESET;
	while (my_itr != my_ite)
	{
		std::cout << *my_itr << " ";
		my_itr++;
	}
	my_itr = my_lst_cpy.begin();
	my_ite = my_lst_cpy.end();
	std::cout << GREEN << " MY 2       = " << RESET;
	while (my_itr != my_ite)
	{
		std::cout << *my_itr << " ";
		my_itr++;
	}
	std::cout << std::endl;
	lst.swap(lst_cpy);
	my_lst.swap(my_lst_cpy);
	itr = lst.begin();
	ite = lst.end();
	std::cout << GREEN << "ORIGINAL 1 = " << RESET;
	while (itr != ite)
	{
		std::cout << *itr << " ";
		itr++;
	}
	itr = lst_cpy.begin();
	ite = lst_cpy.end();
	std::cout << GREEN << " ORIGINAL 2 = " << RESET;
	while (itr != ite)
	{
		std::cout << *itr << " ";
		itr++;
	}
	std::cout << std::endl;

	my_itr = my_lst.begin();
	my_ite = my_lst.end();
	std::cout << GREEN << "MY 1       = " << RESET;
	while (my_itr != my_ite)
	{
		std::cout << *my_itr << " ";
		my_itr++;
	}
	my_itr = my_lst_cpy.begin();
	my_ite = my_lst_cpy.end();
	std::cout << GREEN << " MY 2       = " << RESET;
	while (my_itr != my_ite)
	{
		std::cout << *my_itr << " ";
		my_itr++;
	}
	std::cout << std::endl;

	std::cout << YELLOW << "  =====RESIZE=====" << RESET << std::endl;
	lst.resize(8, 'F');
	my_lst.resize(8, 'F');
	itr = lst.begin();
	ite = lst.end();
	my_itr = my_lst.begin();
	my_ite = my_lst.end();
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
	lst.resize(3);
	my_lst.resize(3);
	itr = lst.begin();
	ite = lst.end();
	my_itr = my_lst.begin();
	my_ite = my_lst.end();
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

	std::cout << YELLOW << "  =====CLEAR=====" << RESET << std::endl;
	lst.clear();
	my_lst.clear();
	lst_cpy.clear();
	my_lst_cpy.clear();
	itr = lst.begin();
	ite = lst.end();
	my_itr = my_lst.begin();
	my_ite = my_lst.end();
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

	std::cout << YELLOW << "  =====SPLICE=====" << RESET << std::endl;
	for (size_t i = 0; i < 10; i++)
	{
		lst.push_back('a');
		my_lst.push_back('a');
	}
	for (size_t i = 0; i < 10; i++)
	{
		lst_cpy.push_back('B');
		my_lst_cpy.push_back('B');
	}
	itr = lst.begin();
	ite = lst.end();
	std::cout << GREEN << "ORIGINAL 1 = " << RESET;
	while (itr != ite)
	{
		std::cout << *itr << " ";
		itr++;
	}
	itr = lst_cpy.begin();
	ite = lst_cpy.end();
	std::cout << GREEN << " ORIGINAL 2 = " << RESET;
	while (itr != ite)
	{
		std::cout << *itr << " ";
		itr++;
	}
	std::cout << std::endl;
	lst.splice(++lst.begin(), lst_cpy, lst_cpy.begin());
	itr = lst.begin();
	ite = lst.end();
	std::cout << GREEN << "ORIGINAL 1 SPLICE = " << RESET;
	while (itr != ite)
	{
		std::cout << *itr << " ";
		itr++;
	}
	itr = lst_cpy.begin();
	ite = lst_cpy.end();
	std::cout << GREEN << " ORIGINAL 2 SPLICE = " << RESET;
	while (itr != ite)
	{
		std::cout << *itr << " ";
		itr++;
	}
	std::cout << std::endl;
	lst.splice(lst.begin(), lst_cpy);
		itr = lst.begin();
	ite = lst.end();
	std::cout << GREEN << "ORIGINAL 1 SPLICE = " << RESET;
	while (itr != ite)
	{
		std::cout << *itr << " ";
		itr++;
	}
	itr = lst_cpy.begin();
	ite = lst_cpy.end();
	std::cout << GREEN << " ORIGINAL 2 SPLICE = " << RESET;
	while (itr != ite)
	{
		std::cout << *itr << " ";
		itr++;
	}
	std::cout << std::endl;

	my_itr = my_lst.begin();
	my_ite = my_lst.end();
	std::cout << GREEN << "MY 1       = " << RESET;
	while (my_itr != my_ite)
	{
		std::cout << *my_itr << " ";
		my_itr++;
	}
	my_itr = my_lst_cpy.begin();
	my_ite = my_lst_cpy.end();
	std::cout << GREEN << " MY 2       = " << RESET;
	while (my_itr != my_ite)
	{
		std::cout << *my_itr << " ";
		my_itr++;
	}
	std::cout << std::endl;
	my_lst.splice(++my_lst.begin(), my_lst_cpy, my_lst_cpy.begin());
	my_itr = my_lst.begin();
	my_ite = my_lst.end();
	std::cout << GREEN << "MY 1       SPLICE = " << RESET;
	while (my_itr != my_ite)
	{
		std::cout << *my_itr << " ";
		my_itr++;
	}
	my_itr = my_lst_cpy.begin();
	my_ite = my_lst_cpy.end();
	std::cout << GREEN << " MY 2       SPLICE = " << RESET;
	while (my_itr != my_ite)
	{
		std::cout << *my_itr << " ";
		my_itr++;
	}
	std::cout << std::endl;
	my_lst.splice(my_lst.begin(), my_lst_cpy);
	my_itr = my_lst.begin();
	my_ite = my_lst.end();
	std::cout << GREEN << "MY 1       SPLICE = " << RESET;
	while (my_itr != my_ite)
	{
		std::cout << *my_itr << " ";
		my_itr++;
	}
	my_itr = my_lst_cpy.begin();
	my_ite = my_lst_cpy.end();
	std::cout << GREEN << " MY 2       SPLICE = " << RESET;
	while (my_itr != my_ite)
	{
		std::cout << *my_itr << " ";
		my_itr++;
	}
	std::cout << std::endl;

	std::cout << YELLOW << "  =====REMOVE=====" << RESET << std::endl;
	lst.remove('B');
	my_lst.remove('B');
	itr = lst.begin();
	ite = lst.end();
	my_itr = my_lst.begin();
	my_ite = my_lst.end();
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

	std::cout << YELLOW << "  =====REMOVE IF=====" << RESET << std::endl;
	lst.clear();
	my_lst.clear();
	for (size_t i = 0; i < 15; i++)
	{
		lst.push_back(i + 65);
		my_lst.push_back(i + 65);
	}
	itr = lst.begin();
	ite = lst.end();
	my_itr = my_lst.begin();
	my_ite = my_lst.end();
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

	lst.remove_if(single_digit);
	my_lst.remove_if(single_digit);
	itr = lst.begin();
	ite = lst.end();
	my_itr = my_lst.begin();
	my_ite = my_lst.end();
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

	std::cout << YELLOW << "  =====UNIQUE=====" << RESET << std::endl;
	lst.clear();
	my_lst.clear();
	lst.push_back('a');
	lst.push_back('a');
	lst.push_back('a');
	lst.push_back('b');
	lst.push_back('b');
	my_lst.push_back('a');
	my_lst.push_back('a');
	my_lst.push_back('a');
	my_lst.push_back('b');
	my_lst.push_back('b');
	itr = lst.begin();
	ite = lst.end();
	my_itr = my_lst.begin();
	my_ite = my_lst.end();
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
	lst.unique();
	my_lst.unique();
	itr = lst.begin();
	ite = lst.end();
	my_itr = my_lst.begin();
	my_ite = my_lst.end();
	std::cout << GREEN << "ORIGINAL UNIQUE = " << RESET;
	while (itr != ite)
	{
		std::cout << *itr << " ";
		itr++;
	}
	std::cout << std::endl;
	std::cout << GREEN << "MY UNIQUE       = " << RESET;
	while (my_itr != my_ite)
	{
		std::cout << *my_itr << " ";
		my_itr++;
	}
	std::cout << std::endl;

	std::cout << YELLOW << "  =====SORT=====" << RESET << std::endl;
	lst.clear();
	my_lst.clear();
	lst.push_back('b');
	lst.push_back('G');
	lst.push_back('d');
	lst.push_back('q');
	lst.push_back('E');
	my_lst.push_back('b');
	my_lst.push_back('G');
	my_lst.push_back('d');
	my_lst.push_back('q');
	my_lst.push_back('E');
	itr = lst.begin();
	ite = lst.end();
	my_itr = my_lst.begin();
	my_ite = my_lst.end();
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
	lst.sort();
	my_lst.sort();
	itr = lst.begin();
	ite = lst.end();
	my_itr = my_lst.begin();
	my_ite = my_lst.end();
	std::cout << GREEN << "ORIGINAL UNIQUE = " << RESET;
	while (itr != ite)
	{
		std::cout << *itr << " ";
		itr++;
	}
	std::cout << std::endl;
	std::cout << GREEN << "MY UNIQUE       = " << RESET;
	while (my_itr != my_ite)
	{
		std::cout << *my_itr << " ";
		my_itr++;
	}
	std::cout << std::endl;

	std::cout << YELLOW << "  =====REVERSE=====" << RESET << std::endl;
	lst.reverse();
	my_lst.reverse();
	itr = lst.begin();
	ite = lst.end();
	my_itr = my_lst.begin();
	my_ite = my_lst.end();
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

	std::cout << YELLOW << "  =====MERGE=====" << RESET << std::endl;
	std::list<double> lst_mrg, lst_mrg1;
	lst_mrg.push_back(2.2);
	lst_mrg.push_back(2.9);
	lst_mrg.push_back(3.1);
	lst_mrg1.push_back(1.4);
	lst_mrg1.push_back(3.7);
	lst_mrg1.push_back(7.1);
	std::list<double>::iterator itr_mrg = lst_mrg.begin();
	std::list<double>::iterator ite_mrg = lst_mrg.end();
	std::cout << GREEN << "ORIGINAL 1 = " << RESET;
	while (itr_mrg != ite_mrg)
	{
		std::cout << *itr_mrg << " ";
		itr_mrg++;
	}
	std::cout << GREEN << "ORIGINAL 2 = " << RESET;
	itr_mrg = lst_mrg1.begin();
	ite_mrg = lst_mrg1.end();
	while (itr_mrg != ite_mrg)
	{
		std::cout << *itr_mrg << " ";
		itr_mrg++;
	}
	std::cout << std::endl;
	lst_mrg.merge(lst_mrg1);
	itr_mrg = lst_mrg.begin();
	ite_mrg = lst_mrg.end();
	std::cout << GREEN << "ORIGINAL MERGE = " << RESET;
	while (itr_mrg != ite_mrg)
	{
		std::cout << *itr_mrg << " ";
		itr_mrg++;
	}
	std::cout << std::endl;
	ft::list<double> my_lst_mrg, my_lst_mrg1;
	my_lst_mrg.push_back(2.2);
	my_lst_mrg.push_back(2.9);
	my_lst_mrg.push_back(3.1);
	my_lst_mrg1.push_back(1.4);
	my_lst_mrg1.push_back(3.7);
	my_lst_mrg1.push_back(7.1);
	ft::list<double>::iterator my_itr_mrg = my_lst_mrg.begin();
	ft::list<double>::iterator my_ite_mrg = my_lst_mrg.end();
	std::cout << GREEN << "MY 1       = " << RESET;
	while (my_itr_mrg != my_ite_mrg)
	{
		std::cout << *my_itr_mrg << " ";
		my_itr_mrg++;
	}
	std::cout << GREEN << "MY 2       = " << RESET;
	my_itr_mrg = my_lst_mrg.begin();
	my_ite_mrg = my_lst_mrg.end();
	while (my_itr_mrg != my_ite_mrg)
	{
		std::cout << *my_itr_mrg << " ";
		my_itr_mrg++;
	}
	std::cout << std::endl;
	my_lst_mrg.merge(my_lst_mrg1);
	std::cout << GREEN << "MY MERGE       = " << RESET;
	my_itr_mrg = my_lst_mrg.begin();
	my_ite_mrg = my_lst_mrg.end();
	while (my_itr_mrg != my_ite_mrg)
	{
		std::cout << *my_itr_mrg << " ";
		my_itr_mrg++;
	}
	std::cout << std::endl;
}
