#include <iostream>
#include "containers/vector.hpp"
//#include "containers/stack.hpp"
#include "utils/binary_tree.hpp"
#include "utils/binary_tree_node.hpp"
#include "containers/map.hpp"
//#include "utils/pair.hpp"
//#include <vector>

#include "containers/containers_test/srcs/base.hpp"
#if !defined(USING_STD)
# include "containers/vector.hpp"
#else
# include <vector>
#endif /* !defined(STD) */

#define T_SIZE_TYPE typename TESTED_NAMESPACE::vector<T>::size_type

template <typename T>
void	printSize(TESTED_NAMESPACE::vector<T> const &vct, bool print_content = true)
{
const T_SIZE_TYPE size = vct.size();
const T_SIZE_TYPE capacity = vct.capacity();
const std::string isCapacityOk = (capacity >= size) ? "OK" : "KO";
// Cannot limit capacity's max value because it's implementation dependent

std::cout << "size: " << size << std::endl;
std::cout << "capacity: " << isCapacityOk << std::endl;
std::cout << "max_size: " << vct.max_size() << std::endl;
if (print_content)
{
typename TESTED_NAMESPACE::vector<T>::const_iterator it = vct.begin();
typename TESTED_NAMESPACE::vector<T>::const_iterator ite = vct.end();
std::cout << std::endl << "Content is:" << std::endl;
for (; it != ite; ++it)
std::cout << "- " << *it << std::endl;
}
std::cout << "###############################################" << std::endl;
}

//------------------------------------------

#define TESTED_TYPE int

int		main(void)
{
	TESTED_NAMESPACE::vector<TESTED_TYPE> vct(10);
	TESTED_NAMESPACE::vector<TESTED_TYPE> vct2;

	for (unsigned long int i = 0; i < vct.size(); ++i)
		vct[i] = (vct.size() - i) * 3;
	printSize(vct);

	vct2.insert(vct2.end(), 42);
	vct2.insert(vct2.begin(), 2, 21);
	printSize(vct2);

	vct2.insert(vct2.end() - 2, 42);
	printSize(vct2);

	vct2.insert(vct2.end(), 2, 84);
	printSize(vct2);

	vct2.resize(4);
	printSize(vct2);

	vct2.insert(vct2.begin() + 2, vct.begin(), vct.end());
	vct.clear();
	printSize(vct2);

	printSize(vct);
	return (0);
}


