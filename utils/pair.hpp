#ifndef PAIR_HPP
#define PAIR_HPP

namespace ft {
	template <class T1, class T2>
	struct pair {
		//Member Types
		typedef T1 first_type;
		typedef T2 second_type;

		//Constructors
		pair() : first(first_type()), second(second_type()) {}
		pair(const first_type &x, const second_type &y) : first(x), second(y) {}

		template <class U1, class U2>
		pair(const pair<U1, U2> &p) : first(p.first), second(p.second){}

		//Operator=
		/*pair &operator=(const pair &other) {
			first = other.first;
			second = other.second;
			return (*this);
		}*/

		//Member objects
		first_type first;
		second_type second;
	};

	//Operator==
	template <class T1, class T2>
	bool operator==(const ft::pair<T1, T2> &lhs, const ft::pair<T1, T2> &rhs) {
		return ((lhs.first == rhs.first) && (lhs.second == rhs.second));
	}

	//Operator!=
	template <class T1, class T2>
	bool operator!=(const ft::pair<T1, T2> &lhs, const ft::pair<T1, T2> &rhs) {
		return (!(lhs == rhs));
	}

	//Operator<
	template <class T1, class T2>
	bool operator<(const ft::pair<T1, T2> &lhs, const ft::pair<T1, T2> &rhs) {
		if (lhs.first < rhs.first)
			return (true);
		else if (rhs.first < lhs.first)
			return (false);
		else if (lhs.second < rhs.second)
			return (true);
		return (false);
	}

	//Operator<=
	template <class T1, class T2>
	bool operator<=(const ft::pair<T1, T2> &lhs, const ft::pair<T1, T2> &rhs) {
		return (!(rhs < lhs));
	}

	//Operator>
	template <class T1, class T2>
	bool operator>(const ft::pair<T1, T2> &lhs, const ft::pair<T1, T2> &rhs) {
		return (rhs < lhs);
	}

	//Operator>=
	template <class T1, class T2>
	bool operator>=(const ft::pair<T1, T2> &lhs, const ft::pair<T1, T2> &rhs) {
		return (!(lhs < rhs));
	}

	//Make_Pair
	template <class T1, class T2>
	pair<T1, T2> make_pair(T1 x, T2 y) {
		return (pair<T1, T2>(x, y));
	}
}

#endif