#pragma once
#include"Function.h"
#include"Attack.h"


void Show_Text(string text, int Time=50)
{
	for (int i = 0; i < text.length(); i++)
	{
		cout << text[i];
		Sleep(Time);
	}cout << endl;
}


void ShowName() {
	mysetcolor(3, 0);
	cout << endl;
	Show_Text((
		"\t   ______     ______     ______   ______   __         ______     ______     __  __     __     ______  \n"
		"\t  /\\  == \\   /\\  __ \\   /\\__  _\\ /\\__  _\\ /\\ \\       /\\  ___\\   /\\  ___\\   /\\ \\_\\ \\   /\\ \\   /\\  == \\ \n"
		"\t  \\ \\  __<   \\ \\  __ \\  \\/_/\\ \\/ \\/_/\\ \\/ \\ \\ \\____  \\ \\  __\\   \\ \\___  \\  \\ \\  __ \\  \\ \\ \\  \\ \\  _-/ \n"
		"\t   \\ \\_____\\  \\ \\_\\ \\_\\    \\ \\_\\    \\ \\_\\  \\ \\_____\\  \\ \\_____\\  \\/\\_____\\  \\ \\_\\ \\_\\  \\ \\_\\  \\ \\_\\   \n"
		"\t    \\/_____/   \\/_/\\/_/     \\/_/     \\/_/   \\/_____/   \\/_____/   \\/_____/   \\/_/\\/_/   \\/_/   \\/_/   \n"
		"                                                                                                    \n"), 3);
	mysetcolor(7, 0);
}





void ShowMenu() {
	ShowName();
	Show_Text("\t\t\t\t\t   -------------------------");
	Show_Text("\t\t\t\t\t   | RULES OF THE GAME [1] |");
	Show_Text("\t\t\t\t\t   | START GAME [2]        |");
	Show_Text("\t\t\t\t\t   -------------------------");
}


void GameRules() {
	system("cls");
	mysetcolor(3, 5);
	Show_Text("\n     Get ready, for a war has been declared. Its time for some naval warfare.\n\n\n\n", 40);

	mysetcolor(7, 8);   // Set Color
	Show_Text(" 1.  You have to defeat your opponent by destroying all his war ships\n     before he destroys yours.\n", 20);
	Show_Text(" 2.  They battlefield is a 10x10 grid where your ships will be placed\n", 20);
	Show_Text(" 3.  Controls are very easy. Just click where you want to attack.\n", 20);
	Show_Text(" 4.  If your attack hits the enemy ship, you get an extra turn\n", 20);
	Show_Text(" 5.  There are four Ship Types:\n     A Type -> 5x Ship\n     B Type -> 4x Ship\n     C Type -> 3x Ship\n     D Type -> 2x Ship", 20);
	mysetcolor(7, 0);   // Set Color

}

void GraphicShip() {
	cout << "\n\n\n\n" << endl;
	cout << "\t\t                                                              ~~~" << endl;
	cout << "\t\t                                                          |~~" << endl;
	mysetcolor(1, 0);
	Show_Text("\t\t              		            \\                     |     __/___  ", 1);
	Show_Text("\t\t              		             \\                 __|__/______|___", 0);
	mysetcolor(2, 0);
	Show_Text("\t\t              		            __\\__           __ | __ / ______ | ______ | _", 1);
	mysetcolor(4, 0);
	Show_Text("\t\t             		      ______|___|___________/_____\\_______\\_______\\________  ", 0);
	mysetcolor(7, 0);
	cout << "\t\t             	  	      \\                                                   /  " << endl;
	Show_Text("\t\t             	  	       \\                --> MANUAL [0] -->               /  ", 10);
	Show_Text("\t\t          		        \\               --> RANDOM [1] -->              /", 10);
	cout << "\t\t          		         \\                                             /" << endl;
	mysetcolor(7, 1);
	Show_Text("\t\t\t\t   ~ ~~~ ~  ~~~~~~~~~~~     ~~ ~~~~~~~~~  ~~~~~~    ~   ~~ ~~~  ~~~~~~~~~~   ~~~~", 2);
	Show_Text("\t\t\t\t   ~~~~~~~~   ~~~   ~~~~~~~~     ~    ~~~     ~    ~~~~  ~~~~~~~~~      ~~~~~  ~~", 3);
	Show_Text("\t\t\t\t   ~~~~~~~     ~~~~~~   ~~~~~~ ~ ~~~  ~~~~    ~~~~~      ~~~~~  ~    ~~~~~   ~~~~\n\n\n", 2);
	mysetcolor(7, 0);
}







void Start() {
	while (true) {

		ShowMenu();
		cout << "\t\t\t\t\t       ENTER SELECTION : ";
		int choice = 0;
		cin >> choice;

		if (choice == 1) {
			system("cls");
			GameRules();
			Sleep(4000);
			system("cls");

		}
		else if (choice == 2) {
			system("cls");
			GraphicShip();
			cout << "\t\t\t\t\t\t\t\tEnter select : ";
			int select = 0;
			cin >> select;
			if (select == 0) {
				playerBoard[point.y][point.x] = 1;
				putShipManual(playerBoard);
				putShipRandomlyEnemy(enemyBoard, 6);
				while (true) {
					Sleep(2000);
					system("cls");
					AttackPlayer(enemyBoard);
					AttackRandomCPU(playerBoard);
				}
			}
			else if (select == 1) {
	putShipRandomly(playerBoard, 5);

	system("cls");
	ShowMyships(playerBoard, mysize);

	putShipRandomlyEnemy(enemyBoard, 6);
	ShowEnemyShips(enemyBoard, mysize);

	while (true) {
		cout << endl << endl << endl;
		system("cls");
		AttackPlayer(enemyBoard);
		AttackRandomCPU(playerBoard);
					}
				}

			}

	}

}
