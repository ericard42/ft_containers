#ifndef MAP_HPP
#define MAP_HPP

#include <memory>
#include <functional>
#include "../utils/lexicographical_compare.hpp"
#include "../utils/equal.hpp"
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
			typedef Key																		key_type;
			typedef T																		mapped_type;
			typedef	ft::pair<const Key, T>													value_type;
			typedef size_t																	size_type;
			typedef ptrdiff_t																difference_type;
			typedef Compare																	key_compare;
			typedef Allocator																allocator_type;
			typedef typename allocator_type::reference										reference;
			typedef typename allocator_type::const_reference								const_reference;
			typedef typename allocator_type::pointer										pointer;
			typedef typename allocator_type::const_pointer									const_pointer;
			typedef typename ft::map_iterator<treeNode<Key, T>, Key, T, Compare>			iterator;
			typedef typename ft::const_map_iterator<treeNode<Key, T>, Key, T, Compare>		const_iterator;
			typedef typename ft::reverse_iterator<iterator>									reverse_iterator;
			typedef typename ft::reverse_iterator<const_iterator>							const_reverse_iterator;

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
						return (comp(x.first, y.first));
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
					insert(*first++);
			}
			map (const map &x) {
				*this = x;
			}
			//Destructor
			~map() {

			}
			//Operator=
			map &operator=(const map &src) {
				clear();
				_alloc = src._alloc;
				_comp = src._comp;

				for (const_iterator it = src.begin() ; it != src.end() ; it++)
					insert(*it);
				//_tree.setOrigin(_tree.treeCopy(src._tree.getOrigin()));
				return (*this);
			}

			//Begin
			iterator begin() {
				iterator it = iterator(&_tree, _tree.getBegin());
				return (it);
			}
			const_iterator begin() const {
				const_iterator it = const_iterator(&_tree, _tree.getBegin());
				return (it);
			}
			//End
			iterator end() {
				iterator it = iterator(&_tree, _tree.getEnd());
				it++;
				return (it);
			}
			const_iterator end() const {
				const_iterator it = const_iterator(&_tree, _tree.getEnd());
				it++;
				return (it);
			}
			//rBegin
			reverse_iterator rbegin() {
				reverse_iterator it = reverse_iterator(iterator(&_tree, _tree.getEnd()));
				return (it);
			}
			const_reverse_iterator rbegin() const {
				const_reverse_iterator it = const_reverse_iterator(const_iterator(&_tree, _tree.getEnd()));
				return (it);
			}
			//rEnd
			reverse_iterator rend() {
				reverse_iterator it = reverse_iterator(iterator(&_tree, _tree.getBegin()));
				it++;
				return (it);
			}
			const_reverse_iterator rend() const {
				const_reverse_iterator it = const_reverse_iterator(const_iterator(&_tree, _tree.getBegin()));
				it++;
				return (it);
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
				return (_tree.maxSize());
			}

			//Operator[]
			mapped_type &operator[] (const key_type &k) {
				node cur = _tree.search(k);
				if (cur == NULL)
					cur = _tree.add(ft::make_pair(k, mapped_type()));
				return (cur->getValue());
			}

			//Clear
			void clear() {
				if (_tree.getOrigin() != NULL)
					_tree.treeDelete(_tree.getOrigin());
				_tree.setOrigin(NULL);
			}
			//Insert
			pair<iterator, bool> insert (const value_type &val) {
				node cur = _tree.search(val.first);
				if (cur != NULL)
					return (ft::make_pair(iterator(&_tree, cur), false));
				value_type pair;
				_alloc.construct(&pair, val);
				cur = _tree.add(pair);
				return (ft::make_pair(iterator(&_tree, cur), true));
			}
			iterator insert(iterator position, const value_type &val) {
				(void)position;
				return (insert(val).first);
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
				node cur = position.base();
				_tree.del(cur);
			}
			size_type erase(const key_type &k) {
				node cur = _tree.search(k);
				if (cur == NULL)
					return (0);
				_tree.del(cur);
				return (1);
			}
			void erase(iterator first, iterator last) {
				node cur;
				while (first != last)
				{
					cur = first.base();
					_tree.del(cur);
					first++;
				}
			}
			//Swap
			void swap (map &x) {
				if (x == *this)
					return ;
				map tmp = x;
				x = *this;
				*this = tmp;
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
				return (0);
			}
			//Find
			iterator find(const key_type &k) {
				return (iterator(&_tree, _tree.search(k)));
			}
			const_iterator find(const key_type &k) const {
				return (const_iterator(&_tree, _tree.search(k)));
			}
			//Equal_Range
			pair<iterator, iterator> equal_range(const key_type &k) {
				return (ft::make_pair(lower_bound(k), upper_bound(k)));

			}
			pair<const_iterator, const_iterator> equal_range(const key_type &k) const {
				return (ft::make_pair(lower_bound(k), upper_bound(k)));

			}
			//Lower_Bound
			iterator lower_bound(const key_type &k) {
				iterator it = begin();
				while (it != end() && _comp(it->first, k))
					it++;
				return (it);
			}
			const_iterator lower_bound(const key_type &k) const {
				const_iterator it = begin();
				while (it != end() && _comp(it->first, k))
					it++;
				return (it);
			}
			//Upper_Bound
			iterator upper_bound(const key_type &k) {
				iterator it = begin();
				while (it != end() && _comp(k, it->first) == false)
					it++;
				return (it);
			}
			const_iterator upper_bound(const key_type &k) const {
				const_iterator it = begin();
				while (it != end() && _comp(k, it->first) == false)
					it++;
				return (it);
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
		if (lhs.size() != rhs.size())
			return (false);
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
		return(ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
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

	//Swap
	template <class Key, class T, class Compare, class Alloc>
	void swap(map<Key, T, Compare, Alloc> &x, map<Key, T, Compare, Alloc> &y) {
		x.swap(y);
	}
}

#endif
