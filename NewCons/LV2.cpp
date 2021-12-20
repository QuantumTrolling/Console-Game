#include <stdlib.h>
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <thread>
#include "coord.h"
#include "EnemiDead.h"
#include "Attack.h"
#include "HPMPcnt.h"
#include "InstrLV2.h"
#include "enemTrackLV2.h"

using namespace std;

int enXgl; // enemy coordinates
int enYgl; // enemy coordinates
int curX;
int curY;

int chHP; // HP flag(for function 'MPHPcheck')
int chMP; // MP flag(for function 'MPHPcheck')

extern int HP;
extern int MP;

extern int vel;

extern int Score;
extern int chScore;

int EnemHP = 1;
int EnemHP2 = 1;

bool CleanEnemDiscr = 1;

bool UserWin2 = 0;

int LV2() 
{
	enXgl = 20;
	enYgl = 10;

	HP = chHP = 1;
	MP = chMP = 2;

	bool MPcriExist = 1; // flag of MP cristal

	system("cls");
	gotoxy(startX + 2, startY - 2);
	cout << "LEVEL 2";
	gotoxy(startX - 4, startY + 3);
	cout << "Press Enter to start...";
	Sleep(2000);

	int start2 = _getch();
	if (start2 == 13 || start2==0 || start2==224) {
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

		gotoxy(104, 1);
		int cnt1 = HP;
		cout << "HP ";
		while (cnt1 > 0) {
			cout << "\x1b[31m" << (char)skHP << "\x1b[0m" << " ";
			cnt1--;
		}

		gotoxy(104, 2);
		int cnt2 = MP;
		cout << "MP ";
		while (cnt2 > 0) {
			cout << "\x1b[36m" << (char)skMP << "\x1b[0m" << " ";
			cnt2--;
		}

		gotoxy(104, 28);
		cout << "Score: " << Score;

		curX = 51;
		curY = 14;

		gotoxy(curX, curY);
		cout << (char)skin;
		
		thread MPHP(MPHPcheck); // HP, MP and Score output
		thread Ins(Inst2); // Thread of instructions
		thread tEn(SmartTrack2, vel); // enemy track

		int fl = 0;
		while (fl != 27) {
			Sleep(60);
			fl = _getch();

			if (fl == 0 || fl == 224) {
				switch (_getch()) {
				case 72: // code for arrow up
					if (curY != 1 && !(curY - 1 == 6 && curX == 50)) {
						gotoxy(curX, curY);
						curY -= 1;
						cout << " ";
						gotoxy(curX, curY);
						cout << (char)skin;
					}
					else break;
					break;
				case 80: // code for arrow down
					if (curY < 28 && !(curY + 1 == 6 && curX == 50)) {
						gotoxy(curX, curY);
						curY += 1;
						cout << " ";
						gotoxy(curX, curY);
						cout << (char)skin;
					}
					else break;
					break;
				case 77: // code for arrow right
					if (curX < 101 && !(curY == 6 && curX + 1 == 50)) {
						gotoxy(curX, curY);
						curX += 1;
						cout << " ";
						gotoxy(curX, curY);
						cout << (char)skin;
					}
					else break;
					break;
				case 75: // code for arrow left
					if (curX != 1 && !(curY == 6 && curX - 1 == 50)) {
						gotoxy(curX, curY);
						curX -= 1;
						cout << " ";
						gotoxy(curX, curY);
						cout << (char)skin;
					}
					else break;
					break;

				}
			}
			if (curX == 80 && curY == 14 && EnemHP == 1){ // Plyaer death
				HP--;
				UserWin2 = 0;
				break;
			}
			if (fl == 97 && MP > 0) { // Attack and second enemy death
				Attack(curX, curY, 3);
				MP--;
				if (((abs(curX - enXgl)) * (abs(curX - enXgl)) + (abs(curY - enYgl)) * (abs(curY - enYgl))) <= 36) {
					EnemHP2--;
					Score += 3;
				}
			}
			if (curX > 74 && curX < 84 && curY>10 && curY < 18 && fl==97 && EnemHP==1) { // first enemy death
				EnemiDead(80, 14);
				Score += 3;
				EnemHP--;
			}
			if (((abs(curX - enXgl)) * (abs(curX - enXgl)) + (abs(curY - enYgl)) * (abs(curY - enYgl)))<=1 && EnemHP2>0) { // Plyaer death
				HP--;
				break;
			}
			if (curX == 10 && curY == 9 && MPcriExist) { // Player take MP
				MP++;
				Score++;
				MPcriExist = 0;
			}
			// end of level
			if (EnemHP == 0 && EnemHP2==0 && HP!=0)
				UserWin2 = 1;
			if (HP == 0) {
				UserWin2 = 0;
				break;
			}
			if (UserWin2) {
				break;
			}
		}
		MPHP.detach();
		EnemHP2 = 0;
		tEn.join();
		if (UserWin2) {
			UserWin2 = 0;
			Ins.join();
			return 1; // Next level
		}
		else if (!UserWin2 && HP==0){ 
			CleanEnemDiscr = 0;
			Ins.join();
			UserWin2 = 1;
			return 0; // Death and Menu
		}
		else {
			CleanEnemDiscr = 0;
			Ins.join();
			UserWin2 = 1;
			return 2; // Menu
		}
	}
}