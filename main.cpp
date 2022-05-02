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

int main() {
	ft::map<char, int> first;

	first['a'] = 10;
	first['b'] = 42;
	std::cout << first.size() << std::endl;
	ft::map<char, int>::iterator it = first.find('a');
	std::cout << it.base() << std::endl;
	ft::pair<char, int> pair = *it;
	std::cout << pair.second << std::endl;
	return 0;
}