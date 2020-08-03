#include <iostream>
#include "Header.h"
#include <windows.h>

using namespace std;

int main()
{
	movement introduction;
	introduction.movement1();
	main_menu* menu = new main_menu;
	menu->menu_show_start_game();
	cout << "Type your name: ";
	player player1;
	strcpy_s(player1.name, player1.CheckNameAndSave());
	mapa* mapka = new mapa;
	mapa::Tmap map;
	strcpy_s(mapka->name,player1.name);
	mapka->displayMap();
	mapka->show_menu();
	delete menu;
	delete mapka;
	//WPROWADZIĆ JESZCZE SYSTEM WALKI
	//WPROWADZIĆ JESZCZE QUESTY!
	//TRANSPORTY MIĘDZY WSIAMI I MIASTEM!? //Dodatkowe obozowiska?
	//WPROWADZIĆ JESZCZE :: FABUŁĄ!!
	//UPDATE LOADINGSYSTEMU
}