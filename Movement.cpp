#include <iostream>
#include "Header.h"
#include <conio.h>
#include <windows.h>

using namespace std;

void movement::movement1()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	cout << "INTRODUCTION" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	Sleep(1000);
	cout << "Key [ESC] forces our program to exit" << endl;
	cout << "Key [ARROW UP] forces our cursor up" << endl;
	cout << "Key [ARROW DOWN] forces our cursor down" << endl;
	cout << "Key [ARROW RIGHT] forces our cursor right" << endl;
	cout << "Key [ARROW LEFT] forces our cursor left" << endl;
	cout << "Key [ENTER] allows us to enter option" << endl;
	cout << "--------------------------------------" << endl;
	cout << "The goal of the game is to conquer all fortresses - GOOD LUCK!" << endl;
	system("pause");
	system("CLS");
}

int movement::getting_key()
{
	unsigned char znak; // DO GÓRY 72 // W DÓ£ 80 / W LEWO 75 / W PRAWO 77 // ENTER 13 // ESC 27
	znak = _getch();
	static_cast <int>(znak);
	while (_kbhit())  //Sprawdza znaki do odczytania które pozosta³y jeœli s¹/nie ma. (1 = true, 0 = false)
	{
		znak = _getch();
		static_cast <int>(znak);
	}
	return znak;
}