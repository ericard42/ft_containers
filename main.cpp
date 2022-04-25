#include <iostream>
#include "containers/vector.hpp"

int main(){
	ft::vector<int> prout(2, 4);
	for (size_t i = 0; i < prout.size(); i++)
		std::cout << prout.at(i) << std::endl;
	std::cout << "Au moins ça compile..?" << std::endl;
}