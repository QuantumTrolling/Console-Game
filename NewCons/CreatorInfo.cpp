#include <stdlib.h>
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "coord.h"

using namespace std;

void Info() {
	system("cls");
	gotoxy(startX - 26, startY - 10);
	cout << "Hi, i'm just a student from SPBU and i made this game as part of a ";
	gotoxy(startX - 26, startY - 9);
	cout << "project on the subject of 'fundamentals of programming'.";
	gotoxy(startX - 26, startY - 7);
	cout << "My contacts if someone need it:";
	gotoxy(startX - 26, startY - 5);
	cout << "Gmail: thinter157@gmail.com";
	gotoxy(startX - 26, startY - 4);
	cout << "GitHub: QuantumTrolling";
	int ch = _getch();
	while ((ch != 27) && (ch != 13)) {
		ch = _getch();
	}
	system("cls");

}