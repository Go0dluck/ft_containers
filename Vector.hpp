#pragma once
#include <memory>
#include "iterators/random_iterator.hpp"
#include "iterators/reverse_random_iterator.hpp"
#include <iostream>
#include "iterators/Utils.hpp"
#include "iterators/enableif.hpp"

namespace ft
{
	template <typename T, typename Alloc = std::allocator<T> >
	class vector
	{
		public:
			typedef				T value_type; // тип вектора
			typedef				Alloc allocator_type; // аллокатор
			typedef				value_type &reference;
			typedef				value_type const &const_reference;
			typedef				value_type *pointer;
			typedef				value_type const *const_pointer;
			typedef				ptrdiff_t difference_type; // размер для массива
			typedef				size_t size_type; // размер
			typedef				random_iterator<value_type> iterator;
			typedef	const		random_iterator<value_type> const_iterator;
			typedef				reverse_random_iterator<value_type> reverse_iterator;
			typedef	const		reverse_random_iterator<value_type> const_reverse_iterator;
		private:
			size_type			_size; // кол-во элементов
			size_type			_capacity; // максимальное кол-во
			allocator_type		_alloc;
			pointer				_arr;
		public:
			explicit vector (const allocator_type& alloc = allocator_type()) : // стандартный конструктор
			_size(0), _capacity(0), _alloc(alloc), _arr(NULL){};
			explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : _size(n), _capacity(n), _alloc(alloc) // конструктор с размером забитым нулями или заданным типом
			{
				_arr = _alloc.allocate(n);
				for (size_type i = 0; i < _size; i++)
				{
					_alloc.construct(_arr + i, val);
				}
			};
			template <class InputIterator>
			vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(), typename ft::enable_if<!ft::integral<InputIterator>::value >::type* = 0) : _size(0), _capacity(0), _alloc(alloc) // конструктор с рэнжем итераторов
			{
				_size = ft::distance(first, last);
				_capacity = _size;
				_arr = _alloc.allocate(_size);
				for (size_type i = 0; i < _size; i++)
				{
					_alloc.construct(_arr + i, *first);
					first++;
				}
			};
			vector (const vector& x) : _size(x._size), _capacity(x._capacity), _alloc(x._alloc) // конструктор копирования
			{
				_arr = _alloc.allocate(x._size);
				for (size_type i = 0; i < _size; i++)
				{
					_alloc.construct(_arr + i, *(x._arr + i));
				}
			}
			vector &operator=(const vector& x) // конструктор присваивания
			{
				if (this == &x)
					return (*this);
				_size = x._size;
				_capacity = x._capacity;
				_alloc = x._alloc;
				_alloc.deallocate(_arr, _capacity);
				_arr = _alloc.allocate(x._size);
				for (size_type i = 0; i < _size; i++)
				{
					_alloc.construct(_arr + i, *(x._arr + i));
				}
				return (*this);
			}
			~vector() // деструктор
			{
				_alloc.destroy(_arr);
				_alloc.deallocate(_arr, _capacity);
			}
			/////////////////////////////Итераторы////////////////////////
			iterator begin()
			{
				return (iterator(_arr));
			}
			const_iterator begin() const
			{
				return (const_iterator(_arr));
			}
			iterator end()
			{
				return (iterator(&_arr[_size]));
			}
			const_iterator end() const
			{
				return (const_iterator(&_arr[_size]));
			}
			reverse_iterator rbegin()
			{
				return (reverse_iterator(&_arr[_size - 1]));
			}
			const_reverse_iterator rbegin() const
			{
				return (const_reverse_iterator(&_arr[_size - 1]));
			}
			reverse_iterator rend()
			{
				return (reverse_iterator(_arr - 1));
			}
			const_reverse_iterator rend() const
			{
				return (const_reverse_iterator(_arr - 1));
			}
			///////////capacity//////////////////////////
			size_type size() const // возвращает кол-во элементов
			{
				return (_size);
			}
			bool empty() const // пуст ли вектор
			{
				return (_size == 0);
			}
			size_type max_size() const // максимальный размер вектора
			{
				return (_alloc.max_size());
			}
			void resize (size_type n, value_type val = value_type()) // увеличение/уменьшение вектора
			{
				if (n < _size)
				{
					size_type tmp = _size - n;
					while(tmp--)
						pop_back();
				}
				else if (n > _size)
				{
					size_type tmp = n - _size;
					while(tmp--)
						push_back(val);
				}
			}
			void reserve(size_type size) // резервирование памяти
			{
				if (size > _capacity)
				{
					pointer tmp = _alloc.allocate(size);
					for (size_type i = 0; i < _size; i++)
					{
						_alloc.construct(tmp + i, *(_arr + i));
					}
					_alloc.deallocate(_arr, _capacity);
					_arr = tmp;
					_capacity = size;
				}
			}
			size_type capacity() const // возвращает кол-во макс текущих элементов
			{
				return (_capacity);
			}
			////////////Element access//////////////
			reference operator[] (size_type n) // доступ к элементу по индексу
			{
				return (_arr[n]);
			}
			const_reference operator[] (size_type n) const
			{
				return (_arr[n]);
			}
			reference at (size_type n) // доступ к элементу по индексу с проверкой на размер вектора
			{
				if (n >= _size)
				{
					throw std::out_of_range("out_of_range");
				}
				return (_arr[n]);
			}
			const_reference at (size_type n) const
			{
				if (n >= _size)
				{
					throw std::out_of_range("out_of_range");
				}
				return (_arr[n]);
			}
			reference front() // возвращает первый элемент массива
			{
				return (*_arr);
			}
			const_reference front() const
			{
				return (*_arr);
			}
			reference back() // возвращает последний элемент массива
			{
				return (_arr[_size - 1]);
			}
			const_reference back() const
			{
				return (_arr[_size - 1]);
			}
			////////////////////Modifiers/////////////////////
			 template <class InputIterator>
			 void assign (InputIterator first, InputIterator last, typename ft::enable_if<!ft::integral<InputIterator>::value >::type* = 0)
			 {
			 	_size = ft::distance(first, last);
			 	if (_size > _capacity)
			 	{
			 		_alloc.destroy(_arr);
			 		_alloc.deallocate(_arr, _capacity);
			 		_arr = _alloc.allocate(_size);
			 		for (size_type i = 0; i < _size; i++)
			 		{
			 			_alloc.construct(_arr + i, first);
			 			first++;
			 		}
			 		_capacity = _size;
			 	}
			 	else
			 	{
			 		_alloc.destroy(_arr);
			 		for (size_type i = 0; i < _size; i++)
			 		{
			 			_alloc.construct(_arr + i, first);
			 			first++;
			 		}
			 	}
			 }
			void assign (size_type n, const value_type& val) // перезаписывает вектор значением val
			{
				if (n > _capacity)
				{
					_alloc.destroy(_arr);
					_alloc.deallocate(_arr, _capacity);
					_arr = _alloc.allocate(n);
					for (size_type i = 0; i < n; i++)
					{
						_alloc.construct(_arr + i, val);
					}
					_size = n;
					_capacity = n;
				}
				else
				{
					_alloc.destroy(_arr);
					for (size_type i = 0; i <= n; i++)
					{
						_alloc.construct(_arr + i, val);
					}
					_size = n;
				}
			}
			void clear() // очишает вектор и размер на 0 ставит
			{
				_alloc.destroy(_arr);
				_size = 0;
			}
			void push_back (const value_type& val) // добавляем в конец
			{
				if (_size == _capacity)
				{
					if (_size == 0)
						reserve(1);
					else
						reserve(_capacity * 2);
				}
				_arr[_size++] = val;
			}
			void pop_back() // удаляем с конца
			{
				_alloc.destroy(&back());
				_size--;
			}
			iterator insert (iterator position, const value_type& val) // добавляем элемент в позицию
			{
				vector tmp(position, end());
				size_type n = ft::distance(position, end());
				_size -= n;
				push_back(val);
				iterator itr = tmp.begin();
				iterator ite = tmp.end();
				while (itr != ite)
				{
					push_back(*itr);
					itr++;
				}
				return (iterator(&_arr[n]));
			}
			void insert (iterator position, size_type n, const value_type& val) // добавляем кучу элементов в позицию
			{
				vector tmp(position, end());
				size_type sz = ft::distance(position, end());
				_size -= sz;
				while (n--)
					push_back(val);
				iterator itr = tmp.begin();
				iterator ite = tmp.end();
				while (itr != ite)
				{
					push_back(*itr);
					itr++;
				}
			}
			template <class InputIterator>
			void insert (iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!ft::integral<InputIterator>::value >::type* = 0) // добавляем кучу элементов в позицию через итераторы
			{
				vector tmp(position, end());
				size_type sz = ft::distance(position, end());
				_size -= sz;
				while (first != last)
				{
					push_back(*first);
					first++;
				}
				iterator itr = tmp.begin();
				iterator ite = tmp.end();
				while (itr != ite)
				{
					push_back(*itr);
					itr++;
				}
			}
			iterator erase (iterator position) // удаление конкретного элемента
			{
				vector tmp(position + 1, end());
				size_type n = ft::distance(position + 1, end());
				_size -= n;
				pop_back();
				iterator itr = tmp.begin();
				iterator ite = tmp.end();
				while (itr != ite)
				{
					push_back(*itr);
					itr++;
				}
				return (iterator(&_arr[n]));
			}
			iterator erase (iterator first, iterator last) // удаление рэнжа элементов
			{
				vector tmp(last, end());
				size_type n = ft::distance(last, end());
				size_type sz = ft::distance(first, last);
				_size -= n;
				while (sz)
				{
					pop_back();
					sz--;
				}
				iterator itr = tmp.begin();
				iterator ite = tmp.end();
				while (itr != ite)
				{
					push_back(*itr);
					itr++;
				}
				return (iterator(&_arr[n]));
			}
			void swap (vector& x) // замена одного вектора другим
			{
				vector tmp(x.begin(), x.end());
				x.clear();
				x.insert(x.begin(), begin(), end());
				clear();
				insert(begin(), tmp.begin(), tmp.end());
			}
	};
	template <class value_type, class allocator_type>
	bool operator==(const vector<value_type,allocator_type>& lhs, const vector<value_type,allocator_type>& rhs)
	{
		if (lhs.size() != rhs.size())
			return (false);
		typename ft::vector<value_type>::iterator itr_lhs = lhs.begin();
		typename ft::vector<value_type>::iterator itr_rhs = rhs.begin();
		while (itr_lhs != lhs.end() && itr_rhs != rhs.end())
		{
			if (*itr_lhs != *itr_rhs)
				return (false);
			itr_lhs++;
			itr_rhs++;
		}
		return (true);
	}
	template <class value_type, class allocator_type>
	bool operator!=(const vector<value_type,allocator_type>& lhs, const vector<value_type,allocator_type>& rhs)
	{
		return (!(lhs == rhs));
	}
	template <class value_type, class allocator_type>
	bool operator<(const vector<value_type,allocator_type>& lhs, const vector<value_type,allocator_type>& rhs)
	{
		size_t sz;
		if (lhs.size() > rhs.size())
			sz = rhs.size();
		else
			sz = lhs.size();
		for (size_t i = 0; i < sz; i++)
			if (lhs[i] != rhs[i])
				return (lhs[i] < rhs[i]);
		return lhs.size() < rhs.size();
	}
	template <class value_type, class allocator_type>
	bool operator<=(const vector<value_type,allocator_type>& lhs, const vector<value_type,allocator_type>& rhs)
	{
		return (lhs < rhs || lhs == rhs);
	}
	template <class value_type, class allocator_type>
	bool operator>(const vector<value_type,allocator_type>& lhs, const vector<value_type,allocator_type>& rhs)
	{
		return (!(lhs < rhs));
	}
	template <class value_type, class allocator_type>
	bool operator>=(const vector<value_type,allocator_type>& lhs, const vector<value_type,allocator_type>& rhs)
	{
		return (!(lhs < rhs || lhs == rhs));
	}
}
