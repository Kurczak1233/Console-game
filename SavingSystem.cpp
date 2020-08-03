#include <iostream>
#include <fstream>
#include <string>
#include "header.h"
#include <windows.h>

using namespace std;

void SavingSystem::SaveGame()
{
	{
		// OPCJA WYBIERANIA SLOTU!
		slot1colour = CheckSlotColour1(slot1colour);
		slot2colour = CheckSlotColour2(slot2colour);
		slot3colour = CheckSlotColour3(slot3colour);
		slot4colour = CheckSlotColour4(slot4colour);
		slot5colour = CheckSlotColour5(slot5colour);
		{
			system("CLS");

			cout << '\t' << " Pick slot you want to save: " << endl;
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
				fstream SaveSlot1;
				SaveSlot1.open("Slot1.txt", ios::in);
				string line1;
				while (getline(SaveSlot1, line1))
				{
					SaveSlot1.close();
					SaveSlot1.open("Slot1.txt", ios::out);
					SaveSlot1 << player::name << endl;
					SaveSlot1 << player::PlayerPositionX << endl;
					SaveSlot1 << player::PlayerPositionY << endl;
					SaveSlot1 << player::energy << endl;
					SaveSlot1 << player::money << endl;
					SaveSlot1 << player::wood << endl;
					SaveSlot1 << player::soldiers << endl;
					SaveSlot1 << player::food << endl;
					SaveSlot1 << player::weapons << endl;
					SaveSlot1 << mapa::day << endl;
					cout << "Your profile is being saved..." << endl;
					Sleep(1000);
					cout << ".";
					Sleep(1000);
					cout << ".";
					Sleep(1000);
					cout << ".";
					Sleep(500);
					system("CLS");
					cout << "Saving complete" << endl;
					system("pause");
					break;
				}
				SaveSlot1.close();
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
				SaveGame();
				break;
			}
			}
		}
	}
}

int SavingSystem::CheckSlotColour1(int first)
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
int SavingSystem::CheckSlotColour2(int second)
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
int SavingSystem::CheckSlotColour3(int third)
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
int SavingSystem::CheckSlotColour4(int fourth)
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
int SavingSystem::CheckSlotColour5(int fifth)
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

void SavingSystem::slot2()
{
	slot1colour = CheckSlotColour1(slot1colour);
	slot2colour = CheckSlotColour2(slot2colour);
	slot3colour = CheckSlotColour3(slot3colour);
	slot4colour = CheckSlotColour4(slot4colour);
	slot5colour = CheckSlotColour5(slot5colour);
	system("CLS");
	cout << '\t' << " Pick slot you want to save: " << endl;
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
		SaveGame();
		break;
	}
	case 80: //dó³
	{
		slot3();
		break;
	}
	case 13: //enter
	{
		fstream SaveSlot2;
		SaveSlot2.open("Slot2.txt", ios::in);
		string line1;
		while (getline(SaveSlot2, line1))
		{
			SaveSlot2.close();
			SaveSlot2.open("Slot2.txt", ios::out);
			SaveSlot2 << player::name << endl;
			SaveSlot2 << player::PlayerPositionX << endl;
			SaveSlot2 << player::PlayerPositionY << endl;
			SaveSlot2 << player::energy << endl;
			SaveSlot2 << player::money << endl;
			SaveSlot2 << player::wood << endl;
			SaveSlot2 << player::soldiers << endl;
			SaveSlot2 << player::food << endl;
			SaveSlot2 << player::weapons << endl;
			SaveSlot2 << mapa::day << endl;
			cout << "Your profile is being saved..." << endl;
			Sleep(1000);
			cout << ".";
			Sleep(1000);
			cout << ".";
			Sleep(1000);
			cout << ".";
			Sleep(500);
			system("CLS");
			cout << "Saving complete" << endl;
			system("pause");
			break;
		}
		break;
		SaveSlot2.close();

	}
	case 27: //esc
	{
		break;
	}
	default:
	{
		cout << "There is no available sign like that, try again" << endl;
		Sleep(1000);
		SaveGame();
		break;
	}
	}
}
void SavingSystem::slot3()
{
	system("CLS");
	slot1colour = CheckSlotColour1(slot1colour);
	slot2colour = CheckSlotColour2(slot2colour);
	slot3colour = CheckSlotColour3(slot3colour);
	slot4colour = CheckSlotColour4(slot4colour);
	slot5colour = CheckSlotColour5(slot5colour);
	cout << '\t' << " Pick slot you want to save: " << endl;
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
		fstream SaveSlot3;
		SaveSlot3.open("Slot3.txt", ios::in);
		string line1;
		while (getline(SaveSlot3, line1))
		{
			SaveSlot3.close();
			SaveSlot3.open("Slot3.txt", ios::out);
			SaveSlot3 << player::name << endl;
			SaveSlot3 << player::PlayerPositionX << endl;
			SaveSlot3 << player::PlayerPositionY << endl;
			SaveSlot3 << player::energy << endl;
			SaveSlot3 << player::money << endl;
			SaveSlot3 << player::wood << endl;
			SaveSlot3 << player::soldiers << endl;
			SaveSlot3 << player::food << endl;
			SaveSlot3 << player::weapons << endl;
			SaveSlot3 << mapa::day << endl;
			cout << "Your profile is being saved..." << endl;
			Sleep(1000);
			cout << ".";
			Sleep(1000);
			cout << ".";
			Sleep(1000);
			cout << ".";
			Sleep(500);
			system("CLS");
			cout << "Saving complete" << endl;
			system("pause");
			break;

		}
		SaveSlot3.close();
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
		SaveGame();
		break;
	}
	}
}
void SavingSystem::slot4()
{
	system("CLS");
	slot1colour = CheckSlotColour1(slot1colour);
	slot2colour = CheckSlotColour2(slot2colour);
	slot3colour = CheckSlotColour3(slot3colour);
	slot4colour = CheckSlotColour4(slot4colour);
	slot5colour = CheckSlotColour5(slot5colour);
	cout << '\t' << " Pick slot you want to save: " << endl;
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
		fstream SaveSlot4;
		SaveSlot4.open("Slot4.txt", ios::in);
		string line1;
		while (getline(SaveSlot4, line1))
		{
			SaveSlot4.close();
			SaveSlot4.open("Slot4.txt", ios::out);
			SaveSlot4 << player::name << endl;
			SaveSlot4 << player::PlayerPositionX << endl;
			SaveSlot4 << player::PlayerPositionY << endl;
			SaveSlot4 << player::energy << endl;
			SaveSlot4 << player::money << endl;
			SaveSlot4 << player::wood << endl;
			SaveSlot4 << player::soldiers << endl;
			SaveSlot4 << player::food << endl;
			SaveSlot4 << player::weapons << endl;
			SaveSlot4 << mapa::day << endl;
			cout << "Your profile is being saved..." << endl;
			Sleep(1000);
			cout << ".";
			Sleep(1000);
			cout << ".";
			Sleep(1000);
			cout << ".";
			Sleep(500);
			system("CLS");
			cout << "Saving complete" << endl;
			system("pause");
			break;

		}
		SaveSlot4.close();
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
		SaveGame();
		break;
	}
	}
}
void SavingSystem::slot5()
{
	system("CLS");
	slot1colour = CheckSlotColour1(slot1colour);
	slot2colour = CheckSlotColour2(slot2colour);
	slot3colour = CheckSlotColour3(slot3colour);
	slot4colour = CheckSlotColour4(slot4colour);
	slot5colour = CheckSlotColour5(slot5colour);
	cout << '\t' << " Pick slot you want to save: " << endl;
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
		SaveGame();
		break;
	}
	case 13: //enter
	{
		fstream SaveSlot5;
		SaveSlot5.open("Slot5.txt", ios::in);
		string line1;
		while (getline(SaveSlot5, line1))
		{
			SaveSlot5.close();
			SaveSlot5.open("Slot5.txt", ios::out);
			SaveSlot5 << player::name << endl;
			SaveSlot5 << player::PlayerPositionX << endl;
			SaveSlot5 << player::PlayerPositionY << endl;
			SaveSlot5 << player::energy << endl;
			SaveSlot5 << player::money << endl;
			SaveSlot5 << player::wood << endl;
			SaveSlot5 << player::soldiers << endl;
			SaveSlot5 << player::food << endl;
			SaveSlot5 << player::weapons << endl;
			SaveSlot5 << mapa::day << endl;
			cout << "Your profile is being saved..." << endl;
			Sleep(1000);
			cout << ".";
			Sleep(1000);
			cout << ".";
			Sleep(1000);
			cout << ".";
			Sleep(500);
			system("CLS");
			cout << "Saving complete" << endl;
			system("pause");
			break;

		}
		SaveSlot5.close();
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
		SaveGame();
		break;
	}
	}
}