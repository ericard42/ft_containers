#include "../containers/stack.hpp"
#include <stack>

#ifndef STD //-D STD dans le makefile
# define NAMESPACE ft
#else
# define NAMESPACE std
#endif

template <class T>
void print(NAMESPACE::stack<T>& sta, int test) {
	std::cout << "********** " << test << " **********" << std::endl;
	std::cout << "Size : " << sta.size() << std::endl;
	std::cout << "Empty : " << sta.empty() << std::endl;
	std::cout << std::endl;

	if (test != 1)
	{
		std::cout << "Top :" << std::endl;
		std::cout << sta.top() << std::endl;
		std::cout << std::endl;
	}
}

template <class T>
void printRO(NAMESPACE::stack<T> &sta, NAMESPACE::stack<T> &sta2, int test) {
	std::cout << "********** " << test << " **********" << std::endl;

	std::cout << "==\t->\t" << (sta == sta2) << std::endl;
	std::cout << "!=\t->\t" << (sta != sta2) << std::endl;
	std::cout << "<\t->\t" << (sta < sta2) << std::endl;
	std::cout << "<=\t->\t" << (sta <= sta2) << std::endl;
	std::cout << ">\t->\t" << (sta > sta2) << std::endl;
	std::cout << ">=\t->\t" << (sta >= sta2) << std::endl << std::endl;
}

int main() {
	#ifndef STD
		std::cout << "****** Test with FT ******" << std::endl;
	#else
		std::cout << "****** Test with STD ******" << std::endl;
	#endif
	int test = 1;
	NAMESPACE::stack<int> sta;

	//1 - Stack vide (Segfault si top)
	print(sta, test++);

	for (int i = 0; i < 10; i++)
		sta.push(i);
	//2 - Stack avec 10 valeurs de 0 à 9
	print(sta, test++);

	for (int i = 0; i < 5; i++)
		sta.pop();
	//3 - Stack avec 5 valeurs de 0 à 4
	print(sta, test++);

	NAMESPACE::stack<int> sta_cp(sta);
	//4 - Copie de Stack avec 5 valeurs
	print(sta_cp, test++);

	//5 - Test d'operateurs relationnels
	printRO(sta, sta_cp, test++);

	for (int i = 0; i < 10; i++)
		sta_cp.push(i + 5);
	//6 - Stack Copie avec 15 valeurs
	print(sta_cp, test++);

	//7 - Test d'operateurs relationnels
	printRO(sta, sta_cp, test++);

	sta = sta_cp;
	//8 - Copie avec 15 valeurs
	print(sta, test++);

	//9 - Vérifier que les 2 stacks sont égales
	printRO(sta, sta_cp, test++);

	//Vérifier que c'est bien une deepcopy
	sta.push(42);
	//10 - Stack avec 15 valeurs
	print(sta_cp, test++);
	//11 - Copie avec 16 valeurs
	print(sta, test++);

	//12 - Vérifier que les 2 stacks ne sont plus égales
	printRO(sta, sta_cp, test++);
}