#ifndef TREE_ITERATOR_HPP
#define TREE_ITERATOR_HPP

#include "iterator_traits.hpp"
#include "iterator.hpp"
#include "../utils/binary_tree.hpp"
#include "../utils/binary_tree_node.hpp"

namespace ft {

	template <class T, class Key, class Value>
	class map_iterator : public ft::iterator<std::bidirectional_iterator_tag, T> {
		public :
			//T = Node
			typedef Tree<Key, Value> Tree;
			typedef T* node;
			typedef typename T::value_type value_type; //Pair
			typedef typename ft::iterator<std::bidirectional_iterator_tag, value_type>::pointer pointer;
			typedef typename ft::iterator<std::bidirectional_iterator_tag, value_type>::reference reference;
			typedef typename ft::iterator<std::bidirectional_iterator_tag, value_type>::difference_type difference_type;


			//Constructors
			map_iterator() : _tree(Tree()), _cur(node()) {}
			map_iterator(node cur) : _tree(Tree()), _cur(cur) {}
			map_iterator(const map_iterator &src) {
				_tree = Tree();
				_cur = src._cur;
			}
			//Destructor
			~map_iterator() {}
			//Operator=
			map_iterator &operator=(const map_iterator &src) {
				if (*this == src)
					return (*this);
				_tree = Tree();
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
				_cur = _tree.next(_cur);
				return (*this);
			}
			//++Operator
			map_iterator operator++(int) {
				map_iterator tmp = *this;
				_cur = _tree.next(_cur);
				return (tmp);
			}

			//Operator--
			map_iterator &operator--() {
				_cur = _tree.prev(_cur);
				return (*this);
			}
			//--Operator
			map_iterator operator--(int) {
				map_iterator tmp = *this;
				_cur = _tree.prev(_cur);
				return (*this);
			}

			bool operator==(const map_iterator &other) {
				return (_cur == other._cur);
			}

			bool operator!=(const map_iterator &other) {
				return (_cur != other._cur);
			}

		private :

			Tree		_tree;
			node		_cur;
	};

	template <class T, class Key, class Value>
	class const_map_iterator : public ft::iterator<std::bidirectional_iterator_tag, T> {
		public :
			//T = Node
			typedef Tree<Key, Value> Tree;
			typedef T* node;
			typedef typename T::value_type value_type; //Pair
			typedef typename ft::iterator<std::bidirectional_iterator_tag, value_type>::pointer pointer;
			typedef typename ft::iterator<std::bidirectional_iterator_tag, value_type>::reference reference;
			typedef typename ft::iterator<std::bidirectional_iterator_tag, value_type>::difference_type difference_type;


			//Constructors
			const_map_iterator() : _tree(Tree()), _cur(node()) {}
			const_map_iterator(node cur) : _tree(Tree()), _cur(cur) {}
			const_map_iterator(const const_map_iterator &src) {
				_tree = Tree();
				_cur = src._cur;
			}
			const_map_iterator(const map_iterator<T, Key, Value> &src) {
				_tree = Tree();
				_cur = src.base();
			}
			//Destructor
			~const_map_iterator() {}
			//Operator=
			const_map_iterator &operator=(const const_map_iterator &src) {
				if (*this == src)
					return (*this);
				_tree = Tree();
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
				_cur = _tree.next(_cur);
				return (*this);
			}
			//++Operator
			const_map_iterator operator++(int) {
				const_map_iterator tmp = *this;
				_cur = _tree.next(_cur);
				return (tmp);
			}

			//Operator--
			const_map_iterator &operator--() {
				_cur = _tree.prev(_cur);
				return (*this);
			}
			//--Operator
			const_map_iterator operator--(int) {
				const_map_iterator tmp = *this;
				_cur = _tree.prev(_cur);
				return (*this);
			}

			bool operator==(const const_map_iterator &other) {
				return (_cur == other._cur);
			}

			bool operator!=(const const_map_iterator &other) {
				return (_cur != other._cur);
			}

		private :
			Tree		_tree;
			node		_cur;
	};
}

#endif