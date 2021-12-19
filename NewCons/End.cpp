#include <stdlib.h>
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "coord.h"

using namespace std;

extern int Score;

void EndOfGame() {

	system("cls");
	gotoxy(startX, startY - 6);
	cout << "Score: " << Score;
	Sleep(600);
	gotoxy(startX - 3, startY - 4);
	cout << "Now that's all.";
	Sleep(600);
	gotoxy(startX - 6, startY - 2);
	cout << "Thank you for playing!";
	Sleep(5000);
	system("cls");

}