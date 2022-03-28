#ifndef UTILS_HPP
#define UTILS_HPP

#include "../iterators/iterator_traits.hpp"

namespace ft {

template <typename InputIterator>
typename ft::iterator_traits<InputIterator>::difference_type distance(InputIterator first, InputIterator last) {
	typename ft::iterator_traits<InputIterator>::difference_type ret;
	for (ret = 0; first != last; ret++)
		first++;
	return (ret);
}

}

#endif