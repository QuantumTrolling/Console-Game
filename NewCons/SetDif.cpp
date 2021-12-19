#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "coord.h"

using namespace std;

void dif(int switcher)
{
	switch (switcher)
	{
	case 1:
		gotoxy(startX - 7, startY - 8);
		cout << "           ";
		gotoxy(startX - 7, startY - 7);
		cout << "            ";
		gotoxy(startX - 7, startY - 6);
		cout << "            ";
		gotoxy(startX - 7, startY - 8);
		cout << ">> EASY";
		gotoxy(startX - 5, startY - 7);
		cout << "NORMAL";
		gotoxy(startX - 5, startY - 6);
		cout << "HARD";
		break;
	case 2:
		gotoxy(startX - 7, startY - 8);
		cout << "           ";
		gotoxy(startX - 7, startY - 7);
		cout << "            ";
		gotoxy(startX - 7 , startY - 6);
		cout << "            ";
		gotoxy(startX - 5, startY - 8);
		cout << "EASY";
		gotoxy(startX - 7, startY - 7);
		cout << ">> NORMAL";
		gotoxy(startX - 5, startY - 6);
		cout << "HARD";
		break;
	case 3:
		gotoxy(startX - 7, startY - 8);
		cout << "           ";
		gotoxy(startX - 7, startY - 7);
		cout << "            ";
		gotoxy(startX - 7, startY - 6);
		cout << "            ";
		gotoxy(startX  - 5, startY - 8);
		cout << "EASY";
		gotoxy(startX - 5, startY - 7);
		cout << "NORMAL";
		gotoxy(startX  - 7, startY - 6);
		cout << ">> HARD";
		break;
	}
}