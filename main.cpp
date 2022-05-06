#include <iostream>
//#include "containers/vector.hpp"
//#include "containers/stack.hpp"
//#include "utils/binary_tree.hpp"
//#include "utils/binary_tree_node.hpp"
#include "containers/map.hpp"
#include "utils/pair.hpp"
//#include <vector>

int main2() {
	ft::Tree<int, int> arbre;
	//arbre.add(ft::make_pair(42, 2));
	//arbre.add(ft::make_pair(1, 4));
	//arbre.add(ft::make_pair(4, 5));

	ft::Tree<int, int> arbre2;
	arbre2 = arbre;
	return 0;
}

int main3() {
	ft::map<char, int> first;

	first['a'] = 10;
	first['b'] = 42;
	first['c'] = 84;

	ft::map<char, int> second = first;
	ft::map<char, int>::iterator it1 = first.begin();
	ft::map<char, int>::iterator it2 = second.begin();

	for (; it1 != first.end() ; it1++)
		it1.base()->printNode();
	for (; it2 != second.end() ; it2++)
		it2.base()->printNode();
	return 0;
}

#include "containers/containers_test/srcs/map/../base.hpp"
#if !defined(USING_STD)
# include "containers/map.hpp"
#else
# include <map>
#endif /* !defined(STD) */

#define _pair TESTED_NAMESPACE::pair

template <typename T>
std::string	printPair(const T &iterator, bool nl = true, std::ostream &o = std::cout)
{
	o << "key: " << iterator->first << " | value: " << iterator->second;
	if (nl)
		o << std::endl;
	return ("");
}

template <typename T_MAP>
void	printSize(T_MAP const &mp, bool print_content = 1)
{
	std::cout << "size: " << mp.size() << std::endl;
	//std::cout << "max_size: " << mp.max_size() << std::endl;
	if (print_content)
	{
		typename T_MAP::const_iterator it = mp.begin(), ite = mp.end();
		std::cout << std::endl << "Content is:" << std::endl;
		for (; it != ite; ++it)
			std::cout << "- " << printPair(it, false) << std::endl;
	}
	std::cout << "###############################################" << std::endl;
}

template <typename T1, typename T2>
void	printReverse(TESTED_NAMESPACE::map<T1, T2> &mp)
{
	typename TESTED_NAMESPACE::map<T1, T2>::iterator it = mp.end(), ite = mp.begin();

	std::cout << "printReverse:" << std::endl;
	while (it != ite) {
		it--;
		std::cout << "-> " << printPair(it, false) << std::endl;
	}
	std::cout << "_______________________________________________" << std::endl;
}

//--------------------------------//--------------------------------

#include <list>

#define T1 int
#define T2 std::string
typedef TESTED_NAMESPACE::map<T1, T2>::value_type T3;

static int iter = 0;

template <typename MAP, typename U>
void	ft_insert(MAP &mp, U param, U param2)
{
	std::cout << "\t-- [" << iter++ << "] --" << std::endl;
	mp.insert(param, param2);
	printSize(mp);
}

int		main(void)
{
	std::list<T3> lst;
	std::list<T3>::iterator itlst;

	lst.push_back(T3(42, "lol"));

	lst.push_back(T3(50, "mdr"));
	lst.push_back(T3(35, "funny"));

	lst.push_back(T3(45, "bunny"));
	lst.push_back(T3(21, "fizz"));
	lst.push_back(T3(38, "buzz"));
	lst.push_back(T3(55, "fuzzy"));

	std::cout << "List contains:" << std::endl;
	for (itlst = lst.begin(); itlst != lst.end(); ++itlst)
		printPair(itlst);

	TESTED_NAMESPACE::map<T1, T2> mp;
	ft_insert(mp, lst.begin(), lst.end());

	lst.clear();

	lst.push_back(T3(87, "hey"));
	lst.push_back(T3(47, "eqweqweq"));
	lst.push_back(T3(35, "this key is already inside"));
	lst.push_back(T3(23, "but not that one"));
	lst.push_back(T3(1, "surprising isnt it?"));
	lst.push_back(T3(100, "is it enough??"));
	lst.push_back(T3(55, "inside map too"));

	std::cout << "List contains:" << std::endl;
	for (itlst = lst.begin(); itlst != lst.end(); ++itlst)
		printPair(itlst);

	ft_insert(mp, lst.begin(), lst.begin());
	ft_insert(mp, lst.begin(), lst.end());

	return (0);
}