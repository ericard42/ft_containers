#ifndef BINARY_TREE_NODE_HPP
#define BINARY_TREE_NODE_HPP

#include "pair.hpp"
#include <iostream>

namespace ft {

	template <class Key, class Value>
	class treeNode {

		public :
			typedef treeNode* pointer;
			typedef const treeNode* const_pointer;
			typedef ft::pair<Key, Value> value_type;

			treeNode() : _data(value_type()), _parent(NULL), _right(NULL), _left(NULL) {}
			treeNode(value_type const &pair, const pointer parent = pointer()) : _data(pair), _parent(parent), _right(NULL), _left(NULL) {}
			treeNode(treeNode const &src) {
				*this = src;
			}
			treeNode &operator=(treeNode const &src) {
				_data = src._data;
				_parent = src._parent;
				_right = src._right;
				_left = src._left;
				return *this;
			}
			~treeNode() {};

			void setParent(const pointer parent) {
				_parent = parent;
			}
			void setLeft(const pointer left) {
				_left = left;
			}
			void setRight (const pointer right) {
				_right = right;
			}

			const_pointer getCurrent() {
				return (this);
			}
			pointer getParent() {
				return (_parent);
			}
			pointer getLeft() {
				return (_left);
			}
			pointer getRight() {
				return (_right);
			}

			void setKey(const Key &key) {
				_data.first = key;
			}
			void setValue(const Value &value) {
				_data.second = value;
			}
			void setPair(const value_type &pair) {
				_data = pair;
			}

			Key &getKey() {
				return (_data.first);
			}
			Key const &getKey() const {
				return (_data.first);
			}
			Value &getValue() {
				return (_data.second);
			}
			value_type &getPair() {
				return (_data);
			}
			const value_type &getPair() const {
				return (_data);
			}

			void printNode() {
				std::cout << "Key : " << getKey() << "\n";
				//std::cout << "Value : " << getValue() << "\n";
				if (getParent() != NULL)
					std::cout << "Key Parent : " << getParent()->getKey() << "\n";
				if (getLeft() != NULL)
					std::cout << "Key Left : " << getLeft()->getKey() << "\n";
				if (getRight() != NULL)
					std::cout << "Key Right : " << getRight()->getKey() << "\n";
				std::cout << "--------------------" << std::endl;
			}

		private :
			value_type _data;
			pointer _parent;
			pointer _right;
			pointer _left;

	};

}

#endif