#pragma once
#include "Utils.hpp"

template <class T>
class iterator_set
{
public:
	typedef T value_type;
	typedef	ptrdiff_t difference_type;
	// typedef T* pointer;
	typedef T& reference;
	typedef ft::setnode<value_type>* pointer;
private:
	pointer _node;
public:
	iterator_set() : _node(nullptr) {};
	iterator_set(pointer ptr) : _node(ptr) {};
	~iterator_set() {};
	iterator_set(const iterator_set &cpy) : _node(cpy._node) {} ;
	iterator_set &operator=(const iterator_set &oper)
	{
		if (this == &oper)
			return *this;
		_node = oper._node;
		return *this;
	}
	bool operator==(const iterator_set &itr) const
	{
		return (_node == itr._node);
	}
	bool operator!=(const iterator_set &itr) const
	{
		return (_node != itr._node);
	}
	value_type &operator*()
	{
		return _node->data;
	}
	value_type *operator->()
	{
		return &_node->data;
	}
	iterator_set &operator++()
	{
		pointer next = _node;
		if (_node->right != nullptr)
		{
			next = _node->right;
			while (next->left)
				next = next->left;
		}
		else
		{
			while (next->parent && next == next->parent->right)
				next = next->parent;
			next = next->parent;
		}
		_node = next;
		return (*this);
	}
	iterator_set operator++(int)
	{
		iterator_set tmp = *this;
		++(*this);
		return (tmp);
	}
	iterator_set &operator--()
	{
		pointer next = _node;
		if (_node->left != nullptr)
		{
			next = _node->left;
			while (next->right)
				next = next->right;
		}
		else
		{
			while (next->parent != nullptr && next == next->parent->left)
				next = next->parent;
			next = next->parent;
		}
		_node = next;
		return (*this);
	}
	iterator_set operator--(int)
	{
		iterator_set tmp = *this;
		--(*this);
		return (tmp);
	}
	pointer getNode()
	{
		return _node;
	}
	pointer getNode() const
	{
		return _node;
	}
};
