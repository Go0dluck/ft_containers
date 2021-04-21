#pragma once
#include "../List.hpp"

template <typename List>
class reverse_iterator_list
{
	public:
        typedef typename List::value_type value_type;
        typedef	ptrdiff_t difference_type;
        typedef typename List::node* pointer;
	private:
		pointer _node;
	public:
		reverse_iterator_list(value_type node = NULL) : _node(node) {};
		~reverse_iterator_list() {} ;
		reverse_iterator_list(const reverse_iterator_list &cpy) : _node(cpy._node) {};
		reverse_iterator_list &operator=(const reverse_iterator_list &oper)
		{
			if (this == &oper)
				return (*this);
			_node = oper._pointer;
			return (*this);
		};
		bool operator==(const reverse_iterator_list &itr) const
		{
			return (_node != itr._node);
		}
		bool operator!=(const reverse_iterator_list &itr) const
		{
			return (_node == itr._node);
		}
		value_type operator*()
		{
			return (_node->data);
		}
		pointer operator->()
		{
			return (_node);
		}
		reverse_iterator_list &operator++()
		{
			_node = _node->prev;
			return (*this);
		}
		reverse_iterator_list operator++(int)
		{
			reverse_iterator_list tmp = *this;
			--(*this);
			return (tmp);
		}
		reverse_iterator_list &operator--()
		{
			_node = _node->next;
			return (*this);
		}
		reverse_iterator_list operator--(int)
		{
			reverse_iterator_list tmp = *this;
			++(*this);
			return (tmp);
		}
};
