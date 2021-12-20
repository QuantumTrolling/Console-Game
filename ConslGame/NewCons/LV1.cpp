#include <stdlib.h>
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <thread>
#include "coord.h"
#include "InstrLV1.h"

using namespace std;

int HP; // Health Point
int MP; // Mana Point

int Score = 0; // Player score
int chScore = 0; // score flag

int cntHP = 0;
int cntMP = 0;

bool UserWin1 = 0;
int curX1 = 51, curY1 = 14; // Player coordinates

int LV1()
{
	HP = 0;
	MP = 0;

	bool HaveMP = 1; // MP flag
	bool HaveHP = 1; // HP flag

	gotoxy(startX+2, startY - 2);
	cout << "LEVEL 1";
	gotoxy(startX - 4, startY + 3);
	cout << "Press Enter to start...";

	int start1 = _getch();
	if (start1 == 13 || start1==0 || start1==224) {
		system("cls");
		// bordes
		{
			for (int i = 1; i < 102; i++)
				for (int j = 0; j < 1; j++) {
					gotoxy(i, j);
					cout << (char)205;
				}
			for (int i = 1; i < 102; i++)
				for (int j = 29; j < 30; j++) {
					gotoxy(i, j);
					cout << (char)205;
				}
			for (int i = 0; i < 1; i++)
				for (int j = 1; j < 29; j++) {
					gotoxy(i, j);
					cout << (char)186;
				}
			for (int i = 102; i < 103; i++)
				for (int j = 1; j < 29; j++) {
					gotoxy(i, j);
					cout << (char)186;
				}
			gotoxy(0, 0);
			cout << (char)201;
			gotoxy(102, 0);
			cout << (char)187;
			gotoxy(0, 29);
			cout << (char)200;
			gotoxy(102, 29);
			cout << (char)188;
			gotoxy(51, 14);
		}
		thread Ins(Inst); // Thread of instructions
		gotoxy(curX1, curY1);
		cout << (char)skin;
		int fl = 0;
		while (fl != 27) {
			Sleep(60);
			fl = _getch();
			if (fl == 0 || fl == 224) {
				switch (_getch()) {
				case 72: // code for arrow up
					if (curY1 != 1) {
						gotoxy(curX1, curY1);
						curY1 -= 1;
						cout << " ";
						gotoxy(curX1, curY1);
						cout << (char)skin;
					}
					else break;
					break;
				case 80: // code for arrow down
					if (curY1 < 28) {
						gotoxy(curX1, curY1);
						curY1 += 1;
						cout << " ";
						gotoxy(curX1, curY1);
						cout << (char)skin;
					}
					else break;
					break;
				case 77: // code for arrow right
					if (curX1 < 101) {
						gotoxy(curX1, curY1);
						curX1 += 1;
						cout << " ";
						gotoxy(curX1, curY1);
						cout << (char)skin;
					}
					else break;
					break;
				case 75: // code for arrow left
					if (curX1 != 1) {
						gotoxy(curX1, curY1);
						curX1 -= 1;
						cout << " ";
						gotoxy(curX1, curY1);
						cout << (char)skin;
					}
					else break;
					break;

				}
				if (curX1 == 30 && curY1 == 6 && HaveHP) {
					HP++;
					HaveHP = 0;
				}
			}
			if (curX1 == 60 && curY1 == 10 && HaveMP) {
				MP++;
				HaveMP = 0;
			}
			// end of level
			if (HP == 1 && MP == 1) { UserWin1 = 1; break; }
		}

		if (UserWin1) {
			Ins.join();
			return 1; // Next level
		}
		else {
			UserWin1 = 1;
			Ins.join();
			return 0; // Menu
		}

	}

}