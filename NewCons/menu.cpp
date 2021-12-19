#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "coord.h"

using namespace std;

void Menu(int switcher)
{
	switch (switcher)
	{
	case 1:
		gotoxy(startX - 1, startY - 4);
		cout << "<< PLAY! >>";
		gotoxy(startX+1, startY - 2);
		cout << "Settings";
		gotoxy(startX + 1, startY);
		cout << "Creator";
		gotoxy(startX + 2, startY + 2);
		cout << "EXIT";
		break;
	case 2:
		gotoxy(startX+2, startY - 4);
		cout << "PLAY!";
		gotoxy(startX - 2, startY - 2);
		cout << "<< Settings >>";
		gotoxy(startX+1, startY );
		cout << "Creator";
		gotoxy(startX + 2, startY + 2);
		cout << "EXIT";
		break;
	case 3:
		gotoxy(startX+2, startY - 4);
		cout << "PLAY!";
		gotoxy(startX+1, startY - 2);
		cout << "Settings";
		gotoxy(startX - 2, startY);
		cout << "<< Creator >>";
		gotoxy(startX + 2, startY + 2);
		cout << "EXIT";
		break;
	case 4:
		gotoxy(startX + 2, startY - 4);
		cout << "PLAY!";
		gotoxy(startX + 1, startY - 2);
		cout << "Settings";
		gotoxy(startX + 1, startY);
		cout << "Creator";
		gotoxy(startX - 1, startY + 2);
		cout << "<< EXIT >>";
		break;

	}
}