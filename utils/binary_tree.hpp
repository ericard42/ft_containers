#ifndef BINARY_TREE_HPP
#define BINARY_TREE_HPP

namespace ft {

	template <class T, class Compare, class Allocator>
	class BT {
		public :
			typedef T			value_type;
			typedef Allocator	allocator_type;
			typedef Compare		key_compare;

			BT() {

			}

			struct Node {
				value_type	_Data;
				Node		*parent;
				Node		*left;
				Node		*right;
			};

		private :



	};

}

#endif