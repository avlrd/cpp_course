#pragma once

#include <iostream>
#include <random>

int sum(int a, int b);
void swap(int& a, int& b);
void thirdFunctionRef(int a, int b, int& c);
void thirdFunctionPtr(int a, int b, int* c);
void randomIntsTabFill(int tab[], int size);
void displayTab(int tab[], int size);
void sortUp(int tab[], int size);