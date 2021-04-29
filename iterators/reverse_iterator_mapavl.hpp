#pragma once
#include "Utils.hpp"

template <class Key, class T>
class reverse_iterator_mapavl
{
public:
	typedef             Key key_type;
	typedef             T mapped_type;
	typedef             std::pair<key_type, mapped_type> value_type;
	typedef             std::pair<key_type, mapped_type> &reference;
	typedef	            ptrdiff_t difference_type;
	typedef             ft::anode<key_type, mapped_type>* pointer;
private:
	pointer _node;
public:
	reverse_iterator_mapavl() : _node(nullptr) {};
	reverse_iterator_mapavl(pointer ptr) : _node(ptr) {};
	~reverse_iterator_mapavl() {};
	reverse_iterator_mapavl(const reverse_iterator_mapavl &cpy) : _node(cpy._node) {} ;
	reverse_iterator_mapavl &operator=(const reverse_iterator_mapavl &oper)
	{
		if (this == &oper)
			return *this;
		_node = oper._node;
		return *this;
	}
	bool operator==(const reverse_iterator_mapavl &itr) const
	{
		return (_node == itr._node);
	}
	bool operator!=(const reverse_iterator_mapavl &itr) const
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
	reverse_iterator_mapavl &operator++()
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
	reverse_iterator_mapavl operator++(int)
	{
		reverse_iterator_mapavl tmp = *this;
		++(*this);
		return (tmp);
	}
	reverse_iterator_mapavl &operator--()
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
	reverse_iterator_mapavl operator--(int)
	{
		reverse_iterator_mapavl tmp = *this;
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