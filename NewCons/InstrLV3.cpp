#include <stdlib.h>
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <thread>
#include "coord.h"

using namespace std;

void InstrLV3() {
	Sleep(200);

	gotoxy(103, 4);
	cout << "There you can";
	gotoxy(103, 5);
	cout << "see fog of war.";
	Sleep(900);
	gotoxy(103, 7);
	cout << "Try to explore";
	Sleep(200);
	gotoxy(103, 8);
	cout << "this area and";
	Sleep(200);
	gotoxy(103, 9);
	cout << "find some items.";
	Sleep(900);
	gotoxy(103, 11);
	cout << "But remember not";
	Sleep(200);
	gotoxy(103, 12);
	cout << "all of them have";
	Sleep(200);
	gotoxy(103, 13);
	cout << "positive effects.";
	Sleep(900);
	gotoxy(103, 15);
	cout << "Also there can";
	Sleep(200);
	gotoxy(103, 16);
	cout << "be enemies here";
}