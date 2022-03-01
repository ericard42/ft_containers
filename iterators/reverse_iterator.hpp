#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

#include "iterator_traits.hpp"

namespace ft {

	template <class Iterator>
	class reverse_iterator : public ft::iterator<
	        						typename ft::iterator_traits<Iterator>::iterator_category,
									typename ft::iterator_traits<Iterator>::value_type,
									typename ft::iterator_traits<Iterator>::difference_type,
									typename ft::iterator_traits<Iterator>::pointer,
									typename ft::iterator_traits<Iterator>::reference > {
		public :
			typedef	Iterator iterator_type;
			typedef typename ft::iterator_traits<Iterator>::iterator_category iterator_category;
			typedef typename ft::iterator_traits<Iterator>::value_type value_type;
			typedef typename ft::iterator_traits<Iterator>::difference_type difference_type;
			typedef typename ft::iterator_traits<Iterator>::pointer pointer;
			typedef typename ft::iterator_traits<Iterator>::reference reference;

			reverse_iterator() {} //Constructor
			explicit reverse_iterator(iterator_type it) : _current(iterator_type(it)){} //Initialization constructor
			template <class Iter>
			reverse_iterator(const reverse_iterator<Iter>& rev_it) {*this = rev_it;} //Copy constructor
			~reverse_iterator() {} //Destructor

			//Accesses the underlying iterator
			iterator_type base() const {
				return (_current);
			}
			//Accesses the pointed-to element
			reference operator*() const {
				Iterator d_tmp = base();
				--d_tmp;
				return *d_tmp;
			}
			pointer operator->() const {
				return &(operator*());
			}
			//Accesses an element by index
			reference operator[](difference_type n) const {
				Iterator d_tmp = base() - n;
				return *d_tmp;
			}
			//Advances or decrements the iterator
			reverse_iterator operator+(difference_type n) const {
				return (reverse_iterator(_current - n));
			}
			reverse_iterator& operator++() {
				_current--;
				return *this;
			}
			reverse_iterator operator++(int) {
				reverse_iterator tmp = *this;
				_current--;
				return tmp;
			}
			reverse_iterator& operator+=(difference_type n) {
				_current -= n;
				return *this;
			}
			reverse_iterator operator-(difference_type n) {
				return (reverse_iterator(_current + n));
			}
			reverse_iterator& operator--() {
				_current++;
				return *this;
			}
			reverse_iterator operator--(int) {
				reverse_iterator tmp = *this;
				_current++;
				return tmp;
			}
			reverse_iterator& operator-=(difference_type n) {
				_current += n;
				return *this;
			}

		protected :
			Iterator _current;
	};

	//Advances the iterator
	template <class Iterator>
	reverse_iterator<Iterator> operator+ (
			typename reverse_iterator<Iterator>::difference_type n,
			const reverse_iterator<Iterator>& rev_it) {
		return rev_it - n;
	}
	//Computes the distance between two iterator adaptors
	template <class Iterator>
	typename reverse_iterator<Iterator>::difference_type operator- (
			const reverse_iterator<Iterator>& lhs,
			const reverse_iterator<Iterator>& rhs) {
		return lhs.base() - rhs.base();
	}
	//Relational Operators
	template <class Iterator>
	bool operator== (const reverse_iterator<Iterator>& lhs,
					const reverse_iterator<Iterator>& rhs) {
		return lhs.base() == rhs.base();
	}
	template <class Iterator>
	bool operator!= (const reverse_iterator<Iterator>& lhs,
					 const reverse_iterator<Iterator>& rhs) {
		return lhs.base() != rhs.base();
	}
	template <class Iterator>
	bool operator< (const reverse_iterator<Iterator>& lhs,
					const reverse_iterator<Iterator>& rhs) {
		return lhs.base() > rhs.base();
	}
	template <class Iterator>
	bool operator<= (const reverse_iterator<Iterator>& lhs,
					 const reverse_iterator<Iterator>& rhs) {
		return lhs.base() >= rhs.base();
	}
	template <class Iterator>
	bool operator> (const reverse_iterator<Iterator>& lhs,
					const reverse_iterator<Iterator>& rhs) {
		return lhs.base() < rhs.base();
	}
	template <class Iterator>
	bool operator>= (const reverse_iterator<Iterator>& lhs,
					 const reverse_iterator<Iterator>& rhs) {
		return lhs.base <= rhs.base();
	}
}

#endif
