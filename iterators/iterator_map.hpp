#pragma once
#include "Utils.hpp"

template <class Key, class T>
class iterator_map
{
public:
    typedef             Key key_type;
    typedef             T mapped_type;
    typedef             std::pair<key_type, mapped_type> value_type;
    typedef             std::pair<key_type, mapped_type> &reference;
    typedef	            ptrdiff_t difference_type;
    typedef             ft::NodeMap<key_type, mapped_type>* pointer;
private:
    pointer _node;
public:
    iterator_map() : _node(NULL) {};
    iterator_map(pointer ptr) : _node(ptr) {};
    ~iterator_map() {};
    iterator_map(const iterator_map &cpy) : _node(cpy._node) {} ;
    iterator_map &operator=(const iterator_map &oper)
    {
        if (this == &oper)
            return *this;
        _node = oper._node;
        return *this;
    }
    bool operator==(const iterator_map &itr) const
    {
        return (_node == itr._node);
    }
    bool operator!=(const iterator_map &itr) const
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
    iterator_map &operator++()
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
    iterator_map operator++(int)
    {
        iterator_map tmp = *this;
        ++(*this);
        return (tmp);
    }
    iterator_map &operator--()
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
            while (next->parent != nullptr && next == next->parent->left) {
                next = next->parent;
            }
            next = next->parent;
        }
        _node = next;
        return (*this);
    }
    iterator_map operator--(int)
    {
        iterator_map tmp = *this;
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