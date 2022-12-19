#include "Othello.hpp"

Othello::Othello()
{
	grid = new Grid(8, 8);
}

Othello::~Othello()
{
}

void Othello::run(int& mode)
{
	int symbol;
	switch (mode)
	{
	default:
		std::cerr << "Mode switcher error.\n";
		break;

	case 1:
		std::cout << "You are playing against the computer.\n";
		choose_symbol(symbol);
		play_solo(symbol);
		break;

	case 2:
		std::cout << "You are playing against another player.\n";
		choose_symbol(symbol);
		play_multi(symbol);
		break;
	}
}

void Othello::play_solo(int& symbol)
{
	bool player_win = false;
	int winner;
	bool ia = false;
	int ia_symbol = symbol == 1 ? 2 : 1;
	while (!player_win)
	{
		display_grid();
		if (ia == true)
		{
			//tour_ia(ia_symbol);
			ia = false;
		}
		else
		{
			saisir_case(symbol);
			ia = true;
		}
		check_win(player_win, winner);
	}
	display_grid();
	end_screen(symbol, winner);
}

void Othello::play_multi(int& symbol)
{
	bool player_win = false;
	int winner;
	while (!player_win)
	{
		display_grid();
		saisir_case(symbol);
		check_win(player_win, winner);
		if (symbol == 1)
			symbol = 2;
		else
			symbol = 1;
	}
	end_screen(symbol, winner);
}

void Othello::saisir_case(int& symbol)
{
	char column_char;
	int line;
	std::cout << "Enter the column (A to H) and the line (1 to 8) of the case you want to play.\n";
	std::cin >> column_char >> line;

	//*************** verif à faire des entrées ******************//


	//convertion de la lettre colonne en chiffre de 0 à 7
	int column = column_char - 65;
	line -= 1;

	if (empty_case(column, line)) {
		grid->set_element(column, line, symbol);
	}
	else
	{
		std::cout << "Please choose an empty case.\n";
		saisir_case(symbol);
	}



}

//inversement des symboles placés entre le dernier symbole joué et un symbole du même type dans les 8 directions
/*
void Othello::replace_symbolBetween(int& symbol, int& column, int& line)
{

}
*/

//vérifie si la case est vide
bool Othello::empty_case(int& column, int& line)
{
	if (grid->get_element(column, line) == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Othello::check_win(bool& checker, int& winner) {
	//vérifie si le joueur a gagné
	//compte le nombre de x et de o pour les comparer : celui qui a le plus de symboles sur le plateau a gagné
	//(la partie prend fin que lorsque le plateau est rempli)
}

void Othello::display_grid()
{
	grid->display();
}