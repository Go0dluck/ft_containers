#include "../MapAvl.hpp"
#include <map>
#include <iostream>

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define VIOLET "\033[35m"

int main()
{
	std::cout << RED << "\t=====MAP TEST=====" << RESET << std::endl;
	std::cout << YELLOW << "  =====INSERT=====" << RESET << std::endl;
	std::map<char, int> mp;
	ft::map<char, int> my_mp;
	for (size_t i = 0; i < 10; i++)
	{
		mp.insert(std::make_pair(i + 65, i + 65));
		my_mp.insert(std::make_pair(i + 65, i + 65));
	}
	std::map<char, int>::iterator itr = mp.begin();
	std::map<char, int>::iterator ite = mp.end();
	ft::map<char, int>::iterator my_itr = my_mp.begin();
	ft::map<char, int>::iterator my_ite = my_mp.end();
	std::cout << GREEN << "ORIGINAL = " << RESET;
	while (itr != ite)
	{
		std::cout << (*itr).first << "-" << (*itr).second << " ";
		itr++;
	}
	std::cout << std::endl;
	std::cout << GREEN << "MY       = " << RESET;
	while (my_itr != my_ite)
	{
		std::cout << (*my_itr).first << "-" << (*my_itr).second << " ";
		my_itr++;
	}
	std::cout << std::endl;

	std::cout << YELLOW << "  =====EMPTY=====" << RESET << std::endl;
	std::cout << GREEN << "ORIGINAL = " << RESET << mp.empty() << std::endl;
	std::cout << GREEN << "MY       = " << RESET << my_mp.empty() << std::endl;

	std::cout << YELLOW << "  =====SIZE=====" << RESET << std::endl;
	std::cout << GREEN << "ORIGINAL = " << RESET << mp.size() << std::endl;
	std::cout << GREEN << "MY       = " << RESET << my_mp.size() << std::endl;

	std::cout << YELLOW << "  =====MAX SIZE=====" << RESET << std::endl;
	std::cout << GREEN << "ORIGINAL = " << RESET << mp.max_size() << std::endl;
	std::cout << GREEN << "MY       = " << RESET << my_mp.max_size() << std::endl;

	std::cout << YELLOW << "  =====OPERATOR []=====" << RESET << std::endl;
	std::cout << GREEN << "ORIGINAL A ELEMENT = " << RESET << mp['A'] << std::endl;
	std::cout << GREEN << "MY A ELEMENT       = " << RESET << my_mp['A'] << std::endl;
	std::cout << GREEN << "ORIGINAL Z ELEMENT = " << RESET << mp['Z'] << std::endl;
	std::cout << GREEN << "MY Z ELEMENT       = " << RESET << my_mp['Z'] << std::endl;
	itr = mp.begin();
	ite = mp.end();
	my_itr = my_mp.begin();
	my_ite = my_mp.end();
	std::cout << GREEN << "ORIGINAL = " << RESET;
	while (itr != ite)
	{
		std::cout << (*itr).first << "-" << (*itr).second << " ";
		itr++;
	}
	std::cout << std::endl;
	std::cout << GREEN << "MY       = " << RESET;
	while (my_itr != my_ite)
	{
		std::cout << (*my_itr).first << "-" << (*my_itr).second << " ";
		my_itr++;
	}
	std::cout << std::endl;

	std::cout << YELLOW << "  =====ERASE=====" << RESET << std::endl;
	mp.erase(mp.begin());
	my_mp.erase(my_mp.begin());
	itr = mp.begin();
	ite = mp.end();
	my_itr = my_mp.begin();
	my_ite = my_mp.end();
	std::cout << GREEN << "ORIGINAL ITERATOR = " << RESET;
	while (itr != ite)
	{
		std::cout << (*itr).first << "-" << (*itr).second << " ";
		itr++;
	}
	std::cout << std::endl;
	std::cout << GREEN << "MY ITERATOR       = " << RESET;
	while (my_itr != my_ite)
	{
		std::cout << (*my_itr).first << "-" << (*my_itr).second << " ";
		my_itr++;
	}
	std::cout << std::endl;
	mp.erase('E');
	my_mp.erase('E');
	itr = mp.begin();
	ite = mp.end();
	my_itr = my_mp.begin();
	my_ite = my_mp.end();
	std::cout << GREEN << "ORIGINAL 'E' KEY = " << RESET;
	while (itr != ite)
	{
		std::cout << (*itr).first << "-" << (*itr).second << " ";
		itr++;
	}
	std::cout << std::endl;
	std::cout << GREEN << "MY 'E' KEY       = " << RESET;
	while (my_itr != my_ite)
	{
		std::cout << (*my_itr).first << "-" << (*my_itr).second << " ";
		my_itr++;
	}
	std::cout << std::endl;

	std::cout << YELLOW << "  =====SWAP=====" << RESET << std::endl;
	std::map<char, int> mp_sw;
	ft::map<char, int> my_mp_sw;
	for (size_t i = 10; i < 20; i++)
	{
		mp_sw.insert(std::make_pair(i + 65, i + 65));
		my_mp_sw.insert(std::make_pair(i + 65, i + 65));
	}
	itr = mp.begin();
	ite = mp.end();
	std::cout << GREEN << "ORIGINAL 1 = " << RESET;
	while (itr != ite)
	{
		std::cout << (*itr).first << "-" << (*itr).second << " ";
		itr++;
	}
	itr = mp_sw.begin();
	ite = mp_sw.end();
	std::cout << GREEN << " ORIGINAL 2 = " << RESET;
	while (itr != ite)
	{
		std::cout << (*itr).first << "-" << (*itr).second << " ";
		itr++;
	}
	std::cout << std::endl;
	my_itr = my_mp.begin();
	my_ite = my_mp.end();
	std::cout << GREEN << "MY 1       = " << RESET;
	while (my_itr != my_ite)
	{
		std::cout << (*my_itr).first << "-" << (*my_itr).second << " ";
		my_itr++;
	}
	my_itr = my_mp_sw.begin();
	my_ite = my_mp_sw.end();
	std::cout << GREEN << " MY 2       = " << RESET;
	while (my_itr != my_ite)
	{
		std::cout << (*my_itr).first << "-" << (*my_itr).second << " ";
		my_itr++;
	}
	std::cout << std::endl;
	mp.swap(mp_sw);
	my_mp.swap(my_mp_sw);

	itr = mp.begin();
	ite = mp.end();
	std::cout << GREEN << "ORIGINAL 1 SWAP = " << RESET;
	while (itr != ite)
	{
		std::cout << (*itr).first << "-" << (*itr).second << " ";
		itr++;
	}
	itr = mp_sw.begin();
	ite = mp_sw.end();
	std::cout << GREEN << " ORIGINAL 2 SWAP = " << RESET;
	while (itr != ite)
	{
		std::cout << (*itr).first << "-" << (*itr).second << " ";
		itr++;
	}
	std::cout << std::endl;
	my_itr = my_mp.begin();
	my_ite = my_mp.end();
	std::cout << GREEN << "MY 1 SWAP       = " << RESET;
	while (my_itr != my_ite)
	{
		std::cout << (*my_itr).first << "-" << (*my_itr).second << " ";
		my_itr++;
	}
	my_itr = my_mp_sw.begin();
	my_ite = my_mp_sw.end();
	std::cout << GREEN << " MY 2 SWAP       = " << RESET;
	while (my_itr != my_ite)
	{
		std::cout << (*my_itr).first << "-" << (*my_itr).second << " ";
		my_itr++;
	}
	std::cout << std::endl;

	std::cout << YELLOW << "  =====KEY_COMP=====" << RESET << std::endl;
	std::map<char,int> mymap;
  	std::map<char,int>::key_compare mycomp = mymap.key_comp();
	ft::map<char,int> mymap1;
  	ft::map<char,int>::key_compare mycomp1 = mymap1.key_comp();
	mymap['a']=100;
  	mymap['b']=200;
 	mymap['c']=300;
	mymap1['a']=100;
  	mymap1['b']=200;
 	mymap1['c']=300;
	std::cout << GREEN << "ORIGINAL = \n" << RESET;
	char highest = mymap.rbegin()->first;
	char highest1 = mymap1.rbegin()->first;
	std::map<char,int>::iterator it = mymap.begin();
	do {
		std::cout << it->first << " => " << it->second << '\n';
	} while ( mycomp((*it++).first, highest) );
	std::cout << GREEN << "MY       = \n" << RESET;
	ft::map<char,int>::iterator my_it = mymap1.begin();
	do {
		std::cout << my_it->first << " => " << my_it->second << '\n';
	} while ( mycomp1((*my_it++).first, highest1) );

	std::cout << YELLOW << "  =====VALUE COMP=====" << RESET << std::endl;
	mymap.clear();
	mymap1.clear();
	mymap['x']=1001;
  	mymap['y']=2002;
  	mymap['z']=3003;
	mymap1['x']=1001;
  	mymap1['y']=2002;
  	mymap1['z']=3003;
	std::cout << GREEN << "ORIGINAL = \n" << RESET;
	std::pair<char,int> highest3 = *mymap.rbegin();
	it = mymap.begin();
	do {
		std::cout << it->first << " => " << it->second << '\n';
	} while ( mymap.value_comp()(*it++, highest3) );
	std::cout << GREEN << "MY       = \n" << RESET;
	std::pair<char,int> highest4 = *mymap1.rbegin();
	my_it = mymap1.begin();
	do {
		std::cout << my_it->first << " => " << my_it->second << '\n';
	} while ( mymap1.value_comp()(*my_it++, highest4) );

	std::cout << YELLOW << "  =====FIND=====" << RESET << std::endl;
	mymap.clear();
	mymap1.clear();
	mymap['a']=50;
	mymap['b']=100;
	mymap['c']=150;
	mymap['d']=200;
	mymap1['a']=50;
	mymap1['b']=100;
	mymap1['c']=150;
	mymap1['d']=200;
	std::cout << GREEN << "ORIGINAL = \n" << RESET;
	it = mymap.find('b');
	if (it != mymap.end())
		mymap.erase (it);
	std::cout << "a => " << mymap.find('a')->second << '\n';
	std::cout << "c => " << mymap.find('c')->second << '\n';
	std::cout << "d => " << mymap.find('d')->second << '\n';
	std::cout << GREEN << "MY       = \n" << RESET;
	my_it = mymap1.find('b');
	if (my_it != mymap1.end())
		mymap1.erase (my_it);
	std::cout << "a => " << mymap1.find('a')->second << '\n';
	std::cout << "c => " << mymap1.find('c')->second << '\n';
	std::cout << "d => " << mymap1.find('d')->second << '\n';

	std::cout << YELLOW << "  =====COUNT=====" << RESET << std::endl;
	mymap.clear();
	mymap1.clear();
	mymap['a']=101;
  	mymap['c']=202;
 	mymap['f']=303;
	mymap1['a']=101;
  	mymap1['c']=202;
 	mymap1['f']=303;
	char c;
	// char c1;
	std::cout << GREEN << "ORIGINAL = \n" << RESET;
	for (c='a'; c<'h'; c++)
	{
		std::cout << c;
		if (mymap.count(c)>0)
		std::cout << " is an element of mymap.\n";
		else
		std::cout << " is not an element of mymap.\n";
	}
	std::cout << GREEN << "MY       = \n" << RESET;
	for (c='a'; c<'h'; c++)
	{
		std::cout << c;
		if (mymap1.count(c)>0)
		std::cout << " is an element of mymap.\n";
		else
		std::cout << " is not an element of mymap.\n";
	}

	std::cout << YELLOW << "  =====LOWER/UPPER BOUND=====" << RESET << std::endl;
	std::map<char,int>::iterator itlow,itup;
	ft::map<char,int>::iterator itlow1,itup1;
	mymap.clear();
	mymap1.clear();
	mymap['a']=20;
	mymap['b']=40;
	mymap['c']=60;
	mymap['d']=80;
	mymap['e']=100;
	mymap1['a']=20;
	mymap1['b']=40;
	mymap1['c']=60;
	mymap1['d']=80;
	mymap1['e']=100;
	std::cout << GREEN << "ORIGINAL = \n" << RESET;
	itlow=mymap.lower_bound ('b');
	itup=mymap.upper_bound ('d');
	mymap.erase(itlow,itup);
	for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	std::cout << GREEN << "MY       = \n" << RESET;
	itlow1=mymap1.lower_bound ('b');
	itup1=mymap1.upper_bound ('d');
	mymap1.erase(itlow1,itup1);
	for (ft::map<char,int>::iterator it=mymap1.begin(); it!=mymap1.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	std::cout << YELLOW << "  =====EQUAL RANGE=====" << RESET << std::endl;
	mymap.clear();
	mymap1.clear();
	mymap['a']=10;
	mymap['b']=20;
	mymap['c']=30;
	mymap1['a']=10;
	mymap1['b']=20;
	mymap1['c']=30;
	std::cout << GREEN << "ORIGINAL = \n" << RESET;
	std::pair<std::map<char,int>::iterator,std::map<char,int>::iterator> ret;
	ret = mymap.equal_range('b');
	std::cout << "lower bound points to: ";
	std::cout << ret.first->first << " => " << ret.first->second << '\n';
	std::cout << "upper bound points to: ";
	std::cout << ret.second->first << " => " << ret.second->second << '\n';

	std::cout << GREEN << "MY       = \n" << RESET;
	std::pair<ft::map<char,int>::iterator,ft::map<char,int>::iterator> ret1;
	ret1 = mymap1.equal_range('b');
	std::cout << "lower bound points to: ";
	std::cout << ret1.first->first << " => " << ret1.first->second << '\n';
	std::cout << "upper bound points to: ";
	std::cout << ret1.second->first << " => " << ret1.second->second << '\n';
}
