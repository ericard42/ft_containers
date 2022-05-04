#ifndef TREE_ITERATOR_HPP
#define TREE_ITERATOR_HPP

#include "iterator_traits.hpp"
#include "iterator.hpp"
#include "../utils/binary_tree.hpp"
#include "../utils/binary_tree_node.hpp"

namespace ft {

	template <class T, class Key, class Value, class Compare = std::less<T> >
	class map_iterator : public ft::iterator<std::bidirectional_iterator_tag, T> {
		public :
			//T = Node
			typedef const Tree<Key, Value, Compare>* _Tree;
			typedef T* node;
			typedef typename T::value_type value_type; //Pair
			typedef typename ft::iterator<std::bidirectional_iterator_tag, value_type>::pointer pointer;
			typedef typename ft::iterator<std::bidirectional_iterator_tag, value_type>::reference reference;
			typedef typename ft::iterator<std::bidirectional_iterator_tag, value_type>::difference_type difference_type;


			//Constructors
			map_iterator() : _tree(_Tree()), _cur(node()) {}
			map_iterator(_Tree tree, node cur) : _tree(tree), _cur(cur) {}
			map_iterator(const map_iterator &src) : _tree(_Tree()), _cur(node()) {
				*this = src;
			}
			//Destructor
			~map_iterator() {}
			//Operator=
			map_iterator &operator=(const map_iterator &src) {
				if (*this == src)
					return (*this);
				_tree = src._tree;
				_cur = src._cur;
				return (*this);
			}

			node base() const {
				return (_cur);
			}

			//Operator*
			reference operator*() const {
				return (_cur->getPair());
			}
			//Operator->
			pointer operator->() const {
				return (&(_cur->getPair()));
			}

			//Operator++
			map_iterator &operator++() {
				_cur = _tree->next(_cur);
				return (*this);
			}
			//++Operator
			map_iterator operator++(int) {
				map_iterator tmp = *this;
				_cur = _tree->next(_cur);
				return (tmp);
			}

			//Operator--
			map_iterator &operator--() {
				_cur = _tree->prev(_cur);
				return (*this);
			}
			//--Operator
			map_iterator operator--(int) {
				map_iterator tmp = *this;
				_cur = _tree->prev(_cur);
				return (*this);
			}

			bool operator==(const map_iterator &other) {
				return (_cur == other._cur);
			}

			bool operator!=(const map_iterator &other) {
				return (_cur != other._cur);
			}

			_Tree getTree() const {
				return (_tree);
			}

		private :

			_Tree		_tree;
			node		_cur;
	};

	template <class T, class Key, class Value, class Compare = std::less<T> >
	class const_map_iterator : public ft::iterator<std::bidirectional_iterator_tag, T> {
		public :
			//T = Node
			typedef const Tree<Key, Value, Compare>* _Tree;
			typedef T* node;
			typedef typename T::value_type value_type; //Pair
			typedef typename ft::iterator<std::bidirectional_iterator_tag, value_type>::pointer pointer;
			typedef typename ft::iterator<std::bidirectional_iterator_tag, value_type>::reference reference;
			typedef typename ft::iterator<std::bidirectional_iterator_tag, value_type>::difference_type difference_type;


			//Constructors
			const_map_iterator() : _tree(_Tree()), _cur(node()) {}
			const_map_iterator(_Tree tree, node cur) : _tree(tree), _cur(cur) {}
			const_map_iterator(const const_map_iterator &src) : _tree(_Tree()), _cur(node()) {
				*this = src;
			}
			const_map_iterator(const map_iterator<T, Key, Value, Compare> &src) {
				_tree = src.getTree();
				_cur = src.base();
			}
			//Destructor
			~const_map_iterator() {}
			//Operator=
			const_map_iterator &operator=(const const_map_iterator &src) {
				if (*this == src)
					return (*this);
				_tree = src._tree;
				_cur = src._cur;
				return (*this);
			}

			node base() const {
				return (_cur);
			}

			//Operator*
			reference operator*() const {
				return (_cur->getPair());
			}
			//Operator->
			pointer operator->() const {
				return (&(_cur->getPair()));
			}

			//Operator++
			const_map_iterator &operator++() {
				_cur = _tree->next(_cur);
				return (*this);
			}
			//++Operator
			const_map_iterator operator++(int) {
				const_map_iterator tmp = *this;
				_cur = _tree->next(_cur);
				return (tmp);
			}

			//Operator--
			const_map_iterator &operator--() {
				_cur = _tree->prev(_cur);
				return (*this);
			}
			//--Operator
			const_map_iterator operator--(int) {
				const_map_iterator tmp = *this;
				_cur = _tree->prev(_cur);
				return (*this);
			}

			bool operator==(const const_map_iterator &other) {
				return (_cur == other._cur);
			}

			bool operator!=(const const_map_iterator &other) {
				return (_cur != other._cur);
			}

		private :
			_Tree		_tree;
			node		_cur;
	};
}

#endif