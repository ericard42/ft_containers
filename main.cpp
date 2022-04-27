#include <iostream>
#include "containers/vector.hpp"
#include "containers/stack.hpp"
#include <vector>

int main() {

	ft::stack<int> prout;

	prout.push(4);
	prout.push(42);
	std::cout << prout.top() << std::endl;
	prout.pop();
	std::cout << prout.top() << std::endl;
}