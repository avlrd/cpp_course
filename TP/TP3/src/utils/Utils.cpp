#include "Utils.hpp"

void clear_screen()
{
#ifdef _WIN32
	system("cls");
#else 
	system("clear");
#endif
}

//symbol to integer
int stoi(char symbol)
{
	switch (symbol)
	{
	case 'X':
		return 1;
		break;
	case 'O':
		return 2;
		break;
	default:
		return -1;
		break;
	}
}

void verif_IsIntegerBetween(int& number, int& number1, int& number2) 
{

	while (std::cin.fail() || number1 < 0 || number1 > number2)
	{
		std::cin.clear();
		std::cin.ignore(256, '\n');
		std::cout << "Please enter a valid number: ";
		std::cin >> number1;
	}
}

void verif_IsLetterBetween(char& letter, char& letter1, char& letter2)
{
	while (std::cin.fail() || letter < letter1 || letter > letter2)
	{	
		std::cin.clear();
		std::cin.ignore(256, '\n');
		std::cout << "Please enter a valid letter: ";
		std::cin >> letter;
	}
}

void choose_symbol(int& n)
{
	char symbol;
	std::cout << "Choose your symbol : X/O\n";
	std::cin >> symbol;
	n = stoi(symbol);
	std::cout << "You are playing with " << symbol << ".\n";
}

void main_menu(int& mode, int& mode2)
{
	clear_screen();
	int safe = 0;
	
	std::cout << "----- Menu principal -----" << std::endl;
	std::cout << "Veuillez choisir un jeu :\n";
	std::cout << "\t- Morpion (1)\n";
	std::cout << "\t- Puissance 4 (2)\n";
	std::cout << "\t- Othello (3)\n";
	std::cin >> safe;

	while(safe != 1 && safe != 2 && safe != 3)
	{
		std::cout << "Entr�e invalide.\n";
		std::cin >> safe;
	}
	mode = safe;

	clear_screen();

	std::cout << "Veuillez choisir le mode de jeu :\n";
	std::cout << "\t- Solo (1)\n";
	std::cout << "\t- Multijoueur (2)\n";
	std::cin >> safe;

	while(safe != 1 && safe != 2)
	{
		std::cout << "Entr�e invalide.\n";
		std::cin >> safe;
	}
	mode2 = safe;
	clear_screen();
}

void end_screen(int& symbol, int& winner)
{
	if(symbol == winner)
		std::cout << "Victoire !\n";
	else
		std::cout << "D�faite...\n";

	
	char ask;
	std::cout << "Voulez vous rejouer ? (Y/n)\n";
	std::cin >> ask;
	
	if (ask == 'n')
		return;
}