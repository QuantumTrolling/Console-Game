#include <stdlib.h>
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "coord.h"

using namespace std;

extern int HP;
extern int MP;
extern int chHP;
extern int chMP;

extern int Score;
extern int chScore;

void MPHPcheck() {
	while (HP>=0){
		Sleep(33);
		if (chScore != Score) {
			Sleep(50);
			gotoxy(111, 28);
			cout << " ";
			gotoxy(111, 28);
			cout << Score;
			chScore = Score;
		}

		if (HP == 0) {
			if (chHP != HP) {
				gotoxy(106, 1);
				cout << "            ";
			}
			break;
		}
		else {
			if (chHP != HP) {
				int cnt1 = HP;
				gotoxy(106, 1);
				cout << "             ";
				gotoxy(107, 1);
				while (cnt1 > 0) {
					cout << "\x1b[31m" << (char)skHP << "\x1b[0m" << " ";
					cnt1--;
				}
				chHP = HP;
			}
			if (chMP != MP) {
				gotoxy(106, 2);
				int cnt2 = MP;
				cout << "             ";
				gotoxy(107, 2);
				while (cnt2 > 0) {
					cout << "\x1b[36m" << (char)skMP << "\x1b[0m" << " ";
					cnt2--;
				}
				chMP = MP;
			}
		}

	}
}