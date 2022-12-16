#include "../inc/Part1.h"
#include "../inc/Tennis.h"
#include "../inc/Part3.h"

using std::string;

int main()
{
	/*
	// PARTIE 1
	int a = 5;
	int b = 10;
	int c = 20;

	//1.1 + 1.2
	std::cout << "Partie 1.1 et 1.2\n\n";
	std::cout << a << " " << b << "\n";
	swap(a, b);
	std::cout << a << " " << b << "\n";
	std::cout << "\n\n";

	//1.3
	std::cout << "Partie 1.3\n\n";
	std::cout << "Old c value :" << c << "\n";
	thirdFunctionRef(a, b, c);
	std::cout << "New c value (ref) :" << c << "\n";
	c = 20;
	thirdFunctionPtr(a, b, &c);
	std::cout << "New c value (ptr) :" << c << "\n";
	std::cout << "\n\n";

	//1.4
	std::cout << "Partie 1.4\n\n";

	int size;
	int* tab;

	std::cout << "Veuillez enter la taille du tableau :\n";
	std::cin >> size;
	tab = new int[size];

	randomIntsTabFill(tab, size);
	std::cout << "Voici le tableau genere aleatoirement...\n\t";
	displayTab(tab, size);

	std::cout << "\n\nSouhaitez vous trier le tableau par ordre croissant (1) ou décroissant (2) ?\n";
	int listener;
	std::cin >> listener;

	if (listener == 1)
	{
		sortUp(tab, size);
		std::cout << "Voici le tableau trie par ordre croissant :\n\t";
		displayTab(tab, size);
	}
	else
	{
		sortDown(tab, size);
		std::cout << "Voici le tableau trie par ordre decroissant :\n\t";
		displayTab(tab, size);
	}

	string listenerBis;
	std::cout << "\nSouhaitez-vous voir le tableau trie dans l'autre sens ? (oui/non)\n";
	std::cin >> listenerBis;
	if (listenerBis == "oui")
	{
		reverseTab(tab, size);
		std::cout << "\nVoici le tableau trié par ordre decroissant :\n\t";
		displayTab(tab, size);
	}

	std::cout << "\n\n";

	// PARTIE 2

	string nameA, nameB;
	std::cout << "Bonjour et bienvenue a la finale du Tournoi de Tennis du CNAM.\n"
		<< "Cette finale oppose le joueur (entrez le nom du joueur)...\n";
	std::cin >> nameA;
	std::cout << "et...\n";
	std::cin >> nameB;
	std::cout << ".\nInstallez vous confortablement, le match va commencer.\n\n";

	for (int i = 0; i < 3; i++)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		std::cout << "...\n";
	}	

	Tennis* game = new Tennis(nameA, nameB);
	*/
	// PARTIE 3

	presentation();

	affichageEtSaisieDeNombre();

	return 0;
}