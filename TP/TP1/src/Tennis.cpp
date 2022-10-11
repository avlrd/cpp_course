#include "../inc/Tennis.h"

Tennis::Tennis(std::string playerAName, std::string playerBName)
{
	this->A = new Player(playerAName);
	B = new Player(playerBName);
	won = false;
	winner = -1;
	srand((unsigned)time(NULL));

	while (won == false)
	{
		playMatch();
	}

	if (winner == 0)
		displayScore(A->getName());
	else
		displayScore(B->getName());
}

void Tennis::playMatch()
{
	int random = rand() % 2;

	compute(random);
}

void Tennis::compute(int id)
{
	switch (id)
	{
		case 0:
			if (A->getPoints() == 4 || (A->getPoints() == 3 && B->getPoints() < 3))
			{
				A->resetPoints();
				B->resetPoints();
				if (A->getGames() == 5 && B->getGames() < 5 || A->getGames() == 6 && B->getGames() == 5)
				{
					A->addGame();
					scoreboardHandler(A->getGames(), B->getGames());
					A->resetGames();
					B->resetGames();
					if (A->getSets() == 1)
					{
						won = true;
						winner = 0;
					}
					else
					{
						A->addSet();
					}
				}
				else
				{
					if (A->getGames() == 5 && B->getGames() == 6)
					{
						A->addGame();
						tiebreak();
					}
					else
					{
						A->addGame();
					}
				}
			}
			else
			{
				if (B->getPoints() == 4)
				{
					B->remPoint();
				}
				else
				{
					A->addPoint();
				}
			}
			break;

		case 1:
			if (B->getPoints() == 4 || (B->getPoints() == 3 && A->getPoints() < 3))
			{
				A->resetPoints();
				B->resetPoints();
				if (B->getGames() == 5 && A->getGames() < 5 || B->getGames() == 6 && A->getGames() == 5)
				{
					B->addGame();
					scoreboardHandler(A->getGames(), B->getGames());
					A->resetGames();
					B->resetGames();
					if (B->getSets() == 1)
					{
						won = true;
						winner = 1;
					}
					else
					{
						B->addSet();
					}
				}
				else
				{
					if (B->getGames() == 5 && A->getGames() == 6)
					{
						B->addGame();
						tiebreak();
					}
					else
					{
						B->addGame();
					}
				}
			}
			else
			{
				if (A->getPoints() == 4)
				{
					A->remPoint();
				}
				else
				{
					B->addPoint();
				}
			}
			break;
	}
}

void Tennis::tiebreak()
{
	int random = -1;

	while (random != 2)
	{
		random = rand() % 2;
		switch (random)
		{
			case 0:
				if (A->getPoints() >= 10 && B->getPoints() < A->getPoints() - 1)
				{
					A->addGame();
					scoreboardHandler(A->getGames(), B->getGames());
					A->resetPoints();
					B->resetPoints();
					A->resetGames();
					B->resetGames();
					random = 2;
					if (A->getSets() == 1)
					{
						won = true;
						winner = 0;
					}
					else
					{
						A->addSet();
					}
				}
				else
				{
					A->addPoint();
				}

			case 1:
				if (B->getPoints() >= 10 && A->getPoints() < B->getPoints() - 1)
				{
					B->addGame();
					scoreboardHandler(A->getGames(), B->getGames());
					A->resetPoints();
					B->resetPoints();
					A->resetGames();
					B->resetGames();
					random = 2;
					if (B->getSets() == 1)
					{
						won = true;
						winner = 0;
					}
					else
					{
						B->addSet();
					}
				}
				else
				{
					B->addPoint();
				}
		}
	}
}

void Tennis::scoreboardHandler(int nbGamesA, int nbGamesB)
{
	if (A->getSets() == 0 && B->getSets() == 0)
	{
		score[0][0] = nbGamesA;
		score[0][1] = nbGamesB;
	}
	else if (A->getSets() == 1 && B->getSets() == 0 || A->getSets() == 0 && B->getSets() == 1)
	{
		score[1][0] = nbGamesA;
		score[1][1] = nbGamesB;
	}
	else
	{
		score[2][0] = nbGamesA;
		score[2][1] = nbGamesB;
	}
}

void Tennis::displayScore(string winner)
{
	std::cout << "Fin du match !\n";
	std::cout << "Score final : ";
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			std::cout << score[i][j];
			if (j == 0)
				std::cout << ":";
			else
				std::cout << " ";
		}
	}
	std::cout << "\nVainqueur : " << winner << "\n";
}
