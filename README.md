# cpp_course

## Rapport - Review SOLID

> Alexandre Robert et Arthur Villard

### Introduction

Dans ce rapport, nous allons discuter de la solidité, du respect des principes SOLID du TP3.

Nous tenons à tout d'abord à préciser que nous n'avons pas réussi à produire un code satisfaisant complètement les consignes du TP. Ainsi, nous commenterons en conséquence le code et discuterons de son adaptation même si il n'est pas abouti.

Nous avons décidé de prendre le TP3 d'Arthur pour le refactoriser et effectuer ce code review car celui d'Alexandre a été conçu d'une manière plus compliquée, qui nous aurais pris plus de temps à comprendre et refactoriser.

### S - Single responsibility principle

> Une classe ne doit avoir qu'une seule responsabilité, qu'un seul rôle.

Dans un premier temps, discutons de la répartition en classes.  
Une classe ```Grid``` permettant de représenter une grille de jeu est parfaitement adaptée ici car elle ne comprend uniquement des méthodes concernant la grille en elle-même. Elle permet une adaptation en différents modes de jeux. Cette classe respecte le principle de responsabilité unique.  
Ensuite, pour les classes ```Morpion``` et ```Puissance4```, elles héritent toutes deux de la classe ```Game```. Ainsi, on peut étendre n'importe quel type de jeu qui utilise une grille de cases. Elles respectent le principe dans la mesure où elles s'occupent de la logique du jeu. Cependant, on pourrait le discuter pour les méthodes ```run``` et ```display_grid```. On peut imaginer utiliser directement la méthode ```display``` de ```Grid```, et d'implémenter une méthode ```run``` dans une autre classe s'occupant de la logique de l'application et non du jeu, dans l'esprit d'un menu qui gère différents jeux.  

### O - Open/Closed principle

> Favoriser l'extension à la modification du code.

Ce code ne respecte pas assez ce principe. Par exemple, la répartition en classe permet l'extension de modes de jeux, mais la gestion des coordonnées ou index des cases est très mal réalisée. On aurait pu imaginer une classe comprenant deux entier x et y modélisant les coordonnées des cases. 

```cpp
class Coordinates()
{
	public:
		inline int getX() const { return x; }
		inline int getY() const { return y; }
		inline void setX(int value) const { x = value; }
		inline void setY(int value) const { y = value; }

	private:
		int x;
		int y;
}
```

Ce problème peut se retrouver dans différentes méthodes de logique des jeux, comme par exemple ```Puissance4::saisir_col```.  

### L - Liskov’s substitution principle

> Les objets doivent être remplaçables par des instances de leur sous-type sans altérer le bon fonctionnement du programme.

Ce programme respecte ce principe, il est possible de remplacer toute instance de ```Game``` par ```Morpion``` ou ```Puissance4``` comme l'illustre cet exemple :

```cpp
(main.cpp : lignes 19->25)

case 1:
	game = new Morpion();
	break;
			
case 2:
	game = new Puissance4();
	break;
```

### I - Interface segregation Principle

> Aucun programme ne devrait implémenter des méthodes qu'il n'utilise pas.

Dans ce programme, il y a plusieurs problèmes liés à ce principe. Premièrement, le fichier ```Utils.hpp``` fournit des méthodes diverses n'étant pas forcément liées. Ainsi, certaines classes incluent des méthodes qu'elles n'utilisent pas. Ce problème pourrait être réglé en implémentant des interfaces, bien nommées et organisées en fonction de leur utilisation/apport.

Voici notre proposition de correction :

```cpp
class ISymbolHandling
{
	public:
		//Symbol to integer converter
		virtual int stoi(char symbol) = 0;

		//Symbol choosing function
		virtual void choose_symbol(int& symbol) = 0;
}

class IMenuCycle
{
	public:
		//Main menu display and logic
		virtual void main_menu(int& mode, int& mode2) = 0;

		//End screen display and logic
		virtual void end_screen(int& symbol, int& winner) = 0;
}

class ITerminalDisplay
{
	public:
		//Clears terminal
		virtual void clear_screen() = 0;
}
```

Cette implémentation, nécessitant également une révision des classes les utilisant, permet ainsi de répondre au principe de ségrégation de l’interface.

### D - Dependency Inversion Principle (DIP)

> Une classe doit dépendre de son abstraction, pas de son implémentation.

Ce principe n'est pas respecté dans notre code. Pour y remedier, nous pourrions par exemple mettre en place une interface utilisée par la classe ```Game```, lui permettant d'utiliser les grilles. Une telle implémentation est parfaitement adaptée pour cette situation, où nous aurions beaucoup de modes de jeu implémentant les grilles.

### Tell don't ask

> Dire à l’objet comment faire plutôt que d'interroger son état

Ce principe, qui consiste à intégrer la logique d'un objet à l'intérieur de lui-même (tell), et non pas de l'effectuer en dehors (ask), est totalement respecté, ce qui permet de ne pas écrire plusieurs fois la même portion de code (ce qui serait, de plus, en violation du principe DRY (don’t repeat yourself))

Par exemple, cette logique est implémentée dans une fonction dédiée dans l'objet ```Puissance4``` : 

```cpp
void Puissance4::play_solo(int& symbol)
{
	bool player_win = false;
	int winner;
	bool ia = false;
	while (!player_win)
	{
		display_grid();
		if (ia)
		{
			tour_ia(symbol);
			ia = true;
		}
		else
		{
			saisir_col(symbol);
			ia = false;
		}
	}
	end_screen(symbol, winner);
}
```

### Loi de Déméter

> « Ne parlez qu'à vos amis immédiats »

Notre code n'utilise pas de suite d'appel de méthodes d'objets : pour faire une action ou récupérer une information, seule une méthode est appelée permettant d'effectuer ou remonter une information, comme par exemple pour l'affichage de la grille, plutôt que de faire une méthode ```display``` seulement dans ```Grid```, on crée une méthode ```display_grid``` dans la classe ```Game``` qui l'appelle.

```cpp
(Morpion.cpp)

void Morpion::play_multi(int& symbol)
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

void Morpion::display_grid()
{
	grid->display();
}

(Grid.hpp)

void display();
```