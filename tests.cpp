#include "Vector.hpp"
#include "List.hpp"
#include <list>
#include <vector>
#include <iostream>
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
	std::cout << "ORIGIN = ";
	while (itr != ite)
	{
		std::cout << *itr << " ";
		itr++;
	}
	std::cout << std::endl;
	std::cout << "MY     = ";
	while (my_itr != my_ite)
	{
		std::cout << *my_itr << " ";
		my_itr++;
	}
	std::cout << std::endl;

	std::cout << YELLOW << "\tSIZE" << RESET << std::endl;
	std::cout << "ORIGIN = " << vec.size() << std::endl << "MY     = " << my_vec.size() << std::endl;

	std::cout << YELLOW << "\tMAX SIZE" << RESET << std::endl;
	std::cout << "ORIGIN = " << vec.max_size() << std::endl << "MY     = " << my_vec.max_size() << std::endl;

	std::cout << YELLOW << "\tCAPASITY" << RESET << std::endl;
	std::cout << "ORIGIN = " << vec.capacity() << std::endl << "MY     = " << my_vec.capacity() << std::endl;

	std::cout << YELLOW << "\tRESIZE" << RESET << std::endl;
	vec.resize(5);
	my_vec.resize(5);
	std::cout << "ORIGIN = ";
	for (size_t i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "MY     = ";
		for (size_t i = 0; i < my_vec.size(); i++)
	{
		std::cout << my_vec[i] << " ";
	}
	std::cout << std::endl;
	vec.resize(15, 100);
	my_vec.resize(15, 100);
	std::cout << "ORIGIN = ";
	for (size_t i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "MY     = ";
		for (size_t i = 0; i < my_vec.size(); i++)
	{
		std::cout << my_vec[i] << " ";
	}
	std::cout << std::endl;

	std::cout << YELLOW << "\tEMPTY" << RESET << std::endl;
	std::cout << "ORIGIN = " << vec.empty() << std::endl << "MY     = " << my_vec.empty() << std::endl;

	std::cout << YELLOW << "\tRESERVE" << RESET << std::endl;
	std::cout << "ORIGIN = " << vec.capacity() << std::endl << "MY     = " << my_vec.capacity() << std::endl;
	vec.reserve(100);
	my_vec.reserve(100);
	std::cout << "ORIGIN = " << vec.capacity() << std::endl << "MY     = " << my_vec.capacity() << std::endl;

	std::cout << YELLOW << "\tFRONT" << RESET << std::endl;
	std::cout << "ORIGIN = " << vec.front() << std::endl << "MY     = " << my_vec.front() << std::endl;

	std::cout << YELLOW << "\tBACK" << RESET << std::endl;
	std::cout << "ORIGIN = " << vec.back() << std::endl << "MY     = " << my_vec.back() << std::endl;

	std::cout << YELLOW << "\tASSIGN" << RESET << std::endl;
	vec.assign(5, 30);
	my_vec.assign(5, 30);
	std::cout << "ORIGIN = ";
	for (size_t i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "MY     = ";
		for (size_t i = 0; i < my_vec.size(); i++)
	{
		std::cout << my_vec[i] << " ";
	}
	std::cout << std::endl;

	std::cout << YELLOW << "\tPOP BACK" << RESET << std::endl;
	vec.pop_back();
	my_vec.pop_back();
	std::cout << "ORIGIN = ";
	for (size_t i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "MY     = ";
		for (size_t i = 0; i < my_vec.size(); i++)
	{
		std::cout << my_vec[i] << " ";
	}
	std::cout << std::endl;

	std::cout << YELLOW << "\tINSERT" << RESET << std::endl;
	vec.insert(vec.begin() + 2, 2);
	my_vec.insert(my_vec.begin() + 2, 2);
	std::cout << "ORIGIN = ";
	for (size_t i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "MY     = ";
		for (size_t i = 0; i < my_vec.size(); i++)
	{
		std::cout << my_vec[i] << " ";
	}
	std::cout << std::endl;

	std::cout << YELLOW << "\tERASE" << RESET << std::endl;
	vec.erase(vec.begin());
	my_vec.erase(my_vec.begin());
	std::cout << "ORIGIN = ";
	for (size_t i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "MY     = ";
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
	std::cout << "ORIGIN 1 = ";
	for (size_t i = 0; i < vec1.size(); i++)
	{
		std::cout << vec1[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "MY 1     = ";
		for (size_t i = 0; i < my_vec1.size(); i++)
	{
		std::cout << my_vec1[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "ORIGIN = ";
	for (size_t i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "MY     = ";
		for (size_t i = 0; i < my_vec.size(); i++)
	{
		std::cout << my_vec[i] << " ";
	}
	std::cout << std::endl;

	std::cout << YELLOW << "\tCLEAR" << RESET << std::endl;
	vec.clear();
	my_vec.clear();
	std::cout << "ORIGIN = ";
	for (size_t i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "MY     = ";
		for (size_t i = 0; i < my_vec.size(); i++)
	{
		std::cout << my_vec[i] << " ";
	}
	std::cout << std::endl;
}

void    list_test()
{
    std::cout << RED << "\t===LIST TEST===" << RESET << std::endl;//////////////////////////////////////////////////////////
    ft::list<int> my_lst;
    std::list<int> lst;
    std::cout << YELLOW << "\tPUSH_BACK" << RESET << std::endl;//////////////////////////////////////////////////////////
    for (int i = 10; i < 21; ++i) {
        my_lst.push_back(i);
        lst.push_back(i);
    }
    ft::list<int>::iterator my_itr = my_lst.begin();
    ft::list<int>::iterator my_ite = my_lst.end();
    std::list<int>::iterator itr = lst.begin();
    std::list<int>::iterator ite = lst.end();
    std::cout << "ORIGIN = ";
    while (itr != ite)
    {
        std::cout << *itr << " ";
        itr++;
    }
    std::cout << std::endl;
    std::cout << "MY     = ";
    while (my_itr != my_ite)
    {
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
    std::cout << "ORIGIN = ";
    while (itr != ite)
    {
        std::cout << *itr << " ";
        itr++;
    }
    std::cout << std::endl;
    std::cout << "MY     = ";
    while (my_itr != my_ite)
    {
        std::cout << *my_itr << " ";
        my_itr++;
    }
    std::cout << std::endl;


    std::cout << YELLOW << "\tPUSH_FRONT" << RESET << std::endl;//////////////////////////////////////////////////////////
    for (int i = 0; i < 10; ++i) {
        my_lst.push_front(i);
        lst.push_front(i);
    }
    my_itr = my_lst.begin();
    my_ite = my_lst.end();
    itr = lst.begin();
    ite = lst.end();
    std::cout << "ORIGIN = ";
    while (itr != ite)
    {
        std::cout << *itr << " ";
        itr++;
    }
    std::cout << std::endl;
    std::cout << "MY     = ";
    while (my_itr != my_ite)
    {
        std::cout << *my_itr << " ";
        my_itr++;
    }
    std::cout << std::endl;

    std::cout << YELLOW << "\tPOP FRONT" << RESET << std::endl;//////////////////////////////////////////////////////////
    lst.pop_front();
    my_lst.pop_front();
    my_itr = my_lst.begin();
    my_ite = my_lst.end();
    itr = lst.begin();
    ite = lst.end();
    std::cout << "ORIGIN = ";
    while (itr != ite)
    {
        std::cout << *itr << " ";
        itr++;
    }
    std::cout << std::endl;
    std::cout << "MY     = ";
    while (my_itr != my_ite)
    {
        std::cout << *my_itr << " ";
        my_itr++;
    }
    std::cout << std::endl;

    std::cout << YELLOW << "\tEMPTY" << RESET << std::endl;//////////////////////////////////////////////////////////
    std::cout << "ORIGIN = " << lst.empty() << std::endl;
    std::cout << "MY     = " << my_lst.empty() << std::endl;

    std::cout << YELLOW << "\tSIZE" << RESET << std::endl;//////////////////////////////////////////////////////////
    std::cout << "ORIGIN = " << lst.size() << std::endl;
    std::cout << "MY     = " << my_lst.size() << std::endl;

    std::cout << YELLOW << "\tMAX SIZE" << RESET << std::endl;//////////////////////////////////////////////////////////
    std::cout << "ORIGIN = " << lst.max_size() << std::endl;
    std::cout << "MY     = " << my_lst.max_size() << std::endl;

    std::cout << YELLOW << "\tFRONT" << RESET << std::endl;//////////////////////////////////////////////////////////
    std::cout << "ORIGIN = " << lst.front() << std::endl;
    std::cout << "MY     = " << my_lst.front() << std::endl;

    std::cout << YELLOW << "\tBACK" << RESET << std::endl;//////////////////////////////////////////////////////////
    std::cout << "ORIGIN = " << lst.back() << std::endl;
    std::cout << "MY     = " << my_lst.back() << std::endl;

    std::cout << YELLOW << "\tASSIGN" << RESET << std::endl;//////////////////////////////////////////////////////////
    lst.assign(7, 100);
    my_lst.assign(7, 100);
    my_itr = my_lst.begin();
    my_ite = my_lst.end();
    itr = lst.begin();
    ite = lst.end();
    std::cout << "ORIGIN = ";
    while (itr != ite)
    {
        std::cout << *itr << " ";
        itr++;
    }
    std::cout << std::endl;
    std::cout << "MY     = ";
    while (my_itr != my_ite)
    {
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
    std::cout << "ORIGIN = ";
    while (itr != ite)
    {
        std::cout << *itr << " ";
        itr++;
    }
    std::cout << std::endl;
    std::cout << "MY     = ";
    while (my_itr != my_ite)
    {
        std::cout << *my_itr << " ";
        my_itr++;
    }
    std::cout << std::endl;
    my_itr = my_lst.begin();
    itr = lst.begin();
    lst.insert(++itr, 5, 777);
    my_lst.insert(++my_itr, 5,777);
    my_itr = my_lst.begin();
    my_ite = my_lst.end();
    itr = lst.begin();
    ite = lst.end();
    std::cout << "ORIGIN = ";
    while (itr != ite)
    {
        std::cout << *itr << " ";
        itr++;
    }
    std::cout << std::endl;
    std::cout << "MY     = ";
    while (my_itr != my_ite)
    {
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
    std::cout << "ORIGIN = ";
    while (itr != ite)
    {
        std::cout << *itr << " ";
        itr++;
    }
    std::cout << std::endl;
    std::cout << "MY     = ";
    while (my_itr != my_ite)
    {
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
    std::cout << "ORIGIN = ";
    while (itr != ite)
    {
        std::cout << *itr << " ";
        itr++;
    }
    std::cout << std::endl;
    std::cout << "MY     = ";
    while (my_itr != my_ite)
    {
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
    std::cout << "ORIGIN DO = ";
    while (itr != ite)
    {
        std::cout << *itr << " ";
        itr++;
    }
    itr = lst2.begin();
    ite = lst2.end();
    std::cout << "ORIGIN DO = ";
    while (itr != ite)
    {
        std::cout << *itr << " ";
        itr++;
    }
    std::cout << std::endl;
    std::cout << "MY     DO = ";
    while (my_itr != my_ite)
    {
        std::cout << *my_itr << " ";
        my_itr++;
    }
    my_itr = my_lst2.begin();
    my_ite = my_lst2.end();
    std::cout << "MY     DO = ";
    while (my_itr != my_ite)
    {
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
    std::cout << "ORIGIN SWAP = ";
    while (itr != ite)
    {
        std::cout << *itr << " ";
        itr++;
    }
    itr = lst2.begin();
    ite = lst2.end();
    std::cout << "ORIGIN SWAP = ";
    while (itr != ite)
    {
        std::cout << *itr << " ";
        itr++;
    }
    std::cout << std::endl;
    std::cout << "MY     SWAP = ";
    while (my_itr != my_ite)
    {
        std::cout << *my_itr << " ";
        my_itr++;
    }
    my_itr = my_lst2.begin();
    my_ite = my_lst2.end();
    std::cout << "MY     SWAP = ";
    while (my_itr != my_ite)
    {
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
    std::cout << "ORIGIN = ";
    while (itr != ite)
    {
        std::cout << *itr << " ";
        itr++;
    }
    std::cout << std::endl;
    std::cout << "MY     = ";
    while (my_itr != my_ite)
    {
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
    std::cout << "ORIGIN = ";
    while (itr != ite)
    {
        std::cout << *itr << " ";
        itr++;
    }
    std::cout << std::endl;
    std::cout << "MY     = ";
    while (my_itr != my_ite)
    {
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
    std::cout << "ORIGIN = ";
    while (itr != ite)
    {
        std::cout << *itr << " ";
        itr++;
    }
    std::cout << std::endl;
    std::cout << "MY     = ";
    while (my_itr != my_ite)
    {
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
    std::cout << "ORIGIN LST = ";
    while (itr != ite)
    {
        std::cout << *itr << " ";
        itr++;
    }
    itr = lst2.begin();
    ite = lst2.end();
    std::cout << "ORIGIN LST2 = ";
    while (itr != ite)
    {
        std::cout << *itr << " ";
        itr++;
    }
    std::cout << std::endl;
    std::cout << "MY     LST = ";
    while (my_itr != my_ite)
    {
        std::cout << *my_itr << " ";
        my_itr++;
    }
    my_itr = my_lst2.begin();
    my_ite = my_lst2.end();
    std::cout << "MY     LST = ";
    while (my_itr != my_ite)
    {
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
    std::cout << "ORIGIN LST = ";
    while (itr != ite)
    {
        std::cout << *itr << " ";
        itr++;
    }
    itr = lst2.begin();
    ite = lst2.end();
    std::cout << "ORIGIN LST2 = ";
    while (itr != ite)
    {
        std::cout << *itr << " ";
        itr++;
    }
    std::cout << std::endl;
    std::cout << "MY     LST = ";
    while (my_itr != my_ite)
    {
        std::cout << *my_itr << " ";
        my_itr++;
    }
    my_itr = my_lst2.begin();
    my_ite = my_lst2.end();
    std::cout << "MY     LST = ";
    while (my_itr != my_ite)
    {
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
    std::cout << "ORIGIN LST = ";
    while (itr != ite)
    {
        std::cout << *itr << " ";
        itr++;
    }
    itr = lst2.begin();
    ite = lst2.end();
    std::cout << "ORIGIN LST2 = ";
    while (itr != ite)
    {
        std::cout << *itr << " ";
        itr++;
    }
    std::cout << std::endl;
    std::cout << "MY     LST = ";
    while (my_itr != my_ite)
    {
        std::cout << *my_itr << " ";
        my_itr++;
    }
    my_itr = my_lst2.begin();
    my_ite = my_lst2.end();
    std::cout << "MY     LST = ";
    while (my_itr != my_ite)
    {
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
    std::cout << "ORIGIN = ";
    while (itr != ite)
    {
        std::cout << *itr << " ";
        itr++;
    }
    std::cout << std::endl;
    std::cout << "MY     = ";
    while (my_itr != my_ite)
    {
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
    std::cout << "ORIGIN = ";
    while (itr != ite)
    {
        std::cout << *itr << " ";
        itr++;
    }
    std::cout << std::endl;
    std::cout << "MY     = ";
    while (my_itr != my_ite)
    {
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
    std::cout << "ORIGIN = ";
    while (itrf != itef)
    {
        std::cout << *itrf << " ";
        itrf++;
    }
    std::cout << std::endl;
    std::cout << "MY     = ";
    while (my_itrf != my_itef)
    {
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
    std::cout << "ORIGIN = ";
    while (itr != ite)
    {
        std::cout << *itr << " ";
        itr++;
    }
    std::cout << std::endl;
    std::cout << "MY     = ";
    while (my_itr != my_ite)
    {
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
    std::cout << "ORIGIN = ";
    while (itr != ite)
    {
        std::cout << *itr << " ";
        itr++;
    }
    std::cout << std::endl;
    std::cout << "MY     = ";
    while (my_itr != my_ite)
    {
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
    std::cout << "ORIGIN = ";
    while (itr != ite)
    {
        std::cout << *itr << " ";
        itr++;
    }
    std::cout << std::endl;
    std::cout << "MY     = ";
    while (my_itr != my_ite)
    {
        std::cout << *my_itr << " ";
        my_itr++;
    }
    std::cout << std::endl;
}