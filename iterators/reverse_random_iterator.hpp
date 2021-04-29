#pragma once

template <typename T>
class reverse_random_iterator
{
	public:
		typedef T value_type;
		typedef	ptrdiff_t difference_type;
		typedef T* pointer;
		typedef T& reference;
	private:
		value_type *_pointer;
	public:
		reverse_random_iterator(value_type *pointer = 0) : _pointer(pointer) {};
		~reverse_random_iterator() {};
		reverse_random_iterator(const reverse_random_iterator &cpy) : _pointer(cpy._pointer) {};
		reverse_random_iterator &operator=(const reverse_random_iterator &oper)
		{
			if (this == &oper)
				return (*this);
			_pointer = oper._pointer;
			return (*this);
		};
		bool operator==(const reverse_random_iterator &itr) const
		{
			return (_pointer == itr._pointer);
		}
		bool operator!=(const reverse_random_iterator &itr) const
		{
			return (_pointer != itr._pointer);
		}
		reference operator*()
		{
			return (*_pointer);
		}
		pointer operator->()
		{
			return (_pointer);
		}
		reverse_random_iterator &operator++()
		{
			_pointer--;
			return (*this);
		}
		reverse_random_iterator operator++(int)
		{
			reverse_random_iterator tmp = *this;
			++(_pointer);
			return (tmp);
		}
		reverse_random_iterator &operator--()
		{
			_pointer++;
			return (*this);
		}
		reverse_random_iterator operator--(int)
		{
			reverse_random_iterator tmp = *this;
			--(_pointer);
			return (tmp);
		}
		reverse_random_iterator operator+(const difference_type &x) const
		{
			return (_pointer - x);
		}
		reverse_random_iterator operator-(const difference_type &x) const
		{
			return (_pointer + x);
		}
		bool operator<(const reverse_random_iterator &itr) const
		{
			return (_pointer > itr._pointer);
		}
		bool operator>(const reverse_random_iterator &itr) const
		{
			return (_pointer < itr._pointer);
		}
		bool operator>=(const reverse_random_iterator &itr) const
		{
			return (_pointer <= itr._pointer);
		}
		bool operator<=(const reverse_random_iterator &itr) const
		{
			return (_pointer >= itr._pointer);
		}
		reverse_random_iterator operator+=(const difference_type &x) const
		{
			return(_pointer -= x);
		}
		reverse_random_iterator operator-=(const difference_type &x) const
		{
			return(_pointer += x);
		}
		T &operator[](const difference_type &x) const
		{
			return (_pointer - x);
		}
};
