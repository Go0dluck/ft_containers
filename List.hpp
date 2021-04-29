#pragma once
#include <memory>
#include <iostream>
#include "iterators/iterator_list.hpp"
#include "iterators/reverse_iterator_list.hpp"
#include <unistd.h>
#include "iterators/enableif.hpp"
namespace ft
{
	template <typename T>
	struct Node
	{
		T		data;
		Node	*prev;
		Node	*next;
	};

	template < class T, class Alloc = std::allocator<T> >
	class list
	{
		public:
			typedef				T value_type;
			typedef				Alloc allocator_type;
			typedef				value_type &reference;
			typedef				value_type const &const_reference;
			typedef				value_type *pointer;
			typedef				Node<value_type> node;
			typedef				value_type const *const_pointer;
			typedef				ptrdiff_t difference_type;
			typedef				size_t size_type;
			typedef				iterator_list<list<T> > iterator;
			typedef const		iterator_list<list<T> > const_iterator;
			typedef				reverse_iterator_list<list<T> > reverse_iterator;
			typedef const		reverse_iterator_list<list<T> > const_reverse_iterator;
            typedef typename    Alloc::template rebind<node>::other allocator_rebind;
		private:
            node	*_head;
			size_type			_size;
            allocator_rebind		_alloc;
		public:
			explicit list (const allocator_type& alloc = allocator_type()) : _alloc(alloc)
			{
//			    _head = new node;
                _head = _alloc.allocate(1);
                _alloc.construct(_head, node());
                _head->next = _head;
                _head->prev = _head;
				_size = 0;
			}
			explicit list (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
			{
                _alloc = alloc;
//                _head = new node;
                _head = _alloc.allocate(1);
                _alloc.construct(_head, node());
                _head->next = _head;
                _head->prev = _head;
                _size = 0;
                assign(n, val);
			}
			template <class InputIterator>
            list (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(), typename ft::enable_if<!ft::integral<InputIterator>::value >::type* = 0)
            {
                _alloc = alloc;
//                _head = new node;
                _head = _alloc.allocate(1);
                _alloc.construct(_head, node());
                _head->next = _head;
                _head->prev = _head;
                _size = 0;
                assign(first, last);
            }
            list (const list &cpy)
            {
//                _head = new node;
                _head = _alloc.allocate(1);
                _alloc.construct(_head, node());
                _head->next = _head;
                _head->prev = _head;
                _size = 0;
                assign(cpy.begin(), cpy.end());
                _size = cpy.size();
                _alloc = cpy._alloc;
            }
            list &operator=(const list &oper)
            {
                if (this == &oper)
                    return (*this);
//                _head = new node;
                _head = _alloc.allocate(1);
                _alloc.construct(_head, node());
                _head->next = nullptr;
                _head->prev = nullptr;
                _size = 0;
                assign(oper.begin(), oper.end());
                _size = oper.size();
                _alloc = oper._alloc;
                return (*this);
            }
			~list()
            {
                clear();
//                delete _head;
                _alloc.destroy(_head);
                _alloc.deallocate(_head, 1);
            }
            //////////////Iterators//////////////
            iterator begin()
            {
			    return (iterator(_head->next));
            }
            const_iterator begin() const
            {
                return (const_iterator(_head->next));
            }
            iterator end()
            {
                return (iterator(_head));
            }
            const_iterator end() const
            {
                return (const_iterator(_head));
            }
            reverse_iterator rbegin()
            {
                return (reverse_iterator(_head->prev));
            }
            const_reverse_iterator rbegin() const
            {
                return (const_reverse_iterator(_head->prev));
            }
            reverse_iterator rend()
            {
                return (reverse_iterator(_head->next));
            }
            const_reverse_iterator rend() const
            {
                return (const_reverse_iterator(_head->next));
            }
            //////////////Capacity///////////////
            bool empty() const
            {
			    return (_size == 0);
            }
            size_type size() const
            {
                return (_size);
            }
            size_type max_size() const
            {
                return (_alloc.max_size());
            }
            ///////////Element access:///////////
            reference front()
            {
			    if (_size == 0)
                    return reference ("front called on empty list");
                return reference (_head->next->data);
            }
            const_reference front() const
            {
                if (_size == 0)
                    return const_reference ("front called on empty list");
                return const_reference (_head->next->data);
            }
            reference back()
            {
                if (_size == 0)
                    return reference ("back called on empty list");
                return reference (_head->prev->data);
            }
            const_reference back() const
            {
                if (_size == 0)
                    return const_reference ("back called on empty list");
                return const_reference (_head->prev->data);
            }
			//////////////Modifiers//////////////
            template <class InputIterator>
            void assign (InputIterator first, InputIterator last, typename ft::enable_if<!ft::integral<InputIterator>::value >::type* = 0)
            {
                clear();
                while (first != last)
                {
                    push_back(*first);
                    first++;
                }
            }
            void assign (size_type n, const value_type& val)
            {
                clear();
                for (size_type i = 0; i < n; ++i)
                    push_back(val);
            }
            void push_front (const value_type& val)
            {
                node *_node = _alloc.allocate(1);
                _alloc.construct(_node, node());

                _node->data = val;
                if (_size == 0) {
                    _head->next = _node;
                    _head->prev = _node;
                    _node->next = _head;
                    _node->prev = _head;
                }
                else
                {
                    _node->next = _head->next;
                    _head->next->prev = _node;
                    _head->next = _node;
                    _node->prev = _head;
                }
                _size++;
            }
            void pop_front()
            {
			    node *tmp;
			    if (_size != 0)
                {
			        tmp = _head->next;
			        _head->next = tmp->next;
//			        delete tmp;
                    _alloc.destroy(tmp);
                    _alloc.deallocate(tmp, 1);
			        _size--;
                }
            }
			void push_back(const value_type& val)
			{
                node *_node = _alloc.allocate(1);
                _alloc.construct(_node, node());

                _node->data = val;
                if (_size == 0) {
                    _head->next = _node;
                    _head->prev = _node;
                    _node->next = _head;
                    _node->prev = _head;
                }
                else
                {
                    _node->prev = _head->prev;
                    _head->prev->next = _node;
                    _head->prev = _node;
                    _node->next = _head;
                }
                _size++;
			}
            void pop_back()
            {
			    node *tmp;
			    if (_size != 0)
                {
			        tmp = _head->prev;
			        _head->prev = tmp->prev;
			        tmp->prev->next = _head;
//			        delete (tmp);
                    _alloc.destroy(tmp);
                    _alloc.deallocate(tmp, 1);
                    _size--;
                }
            }
            iterator insert (iterator position, const value_type& val)
            {
                node *tmp = position.get_node();
                node *new_node = _alloc.allocate(1);
                _alloc.construct(new_node, node());
                new_node->data = val;
                new_node->next = tmp;
                new_node->prev = tmp->prev;
                tmp->prev->next = new_node;
                tmp->prev = new_node;
                _size++;
                return (iterator(new_node));
            }
            void insert (iterator position, size_type n, const value_type& val)
            {
                for (size_type i = 0; i < n; ++i) {
                    insert(position, val);
                }
            }
            template <class InputIterator>
            void insert (iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!ft::integral<InputIterator>::value >::type* = 0)
            {
			    while (first != last)
                {
			        insert(position, *first);
			        first++;
                }
            }
            iterator erase (iterator position)
            {
			    node *tmp = position.get_node();
			    tmp->next->prev = tmp->prev;
			    tmp->prev->next = tmp->next;
//			    delete tmp;
			    _size--;
                _alloc.destroy(tmp);
                _alloc.deallocate(tmp, 1);
			    return (iterator(tmp->next));
            }
            iterator erase (iterator first, iterator last)
            {
			    iterator rez = first;
                while (first != last)
                {
                    rez = erase(first);
                    first++;
                }
                return (rez);
            }
            void swap (list& x)
            {
			    list<value_type> tmp;
                tmp.assign(x.begin(), x.end());
			    x.assign(this->begin(), this->end());
                this->assign(tmp.begin(), tmp.end());
                tmp.clear();
            }
            void resize (size_type n, value_type val = value_type())
            {
			    if (n > _size)
                {
                    size_type tmp = n - _size;
                    for (size_type i = 0; i < tmp; ++i) {
                        push_back(val);
                    }
                }
			    else if (n < _size)
                {
                    size_type tmp =  _size - n;
                    for (size_type i = 0; i < tmp; ++i) {
                        pop_back();
                    }
                }
            }
            void clear()
            {
                while (_size)
                    pop_back();
            }
            ////////////////////Operations:///////////////////////
            void splice (iterator position, list& x)
            {
                iterator itr = x.begin();
                iterator ite = x.end();
                for (iterator itr = x.begin(); itr != x.end();)
                {
                    iterator next = itr.get_node()->next;
                    itr.get_node()->prev->next = itr.get_node()->next;
                    itr.get_node()->next->prev = itr.get_node()->prev;
                    itr.get_node()->prev = position.get_node()->prev;
                    itr.get_node()->next = position.get_node();
                    position.get_node()->prev->next = itr.get_node();
                    position.get_node()->prev = itr.get_node();
                    _size++;
                    x._size--;
                    itr = next;
                }
            }
            void splice (iterator position, list& x, iterator i)
            {

                i.get_node()->prev->next = i.get_node()->next;
                i.get_node()->next->prev = i.get_node()->prev;
                i.get_node()->prev = position.get_node()->prev;
                i.get_node()->next = position.get_node();
                position.get_node()->prev->next = i.get_node();
                position.get_node()->prev = i.get_node();
                _size++;
                x._size--;
            }
            void splice (iterator position, list& x, iterator first, iterator last)
            {
                while (first != last)
                {
                    splice(position, x, first);
                    first++;
                }
            }
            void remove (const value_type& val)
            {
                iterator itr = begin();
                iterator ite = end();
                while (itr != ite)
                {
                    if (*itr == val)
                        erase(itr);
                    itr++;
                }
            }
            template <class Predicate>
            void remove_if (Predicate pred)
            {
                iterator itr = begin();
                iterator ite = end();
                while (itr != ite)
                {
                    if (pred(*itr))
                        erase(itr);
                    itr++;
                }
            }
            void unique()
            {
                iterator itr = begin();
                iterator ite = end();
                while (itr != ite)
                {
                    if (*itr == itr.get_node()->prev->data)
                        erase(itr);
                    itr++;
                }
            }
            template <class BinaryPredicate>
            void unique (BinaryPredicate binary_pred)
            {
                iterator itr = begin();
                iterator ite = end();
                while (itr != ite)
                {
                    if (binary_pred(*itr, itr.get_node()->prev->data))
                        erase(itr);
                    itr++;
                }
            }
            void merge (list& x) {
                if (&x == this)
                    return;
                iterator itr = begin();
                iterator ite = end();
                iterator itrX = x.begin();
                iterator iteX = x.end();
                for (; itrX != iteX && itr != ite;) {
                    for (; *itrX > *itr && itr != ite; itr++);
                    splice(itr, x, itrX++);
                }
                while (!x.empty())
                {
                    splice(ite, x, itrX++);
                }
            }
            template <class Compare>
            void merge (list& x, Compare comp)
            {
                if (&x == this)
                    return;
                iterator itr = begin();
                iterator ite = end();
                iterator itrX = x.begin();
                iterator iteX = x.end();
                for (; itrX != iteX && itr != ite;) {
                    for (; comp(*itr, *itrX) && itr != ite; itr++);
                    splice(itr, x, itrX++);
                }
                while (!x.empty())
                {
                    splice(ite, x, itrX++);
                }
            }
            void sort()
            {
			    if (_size > 1) {
                    iterator itr = begin();
                    iterator ite = end();
                    iterator itrN = begin();

                    while (itr != ite)
                    {
                        itrN++;
                        while (itrN != ite)
                        {
                            if (*itr > *itrN)
                            {
                                splice(itr, *this, itrN);
                                itr = begin();
                                itrN = begin();
                            }
                            itrN++;
                        }
                        itr++;
                        itrN = itr;
                    }
                }
            }
            template <class Compare>
            void sort (Compare comp)
            {
			    if (_size > 1)
                {
                    iterator itr = begin();
                    iterator ite = end();
                    iterator itrN = begin();
                    value_type tmp;

                    while (itr != ite)
                    {
                        itrN++;
                        while (itrN != ite)
                        {
                            if (comp(*itrN, *itr))
                            {
                                splice(itr, *this, itrN);
                            }
                            itrN++;
                        }
                        itr++;
                        itrN = itr;
                    }
                }
            }
            void reverse()
            {
                iterator itr = ++begin();
                iterator ite = end();

                while (itr != ite)
                {
                    splice(begin(), *this, itr++);
                }
            }
	};
    template <class value_type, class allocator_type>
    bool operator== (const list<value_type,allocator_type>& lhs, const list<value_type,allocator_type>& rhs)
    {
        if (lhs.size() != rhs.size())
            return (false);
        typename ft::list<value_type>::iterator lhs_itr = lhs.begin();
        typename ft::list<value_type>::iterator rhs_itr = rhs.begin();
        while (lhs_itr != lhs.end() && rhs_itr != rhs.end())
        {
            if (*lhs_itr != *rhs_itr)
                return (false);
            lhs_itr++;
            rhs_itr++;
        }
        return (true);
    }
    template <class value_type, class allocator_type>
    bool operator!= (const list<value_type,allocator_type>& lhs, const list<value_type,allocator_type>& rhs)
    {
        return (!(lhs == rhs));
    }
    template <class value_type, class allocator_type>
    bool operator< (const list<value_type,allocator_type>& lhs, const list<value_type,allocator_type>& rhs)
    {
        typename ft::list<value_type>::iterator lhs_itr = lhs.begin();
        typename ft::list<value_type>::iterator rhs_itr = rhs.begin();
        size_t sz;
        if (lhs.size() > rhs.size())
            sz = rhs.size();
        else
            sz = lhs.size();
        for (size_t i = 0; i < sz; ++i) {
            if (*lhs_itr != *rhs_itr)
                return (*lhs_itr < *rhs_itr);
            lhs_itr++;
            rhs_itr++;
        }
        return lhs.size() < rhs.size();
    }
    template <class value_type, class allocator_type>
    bool operator<= (const list<value_type,allocator_type>& lhs, const list<value_type,allocator_type>& rhs)
    {
        return (lhs < rhs || lhs == rhs);
    }
    template <class value_type, class allocator_type>
    bool operator>= (const list<value_type,allocator_type>& lhs, const list<value_type,allocator_type>& rhs)
    {
        return (!(lhs < rhs) || lhs == rhs);
    }
    template <class value_type, class allocator_type>
    bool operator> (const list<value_type,allocator_type>& lhs, const list<value_type,allocator_type>& rhs)
    {
        return (!(lhs < rhs));
    }
}
