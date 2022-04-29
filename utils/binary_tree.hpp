#ifndef BINARY_TREE_HPP
#define BINARY_TREE_HPP

#include <functional>
#include <memory>
#include "binary_tree_node.hpp"
#include "pair.hpp"

namespace ft {

	template <class Key, class Value, class Compare = std::less<Key> >
	class Tree {
		public:
			typedef treeNode<Key, Value> node;
			typedef node* node_ptr;
			typedef const node* const_node_ptr;
			typedef ft::pair<Key, Value> value_type;
			typedef std::allocator<node> allocator_type;

			Tree() : _origin(node_ptr()), _comp(Compare()), _alloc(allocator_type()) {}
			Tree(const Tree &src) {
				*this = src;
			}
			//Faire Deep Copy
			Tree &operator=(const Tree &src) {
				_comp = src._comp;
				_alloc = src._alloc;
				_origin = src._origin;
			}
			//Supprimer l'arbre correctement
			~Tree() {

			}

			node_ptr add(const value_type &pair) {
				if (_origin == NULL)
				{
					_origin = _alloc.allocate(1);
					_alloc.construct(_origin, node(pair));
					return (_origin);
				}
				node_ptr cur = _origin;
				node_ptr cur_prev;
				while (cur != NULL)
				{
					cur_prev = cur;
					if (_comp(pair.first, cur->getKey()))
						cur = cur->getLeft();
					else if (_comp(cur->getKey(), pair.first))
						cur = cur->getRight();
					else
						return (cur);
				}
				cur = _alloc.allocate(1);
				_alloc.construct(cur, node(pair, cur_prev));
				if (_comp(pair.first, cur->getKey()))
					cur_prev->setLeft(cur);
				else
					cur_prev->setRight(cur);
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
					return (NULL);
				while ((cur->getParent() != NULL) && (cur->getParent()->getLeft() != NULL) && (cur->getParent()->getLeft() != cur))
					cur = cur->getParent();
				if ((cur->getParent() != NULL) && (cur->getParent()->getLeft() != NULL) && (cur->getParent()->getLeft() == cur))
					return (cur->getParent());
				return (NULL);
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
					return (NULL);
				while ((cur->getParent() != NULL) && (cur->getParent()->getRight() != NULL) && (cur->getParent()->getRight() != cur))
					cur = cur->getParent();
				if ((cur->getParent() != NULL) && (cur->getParent()->getRight() != NULL) && (cur->getParent()->getRight() == cur))
					return (cur->getParent());
				return (NULL);
			}

			void del_noChild(node_ptr n_del) {
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
			}

			void del_oneChild(node_ptr n_del) {
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
			}

			void del_twoChild(node_ptr n_del) {
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
					n_new->setLeft(delLeft);
					delLeft->setParent(n_new);
					n_new->setRight(delRight);
					delRight->setParent(n_new);
					if ((n_new->getParent()->getLeft()) && (n_new->getParent()->getLeft() == n_new))
						n_new->getParent()->getLeft() = NULL;
					else
						n_new->getParent()->getRight() = NULL;
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
			}

			void del(node_ptr n_del) {
				if (!n_del)
					return ;
				if (n_del->getLeft() == NULL && n_del->getRight() == NULL)
					del_noChild(n_del);
				else if (n_del->getLeft() == NULL || n_del->getLeft() == NULL)
					del_oneChild(n_del);
				else
					del_twoChild(n_del);
			}

		private :
			node_ptr		_origin;
			Compare			_comp;
			allocator_type	_alloc;
	};

}

#endif