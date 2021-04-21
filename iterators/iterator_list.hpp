#pragma once
#include "../List.hpp"

template <typename List>
class iterator_list
{
	public:
        typedef typename List::value_type value_type;
		typedef	ptrdiff_t difference_type;
        typedef typename List::node* pointer;
    private:
		pointer _node;
	public:
		iterator_list() : _node(NULL) {};
		pointer get_node() const
		{
		  return (_node);
		};
        iterator_list(pointer ptr) : _node(ptr) {};
		~iterator_list() {} ;
		iterator_list(const iterator_list &cpy) : _node(cpy._node) {};
		iterator_list &operator=(const iterator_list &oper)
		{
			if (this == &oper)
				return (*this);
			_node = oper._node;
			return (*this);
		};
		bool operator==(const iterator_list &itr) const
		{
			return (_node == itr._node);
		}
		bool operator!=(const iterator_list &itr) const
		{
			return (_node != itr._node);
		}
		value_type operator*()
		{
			return (_node->data);
		}
		pointer operator->()
		{
			return (_node);
		}
		iterator_list &operator++()
		{
			_node = _node->next;
			return (*this);
		}
		iterator_list operator++(int)
		{
			iterator_list tmp = *this;
			++(*this);
			return (tmp);
		}
		iterator_list &operator--()
		{
			_node = _node->prev;
			return (*this);
		}
		iterator_list operator--(int)
		{
			iterator_list tmp = *this;
			--(*this);
			return (tmp);
		}
};
