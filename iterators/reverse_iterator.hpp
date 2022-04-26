#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

#include "iterator_traits.hpp"
#include "iterator.hpp"

namespace ft {

	template <class Iterator>
	class reverse_iterator : public ft::iterator<
	        						typename ft::iterator_traits<Iterator>::iterator_category,
									typename ft::iterator_traits<Iterator>::value_type,
									typename ft::iterator_traits<Iterator>::difference_type,
									typename ft::iterator_traits<Iterator>::pointer,
									typename ft::iterator_traits<Iterator>::reference > {
		protected :
			Iterator _current;

		public :
			typedef	Iterator iterator_type;
			typedef typename ft::iterator_traits<Iterator>::reference reference;
			typedef typename ft::iterator_traits<Iterator>::pointer pointer;
			typedef typename ft::iterator_traits<Iterator>::difference_type difference_type;

			reverse_iterator() : _current() {} //Constructor
			reverse_iterator(iterator_type it) : _current(it) {} //Initialization constructor
			reverse_iterator(const reverse_iterator &rev_it) : _current(rev_it.base()) {} //Normal Copy Constructor
			template <class Iter>
			reverse_iterator(const reverse_iterator<Iter> &rev_it) : _current(rev_it.base()) {} //Other Type Copy constructor
			~reverse_iterator() {} //Destructor

			//Accesses the underlying iterator
			iterator_type base() const {
				return (_current);
			}
			//Accesses the pointed-to element
			reference operator*() const {
				iterator_type d_tmp = _current;
				d_tmp--;
				return (*d_tmp);
			}
			pointer operator->() const {
				iterator_type tmp = _current;
				tmp--;
				return (tmp.operator->());
			}
			//Accesses an element by index
			reference operator[](difference_type n) const {
				iterator_type d_tmp = (base() - n - 1);
				return (*d_tmp);
			}
			//Advances or decrements the iterator
			//a + n
			reverse_iterator operator+(difference_type n) const {
				return (reverse_iterator(_current - n));
			}
			//a++
			reverse_iterator& operator++() {
				_current--;
				return (*this);
			}
			//++a
			reverse_iterator operator++(int) {
				reverse_iterator tmp = *this;
				_current--;
				return (tmp);
			}
			//a += n
			reverse_iterator& operator+=(difference_type n) {
				_current -= n;
				return (*this);
			}
			//a - n
			reverse_iterator operator-(difference_type n) const {
				return (reverse_iterator(_current + n));
			}
			//a--
			reverse_iterator& operator--() {
				_current++;
				return (*this);
			}
			//--a
			reverse_iterator operator--(int) {
				reverse_iterator tmp = *this;
				_current++;
				return (tmp);
			}
			// a-= n
			reverse_iterator& operator-=(difference_type n) {
				_current += n;
				return (*this);
			}
	};

	//Advances the iterator
	//n + a
	template <class Iterator>
	reverse_iterator<Iterator> operator+(
			typename reverse_iterator<Iterator>::difference_type n,
			const reverse_iterator<Iterator>& rev_it) {
		return (rev_it + n);
	}
	//Calculates the distance between two iterator
	//a - b
	template <class Iterator>
	typename reverse_iterator<Iterator>::difference_type operator-(
			const reverse_iterator<Iterator>& lhs,
			const reverse_iterator<Iterator>& rhs) {
		return (rhs.base() - lhs.base());
	}
	//(const) a - b
	template <class Iterator, class Iterator2>
	typename reverse_iterator<Iterator>::difference_type operator-(
			const reverse_iterator<Iterator>& lhs,
			const reverse_iterator<Iterator2>& rhs) {
		return (rhs.base() - lhs.base());
	}

	//Relational Operators
	//a == b
	template <class Iterator>
	bool operator==(const reverse_iterator<Iterator>& lhs,
					const reverse_iterator<Iterator>& rhs) {
		return (lhs.base() == rhs.base());
	}
	//(const) a == b
	template <class Iterator, class Iterator2>
	bool operator==(const reverse_iterator<Iterator>& lhs,
					const reverse_iterator<Iterator2>& rhs) {
		return (lhs.base() == rhs.base());
	}

	//a != b
	template <class Iterator>
	bool operator!=(const reverse_iterator<Iterator>& lhs,
					 const reverse_iterator<Iterator>& rhs) {
		return (lhs.base() != rhs.base());
	}
	//(const) a != b
	template <class Iterator, class Iterator2>
	bool operator!=(const reverse_iterator<Iterator>& lhs,
					const reverse_iterator<Iterator2>& rhs) {
		return (lhs.base() != rhs.base());
	}

	//a < b
	template <class Iterator>
	bool operator<(const reverse_iterator<Iterator>& lhs,
					const reverse_iterator<Iterator>& rhs) {
		return (lhs.base() > rhs.base());
	}
	//(const) a < b
	template <class Iterator, class Iterator2>
	bool operator<(const reverse_iterator<Iterator>& lhs,
				   const reverse_iterator<Iterator2>& rhs) {
		return (lhs.base() > rhs.base());
	}

	//a <= b
	template <class Iterator>
	bool operator<=(const reverse_iterator<Iterator>& lhs,
					 const reverse_iterator<Iterator>& rhs) {
		return (lhs.base() >= rhs.base());
	}
	//(const) a <= b
	template <class Iterator, class Iterator2>
	bool operator<=(const reverse_iterator<Iterator>& lhs,
					const reverse_iterator<Iterator2>& rhs) {
		return (lhs.base() >= rhs.base());
	}

	//a > b
	template <class Iterator>
	bool operator>(const reverse_iterator<Iterator>& lhs,
					const reverse_iterator<Iterator>& rhs) {
		return (lhs.base() < rhs.base());
	}
	//(const) a > b
	template <class Iterator, class Iterator2>
	bool operator>(const reverse_iterator<Iterator>& lhs,
				   const reverse_iterator<Iterator2>& rhs) {
		return (lhs.base() < rhs.base());
	}

	//a >= b
	template <class Iterator>
	bool operator>=(const reverse_iterator<Iterator>& lhs,
					 const reverse_iterator<Iterator>& rhs) {
		return (lhs.base() <= rhs.base());
	}
	//(const) a >= b
	template <class Iterator, class Iterator2>
	bool operator>=(const reverse_iterator<Iterator>& lhs,
					const reverse_iterator<Iterator2>& rhs) {
		return (lhs.base() <= rhs.base());
	}

}

#endif
