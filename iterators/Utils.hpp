#pragma once
#include <memory>

namespace ft
{
    template <class K, class T>
    class anode
    {
    public:
        std::pair<K, T>   data;
        int       height;
        anode     *left;
        anode     *right;
        anode     *parent;
        bool        end;
        explicit anode(std::pair<K, T> val) {
            data = val;
            left = right = parent = nullptr;
            height = 1;
            end = false;
        }
    };
    template <class T>
    class setnode
    {
    public:
        T   data;
        int         height;
        setnode     *left;
        setnode     *right;
        setnode     *parent;
        bool        end;
        explicit setnode(T val) {
            data = val;
            left = right = parent = nullptr;
            height = 1;
            end = false;
        }
    };
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
    template <class K, class T>
    struct NodeMap
    {
        std::pair<K, T>   data;
        NodeMap     *left;
        NodeMap     *right;
        NodeMap     *parent;
        bool        end;
    };
}
