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
			typedef size_t							size_type;

			//Constructor
			explicit stack(const container_type &cont = container_type()) : c(cont) {

			}
			//Destructor
			~stack() {

			}
			//Operator=
			stack &operator=(const stack &other) {
				return (c = other.c);
			}

			//Empty
			bool empty() {
				return (c.empty());
			}

			//Size
			size_type size() {
				return (c.size());
			}

			//Top
			value_type &top() {
				return (c.back());
			}
			const value_type &top() const {
				return (c.back());
			}

			//Push
			void push(value_type value) {
				c.push_back(value);
			}

			//Pop
			void pop() {
				c.pop_back();
			}

			template <class Tf, class Containerf>
			friend bool operator==(const stack<Tf, Containerf> &lhs, const stack<Tf, Containerf> &rhs);
			template <class Tf, class Containerf>
			friend bool operator<(const stack<Tf, Containerf> &lhs, const stack<Tf, Containerf> &rhs);

		protected :
			container_type c;

	};

	//Relational Operators
	//Operator==
	template <class T, class Container>
	bool operator==(const stack<T, Container> &lhs, const stack<T, Container> &rhs) {
		return (lhs.c == rhs.c);
	}
	//Operator!=
	template <class T, class Container>
	bool operator!=(const stack<T, Container> &lhs, const stack<T, Container> &rhs) {
		return (!(lhs == rhs));
	}
	//Operator<
	template <class T, class Container>
	bool operator<(const stack<T, Container> &lhs, const stack<T, Container> &rhs) {
		return (lhs.c < rhs.c);
	}
	//Operator<=
	template <class T, class Container>
	bool operator<=(const stack<T, Container> &lhs, const stack<T, Container> &rhs) {
		return (!(rhs < lhs));
	}
	//Operator>
	template <class T, class Container>
	bool operator>(const stack<T, Container> &lhs, const stack<T, Container> &rhs) {
		return (rhs < lhs);
	}
	//Operator>=
	template <class T, class Container>
	bool operator>=(const stack<T, Container> &lhs, const stack<T, Container> &rhs) {
		return (!(lhs < rhs));
	}

}


#endif
