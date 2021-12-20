#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <stdlib.h>
#include "coord.h"
#include "SetDif.h"

using namespace std;

int vel = 300; // enemy velocity
int enVis = 256; // enemy vision
int vis = 6; // Player vision

void Settings() {

	gotoxy(startX - 7, startY - 10);
	cout << "Chose Level of Difficulty: ";
	gotoxy(startX - 5, startY - 8);
	cout << "EASY";
	gotoxy(startX - 5, startY - 7);
	cout << "NORMAL";
	gotoxy(startX - 5, startY - 6);
	cout << "HARD";
	gotoxy(startX - 7, startY - 4);
	if (vis == 6) {
		cout << "Selected Level: HORMAL";
	}
	else if (vis == 7) {
		cout << "Selected Level: EASY";
	}
	else
		cout << "Selected Level: HARD";

	int ch = 0 ;
	int st = 0;

	while (ch != 27) {
		ch = _getch();
		if (ch == 0 || ch == 224) {
			switch (_getch()) {
			case 72:
				if (st == 1) {
					dif(3);
					st = 3;
				}
				else if (st > 1) {
					dif(st - 1);
					st--;
				}
				else break;
				// code for arrow up
				break;
			case 80:
				if (st == 3) {
					dif(1);
					st = 1;
				}
				else if (st < 3) {
					dif(st + 1);
					st++;
				}
				else break;
				// code for arrow down
				break;
			}
		}
		if (st == 1 && (ch == 13 || ch==97)) {
			vel = 400;
			enVis = 196;
			vis = 7;
			gotoxy(startX + 9, startY - 4);
			cout << "          ";
			gotoxy(startX + 9, startY - 4);
			cout << "EASY";
		}
		if (st == 2 && (ch == 13 || ch == 97)) {
			vel = 300;
			enVis = 256;
			vis = 6;
			gotoxy(startX + 9, startY - 4);
			cout << "          ";
			gotoxy(startX + 9, startY - 4);
			cout << "NORMAL";
		}
		if (st == 3 && (ch == 13 || ch == 97)) {
			vel = 200;
			enVis = 324;
			vis = 5;
			gotoxy(startX + 9, startY - 4);
			cout << "          ";
			gotoxy(startX + 9, startY - 4);
			cout << "HARD";
		}
	}

	system("cls");
}