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

//--------------------------------

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

#define T1 int
#define T2 std::string

TESTED_NAMESPACE::map<T1, T2> mp;
TESTED_NAMESPACE::map<T1, T2>::iterator it = mp.end();

void	ft_find(T1 const &k)
{
	TESTED_NAMESPACE::map<T1, T2>::iterator ret = mp.find(k);

	if (ret != it)
		printPair(ret);
	else
		std::cout << "map::find(" << k << ") returned end()" << std::endl;
}

void	ft_count(T1 const &k)
{
	std::cout << "map::count(" << k << ")\treturned [" << mp.count(k) << "]" << std::endl;
}

int		main(void)
{
	mp[42] = "fgzgxfn";
	mp[25] = "funny";
	mp[80] = "hey";
	mp[12] = "no";
	mp[27] = "bee";
	mp[90] = "8";
	printSize(mp);

	std::cout << "\t-- FIND --" << std::endl;
	ft_find(12);
	ft_find(3);
	ft_find(35);
	ft_find(90);
	ft_find(100);

	std::cout << "\t-- COUNT --" << std::endl;
	ft_count(-3);
	ft_count(12);
	ft_count(3);
	ft_count(35);
	ft_count(90);
	ft_count(100);

	mp.find(27)->second = "newly inserted mapped_value";

	printSize(mp);

	TESTED_NAMESPACE::map<T1, T2> const c_map(mp.begin(), mp.end());
	std::cout << "const map.find(" << 42 << ")->second: [" << c_map.find(42)->second << "]" << std::endl;
	std::cout << "const map.count(" << 80 << "): [" << c_map.count(80) << "]" << std::endl;
	return (0);
}
