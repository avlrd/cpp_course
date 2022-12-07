# cpp_course

## Rapport - Review SOLID

> Alexandre Robert et Arthur Villard

Dans ce rapport, nous alons discuter de la solidité, du respect des principes SOLID du TP3.

Je tiens tout d'abord à préciser que je n'ai pas réussi à produire un code satisfaisant les consignes du TP. Ainsi, nous commenterons en conséquence le code et discuterons de son adaptation même si il n'est pas abouti.

### S - Single responsibility principle

> Une classe ne doit avoir qu'une seule responsabilité, qu'un seul rôle.

Dans un premier temps, discutons de la répartition en classes.  
Une classe ```Grid``` permettant de représenter une grille de jeu est parfaitement adaptée ici car elle ne comprend uniquement des méthodes concernant la grille en elle même. Elle permet une adaptation en différents modes de jeux. Cette classe respecte le principle de responsabilité unique.  
Ensuite, pour les classes ```Morpion``` et ```Puissance4```, elles héritent toutes deux de la classe ```Game```. Ainsi, on peut étendre n'importe quel type de jeu qui utilise une grille de cases. Elles respectent le principe dans la mesure où elles s'occupent de la logique du jeu. Cependant, on pourrait le discuter pour les méthodes ```run``` et ```display_grid```. On peut imaginer utiliser directement la méthode ```display``` de ```Grid```, et d'implémenter une méthode ```run``` dans une autre classe s'occupant de la logique de l'application et non du jeu, dans l'esprit d'un menu qui appelle gère différents jeux.  

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

> Les objets doivent être remplacables par des instances de leur sous-type sans altérer le bon fonctionnement du programme.

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

Dans ce programme, il y a plusieurs problème liés à ce principe. Premièrement, le fichier ```Utils.hpp``` fournit des méthodes diverses n'étant pas forcément liées. Ainsi, certaines classes incluent des méthodes qu'elles n'utilisent pas. Ce problème pourrait être reglé en implémentant des interfaces, bien nommées et organisées en fonction de leur utilisation/apport.

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

Ce principe est ici ignoré. Par exemple, on pourrait imaginer une interface utilisée par la classe ```Game```, lui permettant d'utiliser les grilles.