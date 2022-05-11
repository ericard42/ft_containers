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

	std::cout << "->\t==\t<-" << std::endl;
	std::cout << (vec == vec2) << std::endl;
	std::cout << "->\t!=\t<-" << std::endl;
	std::cout << (vec != vec2) << std::endl;
	std::cout << "->\t<\t<-" << std::endl;
	std::cout << (vec < vec2) << std::endl;
	std::cout << "->\t<=\t<-" << std::endl;
	std::cout << (vec <= vec2) << std::endl;
	std::cout << "->\t>\t<-" << std::endl;
	std::cout << (vec > vec2) << std::endl;
	std::cout << "->\t>=\t<-" << std::endl;
	std::cout << (vec >= vec2) << std::endl << std::endl;
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

	//Vecteur Vide
	print(vec, test++);
	//Ajouter 15 valeurs
	for (int i = 0; i < 15; i++)
		vec.push_back(i * 2);
	//1 - Vecteur avec 15 valeurs
	print(vec, test++);

	//Suprimer 2 fois la dernière valeur
	vec.pop_back();
	vec.pop_back();
	//2 - Vecteur avec 13 valeurs
	print(vec, test++);

	//Itérateur sur [2]
	NAMESPACE::vector<int>::iterator it = vec.begin();
	for (int i = 0; i < 2; i++)
		it++;
	//Ajouter 5 fois 42 à partir de [2]
	vec.insert(it, 5, 42);
	//3 - Vecteur avec 18 valeurs
	print(vec, test++);

	it = vec.begin();
	NAMESPACE::vector<int>::iterator ite = vec.end();
	//Itérateur sur [7]
	for (int i = 0; i < 7; i++)
		it++;
	//Itérateur sur [10]
	for (int i = 0; i < 8; i++)
		ite--;
	//Supprime de [7] à [9] (3 valeurs)
	vec.erase(it, ite);
	//4 - Vecteur avec 15 valeurs
	print(vec, test++);

	NAMESPACE::vector<int> vec_cp(vec);
	//5 - Vecteur avec 15 valeurs, copie
	print(vec_cp, test++);

	//6 - Test Relationnal Operators
	printRO(vec, vec_cp, test++);

	//Tout remplacer par 5 valeurs
	vec_cp.assign(5, 42);
	//7 - Vecteur avec 5 valeurs
	print(vec_cp, test++);

	it = vec.begin();
	ite = vec.end();
	//Itérateur sur [10]
	for (int i = 0; i < 10; i++)
		it++;
	NAMESPACE::vector<int>::iterator it_cp = vec_cp.begin();
	//Ajouter les valeurs [10] à [14] (5 valeurs) de vec à [0] de vec_cp
	vec_cp.insert(it_cp, it, ite);
	//8 - Vecteur avec 10 valeurs
	print(vec_cp, test++);

	//9 - Test Relationnal Operators
	printRO(vec, vec_cp, test++);

	it_cp = vec_cp.begin();
	it = vec.begin();
	swap(vec, vec_cp);
	//10 - Vecteur avec 10 valeurs
	print(vec, test++);
	//11 - Vecteur avec 15 valeurs
	print(vec_cp, test++);
	std::cout << "****** Itérateurs après swap ******" << std::endl;
	std::cout << "Première valeur de vec, avec itérateur anciennement sur vec_cp" << std::endl;
	std::cout << *it_cp << std::endl;
	std::cout << "Première valeur de vec_cp, avec itérateur anciennement sur vec" << std::endl;
	std::cout << *it << std::endl << std::endl;

	//12 - Test Relationnal Operators
	printRO(vec, vec_cp, test++);

	//Test operator = avec contenu dans les 2 vecteurs.
	vec_cp = vec;
	//13 - Vecteur copié avec 10 valeurs
	print(vec, test++);
	//Copie du vecteur, avec 10 valeurs
	print(vec_cp, test++);

	//14 - Test relationnal Operators
	printRO(vec, vec_cp, test++);

	//Vérifier que c'est bien une deep copy
	vec_cp.push_back(42);
	//15 - Vecteur avec 11 valeurs
	print(vec_cp, test++);

	//16 - Vérifier que les vecteurs ne sont pas égaux.
	printRO(vec, vec_cp, test++);
}



