#ifndef BINARY_TREE_HPP
#define BINARY_TREE_HPP

#include <functional>
#include <memory>
#include "binary_tree_node.hpp"
#include "pair.hpp"
#include "../iterators/map_iterator.hpp"

namespace ft {

	template <class Key, class Value, class Compare = std::less<Key> >
	class Tree {
		public:
			typedef treeNode<Key, Value>						node;
			typedef node*										node_ptr;
			typedef const node*									const_node_ptr;
			typedef size_t 										size_type;
			typedef ft::pair<Key, Value>						value_type;
			typedef std::allocator<node>						allocator_type;
			typedef ft::map_iterator<node, Key, Value>			iterator;
			typedef ft::const_map_iterator<node, Key, Value>	const_iterator;

			Tree() : _origin(node_ptr()), _overf(node_ptr()), _size(0), _comp(Compare()), _alloc(allocator_type()) {}
			Tree(const Tree &src) {
				*this = src;
			}
			//TODO Faire Deep Copy
			Tree &operator=(const Tree &src) {
				_comp = src._comp;
				_alloc = src._alloc;
				_origin = src._origin;
				_overf = src._end;
				_size = src._size;
				return *this;
			}
			//TODO Supprimer l'arbre correctement
			~Tree() {
				node_ptr cur = _origin;
				node_ptr tmp = prev(cur);
				while (tmp != NULL)
				{
					cur = tmp;
					tmp = prev(cur);

				}
				tmp = next(cur);
				while (tmp != NULL)
				{
					_alloc.destroy(cur);
					//_alloc.deallocate(cur, 1);
					cur = tmp;
					tmp = next(cur);
				}
				_alloc.destroy(cur);
				//_alloc.deallocate(cur, 1);
			}

			node_ptr add(const value_type &pair) {
				if (_origin == NULL)
				{
					_origin = _alloc.allocate(1);
					_alloc.construct(_origin, node(pair));
					_size++;
					return (_origin);
				}
				node_ptr cur = _origin;
				node_ptr cur_prev;
				while (cur != NULL)
				{
					cur_prev = cur;
					if (_comp(pair.first, cur->getKey())) {
						cur = cur->getLeft();
					}
					else if (_comp(cur->getKey(), pair.first)) {
						cur = cur->getRight();
					}
					else
						return (cur);
				}
				cur = _alloc.allocate(1);
				_alloc.construct(cur, node(pair, cur_prev));
				if (_comp(pair.first, cur_prev->getKey()))
					cur_prev->setLeft(cur);
				else
					cur_prev->setRight(cur);
				_size++;
				return (cur);
			}

			node_ptr search(Key s_key) {
				if (!_origin)
					return (NULL);
				node_ptr cur = _origin;
				while (cur != NULL)
				{
					if (_comp(s_key, cur->getKey()))
						cur = cur->getLeft();
					else if (_comp(cur->getKey(), s_key))
						cur = cur->getRight();
					else
						return (cur);
				}
				return (NULL);
			}

			node_ptr next(node_ptr cur) {
				if (!cur)
					return (NULL);
				if (cur->getRight() != NULL)
				{
					cur = cur->getRight();
					while (cur->getLeft() != NULL)
						cur = cur->getLeft();
					return (cur);
				}
				if (cur == _origin)
					return (_overf);
				while ((cur->getParent() != NULL) && (cur->getParent()->getLeft() != NULL) && (cur->getParent()->getLeft() != cur))
					cur = cur->getParent();
				if ((cur->getParent() != NULL) && (cur->getParent()->getLeft() != NULL) && (cur->getParent()->getLeft() == cur))
					return (cur->getParent());
				return (_overf);
			}

			node_ptr prev(node_ptr cur) {
				if (!cur)
					return (NULL);
				if (cur->getLeft() != NULL)
				{
					cur = cur->getLeft();
					while (cur->getRight() != NULL)
						cur = cur->getRight();
					return (cur);
				}
				if (cur == _origin)
					return (_overf);
				while ((cur->getParent() != NULL) && (cur->getParent()->getRight() != NULL) && (cur->getParent()->getRight() != cur))
					cur = cur->getParent();
				if ((cur->getParent() != NULL) && (cur->getParent()->getRight() != NULL) && (cur->getParent()->getRight() == cur))
					return (cur->getParent());
				return (_overf);
			}

			void del_noChild(node_ptr &n_del) {
				if (n_del == _origin)
					_origin = NULL;
				else
				{
					if (n_del->getParent()->getLeft() == n_del)
						n_del->getParent()->setLeft(NULL);
					if (n_del->getParent()->getRight() == n_del)
						n_del->getParent()->setRight(NULL);
				}
				_alloc.destroy(n_del);
				n_del = NULL;
				_size--;
			}

			void del_oneChild(node_ptr &n_del) {
				node_ptr n_new;
				node_ptr delParent;

				if (n_del->getRight() != NULL)
					n_new = n_del->getRight();
				else
					n_new = n_del->getLeft();
				if (n_del == _origin)
				{
					_origin = n_new;
					n_new->setParent(NULL);
				}
				else
				{
					delParent = n_del->getParent();
					if ((delParent->getLeft() != NULL) && (delParent->getLeft() == n_del))
						delParent->setLeft(n_new);
					if ((delParent->getRight() != NULL) && (delParent->getRight() == n_del))
						delParent->setRight(n_new);
					n_new->setParent(delParent);
				}
				_alloc.destroy(n_del);
				n_del = NULL;
				_size--;
			}

			void del_twoChild(node_ptr &n_del) {
				node_ptr n_new = next(n_del);
				node_ptr delParent;
				node_ptr delLeft = n_del->getLeft();
				node_ptr delRight = n_del->getRight();

				if (n_del->getRight() == n_new)
				{
					n_new->setLeft(delLeft);
					delLeft->setParent(n_new);

				}
				else
				{
					//Possiblement retirer ce if, parce que forcement a gauche du parent si je suis dans le else
					if ((n_new->getParent()->getLeft()) && (n_new->getParent()->getLeft() == n_new))
					{
						if (n_new->getRight() != NULL)
						{
							n_new->getRight()->setParent(n_new->getParent());
							n_new->getParent()->setLeft(n_new->getRight());
						}
						else
							n_new->getParent()->setLeft(NULL);
					}

					n_new->setLeft(delLeft);
					delLeft->setParent(n_new);
					n_new->setRight(delRight);
					delRight->setParent(n_new);
				}
				if (n_del == _origin)
				{
					_origin = n_new;
					n_new->setParent(NULL);
				}
				else
				{
					delParent = n_del->getParent();
					if ((delParent->getLeft() != NULL) && (delParent->getLeft() == n_del))
						delParent->setLeft(n_new);
					if ((delParent->getRight() != NULL) && (delParent->getRight() == n_del))
						delParent->setRight(n_new);
					n_new->setParent(delParent);
				}
				_alloc.destroy(n_del);
				n_del = NULL;
				_size--;
			}

			void del(node_ptr &n_del) {
				if (!n_del)
					return ;
				if (search(n_del->getKey()) == NULL)
					return ;
				if (n_del->getLeft() == NULL && n_del->getRight() == NULL)
					del_noChild(n_del);
				else if (n_del->getLeft() == NULL || n_del->getLeft() == NULL)
					del_oneChild(n_del);
				else
					del_twoChild(n_del);
			}

			node_ptr getOrigin() {
				return (_origin);
			}

			node_ptr getBegin() {
				node_ptr cur = _origin;
				while (prev(cur) != _overf)
					cur = prev(cur);
				return (cur);
			}

			node_ptr getEnd() {
				node_ptr cur = _origin;
				while(next(cur) != _overf)
					cur = next(cur);
				return (cur);
			}

			size_type getSize() {
				return (_size);
			}

		private :
			node_ptr		_origin;
			node_ptr 		_overf;
			size_type		_size;
			Compare			_comp;
			allocator_type	_alloc;
	};


}

#endif