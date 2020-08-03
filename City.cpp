#include "Header.h"
#include <iostream>
#include <fstream>
#include <Windows.h>

using namespace std;

void city::ShowQuests(string name, int text_colour)
{
	fstream CityQuests;

	CityQuests.open("City_Quests.txt", ios::in);

	if (CityQuests.good() == false)
	{
		cout << "Nie ma takiego pliku!" << endl;
		exit(0);
	}
	string line;
	while (getline(CityQuests, linia))
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
	CityQuests.close();
	system("pause");
	city_show_work();
}

void city::city_show_work()
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
		city_show_exit();
		break;
	}

	case 80:
	{
		city_show_buy();
		break;
	}
	case 13:
	{
		city_bakery_work();
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
		city_show_work();
		break;
	}
	}
}
void city::city_show_buy()
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
		city_show_work();
		break;
	}
	case 80:
	{
		city_show_sleep();
		break;
	}
	case 13:
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
		city_buy_food();
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
		city_show_work();
		break;
	}
	}
}
void city::city_show_sleep()
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
		city_show_buy();
		break;
	}
	case 80:
	{
		city_show_conquer();
		break;
	}
	case 13:
	{
		cout << "You have to pay";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 150);
		cout << " 2 ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
		cout << "gold to sleep." << endl;
		cout << "You will regain";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 150);
		cout << " 100% ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
		cout << "of your movement points" << endl;
		cout << "Confirm?" << endl;
		system("pause");
		if (DecisionList::List_a("go to sleep") == true)
		{
			if (player::money < 2)
			{
				cout << "You don't have enough money!" << endl;
			}
			else
			{
				if (player::energy > 50)
				{
					cout << "You do not need to rest! You have " << player::energy << " energy left" << endl;
					system("pause");
					break;
				}
				player::money = player::money - 2;
				player::energy = 50;
				player::food = player::food - player::soldiers * 1; //SCHEMAT NA KONIEC DNIA
				if (player::job_contract == true)
				{
					player::work_lvl_experience + 1;
					if (player::worked_or_not == false)
					{
						player::days_not_worked++;
					}
				}
				player::worked_or_not = false;
				day++;
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
		city_show_work();
		break;
	}
	}
}

void city::city_show_conquer()
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
		city_show_sleep();
		break;
	}
	case 80:
	{
		city_show_exit();
		break;
	}
	case 13:
	{
		bool a = DecisionList::List_a("conquer this city");
		if (a == true)
		{
			if (player::lvl >= 15)
			{
				//TUTAJ MOSZNA
			}
			else
			{
				cout << "You don't have minimal level to do this (15)" << endl;
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
		city_show_work();
		break;
	}
	}
}

void city::city_show_exit()
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
		city_show_conquer();
		break;
	}
	case 80:
	{
		city_show_work();
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
		city_show_work();
		break;
	}
	}
}

void city::city_bakery_work()
{
	system("CLS");
	cout << "Our manufancture is doing well this year." << endl;
	cout << "Thankfully villages produce enough wheat for us all." << endl;
	cout << "Maybe there is something you can do for us..." << endl;
	EnterableObjects::pointer();
	cout << "1. Baking bread" << '\t' << "It will take ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 150);
	cout << mapa::EnergyRequiredWork;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	cout << " energy. You will get ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 150);
	cout << player::soldiers * 3;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	cout << " food" << endl;
	cout << "2. Find regular job" << endl;
	if (player::job_contract == true)
	{
		cout << "3. Go to your job" << endl;
	}

	int znak2 = movement::getting_key();
	switch (znak2)
	{
	case 72:
	{
		if (player::job_contract == true)
		{
			city_go_to_job();
			break;
		}
		city_earn_money();
		break;
	}
	case 80:
	{
		city_earn_money();
		break;
	}
	case 13:
	{
		if (player::energy > 15)
		{
			player::food = player::food + player::soldiers * 3;
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
		city_bakery_work();
		break;
	}
	}
}


void city::city_earn_money()
{
	system("CLS");
	cout << "Our manufancture is doing well this year." << endl;
	cout << "Thankfully villages produce enough wheat for us all." << endl;
	cout << "Maybe there is something you can do for us..." << endl;
	cout << "1. Baking bread " << endl;
	EnterableObjects::pointer();
	cout << "2. Find regular job" << endl;
	if (player::job_contract == true)
	{
		cout << "3. Go to your job" << endl;
	}
	int znak2 = movement::getting_key();
	switch (znak2)
	{
	case 72:
	{
		city_bakery_work();
		break;
	}
	case 80:
	{
		if (player::job_contract == true)
		{
			city_go_to_job();
			break;
		}
		city_bakery_work();
		break;
	}
	case 13:
	{
		job_contract();
	}
	case 27:
	{
		break;
	}
	default:
	{
		cout << "Nie wprowadzono poprawnego znaku" << endl;
		Sleep(1000);
		city_bakery_work();
		break;
	}
	}
}

void city::city_go_to_job()
{
	if (player::job_contract == true)
	{
		system("CLS");
		cout << "Our manufancture is doing well this year." << endl;
		cout << "Thankfully villages produce enough wheat for us all." << endl;
		cout << "Maybe there is something you can do for us..." << endl;
		cout << "1. Baking bread" << endl;
		cout << "2. Find regular job" << endl;
		EnterableObjects::pointer();
		cout << "3. Go to your job" << endl;
		int znak2 = movement::getting_key();
		switch (znak2)
		{
		case 72:
		{
			city_earn_money();
			break;
		}
		case 80:
		{
			city_bakery_work();
			break;
		}
		case 13:
		{
			if (player::energy > 15)
			{
				player::energy = player::energy - 15;
				player::worked_or_not = true;
				player::experience = player::experience - 2;
				player::days_not_worked = 0;
				switch (player::work_lvl)
				{
				case 0:
				{
					player::money = player::money + 5;
					break;
				}
				case 1:
				{
					player::money = player::money + 7;
					break;
				}
				case 2:
				{
					player::money = player::money + 9;
					break;
				}
				case 3:
				{
					player::money = player::money + 11;
					break;
				}
				case 4:
				{
					player::money = player::money + 15;
					break;
				}
				case 5:
				{
					player::money = player::money + 20;
					break;
				}
				}
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
			city_bakery_work();
			break;
		}
		}
	}
}


void city::job_contract()
{
	switch (player::work_lvl)
	{
	case 0:
	{
		if (player::job_contract == true)
		{
			cout << "You already have your job contract on this lvl!" << endl;
			system("pause");
			break;
		}
		fstream contract;
		contract.open("Job_contract_lvl_0.txt", ios::in);
		string line;
		while (getline(contract, line))
		{
			cout << line << endl;
		}
		contract.close();
		cout << endl;
		system("pause");
		bool a = DecisionList::List_a("sign the contract");
		if (a == true)
		{
			player::job_contract = true;
		}
		break;
	}
	case 1:
	{
		if (player::job_contract == true)
		{
			cout << "You already have your job contract on this lvl!" << endl;
			system("pause");
			break;
		}
		fstream contract;
		contract.open("Job_contract_lvl_1.txt", ios::in);
		string line;
		while (getline(contract, line))
		{
			cout << line << endl;
		}
		contract.close();
		cout << endl;
		system("pause");
		bool a = DecisionList::List_a("sign the contract");
		if (a == true)
		{
			player::job_contract = true;
		}
		break;
	}
	case 2:
	{
		if (player::job_contract == true)
		{
			cout << "You already have your job contract on this lvl!" << endl;
			system("pause");
			break;
		}
		fstream contract;
		contract.open("Job_contract_lvl_2.txt", ios::in);
		string line;
		while (getline(contract, line))
		{
			cout << line << endl;
		}
		contract.close();
		cout << endl;
		system("pause");
		bool a = DecisionList::List_a("sign the contract");
		if (a == true)
		{
			player::job_contract = true;
		}
		break;
	}
	case 3:
	{
		if (player::job_contract == true)
		{
			cout << "You already have your job contract on this lvl!" << endl;
			system("pause");
			break;
		}
		fstream contract;
		contract.open("Job_contract_lvl_3.txt", ios::in);
		string line;
		while (getline(contract, line))
		{
			cout << line << endl;
		}
		contract.close();
		cout << endl;
		system("pause");
		bool a = DecisionList::List_a("sign the contract");
		if (a == true)
		{
			player::job_contract = true;
		}
		break;
	}
	case 4:
	{
		if (player::job_contract == true)
		{
			cout << "You already have your job contract on this lvl!" << endl;
			system("pause");
			break;
		}
		fstream contract;
		contract.open("Job_contract_lvl_4.txt", ios::in);
		string line;
		while (getline(contract, line))
		{
			cout << line << endl;
		}
		contract.close();
		cout << endl;
		system("pause");
		bool a = DecisionList::List_a("sign the contract");
		if (a == true)
		{
			player::job_contract = true;
		}
		break;
	}
	case 5:
	{
		if (player::job_contract == true)
		{
			cout << "You already have your job contract on this lvl!" << endl;
			system("pause");
			break;
		}
		fstream contract;
		contract.open("Job_contract_lvl_5.txt", ios::in);
		string line;
		while (getline(contract, line))
		{
			cout << line << endl;
		}
		contract.close();
		cout << endl;
		system("pause");
		bool a = DecisionList::List_a("sign the contract");
		if (a == true)
		{
			player::job_contract = true;
		}
		break;
	}
	}
}
void city::city_buy_food()
{
	system("CLS");
	cout << "You can buy here some wood and food" << endl;
	EnterableObjects::pointer();
	cout << "1. Food" << endl;
	cout << "2. Wood" << endl;
	cout << "3. Weapons" << endl;
	int znak = movement::getting_key();
	switch (znak)
	{
	case 72:
	{
		city_buy_weapons();
		break;
	}
	case 80:
	{
		city_buy_wood();
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
		city_buy_food();
		break;
	}
	}
}
void city::city_buy_wood()
{
	system("CLS");
	cout << "You can buy here some wood and food" << endl;
	cout << "1. Food" << endl;
	EnterableObjects::pointer();
	cout << "2. Wood" << endl;
	cout << "3. Weapons" << endl;
	int znak = movement::getting_key();
	switch (znak)
	{
	case 72:
	{
		city_buy_food();
		break;
	}
	case 80:
	{
		city_buy_weapons();
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
		city_buy_food();
		break;
	}
	}
}
void city::city_buy_weapons()
{
	system("CLS");
	cout << "You can buy here some wood and food" << endl;
	cout << "1. Food" << endl;
	cout << "2. Wood" << endl;
	EnterableObjects::pointer();
	cout << "3. Weapons" << endl;
	int znak = movement::getting_key();
	switch (znak)
	{
	case 72:
	{
		city_buy_wood();
		break;
	}
	case 80:
	{
		city_buy_food();
		break;
	}
	case 13:
	{
		EnterableObjects::buy_weapons();
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
		city_buy_food();
		break;
	}
	}
}