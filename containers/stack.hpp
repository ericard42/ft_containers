#ifndef STACK_HPP
#define STACK_HPP

#include "vector.hpp"

namespace ft {
	template <class T, class Container = vector<T> >
	class stack {
		public :
			//Member Type
			typedef T								value_type;
			typedef Container						container_type;
			typedef container_type::reference		reference;
			typedef container_type::const_reference	const_reference;
			typedef size_t							size_type;

			//Constructor
			//Destructor
			//Operator=

			//Empty

			//Size

			//Top

			//Push

			//Pop

		protected :
			container_type c;

	};
}

//Relational Operators
//Operator==
//Operator!=
//Operator<
//Operator<=
//Operator>
//Operator>=


#endif
