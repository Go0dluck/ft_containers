#pragma once

template <typename T>
class random_iterator
{
	public:
		typedef T value_type;
		typedef	ptrdiff_t difference_type;
		typedef T* pointer;
		typedef T& reference;
	private:
		value_type *_pointer;
	public:
		random_iterator(value_type *pointer = 0) : _pointer(pointer) {};
		~random_iterator() {};
		random_iterator(const random_iterator &cpy) : _pointer(cpy._pointer) {};
		random_iterator &operator=(const random_iterator &oper)
		{
			if (this == &oper)
				return (*this);
			_pointer = oper._pointer;
			return (*this);
		};
		bool operator==(const random_iterator &itr) const
		{
			return (_pointer == itr._pointer);
		}
		bool operator!=(const random_iterator &itr) const
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
		random_iterator &operator++()
		{
			_pointer++;
			return (*this);
		}
		random_iterator operator++(int)
		{
			random_iterator tmp = *this;
			++(_pointer);
			return (tmp);
		}
		random_iterator &operator--()
		{
			_pointer--;
			return (*this);
		}
		random_iterator operator--(int)
		{
			random_iterator tmp = *this;
			--(_pointer);
			return (tmp);
		}
		random_iterator operator+(const difference_type &x) const
		{
			return (_pointer + x);
		}
		random_iterator operator-(const difference_type &x) const
		{
			return (_pointer - x);
		}
		bool operator<(const random_iterator &itr) const
		{
			return (_pointer < itr._pointer);
		}
		bool operator>(const random_iterator &itr) const
		{
			return (_pointer > itr._pointer);
		}
		bool operator>=(const random_iterator &itr) const
		{
			return (_pointer >= itr._pointer);
		}
		bool operator<=(const random_iterator &itr) const
		{
			return (_pointer <= itr._pointer);
		}
		random_iterator operator+=(const difference_type &x) const
		{
			return(_pointer += x);
		}
		random_iterator operator-=(const difference_type &x) const
		{
			return(_pointer -= x);
		}
		T &operator[](const difference_type &x) const
		{
			return (_pointer + x);
		}
};
