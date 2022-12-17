#pragma once

#include <iostream>

//Clears terminal
void clear_screen();

//Symbol to integer converter
int stoi(char symbol);

//Verifies if the input is an integer between two numbers
void verif_IsIntegerBetween(int& number, int& number1, int& number2);

//Verifies if the input is a letter between two letters
void verif_IsLetterBetween(char& letter, char& letter1, char& letter2);

//Symbol choosing function
void choose_symbol(int& symbol);

//Main menu display and logic
void main_menu(int& mode, int& mode2);

//End screen display and logic
void end_screen(int& symbol, int& winner);