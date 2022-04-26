#include <iostream>
#include "containers/vector.hpp"
#include <vector>

int main() {

	{
		ft::vector<int> prout(0);
		//for (int i = 0; i < 6; i++)
		//	prout.push_back(i + 1);
		ft::vector<int>::iterator poulet;
		poulet = prout.begin();
		prout.insert(poulet, 3,42);
		for (size_t i = 0; i < prout.size(); i++)
			std::cout << prout.at(i) << std::endl;
		std::cout << prout.capacity() << std::endl;
	}
	{
		std::cout << std::endl;
		std::vector<int> prout(0);
		//for (int i = 0; i < 6; i++)
		//	prout.push_back(i+1);
		std::vector<int>::iterator poulet;
		poulet = prout.begin();
		prout.insert(poulet, 3, 42);
		for (size_t i = 0; i < prout.size(); i++)
			std::cout << prout.at(i) << std::endl;
		std::cout << prout.capacity() << std::endl;

	}
}