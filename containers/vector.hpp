#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "../iterators/reverse_iterator.hpp"
#include "../iterators/iterator_traits.hpp"
#include "../iterators/random_iterator.hpp"
#include "../utils/utils.hpp"
#include <memory>
#include

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
				while (_last <= _max)
				{
					_alloc.construct(_last, val);
					_last++;
				}
			}
			//range constructor
			template <class InputIterator>
			vector(InputIterator first, InputIterator last,
				   const allocator_type &alloc = allocator_type()) : _alloc(alloc),
				   														_first(0),
																		_last(0),
																		_max(0) {
				difference_type n = ft::distance(first, last);
				_first = _alloc.allocate(n);
				_max = _first + n;
				_last = _first;
				while (_last <= _max)
				{
					_alloc.construct(_last, *first++);
					_last++;
				}
			}
			//copy constructor
			vector(const vector &x) : _alloc(x.alloc),
										_first(0),
										_last(0),
										_max(0) {
				insert(begin(), x.begin(), x.end());
			}
			//destructor
			~vector() {
				clear();
				_alloc.deallocate(_start, capacity());
			}

			//Operator =
			vector &operator=(const vector &x) {
				if (x == *this)
					return (*this);
				clear();
				insert(begin(), x.begin(), x.end());
				return (*this);
			}

			//Iterators
			iterator begin() {
				return (_first);
			}
			const_iterator begin() const {
				return (_first);
			}

			iterator end() {
				if (empty() == true)
					return (begin());
				return (_last);
			}
			const_iterator end() const {
				if (empty() == true)
					return (begin());
				return (_last);
			}

			reverse_iterator rbegin() {
				return (reverse_iterator(end()));
			}
			const_reverse_iterator rbegin() const {
				return (reverse_iterator(end()));
			}

			reverse_iterator rend() {
				return (reverse_iterator(begin()));
			}
			const_reverse_iterator rend() const {
				return (reverse_iterator(begin()));
			}


			//Capacity
			size_type size() const {
				return (_last - _first);
			}

			size_type max_size() const {
				return (allocator_type().max_size());
			}

			void resize(size_type n, value_type val = value_type()) {
				if (n > max_size())
					throw (std::length_error("vector::out of range"));
				if (n > size())
					insert(end(), n - size(), val);
				while (n < size())
				{
					_last--;
					_alloc.destroy(_last);
				}
			}

			size_type capacity() const {

			}

			bool empty() const {

			}

			void reserve(size_type n) {

			}


			//Element access
			reference operator[](size_type n) {

			}
			const_reference operator[](size_type n) const {

			}

			reference at(size_type n) {

			}
			const_reference at(size_type n) const {

			}

			reference front() {

			}
			const_reference  front() const {

			}

			reference back() {

			}
			const_reference back() const {

			}


			//Modifiers
			template <class InputIterator>
			void assign(InputIterator first, InputIterator last) {

			}
			void assign(size_type n, const value_type &val) {

			}

			void push_back(const value_type &val) {

			}

			void pop_back() {

			}

			iterator insert(iterator position, const value_type &val) {

			}
			void insert(iterator  position, size_type n, const value_type &val) {

			}
			template <class InputIterator>
			void insert(iterator position, InputIterator first, InputIterator last) {

			}

			iterator erase(iterator position) {

			}
			iterator erase(iterator first, iterator last) {

			}

			void swap(vector &x) {

			}

			void clear() {

			}

			//Allocator
			allocator_type get_allocator() const {

			}

		private :
			allocator_type _alloc;
			pointer _first;
			pointer _last;
			pointer _max;
	};

	//relational operators
	template <class T, class Alloc>
	bool operator==(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) {

	}
	template <class T, class Alloc>
	bool operator!=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) {

	}
	template <class T, class Alloc>
	bool operator<(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) {

	}
	template <class T, class Alloc>
	bool operator<=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) {

	}
	template <class T, class Alloc>
	bool operator>(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) {

	}
	template <class T, class Alloc>
	bool operator>=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) {

	}

	//Swap
	template <class T, class Alloc>
	void swap(vector<T, Alloc> &x. vector<T, Alloc> &y) {

	}
}

#endif
