#pragma once
#include "List.hpp"

namespace ft
{
    template <class T, class Container = ft::list<T> >
    class queue
    {
    public:
        typedef     T value_type;
        typedef     Container container_type;
        typedef		size_t size_type;
    private:
        container_type _qu;
    public:
        explicit queue (const container_type& ctnr = container_type()) : _qu(ctnr)
        {
        }
        bool empty() const
        {
            return (_qu.empty());
        }
        size_type size() const
        {
            return (_qu.size());
        }
        value_type& front()
        {
            return (_qu.front());
        }
        const value_type& front() const
        {
            return (_qu.front());
        }
        value_type& back()
        {
            return (_qu.back());
        }
        const value_type& back() const
        {
            return (_qu.back());
        }
        void push (const value_type& val)
        {
            _qu.push_back(val);
        }
        void pop()
        {
            _qu.pop_front();
        }
    };
    template <class value_type, class container_type>
    bool operator== (const queue<value_type,container_type>& lhs, const queue<value_type,container_type>& rhs)
    {
        return (lhs == rhs);
    }
    template <class value_type, class container_type>
    bool operator!= (const queue<value_type,container_type>& lhs, const queue<value_type,container_type>& rhs)
    {
        return (lhs != rhs);
    }
    template <class value_type, class container_type>
    bool operator< (const queue<value_type,container_type>& lhs, const queue<value_type,container_type>& rhs)
    {
        return (lhs < rhs);
    }
    template <class value_type, class container_type>
    bool operator<= (const queue<value_type,container_type>& lhs, const queue<value_type,container_type>& rhs)
    {
        return (lhs <= rhs);
    }
    template <class value_type, class container_type>
    bool operator> (const queue<value_type,container_type>& lhs, const queue<value_type,container_type>& rhs)
    {
        return (lhs > rhs);
    }
    template <class value_type, class container_type>
    bool operator>= (const queue<value_type,container_type>& lhs, const queue<value_type,container_type>& rhs)
    {
        return (lhs >= rhs);
    }
}