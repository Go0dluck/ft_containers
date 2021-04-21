#pragma once
#include <memory>

namespace ft
{
	template <typename Iterator>
	ptrdiff_t distance(Iterator first, Iterator last) //расчет кол-ва элементов в массиве
	{
		ptrdiff_t n = 0;
		while (first != last)
		{
			n++;
			first++;
		}
		return (n);
	}
}
