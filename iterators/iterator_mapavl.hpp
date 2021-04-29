#pragma once
#include "Utils.hpp"

template <class Key, class T>
class iterator_mapavl
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
    iterator_mapavl() : _node(nullptr) {};
    iterator_mapavl(pointer ptr) : _node(ptr) {};
    ~iterator_mapavl() {};
    iterator_mapavl(const iterator_mapavl &cpy) : _node(cpy._node) {} ;
    iterator_mapavl &operator=(const iterator_mapavl &oper)
    {
        if (this == &oper)
            return *this;
        _node = oper._node;
        return *this;
    }
    bool operator==(const iterator_mapavl &itr) const
    {
        return (_node == itr._node);
    }
    bool operator!=(const iterator_mapavl &itr) const
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
    iterator_mapavl &operator++()
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
    iterator_mapavl operator++(int)
    {
        iterator_mapavl tmp = *this;
        ++(*this);
        return (tmp);
    }
    iterator_mapavl &operator--()
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
    iterator_mapavl operator--(int)
    {
        iterator_mapavl tmp = *this;
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