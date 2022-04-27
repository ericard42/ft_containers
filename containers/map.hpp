#ifndef MAP_HPP
#define MAP_HPP

#include <memory>
#include "../utils/pair.hpp"
#include "../iterators/reverse_iterator.hpp"
#include "../iterators/map_iterator.hpp"

namespace ft {
	template <class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<ft::pair<const Key, T> > >
	class map {

		public:
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
			typedef ft::map_iterator<T, Compare>			iterator;
			typedef ft::map_iterator<const T, Compare>		const_iterator;
			typedef ft::reverse_iterator<iterator>			reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;

			//Member Class
			//value_compare

			//Constructor
			//Destructor
			//Operator=
			//Get_allocator

			//Operator[]

			//Begin
			//cBegin
			//End
			//cEnd
			//rBegin
			//crBegin
			//rEnd
			//crEnd

			//Empty
			//Size
			//Max_Size

			//Clear
			//Insert
			//Erase
			//Swap

			//Count
			//Find
			//Equal_Range
			//Lower_Bound
			//Upper_Bound

			//Key_Comp
			//Value_Comp
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
