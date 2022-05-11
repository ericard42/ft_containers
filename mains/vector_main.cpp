#include "../containers/vector.hpp"
#include <vector>

#ifndef STD //-D STD dans le makefile
# define NAMESPACE ft
#else
# define NAMESPACE std
#endif

template <class T>
void print(NAMESPACE::vector<T>& vec, int test) {
	std::cout << "********** " << test << " **********" << std::endl;
	std::cout << "Size : " << vec.size() << std::endl;
	std::cout << "Empty : " << vec.empty() << std::endl;
	std::cout << std::endl;

	std::cout << "Contain :" << std::endl;

	size_t i = 0;
	for (typename NAMESPACE::vector<T>::iterator it = vec.begin(); it != vec.end(); it++)
	{
		std::cout << i << "\t: " << *it << std::endl;
		i++;
	}
	std::cout << std::endl;
}

template <class T>
void printRO(NAMESPACE::vector<T> &vec, NAMESPACE::vector<T> &vec2, int test) {
	std::cout << "********** " << test << " **********" << std::endl;

	std::cout << "==\t->\t" << (vec == vec2) << std::endl;
	std::cout << "!=\t->\t" << (vec != vec2) << std::endl;
	std::cout << "<\t->\t" << (vec < vec2) << std::endl;
	std::cout << "<=\t->\t" << (vec <= vec2) << std::endl;
	std::cout << ">\t->\t" << (vec > vec2) << std::endl;
	std::cout << ">=\t->\t" << (vec >= vec2) << std::endl << std::endl;
}

#include <cstdio>

int main() {
	#ifndef STD
		std::cout << "****** Test with FT ******" << std::endl;
	#else
		std::cout << "****** Test with STD ******" << std::endl;
	#endif
	int test = 1;
	NAMESPACE::vector<int> vec;

	//1 - Vecteur Vide
	print(vec, test++);

	//Ajouter 15 valeurs
	for (int i = 0; i < 15; i++)
		vec.push_back(i * 2);
	//2 - Vecteur avec 15 valeurs
	print(vec, test++);

	//Suprimer 2 fois la dernière valeur
	vec.pop_back();
	vec.pop_back();
	//3 - Vecteur avec 13 valeurs
	print(vec, test++);

	//Itérateur sur [2]
	NAMESPACE::vector<int>::iterator it = vec.begin();
	it += 2;
	//Ajouter 5 fois 42 à partir de [2]
	vec.insert(it, 5, 42);
	//4 - Vecteur avec 18 valeurs
	print(vec, test++);

	it = vec.begin();
	NAMESPACE::vector<int>::iterator ite = vec.end();
	//Itérateur sur [7]
	it += 7;
	//Itérateur sur [10]
	ite -= 8;
	//Supprime de [7] à [9] (3 valeurs)
	vec.erase(it, ite);
	//5 - Vecteur avec 15 valeurs
	print(vec, test++);

	NAMESPACE::vector<int> vec_cp(vec);
	//6 - Vecteur avec 15 valeurs, copie
	print(vec_cp, test++);

	//7 - Test d'operateurs relationnels
	printRO(vec, vec_cp, test++);

	//Tout remplacer par 5 valeurs
	vec_cp.assign(5, 42);
	//8 - Vecteur avec 5 valeurs
	print(vec_cp, test++);

	it = vec.begin();
	ite = vec.end();
	//Itérateur sur [10]
	it += 10;
	NAMESPACE::vector<int>::iterator it_cp = vec_cp.begin();
	//Ajouter les valeurs [10] à [14] (5 valeurs) de vec à [0] de vec_cp
	vec_cp.insert(it_cp, it, ite);
	//9 - Vecteur avec 10 valeurs
	print(vec_cp, test++);

	//10 - Test d'operateurs relationnels
	printRO(vec, vec_cp, test++);

	it_cp = vec_cp.begin();
	it = vec.begin();
	swap(vec, vec_cp);
	//11 - Vecteur avec 10 valeurs
	print(vec, test++);
	//12 - Vecteur avec 15 valeurs
	print(vec_cp, test++);
	std::cout << "****** Itérateurs après swap ******" << std::endl;
	std::cout << "Première valeur de vec, avec itérateur anciennement sur vec_cp" << std::endl;
	std::cout << *it_cp << std::endl;
	std::cout << "Première valeur de vec_cp, avec itérateur anciennement sur vec" << std::endl;
	std::cout << *it << std::endl << std::endl;

	//13 - Test d'operateurs relationnels
	printRO(vec, vec_cp, test++);

	//Test operator = avec contenu dans les 2 vecteurs.
	vec_cp = vec;
	//14 - Vecteur copié avec 10 valeurs
	print(vec, test++);
	//15 - Copie du vecteur, avec 10 valeurs
	print(vec_cp, test++);

	//16 - Test Test d'operateurs relationnels
	printRO(vec, vec_cp, test++);

	//Vérifier que c'est bien une deep copy
	vec_cp.push_back(42);
	//17 - Vecteur avec 11 valeurs
	print(vec_cp, test++);

	//18 - Vérifier que les vecteurs ne sont pas égaux.
	printRO(vec, vec_cp, test++);
}



