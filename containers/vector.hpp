#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "../iterators/reverse_iterator.hpp"
#include "../iterators/iterator_traits.hpp"
#include "../iterators/random_iterator.hpp"
#include "../utils/utils.hpp"
#include <memory>
#include <string>
#include <iostream>
#include <sstream>

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
				while (_last != _max)
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
				while (first != last)
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
				_alloc.deallocate(_first, capacity());
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
					throw (std::length_error("vector::resize"));
				else if (n > size())
					insert(end(), n - size(), val);
				else if (n < size())
				{
					while (n < size())
					{
						_last--;
						_alloc.destroy(_last);
					}
				}
			}

			size_type capacity() const {
				return (_max - _first);
			}

			bool empty() const {
				if (size() == 0)
					return (true);
				else
					return (false);
			}

			void reserve(size_type n) {
				if (n > max_size())
					throw (std::length_error("vector::reserve"));
				else if (n > capacity())
				{
					pointer tmp_first = _first;
					pointer tmp_last = _last;
					size_type tmp_size = size();
					size_type tmp_max = capacity();

					_first = _alloc.allocate(n);
					_max = _first + n;
					_last = _first;
					while (tmp_first != tmp_last)
					{
						_alloc.construct(_last, *tmp_first++);
						_last++;
					}
					_alloc.deallocate(tmp_last - tmp_size, tmp_max);
				}
			}


			//Element access
			reference operator[](size_type n) {
				return (*(_first + n));
			}
			const_reference operator[](size_type n) const {
				return (*(_first + n));
			}

			reference at(size_type n) {
				if (n >= size())
				{
					std::ostringstream oss;
					oss << n;
					std::string s_n = oss.str();
					oss << size();
					std::string s_size = oss.str();
					throw ("vector::range_check: n (which is " + s_n + ") >= this->size() (which is " + s_size + ")");
				}
				else
					return ((*this)[n]);
			}
			const_reference at(size_type n) const {
				if (n >= size())
				{
					std::ostringstream oss;
					oss << n;
					std::string s_n = oss.str();
					oss << size();
					std::string s_size = oss.str();
					throw ("vector::range_check: n (which is " + s_n + ") >= this->size() (which is " + s_size + ")");
				}
				else
					return ((*this)[n]);
			}

			reference front() {
				return(*_first);
			}
			const_reference  front() const {
				return (*_first);
			}

			reference back() {
				return (*(_last - 1));
			}
			const_reference back() const {
				return (*(_last - 1));
			}


			//Modifiers
			template <class InputIterator>
			void assign(InputIterator first, InputIterator last) {
				clear();
				difference_type n = ft::distance(first, last);
				if (n <= 0)
					return ;
				if (size() + n <= capacity())
				{
					for (size_type i = 0; i < n; i++)
					{
						_alloc.construct(_last, *first++);
						_last++;
					}
				}
				else
				{
					_alloc.deallocate(_first, capacity());
					_first = _alloc.allocate(n);
					_max = _first + n;
					_last = _first;
					for (size_type i = 0; i < n; i++)
					{
						_alloc.construct(_last, *first++);
						_last++;
					}
				}
			}
			void assign(size_type n, const value_type &val) {
				clear();
				if (n <= 0)
					return ;
				if (size() + n <= capacity())
				{
					for (size_type i = 0; i < n; i++)
					{
						_alloc.construct(_last, val);
						_last++;
					}
				}
				else
				{
					_alloc.deallocate(_first, capacity());
					_first = _alloc.allocate(n);
					_max = _first + n;
					_last = _first;
					for (size_type i = 0; i < n; i++)
					{
						_alloc.construct(_last, val);
						_last++;
					}
				}
			}

			void push_back(const value_type &val) {
				if (size() == capacity())
				{
					size_type new_max;
					if (size() > 0)
						new_max = (size() * 2);
					else
						new_max = 1;
					reserve(new_max);
				}
				_alloc.constrcut(_last, val);
				_last++;
			}

			void pop_back() {
				_last--;
				_alloc.destroy(_last);
			}

			iterator insert(iterator position, const value_type &val) {

			}
			void insert(iterator  position, size_type n, const value_type &val) {
				if (n <= 0)
					return;
				if (n > max_size())
					throw (std::length_error("vector::fill_insert"));
			}
			template <class InputIterator>
			void insert(iterator position, InputIterator first, InputIterator last) {

			}

			iterator erase(iterator position) {

			}
			iterator erase(iterator first, iterator last) {

			}

			void swap(vector &x) {
				if (x == *this)
					return ;
				allocator_type tmp_alloc = _alloc;
				pointer tmp_first = _first;
				pointer tmp_last = _last;
				pointer tmp_max = _max;

				_alloc = x._alloc;
				_first = x._first;
				_last = x._last;
				_max = x._max;

				x._alloc = tmp_alloc;
				x._first = tmp_first;
				x._last = tmp_last;
				x._max = tmp_max;
			}

			void clear() {
				size_type tmp_size = size();
				size_type i = 0;
				while (i < tmp_size)
				{
					_last--;
					_alloc.destroy(_last);
					i++;
				}
			}

			//Allocator
			allocator_type get_allocator() const {
				return (_alloc);
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
	void swap(vector<T, Alloc> &x, vector<T, Alloc> &y) {
		x.swap(y);
	}
}

#endif
