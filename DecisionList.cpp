#include "Header.h"
#include <iostream>

using namespace std;

bool DecisionList::List_a(string a)
{
	system("CLS");
	cout << "Are you sure you want to " << a << "?" << endl;
	EnterableObjects::pointer();
	cout << "Y/";
	cout << "N" << endl;
	int znak = movement::getting_key();
	switch (znak)
	{
	case 75:
	{
		List_b(a);
		break;
	}
	case 77:
	{
		List_b(a);
		break;
	}
	case 13: //ENTER
	{
		if (a == "quit this program")
		{
			exit(0);
		}
		return true;
		break;
	}
	case 27: //ESC
	{
		return false;
		break;
	}
	default:
	{
		cout << "Nie wprowadzono poprawnego znaku" << endl;
		break;
	}
	}
	return false;
}

bool DecisionList::List_b(string a)
{
	system("CLS");
	cout << "Are you sure you want to " << a << "?" << endl;
	cout << "Y/";
	EnterableObjects::pointer();
	cout << "N" << endl;
	int znak = movement::getting_key();
	switch (znak)
	{
	case 75:
	{
		List_a(a);
		break;
	}
	case 77:
	{
		List_a(a);
		break;
	}
	case 13:
	{
		return false; 
		break;
	}
	case 27:
	{
		return false;
		break;
	}
	default:
	{
		cout << "Nie wprowadzono poprawnego znaku" << endl;
		break;
	}
	}
	return false;
}