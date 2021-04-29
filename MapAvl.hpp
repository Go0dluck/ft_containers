#pragma once
#include <memory>
#include <limits>
#include <functional>
#include "iterators/iterator_mapavl.hpp"
#include "iterators/reverse_iterator_mapavl.hpp"
namespace ft
{
    template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<std::pair<const Key,T> > >
    class map
    {
    public:
        typedef             Key key_type;
        typedef             T mapped_type;
        typedef             std::pair<const key_type, mapped_type> value_type;
        typedef             ft::anode<key_type, mapped_type> nodeMap;
        typedef             Compare key_compare;
        typedef             Alloc allocator_type;
        typedef				T &reference;
        typedef const		T &const_reference;
        typedef				T *pointer;
        typedef const		T *const_pointer;
        typedef				ptrdiff_t difference_type;
        typedef				size_t size_type;
        typedef				iterator_mapavl<key_type, mapped_type> iterator;
        typedef const		iterator_mapavl<key_type, mapped_type> const_iterator;
        typedef				reverse_iterator_mapavl<key_type, mapped_type> reverse_iterator;
        typedef const		reverse_iterator_mapavl<key_type, mapped_type> const_reverse_iterator;
        typedef typename    Alloc::template rebind<nodeMap>::other allocator_rebind;
        class value_compare
        {
            friend class mapavl;
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
        int getHeight(nodeMap* p)
        {
            if (p == nullptr || p == _end)
                return 0;
            return p->height;
        }
        int bfactor(nodeMap* p)
        {
            return getHeight(p->right)-getHeight(p->left);
        }
        void fixheight(nodeMap* p)
        {
            int hl = getHeight(p->left);
            int hr = getHeight(p->right);
            p->height = (hl>hr?hl:hr)+1;
        }
        nodeMap* rotateright(nodeMap* p) // правый поворот вокруг p
        {
            nodeMap* q = p->left;
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
        nodeMap* rotateleft(nodeMap* q) // левый поворот вокруг q
        {
            nodeMap* p = q->right;
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
        nodeMap* balance(nodeMap *p)
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
        nodeMap* addNode(nodeMap *cur, nodeMap *prev, nodeMap *node)
        {
            if (_size == 0)
            {
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
            if (cur->data.first > node->data.first)
                cur->left = addNode(cur->left, cur, node);
            else if (cur->data.first < node->data.first)
                cur->right = addNode(cur->right, cur, node);
            return (balance(cur));
        }
        nodeMap* removemin(nodeMap* p) // удаление узла с минимальным ключом из дерева p
        {
            if( p->left==0 )
                return p->right;
            p->left = removemin(p->left);
            return balance(p);
        }
        nodeMap* findmin(nodeMap* p) // поиск узла с минимальным ключом в дереве p
        {
            return p->left?findmin(p->left):p;
        }
        nodeMap* findmax(nodeMap* p) // поиск узла с минимальным ключом в дереве p
        {
            return p->right?findmax(p->right):p;
        }
		nodeMap* delNode(nodeMap *cur, nodeMap *p)
		{
            if (_size == 1){
                _alloc.destroy(p);
                _alloc.deallocate(p, 1);
                _root->right = _end;
                _root->end = true;
                _end->parent = _root;
                return _root;
            }
            if (p->data.first > cur->data.first)
                cur->right = delNode(cur->right, p);
            else if (p->data.first < cur->data.first)
                cur->left = delNode(cur->left, p);
            else{
                nodeMap *pl = p->left;
                nodeMap *pr = p->right;
                nodeMap *par = p->parent;
                _alloc.destroy(p);
                _alloc.deallocate(p, 1);
                if (!pr || pr == _end){
                    if (pl)
                        pl->parent = par;
                    if (!par)
                        _root = pl;
                    if (pr == _end){
                        if (pl){
                            nodeMap *max = findmax(pl);
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
                    nodeMap *min = findmin(pr);
                    min->right = removemin(pr);
                    min->left = pl;
                    if (min->left != nullptr)
                        min->left->parent = min;
                    if (min->right != nullptr)
                        min->right->parent = min;
                    if (!par)
                        _root = min;
                    return balance(min);
                }
            }
            return balance(cur);
		}
//        nodeMap* delNode(nodeMap *cur, nodeMap *p)
//        {
//            if (p->data.first > cur->data.first)
//                cur->right = delNode(cur->right, p);
//            else if (p->data.first < cur->data.first)
//                cur->left = delNode(cur->left, p);
//            else{
//                nodeMap *pl = p->left;
//                nodeMap *pr = p->right;
//                nodeMap *par = p->parent;
//                bool isRoot = (p == _root);
//                _alloc.destroy(p);
//                _alloc.deallocate(p, 1);
//                if (pl != nullptr)
//                    pl->parent = par;
//                if (pr != nullptr)
//                    pr->parent = par;
//                if (!pr){
//                    if (pl != nullptr)
//                        pl->parent = par;
//                    return pl;
//                }
//                else if (pr == _end)
//                {
//                    if (pl != nullptr){
//                        nodeMap *max = findmax(pl);
//                        max->right = _end;
//                        max->end = true;
//                        _end->parent = max;
//                        pl->parent = par;
//                        return pl;
//                    }
//                    else{
//                        if (par != nullptr) {
//                            par->end = true;
//                            _end->parent = par;
//                            return _end;
//                        }
//                        else
//                        {
//                            _root = _alloc.allocate(1);
//                            _alloc.construct(_root, nodeMap(std::make_pair(0, 0)));
//                            _root->right = _end;
//                            _root->end = true;
//                            _end->parent = _root;
//                            return _root;
//                        }
//                    }
//                }
//                nodeMap *min = findmin(pr);
//                min->right = removemin(pr);
//                min->left = pl;
//                if (min->left != nullptr)
//                    min->left->parent = min;
//                if (min->right != nullptr)
//                    min->right->parent = min;
//                if (isRoot)
//                    _root = min;
//                return balance(min);
//            }
//            return balance(cur);
//        }
    public:
        explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _comp(comp), _alloc(alloc), _size(0)
        {
            _root = _alloc.allocate(1);
            _alloc.construct(_root, nodeMap(std::make_pair(0, 0)));
            _root->right = _end;
            _root->end = true;
            _end = _alloc.allocate(1);
            _alloc.construct(_end, nodeMap(std::make_pair(0, 0)));
            _end->parent = _root;
            _end->height = 0;
        }
        template <class InputIterator>
        map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _comp(comp), _alloc(alloc), _size(0)
        {
			_root = _alloc.allocate(1);
			_alloc.construct(_root, nodeMap(std::make_pair(0, 0)));
			_root->right = _end;
			_root->end = true;
			_end = _alloc.allocate(1);
			_alloc.construct(_end, nodeMap(std::make_pair(0, 0)));
			_end->parent = _root;
			_end->height = 0;
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
        ~map()
        {
			clear();
			_alloc.destroy(_root);
			_alloc.deallocate(_root, 1);
			_alloc.destroy(_end);
			_alloc.deallocate(_end, 1);
        }
        map& operator= (const map& x)
        {
			if (this == &x)
				return *this;
			clear();
			insert(x.begin(), x.end());
			return *this;
        }
		//////////////////////ITERATORS///////////////////////
        iterator begin()
        {
            nodeMap *tmp = _root;
            if (_size == 0)
                return (iterator(tmp));
            while (tmp->left != nullptr)
                tmp = tmp->left;
            return (iterator(tmp));
        }
		const_iterator begin() const
		{
			nodeMap *tmp = _root;
			if (_size == 0)
				return (const_iterator(tmp));
			while (tmp->left != nullptr)
				tmp = tmp->left;
			return (const_iterator(tmp));
		}
        iterator end()
        {
            nodeMap *tmp = _root;
            if (_size == 0)
                return (iterator(tmp));
            while (tmp->end != true)
                tmp = tmp->right;
            return (iterator(tmp->right));
        }
		const_iterator end() const
		{
			nodeMap *tmp = _root;
			if (_size == 0)
				return (const_iterator(tmp));
			while (tmp->end != true)
				tmp = tmp->right;
			return (const_iterator(tmp->right));
		}
		reverse_iterator rbegin()
		{
			nodeMap *tmp = _root;
			if (_size == 0)
				return (reverse_iterator(tmp));
			while (tmp->left != nullptr)
				tmp = tmp->left;
			return (reverse_iterator(tmp));
		}
		const_reverse_iterator rbegin() const
		{
			nodeMap *tmp = _root;
			if (_size == 0)
				return (const_reverse_iterator(tmp));
			while (tmp->left != nullptr)
				tmp = tmp->left;
			return (const_reverse_iterator(tmp));
		}
		reverse_iterator rend()
		{
			nodeMap *tmp = _root;
			if (_size == 0)
				return (reverse_iterator(tmp));
			while (tmp->end != true)
				tmp = tmp->right;
			return (reverse_iterator(tmp->right));
		}
		const_reverse_iterator rend() const
		{
			nodeMap *tmp = _root;
			if (_size == 0)
				return (const_reverse_iterator(tmp));
			while (tmp->end != true)
				tmp = tmp->right;
			return (const_reverse_iterator(tmp->right));
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
            nodeMap *tmp = _root;
            nodeMap *prev = _root;
            nodeMap *node = _alloc.allocate(1);
            _alloc.construct(node, nodeMap(val));
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
				nodeMap *tmp = _root;
				delNode(tmp, position.getNode());
				_size--;
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
