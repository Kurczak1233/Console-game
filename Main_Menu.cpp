#include <iostream>
#include <windows.h>
#include "Header.h"

using namespace std;

int main_menu::text_colour = 14;

void main_menu::menu_show_start_game()
{
	
	system("CLS");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	cout << '\t' << " MAIN MENU : " << endl;
	cout << "------------------------------" << endl;
	EnterableObjects::pointer();
	cout << "1. Start the game" << endl;
	cout << "2. Load Game" << endl;
	cout << "3. Options" << endl;
	cout << "4. Credits" << endl;
	cout << "5. Exit" << endl;
	int znak = movement::getting_key();
	switch (znak)
	{
	case 72:
	{
		menu_show_exit();
		break;
	}
	case 80:
	{
		menu_show_load_game();
		break;
	}
	case 13:
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
		break;
	}
	case 27:
	{
		DecisionList::List_a("quit this program");
		break;
	}
	default:
	{
		cout << "There is no available sign like that, try again" << endl;
		Sleep(1000);
		menu_show_start_game();
		break;
	}
	}
}
void main_menu::menu_show_load_game()
{

	system("CLS");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	cout << '\t' << " MAIN MENU : " << endl;
	cout << "------------------------------" << endl;
	cout << "1. Start the game" << endl;
	EnterableObjects::pointer();
	cout << "2. Load Game" << endl;
	cout << "3. Options" << endl;
	cout << "4. Credits" << endl;
	cout << "5. Exit" << endl;
	int znak = movement::getting_key();
	switch (znak)
	{
	case 72:
	{
		menu_show_start_game();
		break;
	}
	case 80:
	{
		menu_show_options();
		break;
	}
	case 13:
	{
		LoadingSystem *temp = new LoadingSystem;
		temp->LoadGame();
		if (player::loadfunction == false)
		{
			menu_show_start_game();
			break;
		}
		mapa* tempo = new mapa;
		tempo->show_menu();
		delete temp;
		delete tempo;
		break;
	}
	case 27:
	{
		DecisionList::List_a("quit this program");
		break;
	}
	default:
	{
		cout << "There is no available sign like that, try again" << endl;
		Sleep(1000);
		menu_show_start_game();
		break;
	}
	}
}
void main_menu::menu_show_options()
{
	system("CLS");
	cout << '\t' << " MAIN MENU : " << endl;
	cout << "------------------------------" << endl;
	cout << "1. Start the game" << endl;
	cout << "2. Load Game" << endl;
	EnterableObjects::pointer();
	cout << "3. Options" << endl;
	cout << "4. Credits" << endl;
	cout << "5. Exit" << endl;
	int znak = movement::getting_key();
	switch (znak)
	{
	case 72:
	{
		menu_show_load_game();
		break;
	}
	case 80:
	{
		menu_show_credits();
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
		menu_show_start_game();
		break;
	}
	case 27:
	{
		DecisionList::List_a("quit this program");
		menu_show_start_game();
		break;
	}
	default:
	{
		cout << "There is no available sign like that, try again" << endl;
		Sleep(1000);
		menu_show_start_game();
		break;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	}
}
void main_menu::menu_show_credits()
{

	system("CLS");
	cout << '\t' << " MAIN MENU : " << endl;
	cout << "------------------------------" << endl;
	cout << "1. Start the game" << endl;
	cout << "2. Load Game" << endl;
	cout << "3. Options" << endl;
	EnterableObjects::pointer();
	cout << "4. Credits" << endl;
	cout << "5. Exit" << endl;
	int znak = movement::getting_key();
	switch (znak)
	{
	case 72:
	{
		menu_show_options();
		break;
	}
	case 80:
	{
		menu_show_exit();
		break;
	}
	case 13:
	{
		Credits();
		menu_show_start_game();
		break;
	}
	case 27:
	{
		DecisionList::List_a("quit this program");
		break;
	}
	default:
	{
		cout << "There is no available sign like that, try again" << endl;
		Sleep(1000);
		menu_show_start_game();
		break;
	}
	}
}
void main_menu::menu_show_exit()
{
	
	system("CLS");
	cout << '\t' << " MAIN MENU : " << endl;
	cout << "------------------------------" << endl;
	cout << "1. Start the game" << endl;
	cout << "2. Load Game" << endl;
	cout << "3. Options" << endl;
	cout << "4. Credits" << endl;
	EnterableObjects::pointer();
	cout << "5. Exit" << endl;
	int znak = movement::getting_key();
	switch (znak)
	{
	case 72:
	{
		menu_show_credits();
		break;
	}
	case 80:
	{
		menu_show_start_game();
		break;
	}
	case 13:
	{
		bool a = DecisionList::List_a("quit this program");
		menu_show_start_game();
		break;
	}
	case 27:
	{
		DecisionList::List_a("quit this program");
		menu_show_start_game();
		break;
	}
	default:
	{
		cout << "There is no available sign like that, try again" << endl;
		Sleep(1000);
		menu_show_start_game();
		break;
	}
	}
}
void main_menu::Credits()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	cout << "The game was a long road in obtaining new skills and knowledge in programming" << endl;
	cout << "Made thoroughly by";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	cout << '\t' << "Michal Kupczak" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	system("pause");
}