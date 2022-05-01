#ifndef MAP_HPP
#define MAP_HPP

#include <memory>
#include <functional>
#include "../utils/lexicographical_compare.hpp"
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
			typedef Key												key_type;
			typedef T												mapped_type;
			typedef	ft::pair<const Key, T>							value_type;
			typedef size_t											size_type;
			typedef ptrdiff_t										difference_type;
			typedef Compare											key_compare;
			typedef Allocator										allocator_type;
			typedef typename allocator_type ::reference				reference;
			typedef typename allocator_type ::const_reference		const_reference;
			typedef typename allocator_type ::pointer				pointer;
			typedef typename allocator_type ::const_pointer			const_pointer;
			typedef typename ft::Tree<Key, T>::iterator 			iterator;
			typedef typename ft::Tree<Key, T>::const_iterator		const_iterator;
			typedef typename ft::reverse_iterator<iterator>			reverse_iterator;
			typedef typename ft::reverse_iterator<const_iterator>	const_reverse_iterator;

			class value_compare : std::binary_function<value_type, value_compare, bool> {
					friend class map;

				protected:
					Compare comp;
					value_compare(Compare c) : comp(c) {}

				public:
					typedef bool			result_type;
					typedef value_type		first_argument_type;
					typedef value_type		second_argument_type;
					result_type operator() (const first_argument_type &x,
											const second_argument_type &y) const {
						return (x.first, y.first);
					}
			};

			//Constructor
			explicit map (const key_compare &comp = key_compare(),
						  const allocator_type &alloc = allocator_type()) : _alloc(alloc),
						  													_comp(comp),
																			_tree(tree()){
			}
			template <class InputIterator>
			map (typename ft::enable_if<!(ft::is_integral<InputIterator>::value), InputIterator>::type first,
				 					InputIterator last, const key_compare &comp = key_compare(),
									 const allocator_type &alloc = allocator_type()) : _alloc(alloc),
									 													_comp(comp),
																						 _tree(tree()) {
				value_type tmp;
				while (first != last)
				{
					_alloc.construct(&tmp, *first++);
					_tree.add(tmp);
				}
			}
			map (const map &x) {
				*this = x;
			}
			//Destructor
			~map() {

			}
			//Operator=
			map &operator=(const map &src) {
				//TODO Do Operator = for Map
			}

			//Begin
			iterator begin() {
				return (iterator(_tree, _tree.getBegin()));
			}
			const_iterator begin() const {
				return (const_iterator(_tree, _tree.getBegin()));
			}
			//End
			iterator end() {
				return (iterator(_tree, _tree.getEnd())++);
			}
			const_iterator end() const {
				return (iterator(_tree, _tree.getEnd())++)
			}
			//rBegin
			reverse_iterator rbegin() {
				return (reverse_iterator(_tree, _tree.getEnd()));
			}
			const_reverse_iterator rbegin() const {
				return (const_reverse_iterator(_tree, _tree.getEnd()));
			}
			//rEnd
			reverse_iterator rend() {
				return (reverse_iterator(_tree, _tree.getBegin())--);
			}
			const_reverse_iterator rend() const {
				return (const_reverse_iterator(_tree, _tree.getBegin())--);
			}

			//Empty
			bool empty() const {
				return (_tree.getOrigin() == NULL);
			}
			//Size
			size_type size() const {
				return (_tree.getSize());
			}
			//Max_Size
			size_type max_size() const {
				return (allocator_type().max_size);
			}

			//Operator[]
			mapped_type &operator[] (const key_type &k) {
				return (_tree.search(k)->getValue());
			}

			//Clear
			void clear() {
				node cur = _tree.getBegin();
				node cur_next;
				while (cur != NULL)
				{
					cur_next = _tree.next(cur);
					_tree.del(cur);
					cur = cur_next;
				}

			}
			//Insert
			pair<iterator, bool> insert (const value_type &val) {
				value_type pair;
				_alloc.construct(&pair, val);
				_tree.add(pair);
				//TODO Return Insert
			}
			iterator insert(iterator position, const value_type &val) {
				//TODO Insert with position
			}
			template <class InputIterator>
			void insert (typename ft::enable_if<!(ft::is_integral<InputIterator>::value), InputIterator>::type first, InputIterator last) {
				value_type pair;
				while (first != last)
				{
					_alloc.construct(&pair, *first++);
					_tree.add(pair);
				}
			}
			//Erase
			void erase(iterator position) {
				_tree.del(&(*position));
			}
			size_type erase(const key_type &k) {
				_tree.del(_tree.search(k));
			}
			void erase(iterator first, iterator last) {
				while (first != last)
				{
					_tree.del(&(*first));
					first++;
				}
			}
			//Swap
			void swap (map &x) {
				//TODO swap
			}

			//Key_Comp
			key_compare key_comp() const {
				return (key_compare());
			}
			//Value_Comp
			value_compare value_comp() const {
				return (value_compare(Compare()));
			}

			//Count
			size_type count(const key_type &k) const {
				if (_tree.search(k) != NULL)
					return (1);
				return (0)
			}
			//Find
			iterator find(const key_type &k) {
				return (iterator(_tree.search(k)));
			}
			const_iterator find(const key_type &k) const {
				return (const_iterator(_tree.search(k)));
			}
			//Equal_Range
			pair<iterator, iterator> equal_range(const key_type &k) {
				iterator it = _tree.search(k);
				//TODO return equal_range
			}
			pair<const_iterator, const_iterator> equal_range(const key_type &k) const {
				const_iterator it = _tree.search(k);
				//TODO return equal_range
			}
			//Lower_Bound
			iterator lower_bound(const key_type &k) {
				//TODO lower_bound
			}
			const_iterator lower_bound(const key_type &k) const {
				//TODO lower_bound
			}
			//Upper_Bound
			iterator upper_bound(const key_type &k) {
				//TODO upper_bound
			}
			const_iterator upper_bound(const key_type &k) const {
				//TODO upper_bound
			}

			//Get_allocator
			allocator_type get_allocator() const {
				return (allocator_type());
			}

		protected :
			typedef Tree<Key, T, Compare>					tree;
			typedef typename treeNode<Key, T>::pointer 		node;

			allocator_type						_alloc;
			Compare								_comp;
			tree								_tree;
	};

	//Operator==
	template <class Key, class T, class Compare, class Alloc>
	bool operator==(const map<Key, T, Compare, Alloc> &lhs,
					const map<Key, T, Compare, Alloc> &rhs) {
		return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}
	//Operator!=
	template <class Key, class T, class Compare, class Alloc>
	bool operator!=(const map<Key, T, Compare, Alloc> &lhs,
					const map<Key, T, Compare, Alloc> &rhs) {
		return (!(lhs == rhs));
	}
	//Operator<
	template <class Key, class T, class Compare, class Alloc>
	bool operator<(const map<Key, T, Compare, Alloc> &lhs,
					const map<Key, T, Compare, Alloc> &rhs) {
		return(ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end));
	}
	//Operator<=
	template <class Key, class T, class Compare, class Alloc>
	bool operator<=(const map<Key, T, Compare, Alloc> &lhs,
					const map<Key, T, Compare, Alloc> &rhs) {
		return (!(rhs < lhs));
	}
	//Operator>
	template <class Key, class T, class Compare, class Alloc>
	bool operator>(const map<Key, T, Compare, Alloc> &lhs,
					const map<Key, T, Compare, Alloc> &rhs) {
		return (rhs < lhs);
	}
	//Operator>=
	template <class Key, class T, class Compare, class Alloc>
	bool operator>=(const map<Key, T, Compare, Alloc> &lhs,
					const map<Key, T, Compare, Alloc> &rhs) {
		return (!(lhs < rhs));
	}

	//ft::swap
}

#endif
