#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "../iterators/reverse_iterator.hpp"
#include "../iterators/iterator_traits.hpp"
#include <memory>

namespace ft {
	template < class T, class Allocator = std::allocator<T> >
	class vector {
		public :
			//Member Type;
			typedef T			value_type;
			typedef Allocator	allocator_type;
			typedef typename	allocator_type::reference reference;
			typedef typename	allocator_type::const_reference const_reference;
			typedef typename	allocator_type::pointer pointer;
			typedef typename	allocator_type::const_pointer const_pointer;
			/*-42*/typedef typename	std::vector<value_type>::iterator iterator; //A modifier
			/*-42*/typedef typename	std::vector<const value_type>::iterator const_iterator; //A modifier
			typedef typename	reverse_iterator<iterator> reverse_iterator;

		private :
	};
}

#endif
