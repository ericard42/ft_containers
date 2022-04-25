#ifndef DISTANCE_HPP
#define DISTANCE_HPP

#include "../iterators/iterator_traits.hpp"

namespace ft {

	template <typename InputIterator>
	typename ft::iterator_traits<InputIterator>::difference_type
	do_distance(InputIterator first, InputIterator last, std::input_iterator_tag)
	{
		typename ft::iterator_traits<InputIterator>::difference_type ret;
		for (ret = 0; first != last; first++)
			ret++;
		return (ret);
	}

	template <typename InputIterator>
	typename ft::iterator_traits<InputIterator>::difference_type
	do_distance(InputIterator first, InputIterator last, std::random_access_iterator_tag)
	{
		return (last - first);
	}

	template <typename InputIterator>
	typename ft::iterator_traits<InputIterator>::difference_type distance(InputIterator first, InputIterator last) {
		return (do_distance(first, last, typename ft::iterator_traits<InputIterator>::iterator_category()));
	}

}

#endif