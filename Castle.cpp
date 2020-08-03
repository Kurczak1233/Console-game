#include "Header.h"
#include <iostream>
#include <fstream>
#include <windows.h>

using namespace std;

void castle::ShowQuests(string name, int text_colour)
{
	fstream CastleQuests;

	CastleQuests.open("Castle_Quests.txt", ios::in);

	if (CastleQuests.good() == false)
	{
		cout << "Nie ma takiego pliku!" << endl;
		exit(0);
	}
	string linia;
	int counter = 1;
	while (getline(CastleQuests, linia))
	{
		if (counter == 1)
		{
			cout << linia;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), text_colour);
			linia = name;
			cout << linia << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
			counter++;
			continue;
		}
		cout << linia << endl;
		counter++;
	}
	CastleQuests.close();
	system("pause");
	castle_show_work();
}


void castle::castle_show_work()
{
	system("CLS");
	cout << "What would you like to do ?" << endl;
	EnterableObjects::pointer();
	cout << "1. Work" << endl;
	cout << "2. Recruit" << endl;
	cout << "3. Sleep" << endl;
	cout << "4. Conquer" << endl;
	cout << "5. Exit" << endl;
	int znak = movement::getting_key();
	switch (znak)
	{
	case 72:
	{
		castle_show_exit();
		break;
	}
	case 80:
	{
		castle_show_recruit();
		break;
	}
	case 13:
	{
		castle_smith_work();
		break;
	}
	case 27:
	{
		break;
	}
	default:
	{
		cout << "Nie wprowadzono poprawnego znaku" << endl;
		Sleep(1000);
		castle_show_work();
		break;
	}
	}
}
void castle::castle_show_recruit()
{
	system("CLS");
	cout << "What would you like to do ?" << endl;
	cout << "1. Work" << endl;
	EnterableObjects::pointer();
	cout << "2. Recruit" << endl;
	cout << "3. Sleep" << endl;
	cout << "4. Conquer" << endl;
	cout << "5. Exit" << endl;
	int znak = movement::getting_key();
	switch (znak)
	{
	case 72:
	{
		castle_show_work();
		break;
	}
	case 80:
	{
		castle_show_sleep();
		break;
	}
	case 13:
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
		//castle_recruit();
		break;
	}
	case 27:
	{
		break;
	}
	default:
	{
		cout << "Nie wprowadzono poprawnego znaku" << endl;
		Sleep(1000);
		castle_show_work();
		break;
	}
	}
}
void castle::castle_show_sleep()
{
	system("CLS");
	cout << "What would you like to do ?" << endl;
	cout << "1. Work" << endl;
	cout << "2. Recruit" << endl;
	EnterableObjects::pointer();
	cout << "3. Sleep" << endl;
	cout << "4. Conquer" << endl;
	cout << "5. Exit" << endl;
	int znak = movement::getting_key();
	switch (znak)
	{
	case 72:
	{
		castle_show_recruit();
		break;
	}
	case 80:
	{
		castle_show_conquer();
		break;
	}
	case 13:
	{
		cout << "You have to pay";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 150);
		cout << " 3 ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
		cout << "gold to sleep." << endl;
		cout << "You will regain";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 150);
		cout << " 120% ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
		cout << "of your movement points" << endl;
		cout << "Confirm?" << endl;
		system("pause");
		if (DecisionList::List_a("go to sleep") == true)
		{
			if (player::money < 3)
			{
				cout << "You don't have enough money!" << endl;
			}
			else
			{
				if (player::energy > 60)
				{
					cout << "You do not need to rest! You have " << player::energy << " energy left" << endl;
					system("pause");
					break;
				}
				player::money = player::money - 3;
				player::energy = 60;
				player::food = player::food - player::soldiers * 1;
				day++;
				if (player::job_contract == true)
				{
					player::work_lvl_experience + 1;
					if (player::worked_or_not == false)
					{
						player::days_not_worked++;
					}
				}
				player::worked_or_not = false;
			}
		}
		break;
	}
	case 27:
	{
		break;
	}
	default:
	{
		cout << "Nie wprowadzono poprawnego znaku" << endl;
		Sleep(1000);
		castle_show_work();
		break;
	}
	}
}

void castle::castle_show_conquer()
{
	system("CLS");
	cout << "What would you like to do ?" << endl;
	cout << "1. Work" << endl;
	cout << "2. Recruit" << endl;
	cout << "3. Sleep" << endl;
	EnterableObjects::pointer();
	cout << "4. Conquer" << endl;
	cout << "5. Exit" << endl;
	int znak = movement::getting_key();
	switch (znak)
	{
	case 72:
	{
		castle_show_sleep();
		break;
	}
	case 80:
	{
		castle_show_exit();
		break;
	}
	case 13:
	{
		bool a = DecisionList::List_a("conquer this city");
		if (a == true)
		{
			if (player::lvl >= 30)
			{
				//TUTAJ MOSZNA
			}
			else
			{
				cout << "You don't have minimal level to do this (30)" << endl;
				system("pause");
				break;
			}
			//Metoda WALKI O WIEŒ!
			//RANDY  + Ma³e mapki z interaktywnoœci¹ gracza?
			//Szar¿a wieœniaków na mapce i unikaæ np
			//Wejœæ do domku unikaj¹c takiej szar¿y
		}
		break;
	}
	case 27:
	{
		break;
	}
	default:
	{
		cout << "Nie wprowadzono poprawnego znaku" << endl;
		Sleep(1000);
		castle_show_work();
		break;
	}
	}
}

void castle::castle_show_exit()
{
	system("CLS");
	cout << "What would you like to do ?" << endl;
	cout << "1. Work" << endl;
	cout << "2. Recruit" << endl;
	cout << "3. Sleep" << endl;
	cout << "4. Conquer" << endl;
	EnterableObjects::pointer();
	cout << "5. Exit" << endl;
	int znak = movement::getting_key();
	switch (znak)
	{
	case 72:
	{
		castle_show_conquer();
		break;
	}
	case 80:
	{
		castle_show_work();
		break;
	}
	case 13:
	{
		break;
	}
	case 27:
	{
		break;
	}
	default:
	{
		cout << "Nie wprowadzono poprawnego znaku" << endl;
		Sleep(1000);
		castle_show_work();
		break;
	}
	}
}

void castle::castle_smith_work()
{
		system("CLS");
		cout << "Welcome adventurer!" << endl;
		cout << "We've got a lot of iron recently!" << endl;
		cout << "If you are strong you will be good smith!" << endl;
		EnterableObjects::pointer();
		cout << "1. Forge weapons " << '\t' << "It will take ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 150);
		cout << mapa::EnergyRequiredWork;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
		cout << " energy. You will get ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 150);
		cout << 3;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
		cout << " weapons" << endl;
		int znak2 = movement::getting_key();
		switch (znak2)
		{
		case 72:
		{
			castle_smith_work();
			break;
		}
		case 80:
		{
			castle_smith_work();
			break;
		}
		case 13:
		{
			player::weapons = player::weapons + 3;
			player::energy = player::energy - 15;
			player::experience = player::experience - 2;
		}
		case 27:
		{
			break;
		}
		default:
		{
			cout << "Nie wprowadzono poprawnego znaku" << endl;
			Sleep(1000);
			castle_smith_work();
			break;
		}
		}
}