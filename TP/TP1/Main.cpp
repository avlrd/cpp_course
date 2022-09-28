#include "Part1.h"

int main()
{
	// PARTIE 1
	int a = 5;
	int b = 10;
	int c = 20;
	int size = 5;
	int tab[5];

	//1.1 + 1.2
	std::cout << a << " " << b << "\n";
	swap(a, b);
	std::cout << a << " " << b << "\n";
	std::cout << "\n";

	//1.3
	std::cout << "Old c value :" << c << "\n";
	thirdFunctionRef(a, b, c);
	std::cout << "New c value (ref) :" << c << "\n";
	c = 20;
	thirdFunctionPtr(a, b, &c);
	std::cout << "New c value (ptr) :" << c << "\n";
	std::cout << "\n";

	//1.4
	randomIntsTabFill(tab, size);
	displayTab(tab, size);

	// PARTIE 2

	

	return 0;
}