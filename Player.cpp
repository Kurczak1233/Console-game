#include "Header.h"
#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <windows.h>

using namespace std;

char player::name[50];
int player::energy = 50;
int player::money = 100;
int player::wood = 200;
int player::soldiers = 1;
int player::weapons = 5;
int player::food = 100;
int player::PlayerPositionX = 2;
int player::PlayerPositionY = 2;  
int player::work_lvl = 0; // Od tego miejsca update Sejwów!
int player::work_lvl_experience = 20;
int player::lvl = 0;
int player::experience = 20;
bool player::job_contract = false;
int player::days_not_worked = 0;
bool player::worked_or_not = false;
bool player::loadfunction = true;

player::player()
{
}

char* player::CheckNameAndSave()
{
	fstream SaveUserData;
	SaveUserData.open("Users_Save_Game_Data.txt", ios::in);
	if (SaveUserData.good() == false)
	{
		cout << "There is no object like that!" << endl;
		system("pause");
		exit(0);
	}
	string line;
	char name[50];
	int energy;
	int money;
	int wood;
	int soldiers;
	int food;
	int weapons;
	int line_number = 1;
	char Yourname[50];
	cout << "Type your name: ";
	cin >> Yourname;
	while (getline(SaveUserData, line))
	{
		if (strcmp(Yourname, line.c_str()) == 0)
		{
			cout << "That name already exists!" << endl;
			cout << "Would you like to load ";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), main_menu::text_colour);
			cout << Yourname;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
			cout << " game stats?" << endl;
			system("pause"); 
			bool a = DecisionList::List_a("load this stats");
			if (a == true)
			{
				strcpy_s(player::name, Yourname);
				return Yourname;
			}
			else
			{
				cout << "Find new nickname then" << endl;
				system("pause");
				player::CheckNameAndSave();
			}
			SaveUserData.close();
			return Yourname;
		}
	}

	SaveUserData.close();
	SaveUserData.open("Users_Save_Game_Data.txt", ios::in | ios::app);
	if (SaveUserData.good() == false)
	{
		SaveUserData << Yourname << endl;
		system("pause");
		SaveUserData.close();
		exit(0);
	}
	SaveUserData << Yourname << endl;
	SaveUserData << player::energy << endl;
	SaveUserData << player::money << endl;
	SaveUserData << player::wood << endl;
	SaveUserData << player::soldiers << endl;
	SaveUserData << player::food << endl;
	SaveUserData << player::weapons << endl;
	SaveUserData << endl;
	cout << "Your name has been saved" << endl;
	system("pause");
	SaveUserData.close();
	strcpy_s(player::name, Yourname);
	return Yourname;
}
