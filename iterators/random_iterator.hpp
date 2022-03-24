#ifndef RANDOM_ITERATOR_HPP
#define RANDOM ITERATOR_HPP

#include "iterator_traits.hpp"
#include "iterator.hpp"

namespace ft {

	template <class T>
	class random_iterator : public ft::iterator<std::random_access_iterator_tag, T> {
		protected :
			pointer _p;

		public :

			random_iterator()  {} //Constructor
	};

}

#endif
