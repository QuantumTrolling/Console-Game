#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <stdlib.h>
#include "coord.h"

using namespace std;

void YouDead()
{
	gotoxy(startX, startY);
	cout << "YOU DEAD" << endl;
	Sleep(2000);
	system("cls");
}