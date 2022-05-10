#ifndef BINARY_TREE_HPP
#define BINARY_TREE_HPP

#include <functional>
#include <memory>
#include "binary_tree_node.hpp"
#include "pair.hpp"
//#include "../iterators/map_iterator.hpp"

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

			Tree() : _origin(NULL), _size(0), _comp(Compare()), _alloc(allocator_type()) {
				_begin = _alloc.allocate(1);
				_alloc.construct(_begin, node());
				_end = _alloc.allocate(1);
				_alloc.construct(_end, node());
			}
			Tree(const Tree &src) {
				*this = src;
			}
			Tree &operator=(const Tree &src) {
				if (_origin != NULL)
				{
					treeDelete(_origin);
					_size = 0;
				}
				if (_begin != NULL)
					_alloc.deallocate(_begin, 1);
				if (_end != NULL)
					_alloc.deallocate(_end, 1);
				_comp = src._comp;
				_alloc = src._alloc;
				_size = src._size;
				if (src._origin != NULL)
					_origin = treeCopy(src._origin);
				else
					_origin = NULL;
				_begin = _alloc.allocate(1);
				_alloc.construct(_begin, node());
				_end = _alloc.allocate(1);
				_alloc.construct(_end, node());
				return *this;
			}
			~Tree() {
				if (_origin != NULL)
				{
					treeDelete(_origin);
					_size = 0;
				}
				if (_begin != NULL)
				{
					_alloc.deallocate(_begin, 1);
					_begin = NULL;
				}
				if (_end != NULL)
				{
					_alloc.deallocate(_end, 1);
					_end = NULL;
				}
			}

			void treeReset() {
				_origin = NULL;
				_begin = NULL;
				_end = NULL;
				_size = 0;
				_comp = Compare();
				_alloc = allocator_type();
			}

			//Delete en récursif en enlevant les enfants en priorité.
			void	treeDelete(node_ptr cur) {
				if (_origin == NULL)
					return ;
				if (cur->getLeft() != NULL)
				{
					treeDelete(cur->getLeft());
					cur->setLeft(NULL);
				}
				if (cur->getRight() != NULL)
				{
					treeDelete(cur->getRight());
					cur->setRight(NULL);
				}
				if (cur != NULL)
				{
					_alloc.destroy(cur);
					_alloc.deallocate(cur, 1);
					cur = NULL;
				}
				_size = 0;
			}

			size_type maxSize() const {
				return (_alloc.max_size());
			}

			node_ptr treeCopy(node_ptr c_cur) {
				node_ptr cur = _alloc.allocate(1);
				_alloc.construct(cur, node(c_cur->getPair()));
				if (c_cur->getLeft() != NULL)
				{
					cur->setLeft(treeCopy(c_cur->getLeft()));
					cur->getLeft()->setParent(cur);
				}
				if (c_cur->getRight() != NULL)
				{
					cur->setRight(treeCopy(c_cur->getRight()));
					cur->getRight()->setParent(cur);
				}
				return (cur);
			}

			//Comparer les deux valeurs jusqu'à avoir un espace vide où ajouter la data
			// (Ou trouver la même valeur et ne rien ajouter)
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

			node_ptr search(Key s_key) const {
				if (_origin == NULL)
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

			//Trouver la valeur suivante. Sauf exceptions, next sera la data la plus à gauche de l'enfant à droite d'où on est.
			node_ptr next(node_ptr cur) const {
				if (!cur)
					return (NULL);
				if (cur == _begin)
					return (getBegin());
				if (cur->getRight() != NULL)
				{
					cur = cur->getRight();
					while (cur->getLeft() != NULL)
						cur = cur->getLeft();
					return (cur);
				}
				if (cur->getParent() == NULL)
					return (_end);
				while ((cur->getParent() != NULL) && (cur->getParent()->getLeft() != cur))
					cur = cur->getParent();
				if ((cur->getParent() != NULL) && (cur->getParent()->getLeft() == cur))
					return (cur->getParent());
				return (_end);
			}

			//Trouver la valeur précédente. Sauf exceptions, next sera la data la plus à droite de l'enfant à gauche d'où on est.
			node_ptr prev(node_ptr cur) const {
				if (!cur)
					return (NULL);
				if (cur == _end)
					return (getEnd());
				if (cur->getLeft() != NULL)
				{
					cur = cur->getLeft();
					while (cur->getRight() != NULL)
						cur = cur->getRight();
					return (cur);
				}
				if (cur->getParent() == NULL)
					return (_begin);
				while ((cur->getParent() != NULL) && (cur->getParent()->getRight() != cur))
					cur = cur->getParent();
				if ((cur->getParent() != NULL) && (cur->getParent()->getRight() == cur))
					return (cur->getParent());
				return (_begin);
			}

			//Pas d'enfant, on supprime simplement la node.
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
				_alloc.deallocate(n_del, 1);
				n_del = NULL;
				_size--;
			}

			//Un enfant, on remplace simplement la node par son unique enfant.
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
				_alloc.deallocate(n_del, 1);
				n_del = NULL;
				_size--;
			}

			//Deux enfants, on va remplacer la node par next.
			void del_twoChild(node_ptr &n_del) {
				node_ptr n_new = next(n_del);
				node_ptr delParent;
				node_ptr delLeft = n_del->getLeft();
				node_ptr delRight = n_del->getRight();

				//La node qui remplacera n'aura jamais d'enfant à sa gauche.

				//Si on est directement à droite de la node à supprimer, on modifie seulement l'enfant de gauche.
				if ((n_del->getRight()) && n_del->getRight() == n_new)
				{
					n_new->setLeft(delLeft);
					delLeft->setParent(n_new);

				}
				//Si on n'est pas à droite de la node à supprimer, il faut lui donner ses deux nouveaux enfants.
				else
				{
					//Si la node qui remplace a déjà un enfant à droite, ce dernier la remplacera à gauche de son parent.
					if (n_new->getRight() != NULL)
					{
						n_new->getRight()->setParent(n_new->getParent());
						n_new->getParent()->setLeft(n_new->getRight());
					}
					else
						n_new->getParent()->setLeft(NULL);

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
				_alloc.deallocate(n_del, 1);
				n_del = NULL;
				_size--;
			}

			//Vérifier combien d'enfants a la node à delete.
			void del(node_ptr &n_del) {
				if (!n_del)
					return ;
				if (n_del == _end || n_del == _begin)
					return ;
				if (search(n_del->getKey()) == NULL)
					return ;
				if (n_del->getLeft() == NULL && n_del->getRight() == NULL)
					del_noChild(n_del);
				else if (n_del->getLeft() == NULL || n_del->getRight() == NULL)
					del_oneChild(n_del);
				else
					del_twoChild(n_del);
			}

			void setOrigin(node_ptr cur) {
				_origin = cur;
			}

			node_ptr getOrigin() const {
				return (_origin);
			}

			node_ptr getBegin() const {
				node_ptr cur = _origin;
				while (prev(cur) != NULL && prev(cur) != _begin)
					cur = prev(cur);
				return (cur);
			}

			node_ptr getEnd() const {
				node_ptr cur = _origin;
				while(next(cur) != NULL && next(cur) != _end)
					cur = next(cur);
				return (cur);
			}

			node_ptr getPastEnd() const {
				return (_end);
			}

			node_ptr getPastBegin() const {
				return (_begin);
			}

			size_type getSize() const {
				return (_size);
			}

		private :
			node_ptr		_origin;
			size_type		_size;
			Compare			_comp;
			allocator_type	_alloc;
			node_ptr 		_begin;
			node_ptr		_end;
	};


}

#endif