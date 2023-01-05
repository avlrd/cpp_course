#include "CLI.hpp"

void CommandLineInterface::clear()
{
	#ifdef _WIN32
		system("cls");
	#else 
		system("clear");
	#endif
}

void CommandLineInterface::welcome()
{
	clear();
	std::cout << "\n\tBienvenue !\n\n\t\tApplication de jeux de plateau réalisée par Arthur VILLARD et Alexandre ROBERT" << std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(2));
}

void CommandLineInterface::ready_check_error()
{
	std::cout << "Une erreur est survenue lors de la vérification des données de jeu" << std::endl;
}

void CommandLineInterface::menu_input_error()
{
	std::cout << "Entrée invalide : ";
}

void CommandLineInterface::game_type_selection_display()
{
	clear();
	std::cout << "Veuillez choisir le jeu auquel vous voulez jouer : " << std::endl;
	std::cout << "\t1 - Morpion" << std::endl;
	std::cout << "\t2 - Puissance 4" << std::endl;
	std::cout << "\t3 - Othello" << std::endl;
	std::cout << "\t4 - Quitter" << std::endl;
}

void CommandLineInterface::game_mode_selection_display()
{
	clear();
	std::cout << "Veuillez choisir le mode de jeu : " << std::endl;
	std::cout << "\t1 - Solo" << std::endl;
	std::cout << "\t2 - Multijoueur" << std::endl;
	std::cout << "\t4 - Retour" << std::endl;
}

void CommandLineInterface::name_selection_display()
{
	clear();
	std::cout << "Veuillez entrer votre pseudonyme : " << std::endl;
}

bool CommandLineInterface::input(int& value)
{
	if (std::cin >> value)
		return true;
	return false;
}

bool CommandLineInterface::input(std::string& value)
{
	if (std::cin >> value)
		return true;
	return false;
}

void CommandLineInterface::clear_input()
{
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void CommandLineInterface::displayGrid(Grid& grid)
{
	for (int i = 0; i < grid.get_height(); i++)
	{
		for (int k = 0; k < grid.get_width() * 4 + 1; k++)
			std::cout << "-";
		std::cout << std::endl;
		for (int j = 0; j < grid.get_width(); j++)
		{
			std::cout << "| ";
			switch (grid.get_element(i, j).getCellValue())
			{
				case ECellValue::EMPTY:
					std::cout << " ";
					break;
				case ECellValue::O:
					std::cout << "O";
					break;
				case ECellValue::X:
					std::cout << "X";
					break;
				default:
					std::cout << "?";
					break;
			}
			std::cout << " ";
		}
		std::cout << "|" << std::endl;
	}
	for (int k = 0; k < grid.get_width() * 4 + 1; k++)
		std::cout << "-";
	std::cout << std::endl;
}