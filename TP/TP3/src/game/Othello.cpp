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
		verif_IsIntegerBetween(mode, 1, 2);
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
		int column = 0;
		int line = 0;
		display_grid();
		if (ia == true)
		{
			//tour_ia(ia_symbol);
			ia = false;
		}
		else
		{
			saisir_case(symbol, column, line);
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
		int column = 0;
		int line = 0;
		display_grid();
		saisir_case(symbol, column, line);
		replace_symbolBetween(symbol, column, line);
		
		//inversement des joueurs pour prochain tour
		if (symbol == 1)
			symbol = 2;
		else
			symbol = 1;
	}
	end_screen(symbol, winner);
}

void Othello::saisir_case(int& symbol, int& column, int& line)
{
	char column_char;
	std::cout << "Enter the column (A to H) and the line (1 to 8) of the case you want to play.\n";
	std::cin >> column_char >> line;

	//vérif des entrées
	verif_IsLetterBetween(column_char, 'A', 'H');
	verif_IsIntegerBetween(line, 1, 8);
	
	//convertion de la lettre colonne en chiffre de 0 à 7
	column = column_char - 65;
	line -= 1;

	if (empty_case(line, column)) {
		grid->set_element(line, column, symbol);
	}
	else
	{
		std::cout << "Please choose an empty case.\n";
		saisir_case(symbol, column, line);
	}
}


void Othello::replace_symbolBetween(int& symbol, int& column, int& line)
{
	// *** FONCTIONNEMENT METHODE *** //
	//1. verifie dans les 8 directions si il y a un symbole du même type, note la position dans un tableau last_symbol
	//2. remplace les symboles entre la case jouée et la position de last_symbol pour chaque direction

	int directions[8][2] = { {0,1}, {1,1}, {1,0}, {1,-1}, {0,-1}, {-1,-1}, {-1,0}, {-1,1} };
	int last_symbol[8][2] = { {0,0}, {0,0}, {0,0}, {0,0}, {0,0}, {0,0}, {0,0}, {0,0} };
	
	std::cout << "Position of the symbol played  : x = " << column << " y = " << line << " | Symbole : " << grid->get_element(line, column) << std::endl;
	
	//1. verifie dans les 8 directions si il y a un symbole du même type, note la position dans un tableau last_symbol
	for (int i = 0; i < 8; i++)
	{
		int x = column;
		int y = line;
		bool other_symbol_found = false;
		bool same_symbol_found = false;

		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		//DOING éviter de sortir du tableau lorsque on ignore la position de la case jouée (faire un if ?)



		//ignore la position de la case jouée en appliquant la direction
		try
		{
			std::cout << "try " << i << " ignoring actual case" << std::endl; // crash ici
			x += directions[i][0];
			y += directions[i][1];
		}
		catch (const std::exception&)
		{
			continue;
		}


		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		
		// tant que la case n'est pas vide et que le symbole n'est pas le même que celui joué ou lui-même
		while (grid->get_element(y, x) != 0 && grid->get_element(y, x) != symbol)
		{	
			std::cout << "Other symbol found at x = " << x << " y = " << y << std::endl;
			try
			{
				std::cout << "try " << i << " direction" << std::endl;
				x += directions[i][0];
				y += directions[i][1];
			}
			catch (const std::exception&) 
			{
				other_symbol_found = true;
				break;
			}	
			other_symbol_found = true;
		}

		//si le symbole est le même que celui joué et qu'un autre symbole a été trouvé avant
		if (grid->get_element(y, x) == symbol && other_symbol_found == true)
		{
			std::cout << "Same symbol found at x = " << x << " y = " << y << std::endl;
			last_symbol[i][0] = x;
			last_symbol[i][1] = y;
			same_symbol_found = true;
		}
		
		//2. remplace les symboles entre la case jouée et la position de last_symbol s'ils existent
		if (other_symbol_found && same_symbol_found)
		{
			std::cout << "Replace symbols between x = " << column << " y = " << line << " and x = " << last_symbol[i][0] << " y = " << last_symbol[i][1] << std::endl;
			int x = column;
			int y = line;
			while (x != last_symbol[i][0] || y != last_symbol[i][1])
			{
				x += directions[i][0];
				y += directions[i][1];
				grid->set_element(y, x, symbol);
			}
		}
	}
}

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
	int x = 0;
	int o = 0;
	
	//parcours la grille et compte le nombre de chaque symbole
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (grid->get_element(i, j) == 1)
			{
				x++;
			}
			else if (grid->get_element(i, j) == 2)
			{
				o++;
			}
		}
	}
	
	if (x > o)
	{
		winner = 1;
		checker = true;
	}
	else if (x < o)
	{
		winner = 2;
		checker = true;
	}
	else
	{
		checker = false;
	}
}

void Othello::display_grid()
{
	grid->display();
}