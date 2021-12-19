#include <stdlib.h>
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "coord.h"

using namespace std;

void Attack(int x, int y, int n) {

int cnt = 0; // rander distance

while (cnt != n) {
	for (int i = y - cnt - 1; i <= y + cnt + 1; i++)
		for (int j = x - cnt - 1; j <= x + cnt + 1; j++) {
			if ((i == (y - cnt - 1)) || (i == (y + cnt + 1))) {
				gotoxy(j, i);
				cout << "\x1b[34m" << (char)skAttack << "\x1b[0m";
			}
			else  if ((j == (x - cnt - 1)) || (j == (x + cnt + 1))) {
				gotoxy(j, i);
				cout << "\x1b[34m" << (char)skAttack << "\x1b[0m";
			}
		}
	Sleep(190);
	for (int i = y - cnt - 1; i <= y + cnt + 1; i++)
		for (int j = x - cnt - 1; j <= x + cnt + 1; j++) {
			if ((i == (y - cnt - 1)) || (i == (y + cnt + 1))) {
				gotoxy(j, i);
				cout << " ";
			}
			else  if ((j == (x - cnt - 1)) || (j == (x + cnt + 1))) {
				gotoxy(j, i);
				cout << " ";
			}
		}
	cnt++;
}
}