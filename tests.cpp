#include "Vector.hpp"
#include "List.hpp"
//#include "Map.hpp"
#include "MapAvl.hpp"
#include "Stack.hpp"
#include "Queue.hpp"
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <stack>
#include <iostream>
#include <time.h>

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define VIOLET "\033[35m"

void	vector_test()
{
	std::cout << RED << "\t===VECTOR TEST===" << RESET << std::endl;
	std::vector<int> vec;
	ft::vector<int> my_vec;
	std::cout << YELLOW << "\tPUSH_BACK AND ITERATOR" << RESET << std::endl;
	for (size_t i = 0; i < 10; i++)
	{
		vec.push_back(i);
		my_vec.push_back(i);
	}
	std::vector<int>::iterator itr = vec.begin();
	std::vector<int>::iterator ite = vec.end();
	ft::vector<int>::iterator my_itr = my_vec.begin();
	ft::vector<int>::iterator my_ite = my_vec.end();
	std::cout << GREEN << "ORIGIN = " << RESET;
	while (itr != ite)
	{
		std::cout << *itr << " ";
		itr++;
	}
	std::cout << std::endl;
    std::cout << GREEN << "MY     = " << RESET;
	while (my_itr != my_ite)
	{
		std::cout << *my_itr << " ";
		my_itr++;
	}
	std::cout << std::endl;

	std::cout << YELLOW << "\tSIZE" << RESET << std::endl;
	std::cout << GREEN << "ORIGIN = " << RESET << vec.size() << std::endl << GREEN << "MY     = " << RESET << my_vec.size() << std::endl;

	std::cout << YELLOW << "\tMAX SIZE" << RESET << std::endl;
    std::cout << GREEN << "ORIGIN = " << RESET << vec.max_size() << std::endl << GREEN << "MY     = " << RESET << my_vec.max_size() << std::endl;

	std::cout << YELLOW << "\tCAPASITY" << RESET << std::endl;
    std::cout << GREEN << "ORIGIN = " << RESET << vec.capacity() << std::endl << GREEN << "MY     = " << RESET << my_vec.capacity() << std::endl;

	std::cout << YELLOW << "\tRESIZE" << RESET << std::endl;
	vec.resize(5);
	my_vec.resize(5);
    std::cout << GREEN << "ORIGIN = " << RESET;
	for (size_t i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;
    std::cout << GREEN << "MY     = " << RESET;
		for (size_t i = 0; i < my_vec.size(); i++)
	{
		std::cout << my_vec[i] << " ";
	}
	std::cout << std::endl;
	vec.resize(15, 100);
	my_vec.resize(15, 100);
    std::cout << GREEN << "ORIGIN = " << RESET;
	for (size_t i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;
    std::cout << GREEN << "MY     = " << RESET;
		for (size_t i = 0; i < my_vec.size(); i++)
	{
		std::cout << my_vec[i] << " ";
	}
	std::cout << std::endl;

	std::cout << YELLOW << "\tEMPTY" << RESET << std::endl;
    std::cout << GREEN << "ORIGIN = " << RESET << vec.empty() << std::endl << GREEN <<"MY     = " << RESET << my_vec.empty() << std::endl;

	std::cout << YELLOW << "\tRESERVE" << RESET << std::endl;
    std::cout << GREEN << "ORIGIN = " << RESET << vec.capacity() << std::endl << GREEN <<"MY     = " << RESET << my_vec.capacity() << std::endl;
	vec.reserve(100);
	my_vec.reserve(100);
    std::cout << GREEN << "ORIGIN = " << RESET << vec.capacity() << std::endl << GREEN <<"MY     = " << RESET << my_vec.capacity() << std::endl;

	std::cout << YELLOW << "\tFRONT" << RESET << std::endl;
    std::cout << GREEN << "ORIGIN = " << RESET << vec.front() << std::endl << GREEN <<"MY     = " << RESET << my_vec.front() << std::endl;

	std::cout << YELLOW << "\tBACK" << RESET << std::endl;
    std::cout << GREEN << "ORIGIN = " << RESET << vec.back() << std::endl << GREEN <<"MY     = " << RESET << my_vec.back() << std::endl;

	std::cout << YELLOW << "\tASSIGN" << RESET << std::endl;
	vec.assign(5, 30);
	my_vec.assign(5, 30);
    std::cout << GREEN << "ORIGIN = " << RESET;
	for (size_t i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;
    std::cout << GREEN << "MY     = " << RESET;
		for (size_t i = 0; i < my_vec.size(); i++)
	{
		std::cout << my_vec[i] << " ";
	}
	std::cout << std::endl;

	std::cout << YELLOW << "\tPOP BACK" << RESET << std::endl;
	vec.pop_back();
	my_vec.pop_back();
    std::cout << GREEN << "ORIGIN = " << RESET;
	for (size_t i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;
    std::cout << GREEN << "MY     = " << RESET;
		for (size_t i = 0; i < my_vec.size(); i++)
	{
		std::cout << my_vec[i] << " ";
	}
	std::cout << std::endl;

	std::cout << YELLOW << "\tINSERT" << RESET << std::endl;
	vec.insert(vec.begin() + 2, 2);
	my_vec.insert(my_vec.begin() + 2, 2);
    std::cout << GREEN << "ORIGIN = " << RESET;
	for (size_t i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;
    std::cout << GREEN << "MY     = " << RESET;
		for (size_t i = 0; i < my_vec.size(); i++)
	{
		std::cout << my_vec[i] << " ";
	}
	std::cout << std::endl;

	std::cout << YELLOW << "\tERASE" << RESET << std::endl;
	vec.erase(vec.begin());
	my_vec.erase(my_vec.begin());
    std::cout << GREEN << "ORIGIN = " << RESET;
	for (size_t i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;
    std::cout << GREEN << "MY     = " << RESET;
		for (size_t i = 0; i < my_vec.size(); i++)
	{
		std::cout << my_vec[i] << " ";
	}
	std::cout << std::endl;

	std::cout << YELLOW << "\tSWAP" << RESET << std::endl;
	std::vector<int> vec1;
	ft::vector<int> my_vec1;
	for (size_t i = 10; i < 20; i++)
	{
		vec1.push_back(i);
		my_vec1.push_back(i);
	}
	vec.swap(vec1);
	my_vec.swap(my_vec1);
    std::cout << GREEN << "ORIGIN 1 = " << RESET;
	for (size_t i = 0; i < vec1.size(); i++)
	{
		std::cout << vec1[i] << " ";
	}
	std::cout << std::endl;
    std::cout << GREEN << "MY 1     = " << RESET;
		for (size_t i = 0; i < my_vec1.size(); i++)
	{
		std::cout << my_vec1[i] << " ";
	}
	std::cout << std::endl;
    std::cout << GREEN << "ORIGIN = " << RESET;
	for (size_t i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;
    std::cout << GREEN << "MY     = " << RESET;
		for (size_t i = 0; i < my_vec.size(); i++)
	{
		std::cout << my_vec[i] << " ";
	}
	std::cout << std::endl;

	std::cout << YELLOW << "\tCLEAR" << RESET << std::endl;
	vec.clear();
	my_vec.clear();
    std::cout << GREEN << "ORIGIN = " << RESET;
	for (size_t i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;
    std::cout << GREEN << "MY     = " << RESET;
		for (size_t i = 0; i < my_vec.size(); i++)
	{
		std::cout << my_vec[i] << " ";
	}
	std::cout << std::endl;
}

void    list_test() {
    std::cout << RED << "\t===LIST TEST===" << RESET
              << std::endl;//////////////////////////////////////////////////////////
    ft::list<int> my_lst;
    std::list<int> lst;
    std::cout << YELLOW << "\tPUSH_BACK" << RESET
              << std::endl;//////////////////////////////////////////////////////////
    for (int i = 10; i < 21; ++i) {
        my_lst.push_back(i);
        lst.push_back(i);
    }
    ft::list<int>::iterator my_itr = my_lst.begin();
    ft::list<int>::iterator my_ite = my_lst.end();
    std::list<int>::iterator itr = lst.begin();
    std::list<int>::iterator ite = lst.end();
    std::cout << GREEN << "ORIGIN = " << RESET;
    while (itr != ite) {
        std::cout << *itr << " ";
        itr++;
    }
    std::cout << std::endl;
    std::cout << GREEN << "MY     = " << RESET;
    while (my_itr != my_ite) {
        std::cout << *my_itr << " ";
        my_itr++;
    }
    std::cout << std::endl;

    std::cout << YELLOW << "\tPOP BACK" << RESET << std::endl;//////////////////////////////////////////////////////////
    lst.pop_back();
    my_lst.pop_back();
    my_itr = my_lst.begin();
    my_ite = my_lst.end();
    itr = lst.begin();
    ite = lst.end();
    std::cout << GREEN << "ORIGIN = " << RESET;
    while (itr != ite) {
        std::cout << *itr << " ";
        itr++;
    }
    std::cout << std::endl;
    std::cout << GREEN << "MY     = " << RESET;
    while (my_itr != my_ite) {
        std::cout << *my_itr << " ";
        my_itr++;
    }
    std::cout << std::endl;


    std::cout << YELLOW << "\tPUSH_FRONT" << RESET
              << std::endl;//////////////////////////////////////////////////////////
    for (int i = 0; i < 10; ++i) {
        my_lst.push_front(i);
        lst.push_front(i);
    }
    my_itr = my_lst.begin();
    my_ite = my_lst.end();
    itr = lst.begin();
    ite = lst.end();
    std::cout << GREEN << "ORIGIN = " << RESET;
    while (itr != ite) {
        std::cout << *itr << " ";
        itr++;
    }
    std::cout << std::endl;
    std::cout << GREEN << "MY     = " << RESET;
    while (my_itr != my_ite) {
        std::cout << *my_itr << " ";
        my_itr++;
    }
    std::cout << std::endl;

    std::cout << YELLOW << "\tPOP FRONT" << RESET
              << std::endl;//////////////////////////////////////////////////////////
    lst.pop_front();
    my_lst.pop_front();
    my_itr = my_lst.begin();
    my_ite = my_lst.end();
    itr = lst.begin();
    ite = lst.end();
    std::cout << GREEN << "ORIGIN = " << RESET;
    while (itr != ite) {
        std::cout << *itr << " ";
        itr++;
    }
    std::cout << std::endl;
    std::cout << GREEN << "MY     = " << RESET;
    while (my_itr != my_ite) {
        std::cout << *my_itr << " ";
        my_itr++;
    }
    std::cout << std::endl;

    std::cout << YELLOW << "\tEMPTY" << RESET << std::endl;//////////////////////////////////////////////////////////
    std::cout << GREEN << "ORIGIN = " << RESET << lst.empty() << std::endl;
    std::cout << GREEN << "MY     = " << RESET << my_lst.empty() << std::endl;

    std::cout << YELLOW << "\tSIZE" << RESET << std::endl;//////////////////////////////////////////////////////////
    std::cout << GREEN << "ORIGIN = " << RESET << lst.size() << std::endl;
    std::cout << GREEN << "MY     = " << RESET << my_lst.size() << std::endl;

    std::cout << YELLOW << "\tMAX SIZE" << RESET << std::endl;//////////////////////////////////////////////////////////
    std::cout << GREEN << "ORIGIN = " << RESET << lst.max_size() << std::endl;
    std::cout << GREEN << "MY     = " << RESET << my_lst.max_size() << std::endl;

    std::cout << YELLOW << "\tFRONT" << RESET << std::endl;//////////////////////////////////////////////////////////
    std::cout << GREEN << "ORIGIN = " << RESET << lst.front() << std::endl;
    std::cout << GREEN << "MY     = " << RESET << my_lst.front() << std::endl;

    std::cout << YELLOW << "\tBACK" << RESET << std::endl;//////////////////////////////////////////////////////////
    std::cout << GREEN << "ORIGIN = " << RESET << lst.back() << std::endl;
    std::cout << GREEN << "MY     = " << RESET << my_lst.back() << std::endl;

    std::cout << YELLOW << "\tASSIGN" << RESET << std::endl;//////////////////////////////////////////////////////////
    lst.assign(7, 100);
    my_lst.assign(7, 100);
    my_itr = my_lst.begin();
    my_ite = my_lst.end();
    itr = lst.begin();
    ite = lst.end();
    std::cout << GREEN << "ORIGIN = " << RESET;
    while (itr != ite) {
        std::cout << *itr << " ";
        itr++;
    }
    std::cout << std::endl;
    std::cout << GREEN << "MY     = " << RESET;
    while (my_itr != my_ite) {
        std::cout << *my_itr << " ";
        my_itr++;
    }
    std::cout << std::endl;

    std::cout << YELLOW << "\tINSERT" << RESET << std::endl;//////////////////////////////////////////////////////////
    my_itr = my_lst.begin();
    itr = lst.begin();
    lst.insert(++itr, 999);
    my_lst.insert(++my_itr, 999);
    my_itr = my_lst.begin();
    my_ite = my_lst.end();
    itr = lst.begin();
    ite = lst.end();
    std::cout << GREEN << "ORIGIN = " << RESET;
    while (itr != ite) {
        std::cout << *itr << " ";
        itr++;
    }
    std::cout << std::endl;
    std::cout << GREEN << "MY     = " << RESET;
    while (my_itr != my_ite) {
        std::cout << *my_itr << " ";
        my_itr++;
    }
    std::cout << std::endl;
    my_itr = my_lst.begin();
    itr = lst.begin();
    lst.insert(++itr, 5, 777);
    my_lst.insert(++my_itr, 5, 777);
    my_itr = my_lst.begin();
    my_ite = my_lst.end();
    itr = lst.begin();
    ite = lst.end();
    std::cout << GREEN << "ORIGIN = " << RESET;
    while (itr != ite) {
        std::cout << *itr << " ";
        itr++;
    }
    std::cout << std::endl;
    std::cout << GREEN << "MY     = " << RESET;
    while (my_itr != my_ite) {
        std::cout << *my_itr << " ";
        my_itr++;
    }
    std::cout << std::endl;

    std::cout << YELLOW << "\tERASE" << RESET << std::endl;//////////////////////////////////////////////////////////
    my_itr = my_lst.begin();
    itr = lst.begin();
    lst.erase(++itr);
    my_lst.erase(++my_itr);
    my_itr = my_lst.begin();
    my_ite = my_lst.end();
    itr = lst.begin();
    ite = lst.end();
    std::cout << GREEN << "ORIGIN = " << RESET;
    while (itr != ite) {
        std::cout << *itr << " ";
        itr++;
    }
    std::cout << std::endl;
    std::cout << GREEN << "MY     = " << RESET;
    while (my_itr != my_ite) {
        std::cout << *my_itr << " ";
        my_itr++;
    }
    std::cout << std::endl;
    my_itr = my_lst.begin();
    my_ite = my_lst.end();
    itr = lst.begin();
    ite = lst.end();
    lst.erase(++itr, --ite);
    my_lst.erase(++my_itr, --my_ite);
    my_itr = my_lst.begin();
    my_ite = my_lst.end();
    itr = lst.begin();
    ite = lst.end();
    std::cout << GREEN << "ORIGIN = " << RESET;
    while (itr != ite) {
        std::cout << *itr << " ";
        itr++;
    }
    std::cout << std::endl;
    std::cout << GREEN << "MY     = " << RESET;
    while (my_itr != my_ite) {
        std::cout << *my_itr << " ";
        my_itr++;
    }
    std::cout << std::endl;

    std::cout << YELLOW << "\tSWAP" << RESET << std::endl;//////////////////////////////////////////////////////////
    std::list<int> lst2(5, 200);
    ft::list<int> my_lst2(5, 200);
    lst.assign(5, 100);
    my_lst.assign(5, 200);
    my_itr = my_lst.begin();
    my_ite = my_lst.end();
    itr = lst.begin();
    ite = lst.end();
    std::cout << GREEN << "ORIGIN DO = " << RESET;
    while (itr != ite) {
        std::cout << *itr << " ";
        itr++;
    }
    itr = lst2.begin();
    ite = lst2.end();
    std::cout << GREEN << "ORIGIN DO = " << RESET;
    while (itr != ite) {
        std::cout << *itr << " ";
        itr++;
    }
    std::cout << std::endl;
    std::cout << GREEN << "MY     DO = " << RESET;
    while (my_itr != my_ite) {
        std::cout << *my_itr << " ";
        my_itr++;
    }
    my_itr = my_lst2.begin();
    my_ite = my_lst2.end();
    std::cout << GREEN << "MY     DO = " << RESET;
    while (my_itr != my_ite) {
        std::cout << *my_itr << " ";
        my_itr++;
    }
    std::cout << std::endl;
    my_lst.swap(my_lst2);
    lst.swap(lst2);
    my_itr = my_lst.begin();
    my_ite = my_lst.end();
    itr = lst.begin();
    ite = lst.end();
    std::cout << GREEN << "ORIGIN SWAP = " << RESET;
    while (itr != ite) {
        std::cout << *itr << " ";
        itr++;
    }
    itr = lst2.begin();
    ite = lst2.end();
    std::cout << GREEN << "ORIGIN SWAP = " << RESET;
    while (itr != ite) {
        std::cout << *itr << " ";
        itr++;
    }
    std::cout << std::endl;
    std::cout << GREEN << "MY     SWAP = " << RESET;
    while (my_itr != my_ite) {
        std::cout << *my_itr << " ";
        my_itr++;
    }
    my_itr = my_lst2.begin();
    my_ite = my_lst2.end();
    std::cout << GREEN << "MY     SWAP = " << RESET;
    while (my_itr != my_ite) {
        std::cout << *my_itr << " ";
        my_itr++;
    }
    std::cout << std::endl;

    std::cout << YELLOW << "\tRESIZE" << RESET << std::endl;//////////////////////////////////////////////////////////
    lst.resize(3);
    my_lst.resize(3);
    my_itr = my_lst.begin();
    my_ite = my_lst.end();
    itr = lst.begin();
    ite = lst.end();
    std::cout << GREEN << "ORIGIN = " << RESET;
    while (itr != ite) {
        std::cout << *itr << " ";
        itr++;
    }
    std::cout << std::endl;
    std::cout << GREEN << "MY     = " << RESET;
    while (my_itr != my_ite) {
        std::cout << *my_itr << " ";
        my_itr++;
    }
    std::cout << std::endl;
    lst.resize(10, 777);
    my_lst.resize(10, 777);
    my_itr = my_lst.begin();
    my_ite = my_lst.end();
    itr = lst.begin();
    ite = lst.end();
    std::cout << GREEN << "ORIGIN = " << RESET;
    while (itr != ite) {
        std::cout << *itr << " ";
        itr++;
    }
    std::cout << std::endl;
    std::cout << GREEN << "MY     = " << RESET;
    while (my_itr != my_ite) {
        std::cout << *my_itr << " ";
        my_itr++;
    }
    std::cout << std::endl;

    std::cout << YELLOW << "\tCLEAR" << RESET << std::endl;//////////////////////////////////////////////////////////
    lst.clear();
    my_lst.clear();
    my_itr = my_lst.begin();
    my_ite = my_lst.end();
    itr = lst.begin();
    ite = lst.end();
    std::cout << GREEN << "ORIGIN = " << RESET;
    while (itr != ite) {
        std::cout << *itr << " ";
        itr++;
    }
    std::cout << std::endl;
    std::cout << GREEN << "MY     = " << RESET;
    while (my_itr != my_ite) {
        std::cout << *my_itr << " ";
        my_itr++;
    }
    std::cout << std::endl;

    std::cout << YELLOW << "\tSPLICE" << RESET << std::endl;//////////////////////////////////////////////////////////
    for (int i = 0; i < 10; ++i) {
        lst.push_back(i);
        my_lst.push_back(i);
    }
    my_itr = my_lst.begin();
    my_ite = my_lst.end();
    itr = lst.begin();
    ite = lst.end();
    std::cout << GREEN << "ORIGIN LST = " << RESET;
    while (itr != ite) {
        std::cout << *itr << " ";
        itr++;
    }
    itr = lst2.begin();
    ite = lst2.end();
    std::cout << GREEN << "ORIGIN LST2 = " << RESET;
    while (itr != ite) {
        std::cout << *itr << " ";
        itr++;
    }
    std::cout << std::endl;
    std::cout << GREEN << "MY     LST = " << RESET;
    while (my_itr != my_ite) {
        std::cout << *my_itr << " ";
        my_itr++;
    }
    my_itr = my_lst2.begin();
    my_ite = my_lst2.end();
    std::cout << GREEN << "MY     LST2 = " << RESET;
    while (my_itr != my_ite) {
        std::cout << *my_itr << " ";
        my_itr++;
    }
    std::cout << std::endl;

    lst.splice(lst.begin(), lst2, lst2.begin());
    my_lst.splice(my_lst.begin(), my_lst2, my_lst2.begin());

    my_itr = my_lst.begin();
    my_ite = my_lst.end();
    itr = lst.begin();
    ite = lst.end();
    std::cout << GREEN << "ORIGIN LST = " << RESET;
    while (itr != ite) {
        std::cout << *itr << " ";
        itr++;
    }
    itr = lst2.begin();
    ite = lst2.end();
    std::cout << GREEN << "ORIGIN LST2 = " << RESET;
    while (itr != ite) {
        std::cout << *itr << " ";
        itr++;
    }
    std::cout << std::endl;
    std::cout << GREEN << "MY     LST = " << RESET;
    while (my_itr != my_ite) {
        std::cout << *my_itr << " ";
        my_itr++;
    }
    my_itr = my_lst2.begin();
    my_ite = my_lst2.end();
    std::cout << GREEN << "MY     LST2 = " << RESET;
    while (my_itr != my_ite) {
        std::cout << *my_itr << " ";
        my_itr++;
    }
    std::cout << std::endl;
    lst.splice(lst.begin(), lst2);
    my_lst.splice(my_lst.begin(), my_lst2);
    my_itr = my_lst.begin();
    my_ite = my_lst.end();
    itr = lst.begin();
    ite = lst.end();
    std::cout << GREEN << "ORIGIN LST = " << RESET;
    while (itr != ite) {
        std::cout << *itr << " ";
        itr++;
    }
    itr = lst2.begin();
    ite = lst2.end();
    std::cout << GREEN << "ORIGIN LST2 = " << RESET;
    while (itr != ite) {
        std::cout << *itr << " ";
        itr++;
    }
    std::cout << std::endl;
    std::cout << GREEN << "MY     LST = " << RESET;
    while (my_itr != my_ite) {
        std::cout << *my_itr << " ";
        my_itr++;
    }
    my_itr = my_lst2.begin();
    my_ite = my_lst2.end();
    std::cout << GREEN << "MY     LST2 = " << RESET;
    while (my_itr != my_ite) {
        std::cout << *my_itr << " ";
        my_itr++;
    }
    std::cout << std::endl;

    std::cout << YELLOW << "\tREMOVE" << RESET << std::endl;//////////////////////////////////////////////////////////
    lst.remove(5);
    my_lst.remove(5);
    my_itr = my_lst.begin();
    my_ite = my_lst.end();
    itr = lst.begin();
    ite = lst.end();
    std::cout << GREEN << "ORIGIN = " << RESET;
    while (itr != ite) {
        std::cout << *itr << " ";
        itr++;
    }
    std::cout << std::endl;
    std::cout << GREEN << "MY     = " << RESET;
    while (my_itr != my_ite) {
        std::cout << *my_itr << " ";
        my_itr++;
    }
    std::cout << std::endl;

    std::cout << YELLOW << "\tUNIQUE" << RESET << std::endl;//////////////////////////////////////////////////////////
    lst.unique();
    my_lst.unique();
    my_itr = my_lst.begin();
    my_ite = my_lst.end();
    itr = lst.begin();
    ite = lst.end();
    std::cout << GREEN << "ORIGIN = " << RESET;
    while (itr != ite) {
        std::cout << *itr << " ";
        itr++;
    }
    std::cout << std::endl;
    std::cout << GREEN << "MY     = " << RESET;
    while (my_itr != my_ite) {
        std::cout << *my_itr << " ";
        my_itr++;
    }
    std::cout << std::endl;

    std::cout << YELLOW << "\tMERGE" << RESET << std::endl;//////////////////////////////////////////////////////////
    ft::list<float> my_lstf, my_lstf2;
    std::list<float> lstf, lstf2;
    my_lstf.push_back(2.2);
    my_lstf.push_back(3.4);
    my_lstf.push_back(9.6);
    my_lstf2.push_back(1.4);
    my_lstf2.push_back(5.5);
    my_lstf2.push_back(19.2);
    my_lstf.merge(my_lstf2);

    lstf.push_back(2.2);
    lstf.push_back(3.4);
    lstf.push_back(9.6);
    lstf2.push_back(1.4);
    lstf2.push_back(5.5);
    lstf2.push_back(19.2);
    lstf.merge(lstf2);

    ft::list<float>::iterator my_itrf = my_lstf.begin();
    ft::list<float>::iterator my_itef = my_lstf.end();
    std::list<float>::iterator itrf = lstf.begin();
    std::list<float>::iterator itef = lstf.end();
    std::cout << GREEN << "ORIGIN = " << RESET;
    while (itrf != itef) {
        std::cout << *itrf << " ";
        itrf++;
    }
    std::cout << std::endl;
    std::cout << GREEN << "MY     = " << RESET;
    while (my_itrf != my_itef) {
        std::cout << *my_itrf << " ";
        my_itrf++;
    }
    std::cout << std::endl;

    std::cout << YELLOW << "\tSORT" << RESET << std::endl;//////////////////////////////////////////////////////////
    lst.clear();
    my_lst.clear();
    for (int i = 0; i < 10; ++i) {
        lst.push_back(rand() % 100);
        my_lst.push_back(rand() % 100);
    }
    my_itr = my_lst.begin();
    my_ite = my_lst.end();
    itr = lst.begin();
    ite = lst.end();
    std::cout << GREEN << "ORIGIN = " << RESET;
    while (itr != ite) {
        std::cout << *itr << " ";
        itr++;
    }
    std::cout << std::endl;
    std::cout << GREEN << "MY     = " << RESET;
    while (my_itr != my_ite) {
        std::cout << *my_itr << " ";
        my_itr++;
    }
    std::cout << std::endl;
    lst.sort();
    my_lst.sort();
    my_itr = my_lst.begin();
    my_ite = my_lst.end();
    itr = lst.begin();
    ite = lst.end();
    std::cout << GREEN << "ORIGIN = " << RESET;
    while (itr != ite) {
        std::cout << *itr << " ";
        itr++;
    }
    std::cout << std::endl;
    std::cout << GREEN << "MY     = " << RESET;
    while (my_itr != my_ite) {
        std::cout << *my_itr << " ";
        my_itr++;
    }
    std::cout << std::endl;

    std::cout << YELLOW << "\tREVERCE" << RESET << std::endl;//////////////////////////////////////////////////////////
    lst.reverse();
    my_lst.reverse();
    my_itr = my_lst.begin();
    my_ite = my_lst.end();
    itr = lst.begin();
    ite = lst.end();
    std::cout << GREEN << "ORIGIN = " << RESET;
    while (itr != ite) {
        std::cout << *itr << " ";
        itr++;
    }
    std::cout << std::endl;
    std::cout << GREEN << "MY     = " << RESET;
    while (my_itr != my_ite) {
        std::cout << *my_itr << " ";
        my_itr++;
    }
    std::cout << std::endl;
}

void    map_test()
{
    std::cout << RED << "\t===MAP TEST===" << RESET << std::endl;
    std::map<int, int> map;
    ft::map<int, int> my_map;
    std::cout << YELLOW << "===INSERT===" << RESET << std::endl;//////////////////////////////////////////////////////////
//    my_map.insert(std::make_pair(10, 10));
//    for (int i = 0; i < 10; ++i) {
//        map.insert(std::pair<int, int>(i * 2, i * 4));
//        my_map.insert(std::make_pair(i * 2, i * 4));
//    }
//    std::map<int, int>::iterator itr = map.begin();
//    std::map<int, int>::iterator ite = map.end();
//    ft::map<int, int>::iterator my_itr = my_map.begin();
//    ft::map<int, int>::iterator my_ite = my_map.end();
//    std::cout << GREEN << "ORIGINAL > " << RESET;
//    while (itr != ite)
//    {
//        std::cout << itr->first << "=>" << itr->second << " ";
//        itr++;
//    }
//    std::cout << std::endl;
//    std::cout << GREEN << "MY       > " << RESET;
//    while (my_itr != my_ite)
//    {
//        std::cout << my_itr->first << "=>" << my_itr->second << " ";
//        my_itr++;
//    }
//    std::cout << std::endl;
//    map.insert(map.begin(), std::pair<int, int>(9, 9));
//    my_map.insert(my_map.begin(), std::pair<int, int>(9, 9));
//    itr = map.begin();
//    ite = map.end();
//    my_itr = my_map.begin();
//    my_ite = my_map.end();
//    std::cout << GREEN << "ORIGINAL > " << RESET;
//    while (itr != ite)
//    {
//        std::cout << itr->first << "=>" << itr->second << " ";
//        itr++;
//    }
//    std::cout << std::endl;
//    std::cout << GREEN << "MY       > " << RESET;
//    while (my_itr != my_ite)
//    {
//        std::cout << my_itr->first << "=>" << my_itr->second << " ";
//        my_itr++;
//    }
//    std::cout << std::endl;
//    std::map<int, int> map1;
//    ft::map<int, int> my_map1;
//    for (int i = 100; i < 130; ++i) {
//        map1.insert(std::pair<int, int>(i * 2, i * 4));
//        my_map1.insert(std::pair<int, int>(i * 2, i * 4));
//    }
//    map.insert(map1.begin(), map1.end());
//    my_map.insert(my_map1.begin(), my_map1.end());
//    itr = map.begin();
//    ite = map.end();
//    my_itr = my_map.begin();
//    my_ite = my_map.end();
//    std::cout << GREEN << "ORIGINAL > " << RESET;
//    while (itr != ite)
//    {
//        std::cout << itr->first << "=>" << itr->second << " ";
//        itr++;
//    }
//    std::cout << std::endl;
//    std::cout << GREEN << "MY       > " << RESET;
//    while (my_itr != my_ite)
//    {
//        std::cout << my_itr->first << "=>" << my_itr->second << " ";
//        my_itr++;
//    }
//    std::cout << std::endl;
//
//    std::cout << YELLOW << "===EMPTY===" << RESET << std::endl;//////////////////////////////////////////////////////////
//    std::cout << GREEN << "ORIGINAL > " << RESET << map.empty() << std::endl;
//    std::cout << GREEN << "MY       > " << RESET << my_map.empty() << std::endl;
//
//    std::cout << YELLOW << "===SIZE===" << RESET << std::endl;//////////////////////////////////////////////////////////
//    std::cout << GREEN << "ORIGINAL > " << RESET << map.size() << std::endl;
//    std::cout << GREEN << "MY       > " << RESET << my_map.size() << std::endl;
//
//    std::cout << YELLOW << "===MAX SIZE===" << RESET << std::endl;//////////////////////////////////////////////////////////
//    std::cout << GREEN << "ORIGINAL > " << RESET << map.max_size() << std::endl;
//    std::cout << GREEN << "MY       > " << RESET << my_map.max_size() << std::endl;
//
//    std::cout << YELLOW << "===[]===" << RESET << std::endl;//////////////////////////////////////////////////////////
//    std::cout << GREEN << "ORIGINAL > " << RESET << map[9] << std::endl;
//    std::cout << GREEN << "MY       > " << RESET << my_map[9] << std::endl;
//    std::cout << GREEN << "ORIGINAL > " << RESET << map[777] << std::endl;
//    std::cout << GREEN << "MY       > " << RESET << my_map[777] << std::endl;
//    itr = map.begin();
//    ite = map.end();
//    my_itr = my_map.begin();
//    my_ite = my_map.end();
//    std::cout << GREEN << "ORIGINAL > " << RESET;
//    while (itr != ite)
//    {
//        std::cout << itr->first << "=>" << itr->second << " ";
//        itr++;
//    }
//    std::cout << std::endl;
//    std::cout << GREEN << "MY       > " << RESET;
//    while (my_itr != my_ite)
//    {
//        std::cout << my_itr->first << "=>" << my_itr->second << " ";
//        my_itr++;
//    }
//    std::cout << std::endl;
//
//    std::cout << YELLOW << "===ERASE===" << RESET << std::endl;//////////////////////////////////////////////////////////
//    map.erase(++map.begin());
//    my_map.erase(++my_map.begin());
//    itr = map.begin();
//    ite = map.end();
//    my_itr = my_map.begin();
//    my_ite = my_map.end();
//    std::cout << GREEN << "ORIGINAL > " << RESET;
//    while (itr != ite)
//    {
//        std::cout << itr->first << "=>" << itr->second << " ";
//        itr++;
//    }
//    std::cout << std::endl;
//    std::cout << GREEN << "MY       > " << RESET;
//    while (my_itr != my_ite)
//    {
//        std::cout << my_itr->first << "=>" << my_itr->second << " ";
//        my_itr++;
//    }
//    std::cout << std::endl;
//    map.erase(777);
//    my_map.erase(777);
//    itr = map.begin();
//    ite = map.end();
//    my_itr = my_map.begin();
//    my_ite = my_map.end();
//    std::cout << GREEN << "ORIGINAL > " << RESET;
//    while (itr != ite)
//    {
//        std::cout << itr->first << "=>" << itr->second << " ";
//        itr++;
//    }
//    std::cout << std::endl;
//    std::cout << GREEN << "MY       > " << RESET;
//    while (my_itr != my_ite)
//    {
//        std::cout << my_itr->first << "=>" << my_itr->second << " ";
//        my_itr++;
//    }
//    std::cout << std::endl;
//    map.erase(++map.begin(), --map.end());
//    my_map.erase(++my_map.begin(), --my_map.end());
//    itr = map.begin();
//    ite = map.end();
//    my_itr = my_map.begin();
//    my_ite = my_map.end();
//    std::cout << GREEN << "ORIGINAL > " << RESET;
//    while (itr != ite)
//    {
//        std::cout << itr->first << "=>" << itr->second << " ";
//        itr++;
//    }
//    std::cout << std::endl;
//    std::cout << GREEN << "MY       > " << RESET;
//    while (my_itr != my_ite)
//    {
//        std::cout << my_itr->first << "=>" << my_itr->second << " ";
//        my_itr++;
//    }
//    std::cout << std::endl;
//
//    std::cout << YELLOW << "===CLEAR===" << RESET << std::endl;//////////////////////////////////////////////////////////
//    map.clear();
//    my_map.clear();
//    itr = map.begin();
//    ite = map.end();
//    my_itr = my_map.begin();
//    my_ite = my_map.end();
//    std::cout << GREEN << "ORIGINAL > " << RESET;
//    while (itr != ite)
//    {
//        std::cout << itr->first << "=>" << itr->second << " ";
//        itr++;
//    }
//    std::cout << std::endl;
//    std::cout << "SIZE = " << map.size() << std::endl;
//    std::cout << GREEN << "MY       > " << RESET;
//    while (my_itr != my_ite)
//    {
//        std::cout << my_itr->first << "=>" << my_itr->second << " ";
//        my_itr++;
//    }
//    std::cout << std::endl;
//    std::cout << "SIZE = " << my_map.size() << std::endl;
//
//    std::cout << YELLOW << "===SWAP===" << RESET << std::endl;//////////////////////////////////////////////////////////
//    std::map<char, int> map_string;
//    ft::map<char, int> my_map_string;
//    std::map<char, int> map_string1;
//    ft::map<char, int> my_map_string1;
//    for (int i = 0; i < 10; ++i) {
//        map_string.insert(std::pair<char, int>(i + 97, i));
//        my_map_string.insert(std::pair<char, int>(i + 97, i));
//    }
//    for (int i = 0; i < 10; ++i) {
//        map_string1.insert(std::pair<char, int>(i + 65, i));
//        my_map_string1.insert(std::pair<char, int>(i + 65, i));
//    }
//    std::map<char, int>::iterator itr_str = map_string.begin();
//    std::map<char, int>::iterator ite_str = map_string.end();
//    ft::map<char, int>::iterator my_itr_str = my_map_string.begin();
//    ft::map<char, int>::iterator my_ite_str = my_map_string.end();
//    std::cout << GREEN << "ORIGINAL 1 > " << RESET;
//    while (itr_str != ite_str)
//    {
//        std::cout << itr_str->first << "=>" << itr_str->second << " ";
//        itr_str++;
//    }
//    std::cout << std::endl;
//
//    std::map<char, int>::iterator itr_str1 = map_string1.begin();
//    std::map<char, int>::iterator ite_str1 = map_string1.end();
//    ft::map<char, int>::iterator my_itr_str1 = my_map_string1.begin();
//    ft::map<char, int>::iterator my_ite_str1 = my_map_string1.end();
//    std::cout << GREEN << "ORIGINAL 2 > " << RESET;
//    while (itr_str1 != ite_str1)
//    {
//        std::cout << itr_str1->first << "=>" << itr_str1->second << " ";
//        itr_str1++;
//    }
//    std::cout << std::endl;
//
//    std::cout << GREEN << "MY 1       > " << RESET;
//    while (my_itr_str != my_ite_str)
//    {
//        std::cout << my_itr_str->first << "=>" << my_itr_str->second << " ";
//        my_itr_str++;
//    }
//    std::cout << std::endl;
//    std::cout << GREEN << "MY 2       > " << RESET;
//    while (my_itr_str1 != my_ite_str1)
//    {
//        std::cout << my_itr_str1->first << "=>" << my_itr_str1->second << " ";
//        my_itr_str1++;
//    }
//    std::cout << std::endl;
//
//    map_string.swap(map_string1);
//    my_map_string.swap(my_map_string1);
//
//    itr_str = map_string.begin();
//    ite_str = map_string.end();
//    my_itr_str = my_map_string.begin();
//    my_ite_str = my_map_string.end();
//    std::cout << GREEN << "ORIGINAL SWAP 1 > " << RESET;
//    while (itr_str != ite_str)
//    {
//        std::cout << itr_str->first << "=>" << itr_str->second << " ";
//        itr_str++;
//    }
//    std::cout << std::endl;
//
//    itr_str1 = map_string1.begin();
//    ite_str1 = map_string1.end();
//    my_itr_str1 = my_map_string1.begin();
//    my_ite_str1 = my_map_string1.end();
//    std::cout << GREEN << "ORIGINAL SWAP 2 > " << RESET;
//    while (itr_str1 != ite_str1)
//    {
//        std::cout << itr_str1->first << "=>" << itr_str1->second << " ";
//        itr_str1++;
//    }
//    std::cout << std::endl;
//
//    std::cout << GREEN << "MY SWAP 1       > " << RESET;
//    while (my_itr_str != my_ite_str)
//    {
//        std::cout << my_itr_str->first << "=>" << my_itr_str->second << " ";
//        my_itr_str++;
//    }
//    std::cout << std::endl;
//    std::cout << GREEN << "MY SWAP 2       > " << RESET;
//    while (my_itr_str1 != my_ite_str1)
//    {
//        std::cout << my_itr_str1->first << "=>" << my_itr_str1->second << " ";
//        my_itr_str1++;
//    }
//    std::cout << std::endl;
//
//    std::cout << YELLOW << "===KEY COMP===" << RESET << std::endl;//////////////////////////////////////////////////////////
//    std::map<char,int> map3;
//
//    std::map<char,int>::key_compare mycomp = map3.key_comp();
//
//    map3['a']=100;
//    map3['b']=200;
//    map3['c']=300;
//
//    std::cout << GREEN << "ORIGINAL mymap contains:\n" << RESET;
//
//    char highest = map3.rbegin()->first;     // key value of last element
//
//    std::map<char,int>::iterator it = map3.begin();
//    do {
//        std::cout << it->first << " => " << it->second << '\n';
//    } while ( mycomp((*it++).first, highest) );
//
//    ft::map<char,int> mymap;
//
////    ft::map<char,int>::key_compare mycomp1 = mymap.key_comp();
//
//    mymap['a']=100;
//    mymap['b']=200;
//    mymap['c']=300;
//
//    std::cout << GREEN << "MY mymap contains:\n" << RESET;
//
//    char highest1 = mymap.rbegin()->first;     // key value of last element
//
//    ft::map<char,int>::iterator it1 = mymap.begin();
//    do {
//        std::cout << it1->first << " => " << it1->second << '\n';
//    } while ( mycomp((*it1++).first, highest1) );
//
//    std::cout << YELLOW << "===VALUE COMP===" << RESET << std::endl;//////////////////////////////////////////////////////////
//    std::map<char,int> map4;
//
//    map4['x']=1001;
//    map4['y']=2002;
//    map4['z']=3003;
//
//    std::cout << GREEN << "ORIGINAL mymap contains:\n" << RESET;
//
//    std::pair<char,int> highest4 = *map4.rbegin();          // last element
//
//    std::map<char,int>::iterator it4 = map4.begin();
//    do {
//        std::cout << it4->first << " => " << it4->second << '\n';
//    } while ( map4.value_comp()(*it4++, highest4) );
//
//    ft::map<char,int> map5;
//
//    map5['x']=1001;
//    map5['y']=2002;
//    map5['z']=3003;
//
//    std::cout << GREEN << "MY mymap contains:\n" << RESET;
//
//    std::pair<char,int> highest5 = *map5.rbegin();          // last element
//
//    ft::map<char,int>::iterator it5 = map5.begin();
//    do {
//        std::cout << it5->first << " => " << it5->second << '\n';
//    } while ( map5.value_comp()(*it5++, highest5) );
//
//    std::cout << YELLOW << "===FIND===" << RESET << std::endl;//////////////////////////////////////////////////////////
//    std::map<char,int> map6;
//    std::map<char,int>::iterator it6;
//
//    map6['a']=50;
//    map6['b']=100;
//    map6['c']=150;
//    map6['d']=200;
//
//    it6 = map6.find('b');
//    if (it6 != map6.end())
//        map6.erase (it6);
//
//    // print content:
//    std::cout << GREEN << "ORIGINAL elements in mymap:" << '\n' << RESET;
//    std::cout << "a => " << map6.find('a')->second << '\n';
//    std::cout << "c => " << map6.find('c')->second << '\n';
//    std::cout << "d => " << map6.find('d')->second << '\n';
//
//    ft::map<char,int> map7;
//    ft::map<char,int>::iterator it7;
//
//    map7['a']=50;
//    map7['b']=100;
//    map7['c']=150;
//    map7['d']=200;
//
//    it7 = map7.find('b');
//    if (it7 != map7.end())
//        map7.erase (it7);
//
//    // print content:
//    std::cout << GREEN << "MY elements in mymap:" << '\n' << RESET;
//    std::cout << "a => " << map7.find('a')->second << '\n';
//    std::cout << "c => " << map7.find('c')->second << '\n';
//    std::cout << "d => " << map7.find('d')->second << '\n';
//
//    std::cout << YELLOW << "===COUNT===" << RESET << std::endl;//////////////////////////////////////////////////////////
//    std::map<char,int> mymap8;
//    char c;
//
//    mymap8 ['a']=101;
//    mymap8 ['c']=202;
//    mymap8 ['f']=303;
//    std::cout << GREEN << "ORIGINAL" << std::endl << RESET;
//    for (c='a'; c<'h'; c++)
//    {
//        std::cout << c;
//        if (mymap8.count(c)>0)
//            std::cout << " is an element of mymap.\n";
//        else
//            std::cout << " is not an element of mymap.\n";
//    }
//
//    ft::map<char,int> mymap9;
//    char c1;
//
//    mymap9 ['a']=101;
//    mymap9 ['c']=202;
//    mymap9 ['f']=303;
//    std::cout << GREEN << "MY" << RESET << std::endl;
//    for (c1='a'; c1<'h'; c1++)
//    {
//        std::cout << c1;
//        if (mymap9.count(c1)>0)
//            std::cout << " is an element of mymap.\n";
//        else
//            std::cout << " is not an element of mymap.\n";
//    }
//
//    std::cout << YELLOW << "===LOWER BOUND===" << RESET << std::endl;//////////////////////////////////////////////////////////
//    std::map<char,int> mymap10;
//    std::map<char,int>::iterator itlow,itup;
//
//    mymap10['a']=20;
//    mymap10['b']=40;
//    mymap10['c']=60;
//    mymap10['d']=80;
//    mymap10['e']=100;
//
//    itlow=mymap10.lower_bound ('b');  // itlow points to b
//    itup=mymap10.upper_bound ('d');   // itup points to e (not d!)
//
//    mymap10.erase(itlow,itup);        // erases [itlow,itup)
//    std::cout << GREEN << "ORIGINAL" << RESET << std::endl;
//    // print content:
//    for (std::map<char,int>::iterator it10=mymap10.begin(); it10!=mymap10.end(); ++it10)
//        std::cout << it10->first << " => " << it10->second << '\n';
//    std::cout << GREEN << "MY" << RESET << std::endl;
//    ft::map<char,int> mymap11;
//    ft::map<char,int>::iterator itlow1,itup1;
//
//    mymap11['a']=20;
//    mymap11['b']=40;
//    mymap11['c']=60;
//    mymap11['d']=80;
//    mymap11['e']=100;
//
//    itlow1=mymap11.lower_bound ('b');  // itlow points to b
//    itup1=mymap11.upper_bound ('d');   // itup points to e (not d!)
//
//    mymap11.erase(itlow1,itup1);        // erases [itlow,itup)
//
//    // print content:
//    for (ft::map<char,int>::iterator it11=mymap11.begin(); it11!=mymap11.end(); ++it11)
//        std::cout << it11->first << " => " << it11->second << '\n';
//
//
//    std::cout << YELLOW << "===UPPER BOUND===" << RESET << std::endl;//////////////////////////////////////////////////////////
//    std::map<char,int> mymap12;
//    std::map<char,int>::iterator itlow2,itup2;
//
//    mymap12['a']=20;
//    mymap12['b']=40;
//    mymap12['c']=60;
//    mymap12['d']=80;
//    mymap12['e']=100;
//
//    itlow2=mymap12.lower_bound ('b');  // itlow points to b
//    itup2=mymap12.upper_bound ('d');   // itup points to e (not d!)
//
//    mymap12.erase(itlow2,itup2);        // erases [itlow,itup)
//    std::cout << GREEN << "ORIGINAL" << RESET << std::endl;
//    // print content:
//    for (std::map<char,int>::iterator it12=mymap12.begin(); it12!=mymap12.end(); ++it12)
//        std::cout << it12->first << " => " << it12->second << '\n';
//
//    ft::map<char,int> mymap13;
//    ft::map<char,int>::iterator itlow3,itup3;
//
//    mymap13['a']=20;
//    mymap13['b']=40;
//    mymap13['c']=60;
//    mymap13['d']=80;
//    mymap13['e']=100;
//    std::cout << GREEN << "MY" << RESET << std::endl;
//    itlow3=mymap13.lower_bound ('b');  // itlow points to b
//    itup3=mymap13.upper_bound ('d');   // itup points to e (not d!)
//
//    mymap13.erase(itlow3,itup3);        // erases [itlow,itup)
//
//    // print content:
//    for (ft::map<char,int>::iterator it13=mymap13.begin(); it13!=mymap13.end(); ++it13)
//        std::cout << it13->first << " => " << it13->second << '\n';
//
//    std::cout << YELLOW << "===EQUAL RANGE===" << RESET << std::endl;//////////////////////////////////////////////////////////
//    std::cout << GREEN << "ORIGINAL" << RESET << std::endl;
//    std::map<char,int> mymap14;
//
//    mymap14['a']=10;
//    mymap14['b']=20;
//    mymap14['c']=30;
//
//    std::pair<std::map<char,int>::iterator,std::map<char,int>::iterator> ret;
//    ret = mymap14.equal_range('b');
//
//    std::cout << "lower bound points to: ";
//    std::cout << ret.first->first << " => " << ret.first->second << '\n';
//
//    std::cout << "upper bound points to: ";
//    std::cout << ret.second->first << " => " << ret.second->second << '\n';
//    std::cout << GREEN << "MY" << RESET << std::endl;
//    ft::map<char,int> mymap15;
//
//    mymap15['a']=10;
//    mymap15['b']=20;
//    mymap15['c']=30;
//
//    std::pair<ft::map<char,int>::iterator,ft::map<char,int>::iterator> ret1;
//    ret1 = mymap15.equal_range('b');
//
//    std::cout << "lower bound points to: ";
//    std::cout << ret1.first->first << " => " << ret1.first->second << '\n';
//
//    std::cout << "upper bound points to: ";
//    std::cout << ret1.second->first << " => " << ret1.second->second << '\n';

//    std::map<int, int> test;
//    ft::map<int, int> my_test;
//    for (int i = 0; i < 10000; ++i) {
//        test.insert(std::pair<int, int>(i, i));
//        my_test.insert(std::pair<int, int>(i, i));
//    }
//
//    clock_t start1 = clock();
//    std::cout << test[9999] << std::endl;
//    clock_t end1 = clock();
//    double seconds1 = (double)(end1 - start1) / CLOCKS_PER_SEC;
//    printf("ORIGINAL The time: %f seconds\n", seconds1);
//
//    clock_t start = clock();
//    std::cout << my_test[9999] << std::endl;
//    clock_t end = clock();
//    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
//    printf("MY The time: %f seconds\n", seconds);
//

}

void    stack_test()
{
    std::cout << RED << "\t===STACK TEST===" << RESET << std::endl;
    std::cout << YELLOW << "===PUSH TOP POP===" << RESET << std::endl;//////////////////////////////////////////////////////////
    std::stack<int> st;
    ft::stack<int> my_st;
    for (int i = 0; i < 10; ++i) {
        st.push(i);
        my_st.push(i);
    }
    std::cout << GREEN << "ORIGINAL = " << RESET;
    for (int i = 0; i < 10; ++i) {
        std::cout << st.top() << " ";
        st.pop();
    }
    std::cout << std::endl;

    std::cout << GREEN << "MY       = " << RESET;
    for (int i = 0; i < 10; ++i) {
        std::cout << my_st.top() << " ";
        my_st.pop();
    }
    std::cout << std::endl;

    std::cout << YELLOW << "===EMPTY===" << RESET << std::endl;//////////////////////////////////////////////////////////
    std::cout << GREEN << "ORIGINAL = " << RESET << st.empty() << std::endl;
    std::cout << GREEN << "MY       = " << RESET << my_st.empty() << std::endl;

    std::cout << YELLOW << "===SIZE===" << RESET << std::endl;//////////////////////////////////////////////////////////
    std::cout << GREEN << "ORIGINAL = " << RESET << st.size() << std::endl;
    std::cout << GREEN << "MY       = " << RESET << my_st.size() << std::endl;
    for (int i = 0; i < 100; ++i) {
        st.push(i);
        my_st.push(i);
    }
    std::cout << GREEN << "ORIGINAL 100 = " << RESET << st.size() << std::endl;
    std::cout << GREEN << "MY       100 = " << RESET << my_st.size() << std::endl;
}

void    queue_test()
{
    std::cout << RED << "\t===QUEUE TEST===" << RESET << std::endl;
    std::cout << YELLOW << "===PUSH FRONT BACK POP===" << RESET << std::endl;//////////////////////////////////////////////////////////
    std::queue<int> qu;
    ft::queue<int> my_qu;
    for (int i = 0; i < 10; ++i) {
        qu.push(i);
        my_qu.push(i);
    }
    std::cout << GREEN << "ORIGINAL = " << RESET;
    for (int i = 0; i < 10; ++i) {
        std::cout << qu.front() << " ";
        qu.pop();
    }
    std::cout << std::endl;

    std::cout << GREEN << "MY       = " << RESET;
    for (int i = 0; i < 10; ++i) {
        std::cout << my_qu.front() << " ";
        my_qu.pop();
    }
    std::cout << std::endl;
    qu.push(5);
    my_qu.push(5);
    std::cout << GREEN << "ORIGINAL = " << RESET << qu.back() << std::endl;
    std::cout << GREEN << "MY       = " << RESET << my_qu.back() << std::endl;

    std::cout << YELLOW << "===EMPTY===" << RESET << std::endl;//////////////////////////////////////////////////////////
    std::cout << GREEN << "ORIGINAL = " << RESET << qu.empty() << std::endl;
    std::cout << GREEN << "MY       = " << RESET << my_qu.empty() << std::endl;

    std::cout << YELLOW << "===SIZE===" << RESET << std::endl;//////////////////////////////////////////////////////////
    std::cout << GREEN << "ORIGINAL = " << RESET << qu.size() << std::endl;
    std::cout << GREEN << "MY       = " << RESET << my_qu.size() << std::endl;
    for (int i = 0; i < 100; ++i) {
        qu.push(i);
        my_qu.push(i);
    }
    std::cout << GREEN << "ORIGINAL 100 = " << RESET << qu.size() << std::endl;
    std::cout << GREEN << "MY       100 = " << RESET << my_qu.size() << std::endl;
}