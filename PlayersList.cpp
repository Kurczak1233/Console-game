#include <iostream>
#include <string>
#include <fstream>
#include "Header.h"

using namespace std;


ostream& operator<< (ostream& os, player& wektor)
{
	os << wektor.name << endl;
	os << wektor.energy << endl;
	os << wektor.money << endl;
	os << wektor.wood << endl;
	os << wektor.soldiers << endl;
	os << wektor.food << endl;
	os << wektor.weapons << endl;
	cout << endl;
	return os;
}
void PlayersList::ShowList()
{
	player* temp = first;
	fstream SaveUserData;
	SaveUserData.open("User_Data.txt", ios::in);
	while (temp)
	{
		cout << *temp << endl;
		temp = temp->next;
	}
	SaveUserData.close();
} 
void PlayersList::SaveUsersData()
{
	fstream SaveUserData;
	player *temp = first;
	{
		SaveUserData.open("Users_Save_Game_Data.txt", ios::out | ios::app);
		if (SaveUserData.good() == false)
		{
			cout << "There is no object like that!" << endl;
			exit(0);
		}
		SaveUserData << temp->name << endl;
		SaveUserData << temp->energy << endl;
		SaveUserData << temp->money << endl;
		SaveUserData << temp->wood << endl;
		SaveUserData << temp->soldiers << endl;
		SaveUserData << temp->food << endl;
		SaveUserData << temp->weapons << endl;
		SaveUserData << endl;
	}
	delete temp;
	SaveUserData.close();
}