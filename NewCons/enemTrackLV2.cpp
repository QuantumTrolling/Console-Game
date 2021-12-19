#include <stdlib.h>
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "coord.h"
#include "EnemiDead.h"

using namespace std;

extern int HP;

extern int curX;
extern int curY;
extern int enXgl;
extern int enYgl;
extern bool UserWin2;
extern int EnemHP2;
extern int EnemHP;

extern int enVis;

void SmartTrack2(int vel) {
	bool EnFirstPrint = 1;
	while (!((HP < 1) || (UserWin2 == 1) || (EnemHP2 == 0))) {
		Sleep(150);
		if (EnemHP == 0) {
			if (EnFirstPrint) {
				gotoxy(enXgl, enYgl);
				cout << "\x1b[32m" << (char)skEnem << "\x1b[0m";;
				EnFirstPrint = 0;
			}
			if (((abs(curX - enXgl)) * (abs(curX - enXgl)) + (abs(curY - enYgl)) * (abs(curY - enYgl))) <= enVis) {
				while (((abs(curX - enXgl)) * (abs(curX - enXgl)) + (abs(curY - enYgl)) * (abs(curY - enYgl))) <= enVis) {
					if (enXgl > curX && enYgl > curY) {
						gotoxy(enXgl, enYgl);
						cout << "\x1b[32m" << (char)skEnem << "\x1b[0m";
						Sleep(vel);
						gotoxy(enXgl, enYgl);
						cout << " ";
						enXgl--;
						enYgl--;
					}
					if (enXgl < curX && enYgl < curY) {
						gotoxy(enXgl, enYgl);
						cout << "\x1b[32m" << (char)skEnem << "\x1b[0m";
						Sleep(vel);
						gotoxy(enXgl, enYgl);
						cout << " ";
						enXgl++;
						enYgl++;
					}
					if (enXgl > curX && enYgl < curY) {
						gotoxy(enXgl, enYgl);
						cout << "\x1b[32m" << (char)skEnem << "\x1b[0m";
						Sleep(vel);
						gotoxy(enXgl, enYgl);
						cout << " ";
						enXgl--;
						enYgl++;
					}
					if (enXgl < curX && enYgl > curY) {
						gotoxy(enXgl, enYgl);
						cout << "\x1b[32m" << (char)skEnem << "\x1b[0m";
						Sleep(vel);
						gotoxy(enXgl, enYgl);
						cout << " ";
						enXgl++;
						enYgl--;
					}
					if ((enXgl == curX) && enYgl < curY) {
						gotoxy(enXgl, enYgl);
						cout << "\x1b[32m" << (char)skEnem << "\x1b[0m";
						Sleep(vel);
						gotoxy(enXgl, enYgl);
						cout << " ";
						enYgl++;
					}
					if ((enXgl == curX) && enYgl > curY) {
						gotoxy(enXgl, enYgl);
						cout << "\x1b[32m" << (char)skEnem << "\x1b[0m";
						Sleep(vel);
						gotoxy(enXgl, enYgl);
						cout << " ";
						enYgl--;
					}
					if ((enYgl == curY) && enXgl < curX) {
						gotoxy(enXgl, enYgl);
						cout << "\x1b[32m" << (char)skEnem << "\x1b[0m";
						Sleep(vel);
						gotoxy(enXgl, enYgl);
						cout << " ";
						enXgl++;
					}
					if ((enYgl == curY) && enXgl > curX) {
						gotoxy(enXgl, enYgl);
						cout << "\x1b[32m" << (char)skEnem << "\x1b[0m";
						Sleep(vel);
						gotoxy(enXgl, enYgl);
						cout << " ";
						enXgl--;
					}
					if (((enXgl == curX) && (enYgl == curY))) { HP--; EnemHP2--; }
					if (HP < 1 || UserWin2 == 1 || EnemHP2 == 0)
						break;
				}
				gotoxy(enXgl, enYgl);
				cout << "\x1b[32m" << (char)skEnem << "\x1b[0m";
				if (EnemHP2 == 0)
					EnemiDead(enXgl, enYgl);
				else if (UserWin2 == 1 || HP < 1) {
					gotoxy(enXgl, enYgl);
					cout << " ";
				}
			}
		}
	}
}