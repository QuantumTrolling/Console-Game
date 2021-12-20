#include <stdlib.h>
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "coord.h"
#include "EnemiDead.h"

using namespace std;

extern int fog[N][M];
extern int HP;
extern int enVis;

extern int curX;
extern int curY;
extern int enXgl;
extern int enYgl;
extern bool UserWin;
extern int EnemHP;

void SmartTrack(int vel) {
	while (!((HP<1) || (UserWin==1) || (EnemHP==0))) {
		Sleep(100);
		if (((abs(curX - enXgl)) * (abs(curX - enXgl)) + (abs(curY - enYgl)) * (abs(curY - enYgl))) <= enVis) {
			while (((abs(curX - enXgl)) * (abs(curX - enXgl)) + (abs(curY - enYgl)) * (abs(curY - enYgl))) <= enVis) {
				if (enXgl > curX && enYgl > curY) {
					if (fog[enYgl][enXgl] == 1 && fog[enYgl-1][enXgl-1]==1) {
						gotoxy(enXgl, enYgl);
						cout << "\x1b[32m" << (char)skEnem << "\x1b[0m";
						Sleep(vel);
						if (fog[enYgl][enXgl] != 1) {
							gotoxy(enXgl, enYgl);
							cout << (char)fogsk2;
						}
						else {
							gotoxy(enXgl, enYgl);
							cout << " ";
						}
					}
					if (fog[enYgl][enXgl] != 1 && fog[enYgl - 1][enXgl - 1] == 1) {
						gotoxy(enXgl, enYgl);
						cout << (char)fogsk2;
						Sleep(vel);
						gotoxy(enXgl, enYgl);
						cout << (char)fogsk2;
					}
					else Sleep(vel);
					enXgl--;
					enYgl--;
				}
				if (enXgl < curX && enYgl < curY) {
					if (fog[enYgl][enXgl] == 1 && fog[enYgl+1][enXgl+1] == 1) {
						gotoxy(enXgl, enYgl);
						cout << "\x1b[32m" << (char)skEnem << "\x1b[0m";
						Sleep(vel);
						if (fog[enYgl][enXgl] != 1) {
							gotoxy(enXgl, enYgl);
							cout << (char)fogsk2;
						}
						else {
							gotoxy(enXgl, enYgl);
							cout << " ";
						}
					}
					if (fog[enYgl][enXgl] != 1 && fog[enYgl + 1][enXgl + 1] == 1) {
						gotoxy(enXgl, enYgl);
						cout << (char)fogsk2;
						Sleep(vel);
						gotoxy(enXgl, enYgl);
						cout << (char)fogsk2;
					}
					else Sleep(vel);
					enXgl++;
					enYgl++;
				}
				if (enXgl > curX && enYgl < curY) {
					if (fog[enYgl][enXgl] == 1 && fog[enYgl+1][enXgl-1] == 1) {
						gotoxy(enXgl, enYgl);
						cout << "\x1b[32m" << (char)skEnem << "\x1b[0m";
						Sleep(vel);
						if (fog[enYgl][enXgl] != 1) {
							gotoxy(enXgl, enYgl);
							cout << (char)fogsk2;
						}
						else {
							gotoxy(enXgl, enYgl);
							cout << " ";
						}
					}
					if (fog[enYgl][enXgl] != 1 && fog[enYgl + 1][enXgl - 1] == 1) {
						gotoxy(enXgl, enYgl);
						cout << (char)fogsk2;
						Sleep(vel);
						gotoxy(enXgl, enYgl);
						cout << (char)fogsk2;
					}
					else Sleep(vel);
					enXgl--;
					enYgl++;
				}
				if (enXgl < curX && enYgl > curY) {
					if (fog[enYgl][enXgl] == 1 && fog[enYgl-1][enXgl + 1] == 1) {
						gotoxy(enXgl, enYgl);
						cout << "\x1b[32m" << (char)skEnem << "\x1b[0m";
						Sleep(vel);
						if (fog[enYgl][enXgl] != 1) {
							gotoxy(enXgl, enYgl);
							cout << (char)fogsk2;
						}
						else {
							gotoxy(enXgl, enYgl);
							cout << " ";
						}
					}
					if (fog[enYgl][enXgl] != 1 && fog[enYgl - 1][enXgl + 1] == 1) {
						gotoxy(enXgl, enYgl);
						cout << (char)fogsk2;
						Sleep(vel);
						gotoxy(enXgl, enYgl);
						cout << (char)fogsk2;
					}
					else Sleep(vel);
					enXgl++;
					enYgl--;
				}
				if ((enXgl == curX) && enYgl < curY) {
					if (fog[enYgl][enXgl] == 1 && fog[enYgl + 1][enXgl] == 1) {
						gotoxy(enXgl, enYgl);
						cout << "\x1b[32m" << (char)skEnem << "\x1b[0m";
						Sleep(vel);
						if (fog[enYgl][enXgl] != 1) {
							gotoxy(enXgl, enYgl);
							cout << (char)fogsk2;
						}
						else {
							gotoxy(enXgl, enYgl);
							cout << " ";
						}
					}
					if (fog[enYgl][enXgl] != 1 && fog[enYgl + 1][enXgl] == 1) {
						gotoxy(enXgl, enYgl);
						cout << (char)fogsk2;
						Sleep(vel);
						gotoxy(enXgl, enYgl);
						cout << (char)fogsk2;
					}
					else Sleep(vel);
					enYgl++;
				}
				if ((enXgl == curX) && enYgl > curY) {
					if (fog[enYgl][enXgl] == 1 && fog[enYgl - 1][enXgl] == 1) {
						gotoxy(enXgl, enYgl);
						cout << "\x1b[32m" << (char)skEnem << "\x1b[0m";
						Sleep(vel);
						if (fog[enYgl][enXgl] != 1) {
							gotoxy(enXgl, enYgl);
							cout << (char)fogsk2;
						}
						else {
							gotoxy(enXgl, enYgl);
							cout << " ";
						}gotoxy(enXgl, enYgl);
						cout << " ";
					}
					if (fog[enYgl][enXgl] != 1 && fog[enYgl - 1][enXgl] == 1) {
						gotoxy(enXgl, enYgl);
						cout << (char)fogsk2;
						Sleep(vel);
						gotoxy(enXgl, enYgl);
						cout << (char)fogsk2;
					}
					else Sleep(vel);
					enYgl--;
				}
				if ((enYgl == curY) && enXgl < curX) {
					if (fog[enYgl][enXgl] == 1 && fog[enYgl][enXgl + 1] == 1) {
						gotoxy(enXgl, enYgl);
						cout << "\x1b[32m" << (char)skEnem << "\x1b[0m";
						Sleep(vel);
						if (fog[enYgl][enXgl] != 1) {
							gotoxy(enXgl, enYgl);
							cout << (char)fogsk2;
						}
						else {
							gotoxy(enXgl, enYgl);
							cout << " ";
						}
					}
					if (fog[enYgl][enXgl] != 1 && fog[enYgl][enXgl + 1] == 1) {
						gotoxy(enXgl, enYgl);
						cout << (char)fogsk2;
						Sleep(vel);
						gotoxy(enXgl, enYgl);
						cout << (char)fogsk2;
					}
					else Sleep(vel);
					enXgl++;
				}
				if ((enYgl == curY) && enXgl > curX) {
					if (fog[enYgl][enXgl] == 1 && fog[enYgl][enXgl - 1] == 1) {
						gotoxy(enXgl, enYgl);
						cout << "\x1b[32m" << (char)skEnem << "\x1b[0m";
						Sleep(vel);
						if (fog[enYgl][enXgl] != 1) {
							gotoxy(enXgl, enYgl);
							cout << (char)fogsk2;
						}
						else {
							gotoxy(enXgl, enYgl);
							cout << " ";
						}
					}
					if (fog[enYgl][enXgl] != 1 && fog[enYgl][enXgl - 1] == 1) {
						gotoxy(enXgl, enYgl);
						cout << (char)fogsk2;
						Sleep(vel);
						gotoxy(enXgl, enYgl);
						cout << (char)fogsk2;
					}
					else Sleep(vel);
					enXgl--;
				}
				if (((enXgl == curX) && (enYgl == curY))) { HP--; EnemHP--; }
				if (HP < 1 || UserWin == 1 || EnemHP == 0)
					break;
			}
			if (fog[enYgl][enXgl] == 1) {
				gotoxy(enXgl, enYgl);
				cout << "\x1b[32m" << (char)skEnem << "\x1b[0m";
			}
			if (EnemHP == 0 && fog[enYgl][enXgl]==1)
				EnemiDead(enXgl, enYgl);
			else if ((UserWin == 1 || HP < 1) && fog[enYgl][enXgl]==1) {
				gotoxy(enXgl, enYgl);
				cout << " ";
			}
		}
	}
}


// Not used
void NotSmartTrack(int vel) {
	Sleep(100);
	gotoxy(enXgl, enYgl);
	cout << (char)skEnem;
	while (!(enXgl == curX && enYgl == curY)) {
		if (enXgl > curX && enYgl > curY) {
			gotoxy(enXgl, enYgl);
			cout << (char)skEnem;
			Sleep(vel);
			gotoxy(enXgl, enYgl);
			cout << " ";
			enXgl--;
			enYgl--;
		}
		if (enXgl < curX && enYgl < curY) {
			gotoxy(enXgl, enYgl);
			cout << (char)skEnem;
			Sleep(vel);
			gotoxy(enXgl, enYgl);
			cout << " ";
			enXgl++;
			enYgl++;
		}
		if (enXgl > curX && enYgl < curY) {
			gotoxy(enXgl, enYgl);
			cout << (char)skEnem;
			Sleep(vel);
			gotoxy(enXgl, enYgl);
			cout << " ";
			enXgl--;
			enYgl++;
		}
		if (enXgl < curX && enYgl > curY) {
			gotoxy(enXgl, enYgl);
			cout << (char)skEnem;
			Sleep(vel);
			gotoxy(enXgl, enYgl);
			cout << " ";
			enXgl++;
			enYgl--;
		}
		if ((enXgl == curX) && enYgl < curY) {
			gotoxy(enXgl, enYgl);
			cout << (char)skEnem;
			Sleep(vel);
			gotoxy(enXgl, enYgl);
			cout << " ";
			enYgl++;
		}
		if ((enXgl == curX) && enYgl > curY) {
			gotoxy(enXgl, enYgl);
			cout << (char)skEnem;
			Sleep(vel);
			gotoxy(enXgl, enYgl);
			cout << " ";
			enYgl--;
		}
		if ((enYgl == curY) && enXgl < curX) {
			gotoxy(enXgl, enYgl);
			cout << (char)skEnem;
			Sleep(vel);
			gotoxy(enXgl, enYgl);
			cout << " ";
			enXgl++;
		}
		if ((enYgl == curY) && enXgl > curX) {
			gotoxy(enXgl, enYgl);
			cout << (char)skEnem;
			Sleep(vel);
			gotoxy(enXgl, enYgl);
			cout << " ";
			enXgl--;
		}
	}

}