#pragma once
#include<iostream>
#include<iomanip>
#include<Windows.h>
#include"Entities.h"
#include <conio.h>
using namespace std;





/*
0 = Black	8 = Gray
1 = Blue	9 = Light Blue
2 = Green	A = Light Green
3 = Aqua	B = Light Aqua
4 = Red	C = Light Red
5 = Purple	D = Light Purple
6 = Yellow	E = Light Yellow
7 = White	F = Bright White


*/

void mysetcolor(int fg, int bg) {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, fg | (bg << 4));

}


int** ReserveArray(int size);


int mysize = 12;
bool chekingIgnore = false;

int** playerBoard = ReserveArray(mysize);
int** enemyBoard = ReserveArray(mysize);



int** ReserveArray(int size) {
	int** arr = new int* [size];
	for (size_t i = 0; i < size; i++)
		arr[i] = new int[size] {};

	return arr;
}








void ShowWinPlayer() {
	system("cls");
	cout << endl << endl << endl << endl;
	mysetcolor(10, 0);
	cout << "\t\t\t      @@@@@@      @           @ @    @     @   @@@@@@    @@@@@        " << endl;
    cout << "\t\t\t      @     @	 @	    @    @   @   @    @          @    @    " << endl;
    cout << "\t\t\t     @     @    @	   @    @    @ @     @          @    @      " << endl;
	cout << "\t\t\t    @@@@@@     @	  @@@@@@     @      @@@@@      @@@@@    " << endl;
	cout << "\t\t\t   @	      @		 @    @	    @	   @          @  @      " << endl;
	cout << "\t\t\t  @          @ @ @ @    @    @     @      @@@@@@@    @     @         " << endl<< endl<< endl <<endl << endl;//////
	mysetcolor(1, 0);
	cout << "\t\t\t\t        @      @     @      o      @     @         " << endl;
	cout << "\t\t\t\t        @    @ @    @      @      @ @   @         " << endl ;
	cout << "\t\t\t\t        @   @  @   @      @      @  @  @        " << endl ;
	cout << "\t\t\t\t        @  @   @  @      @      @   @ @        " << endl;
	cout << "\t\t\t\t        @ @    @ @      @      @    @@       " << endl;
	cout << "\t\t\t\t        @      @       @      @     @      \n\n\n\n\n" << endl;
	mysetcolor(7, 0);
}



void ShowWinCPU() {
	system("cls");
	cout << endl << endl << endl << endl;
	mysetcolor(4, 0);
	cout << "\t\t\t        @@@@@@    @@@@@@@      @       @    " << endl;
	cout << "\t\t\t      @     	   @	 @    @       @      " << endl;
	cout << "\t\t\t     @            @	@    @       @          " << endl;
	cout << "\t\t\t    @            @@@@@@     @       @   " << endl;
	cout << "\t\t\t   @	        @	     @    @    " << endl;
	cout << "\t\t\t   @@@@@@@     @              @@@           " << endl << endl << endl << endl << endl;//////
	mysetcolor(9, 0);
	cout << "\t\t\t\t        @      @     @      o      @     @         " << endl;
	cout << "\t\t\t\t        @    @ @    @      @      @ @   @         " << endl;
	cout << "\t\t\t\t        @   @  @   @      @      @  @  @        " << endl;
	cout << "\t\t\t\t        @  @   @  @      @      @   @ @        " << endl;
	cout << "\t\t\t\t        @ @    @ @      @      @    @@       " << endl;
	cout << "\t\t\t\t        @      @       @      @     @      \n\n\n\n\n" << endl;
	mysetcolor(7, 0);
}





void ShowMyships(int** arr, int size) {
	int counterCPUShip = 0;
	//cout << "  " << endl << endl;
	cout << "\n  \t\t    Player" << endl;
	size_t m = 65;
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++)
		{

			if (arr[i][j] == 1) {
				if (j == 1) {
					mysetcolor(4, 0);
					cout << char(11) << " ";
				}
				else {
					mysetcolor(4, 0);
					cout << "  " << char(11) << " ";
				}
			}

			else if (arr[i][j] == 9) {

				cout << char(240) << "  ";
			}

			else if (arr[i][j] == 2) {
				if (j == 1) {
					mysetcolor(11, 0);
					cout << "o" << " ";
					mysetcolor(7, 0);
				}
				else {
					mysetcolor(11, 0);
					cout << "  " << "o" << " ";
					mysetcolor(7, 0);
				}
			}

			else if (arr[i][j] == 7) {
				if (j == 1) {
					mysetcolor(4, 0);
					cout << 'X' << " ";
					mysetcolor(7, 0);
				}
				else {
					mysetcolor(4, 0);
					cout << "  " << 'X' << " ";
					mysetcolor(7, 0);
				}
				counterCPUShip++;
			}

			else if (arr[i][j] == 0 && i != size - 1) {
				if (i == 0) {
					for (size_t i = 0; i < 10; i++)
					{
						if (i == 0) {
							cout << "    <" << i << ">";
						}
						else {
							cout << " <" << i << ">";

						}
					}
					break;
				}
				else if (j == 0) {
					for (; m < 75; )
					{
						cout << "  " << (char)m << " |";
						m++;
						break;
					}
				}
				else if (j == size - 1) {
					mysetcolor(7, 0);
					cout << "|" << endl;
				}
				else if (arr[i][j] == 0) {
					if (j == 1) {
						mysetcolor(3, 0);
						cout << (char)219 << "|";;
						mysetcolor(7, 0);
					}
					else {
						mysetcolor(3, 0);
						cout << " |" << (char)219 << "|";;
						mysetcolor(7, 0);
					}
				}
				else {
					cout << "  ";
				}
			}
			//}
			else if (arr[i][j] == 5) {
				if (j == 1) {
					mysetcolor(12, 0);
					cout << char(11) << " ";
				}
				else {
					mysetcolor(12, 0);
					cout << "  " << char(11) << " ";
				}
			}

		}
		cout << endl;
		if (counterCPUShip == 16) {
			system("cls");
			ShowWinCPU();
			system("pause");

		}
	}
}








//Gemilerin gorsenmemeyi temin etmek ucun ShowEnemyShips funksiyasinda axirinci if else-de rengin kodunu  3-e deyismek lazimdir.   5-kodunu yazaraq Dusmen Gemilerin gorunmesini temin edirik
void ShowEnemyShips(int** arr, int size) {
	int counterPlayerShip = 0;
	//cout << "  " << endl ;
	cout << "\n\t\t    CPU" << endl;
	size_t m = 65;
	for (size_t i = 0; i < size - 1; i++)
	{
		for (size_t j = 0; j < size; j++)
		{
			if (arr[i][j] == 3) {
				if (j == 1) {
					mysetcolor(4, 0);
					cout << char(11) << " ";
				}
				else {
					mysetcolor(4, 0);
					cout << "  " << char(11) << " ";
				}
			}
			else if (arr[i][j] == 7) {
				if (j == 1) {
					mysetcolor(4, 0);
					cout << 'X' << " ";
					mysetcolor(7, 0);
				}
				else {
					mysetcolor(4, 0);
					cout << "  " << 'X' << " ";
					mysetcolor(7, 0);
				}
				counterPlayerShip++;
			}
			else if (arr[i][j] == 0 && i != size - 1) {
				if (i == 0) {
					for (size_t i = 0; i < 10; i++)
					{
						if (i == 0) {
							cout << "    <" << i << ">";
						}
						else {
							cout << " <" << i << ">";

						}
					}
					break;
				}
				else if (j == 0) {
					for (; m < 75; )
					{
						cout << "  " << (char)m << " |";
						m++;
						break;
					}
				}
				else if (j == size - 1) {
					mysetcolor(7, 0);
					cout << "|" << endl;;
				}
				else if (arr[i][j] == 0) {
					if (j == 1) {
						mysetcolor(3, 0);
						cout << (char)219 << "|";;
						mysetcolor(7, 0);
					}
					else {
						mysetcolor(3, 0);
						cout << " |" << (char)219 << "|";;
						mysetcolor(7, 0);
					}
				}
				else {
					cout << "  ";
				}
			}

			else if (arr[i][j] == 2) {

				if (j == 1) {
					mysetcolor(11, 0);
					cout << "o" << " ";
					mysetcolor(7, 0);
				}
				else {
					mysetcolor(11, 0);
					cout << "  " << "o" << " ";
					mysetcolor(7, 0);
				}
			}
			else {
				if (j == 1) {
					mysetcolor(3, 0);
					cout << (char)219 << "|";;
					mysetcolor(7, 0);
				}
				else {
					mysetcolor(3, 0);
					cout << " |" << (char)219 << "|";
					mysetcolor(7, 0);
				}
			}
		}
		cout << endl;
		if (counterPlayerShip == 16) {
			ShowWinPlayer();
			system("pause");
			system("cls");

		}
	}
}








bool isEmptyPlace(int** arr, int y, int x) {

	if (y == mysize - 1 || x == mysize - 1)
		return false;

	if (y == 0 || x == 0)
		return false;

	if (arr[y][x] == 6 || arr[y][x] == 7 || arr[y][x] == 2) return true;

	if (arr[y][x] != 0 || y < 0 || y >= mysize || x < 0 || x >= mysize)
		return false;

	return true;
}








bool fillShipManual(int** arr, int y, int x, Directions d, int count) {///1

	bool hasSomething = false;
	int countCheck = 0;

	if (d == RIGHT) {

		for (size_t i = y; i < y + 1; i++)
		{
			for (size_t j = x; j < x + count; j++) {

				if (arr[i][j] != 0 || i < 0 || i >= mysize || j < 0 || j >= mysize || arr[i][j + 1] == 5
					|| arr[y + 1][x] == 5 || arr[y][x + 1] == 5 || arr[y][x - 1] == 5)
					countCheck++;

				if (y - 1 != -1) {

					if (arr[y - 1][x] == 5)
						++countCheck;
				}
			}
		}

		if (countCheck == 0) {

			for (size_t i = y; i < y + 1; i++)
			{
				for (size_t j = x; j < x + count; j++)
					arr[i][j] = 5;
			}

			hasSomething = false;
		}

		else
		{
			hasSomething = true;
			cout << "\a" << endl;
		}
	}

	else if (d == DOWN) {

		int i = 0, k = 0;

		for (i = y; i < y + count; i++) {//count+1 yazdiqda y=8 count=3 olsa  onda i<12 olacaq en boyuk y-in qiymeti 11dir 

			if (i > 10) {
				countCheck++;
				break;
			}

			for (k = x - 1; k < x + 2; k++) {

				if (k == -1) {
					k++;
				}
				if (arr[i][k] != 0 || k < 0 || k > mysize || i < 0 || i > mysize
					|| arr[y + 1][x] == 5 || arr[y][x + 1] == 5 || arr[y][x - 1] == 5)
					++countCheck;

			}

		}

		if (countCheck == 0) {

			for (size_t i = y; i < y + count; i++)
			{
				for (size_t j = x; j < x + 1; j++)
					arr[i][j] = 5;
			}

			hasSomething = false;
		}
		else
		{
			hasSomething = true;
			cout << "\a";
		}
	}
	return hasSomething;
}




void reversManual(int** arr, int y, int x, Directions d, int count) {

	fillShipManual(arr, point.y, point.x, d, count);
}




//baxilacaq bura
void clearShip(int** arr, int y, int x, Directions d, int count) {

	if (d == RIGHT) {

		for (size_t i = y; i < y + 1; i++)
		{
			for (size_t k = x; k < x + count + 1; k++)
				arr[i][k] = 0;
		}
	}

	else if (d == DOWN) {

		for (size_t i = y; i < y + count; i++)
		{
			if (i >= 10) break;
			for (size_t k = x; k < x + 1; k++)
				arr[i][k] = 0;
		}
	}
}




bool putShipWithCordinates(int** arr, int y, int x, Directions direction, int count) {//2
	if (count + x <= 11) {

		bool result = fillShipManual(arr, point.y, point.x, direction, count);
		char revers = ' ';

		do
		{
			system("cls");
			ShowMyships(arr, mysize);

			int revers = 0;
			revers = _getch();

			if (revers == REVERS) {

				clearShip(arr, point.y, point.x, RIGHT, count);
				if (direction == RIGHT) {

					direction = DOWN;
					reversManual(arr, point.y, point.x, DOWN, count);
				}

				else
				{
					direction = RIGHT;
					clearShip(arr, point.y, point.x, DOWN, count);
					reversManual(arr, point.y, point.x, RIGHT, count);
				}
				ShowMyships(arr, mysize);
			}

			if (revers == ENTER) {
				point.y = 0;
				point.x = 0;
				break;
			}

		} while (revers != ENTER);
		return result;
	}
	return true;//Counter+X temasi
}







void putShipManual(int** arr) {//Yerlesdirir ve ilkin yerine qayidir  //       
	//Oyuncunun Hereketini tenzimleyir,ve gemileri yerlesdirir

	int counters[5] = { 4,2,3,5,2 };
	int index = 0;

	while (true) {
		system("cls");
		ShowMyships(arr, mysize);
		int direction = 0;
		direction = _getch();


		if (direction == 224) {

			direction = _getch();
			arr[point.y][point.x] = 0;

			if (direction == RIGHT) {
				if (isEmptyPlace(arr, point.y, point.x + 1)) {
					if (point.x < 10) {
						point.x++;//Adam hereket edir saga dogru
					}
				}
			}

			else if (direction == LEFT) {

				if (isEmptyPlace(arr, point.y, point.x - 1))
					point.x--;//Adam hereket edir sola dogru
			}

			else if (direction == UP) {

				if (isEmptyPlace(arr, point.y - 1, point.x)) {
					point.y--;//Adam hereket yuxari saga dogru
				}
			}

			else if (direction == DOWN) {
				if (isEmptyPlace(arr, point.y + 1, point.x)) {
					if (point.y < 10) {
						point.y++;//Adam hereket edir asagiya dogru
					}
				}
			}

			arr[point.y][point.x] = 1;
		}

		else if (direction == ENTER) {

			arr[point.y][point.x] = 0;
			bool result = putShipWithCordinates(arr, point.y, point.x, RIGHT, counters[index]);//Counter saylara gore doldurur geminin uzununlugunu, index ise ardicilliqdi

			if (result == false)
				++index;

			point.y = 1;
			point.x = 1;
			arr[point.y][point.x] = 1;

			if (index == 5) {
				break;
			}
		}
	}

}






bool fillShipsRandomly(int** arr, int y, int x, Directions d, int count, int data) { 


	bool hasSomething = false;
	int counterChecker = 0;

	if (d == RIGHT) {

		int i = 0, k = 0;  
		for (int i = y - 1; i < y + 2; i++) {

			for (int k = x - 1; k < x + count + 1; k++) {
				if (arr[i][k] != 0)
					++counterChecker;//5
			}
			if (counterChecker > 0)
				break;
		}

		if (counterChecker == 0) {

			for (int i = y; i < y + 1; i++) {

				for (int k = x; k < x + count; k++) {

					arr[i][k] = data;
				}
			}

			hasSomething = false;
		}

		else { hasSomething = true; }
	}

	else if (d == DOWN) {

		int i = 0, k = 0;

		for (i = y - 1; i < y + count + 1; i++) {

			if (i >= 10) {
				counterChecker++;
				break;
			}

			for (k = x - 1; k < x + 2; k++) {

				if (arr[i][k] != 0 || k < 0 || k > mysize || i < 0 || i > mysize || arr[x - 1][y + 1] == 5)
					++counterChecker;
			}
		}

		if (counterChecker == 0) {

			for (size_t i = y; i < y + count; i++)
			{
				for (size_t j = x; j < x + 1; j++)
					arr[i][j] = data;
			}

			hasSomething = false;
		}
		else
		{
			hasSomething = true;
			cout << "\a";
		}
	}
	return hasSomething;
}






void fillSpecialFunction(int** arr, int count, int data) {      
	srand(time(nullptr));
	bool isNotOkay = false;
	do
	{
		int x = 2 + rand() % (10 - 2 + 1);//11 max goturende qiraqda sehv verirdi
		int y = 1 + rand() % (10 - 1 + 1);

		isNotOkay = false;
		if (y % 2 == 0) {
			isNotOkay = fillShipsRandomly(arr, y, x, RIGHT, count, data);//Buradan sonra random verdiyi X ve Y koor  doldurur
		}
		else {
			isNotOkay = fillShipsRandomly(arr, y, x, DOWN, count, data);
		}

		if (isNotOkay == false)break;

	} while (isNotOkay == true);
	srand(81);
}







//void fillSpecialFunctionEnemy(int** arr, int count, int data) {
//
//	srand(time(nullptr));
//
//	bool isNotOkay = false;
//
//	do
//	{
//		int x = 2 + rand() % (10 - 2 + 1);
//		int y = 1 + rand() % (10 - 1 + 1);
//
//		isNotOkay = false;
//
//		if (x % 2 == 0) {
//			isNotOkay = fillShipsRandomly(arr, y, x, RIGHT, count, data);
//		}
//		else {
//			isNotOkay = fillShipsRandomly(arr, y, x, DOWN, count, data);
//		}
//
//		if (isNotOkay == false)break;
//
//	} while (isNotOkay == true);
//	srand(43);
//}






void putShipRandomly(int** arr, int data) {
	srand(200);
	const int size = 5;
	int counters[size] = { 5,3,2,4,2};
	for (size_t i = 0; i < size; i++)
		fillSpecialFunction(arr, counters[i], data);
}






void putShipRandomlyEnemy(int** arr, int data) {
	srand(101);
	const int size = 5;
	int counters[size] = { 2,3,4,2,5 };

	for (size_t i = 0; i < size; i++)
		fillSpecialFunction(arr, counters[i], data);
}





bool isEmptyArea(int** arr, int x, int y) {

	if (arr[y][x - 1] == 7 || arr[y][x + 1] == 7 || arr[y - 1][x] == 7 || arr[y + 1][x] == 7) {

		return false;
	}
	return true;
}















