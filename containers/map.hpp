#ifndef MAP_HPP
#define MAP_HPP

#include <memory>
#include <functional>
#include "../utils/type_traits.hpp"
#include "../utils/pair.hpp"
#include "../iterators/reverse_iterator.hpp"
#include "../iterators/map_iterator.hpp"
#include "../utils/binary_tree_node.hpp"
#include "../utils/binary_tree.hpp"

namespace ft {
	template <class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<ft::pair<const Key, T> > >
	class map {

		public:
			//Member Types
			typedef Key										key_type;
			typedef T										mapped_type;
			typedef	ft::pair<const Key, T>					value_type;
			typedef size_t									size_type;
			typedef ptrdiff_t								difference_type;
			typedef Compare									key_compare;
			typedef Allocator								allocator_type;
			typedef Allocator::reference					reference;
			typedef Allocator::const_reference				const_reference;
			typedef Allocator::pointer						pointer;
			typedef Allocator::const_pointer				const_pointer;
			typedef ft::Tree<Key, T>::iterator 				iterator;
			typedef ft::Tree<Key, T>::const_iterator		const_iterator;
			typedef ft::reverse_iterator<iterator>			reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;

			//Constructor
			explicit map (const key_compare &comp = key_compare(),
						  const allocator_type &alloc = allocator_type()) {

			}
			template <class InputIterator>
			map (typename ft::enable_if<!(ft::is_integral<InputIterator>::value), InputIterator>::type first,
				 					InputIterator last, const key_compare &comp = key_compare(),
									 const allocator_type &alloc = allocator_type()) {

			}
			map (const map &x) {

			}
			//Destructor
			~map() {

			}
			//Operator=
			map &operator=(const map &src) {

			}

			//Begin
			iterator begin() {

			}
			const_iterator begin() const {

			}
			//End
			iterator end() {

			}
			const_iterator end() const {

			}
			//rBegin
			reverse_iterator rbegin() {

			}
			const_reverse_iterator rbegin() const {

			}
			//rEnd
			reverse_iterator rend() {

			}
			const_reverse_iterator rend() const {

			}

			//Empty
			bool empty() const {

			}
			//Size
			size_type size() const {

			}
			//Max_Size
			size_type max_size() const {

			}

			//Operator[]
			mapped_type &operator[] (const key_type &k) {

			}

			//Clear
			void clear() {

			}
			//Insert
			pair<iterator, bool> insert (const value_type &val) {

			}
			iterator insert(iterator position, const value_type &val) {

			}
			template <class InputIterator>
			void insert (typename ft::enable_if<!(ft::is_integral<InputIterator>::value), InputIterator>::type first, InputIterator last) {

			}
			//Erase
			void erase(iterator position) {

			}
			size_type erase(const key_type &k) {

			}
			void erase(iterator first, iterator last) {

			}
			//Swap
			void swap (map &x) {

			}

			//Key_Comp
			key_compare key_comp() const {

			}
			//Value_Comp
			value_compare value_comp() const {

			}

			//Count
			size_type count(const key_type &k) const {

			}
			//Find
			iterator find(const key_type &k) {

			}
			const_iterator find(const key_type &k) const {

			}
			//Equal_Range
			pair<const_iterator, const_iterator> equal_range(const key_type &k) const {

			}
			pair<iterator, iterator> equal_range(const key_type &k) {

			}
			//Lower_Bound
			iterator lower_bound(const key_type &k) {

			}
			const_iterator lower_bound(const key_type &k) const {

			}
			//Upper_Bound
			iterator upper_bound(const key_type &k) {

			}
			const_iterator upper_bound(const key_type &k) const {

			}

			//Get_allocator
			allocator_type get_allocator() const {

			}

		private :
			allocator_type						_alloc;
			Tree<key_type, value_type, Compare> _tree;
			//Compare							_comp;
	};

	//Operator==
	//Operator!=
	//Operator<
	//Operator<=
	//Operator>
	//Operator>=

	//ft::swap
}

#endif
