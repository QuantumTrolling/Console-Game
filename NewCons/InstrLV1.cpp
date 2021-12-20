#include <stdlib.h>
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "coord.h"
#include <thread>

using namespace std;

extern int HP;
extern int MP;
extern int cntHP;
extern int cntMP;

extern bool UserWin1;

extern int curX1;
extern int curY1;

void Inst() {
	Sleep(150);

	bool inHP = 1;
	bool inMP = 1;

	gotoxy(105, 2);
	cout << "Use arrows";
	gotoxy(105, 3);
	cout << " to move.";
	Sleep(1000);
	gotoxy(104, 5);
	cout << " You need to ";
	gotoxy(105, 6);
	cout << "take this " << "\x1b[31m" << (char)skHP << "\x1b[0m";
	Sleep(600);
	gotoxy(30, 6);

	cout << "\x1b[31m" << (char)skHP << "\x1b[0m";
	while (inHP) {
		if (HP > 0 && cntHP < HP)
		{
			gotoxy(105, 2);
			cout << "            ";
			gotoxy(105, 3);
			cout << "            ";
			gotoxy(104, 5);
			cout << "             ";
			gotoxy(105, 6);
			cout << "            ";
			cntHP++;
			gotoxy(104, 1);
			cout << "HP ";
			int count = HP;
			while (count > 0) {
				cout << "\x1b[31m" << (char)skHP << "\x1b[0m" << " ";
				count--;
			}
			Sleep(1000);
			gotoxy(104, 4);
			cout << "It is your";
			gotoxy(104, 5);
			cout << "Health Point";
			Sleep(2000);
		}
		if (cntHP == HP && cntHP != 0) {
			gotoxy(60, 10);
			cout << "\x1b[36m" << (char)skMP << "\x1b[0m";
			gotoxy(104, 4);
			cout << "            ";
			gotoxy(104, 5);
			cout << "              ";
			gotoxy(104, 4);
			cout << "Now you need";
			gotoxy(104, 5);
			cout << "to take this " << "\x1b[36m" << (char)skMP << "\x1b[0m";;
			Sleep(600);
			inHP = 0;
		}
	}
	while(inMP){
		if (MP > 0 && MP != cntMP) {
			cntMP++;
			gotoxy(104, 4);
			cout << "              ";
			gotoxy(104, 5);
			cout << "                ";
			gotoxy(104, 2);
			cout << "MP ";
			int count = MP;
			while (count > 0) {
				cout << "\x1b[36m" << (char)skMP << "\x1b[0m" << " ";
				count--;
			}
			Sleep(1000);
			gotoxy(60, 10);
			cout << (char)skin;
			gotoxy(104, 4);
			cout << "It is your";
			gotoxy(104, 5);
			cout << "Mana Point";
			Sleep(1500);
			inMP = 0;
		}
	}

}