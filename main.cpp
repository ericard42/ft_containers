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


#include <list>

#define T1 int
#define T2 int
typedef _pair<const T1, T2> T3;

int		main(void)
{
	std::list<T3> lst;
	unsigned int lst_size = 7;
	for (unsigned int i = 0; i < lst_size; ++i)
		lst.push_back(T3(lst_size - i, i));

	TESTED_NAMESPACE::map<T1, T2> mp(lst.begin(), lst.end());
	TESTED_NAMESPACE::map<T1, T2>::iterator it = mp.begin(), ite = mp.end();

	TESTED_NAMESPACE::map<T1, T2> mp_range(it, --(--ite));
	for (int i = 0; it != ite; ++it)
		it->second = ++i * 5;

	it = mp.begin(); ite = --(--mp.end());
	TESTED_NAMESPACE::map<T1, T2> mp_copy(mp);
	for (int i = 0; it != ite; ++it)
		it->second = ++i * 7;

	std::cout << "\t-- PART ONE --" << std::endl;
	printSize(mp);
	printSize(mp_range);
	printSize(mp_copy);

	mp = mp_copy;
	mp_copy = mp_range;
	mp_range.clear();

	std::cout << "\t-- PART TWO --" << std::endl;
	printSize(mp);
	printSize(mp_range);
	printSize(mp_copy);
	return (0);
}
