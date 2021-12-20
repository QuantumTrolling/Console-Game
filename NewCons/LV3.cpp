#include <stdlib.h>
#include <iostream>
#include <Windows.h>
#include <fstream>
#include <conio.h>
#include <thread>
#include <string>
#include "coord.h"
#include "EnemiDead.h"
#include "Attack.h"
#include "enemTracks.h"
#include "HPMPcnt.h"
#include "InstrLV3.h"

using namespace std;

int fog[N][M]; // Fog of War

extern int HP;
extern int MP;
extern int chHP;
extern int chMP;

extern int vel; // enemy velocity(for 'SmartTrack')

extern int EnemHP;

extern int curX;
extern int curY;
extern int enXgl;
extern int enYgl;

extern int Score;
extern int chScore;

bool UserWin = 0;
extern int vis; // Player vision (min: 5, max: 7}

int LV3() {

	curX = startX;
	curY = startY;
	enXgl = 20;
	enYgl = 10;

	EnemHP = 1;

	int cntEn = 1;
	bool CleanEnemDiscr = 1;
	bool UserWin = 0;

	system("cls");
	gotoxy(startX + 2, startY - 2);
	cout << "LEVEL 3";
	gotoxy(startX - 4, startY + 3);
	cout << "Press Enter to start...";
	Sleep(2000);
	int start3 = _getch();

	if (start3 == 13 || start3 == 0 || start3==224) {
		system("cls");
		// Fog of war output
		string s;
		ifstream file("FogofWar.txt");
		for (int i = 0; i < N; i++) {
			getline(file, s);
			for (int j = 0; j < M; j++) {
				fog[i][j] = s[j] - '0';
			}
		}
		file.close();

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++)
				if (fog[i][j] == 0 || fog[i][j]==4 || fog[i][j]==5 || fog[i][j] == 6 || fog[i][j] == 7)
					cout << (char)fogsk;
				else if (fog[i][j] == 1)
					cout << " ";
			cout << "\n";
		}

		int n = 0;
		while (n < vis + 1) { // start visible area
			for (int i = curY - vis + n; i < curY - vis + 1 + n; i++) {
				for (int j = curX - n; j < curX + n + 1; j++) {
					gotoxy(j, i);
					cout << " ";
					fog[i][j] = 1;
				}
			}
			for (int i = curY + 1 + n; i < curY + 2 + n; i++) {
				for (int j = curX - vis + 1 + n; j < curX + vis - n; j++) {
					gotoxy(j, i);
					cout << " ";
					fog[i][j] = 1;
				}
			}
			n++;
		}
		// bordes
		{
			for (int i = 1; i < 102; i++)
				for (int j = 0; j < 1; j++) {
					gotoxy(i, j);
					cout << (char)205;
				}
			for (int i = 1; i < 102; i++)
				for (int j = 29; j < 30; j++) {
					gotoxy(i, j);
					cout << (char)205;
				}
			for (int i = 0; i < 1; i++)
				for (int j = 1; j < 29; j++) {
					gotoxy(i, j);
					cout << (char)186;
				}
			for (int i = 102; i < 103; i++)
				for (int j = 1; j < 29; j++) {
					gotoxy(i, j);
					cout << (char)186;
				}
			gotoxy(0, 0);
			cout << (char)201;
			gotoxy(102, 0);
			cout << (char)187;
			gotoxy(0, 29);
			cout << (char)200;
			gotoxy(102, 29);
			cout << (char)188;
			gotoxy(51, 14);
		}

		gotoxy(104, 1);
		int cnt1 = HP;
		cout << "HP ";
		while (cnt1 > 0) {
			cout << "\x1b[31m" << (char)skHP << "\x1b[0m" << " ";
			cnt1--;
		}

		gotoxy(104, 2);
		int cnt2 = MP;
		cout << "MP ";
		while (cnt2 > 0) {
			cout << "\x1b[36m" << (char)skMP << "\x1b[0m" << " ";
			cnt2--;
		}

		gotoxy(104, 28);
		cout << "Score: " << Score;

		gotoxy(curX, curY);
		cout << (char)skin;

		int cnt = 0;

		thread tInst(InstrLV3); // Thread of instruction
		thread Ent(SmartTrack, vel); // enemy track

		int fl = 0;
		while (fl != 27 ) {
			Sleep(60);
			n = 0;
			if (HP < 1) {
				UserWin = 0;
				break;
			}
			fl = _getch();
			if (fl == 0 || fl == 224) {
				switch (_getch()) {
				case 72: // code for arrow up
					if (curY != 1 ) {
						gotoxy(curX, curY);
						curY -= 1;
						while (n < vis + 1) {
							for (int i = curY - vis + n; i < curY - vis + 1 + n; i++) {
								for (int j = curX - n; j < curX + n + 1; j++) {
									if (fog[i][j]!=3 && i>0 && j>0) {
										if (fog[i][j] == 4){
											gotoxy(j, i);
											cout << "\x1b[31m" << (char)skHP << "\x1b[0m";
										}
										else if (fog[i][j] == 5) {
											gotoxy(j, i);
											cout << "\x1b[36m" << (char)skMP << "\x1b[0m";
										}
										else if (fog[i][j] == 6) {
											gotoxy(j, i);
											cout << "\x1b[35m" << (char)skSpik << "\x1b[0m";
										}
										else if (fog[i][j] == 7) {
											gotoxy(j, i);
											cout << (char)EndofGame;
										}
										else {
											gotoxy(j, i);
											cout << " ";
											fog[i][j] = 1;
										}
									}
								}
							}
							for (int i = curY + 1 + n; i < curY + 2 + n; i++) {
								for (int j = curX - vis + 1 + n; j < curX + vis - n; j++) {
									if (fog[i][j] != 3 && i>0 && j>0) {
										if (fog[i][j] == 4) {
											gotoxy(j, i);
											cout << "\x1b[31m" << (char)skHP << "\x1b[0m";
										}
										else if (fog[i][j] == 5) {
											gotoxy(j, i);
											cout << "\x1b[36m" << (char)skMP << "\x1b[0m";
										}
										else if (fog[i][j] == 6) {
											gotoxy(j, i);
											cout << "\x1b[35m" << (char)skSpik << "\x1b[0m";
										}
										else if (fog[i][j] == 7) {
											gotoxy(j, i);
											cout << (char)EndofGame;
										}
										else {
											gotoxy(j, i);
											cout << " ";
											fog[i][j] = 1;
										}
									}
								}
							}

							n++;
						}
						cnt = vis;
						while (cnt >= 0) {
							if (fog[curY - cnt + vis + 1][curX - cnt] != 3 && (curY - cnt + vis + 1)>0 && (curX - cnt)>0 && fog[curY - cnt + vis + 1][curX - cnt] != 2) {
								if (fog[curY - cnt + vis + 1][curX - cnt] == 4) {
									gotoxy(curX - cnt, curY - cnt + vis + 1);
									cout << "\x1b[31m" << (char)skHP << "\x1b[0m";
								}
								else if (fog[curY - cnt + vis + 1][curX - cnt] == 5) {
									gotoxy(curX - cnt, curY - cnt + vis + 1);
									cout << "\x1b[36m" << (char)skMP << "\x1b[0m";
								}
								else if (fog[curY - cnt + vis + 1][curX - cnt] == 6) {
									gotoxy(curX - cnt, curY - cnt + vis + 1);
									cout << "\x1b[35m" << (char)skSpik << "\x1b[0m";
								}
								else if (fog[curY - cnt + vis + 1][curX - cnt] == 7) {
									gotoxy(curX - cnt, curY - cnt + vis + 1);
									cout << (char)EndofGame;
								}
								else {
									gotoxy(curX - cnt, curY - cnt + vis + 1);
									cout << (char)fogsk2;
									fog[curY - cnt + vis + 1][curX - cnt] = 2;
								}
							}
							if (fog[curY + cnt + 1][curX - cnt + vis] != 3 && (curY + cnt + 1)>0 && (curX - cnt + vis)>0 && fog[curY + cnt + 1][curX - cnt + vis] != 2) {
								if (fog[curY + cnt + 1][curX - cnt + vis] == 4) {
									gotoxy(curX - cnt + vis, curY + cnt + 1);
									cout << "\x1b[31m" << (char)skHP << "\x1b[0m";
								}
								else if (fog[curY + cnt + 1][curX - cnt + vis] == 5) {
									gotoxy(curX - cnt + vis, curY + cnt + 1);
									cout << "\x1b[36m" << (char)skMP << "\x1b[0m";
								}
								else if (fog[curY + cnt + 1][curX - cnt + vis] == 6) {
									gotoxy(curX - cnt + vis, curY + cnt + 1);
									cout << "\x1b[35m" << (char)skSpik << "\x1b[0m";
								}
								else if (fog[curY + cnt + 1][curX - cnt + vis] == 7) {
									gotoxy(curX - cnt + vis, curY + cnt + 1);
									cout <<  (char)EndofGame;
								}
								else {
									gotoxy(curX - cnt + vis, curY + cnt + 1);
									cout << (char)fogsk2;
									fog[curY + cnt + 1][curX - cnt + vis] = 2;
								}
							}
							cnt--;
						}
						gotoxy(curX, curY);
						cout << (char)skin;
					}
					else break;
					break;
				case 80: // code for arrow down
					if (curY < 28 ) {
						gotoxy(curX, curY);
						curY += 1;
						while (n < vis + 1) {
							for (int i = curY - vis + n; i < curY - vis + 1 + n; i++) {
								for (int j = curX - n; j < curX + n + 1; j++) {
									if (fog[i][j] != 3 && i>0 && j>0) {
										if (fog[i][j] == 4) {
											gotoxy(j, i);
											cout << "\x1b[31m" << (char)skHP << "\x1b[0m";
										}
										else if (fog[i][j] == 5) {
											gotoxy(j, i);
											cout << "\x1b[36m" << (char)skMP << "\x1b[0m";
										}
										else if (fog[i][j] == 6) {
											gotoxy(j, i);
											cout << "\x1b[35m" << (char)skSpik << "\x1b[0m";
										}
										else if (fog[i][j] == 7) {
											gotoxy(j, i);
											cout << (char)EndofGame;
										}
										else {
											gotoxy(j, i);
											cout << " ";
											fog[i][j] = 1;
										}
									}
								}
							}
							for (int i = curY + 1 + n; i < curY + 2 + n; i++) {
								for (int j = curX - vis + 1 + n; j < curX + vis - n; j++) {
									if (fog[i][j] != 3 && i>0 && j>0) {
										if (fog[i][j] == 4) {
											gotoxy(j, i);
											cout << "\x1b[31m" << (char)skHP << "\x1b[0m";
										}
										else if (fog[i][j] == 5) {
											gotoxy(j, i);
											cout << "\x1b[36m" << (char)skMP << "\x1b[0m";
										}
										else if (fog[i][j] == 6) {
											gotoxy(j, i);
											cout << "\x1b[35m" << (char)skSpik << "\x1b[0m";
										}
										else if (fog[i][j] == 7) {
											gotoxy(j, i);
											cout << (char)EndofGame;
										}
										else {
											gotoxy(j, i);
											cout << " ";
											fog[i][j] = 1;
										}
									}
								}
							}

							n++;
						}
						cnt = vis;
						while (cnt >= 0) {
							if (fog[curY + cnt - vis - 1][curX - cnt] != 3 && (curY + cnt - vis - 1)>0 && (curX - cnt)>0 && fog[curY + cnt - vis - 1][curX - cnt] != 2) {
								if (fog[curY + cnt - vis - 1][curX - cnt] == 4) {
									gotoxy(curX - cnt, curY + cnt - vis - 1);
									cout << "\x1b[31m" << (char)skHP << "\x1b[0m";
								}
								else if (fog[curY + cnt - vis - 1][curX - cnt] == 5) {
									gotoxy(curX - cnt, curY + cnt - vis - 1);
									cout << "\x1b[36m" << (char)skMP << "\x1b[0m";
								}
								else if (fog[curY + cnt - vis - 1][curX - cnt] == 6) {
									gotoxy(curX - cnt, curY + cnt - vis - 1);
									cout << "\x1b[35m" << (char)skSpik << "\x1b[0m";
								}
								else if (fog[curY + cnt - vis - 1][curX - cnt] == 7) {
									gotoxy(curX - cnt, curY + cnt - vis - 1);
									cout << (char)EndofGame;
								}
								else {
									gotoxy(curX - cnt, curY + cnt - vis - 1);
									fog[curY + cnt - vis - 1][curX - cnt] = 2;
									cout << (char)fogsk2;
								}
							}
							if (fog[curY - cnt - 1][curX - cnt + vis] != 3 && (curY - cnt - 1)>0 && (curX - cnt + vis)>0 && fog[curY - cnt - 1][curX - cnt + vis] != 2) {
								if (fog[curY - cnt - 1][curX - cnt + vis] == 4) {
									gotoxy(curX - cnt + vis, curY - cnt - 1);
									cout << "\x1b[31m" << (char)skHP << "\x1b[0m";
								}
								else if (fog[curY - cnt - 1][curX - cnt + vis] == 5) {
									gotoxy(curX - cnt + vis, curY - cnt - 1);
									cout << "\x1b[36m" << (char)skMP << "\x1b[0m";
								}
								else if (fog[curY - cnt - 1][curX - cnt + vis] == 6) {
									gotoxy(curX - cnt + vis, curY - cnt - 1);
									cout << "\x1b[35m" << (char)skSpik << "\x1b[0m";
								}
								else if (fog[curY - cnt - 1][curX - cnt + vis] == 7) {
									gotoxy(curX - cnt + vis, curY - cnt - 1);
									cout << (char)EndofGame;
								}
								else {
									gotoxy(curX - cnt + vis, curY - cnt - 1);
									fog[curY - cnt - 1][curX - cnt + vis] = 2;
									cout << (char)fogsk2;
								}
							}
							cnt--;
						}

						gotoxy(curX, curY);
						cout << (char)skin;
					}
					else break;
					break;
				case 77: // code for arrow right
					if (curX < 101) {
						gotoxy(curX, curY);
						curX += 1;
						while (n < vis + 1) {
							for (int i = curY - vis + n; i < curY - vis + 1 + n; i++) {
								for (int j = curX - n; j < curX + n + 1; j++) {
									if (fog[i][j] != 3 && i>0 && j>0) {
										if (fog[i][j] == 4) {
											gotoxy(j, i);
											cout << "\x1b[31m" << (char)skHP << "\x1b[0m";
										}
										else if (fog[i][j] == 5) {
											gotoxy(j, i);
											cout << "\x1b[36m" << (char)skMP << "\x1b[0m";
										}
										else if (fog[i][j] == 6) {
											gotoxy(j, i);
											cout << "\x1b[35m" << (char)skSpik << "\x1b[0m";
										}
										else if (fog[i][j] == 7) {
											gotoxy(j, i);
											cout << (char)EndofGame;
										}
										else {
											gotoxy(j, i);
											cout << " ";
											fog[i][j] = 1;
										}
									}
								}
							}
							for (int i = curY + 1 + n; i < curY + 2 + n; i++) {
								for (int j = curX - vis + 1 + n; j < curX + vis - n; j++) {
									if (fog[i][j] != 3 && i>0 && j>0) {
										if (fog[i][j] == 4) {
											gotoxy(j, i);
											cout << "\x1b[31m" << (char)skHP << "\x1b[0m";
										}
										else if (fog[i][j] == 5) {
											gotoxy(j, i);
											cout << "\x1b[36m" << (char)skMP << "\x1b[0m";
										}
										else if (fog[i][j] == 6) {
											gotoxy(j, i);
											cout << "\x1b[35m" << (char)skSpik << "\x1b[0m";
										}
										else if (fog[i][j] == 7) {
											gotoxy(j, i);
											cout << (char)EndofGame;
										}
										else {
											gotoxy(j, i);
											cout << " ";
											fog[i][j] = 1;
										}
									}
								}
							}

							n++;
						}
						cnt = vis;
						while (cnt >= 0) {
							if (fog[curY - cnt][curX + cnt - vis - 1] != 3 && (curY - cnt)>0 && (curX + cnt - vis - 1)>0 && fog[curY - cnt][curX + cnt - vis - 1] != 2) {
								if (fog[curY - cnt][curX + cnt - vis - 1] == 4) {
									gotoxy(curX + cnt - vis - 1, curY - cnt);
									cout << "\x1b[31m" << (char)skHP << "\x1b[0m";
								}
								else if (fog[curY - cnt][curX + cnt - vis - 1] == 5) {
									gotoxy(curX + cnt - vis - 1, curY - cnt);
									cout << "\x1b[36m" << (char)skMP << "\x1b[0m";
								}
								else if (fog[curY - cnt][curX + cnt - vis - 1] == 6) {
									gotoxy(curX + cnt - vis - 1, curY - cnt);
									cout << "\x1b[35m" << (char)skSpik << "\x1b[0m";
								}
								else if (fog[curY - cnt][curX + cnt - vis - 1] == 7) {
									gotoxy(curX + cnt - vis - 1, curY - cnt);
									cout << (char)EndofGame;
								}
								else {
									gotoxy(curX + cnt - vis - 1, curY - cnt);
									fog[curY - cnt][curX + cnt - vis - 1] = 2;
									cout << (char)fogsk2;
								}
							}
							if (fog[curY - cnt + vis][curX - cnt - 1] != 3 && (curY - cnt + vis)>0 && (curX - cnt - 1)>0 && fog[curY - cnt + vis][curX - cnt - 1] != 2) {
								if (fog[curY - cnt + vis][curX - cnt - 1] == 4) {
									gotoxy(curX - cnt - 1, curY - cnt + vis);
									cout << "\x1b[31m" << (char)skHP << "\x1b[0m";
								}
								else if (fog[curY - cnt + vis][curX - cnt - 1] == 5) {
									gotoxy(curX - cnt - 1, curY - cnt + vis);
									cout << "\x1b[36m" << (char)skMP << "\x1b[0m";
								}
								else if (fog[curY - cnt + vis][curX - cnt - 1] == 6) {
									gotoxy(curX - cnt - 1, curY - cnt + vis);
									cout << "\x1b[35m" << (char)skSpik << "\x1b[0m";
								}
								else if (fog[curY - cnt + vis][curX - cnt - 1] == 7) {
									gotoxy(curX - cnt - 1, curY - cnt + vis);
									cout << (char)EndofGame;
								}
								else {
									gotoxy(curX - cnt - 1, curY - cnt + vis);
									fog[curY - cnt + vis][curX - cnt - 1] = 2;
									cout << (char)fogsk2;
								}
							}
							cnt--;
						}
						gotoxy(curX, curY);
						cout << (char)skin;
					}
					else break;
					break;
				case 75: // code for arrow left
					if (curX != 1 ) {
						gotoxy(curX, curY);
						curX -= 1;
						while (n < vis + 1) {
							for (int i = curY - vis + n; i < curY - vis + 1 + n; i++) {
								for (int j = curX - n; j < curX + n + 1; j++) {
									if (fog[i][j] != 3 && i>0 && j>0) {
										if (fog[i][j] == 4) {
											gotoxy(j, i);
											cout << "\x1b[31m" << (char)skHP << "\x1b[0m";
										}
										else if (fog[i][j] == 5) {
											gotoxy(j, i);
											cout << "\x1b[36m" << (char)skMP << "\x1b[0m";
										}
										else if (fog[i][j] == 6) {
											gotoxy(j, i);
											cout << "\x1b[35m" << (char)skSpik << "\x1b[0m";
										}
										else if (fog[i][j] == 7) {
											gotoxy(j, i);
											cout << (char)EndofGame;
										}
										else {
											gotoxy(j, i);
											cout << " ";
											fog[i][j] = 1;
										}
									}
								}
							}
							for (int i = curY + 1 + n; i < curY + 2 + n; i++) {
								for (int j = curX - vis + 1 + n; j < curX + vis - n; j++) {
									if (fog[i][j] != 3 && i>0 && j>0) {
										if (fog[i][j] == 4) {
											gotoxy(j, i);
											cout << "\x1b[31m" << (char)skHP << "\x1b[0m";
										}
										else if (fog[i][j] == 5) {
											gotoxy(j, i);
											cout << "\x1b[36m" << (char)skMP << "\x1b[0m";
										}
										else if (fog[i][j] == 6) {
											gotoxy(j, i);
											cout << "\x1b[35m" << (char)skSpik << "\x1b[0m";
										}
										else if (fog[i][j] == 7) {
											gotoxy(j, i);
											cout << (char)EndofGame;
										}
										else {
											gotoxy(j, i);
											cout << " ";
											fog[i][j] = 1;
										}
									}
								}
							}

							n++;
						}
						cnt = vis;
						while (cnt >= 0) {
							if (fog[curY - cnt][curX - cnt + vis + 1] != 3 && (curY - cnt)>0 && (curX - cnt + vis + 1)>0 && fog[curY - cnt][curX - cnt + vis + 1] != 2) {
								if (fog[curY - cnt][curX - cnt + vis + 1] == 4) {
									gotoxy(curX - cnt + vis + 1, curY - cnt);
									cout << "\x1b[31m" << (char)skHP << "\x1b[0m";
								}
								else if (fog[curY - cnt][curX - cnt + vis + 1] == 5) {
									gotoxy(curX - cnt + vis + 1, curY - cnt);
									cout << "\x1b[36m" << (char)skMP << "\x1b[0m";
								}
								else if (fog[curY - cnt][curX - cnt + vis + 1] == 6) {
									gotoxy(curX - cnt + vis + 1, curY - cnt);
									cout << "\x1b[35m" << (char)skSpik << "\x1b[0m";
								}
								else if (fog[curY - cnt][curX - cnt + vis + 1] == 7) {
									gotoxy(curX - cnt + vis + 1, curY - cnt);
									cout << (char)EndofGame;
								}
								else {
									gotoxy(curX - cnt + vis + 1, curY - cnt);
									fog[curY - cnt][curX - cnt + vis + 1] = 2;
									cout << (char)fogsk2;
								}
							}
							if (fog[curY - cnt + vis][curX + cnt + 1] != 3 && (curY - cnt + vis)>0 && (curX + cnt + 1)>0 && fog[curY - cnt + vis][curX + cnt + 1] != 2) {
								if (fog[curY - cnt + vis][curX + cnt + 1] == 4) {
									gotoxy(curX + cnt + 1, curY - cnt + vis);
									cout << "\x1b[31m" << (char)skHP << "\x1b[0m";
								}
								else if (fog[curY - cnt + vis][curX + cnt + 1] == 5) {
									gotoxy(curX + cnt + 1, curY - cnt + vis);
									cout << "\x1b[36m" << (char)skMP << "\x1b[0m";
								}
								else if (fog[curY - cnt + vis][curX + cnt + 1] == 6) {
									gotoxy(curX + cnt + 1, curY - cnt + vis);
									cout << "\x1b[35m" << (char)skSpik << "\x1b[0m";
								}
								else if (fog[curY - cnt + vis][curX + cnt + 1] == 7) {
									gotoxy(curX + cnt + 1, curY - cnt + vis);
									cout << (char)EndofGame;
								}
								else {
									gotoxy(curX + cnt + 1, curY - cnt + vis);
									fog[curY - cnt + vis][curX + cnt + 1] = 2;
									cout << (char)fogsk2;
								}
							}
							cnt--;
						}

						gotoxy(curX, curY);
						cout << (char)skin;
					}
					else break;
					break;

				}
			}
			if (fog[curY][curX] == 4) { // get MP
				HP++;
				Score++;
				fog[curY][curX] = 1;
			}
			if (fog[curY][curX] == 5) { // get HP
				MP++;
				Score++;
				fog[curY][curX] = 1;
			}
			if (fog[curY][curX] == 6) { // get Spik(-1HP, -1MP)
				if (MP > 0) MP--;
				HP--;
				fog[curY][curX] = 1;
			}
			if (fog[curY][curX] == 7) { // get 'end of game'
				fog[curY][curX] = 1;
				UserWin = 1;
				break;
			}

			if (fl == 97 && MP > 0) { // Attack and enemy death
				Attack(curX, curY, 2);
				MP--;
				if (((abs(curX - enXgl)) * (abs(curX - enXgl)) + (abs(curY - enYgl)) * (abs(curY - enYgl))) <= 49) {
					EnemHP--;
					Score += 3;
				}

			}
			// end of game
			if (HP < 1) {
				UserWin = 0;
				break;
			}
		}

		ofstream fileout("FogReturn.txt");
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				fileout << fog[i][j];
			}
			fileout << "\n";
		}
		fileout.close();

		tInst.join();

		if (UserWin) {
			EnemHP = 0;
			Ent.join();
			return 1; // End of game
		}
		else if (HP > 0) {
			EnemHP = 0;
			Ent.join();
			return 2; // Menu
		}
		Ent.join();
		return 0; // Death and Menu
	}
}