#ifndef BINARY_TREE_HPP
#define BINARY_TREE_HPP

#include <functional>
#include "binary_tree_node.hpp"
#include "pair.hpp"

namespace ft {

	template <class Key, class Value, class Compare = std::less<Key> >
	class tree {
			typedef treeNode<Key, Value> node;
			typedef node* node_ptr;
			typedef const node* const_node_ptr;
			typedef ft::pair<Key, Value> value_type;

			tree() : _origin(node_ptr()), _comp(Compare()) {}
			tree(const tree &src) {
				*this = src;
			}
			//Faire Deep Copy
			tree &operator=(const tree &src) {
				_origin = src._origin;
				_comp = src._comp;
			}
			//Supprimer l'arbre correctement
			~tree() {

			}

			node_ptr recursiveAdd(node_ptr tree, const value_type &pair) {
				if (tree == NULL)
				{
					tree->setPair(pair);
					return (pair);
				}
				if /*Plus petit*/ (_comp(pair.first, tree->getKey()))
					tree->setLeft(recursiveAdd(tree->getLeft(), pair));
				else if /*Plus Grand*/ (_comp(tree->getKey(), pair.first))
					tree->setRight(recursiveAdd(tree->getRight(), pair));
				else /*Egal*/
					return (tree);
				return (tree);
			}

			node_ptr add(const value_type &pair) {
				return (recursiveAdd(_origin, pair));
			}

		private :
			node_ptr	_origin;
			Compare		_comp;
	};

}

#endif