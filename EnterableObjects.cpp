#include "Header.h"
#include <iostream>
#include <windows.h>

void EnterableObjects::pointer()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), text_colour);
	cout << "-->";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
}

void EnterableObjects::buy_wood()
{
	int* woodtab = new int[1000];
	int exit = 0;
	system("CLS");
	cout << "Use your UP and DOWN key button to set the value" << endl;
	for (int i = 0; true; i)
	{
		int znak = movement::getting_key();
		switch (znak)
		{
		case 72:
		{
			i++;
			woodtab[i] = i * 10;
			system("CLS");
			cout << "Use your UP and DOWN key button to set the value: " << endl;
			cout << "Wood: " << woodtab[i] << " Gold :" << i << endl;
			break;
		}
		case 80:
		{
			if (i < 1)
			{
				system("CLS");
				cout << "You cannot buy minus wood!" << endl;
				break;
			}
			else
			{
				i--;
				woodtab[i] = i * 10;
				system("CLS");
				cout << "Use your UP and DOWN key button to set the value: " << endl;
				cout << "Wood: " << woodtab[i] << " Gold :" << i << endl;
				break;
			}
		}
		case 13:
		{
			if (player::money < i)
			{
				cout << "You do not have enough money!" << endl;
				break;
			}
			else
			{
				player::money = player::money - i;
				player::wood = player::wood + i * 10;
				exit++;
				break;
			}
		}
		case 27:
		{
			exit++;
			break;
		}
		}
		if (exit == 1)
		{
			break; // Wyjœcie z pêtli nieskoñczonej
		}
	}
	delete[] woodtab;
}

void EnterableObjects::buy_food()
{
	int* foodtab = new int[1000];
	int exit = 0;
	system("CLS");
	cout << "Use your UP and DOWN key button to set the value" << endl;
	for (int i = 0; true; i)
	{
		int znak = movement::getting_key();
		switch (znak)
		{
		case 72:
		{
			i++;
			foodtab[i] = i * 10;
			system("CLS");
			cout << "Use your UP and DOWN key button to set the value: " << endl;
			cout << "Food: " << foodtab[i] << " Gold :" << i << endl;
			break;
		}
		case 80:
		{
			if (i < 1)
			{
				system("CLS");
				cout << "You cannot buy minus food!" << endl;
				break;
			}
			else
			{
				i--;
				foodtab[i] = i * 10;
				system("CLS");
				cout << "Use your UP and DOWN key button to set the value: " << endl;
				cout << "Food: " << foodtab[i] << " Gold :" << i << endl;
				break;
			}
		}
		case 13:
		{
			if (player::money < i)
			{
				cout << "You do not have enough money!" << endl;
				break;
			}
			else
			{
				player::money = player::money - i;
				player::food = player::food + i * 10;
				exit++;
				break;
			}
		}
		case 27:
		{
			exit++;
			break;
		}
		}
		if (exit == 1)
		{
			break; // Wyjœcie z pêtli nieskoñczonej
		}
	}
	delete[] foodtab;
}

void EnterableObjects::buy_weapons()
{
	int* foodtab = new int[1000];
	int exit = 0;
	system("CLS");
	cout << "Use your UP and DOWN key button to set the value" << endl;
	for (int i = 0; true; i)
	{
		int znak = movement::getting_key();
		switch (znak)
		{
		case 72:
		{
			i++;
			system("CLS");
			cout << "Use your UP and DOWN key button to set the value: " << endl;
			cout << "Weapons: " << i << " Gold :" << i * 5 << endl;
			break;
		}
		case 80:
		{
			if (i < 1)
			{
				system("CLS");
				cout << "You cannot buy minus food!" << endl;
				break;
			}
			else
			{
				i--;
				system("CLS");
				cout << "Use your UP and DOWN key button to set the value: " << endl;
				cout << "Weapons: " << i << " Gold :" << i*5  << endl;
				break;
			}
		}
		case 13:
		{
			if (player::money < i * 5)
			{
				cout << "You do not have enough money!" << endl;
				break;
			}
			else
			{
				player::money = player::money - i * 5;
				player::weapons = player::weapons + i;
				exit++;
				break;
			}
		}
		case 27:
		{
			exit++;
			break;
		}
		}
		if (exit == 1)
		{
			break; // Wyjœcie z pêtli nieskoñczonej
		}
	}
	delete[] foodtab;
}