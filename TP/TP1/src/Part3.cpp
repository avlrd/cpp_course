#include "../inc/Part3.h"

void titleCase(string& s)
{
	for (int i = 0; i < s.length(); i++)
	{
		s[i] = tolower(s[i]);
		if (i == 0)
			s[i] = toupper(s[i]);
	}
}

void presentation()
{
	string nom;
	string prenom;
	std::cout << "Bonjour, quel est votre nom et votre prénom ?\n";
	std::cin >> nom >> prenom;
	titleCase(nom);
	titleCase(prenom);
	std::cout << "Bonjour, " << nom << " " << prenom << " !\n";
}

void affichageEtSaisieDeNombre()
{
	std::cout << "un texte" << std::endl;

	std::cout << "\nUn nombre entre 0 et 1000 a ete genere aleatoirement. Quel est-il ?\n";

	srand((unsigned)time(NULL));
	int random = rand() % 1000;
	std::cout << random;

	int guess = -1;
	int tries = 1;
	std::cin >> guess;

	while (guess != random)
	{
		std::cout << "\nEt non ! Essayez encore...\n";
		std::cin >> guess;
		tries++;
	}
	
	std::cout << "\nBravo ! Vous avez trouve le bon nombre en " << tries << " essais.\n";

	std::cout << "\nVeuillez choisir un nombre entre 0 et 1000. Je vais essayer de le deviner et vous devrez a chaque essai me dire si c'est plus grand ou plus petit. Vous avez 3 secondes.\n";
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));

	bool won = false;
	tries = 0;
	string answer;

	guess = 500;

	while (won == false)
	{
		std::cout << "\nVotre nombre est-il " << guess << " ? (oui/non)\n";

		tries++;
		std::cin >> answer;

		if (answer == "oui")
			won = true;
		else
		{
			std::cout << "Est-ce + ou - ?\n";
			std::cin >> answer;

			if (answer == "+")
				guess += guess / 2;
			else
				guess = guess / 2 + 1;
		}
	}

	std::cout << "\nJ'ai trouve en " << tries << " essais.\n";
}
