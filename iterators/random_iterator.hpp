#ifndef RANDOM_ITERATOR_HPP
#define RANDOM ITERATOR_HPP

#include "iterator_traits.hpp"
#include "iterator.hpp"

namespace ft {

	template <class T>
	class random_iterator : public ft::iterator<std::random_access_iterator_tag, T> {
		public :
			typedef typename ft::iterator<std::random_access_iterator_tag, T>::pointer pointer;
			typedef typename ft::iterator<std::random_access_iterator_tag, T>::reference reference;
			typedef typename ft::iterator<std::random_access_iterator_tag, T>::difference_type difference_type;

			random_iterator() : _p(pointer()) {} //Default Constructor
			random_iterator(pointer p) : _p(p) {}
			random_iterator(const random_iterator &src) : _p(src._p) {} //Copy Constructor
			~random_iterator() {} // Destructor

			random_iterator &operator=(const random_iterator &src) {
				if (this == &src)
					return (*this);
				_p = src._p;
				return (*this);
			}

			//Accesses the underlying iterator
			pointer base() const {
				return (_p);
			}

			//Accesses the pointed-to element
			reference operator*() const {
				return (*_p);
			}
			pointer operator->() const {
				return (&(operator*()));
			}

			//Accesses an element by index
			reference operator[](difference_type n) {
				pointer tmp = base() + n;
				return (*tmp);
			}

			//Advances or decrements the iterator
			//a + n
			random_iterator operator+(difference_type n) const {
				return (random_iterator(_p + n));
			}
			//a++
			random_iterator &operator++() {
				_p++;
				return (*this);
			}
			//++a
			random_iterator operator++(int) {
				random_iterator tmp = *this;
				_p++;
				return (tmp);
			}
			//a += n
			random_iterator &operator+=(difference_type n) {
				_p += n;
				return (*this);
			}
			//a - n
			random_iterator operator-(difference_type n) const {
				return (random_iterator(_p - n));
			}
			//a--
			random_iterator &operator--() {
				_p--;
				return (*this);
			}
			//--a
			random_iterator operator--(int) {
				random_iterator tmp = *this;
				_p--;
				return (tmp);
			}
			//a -= n
			random_iterator &operator-=(difference_type n) {
				_p -= n;
				return (*this);
			}

			operator random_iterator<const T> const() {
				return (random_iterator<const T>(_p));
			}

		private :
			pointer _p;
	};

	//Advances the iterator
	//n + a
	template <class T>
	ft::random_iterator<T> operator+(typename ft::random_iterator<T>::difference_type n,
								const ft::random_iterator<T> &it) {
		return (it + n);
	}
	//Calculates the distance between two iterator
	//a - b
	template <class T>
	typename ft::random_iterator<T>::difference_type operator-(
							const ft::random_iterator<T> &lhs,
							const ft::random_iterator<T> &rhs) {
			return (lhs.base() - rhs.base());
	}
	//a - const b
	template <class T>
	typename ft::random_iterator<T>::difference_type operator-(
			const ft::random_iterator<T> &lhs,
			const ft::random_iterator<const T> &rhs) {
		return (lhs.base() - rhs.base());
	}
	//const a - b
	template <class T>
	typename ft::random_iterator<T>::difference_type operator-(
			const ft::random_iterator<const T> &lhs,
			const ft::random_iterator<T> &rhs) {
		return (lhs.base() - rhs.base());
	}

	//Relational Operators
	//a == b
	template <class T>
	bool operator==(const ft::random_iterator<T> &lhs,
					const ft::random_iterator<T> &rhs) {
		return (lhs.base() == rhs.base());
	}
	//a == const b
	template <class T>
	bool operator==(const ft::random_iterator<T> &lhs,
					const ft::random_iterator<const T> &rhs) {
		return (lhs.base() == rhs.base());
	}
	//const a == b
	template <class T>
	bool operator==(const ft::random_iterator<const T> &lhs,
					const ft::random_iterator<T> &rhs) {
		return (lhs.base() == rhs.base());
	}

	//a != b
	template <class T>
	bool operator!=(const ft::random_iterator<T> &lhs,
					const ft::random_iterator<T> &rhs) {
		return (lhs.base() != rhs.base());
	}
	//a != const b
	template <class T>
	bool operator!=(const ft::random_iterator<T> &lhs,
					const ft::random_iterator<const T> &rhs) {
		return (lhs.base() != rhs.base());
	}
	//const a != b
	template <class T>
	bool operator!=(const ft::random_iterator<const T> &lhs,
					const ft::random_iterator<T> &rhs) {
		return (lhs.base() != rhs.base());
	}

	//a < b
	template <class T>
	bool operator<(const ft::random_iterator<T> &lhs,
					const ft::random_iterator<T> &rhs) {
		return (lhs.base() < rhs.base());
	}
	//a < const b
	template <class T>
	bool operator<(const ft::random_iterator<T> &lhs,
				   const ft::random_iterator<const T> &rhs) {
		return (lhs.base() < rhs.base());
	}
	//const a < b
	template <class T>
	bool operator<(const ft::random_iterator<const T> &lhs,
				   const ft::random_iterator<T> &rhs) {
		return (lhs.base() < rhs.base());
	}

	//a <= b
	template <class T>
	bool operator<=(const ft::random_iterator<T> &lhs,
					const ft::random_iterator<T> &rhs) {
		return (lhs.base() <= rhs.base());
	}
	//a <= const b
	template <class T>
	bool operator<=(const ft::random_iterator<T> &lhs,
					const ft::random_iterator<const T> &rhs) {
		return (lhs.base() <= rhs.base());
	}
	//const a <= b
	template <class T>
	bool operator<=(const ft::random_iterator<const T> &lhs,
					const ft::random_iterator<T> &rhs) {
		return (lhs.base() <= rhs.base());
	}

	//a > b
	template <class T>
	bool operator>(const ft::random_iterator<T> &lhs,
					const ft::random_iterator<T> &rhs) {
		return (lhs.base() > rhs.base());
	}
	//a > const b
	template <class T>
	bool operator>(const ft::random_iterator<T> &lhs,
				   const ft::random_iterator<const T> &rhs) {
		return (lhs.base() > rhs.base());
	}
	//const a > b
	template <class T>
	bool operator>(const ft::random_iterator<const T> &lhs,
				   const ft::random_iterator<T> &rhs) {
		return (lhs.base() > rhs.base());
	}

	//a >= b
	template <class T>
	bool operator>=(const ft::random_iterator<T> &lhs,
					const ft::random_iterator<T> &rhs) {
		return (lhs.base() >= rhs.base());
	}
	//a >= const b
	template <class T>
	bool operator>=(const ft::random_iterator<T> &lhs,
					const ft::random_iterator<const T> &rhs) {
		return (lhs.base() >= rhs.base());
	}
	//const a >= b
	template <class T>
	bool operator>=(const ft::random_iterator<const T> &lhs,
					const ft::random_iterator<T> &rhs) {
		return (lhs.base() >= rhs.base());
	}
}

#endif
