#include <stdlib.h>
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "coord.h"

using namespace std;

void EnemiDead(int x, int y) {
	gotoxy(x, y);
	cout << " ";
	Sleep(100);
	gotoxy(x, y);
	cout << "\x1b[32m" << (char)skEnem << "\x1b[0m";
	Sleep(100);
	gotoxy(x, y);
	cout << " ";
	Sleep(100);
	gotoxy(x, y);
	cout << "\x1b[32m" << (char)skEnem << "\x1b[0m";
	Sleep(100);
	gotoxy(x, y);
	cout << " ";

}