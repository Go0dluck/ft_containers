	#pragma once
	#include <memory>
	#include <limits>
	#include <functional>
	#include "iterators/iterator_map.hpp"
	#include "iterators/reverse_iterator_map.hpp"
	namespace ft
	{
	template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<std::pair<const Key,T> > >
	class map
	{
	public:
		typedef             Key key_type;
		typedef             T mapped_type;
		typedef             std::pair<const key_type, mapped_type> value_type;
		typedef             NodeMap<key_type, mapped_type> nodeMap;
		typedef             Compare key_compare;
		typedef             Alloc allocator_type;
		typedef				T &reference;
		typedef const		T &const_reference;
		typedef				T *pointer;
		typedef const		T *const_pointer;
		typedef				ptrdiff_t difference_type;
		typedef				size_t size_type;
		typedef				iterator_map<key_type, mapped_type> iterator;
		typedef const		iterator_map<key_type, mapped_type> const_iterator;
		typedef				reverse_iterator_map<key_type, mapped_type> reverse_iterator;
		typedef const		reverse_iterator_map<key_type, mapped_type> const_reverse_iterator;
		typedef typename    Alloc::template rebind<nodeMap>::other allocator_rebind;
		class value_compare
		{
			friend class map;
		protected:
			Compare comp;
			value_compare (Compare c) : comp(c) {};
		public:
			typedef bool result_type;
			typedef value_type first_argument_type;
			typedef value_type second_argument_type;
			bool operator() (const value_type& x, const value_type& y) const
			{
				return comp(x.first, y.first);
			};
		};
	private:
		key_compare _comp;
		allocator_rebind _alloc;
		size_type _size;
		nodeMap *_root;
		nodeMap *_end;
		void addNode(const value_type& val)
		{
			if (val.first > _root->data.first && _root->end != true && _root->right != nullptr)
			{
				_root = _root->right;
				addNode(val);
			}
			if (val.first < _root->data.first && _root->left != nullptr)
			{
				_root = _root->left;
				addNode(val);
			}
		}
	public:
		explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _comp(comp), _alloc(alloc), _size(0)
		{
			_root = nullptr;
			_end = _alloc.allocate(1);
			_alloc.construct(_end, nodeMap());
			_end->left = nullptr;
			_end->right = nullptr;
			_end->parent = _root;
			_end->end = true;
			_end->data = std::make_pair(key_type(), mapped_type());
		}
		template <class InputIterator>
		map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _comp(comp), _alloc(alloc), _size(0)
		{
			_root = nullptr;
			_end = _alloc.allocate(1);
			_alloc.construct(_end, nodeMap());
			_end->left = nullptr;
			_end->right = nullptr;
			_end->parent = _root;
			_end->end = true;
			_end->data = std::make_pair(key_type(), mapped_type());
			insert(first, last);
		}
		map (const map& x)
		{
			_root = nullptr;
			_end = _alloc.allocate(1);
			_alloc.construct(_end, nodeMap());
			_end->left = nullptr;
			_end->right = nullptr;
			_end->parent = _root;
			_end->end = true;
			_end->data = std::make_pair(key_type(), mapped_type());
			*this = x;
		}
		map &operator=(const map &oper)
		{
			if (this == &oper)
				return *this;
			clear();
			insert(oper.begin(), oper.end());
			return *this;
		}
		~map()
		{
			clear();
			_alloc.destroy(_root);
			_alloc.destroy(_end);
			_alloc.deallocate(_root, 1);
			_alloc.deallocate(_end, 1);
		}
		//////////////////////ITERATORS///////////////////////
		iterator begin()
		{
			nodeMap *tmp = _root;
			if (_root == nullptr)
				return (iterator(tmp));
			while (tmp->left != nullptr)
				tmp = tmp->left;
			return (iterator(tmp));
		}
		const_iterator begin() const
		{
			nodeMap *tmp = _root;
			if (_root == nullptr)
				return (const_iterator(tmp));
			while (tmp->left != nullptr)
				tmp = tmp->left;
			return (const_iterator(tmp));
		}
		iterator end()
		{
			nodeMap *tmp = _root;
			if (_root == nullptr)
				return (iterator(tmp));
			while (tmp->end != true)
				tmp = tmp->right;
			return (iterator(tmp->right));
		}
		const_iterator end() const
		{
			nodeMap *tmp = _root;
			if (_root == nullptr)
				return (const_iterator(_end));
			while (tmp->end != true)
				tmp = tmp->right;
			return (const_iterator(tmp->right));
		}
		reverse_iterator rbegin()
		{
			nodeMap *tmp = _root;
			if (_root == nullptr)
				return (reverse_iterator(tmp));
			while (tmp->right != _end)
				tmp = tmp->right;
			return (reverse_iterator(tmp));
		}
		const_reverse_iterator rbegin() const
		{
			nodeMap *tmp = _root;
			if (_root == nullptr)
				return (const_reverse_iterator(tmp));
			while (tmp->left != nullptr)
				tmp = tmp->left;
			return (const_reverse_iterator(tmp));
		}
		reverse_iterator rend()
		{
			nodeMap *tmp = _root;
			if (_root == nullptr)
				return (reverse_iterator (_end));
			while (tmp->end != true)
				tmp = tmp->right;
			return (reverse_iterator (tmp->right));
		}
		const_reverse_iterator rend() const
		{
			nodeMap *tmp = _root;
			if (_root == nullptr)
				return (const_reverse_iterator (_end));
			while (tmp->end != true)
				tmp = tmp->right;
			return (const_reverse_iterator (tmp->right));
		}
		//////////////////////////Capacity//////////////////////////////
		bool empty() const
		{
			return (_size == 0);
		}
		size_type max_size() const
		{
			return (_alloc.max_size());
		}
		size_type size() const
		{
			return _size;
		}
		//////////////////////////Element access////////////////////////
		mapped_type& operator[] (const key_type& k)
		{
			iterator itr = find(k);
			if (itr != end())
			{
				return itr.getNode()->data.second;
			}
			return (insert(std::make_pair(k, mapped_type())).first->second);
		}
		//////////////////////////Modifiers/////////////////////////////
		std::pair<iterator,bool> insert (const value_type& val)
		{
			iterator itr = find(val.first);
			if (itr != end())
				return std::make_pair(itr, false);
			nodeMap *_node = _alloc.allocate(1);
			_alloc.construct(_node, nodeMap());
			if (_root == nullptr){
				_node->data = val;
				_node->parent = _node;
				_node->left = nullptr;
				_node->right = _end;
				_node->end = true;
				_end->parent = _node;
				_root = _node;
				_size++;
				return std::make_pair(iterator(_node), true);
			}
			nodeMap *tmp = _root;
			addNode(val);
			_node->data = val;
			_node->parent = _root;
			_node->left = nullptr;
			_node->right = nullptr;
			if (_root->end == true && _size >= 1 && val.first > _root->data.first) {
				_node->end = true;
				_root->end = false;
				_node->right = _end;
				_end->parent = _node;
			}
			else
				_node->end = false;
			if (val.first > _root->data.first)
				_root->right = _node;
			else
				_root->left = _node;
			_size++;
			_root = tmp;
			return std::make_pair(iterator(_node), true);
		}
		iterator insert (iterator position, const value_type& val)
		{
			(void)position;
			return (insert(val).first);
		}
		template <class InputIterator>
		void insert (InputIterator first, InputIterator last)
		{
			while (first != last)
			{
				insert(*first);
				first++;
			}
		}
		void erase (iterator position)
		{
			if (_size > 0)
			{
				nodeMap *del = position.getNode();
				if (position.getNode() == _root){
					if (position.getNode()->left != nullptr && position.getNode()->right != _end){
						iterator next = position.getNode()->right;
						while (next.getNode()->left != nullptr)
							next = next.getNode()->left;
						next.getNode()->left = position.getNode()->left;
						position.getNode()->left->parent = next.getNode();
						_root = position.getNode()->right;
					}
					else if (position.getNode()->left == nullptr && position.getNode()->right == _end){
						_root = nullptr;
						_end->parent = _root;
						_end->end = true;
					}
					else{
						position.getNode()->right->parent = position.getNode()->right;
						_root = position.getNode()->right;
					}
				}
				else if (position.getNode()->left == nullptr && position.getNode()->right == nullptr){
					del = del->parent;
					if (del->left == position.getNode())
						del->left = nullptr;
					else
						del->right = nullptr;
				}
				else if (position.getNode()->right != nullptr && position.getNode()->left == nullptr){
					if (position.getNode()->end == true){
						iterator next = position;
						--next;
						next.getNode()->right = _end;
						next.getNode()->end = true;
						_end->parent = next.getNode();
					}
					else{
						position.getNode()->right->parent = position.getNode()->parent;
						if (position.getNode()->parent->right == position.getNode())
							position.getNode()->parent->right = position.getNode()->right;
						else
							position.getNode()->parent->left = position.getNode()->right;
					}
				}
				else if (position.getNode()->right == nullptr && position.getNode()->left != nullptr){
					position.getNode()->left->parent = position.getNode()->parent;
					if (position.getNode()->parent->right == position.getNode())
						position.getNode()->parent->right = position.getNode()->left;
					else
						position.getNode()->parent->left = position.getNode()->left;
				}
				else{
					if (position.getNode()->end == true){
						iterator next = position;
						--next;
						next.getNode()->right = _end;
						next.getNode()->end = true;
						_end->parent = next.getNode();
						position.getNode()->left->parent = position.getNode()->parent;
						position.getNode()->parent->right = position.getNode()->left;
					}
					else{
						position.getNode()->left->parent = position.getNode()->parent;
						position.getNode()->parent->left = position.getNode()->left;
						iterator next = position.getNode()->left;
						while (next.getNode()->right != NULL)
							next = next.getNode()->right;
						position.getNode()->right->parent = next.getNode();
						next.getNode()->right = position.getNode()->right;
					}
				}
				_alloc.destroy(position.getNode());
				_alloc.deallocate(position.getNode(), 1);
				_size--;
				return;
			}
		}
		size_type erase (const key_type& k)
		{
			iterator tmp = find(k);
			if (tmp == end())
				return 0;
			erase(tmp);
			return 1;
		}
		void erase (iterator first, iterator last)
		{
			while (first != last)
			{
				erase(first);
				first++;
			}
		}
		void swap (map& x)
		{
			map tmp = x;
			x.clear();
			x.insert(begin(), end());
			clear();
			insert(tmp.begin(), tmp.end());
		}
		void clear()
		{
			erase(begin(), end());
		}
		////////////////////////Observers////////////////////////
		key_compare key_comp() const
		{
			return (_comp);
		}
		value_compare value_comp() const
		{
			return value_compare(_comp);
		}
		////////////////////////Operations///////////////////////
		iterator find (const key_type& k)
		{
			iterator itr = begin();
			iterator ite = end();
			if (_root == nullptr)
				return (ite);
			while (itr != ite)
			{
				if (itr.getNode()->data.first == k)
					return itr;
				itr++;
			}
			return itr;
		}
		const_iterator find (const key_type& k) const
		{
			const_iterator itr = begin();
			const_iterator ite = end();
			if (_root == nullptr)
				return (ite);
			while (itr != ite)
			{
				if (itr.getNode()->data.first == k)
					return itr;
				itr++;
			}
			return itr;
		}
		size_type count (const key_type& k)
		{
			if (find(k) != end())
				return 1;
			return 0;
		}
		iterator lower_bound (const key_type& k)
		{
			iterator itr = begin();
			iterator ite = end();
			while (itr != ite)
			{
				if (_comp(itr.getNode()->data.first, k) == false)
					return (itr);
				itr++;
			}
			return (ite);
		}
		const_iterator lower_bound (const key_type& k) const
		{
			const_iterator itr = begin();
			const_iterator ite = end();
			while (itr != ite)
			{
				if (_comp(itr.getNode()->data.first, k) == false)
					return (itr);
				itr++;
			}
			return (ite);
		}
		iterator upper_bound (const key_type& k)
		{
			iterator itr = begin();
			iterator ite = end();
			while (itr != ite)
			{
				if (_comp(itr.getNode()->data.first, k) <= 0)
					return (++itr);
				itr++;
			}
			return (ite);
		}
		const_iterator upper_bound (const key_type& k) const
		{
			const_iterator itr = begin();
			const_iterator ite = end();
			while (itr != ite)
			{
				if (_comp(itr.getNode()->data.first, k) <= 0)
					return (++itr);
				itr++;
			}
			return (ite);
		}
		std::pair<iterator,iterator> equal_range (const key_type& k)
		{
			return (std::pair<iterator,iterator>(lower_bound(k), upper_bound(k)));
		}
		std::pair<const_iterator,const_iterator> equal_range (const key_type& k) const
		{
			return (std::pair<const_iterator,const_iterator>(lower_bound(k), upper_bound(k)));
		}

	};
	}
