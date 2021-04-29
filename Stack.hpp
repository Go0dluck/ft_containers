#pragma once
#include "List.hpp"

namespace ft
{
    template <class T, class Container = ft::list<T> >
    class stack
    {
    public:
        typedef     T value_type;
        typedef     Container container_type;
        typedef		size_t size_type;
    private:
        container_type _st;
    public:
        explicit stack (const container_type& ctnr = container_type()) : _st(ctnr)
        {
        }
        bool empty() const
        {
            return (_st.empty());
        }
        size_type size() const
        {
            return (_st.size());
        }
        value_type& top()
        {
            return (_st.back());
        }
        const value_type& top() const
        {
            return (_st.back());
        }
        void push (const value_type& val)
        {
            _st.push_back(val);
        }
        void pop()
        {
            _st.pop_back();
        }
    };
    template <class value_type, class container_type>
    bool operator== (const stack<value_type,container_type>& lhs, const stack<value_type,container_type>& rhs)
    {
        return (lhs == rhs);
    }
    template <class value_type, class container_type>
    bool operator!= (const stack<value_type,container_type>& lhs, const stack<value_type,container_type>& rhs)
    {
        return (lhs != rhs);
    }
    template <class value_type, class container_type>
    bool operator< (const stack<value_type,container_type>& lhs, const stack<value_type,container_type>& rhs)
    {
        return (lhs < rhs);
    }
    template <class value_type, class container_type>
    bool operator<= (const stack<value_type,container_type>& lhs, const stack<value_type,container_type>& rhs)
    {
        return (lhs <= rhs);
    }
    template <class value_type, class container_type>
    bool operator> (const stack<value_type,container_type>& lhs, const stack<value_type,container_type>& rhs)
    {
        return (lhs > rhs);
    }
    template <class value_type, class container_type>
    bool operator>= (const stack<value_type,container_type>& lhs, const stack<value_type,container_type>& rhs)
    {
        return (lhs >= rhs);
    }
}