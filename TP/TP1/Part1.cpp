#include "Part1.h"

int sum(int a, int b)
{
	return a + b;
}

void swap(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

void thirdFunctionRef(int a, int b, int& c)
{
	c = a + b;
}

void thirdFunctionPtr(int a, int b, int* c)
{
	*c = a + b;
}

void randomIntsTabFill(int tab[], int size)
{
	std::random_device rd;
	std::mt19937 generator(rd());
	std::uniform_int_distribution<int> distribution(0, 100);
	
	for (int i = 0; i < size; i++)
	{
		tab[i] = distribution(generator);
	}
}

void displayTab(int tab[], int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << tab[i] << " ";
	}
}

void sort(int tab[], int size)
{

}
