#include <stdlib.h>
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "coord.h"
#include <thread>

using namespace std;

extern int EnemHP;
extern bool CleanEnemDiscr;
extern bool UserWin2;

void Inst2() {
	Sleep(100);

	gotoxy(80, 14);
	cout << "\x1b[32m" << (char)skEnem << "\x1b[0m";
	Sleep(300);
	gotoxy(103, 4);
	cout << "It's your enemies";
	gotoxy(108, 5);
	cout << "\x1b[32m" << (char)skEnem << "\x1b[0m";
	Sleep(1000);
	gotoxy(103, 6);
	cout << "You can kill them";
	gotoxy(103, 7);
	cout << "by using your MP";
	Sleep(1000);
	gotoxy(103, 9);
	cout << "Try to kill him";
	gotoxy(103, 10);
	cout << "Button 'A'";
	Sleep(600);

	while (CleanEnemDiscr) {
		if (EnemHP == 0 && CleanEnemDiscr) {
			gotoxy(103, 4);
			cout << "                 ";
			gotoxy(108, 5);
			cout << "   ";
			gotoxy(103, 6);
			cout << "                 ";
			gotoxy(103, 7);
			cout << "                 ";
			gotoxy(103, 9);
			cout << "                 ";
			gotoxy(103, 10);
			cout << "                 ";

			gotoxy(10, 9);
			cout << "\x1b[36m" << (char)skMP << "\x1b[0m";
			Sleep(500);
			gotoxy(103, 4);
			cout << "Now try to kill";
			Sleep(600);
			gotoxy(103, 5);
			cout << "one more enemy.";
			Sleep(600);
			gotoxy(103, 7);
			cout << "But be carefull";
			Sleep(900);
			gotoxy(103, 8);
			cout << "now enemy can";
			Sleep(600);
			gotoxy(107, 9);
			cout << "move! ";
			Sleep(1000);

			CleanEnemDiscr = 0;
		}
	}
}