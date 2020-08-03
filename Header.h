#pragma once
#include <string>

using namespace std;

class movement
{
public:
	void movement1();
	static int getting_key();
};

class main_menu : public movement
{
	friend class mapa;
public:
	static int text_colour;
	void menu_show_start_game();
	void menu_show_options();
	void menu_show_credits();
	void menu_show_exit();
	void static Credits();
	void menu_show_load_game();

};

class mapa : public main_menu
{
public:
	static int day;
	static int counter;
	int EnergyLeft = 15;
	char name[50];
	typedef int Tmap[11][29];
	void show_menu();
	void displayMap();
	void displayInformations();
	void move_left();
	void move_right();
	void move_up();
	void move_down();
	void enter_object();
	void InGameMenu_Save();
	void InGameMenu_Load();
	void InGameMenu_Options();
	void InGameMenu_Exit();
	int EnergyRequiredWork = 15;
	int EnergyRequiredRecruit = 3;
};

class player
{
public:
	int static PlayerPositionX;
	int static PlayerPositionY;
	static char name[50];
	int static energy;
	int static money; 
	int static wood; 
	int static soldiers;
	int static weapons;
	int static food;
	int static work_lvl; //Odnoœnie pracy
	int static work_lvl_experience; //Odnoœnie pracy
	bool static job_contract; //Odnoœnie pracy
	int static days_not_worked; //Odnoœnie pracy
	bool static worked_or_not; //Odnoœnie pracy
	int static experience;
	int static lvl;
	bool static loadfunction;
	player();
	char* CheckNameAndSave();
	player* first = nullptr;
	player* next = nullptr;
	player* pointer = nullptr;
	int slot1colour = 0;
	int slot2colour = 0;
	int slot3colour = 0;
	int slot4colour = 0;
	int slot5colour = 0;
	//operator przeci¹¿enia wyœwietlania >>? Dok³¹dnie
};

class SavingSystem : public player
{
public:
	void SaveGame();
	void  slot2();
	void  slot3();
	void  slot4();
	void  slot5();
	int slot1colour = 0;
	int slot2colour = 0;
	int slot3colour = 0;
	int slot4colour = 0;
	int slot5colour = 0;
	int CheckSlotColour1(int first);
	int CheckSlotColour2(int second);
	int CheckSlotColour3(int third);
	int CheckSlotColour4(int fourth);
	int CheckSlotColour5(int fifth);
};

class LoadingSystem : public player
{
public:
	void LoadGame();
	void slot2();
	void slot3();
	void slot4();
	void slot5();
	int slot1colour = 0;
	int slot2colour = 0;
	int slot3colour = 0;
	int slot4colour = 0;
	int slot5colour = 0;
	int CheckSlotColour1(int first);
	int CheckSlotColour2(int second);
	int CheckSlotColour3(int third);
	int CheckSlotColour4(int fourth);
	int CheckSlotColour5(int fifth);
	
};
class EnterableObjects : public mapa
{
public:
	void virtual ShowQuests(string name, int text_colour) = 0;
	void static pointer();
	void buy_wood();
	void buy_weapons();
	void buy_food();

};

class city : public EnterableObjects
{
public:
	void ShowQuests(string name, int text_colour);
	void city_show_buy();
	void city_show_sleep();
	void city_show_exit();
	void city_show_conquer();
	void city_show_work();
	void city_bakery_work();
	void city_buy_wood();
	void city_buy_weapons();
	void city_earn_money();
	void city_go_to_job();
	void job_contract();
	void city_buy_food();
	//void earn_money();
	//void buy_weapons();
};

class village : public EnterableObjects
{
public:
	void ShowQuests(string name, int text_colour);
	void village_show_buy();
	void village_show_sleep();
	void village_show_exit();
	void village_show_conquer();
	void village_show_work();
	void village_field_work();
	void village_forrest_work();
	void village_buy_food();
	void village_buy_wood();
};

class castle : public EnterableObjects
{
public:
	void ShowQuests(string name, int text_colour);
	void castle_show_recruit();
	void castle_show_sleep();
	void castle_show_exit();
	void castle_show_conquer();
	void castle_show_work();
	void castle_smith_work();
	//void castle_recruit();
};

class DecisionList
{
public:
	static bool List_a(string);
	static bool List_b(string);
};

class PlayersList : public player
{
public:
	player* first = nullptr;
	//void AddUser();
	void SaveUsersData();
	void ShowList();
	friend ostream& operator<< (ostream&, player&);
};