#include <iostream>
#include <fstream>
#include <string>
#include "header.h"
#include <windows.h>

using namespace std;

void LoadingSystem::LoadGame()
{
	slot1colour = CheckSlotColour1(slot1colour);
	slot2colour = CheckSlotColour2(slot2colour);
	slot3colour = CheckSlotColour3(slot3colour);
	slot4colour = CheckSlotColour4(slot4colour);
	slot5colour = CheckSlotColour5(slot5colour);
	system("CLS");
	cout << '\t' << " Pick slot you want to load: " << endl;
	EnterableObjects::pointer();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), slot1colour);
	cout << " Slot 1" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), slot2colour);
	cout << " Slot 2" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), slot3colour);
	cout << " Slot 3" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), slot4colour);
	cout << " Slot 4" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), slot5colour);
	cout << " Slot 5" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	int znak = movement::getting_key();
	switch (znak)
	{
	case 72: //góra
	{
		slot5();
		break;
	}
	case 80: //dó³
	{
		slot2();
		break;
	}
	case 13: //enter
	{
		if (slot1colour == 10)
		{
			cout << "This save is empty!" << endl;
			player::loadfunction = false;
			system("pause");
			break;
		}
		fstream LoadSlot1;
		string line1;
		LoadSlot1.open("Slot1.txt", ios::in);
		int counter = 1;
		while (getline(LoadSlot1, line1))
		{
			switch (counter)
			{
			case 1: strcpy_s(player::name, line1.c_str()); break;  
			case 2: player::PlayerPositionX = atoi(line1.c_str()); break;
			case 3: player::PlayerPositionY = atoi(line1.c_str()); break;
			case 4: player::energy = atoi(line1.c_str()); break;
			case 5: player::money = atoi(line1.c_str()); break;
			case 6: player::wood = atoi(line1.c_str()); break;
			case 7: player::soldiers = atoi(line1.c_str()); break;
			case 8: player::food = atoi(line1.c_str()); break;
			case 9: player::weapons = atoi(line1.c_str()); break;
			case 10: mapa::day = atoi(line1.c_str()); break;
			}
			counter++;
		}		
		cout << "Your profile is being loaded..." << endl;
			Sleep(1000);
			cout << ".";
			Sleep(1000);
			cout << ".";
			Sleep(1000);
			cout << ".";
			Sleep(500);
			system("CLS");
			cout << "Loading complete" << endl;
			system("pause");
		LoadSlot1.close();
		break;
	}
	case 27: //esc
	{
		break;
	}
	default:
	{
		cout << "There is no available sign like that, try again" << endl;
		Sleep(1000);
		LoadGame();
		break;
	}
	}
}

int LoadingSystem::CheckSlotColour1(int first)
{
	fstream SaveSlot1;
	first = 0;
	string line;
	SaveSlot1.open("Slot1.txt", ios::in);
	while (getline(SaveSlot1, line))
	{
		if (line == "empty") first = 10;
		else first = 12;
	}
	SaveSlot1.close();
	return first;
}
int LoadingSystem::CheckSlotColour2(int second)
{
	fstream SaveSlot2;
	second = 0;
	string line;
	SaveSlot2.open("Slot2.txt", ios::in);
	while (getline(SaveSlot2, line))
	{
		if (line == "empty") second = 10;
		else second = 12;
	}
	SaveSlot2.close();
	return second;
}
int LoadingSystem::CheckSlotColour3(int third)
{
	fstream SaveSlot3;
	third = 0;
	string line;
	SaveSlot3.open("Slot3.txt", ios::in);
	while (getline(SaveSlot3, line))
	{
		if (line == "empty") third = 10;
		else third = 12;
	}
	SaveSlot3.close();
	return third;
}
int LoadingSystem::CheckSlotColour4(int fourth)
{
	fstream SaveSlot4;
	fourth = 0;
	string line;
	SaveSlot4.open("Slot4.txt", ios::in);
	while (getline(SaveSlot4, line))
	{
		if (line == "empty") fourth = 10;
		else fourth = 12;
	}
	SaveSlot4.close();
	return fourth;
}
int LoadingSystem::CheckSlotColour5(int fifth)
{
	fstream SaveSlot5;
	fifth = 0;
	string line;
	SaveSlot5.open("Slot5.txt", ios::in);
	while (getline(SaveSlot5, line))
	{
		if (line == "empty") fifth = 10;
		else fifth = 12;
	}
	SaveSlot5.close();
	return fifth;
}

void LoadingSystem::slot2()
{
	slot1colour = CheckSlotColour1(slot1colour);
	slot2colour = CheckSlotColour2(slot2colour);
	slot3colour = CheckSlotColour3(slot3colour);
	slot4colour = CheckSlotColour4(slot4colour);
	slot5colour = CheckSlotColour5(slot5colour);
	system("CLS");
	cout << '\t' << " Pick slot you want to load: " << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), slot1colour);
	cout << " Slot 1" << endl;
	EnterableObjects::pointer();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), slot2colour);
	cout << " Slot 2" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), slot3colour);
	cout << " Slot 3" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), slot4colour);
	cout << " Slot 4" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), slot5colour);
	cout << " Slot 5" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	int znak = movement::getting_key();
	switch (znak)
	{
	case 72: //góra
	{
		LoadGame();
		break;
	}
	case 80: //dó³
	{
		slot3();
		break;
	}
	case 13: //enter
	{
		if (slot2colour == 10)
		{
			cout << "This save is empty!" << endl;
			system("pause");
			break;
		}
		fstream LoadSlot1;
		string line1;
		LoadSlot1.open("Slot2.txt", ios::in);
		int counter = 1;
		while (getline(LoadSlot1, line1))
		{
			switch (counter)
			{
			case 1: strcpy_s(player::name, line1.c_str()); break;
			case 2: player::PlayerPositionX = atoi(line1.c_str()); break;
			case 3: player::PlayerPositionY = atoi(line1.c_str()); break;
			case 4: player::energy = atoi(line1.c_str()); break;
			case 5: player::money = atoi(line1.c_str()); break;
			case 6: player::wood = atoi(line1.c_str()); break;
			case 7: player::soldiers = atoi(line1.c_str()); break;
			case 8: player::food = atoi(line1.c_str()); break;
			case 9: player::weapons = atoi(line1.c_str()); break;
			case 10: mapa::day = atoi(line1.c_str()); break;
			}
			counter++;
		}
		cout << "Your profile is being loaded..." << endl;
		Sleep(1000);
		cout << ".";
		Sleep(1000);
		cout << ".";
		Sleep(1000);
		cout << ".";
		Sleep(500);
		system("CLS");
		cout << "Loading complete" << endl;
		system("pause");
		LoadSlot1.close();
		break;
	}
	case 27: //esc
	{
		break;
	}
	default:
	{
		cout << "There is no available sign like that, try again" << endl;
		Sleep(1000);
		LoadGame();
		break;
	}
	}
}
void LoadingSystem::slot3()
{
	slot1colour = CheckSlotColour1(slot1colour);
	slot2colour = CheckSlotColour2(slot2colour);
	slot3colour = CheckSlotColour3(slot3colour);
	slot4colour = CheckSlotColour4(slot4colour);
	slot5colour = CheckSlotColour5(slot5colour);
	system("CLS");
	cout << '\t' << " Pick slot you want to load: " << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), slot1colour);
	cout << " Slot 1" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), slot2colour);
	cout << " Slot 2" << endl;
	EnterableObjects::pointer();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), slot3colour);
	cout << " Slot 3" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), slot4colour);
	cout << " Slot 4" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), slot5colour);
	cout << " Slot 5" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	int znak = movement::getting_key();
	switch (znak)
	{
	case 72: //góra
	{
		slot2();
		break;
	}
	case 80: //dó³
	{
		slot4();
		break;
	}
	case 13: //enter
	{
		if (slot3colour == 10)
		{
			cout << "This save is empty!" << endl;
			system("pause");
			break;
		}
		fstream LoadSlot1;
		string line1;
		LoadSlot1.open("Slot3.txt", ios::in);
		int counter = 1;
		while (getline(LoadSlot1, line1))
		{
			switch (counter)
			{
			case 1: strcpy_s(player::name, line1.c_str()); break;
			case 2: player::PlayerPositionX = atoi(line1.c_str()); break;
			case 3: player::PlayerPositionY = atoi(line1.c_str()); break;
			case 4: player::energy = atoi(line1.c_str()); break;
			case 5: player::money = atoi(line1.c_str()); break;
			case 6: player::wood = atoi(line1.c_str()); break;
			case 7: player::soldiers = atoi(line1.c_str()); break;
			case 8: player::food = atoi(line1.c_str()); break;
			case 9: player::weapons = atoi(line1.c_str()); break;
			case 10: mapa::day = atoi(line1.c_str()); break;
			}
			counter++;
		}
		cout << "Your profile is being loaded..." << endl;
		Sleep(1000);
		cout << ".";
		Sleep(1000);
		cout << ".";
		Sleep(1000);
		cout << ".";
		Sleep(500);
		system("CLS");
		cout << "Loading complete" << endl;
		system("pause");
		LoadSlot1.close();
		break;
	}
	case 27: //esc
	{
		break;
	}
	default:
	{
		cout << "There is no available sign like that, try again" << endl;
		Sleep(1000);
		LoadGame();
		break;
	}
	}
}

void LoadingSystem::slot4()
{
	slot1colour = CheckSlotColour1(slot1colour);
	slot2colour = CheckSlotColour2(slot2colour);
	slot3colour = CheckSlotColour3(slot3colour);
	slot4colour = CheckSlotColour4(slot4colour);
	slot5colour = CheckSlotColour5(slot5colour);
	system("CLS");
	cout << '\t' << " Pick slot you want to load: " << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), slot1colour);
	cout << " Slot 1" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), slot2colour);
	cout << " Slot 2" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), slot3colour);
	cout << " Slot 3" << endl;
	EnterableObjects::pointer();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), slot4colour);
	cout << " Slot 4" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), slot5colour);
	cout << " Slot 5" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	int znak = movement::getting_key();
	switch (znak)
	{
	case 72: //góra
	{
		slot3();
		break;
	}
	case 80: //dó³
	{
		slot5();
		break;
	}
	case 13: //enter
	{
		if (slot4colour == 10)
		{
			cout << "This save is empty!" << endl;
			system("pause");
			break;
		}
		fstream LoadSlot1;
		string line1;
		LoadSlot1.open("Slot4.txt", ios::in);
		int counter = 1;
		while (getline(LoadSlot1, line1))
		{
			switch (counter)
			{
			case 1: strcpy_s(player::name, line1.c_str()); break;
			case 2: player::PlayerPositionX = atoi(line1.c_str()); break;
			case 3: player::PlayerPositionY = atoi(line1.c_str()); break;
			case 4: player::energy = atoi(line1.c_str()); break;
			case 5: player::money = atoi(line1.c_str()); break;
			case 6: player::wood = atoi(line1.c_str()); break;
			case 7: player::soldiers = atoi(line1.c_str()); break;
			case 8: player::food = atoi(line1.c_str()); break;
			case 9: player::weapons = atoi(line1.c_str()); break;
			case 10: mapa::day = atoi(line1.c_str()); break;
			}
			counter++;
		}
		cout << "Your profile is being loaded..." << endl;
		Sleep(1000);
		cout << ".";
		Sleep(1000);
		cout << ".";
		Sleep(1000);
		cout << ".";
		Sleep(500);
		system("CLS");
		cout << "Loading complete" << endl;
		system("pause");
		LoadSlot1.close();
		break;
	}
	case 27: //esc
	{
		break;
	}
	default:
	{
		cout << "There is no available sign like that, try again" << endl;
		Sleep(1000);
		LoadGame();
		break;
	}
	}
}

void LoadingSystem::slot5()
{
	slot1colour = CheckSlotColour1(slot1colour);
	slot2colour = CheckSlotColour2(slot2colour);
	slot3colour = CheckSlotColour3(slot3colour);
	slot4colour = CheckSlotColour4(slot4colour);
	slot5colour = CheckSlotColour5(slot5colour);
	system("CLS");
	cout << '\t' << " Pick slot you want to load: " << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), slot1colour);
	cout << " Slot 1" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), slot2colour);
	cout << " Slot 2" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), slot3colour);
	cout << " Slot 3" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), slot4colour);
	cout << " Slot 4" << endl;
	EnterableObjects::pointer();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), slot5colour);
	cout << " Slot 5" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	int znak = movement::getting_key();
	switch (znak)
	{
	case 72: //góra
	{
		slot4();
		break;
	}
	case 80: //dó³
	{
		LoadGame();
		break;
	}
	case 13: //enter
	{
		if (slot4colour == 10)
		{
			cout << "This save is empty!" << endl;
			system("pause");
			break;
		}
		fstream LoadSlot1;
		string line1;
		LoadSlot1.open("Slot5.txt", ios::in);
		int counter = 1;
		while (getline(LoadSlot1, line1))
		{
			switch (counter)
			{
			case 1: strcpy_s(player::name, line1.c_str()); break;
			case 2: player::PlayerPositionX = atoi(line1.c_str()); break;
			case 3: player::PlayerPositionY = atoi(line1.c_str()); break;
			case 4: player::energy = atoi(line1.c_str()); break;
			case 5: player::money = atoi(line1.c_str()); break;
			case 6: player::wood = atoi(line1.c_str()); break;
			case 7: player::soldiers = atoi(line1.c_str()); break;
			case 8: player::food = atoi(line1.c_str()); break;
			case 9: player::weapons = atoi(line1.c_str()); break;
			case 10: mapa::day = atoi(line1.c_str()); break;
			}
			counter++;
		}
		cout << "Your profile is being loaded..." << endl;
		Sleep(1000);
		cout << ".";
		Sleep(1000);
		cout << ".";
		Sleep(1000);
		cout << ".";
		Sleep(500);
		system("CLS");
		cout << "Loading complete" << endl;
		system("pause");
		LoadSlot1.close();
		break;
	}
	case 27: //esc
	{
		break;
	}
	default:
	{
		cout << "There is no available sign like that, try again" << endl;
		Sleep(1000);
		LoadGame();
		break;
	}
	}
}
