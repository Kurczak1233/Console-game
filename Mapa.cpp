#include <iostream>
#include "Header.h"
#include <windows.h>
#include <fstream>
#include <string>

using namespace std;

mapa::Tmap map1 =
{
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 8, 0, 1 },
	{ 1, 0, 0, 8, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
};

int mapa::day = 1;

void mapa::show_menu()
{
	mapa::displayMap();
	mapa::displayInformations();
	if (player::food == 0)
	{
		system("CLS");
		cout << "GAME OVER" << endl;
		exit(0);
	}
	if (player::energy == 0)
	{
		system("CLS");
		mapa::displayMap();
		cout << endl;
		cout << "You have no energy left today! You have to sleep!" << endl;
		cout << "Sleeping here costs you: ";
		for (int i = 0; i < 11; i++)
		{
			for (int j = 0; j < 29; j++)
			{
				if (map1[i][j] == 5)
				{
					if (player::food > 25)
					{
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 150);
						cout << 25;
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
						cout << " food due to wild animals activity" << endl;
						system("pause");
						player::food = player::food - 25;
					}
					else
					{

						system("CLS");
						cout << "You starved" << endl;
						cout << "GAME OVER" << endl;
						exit(0);

					}
				}
				if (map1[i][j] == 10 || map1[i][j] == 11 || map1[i][j] == 12)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 150);
					cout << "2 gold ";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
					cout << "Press any key to rest..." << endl;
					player::food = player::food - player::soldiers * 1;
					break;
				}
			}
		}
		player::energy = 50;
		player::food = player::food - player::soldiers * 1;  //SCHEMAT NA KONIEC DNIA
		day++;
		if (player::job_contract == true)
		{
			if (player::worked_or_not == false)
			{
				player::days_not_worked++;
			}
		}
		player::worked_or_not = false;
	}
		if (player::job_contract == true)  //WORK LVL
		{
			player::work_lvl_experience + 1;
			if (player::work_lvl == 0)
			{
				if (player::work_lvl_experience == 14)
				{
					player::work_lvl = 1;
					cout << "You have gained new LVL!" << endl;
					cout << "You can now get a better job!" << endl;
					player::work_lvl_experience = 0;
					player::job_contract = false;
				}
			}
			if (player::work_lvl == 1)
			{
				if (player::work_lvl_experience == 28)
				{
					player::work_lvl = 2;
					cout << "You have gained new LVL!" << endl;
					cout << "You can now get a better job!" << endl;
					player::work_lvl_experience = 0;
					player::job_contract = false;
				}
			}
			if (player::work_lvl == 2)
			{
				if (player::work_lvl_experience == 35)
				{
					player::work_lvl = 3;
					cout << "You have gained new LVL!" << endl;
					cout << "You can now get a better job!" << endl;
					player::work_lvl_experience = 0;
					player::job_contract = false;
				}
			}
			if (player::work_lvl == 3)
			{
				if (player::work_lvl_experience == 42)
				{
					player::work_lvl = 4;
					cout << "You have gained new LVL!" << endl;
					cout << "You can now get a better job!" << endl;
					player::work_lvl_experience = 0;
					player::job_contract = false;
				}
			}
			if (player::work_lvl == 4)
			{
				if (player::work_lvl_experience == 49)
				{
					player::work_lvl = 5;
					cout << "You have gained new LVL!" << endl;
					cout << "You can now get a better job!" << endl;
					player::work_lvl_experience = 0;
					player::job_contract = false;
				}
			}
		

			if (player::worked_or_not == false)
			{
				if (player::work_lvl == 0)
				{
					if (player::days_not_worked == 7)
					{
						system("CLS");
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), text_colour);
						cout << "You have lost your job!" << endl;
						player::job_contract = false;
						player::days_not_worked = 0;
						system("pause");
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
					}
				}
				if (player::work_lvl == 1)
				{
					if (player::days_not_worked == 6)
					{
						system("CLS");
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), text_colour);
						cout << "You have lost your job!" << endl;
						player::job_contract = false;
						player::work_lvl--;
						player::days_not_worked = 0;
						system("pause");
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
					}
				}
				if (player::work_lvl == 2)
				{
					if (player::days_not_worked == 5)
					{
						system("CLS");
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), text_colour);
						cout << "You have lost your job!" << endl;
						player::job_contract = false;
						player::work_lvl--;
						player::days_not_worked = 0;
						system("pause");
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
					}
				}
				if (player::work_lvl == 3)
				{
					if (player::days_not_worked == 4)
					{
						system("CLS");
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), text_colour);
						cout << "You have lost your job!" << endl;
						player::job_contract = false;
						player::work_lvl--;
						player::days_not_worked = 0;
						system("pause");
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
					}
				}
				if (player::work_lvl == 4)
				{
					if (player::days_not_worked == 3)
					{
						system("CLS");
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), text_colour);
						cout << "You have lost your job!" << endl;
						player::job_contract = false;
						player::work_lvl--;
						player::days_not_worked = 0;
						system("pause");
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
					}
				}
				if (player::work_lvl == 5)
				{
					if (player::days_not_worked == 2)
					{
						system("CLS");
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), text_colour);
						cout << "You have lost your job!" << endl;
						player::job_contract = false;
						player::work_lvl--;
						player::days_not_worked = 0;
						system("pause");
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
					}
				}
			}
		}

		

	int znak = movement::getting_key();
	system("CLS");
	switch (znak)
	{
	case 72: //góra
	{
		move_up();
		show_menu();
		break;
	}
	case 80:// dó³
	{
		move_down();
		show_menu();
		break;
	}
	case 75: //lewo
	{
		move_left();
		show_menu();
		break;
	}
	case 77: //prawo
	{
		move_right();
		show_menu();
		break;
	}
	case 13: //enter
	{
		enter_object();
		show_menu();
		break;
	}
	case 27:
	{
		InGameMenu_Save(); 
		show_menu();
		break;
	}
	default:
	{
		show_menu();
		break;
	}
	}
}

int mapa::counter = 0;

void mapa::displayMap()
{
	system("CLS");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), text_colour);
	if (player::name != mapa::name)
	{
		strcpy_s(mapa::name, player::name);
	}
	
	if (player::PlayerPositionX != 2 && player::PlayerPositionY != 9)
	{
		if (counter == 0)
		{

			for (int i = 0; i < 11; i++)
			{
				for (int j = 0; j < 29; j++)
				{
					if (map1[i][j] == 5)
					{
						map1[i][j] = 0;
					}
					else if (map1[i][j] == 10) //fortress = 10
					{
						map1[i][j] = 4;
						//Village =  8 / Fortress = 4 /City = 7
					}
					else if (map1[i][j] == 11)  // miasto 11
					{
						map1[i][j] = 7;
					}
					else if (map1[i][j] == 12) //wies 12
					{
						map1[i][j] = 8;
					}
				}
			}
			counter++;
			strcpy_s(mapa::name, player::name);
			for (int i = 0; i < 11; i++)
			{
				for (int j = 0; j < 29; j++)
				{
					if (map1[player::PlayerPositionX][player::PlayerPositionY] == 0)
					{
						map1[player::PlayerPositionX][player::PlayerPositionY] = 5;
						break;
					}
					else if (map1[player::PlayerPositionX][player::PlayerPositionY] == 4) //zajêty fortress = 10
					{
						map1[player::PlayerPositionX][player::PlayerPositionY] = 10;
						break;
						//Village =  8 / Fortress = 4 /City = 7
					}
					else if (map1[player::PlayerPositionX][player::PlayerPositionY] == 7)  //zajête miasto 11
					{
						map1[player::PlayerPositionX][player::PlayerPositionY] = 11;
						break;
					}
					else if (map1[player::PlayerPositionX][player::PlayerPositionY] == 8) // zajêta wies 12
					{
						map1[player::PlayerPositionX][player::PlayerPositionY] = 12;
						break;
					}
					else
					{
						break;
					}
				}
			}


		}
	}
	if (player::experience <= 0)
	{
		player::lvl = player::lvl + 1;
		player::experience = 20 + player::lvl * 2;
		cout << "LVL UP!" << endl;
		cout << "You are now on " << player::lvl << " LVL" << endl;
		system("pause");
		system("CLS");
	}
	cout << mapa::name;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	cout << " your LVL: ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), text_colour);  //Wyœwietlanie nad mapk¹
	cout << player::lvl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	cout << '\t' << " EXP to next LVL ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), text_colour);
	cout << player::experience;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	cout << '\t' << " Day: ";
	cout << day << endl;
	for (int i = 0; i < 11; i++)
	{
		if (i != 0)
		{
			cout << endl;
		}
		for (int j = 0; j < 29; j++)
		{
			switch (map1[i][j])
			{
			case 1: cout << "x"; break;
			case 0: cout << " "; break;
			case 5:
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), text_colour);
				cout << "X";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
				break;
			}
			case 4: cout << "F"; break;
			case 7: cout << "C"; break;
			case 8: cout << "V"; break;
			case 10:
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 150);
				cout << "X";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
				break;
			}
			case 11:
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 150);
				cout << "X";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
				break;
			}
			case 12:
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 150);
				cout << "X";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
				break;
			}
			}
		}
	}
}
void mapa::move_left()
{
	for (int i = 0; i < 11; i++)
	{
		if (i != 0)
		{
			cout << endl;
		}
		for (int j = 0; j < 29; j++)
		{
			switch (map1[i][j])
			{
			case 5:
			{
				if (map1[i][j - 1] == 4)
				{
					map1[i][j] = 0;
					map1[i][j - 1] = 10;
					player::energy--;
					return;
				}
				if (map1[i][j - 1] == 7)
				{
					map1[i][j] = 0;
					map1[i][j - 1] = 11;
					player::energy--;
					return;
				}
				if (map1[i][j - 1] == 8)
				{
					map1[i][j] = 0;
					map1[i][j - 1] = 12;
					player::energy--;
					return;
				}
				break;
			}
			case 10: //Pocz¹tek algorytmów wychodzenia z obiektow
			{
				if (map1[i][j - 1] != 1)
				{
					map1[i][j] = 4;
					map1[i][j - 1] = 5;
					player::energy--;
					return;
				}
			}
			case 11:
			{
				if (map1[i][j - 1] != 1)
				{
					map1[i][j] = 7;
					map1[i][j - 1] = 5;
					player::energy--;
					return;
				}
			}
			case 12:
			{
				if (map1[i][j - 1] != 1)
				{
					map1[i][j] = 8;
					map1[i][j - 1] = 5;
					player::energy--;
					return;
				}
			}
			}
			if (map1[i][j] == 5 && map1[i][j - 1] != 1)
			{
				int temp;
				temp = map1[i][j];
				map1[i][j] = map1[i][j - 1];
				map1[i][j - 1] = temp;
				player::energy--;
			}
		}
	}
	return;
}
void mapa::move_right()
{
	int licznik = 0;
	for (int i = 0; i < 11; i++)
	{
		if (i != 0)
		{
			cout << endl;
		}
		for (int j = 0; j < 29; j++)
		{
			switch (map1[i][j])
			{
			case 5:
			{
				if (licznik == 0)
				{
					if (map1[i][j] == 5) // j = 7
					{
						if (map1[i][j + 1] != 1)
						{
							// Pocz¹tek algorytmu wchodzenia do obiektów

							if (map1[i][j + 1] == 4)
							{
								map1[i][j] = 0;
								map1[i][j + 1] = 10;
								player::energy--;
								return;
							}
							if (map1[i][j + 1] == 7)
							{
								map1[i][j] = 0;
								map1[i][j + 1] = 11;
								player::energy--;
								return;
							}
							if (map1[i][j + 1] == 8)
							{
								map1[i][j] = 0;
								map1[i][j + 1] = 12;
								player::energy--;
								return;
							}
							int temp;
							temp = map1[i][j];
							map1[i][j] = map1[i][j + 1];
							map1[i][j + 1] = temp;
							player::energy--;
							cout << " ";
							licznik++;
						}
					}
				}
				break;
			}
			case 10: //Pocz¹tek algorytmów wychodzenia z obiektow
			{
				if (map1[i][j + 1] != 1)
				{
					map1[i][j] = 4;
					map1[i][j + 1] = 5;
					player::energy--;
					return;
				}
			}
			case 11:
			{
				if (map1[i][j + 1] != 1)
				{
					map1[i][j] = 7;
					map1[i][j + 1] = 5;
					player::energy--;
					return;
				}
			}
			case 12:
			{
				if (map1[i][j + 1] != 1)
				{
					map1[i][j] = 8;
					map1[i][j + 1] = 5;
					player::energy--;
					return;
				}
			}
			}
		}
	}
	return;
}

void mapa::move_up()
{
	mapa* nowa = new mapa;
	for (int i = 0; i < 11; i++)
	{
		if (i != 0)
		{
			cout << endl;
		}
		for (int j = 0; j < 29; j++)
		{
			switch (map1[i][j])
			{
			case 5:
			{
				if (map1[i + 1][j] != 1) // Pocz¹tek algorytmu wchodzenia do obiektów
				{
					if (map1[i - 1][j] == 4)
					{
						map1[i][j] = 0;
						map1[i - 1][j] = 10;
						player::energy--;
						return;
					}
					if (map1[i - 1][j] == 7)
					{
						map1[i][j] = 0;
						map1[i - 1][j] = 11;
						player::energy--;
						return;
					}
					if (map1[i - 1][j] == 8)
					{
						map1[i][j] = 0;
						map1[i - 1][j] = 12;
						player::energy--;
						return;
					}
				}

				break;
			}
			case 10: //Pocz¹tek algorytmów wychodzenia z obiektow
			{
				if (map1[i - 1][j] != 1)
				{
					map1[i][j] = 4;
					map1[i - 1][j] = 5;
					player::energy--;
					return;
				}
			}
			case 11:
			{
				if (map1[i - 1][j] != 1)
				{
					map1[i][j] = 7;
					map1[i - 1][j] = 5;
					player::energy--;
					return;
				}
			}
			case 12:
			{
				if (map1[i - 1][j] != 1)
				{
					map1[i][j] = 8;
					map1[i - 1][j] = 5;
					player::energy--;
					return;
				}
			}
			}

			if (map1[i][j] == 5 && map1[i - 1][j] != 1)// j = 7
			{
				int temp;
				temp = map1[i][j];
				map1[i][j] = map1[i - 1][j];
				map1[i - 1][j] = temp;
				player::energy--;
			}
		}
	}return;
}
void mapa::move_down()
{
	int licznikWall = 0;
	for (int i = 0; i < 11; i++)
	{
		if (i != 0)
		{
			cout << endl;
		}
		for (int j = 0; j < 29; j++)
		{
			switch (map1[i][j])
			{
			case 5:
			{
				if (licznikWall == 0)
				{
					if (map1[i][j] == 5)// j = 7
					{
						if (map1[i + 1][j] != 1)
						{
							if (map1[i + 1][j] == 4) // Algorytmy wchodzenia do fortress
							{
								map1[i][j] = 0;
								map1[i + 1][j] = 10;
								player::energy--;
								return;
							}
							if (map1[i + 1][j] == 7) // Algorytmy wchodzenia do miast
							{
								map1[i][j] = 0;
								map1[i + 1][j] = 11;
								player::energy--;
								return;
							}
							if (map1[i + 1][j] == 8) // Algorytmy wchodzenia do wsi
							{
								map1[i][j] = 0;
								map1[i + 1][j] = 12;
								player::energy--;
								return;
							}
							int temp;
							temp = map1[i][j];
							map1[i][j] = map1[i + 1][j];
							map1[i + 1][j] = temp;
							cout << " ";
							licznikWall++;
							player::energy--;
						}
					}
				}
				break;
			}
			case 10: //Pocz¹tek algorytmów wychodzenia z obiektow
			{
				if (map1[i + 1][j] != 1)
				{
					map1[i][j] = 4;
					map1[i + 1][j] = 5;
					player::energy--;
					return;
				}
			}
			case 11:
			{
				if (map1[i + 1][j] != 1)
				{
					map1[i][j] = 7;
					map1[i + 1][j] = 5;
					player::energy--;
					return;
				}
			}
			case 12:
			{
				if (map1[i + 1][j] != 1)
				{
					map1[i][j] = 8;
					map1[i + 1][j] = 5;
					player::energy--;
					return;
				}
			}
			}
		}
	}
	return;
}

void mapa::displayInformations()
{
	cout << endl;
	cout << "-----------------------------------" << endl;
	cout << "You have ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 150);
	cout << player::energy;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	cout << " moves left" << endl;
	cout << "Your gold: ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 150);
	cout << player::money << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	cout << "Your Soldiers: ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 150);
	cout << player::soldiers << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	cout << "Your Wood: ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 150);
	cout << player::wood << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	cout << "Your Food: ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 150);
	cout << player::food << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	cout  << "Your Weapons: ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 150);
	cout << player::weapons << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	cout << endl;
	cout << "Currently your army eats ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 150);
	cout << player::soldiers;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	cout << " food daily" << endl;
	cout << "You are ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 150);
	if (player::job_contract == true)
	{
		switch (player::work_lvl)
		{
		case 0:
		{
			cout << "Unqualified worker! (lvl " << player::work_lvl << ")" << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
			cout << "You weren't in job for: " << player::days_not_worked << "/7" << endl;
			break;
		}
		case 1:
		{
			cout << "Clumsy worker! (lvl " << player::work_lvl << ")" << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
			cout << "You weren't in job for: " << player::days_not_worked << "/6" << endl;
			break;
		}
		case 2:
		{
			cout << "Indolent worker! (lvl " << player::work_lvl << ")" << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
			cout << "You weren't in job for: " << player::days_not_worked << "/5" << endl;
			break;
		}
		case 3:
		{
			cout << "Scrupulous worker! (lvl " << player::work_lvl << ")" << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
			cout << "You weren't in job for: " << player::days_not_worked << "/4" << endl;
			break;
		}
		case 4:
		{
			cout << "Skilled worker! (lvl " << player::work_lvl << ")" << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
			cout << "You weren't in job for: " << player::days_not_worked << "/3" << endl;
			break;
		}
		case 5:
		{
			cout << "Very talented worker! (lvl " << player::work_lvl << ")" << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
			cout << "You weren't in job for: " << player::days_not_worked << "/2" << endl;
			break;
		}
		}
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	cout << "F means Fortress, C means City, V means Village" << endl;
}

void mapa::enter_object()
{
	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 29; j++)
		{
			if (map1[i][j] == 10)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 150);
				cout << "Fortress" << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
				EnterableObjects* pointer;
				castle castle1;
				pointer = &castle1;
				pointer->ShowQuests(mapa::name, text_colour);
			}
			if (map1[i][j] == 11)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 150);
				cout << "City" << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
				EnterableObjects* pointer;
				city city1;
				pointer = &city1;
				pointer->ShowQuests(mapa::name, text_colour);
			}
			if (map1[i][j] == 12)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 150);
				cout << "Village" << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
				EnterableObjects* pointer;
				village village1;
				pointer = &village1;
				pointer->ShowQuests(mapa::name, text_colour);
			}
			if (map1[i][j] == 5)
			{
				cout << "You are not standing on any enterable object!" << endl;
			}
		}
	}
	return;
}

void mapa::InGameMenu_Save()
{
	system("CLS");
	SavingSystem* temp = new SavingSystem;
	EnterableObjects::pointer();
	cout << "1. Save game" << endl;
	cout << "2. Load game" << endl;
	cout << "3. Options" << endl;
	cout << "4. Exit" << endl;
	int znak = movement::getting_key();
	switch (znak)
	{
	case 72: //Góra
	{
		InGameMenu_Exit();
		break;
	}
	case 80: //dó³
	{
		InGameMenu_Load();
		break;
	}
	case 13: //ennter
	{		
		for (int i = 0; i < 11; i++)
		{
			for (int j = 0; j < 29; j++)
			{
				if (map1[i][j] == 5)
				{
					player::PlayerPositionX = i;
					player::PlayerPositionY = j;
				}
				else if (map1[i][j] == 10) 
				{
					player::PlayerPositionX = i;
					player::PlayerPositionY = j;
				}
				else if (map1[i][j] == 11)
				{
					player::PlayerPositionX = i;
					player::PlayerPositionY = j;
				}
				else if (map1[i][j] == 12)
				{
					player::PlayerPositionX = i;
					player::PlayerPositionY = j;
				}
			}
		}
		temp->SaveGame();
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
		InGameMenu_Save();
		break;
	}
	}
	delete temp;
}
void mapa::InGameMenu_Load()
{
	system("CLS");
	cout << "1. Save game" << endl;
	EnterableObjects::pointer();
	cout << "2. Load game" << endl;
	cout << "3. Options" << endl;
	cout << "4. Exit" << endl;
	int znak = movement::getting_key();
	switch (znak)
	{
	case 72: //Góra
	{
		InGameMenu_Save();
		break;
	}
	case 80: //dó³
	{
		InGameMenu_Options();
		break;
	}
	case 13:
	{
		for (int i = 0; i < 11; i++)
		{
			for (int j = 0; j < 29; j++)
			{
				if (map1[i][j] == 5)
				{
					map1[i][j] = 0;
				}
				else if (map1[i][j] == 10) //fortress = 10
				{
					map1[i][j] = 4;
					//Village =  8 / Fortress = 4 /City = 7
				}
				else if (map1[i][j] == 11)  // miasto 11
				{
					map1[i][j] = 7;
				}
				else if (map1[i][j] == 12) //wies 12
				{
					map1[i][j] = 8;
				}
			}
		}
		LoadingSystem* systemx = new LoadingSystem;
		systemx->LoadingSystem::LoadGame();
		delete systemx;
		strcpy_s(mapa::name, player::name);
		for (int i = 0; i < 11; i++)
		{
			for (int j = 0; j < 29; j++)
			{
				if (map1[player::PlayerPositionX][player::PlayerPositionY] == 0)
				{ 
					map1[player::PlayerPositionX][player::PlayerPositionY] = 5;
					break;
				}
				else if (map1[player::PlayerPositionX][player::PlayerPositionY] == 4) //zajêty fortress = 10
				{
					map1[player::PlayerPositionX][player::PlayerPositionY] = 10;
					break;
					//Village =  8 / Fortress = 4 /City = 7
				}
				else if (map1[player::PlayerPositionX][player::PlayerPositionY] == 7)  //zajête miasto 11
				{
					map1[player::PlayerPositionX][player::PlayerPositionY] = 11;
					break;
				}
				else if (map1[player::PlayerPositionX][player::PlayerPositionY] == 8) // zajêta wies 12
				{
					map1[player::PlayerPositionX][player::PlayerPositionY] = 12;
					break;
				}
				else
				{
					break;
				}
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
		cout << "There is no available sign like that, try again" << endl;
		Sleep(1000);
		InGameMenu_Load();
		break;
	}
	}
}
void mapa::InGameMenu_Options()
{
	system("CLS");
	cout << "1. Save game" << endl;
	cout << "2. Load game" << endl;
	EnterableObjects::pointer();
	cout << "3. Options" << endl;
	cout << "4. Exit" << endl;
	int znak = movement::getting_key();
	switch (znak)
	{
	case 72: //Góra
	{
		InGameMenu_Load();
		break;
	}
	case 80: //dó³
	{
		InGameMenu_Exit();
		break;
	}
	case 13:
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
		cout << "Set your text colour" << endl;
		cout << "Available colours from 1 to 15" << endl;
		cout << "Recommended: " << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
		cout << "3. Dark Green";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		cout << " 7. Light grey";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
		cout << " 8. Dark grey";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << " 11. Turquoise";
		cout << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		cout << "12. Red";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
		cout << " 13. Purple";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << " 14. Yellow";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << " 15. White";
		cout << endl;
		cout << "Type your colour ";
		int d;
		cin >> d;
		if (d < 16)
		{
			text_colour = d;
		}
		else
		{
			cout << "Unavailable colour!" << endl;
			Sleep(1000);
		}
		break;
	}
	case 27:
	{
		break;
	}
	default:
	{
		cout << "There is no available sign like that, try again" << endl;
		Sleep(1000);
		InGameMenu_Options();
		break;
	}
	}
}
void mapa::InGameMenu_Exit()
{
	system("CLS");
	cout << "1. Save game" << endl;
	cout << "2. Load game" << endl;
	cout << "3. Options" << endl;
	EnterableObjects::pointer();
	cout << "4. Exit" << endl;
	int znak = movement::getting_key();
	switch (znak)
	{
	case 72: //Góra
	{
		InGameMenu_Options();
		break;
	}
	case 80: //dó³
	{
		InGameMenu_Save();
		break;
	}
	case 13:
	{
		DecisionList::List_a("quit this program");
		break;
	}
	case 27:
	{
		break;
	}
	default:
	{
		cout << "There is no available sign like that, try again" << endl;
		Sleep(1000);
		InGameMenu_Exit();
		break;
	}
	}
}
