#include "../containers/map.hpp"
#include <map>

#ifndef STD //-D STD dans le makefile
# define NAMESPACE ft
#else
# define NAMESPACE std
#endif

template <class Key, class T>
void print(NAMESPACE::map<Key, T>& mp, int test) {
	std::cout << "********** " << test << " **********" << std::endl;
	std::cout << "Size : " << mp.size() << std::endl;
	std::cout << "Empty : " << mp.empty() << std::endl;
	std::cout << std::endl;

	std::cout << "Contain :" << std::endl;

	size_t i = 0;
	for (typename NAMESPACE::map<Key, T>::iterator it = mp.begin(); it != mp.end(); it++)
	{
		std::cout << i << ":\t" << it->first << "\t->\t" << it->second << std::endl;
		i++;
	}
	std::cout << std::endl;
}

template <class Key, class T>
void printRO(NAMESPACE::map<Key, T> &mp, NAMESPACE::map<Key, T> &mp2, int test) {
	std::cout << "********** " << test << " **********" << std::endl;

	std::cout << "==\t->\t" << (mp == mp2) << std::endl;
	std::cout << "!=\t->\t" << (mp != mp2) << std::endl;
	std::cout << "<\t->\t" << (mp < mp2) << std::endl;
	std::cout << "<=\t->\t" << (mp <= mp2) << std::endl;
	std::cout << ">\t->\t" << (mp > mp2) << std::endl;
	std::cout << ">=\t->\t" << (mp >= mp2) << std::endl << std::endl;
}

int main() {
	#ifndef STD
		std::cout << "****** Test with FT ******" << std::endl;
	#else
		std::cout << "****** Test with STD ******" << std::endl;
	#endif
	int test = 1;
	NAMESPACE::map<int, char> mp;

	//1 - Map vide
	print(mp, test++);

	mp[42] = 'a';
	mp[3] = 'b';
	mp[10] = 'c';
	//2 - Map avec 3 pairs
	print(mp, test++);

	//Tenter d'ajouter une pair avec une clé qui existe via insert.
	mp.insert(NAMESPACE::pair<int ,char>(42, 'z'));
	//3 - Map avec 3 pairs, 42 -> a
	print(mp, test++);

	//Tenter de modifier la valeur de la clé 42 via operator[].
	mp[42] = 'z';
	//4 - Map avec 3 pairs, 42 -> z
	print(mp, test++);

	for (int i = 0; i < 10; i++)
		mp[i * 4] = 'd' + i;
	//5 - Map avec 13 pairs
	print(mp, test++);

	NAMESPACE::map<int, char> mp_cp(mp);
	//6 - Copie de map avec 13 pairs
	print(mp_cp, test++);

	//7 - Test d'opérateurs relationnels
	printRO(mp, mp_cp, test++);

	//Modifier la valeur de la clé 0 pour tester si mp est plus grand que mp_cp
	mp[0] = 'z';
	//8 - Opérateurs relationnels
	printRO(mp, mp_cp, test++);

	//Retirer une clé en particulier
	mp.erase(16);
	//9 - Map avec 12 pairs
	print(mp, test++);

	NAMESPACE::map<int, char>::iterator it = mp.begin();
	//Retirer une pair avec un itérateur
	it++;
	it++; //(4 -> e)
	mp.erase(it);
	//10 - Map avec 11 pairs
	print(mp, test++);

	NAMESPACE::map<int, char>::iterator ite = mp.end();
	it = mp.begin();
	for (int i = 0; i < 6; i++)
		it++; //(24 -> j)
	for (int i = 0; i < 3; i++)
		ite--; //(32 -> l)
	//Retirer une pair avec itérateur de début et de fin
	mp.erase(it, ite);
	//11 - Map avec 9 pairs
	print(mp, test++);

	mp.clear();
	//12 - Map vide
	print(mp, test++);

	it = mp_cp.begin();
	for (int i = 0; i < 7; i++)
		it++; //20 -> i
	ite = mp_cp.end(); //end
	//Copier avec les itérateurs d'une autre map
	mp.insert(it, ite);
	//13 - Map de 6
	print(mp, test++);

	//14 - Trouver une clé qui existe
	it = mp.find(28);
	std::cout << "********** " << test++ << " **********" << std::endl;
	std::cout << "\tFind key 28\t" << std::endl;
	std::cout << it->first << "\t->\t" << it->second << std::endl;

	//Operator=
	mp = mp_cp;
	//15 - Map de 13
	print(mp_cp, test++);
	//16 - Copie de map de 13
	print(mp, test++);

	//17 - Opérateurs relationnels (Map égales)
	printRO(mp, mp_cp, test++);

	//Tester la deep copy
	mp[100] = '!';
	//18 - Map de 14
	print(mp, test++);

	//19 - Opérateurs relationnelles (Map non - égales)
	printRO(mp, mp_cp, test++);
}