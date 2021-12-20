#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <stdlib.h>
#include "coord.h"
#include "menu.h"
#include "LV1.h"
#include "LV2.h"
#include "LV3.h"
#include "GameOver.h"
#include "Settings.h"
#include "End.h"
#include "CreatorInfo.h"

using namespace std;

int main()
{
	// hide cursore
	CONSOLE_CURSOR_INFO curs = { 0 };
	curs.dwSize = sizeof(curs);
	curs.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curs);

	Menu(1);

	int choicen = 0;
	int st = 1;

	while (choicen != 27) {
		Sleep(50);
		choicen = _getch();
		if (choicen == 0 || choicen == 224) {
			switch (_getch()) {
			case 72: // code for arrow up
				if (st == 1) {
					system("cls");
					Menu(4);
					st = 4;
				}
				else if (st > 1) {
					system("cls");
					Menu(st - 1);
					st--;
				}
				else break;
				break;
			case 80: // code for arrow down
				if (st == 4) {
					system("cls");
					Menu(1);
					st = 1;
				}
				else if (st < 4) {
					system("cls");
					Menu(st + 1);
					st++;
				}
				else break;
				break;
			}
		}

		if (st == 1 && choicen == 13) { // start of levels
			system("cls");
			if (LV1() == 1) {
				switch (LV2())
				{
				case 0:
					YouDead();
					Menu(1);
					break;
				case 1:
					switch (LV3())
					{
					case 0:
						YouDead();
						Menu(1);
						break;
					case 1:
						EndOfGame();
						Menu(1);
						break;
					case 2:
						system("cls");
						Menu(1);
						break;
					}
					break;
				case 2:
					system("cls");
					Menu(1);
					break;
				}
			}
		}
		if (st == 2 && choicen == 13) { // settings
			system("cls");
			Settings();
			Menu(2);
		}
		if (st == 3 && choicen == 13) { // information about creator
			Info();
			Menu(3);
		}
		if (st == 4 && choicen == 13) // exit
			break;

	}

}