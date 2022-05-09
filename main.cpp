#include <iostream>
#include "containers/vector.hpp"
//#include "containers/stack.hpp"
#include "utils/binary_tree.hpp"
#include "utils/binary_tree_node.hpp"
#include "containers/map.hpp"
//#include "utils/pair.hpp"
//#include <vector>

/*#include "containers/containers_test/srcs/base.hpp"
#if !defined(USING_STD)
# include "containers/vector.hpp"
#else
# include <vector>
#endif *//* !defined(STD) */

/*#define T_SIZE_TYPE typename TESTED_NAMESPACE::vector<T>::size_type

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
}*/

#include "42TESTERS-CONTAINERS/MAP/mains/test_utils.hpp"
#include <map>

#ifndef STD
# define NAMESPACE ft
#else
# define NAMESPACE std
#endif

using namespace NAMESPACE;

template <class Key, class T>
void	print(map<Key, T>& lst)
{
	for (typename map<Key, T>::iterator it = lst.begin(); it != lst.end(); it++)
		cout << it->first << " => " << it->second << '\n';
}

int main2 ()
{
	map<char,int> foo,bar;

	foo['x']=100;
	foo['y']=200;
	// arbre xy

	bar['a']=11;
	bar['b']=22;
	bar['c']=33;


	map<char, int>::const_iterator tmp = foo.begin(); //tmp iterates through foo
	map<char, int>::const_iterator tmp2 = bar.begin(); //tmp2 iterates through bar

	swap(bar, foo); //tmp iterates through bar
	//tmp2 iterates through foo

	map<char, int>	other;

	other['1'] = 73;
	other['2'] = 173;
	other['3'] = 763;
	other['4'] = 73854;
	other['5'] = 74683;
	other['6'] = 753;

	map<char, int>::const_iterator tmp3 = other.begin(); // tmp3 iterates through other

	cout << "foo contains:\n";
	for (map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
		cout << it->first << " => " << it->second << '\n';

	cout << "bar contains:\n";
	for (map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
		cout << it->first << " => " << it->second << '\n';

	while(tmp != bar.end())
	{
		cout << tmp->first << " => " << tmp->second << '\n';
		tmp++;
	}
	tmp--;

	while(tmp2 != foo.end())
	{
		cout << tmp2->first << " => " << tmp2->second << '\n';
		tmp2++;
	}
	tmp2--;

	swap(other, foo); //tmp2 iterates through other
	//tmp3 iterates throught foo
	print(other);
	print(foo);
	print(bar);
	while(tmp != bar.begin())
	{
		cout << tmp->first << " => " << tmp->second << '\n';
		tmp--;
	}
	cout << tmp->first << " => " << tmp->second << '\n';

	while(tmp2 != other.begin())
	{
		cout << tmp2->first << " => " << tmp2->second << '\n';
		tmp2--;
	}
	cout << tmp2->first << " => " << tmp2->second << '\n';

	while(tmp3 != foo.end())
	{
		cout << tmp3->first << " => " << tmp3->second << '\n';
		tmp3++;
	}
	tmp3--;

	swap(bar, foo);
	swap(foo, bar);
	swap(bar, foo); //tmp3 iterates through bar
	//tmp iterates through foo

	print(other);
	print(foo);
	print(bar);

	while(tmp != foo.end())
	{
		cout << tmp->first << " => " << tmp->second << '\n';
		tmp++;
	}

	while(tmp2 != other.end())
	{
		cout << tmp2->first << " => " << tmp2->second << '\n';
		tmp2++;
	}

	while(tmp3 != bar.begin())
	{
		cout << tmp3->first << " => " << tmp3->second << '\n';
		tmp3--;
	}
	cout << tmp3->first << " => " << tmp3->second << '\n';

	return 0;
}

int main() {
	map<char,int> foo,bar;

	foo['x']=100;
	foo['y']=200;
	// arbre xy

	bar['a']=11;
	bar['b']=22;
	bar['c']=33;


	typedef map<char, int>::const_iterator mit;

	map<char, int>::const_iterator tmp = foo.begin(); //tmp iterates through foo
	map<char, int>::const_iterator tmp2 = bar.begin(); //tmp2 iterates through bar

	cout << "### Contenu avec begin ###" << std::endl;

	cout << "# foo #" << std::endl;
	for (mit fb = foo.begin(); fb != foo.end(); fb++)
		cout << fb->first << " => " << fb->second << '\n';

	cout << "# bar #" << std::endl;
	for (mit bbou = bar.begin(); bbou != bar.end(); bbou++)
		cout << bbou->first << " => " << bbou->second << '\n';

	cout << "### Contenu avec tmp ###" << std::endl;

	cout << "# foo #" << std::endl;
	// tmp iterates on foo
	for (mit fb = tmp; fb != foo.end(); fb++)
		cout << fb->first << " => " << fb->second << '\n';

	cout << "# bar #" << std::endl;
	// tpm2 iterates on bar
	for (mit bbou = tmp2; bbou != bar.end(); bbou++)
		cout << bbou->first << " => " << bbou->second << '\n';



	swap(bar, foo); //tmp iterates through bar
	//tmp2 iterates through foo

	std::cout << std::endl << "! SWAP !" << std::endl << std::endl;

	cout << "# foo #" << std::endl;
	for (mit fb = foo.begin(); fb != foo.end(); fb++)
		cout << fb->first << " => " << fb->second << '\n';

	cout << "# bar #" << std::endl;
	for (mit bbou = bar.begin(); bbou != bar.end(); bbou++)
		cout << bbou->first << " => " << bbou->second << '\n';

	cout << "### Contenu avec tmp ###" << std::endl;

	cout << "# foo #" << std::endl;
	// tmp iterates on bar, but tmp il a l'arbre de foo
	while(tmp != bar.end()) {
		cout << tmp->first << " => " << tmp->second << '\n';
		tmp++;
	}

	cout << "# bar #" << std::endl;
	// tpm2 iterates on foo
	while(tmp2 != foo.end()) {
		cout << tmp2->first << " => " << tmp2->second << '\n';
		tmp2++;
	}
}

