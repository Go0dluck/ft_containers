#include "../Set.hpp"
#include <set>
#include <iostream>

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define VIOLET "\033[35m"

int main()
{
	std::cout << RED << "\t=====SET TEST=====" << RESET << std::endl;
	std::cout << YELLOW << "  =====INSERT=====" << RESET << std::endl;
	std::set<char> set;
	ft::set<char> my_set;
	for (size_t i = 0; i < 10; i++)
	{
		set.insert(i + 65);
		my_set.insert(i + 65);
	}
	std::set<char>::iterator itr = set.begin();
	std::set<char>::iterator ite = set.end();
	ft::set<char>::iterator my_itr = my_set.begin();
	ft::set<char>::iterator my_ite = my_set.end();
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
	std::cout << GREEN << "ORIGINAL = " << RESET << set.empty() << std::endl;
	std::cout << GREEN << "MY       = " << RESET << my_set.empty() << std::endl;

	std::cout << YELLOW << "  =====SIZE=====" << RESET << std::endl;
	std::cout << GREEN << "ORIGINAL = " << RESET << set.size() << std::endl;
	std::cout << GREEN << "MY       = " << RESET << my_set.size() << std::endl;

	std::cout << YELLOW << "  =====MAX SIZE=====" << RESET << std::endl;
	std::cout << GREEN << "ORIGINAL = " << RESET << set.max_size() << std::endl;
	std::cout << GREEN << "MY       = " << RESET << my_set.max_size() << std::endl;

	std::cout << YELLOW << "  =====ERASE=====" << RESET << std::endl;
	set.erase(set.begin());
	my_set.erase(my_set.begin());
	itr = set.begin();
	ite = set.end();
	my_itr = my_set.begin();
	my_ite = my_set.end();
	std::cout << GREEN << "ORIGINAL ITERATOR = " << RESET;
	while (itr != ite)
	{
		std::cout << *itr << " ";
		itr++;
	}
	std::cout << std::endl;
	std::cout << GREEN << "MY ITERATOR       = " << RESET;
	while (my_itr != my_ite)
	{
		std::cout << *my_itr << " ";
		my_itr++;
	}
	std::cout << std::endl;
	set.erase('E');
	my_set.erase('E');
	itr = set.begin();
	ite = set.end();
	my_itr = my_set.begin();
	my_ite = my_set.end();
	std::cout << GREEN << "ORIGINAL 'E' KEY = " << RESET;
	while (itr != ite)
	{
		std::cout << *itr << " ";
		itr++;
	}
	std::cout << std::endl;
	std::cout << GREEN << "MY 'E' KEY       = " << RESET;
	while (my_itr != my_ite)
	{
		std::cout << *my_itr << " ";
		my_itr++;
	}
	std::cout << std::endl;

	std::cout << YELLOW << "  =====SWAP=====" << RESET << std::endl;
	std::set<char> set_sw;
	ft::set<char> my_set_sw;
	for (size_t i = 10; i < 20; i++)
	{
		set_sw.insert(i + 65);
		my_set_sw.insert(i + 65);
	}
	itr = set.begin();
	ite = set.end();
	std::cout << GREEN << "ORIGINAL 1 = " << RESET;
	while (itr != ite)
	{
		std::cout << *itr << " ";
		itr++;
	}
	itr = set_sw.begin();
	ite = set_sw.end();
	std::cout << GREEN << " ORIGINAL 2 = " << RESET;
	while (itr != ite)
	{
		std::cout << *itr << " ";
		itr++;
	}
	std::cout << std::endl;
	my_itr = my_set.begin();
	my_ite = my_set.end();
	std::cout << GREEN << "MY 1       = " << RESET;
	while (my_itr != my_ite)
	{
		std::cout << *my_itr << " ";
		my_itr++;
	}
	my_itr = my_set_sw.begin();
	my_ite = my_set_sw.end();
	std::cout << GREEN << " MY 2       = " << RESET;
	while (my_itr != my_ite)
	{
		std::cout << *my_itr << " ";
		my_itr++;
	}
	std::cout << std::endl;
	set.swap(set_sw);
	my_set.swap(my_set_sw);

	itr = set.begin();
	ite = set.end();
	std::cout << GREEN << "ORIGINAL 1 SWAP = " << RESET;
	while (itr != ite)
	{
		std::cout << *itr << " ";
		itr++;
	}
	itr = set_sw.begin();
	ite = set_sw.end();
	std::cout << GREEN << " ORIGINAL 2 SWAP = " << RESET;
	while (itr != ite)
	{
		std::cout << *itr << " ";
		itr++;
	}
	std::cout << std::endl;
	my_itr = my_set.begin();
	my_ite = my_set.end();
	std::cout << GREEN << "MY 1 SWAP       = " << RESET;
	while (my_itr != my_ite)
	{
		std::cout << *my_itr << " ";
		my_itr++;
	}
	my_itr = my_set_sw.begin();
	my_ite = my_set_sw.end();
	std::cout << GREEN << " MY 2 SWAP       = " << RESET;
	while (my_itr != my_ite)
	{
		std::cout << *my_itr << " ";
		my_itr++;
	}
	std::cout << std::endl;

	std::cout << YELLOW << "  =====KEY_COMP=====" << RESET << std::endl;
	std::set<int> myset;
	ft::set<int> my_myset;
	int highest;
	std::set<int>::key_compare mycomp = myset.key_comp();
	ft::set<int>::key_compare my_mycomp = my_myset.key_comp();
	for (int i=0; i<=5; i++)
	{
		myset.insert(i);
		my_myset.insert(i);
	}
	std::cout << GREEN << "ORIGINAL = " << RESET;
	highest=*myset.rbegin();
	std::set<int>::iterator it=myset.begin();
	do {
		std::cout << ' ' << *it;
	} while ( mycomp(*(++it),highest) );

	std::cout << '\n';
	std::cout << GREEN << "MY       = " << RESET;
	highest=*my_myset.rbegin();
	ft::set<int>::iterator my_it=my_myset.begin();
	do {
		std::cout << ' ' << *my_it;
	} while ( my_mycomp(*(++my_it),highest) );
	std::cout << '\n';

	std::cout << YELLOW << "  =====VALUE COMP=====" << RESET << std::endl;
	myset.clear();
	my_myset.clear();
	std::set<int>::value_compare myvcomp = myset.value_comp();
	ft::set<int>::value_compare my_myvcomp = my_myset.value_comp();
	for (int i=0; i<=5; i++)
	{
		myset.insert(i);
		my_myset.insert(i);
	}
	std::cout << GREEN << "ORIGINAL = " << RESET;
	highest=*myset.rbegin();
	it=myset.begin();
	do {
		std::cout << ' ' << *it;
	} while ( myvcomp(*(++it),highest) );

	std::cout << '\n';
	std::cout << GREEN << "MY       = " << RESET;
	highest=*my_myset.rbegin();
	my_it=my_myset.begin();
	do {
		std::cout << ' ' << *my_it;
	} while ( my_myvcomp(*(++my_it),highest) );
	std::cout << '\n';

	std::cout << YELLOW << "  =====FIND=====" << RESET << std::endl;
	myset.clear();
	my_myset.clear();
	for (int i=1; i<=5; i++)
	{
		myset.insert(i*10);
		my_myset.insert(i*10);
	}
	it=myset.find(20);
	my_it=my_myset.find(20);
	myset.erase (it);
	myset.erase (myset.find(40));
	my_myset.erase (my_it);
	my_myset.erase (my_myset.find(40));
	std::cout << GREEN << "ORIGINAL = " << RESET;
	for (it=myset.begin(); it!=myset.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	std::cout << GREEN << "MY       = " << RESET;
	for (my_it=my_myset.begin(); my_it!=my_myset.end(); ++my_it)
		std::cout << ' ' << *my_it;
	std::cout << '\n';

	std::cout << YELLOW << "  =====COUNT=====" << RESET << std::endl;
	myset.clear();
	my_myset.clear();
	for (int i=1; i<5; ++i)
	{
		myset.insert(i*3);
		my_myset.insert(i*3);
	}
	std::cout << GREEN << "ORIGINAL = \n" << RESET;
	for (int i=0; i<10; ++i)
	{
		std::cout << i;
		if (myset.count(i)!=0)
			std::cout << " is an element of myset.\n";
		else
			std::cout << " is not an element of myset.\n";
	}
	std::cout << GREEN << "MY       = \n" << RESET;
	for (int i=0; i<10; ++i)
	{
		std::cout << i;
		if (my_myset.count(i)!=0)
			std::cout << " is an element of myset.\n";
		else
			std::cout << " is not an element of myset.\n";
	}

	std::cout << YELLOW << "  =====LOWER/UPPER BOUND=====" << RESET << std::endl;
	myset.clear();
	my_myset.clear();
	std::set<int>::iterator itlow,itup;
	ft::set<int>::iterator my_itlow,my_itup;
	for (int i=1; i<10; i++)
	{
		myset.insert(i*10);
		my_myset.insert(i*10);
	}
	itlow=myset.lower_bound (30);
	itup=myset.upper_bound (60);
	my_itlow=my_myset.lower_bound (30);
	my_itup=my_myset.upper_bound (60);
	myset.erase(itlow,itup);
	my_myset.erase(my_itlow,my_itup);
	std::cout << GREEN << "ORIGINAL = " << RESET;
	for (std::set<int>::iterator it=myset.begin(); it!=myset.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	std::cout << GREEN << "MY       = " << RESET;
	for (ft::set<int>::iterator my_it=my_myset.begin(); my_it!=my_myset.end(); ++my_it)
		std::cout << ' ' << *my_it;
	std::cout << '\n';

	std::cout << YELLOW << "  =====EQUAL RANGE=====" << RESET << std::endl;
	myset.clear();
	my_myset.clear();
	for (int i=1; i<=5; i++)
	{
		myset.insert(i*10);
		my_myset.insert(i*10);
	}
	std::pair<std::set<int>::iterator,std::set<int>::iterator> ret;
	std::pair<ft::set<int>::iterator,ft::set<int>::iterator> my_ret;
	ret = myset.equal_range(30);
	my_ret = my_myset.equal_range(30);
	std::cout << GREEN << "ORIGINAL = \n" << RESET;
	std::cout << "the lower bound points to: " << *ret.first << '\n';
	std::cout << "the upper bound points to: " << *ret.second << '\n';
	std::cout << GREEN << "MY       = \n" << RESET;
	std::cout << "the lower bound points to: " << *my_ret.first << '\n';
	std::cout << "the upper bound points to: " << *my_ret.second << '\n';
}
