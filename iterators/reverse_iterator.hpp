#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

#include "iterator_traits.hpp"

namespace ft {

	template <class Iterator>
	class reverse_iterator {
		public :
			typedef	Iterator iterator_type;
			typedef typename iterator_traits<Iterator>::iterator_category iterator_category;
			typedef typename iterator_traits<Iterator>::value_type value_type;
			typedef typename iterator_traits<Iterator>::difference_type difference_type;
			typedef typename iterator_traits<Iterator>::pointer pointer;
			typedef typename iterator_traits<Iterator>::reference reference;

			reverse_iterator(); //Constructor
			~reverse_iterator(); //Destructor

			template <class U>
			reverse_iterator& operator=(const reverse_iterator<U>& other) {
				this->current = other.base()
				return *this;
			}
			//
			iterator_type base() const {
				return (_current);
			}
			//
			reference operator*() const {
				Iterator d_tmp = _current;
				--d_tmp;
				return *d_tmp;
			}
			pointer operator->() const {

			}
			//
			reference operator[](difference_type n) const {

			}
			//
			reverse_iterator operator+(difference_type n) const {

			}
			reverse_iterator& operator++() {

			}
			reverse_iterator operator++(int) {

			}
			reverse_iterator& operator+=(difference_type n) {

			}
			reverse_iterator operator-(difference_type n) {

			}
			reverse_iterator& operator--() {

			}
			reverse_iterator operator--(int) {

			}
			reverse_iterator& operator-=(difference_type n) {

			}

		protected :
			Iterator _current;
	};

}

#endif
