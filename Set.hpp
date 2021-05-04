#pragma once
#include <memory>
#include <limits>
#include <functional>
#include "iterators/Utils.hpp"
#include "iterators/iterator_set.hpp"
#include "iterators/reverse_iterator_set.hpp"

namespace ft
{
	template < class T, class Compare = std::less<T>, class Alloc = std::allocator<T> >
	class set
	{
	public:
		typedef				T key_type;
		typedef				T value_type;
		typedef				std::less<key_type> key_compare;
		typedef				std::less<value_type> value_compare;
		typedef				Alloc allocator_type;
		typedef				T &reference;
		typedef const		T &const_reference;
		typedef				T *pointer;
		typedef const		T *const_pointer;
		typedef				ptrdiff_t difference_type;
		typedef				size_t size_type;
		typedef				ft::setnode<value_type> nodeSet;
		typedef				iterator_set<value_type> iterator;
        typedef const		iterator_set<value_type> const_iterator;
        typedef				reverse_iterator_set<value_type> reverse_iterator;
        typedef const		reverse_iterator_set<value_type> const_reverse_iterator;
		typedef typename	Alloc::template rebind<nodeSet>::other allocator_rebind;
	private:
		key_compare			_comp;
		allocator_rebind	_alloc;
		size_type			_size;
		nodeSet				*_root;
		nodeSet				*_end;
		int getHeight(nodeSet* p)
        {
            if (p == nullptr || p == _end)
                return 0;
            return p->height;
        }
        int bfactor(nodeSet* p)
        {
            return getHeight(p->right)-getHeight(p->left);
        }
        void fixheight(nodeSet* p)
        {
            int hl = getHeight(p->left);
            int hr = getHeight(p->right);
            p->height = (hl>hr?hl:hr)+1;
        }
        nodeSet* rotateright(nodeSet* p) // правый поворот вокруг p
        {
            nodeSet* q = p->left;
            p->left = q->right;
            q->right = p;
            q->parent = p->parent;
            p->parent = q;
            if (p->left != nullptr)
                p->left->parent = p;
            fixheight(p);
            fixheight(q);
            if (p == _root)
            {
                _root = q;
                _root->parent = nullptr;
            }
            return q;
        }
        nodeSet* rotateleft(nodeSet* q) // левый поворот вокруг q
        {
            nodeSet* p = q->right;
            q->right = p->left;
            p->left = q;
            p->parent = q->parent;
            q->parent = p;
            if (q->right != nullptr)
                q->right->parent = q;
            fixheight(q);
            fixheight(p);
            if (q == _root) {
                _root = p;
                _root->parent = nullptr;
            }
            return p;
        }
        nodeSet* balance(nodeSet *p)
        {
            fixheight(p);
            if (bfactor(p) == 2)
            {
                if (bfactor(p->right) < 0)
                    p->right = rotateright(p->right);
                return rotateleft(p);
            }
            if (bfactor(p) == -2)
            {
                if( bfactor(p->left) > 0  ) {
                    p->left = rotateleft(p->left);
                    p->left->parent = p;
                }
                return rotateright(p);
            }
            return (p);
        }
        nodeSet* addNode(nodeSet *cur, nodeSet *prev, nodeSet *node)
        {
            if (_size == 0)
            {
                _alloc.destroy(_root);
			    _alloc.deallocate(_root, 1);
                node->end = true;
                node->right = _end;
                _end->parent = node;
                _root = node;
                return (node);
            }
            if (cur == nullptr)
            {
                node->parent = prev;
                return node;
            }
            else if (cur == _end)
            {
                node->parent = prev;
                node->end = true;
                prev->end = false;
                node->right = _end;
                _end->parent = node;
                return (node);
            }
            if (cur->data > node->data)
                cur->left = addNode(cur->left, cur, node);
            else if (cur->data < node->data)
                cur->right = addNode(cur->right, cur, node);
            return (balance(cur));
        }
        nodeSet* removemin(nodeSet* p) // удаление узла с минимальным ключом из дерева p
        {
            if( p->left==0 )
                return p->right;
            p->left = removemin(p->left);
            return balance(p);
        }
        nodeSet* findmin(nodeSet* p) // поиск узла с минимальным ключом в дереве p
        {
            return p->left?findmin(p->left):p;
        }
        nodeSet* findmax(nodeSet* p) // поиск узла с минимальным ключом в дереве p
        {
            return p->right?findmax(p->right):p;
        }
		nodeSet* delNode(nodeSet *cur, nodeSet *p)
		{
            if (_size == 1){
                _alloc.destroy(p);
                _alloc.deallocate(p, 1);

				_root = _alloc.allocate(1);
				_alloc.construct(_root, nodeSet(0));
				_root->right = _end;
				_root->end = true;
                _end->parent = _root;
                return _root;
            }
            if (p->data > cur->data)
                cur->right = delNode(cur->right, p);
            else if (p->data < cur->data)
                cur->left = delNode(cur->left, p);
            else{
                nodeSet *pl = p->left;
                nodeSet *pr = p->right;
                nodeSet *par = p->parent;
                _alloc.destroy(p);
                _alloc.deallocate(p, 1);
                if (!pr || pr == _end){
                    if (pl)
                        pl->parent = par;
                    if (!par)
                        _root = pl;
                    if (pr == _end){
                        if (pl){
                            nodeSet *max = findmax(pl);
                            max->right = _end;
                            max->end = true;
                            _end->parent = max;
                        }
                        else{
                            _end->parent = par;
                            par->end = true;
                            return _end;
                        }
                    }
                    return pl;
                }else{
                    nodeSet *min = findmin(pr);
                    min->right = removemin(pr);
                    min->left = pl;
                    if (min->left != nullptr)
                        min->left->parent = min;
                    if (min->right != nullptr)
                        min->right->parent = min;
                    if (!par){
						_root = min;
						min->parent = nullptr;
                    }
                    return balance(min);
                }
            }
            return balance(cur);
		}
	public:
		//////////////////////////////////////////Member functions/////////////////////////////////////
		explicit set (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _comp(comp), _alloc(alloc)
		{
			_size = 0;
			_root = _alloc.allocate(1);
			_alloc.construct(_root, nodeSet(0));
			_root->right = _end;
			_root->end = true;
			_end = _alloc.allocate(1);
			_alloc.construct(_end, nodeSet(0));
			_end->parent = _root;
			_end->height = 0;
		}
		template <class InputIterator>
		set (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _comp(comp), _alloc(alloc)
		{
			_root = _alloc.allocate(1);
			_alloc.construct(_root, nodeSet(0));
			_root->right = _end;
			_root->end = true;
			_end = _alloc.allocate(1);
			_alloc.construct(_end, nodeSet(0));
			_end->parent = _root;
			_end->height = 0;
			insert(first, last);
		}
		set (const set& x)
		{
			_root = nullptr;
			_end = _alloc.allocate(1);
			_alloc.construct(_end, nodeSet(0));
			_end->left = nullptr;
			_end->right = nullptr;
			_end->parent = _root;
			_end->end = true;
			_end->data = 0;
			*this = x;
		}
		~set()
		{
			clear();
			_alloc.destroy(_root);
			_alloc.deallocate(_root, 1);
			_alloc.destroy(_end);
			_alloc.deallocate(_end, 1);
		}
		set& operator= (const set& x)
		{
			if (this == &x)
				return *this;
			clear();
			insert(x.begin(), x.end());
			return *this;
		}
		//////////////////////////////////////////Iterators/////////////////////////////////////
        iterator begin()
        {
            nodeSet *tmp = _root;
            if (_size == 0)
                return (iterator(tmp));
            while (tmp->left != nullptr)
                tmp = tmp->left;
            return (iterator(tmp));
        }
		const_iterator begin() const
		{
			nodeSet *tmp = _root;
			if (_size == 0)
				return (const_iterator(tmp));
			while (tmp->left != nullptr)
				tmp = tmp->left;
			return (const_iterator(tmp));
		}
        iterator end()
        {
            nodeSet *tmp = _root;
            if (_size == 0)
                return (iterator(tmp));
            while (tmp->end != true)
                tmp = tmp->right;
            return (iterator(tmp->right));
        }
		const_iterator end() const
		{
			nodeSet *tmp = _root;
			if (_size == 0)
				return (const_iterator(tmp));
			while (tmp->end != true)
				tmp = tmp->right;
			return (const_iterator(tmp->right));
		}
		reverse_iterator rbegin()
		{
			nodeSet *tmp = _root;
			if (_root == nullptr)
				return (reverse_iterator(tmp));
			while (tmp->right != _end)
				tmp = tmp->right;
			return (reverse_iterator(tmp));
		}
		const_reverse_iterator rbegin() const
		{
			nodeSet *tmp = _root;
			if (_root == nullptr)
				return (const_reverse_iterator(tmp));
			while (tmp->left != nullptr)
				tmp = tmp->left;
			return (const_reverse_iterator(tmp));
		}
		reverse_iterator rend()
		{
			nodeSet *tmp = _root;
			if (_root == nullptr)
				return (reverse_iterator (_end));
			while (tmp->end != true)
				tmp = tmp->right;
			return (reverse_iterator (tmp->right));
		}
		const_reverse_iterator rend() const
		{
			nodeSet *tmp = _root;
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
		//////////////////////////Modifiers/////////////////////////////
		std::pair<iterator,bool> insert (const value_type& val)
		{
			iterator itr = find(val);
			if (itr != end())
				return std::make_pair(itr, false);
			nodeSet *tmp = _root;
            nodeSet *prev = _root;
            nodeSet *node = _alloc.allocate(1);
			_alloc.construct(node, nodeSet(val));
            addNode(tmp, prev, node);
            _size++;
            return std::make_pair(iterator(node), true);
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
        	if (_size > 0){
				nodeSet *tmp = _root;
				delNode(tmp, position.getNode());
				_size--;
        	}
        }
		size_type erase (const value_type& val)
		{
			iterator tmp = find(val);
			if (tmp == end())
				return 0;
			erase(tmp);
			return 1;
		}
        void erase (iterator first, iterator last)
        {
        	iterator tmp;
            while (first != last)
            {
            	tmp = first;
            	tmp++;
                erase(first);
                first = tmp;
            }
        }
		void swap (set& x)
		{
			set<value_type> tmp;
            tmp.insert(x.begin(), x.end());
            x.clear();
            x.insert(this->begin(), this->end());
            this->clear();
            this->insert(tmp.begin(), tmp.end());

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
		iterator find (const value_type& val) const
		{
			iterator itr = begin();
			iterator ite = end();
			if (_root == nullptr)
				return (ite);
			while (itr != ite)
			{
				if (itr.getNode()->data == val)
					return itr;
				itr++;
			}
			return itr;
		}
		size_type count (const value_type& val) const
		{
			if (find(val) != end())
				return 1;
			return 0;
		}
		iterator lower_bound (const value_type& val) const
		{
			iterator itr = begin();
			iterator ite = end();
			while (itr != ite)
			{
				if (_comp(itr.getNode()->data, val) == false)
					return (itr);
				itr++;
			}
			return (ite);
		}
		iterator upper_bound (const value_type& val) const
		{
			iterator itr = begin();
			iterator ite = end();
			while (itr != ite)
			{
				if (_comp(itr.getNode()->data, val) <= 0)
					return (++itr);
				itr++;
			}
			return (ite);
		}
		std::pair<iterator,iterator> equal_range (const value_type& val) const
		{
			return (std::pair<iterator,iterator>(lower_bound(val), upper_bound(val)));
		}
	};
}
