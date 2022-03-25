#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "../iterators/reverse_iterator.hpp"
#include "../iterators/iterator_traits.hpp"
#include "../iterators/random_iterator.hpp"
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
			typedef typename	ft::random_iterator<value_type> iterator;
			typedef typename	ft::random_iterator<const value_type> const_iterator;
			typedef typename	ft::reverse_iterator<iterator> reverse_iterator;
			typedef typename	ft::reverse_iterator<const_iterator> const_reverse_iterator;
			typedef typename 	ft::iterator_traits<iterator>::difference_type difference_type;
			typedef typename	allocator_type::size_type 	size_type;

			//Default Constructor
			explicit vector(const allocator_type &alloc = allocator_type()) : _alloc(alloc),
																				_first(0),
																				_last(0),
																				_max (0) {

			}
			//fill constructor
			explicit vector(size_type n, const value_type &val = value_type(),
							const allocator_type &alloc = allocator_type()) : _alloc(alloc),
																				_first(0),
																				_last(0),
																				_max(0) {
				_first = _alloc.allocate(n);
				_max = _first + n;
				_last = _first;
				while (_last < _max)
				{
					_alloc.construct(_last, val);
					_last++;
				}
			}
			//range constructor
			template <class InputIterator>
			vector(InputIterator first, InputIterator last, const allocator_type &alloc = allocator_type()) {

			}
			//copy constructor
			vector(const vector &x) {

			}
			//destructor
			~vector() {

			}

		private :
			allocator_type _alloc;
			pointer _first;
			pointer _last;
			pointer _max;
	};
}

#endif
