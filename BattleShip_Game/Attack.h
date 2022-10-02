#pragma once
#include<iostream>
#include<Windows.h>
#include"Entities.h"
#include"Function.h"
using namespace std;


void ClearBlow(Striked& strike) {
	strike.down = false;
	strike.down_Access = false;
	strike.left = false;
	strike.left_Access = false;
	strike.right = false;
	strike.right_Access = false;
	strike.striked = false;
	strike.striked_x = -1;
	strike.striked_y = -1;
}



void ShowMetods() {
	system("cls");
	ShowMyships(playerBoard, mysize);
	ShowEnemyShips(enemyBoard, mysize);
}



bool isBoom(int** arr, int x, int y) {


	if (arr[y][x - 1] == 5 || arr[y][x + 1] == 5 || arr[y - 1][x] == 5 || arr[y + 1][x] == 5) {

		return false;
	}

	return true;
}



bool AttackPlayer(int** arr) {

	int old_y = 1;
	int old_x = 1;
	int simvol = -1;

	if (chekingIgnore == false) {

		cin.ignore();
		cin.clear();
		chekingIgnore = true;
	}

	while (true) {

		system("cls");
		ShowMyships(playerBoard, mysize);
		ShowEnemyShips(arr, mysize);

		int direction = 0;
		direction = _getch();

		if (direction == 224) {
			direction = _getch();//Bu hisse uzerinden kecmek ucun duzeldilecek
			old_y = point.y;
			old_x = point.x;

			if (arr[point.y][point.x] == 3 && simvol != -1)
				arr[old_y][old_x] = simvol;

			if (direction == RIGHT) {

				if (isEmptyPlace(arr, point.y, point.x + 1)) {
					simvol = arr[point.y][point.x + 1];
					point.x++;
				}
			}

			else if (direction == LEFT) {

				if (isEmptyPlace(arr, point.y, point.x - 1)) {
					simvol = arr[point.y][point.x - 1];
					point.x--;
				}
			}

			else if (direction == UP) {

				if (isEmptyPlace(arr, point.y - 1, point.x)) {
					simvol = arr[point.y - 1][point.x];
					point.y--;
				}
			}

			else if (direction == DOWN) {

				if (isEmptyPlace(arr, point.y + 1, point.x)) {
					simvol = arr[point.y + 1][point.x];
					point.y++;
				}
			}
			arr[point.y][point.x] = 3;
		}

		else if (direction == ENTER) {

			if (simvol == 6) {
				arr[point.y][point.x] = 7;
				simvol = -1;
				continue;
			}

			else if (simvol == 0) {

				arr[point.y][point.x] = 2;
				return false;
			}

			else {
				arr[point.y][point.x] = 0;
				point.y = 0;
				point.x = 1;
				return false;
			}

		}
	}
}


void AttackRandomCPU(int** arr) {
	srand(time(0));

	bool isOkay = false;
	int x = 1;
	int y = 1;

	while (true) {

		do {

			x = 1 + rand() % (10 - 1 + 1);///////////////////////////////
			y = 1 + rand() % (10 - 1 + 1);
			Sleep(500);

		} while (arr[y][x] == 2 || arr[y][x] == 7);

		if (!strike.striked) {

			if (arr[y][x] == 5) {

				if (isBoom(arr, x, y)) {

					cout << "\a\a\a";
					ClearBlow(strike);
					continue;
				}

				arr[y][x] = 7;//  X bomba partladi simvolu

				strike.striked = true;
				strike.striked_x = x;
				strike.striked_y = y;

				system("cls");
				ShowMyships(playerBoard, mysize);
				ShowEnemyShips(enemyBoard, mysize);
				Sleep(500);
				continue;
			}
		}

		else {

			if (!strike.left_Access) {

				if (strike.left == false) {

					x = strike.striked_x - 1;
					y = strike.striked_y;

					if (arr[y][x] == 2) {// o isaresi
						strike.left_Access = true;
						continue;
					}
					else if (y >= mysize || y<0 || x>mysize || x < 0) {
						strike.left_Access = true;
						continue;
					}

					if (isEmptyArea(arr, x, y)) {
						strike.left_Access = true;
						continue;
					}

					if (arr[y][x] == 5) {

						arr[y][x] = 7;
						strike.left = true;

						if (isBoom(arr, x, y)) {
							if (isBoom(arr, strike.striked_x, strike.striked_y)) {
								cout << "\a\a\a";
								ClearBlow(strike);
								continue;
							}
						}
					}

					else {
						arr[y][x] = 2;
						strike.left = false;
						strike.left_Access = true;
						Sleep(500);
						ShowMetods();
						break;
					}
				}

				if (strike.left == true) {

					x = strike.striked_x - 2;
					y = strike.striked_y;

					if (arr[y][x] == 2) {
						strike.left_Access = true;
						continue;
					}
					else if (y >= mysize || y<0 || x>mysize || x < 0) {
						strike.left_Access = true;
						continue;
					}
					if (arr[y][x] == 5) {
						arr[y][x] = 7;
						strike.left = true;
						if (isBoom(arr, x, y)) {
							if (isBoom(arr, strike.striked_x, strike.striked_y)) {
								cout << "\a\a\a";
								ClearBlow(strike);
								continue;
							}
						}
						Sleep(500);
						ShowMetods();
					}
					else {
						arr[y][x] = 2;
						strike.left = false;
						strike.left_Access = true;
						Sleep(500);
						ShowMetods();
						break;
					}
				}

				if (strike.left == true) {

					x = strike.striked_x - 3;
					y = strike.striked_y;

					if (arr[y][x] == 2) {
						strike.left_Access = true;
						continue;
					}
					else if (y >= mysize || y<0 || x>mysize || x < 0) {
						strike.left_Access = true;
						continue;
					}

					if (arr[y][x] == 5) {
						arr[y][x] = 7;
						strike.left = true;
						if (isBoom(arr, x, y)) {
							if (isBoom(arr, strike.striked_x, strike.striked_y)) {
								cout << "\a\a\a";
								ClearBlow(strike);
								continue;
							}
						}
						Sleep(500);
						ShowMetods();
					}
					else {
						arr[y][x] = 2;
						strike.left = false;
						strike.left_Access = true;
						Sleep(500);
						ShowMetods();
						break;
					}
				}
			}

			if (!strike.right_Access) {

				if (strike.right == false) {

					x = strike.striked_x + 1;
					y = strike.striked_y;

					if (arr[y][x] == 2) {
						strike.right_Access = true;
						continue;
					}
					else if (y >= mysize || y<0 || x>mysize || x < 0) {
						strike.right_Access = true;
						continue;
					}

					if (isEmptyArea(arr, x, y)) {
						strike.left_Access = true;
						continue;
					}

					if (arr[y][x] == 5) {
						arr[y][x] = 7;
						strike.right = true;
						if (isBoom(arr, x, y)) {
							if (isBoom(arr, strike.striked_x, strike.striked_y)) {
								cout << "\a\a\a";
								ClearBlow(strike);
								continue;
							}
						}
						Sleep(500);
						ShowMetods();
					}

					else {
						arr[y][x] = 2;
						strike.right = false;
						strike.right_Access = true;
						Sleep(500);
						ShowMetods();
						break;
					}
				}

				if (strike.right == true) {

					x = strike.striked_x + 2;
					y = strike.striked_y;

					if (arr[y][x] == 2) {
						strike.right_Access = true;
						continue;
					}
					else if (y >= mysize || y<0 || x>mysize || x < 0) {
						strike.right_Access = true;
						continue;
					}

					if (arr[y][x] == 5) {
						arr[y][x] = 7;
						strike.right = true;
						if (isBoom(arr, x, y)) {
							if (isBoom(arr, strike.striked_x, strike.striked_y)) {
								cout << "\a\a\a";
								ClearBlow(strike);
								continue;
							}
						}
						Sleep(500);
						ShowMetods();
					}
					else {
						arr[y][x] = 2;
						strike.right = false;
						strike.right_Access = true;
						//strike.up_Access = true;
						//strike.dowm_Access = true;
						Sleep(500);
						ShowMetods();
						break;
					}
				}

				if (strike.right == true) {

					x = strike.striked_x + 3;
					y = strike.striked_y;

					if (arr[y][x] == 2) {
						strike.right_Access = true;
						continue;
					}
					else if (y >= mysize || y<0 || x>mysize || x < 0) {
						strike.right_Access = true;
						continue;
					}

					if (arr[y][x] == 5) {
						arr[y][x] = 7;
						strike.right = true;
						if (isBoom(arr, x, y)) {
							if (isBoom(arr, strike.striked_x, strike.striked_y)) {
								cout << "\a\a\a";
								ClearBlow(strike);
								continue;
							}
						}
						Sleep(500);
						ShowMetods();
					}
					else {
						arr[y][x] = 2;
						strike.right = false;
						strike.right_Access = true;
						Sleep(500);
						ShowMetods();
						break;
					}
				}
			}

			if (!strike.down_Access) {

				//strike.down_Access = true;
				if (strike.down == false) {

					x = strike.striked_x;
					y = strike.striked_y + 1;

					if (arr[y][x] == 2) {
						strike.down_Access = true;
						continue;
					}
					else if (y >= mysize || y<0 || x>mysize || x < 0) {
						strike.down_Access = true;
						continue;
					}
					if (isEmptyArea(arr, x, y)) {
						strike.left_Access = true;
						continue;
					}

					if (arr[y][x] == 5) {
						arr[y][x] = 7;
						strike.down = true;
						if (isBoom(arr, x, y)) {
							if (isBoom(arr, strike.striked_x, strike.striked_y)) {
								cout << "\a\a\a";
								ClearBlow(strike);
								continue;
							}
						}
						Sleep(500);
						ShowMetods();
					}

					else {
						arr[y][x] = 2;
						strike.down = false;
						strike.down_Access = true;
						Sleep(500);
						ShowMetods();
						break;
					}
				}

				if (strike.down == true) {

					x = strike.striked_x;
					y = strike.striked_y + 2;

					if (arr[y][x] == 2) {
						strike.down_Access = true;
						continue;
					}
					else if (y >= mysize || y<0 || x>mysize || x < 0) {
						strike.down_Access = true;
						continue;
					}

					if (arr[y][x] == 5) {
						arr[y][x] = 7;
						strike.down = true;
						if (isBoom(arr, x, y)) {
							if (isBoom(arr, strike.striked_x, strike.striked_y)) {
								cout << "\a\a\a";
								ClearBlow(strike);
								continue;
							}
						}
						Sleep(500);
						ShowMetods();
					}
					else {
						arr[y][x] = 2;
						strike.down = false;
						strike.down_Access = true;
						Sleep(500);
						ShowMetods();
						break;
					}
				}

				if (strike.down == true) {

					x = strike.striked_x;
					y = strike.striked_y + 3;

					if (arr[y][x] == 2) {
						strike.down_Access = true;
						continue;
					}
					else if (y >= mysize || y<0 || x>mysize || x < 0) {
						strike.down_Access = true;
						continue;
					}

					if (arr[y][x] == 5) {
						arr[y][x] = 7;
						strike.down = true;
						if (isBoom(arr, x, y)) {
							if (isBoom(arr, strike.striked_x, strike.striked_y)) {
								cout << "\a\a\a";
								ClearBlow(strike);
								continue;
							}
						}
						Sleep(500);
						ShowMetods();
					}
					else {
						arr[y][x] = 2;
						strike.down = false;
						strike.down_Access = true;
						Sleep(500);
						ShowMetods();
						break;
					}
				}
			}

			if (!strike.up_Access) {

				strike.up_Access = true;
				if (strike.up == false) {

					x = strike.striked_x;
					y = strike.striked_y - 1;

					if (arr[y][x] == 2) {
						strike.up_Access = true;
						continue;
					}
					else if (y >= mysize || y<0 || x>mysize || x < 0) {
						strike.up_Access = true;
						continue;
					}
					if (isEmptyArea(arr, x, y)) {
						strike.left_Access = true;
						continue;
					}

					if (arr[y][x] == 5) {
						arr[y][x] = 7;
						strike.up = true;
						if (isBoom(arr, x, y)) {
							if (isBoom(arr, strike.striked_x, strike.striked_y)) {
								cout << "\a\a\a";
								ClearBlow(strike);
								continue;
							}
						}
						Sleep(500);
						ShowMetods();
					}

					else {
						arr[y][x] = 2;
						strike.up = false;
						strike.up_Access = true;
						Sleep(500);
						ShowMetods();
						break;
					}
				}

				if (strike.up == true) {

					x = strike.striked_x;
					y = strike.striked_y - 2;

					if (arr[y][x] == 2) {
						strike.up_Access = true;
						continue;
					}
					else if (y >= mysize || y<0 || x>mysize || x < 0) {
						strike.up_Access = true;
						continue;
					}

					if (arr[y][x] == 5) {
						arr[y][x] = 7;
						strike.up = true;
						if (isBoom(arr, x, y)) {
							if (isBoom(arr, strike.striked_x, strike.striked_y)) {
								cout << "\a\a\a";
								ClearBlow(strike);
								continue;
							}
						}
						Sleep(500);
						ShowMetods();
					}
					else {
						arr[y][x] = 2;
						strike.up = false;
						strike.up_Access = true;
						Sleep(500);
						ShowMetods();
						break;
					}
				}

				if (strike.up == true) {

					x = strike.striked_x;
					y = strike.striked_y - 3;

					if (arr[y][x] == 2) {
						strike.up_Access = true;
						continue;
					}
					else if (y >= mysize || y<0 || x>mysize || x < 0) {
						strike.up_Access = true;
						continue;
					}

					if (arr[y][x] == 5) {
						arr[y][x] = 7;
						strike.up = true;
						if (isBoom(arr, x, y)) {
							if (isBoom(arr, strike.striked_x, strike.striked_y)) {
								cout << "\a\a\a";
								ClearBlow(strike);
								continue;
							}
						}
						Sleep(500);
						ShowMetods();
					}
					else {
						arr[y][x] = 2;
						strike.up = false;
						strike.up_Access = true;
						Sleep(500);
						ShowMetods();
						break;
					}
				}
			}
		}

		if (arr[y][x] == 0) {

			arr[y][x] = 2;
			break;
		}
	}
}
