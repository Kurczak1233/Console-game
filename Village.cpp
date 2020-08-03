#include "Header.h"
#include <iostream>
#include <fstream>
#include <windows.h>

using namespace std;

void village::ShowQuests(string name, int text_colour)
{
	fstream VillageQuests;

	VillageQuests.open("Village_Quests.txt", ios::in);

	if (VillageQuests.good() == false)
	{
		cout << "Nie ma takiego pliku!" << endl;
		exit(0);
	}
	string linia;
	int counter = 1;
	while (getline(VillageQuests, linia))
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
	VillageQuests.close();
	system("pause");
	village_show_work();
}

void village::village_show_work()
{
	system("CLS");
	cout << "What would you like to do ?" << endl;
	EnterableObjects::pointer();
	cout << "1. Work" << endl;
	cout << "2. Buy goods" << endl;
	cout << "3. Sleep" << endl;
	cout << "4. Conquer" << endl;
	cout << "5. Exit" << endl;
	int znak = movement::getting_key();
	switch (znak)
	{
	case 72:
	{
		village_show_exit();
		break;
	}
	case 80:
	{
		village_show_buy();
		break;
	}
	case 13:
	{
		village_field_work();
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
		village_show_work();
		break;
	}
	}
}
void village::village_show_buy()
{
	system("CLS");
	cout << "What would you like to do ?" << endl;
	cout << "1. Work" << endl;
	EnterableObjects::pointer();
	cout << "2. Buy goods" << endl;
	cout << "3. Sleep" << endl;
	cout << "4. Conquer" << endl;
	cout << "5. Exit" << endl;
	int znak = movement::getting_key();
	switch (znak)
	{
	case 72:
	{
		village_show_work();
		break;
	}
	case 80:
	{
		village_show_sleep();
		break;
	}
	case 13:
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
		village_buy_food();
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
		village_show_work();
		break;
	}
	}
}
void village::village_show_sleep()
{
	system("CLS");
	cout << "What would you like to do ?" << endl;
	cout << "1. Work" << endl;
	cout << "2. Buy goods" << endl;
	EnterableObjects::pointer();
	cout << "3. Sleep" << endl;
	cout << "4. Conquer" << endl;
	cout << "5. Exit" << endl;
	int znak = movement::getting_key();
	switch (znak)
	{
	case 72:
	{
		village_show_buy();
		break;
	}
	case 80:
	{
		village_show_conquer();
		break;
	}
	case 13:
	{
		cout << "You have to pay";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 150);
		cout << " 1 ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
		cout << "gold to sleep." << endl;
		cout << "You will regain only";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 150);
		cout << " 80% ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
		cout << "of your movement points" << endl;
		system("pause");
		if (DecisionList::List_a("sleep in this conditions") == true)
		{
			if (player::money < 1)
			{
				cout << "You don't have enough money!" << endl;
			}
			else
			{
				if (player::energy > 40)
				{
					cout << "You do not need to rest! You have " <<  player::energy << " energy left" << endl;
					system("pause");
					break;
				}
				player::money = player::money - 1;
				player::energy = 40;
				player::food = player::food - player::soldiers * 1; //SCHEMAT NA KONIEC DNIA
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
		village_show_work();
		break;
	}
	}
}

void village::village_show_conquer()
{
	system("CLS");
	cout << "What would you like to do ?" << endl;
	cout << "1. Work" << endl;
	cout << "2. Buy goods" << endl;
	cout << "3. Sleep" << endl;
	EnterableObjects::pointer();
	cout << "4. Conquer" << endl;
	cout << "5. Exit" << endl;
	int znak = movement::getting_key();
	switch (znak)
	{
	case 72:
	{
		village_show_sleep();
		break;
	}
	case 80:
	{
		village_show_exit();
		break;
	}
	case 13:
	{
		bool a = DecisionList::List_a("conquer this city");
		if (a == true)
		{
			if (player::lvl >= 5)
			{
				//TUTAJ MOSZNA
			}
			else
			{
				cout << "You don't have minimal level to do this (5)" << endl;
				system("pause");
				break;
			}
			break;
		}
	}
	case 27:
	{
		break;
	}
	default:
	{
		cout << "Nie wprowadzono poprawnego znaku" << endl;
		Sleep(1000);
		village_show_work();
		break;
	}
	}
}

void village::village_show_exit()
{
	system("CLS");
	cout << "What would you like to do ?" << endl;
	cout << "1. Work" << endl;
	cout << "2. Buy goods" << endl;
	cout << "3. Sleep" << endl;
	cout << "4. Conquer" << endl;
	EnterableObjects::pointer();
	cout << "5. Exit" << endl;
	int znak = movement::getting_key();
	switch (znak)
	{
	case 72:
	{
		village_show_conquer();
		break;
	}
	case 80:
	{
		village_show_work();
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
		village_show_work();
		break;
	}
	}
}
void village::village_field_work()
{
	system("CLS");
	cout << "We are poor villagers." << endl;
	cout << "As you can see, we have a lot of fields and forrests nearby" << endl;
	cout << "Maybe you could help us a little..." << endl;
	EnterableObjects::pointer();
	cout << "1. Cutting trees" << '\t' << "It will take ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 150);
	cout << mapa::EnergyRequiredWork;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	cout << " energy. You will get ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 150);
	cout << 3;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	cout << " wood" << endl;
	cout << "2. Working on fields" << endl;
	int znak2 = movement::getting_key();
	switch (znak2)
	{
	case 72:
	{
		village_forrest_work();
		break;
	}
	case 80:
	{
		village_forrest_work();
		break;
	}
	case 13:
	{
		if (player::energy > 15)
		{
			player::wood = player::wood + 3;
			player::energy = player::energy - 15;
			player::experience = player::experience - 2;
			break;
		}
		else
		{
			cout << "You have no energy to do that!" << endl;
			system("pause");
			break;
		}
	}
	case 27:
	{
		break;
	}
	default:
	{                                                         
		cout << "Nie wprowadzono poprawnego znaku" << endl;
		Sleep(1000);
		village_forrest_work();
		break;
	}
	}
}
void village::village_forrest_work()
{
	system("CLS");
	cout << "We are poor villagers." << endl;
	cout << "As you can see, we have a lot of fields and forrests nearby" << endl;
	cout << "Maybe you could help us a little..." << endl;
	cout << "1. Cutting trees" << endl;
	EnterableObjects::pointer();
	cout << "2. Working on fields" << '\t' << "It will take ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 150);
	cout << mapa::EnergyRequiredWork;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	cout << " energy. You will get ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 150);
	cout << 3;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	cout << " food" << endl;
	int znak2 = movement::getting_key();
	switch (znak2)
	{
	case 72:
	{
		village_field_work();
		break;
	}
	case 80:
	{
		village_field_work();
		break;
	}
	case 13:
	{
		if (player::energy > 15)
		{
			player::food = player::food + 3;
			player::energy = player::energy - 15;
			player::experience = player::experience - 2;
			break;
		}
		else
		{
			cout << "You have no energy to do that!" << endl;
			system("pause");
			break;
		}
	}
	case 27:
	{
		break;
	}
	default:
	{
		cout << "Nie wprowadzono poprawnego znaku" << endl;
		Sleep(1000);
		village_forrest_work();
		break;
	}
	}
}

void village::village_buy_food()
{
	system("CLS");
	cout << "You can buy here some wood and food" << endl;
	EnterableObjects::pointer();
	cout << "1. Food" << endl;
	cout << "2. Wood" << endl;
	int znak = movement::getting_key();
	switch (znak)
	{
	case 72:
	{
		village_buy_wood();
		break;
	}
	case 80:
	{
		village_buy_wood();
		break;
	}
	case 13:
	{
		EnterableObjects::buy_food();
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
		village_buy_food();
		break;
	}
	}
}
void village::village_buy_wood()
{
	system("CLS");
	cout << "You can buy here some wood and food" << endl;
	cout << "1. Food" << endl;
	EnterableObjects::pointer();
	cout << "2. Wood" << endl;
	int znak = movement::getting_key();
	switch (znak)
	{
	case 72:
	{
		village_buy_food();
		break;
	}
	case 80:
	{
		village_buy_food();
		break;
	}
	case 13:
	{
		EnterableObjects::buy_wood();
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
		village_buy_wood();
		break;
	}
	}
}