#include <iostream>
//#include "containers/vector.hpp"
//#include "containers/stack.hpp"
#include "utils/binary_tree.hpp"
#include "utils/binary_tree_node.hpp"
//#include <vector>

int main() {
	typedef ft::Tree<int, int> tree;
	typedef ft::treeNode<int, int> tree_node;

	tree test = tree();
	ft::pair<int, int> pair(2, 1);
	ft::pair<int, int> pair2(5, 2);
	ft::pair<int, int> pair3(42, 3);
	ft::pair<int, int> pair4(1, 4);
	ft::pair<int, int> pair5(3, 5);
	ft::pair<int, int> pair6(55, 6);


	test.add(pair);
	tree_node *n1 = test.search(2);
	//n1->printNode();

	test.add(pair2);
	tree_node *n2 = test.search(5);
	//n2->printNode();

	test.add(pair3);
	tree_node *n3 = test.search(42);
	//n3->printNode();

	test.add(pair4);
	tree_node *n4 = test.search(1);

	test.add(pair5);
	tree_node *n5 = test.search(3);

	test.add(pair6);
	tree_node *n6 = test.search(55);

	/*tree_node *n1 = test.search(2);
	tree_node *n2 = test.search(5);
	tree_node *n3 = test.search(9);
	tree_node *n4 = test.search(42);*/
	test.del(n1);

	if (n1 != NULL)
		n1->printNode();
	else
		std::cout << "\nn1 del\n" << std::endl;
	if (n2 != NULL)
		n2->printNode();
	else
		std::cout << "n2 del\n" << std::endl;
	if (n3 != NULL)
		n3->printNode();
	else
		std::cout << "\nn3 del\n" << std::endl;
	if (n4 != NULL)
		n4->printNode();
	else
		std::cout << "\nn4 del\n" << std::endl;
	if (n5 != NULL)
		n5->printNode();
	else
		std::cout << "\nn5 del\n" << std::endl;
	if (n6 != NULL)
		n6->printNode();
	else
		std::cout << "\nn6 del\n" << std::endl;
}