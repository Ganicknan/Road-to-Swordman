#include<conio.h>
#include<fstream>
#include<string>
#include"Map.h"
#include"Unit.h"
#include<random>
#include<ctime>
#include"Battle.h"
#include<vector>
#include<cstdlib>
#include"Inventory.h"
using namespace std;

bool closeGame;
int x, y, stage;
int width = 102;
int height = 32;
char map[32][102];
enum eInput { STOP = 0, LEFF, RIGHT, UP, DOWN, INVENTORY };
eInput inp;
bool keyDown = false;
bool inventory_on = false;

void setup() {
	monstersetup();
	closeGame = false;
	x = width / 2;
	y = height / 2;
	stage = 2;
}

void draw() {
	system("cls");
	for (int i = 0; i < 32; i++) {
		for (int j = 0; j < 102; j++) {
			if (x == j && y == i) {
				cout << "U";
			}
			else {
				if (map[i][j] == '0') {
					cout << " ";
				}
				if (map[i][j] == '1') {
					cout << "#";
				}
				if (map[i][j] == '2') {
					cout << ">";
				}
				if (map[i][j] == '3') {
					cout << "<";
				}
				if (map[i][j] == '4') {
					cout << "*";
				}
				if (map[i][j] == 'a') {
					cout << "B";
				}
				if (map[i][j] == 'b') {
					cout << "B";
				}
				if (map[i][j] == 'c') {
					cout << "B";
				}
				if (map[i][j] == 'T') {
					cout << "T";
				}
				if (map[i][j] == 'Q') {
					cout << "Q";
				}
				if (map[i][j] == 'U') {
					cout << "U";
				}
				if (map[i][j] == 'E') {
					cout << "E";
				}
				if (map[i][j] == 'S') {
					cout << "S";
				}
				if (map[i][j] == 'O') {
					cout << "O";
				}
				if (map[i][j] == 'H') {
					cout << "H";
				}
				if (map[i][j] == 'o') {
					cout << "O";
				}
				if (map[i][j] == 'P') {
					cout << "P";
				}
				if (map[i][j] == 's') {
					cout << "O";
				}
				if (map[i][j] == '5') {
					cout << "*";
				}
			}
		}
		cout << "\n";
	}
}

void input() {
	if (_kbhit()) {
		switch (_getch()) {
		case 'w':
			if (map[y - 1][x] != '1') {
				inp = UP;
				keyDown = true;
			}
			break;
		case 'a':
			if (map[y][x - 1] != '1') {
				inp = LEFF;
				keyDown = true;
			}
			break;
		case 's':
			if (map[y + 1][x] != '1') {
				inp = DOWN;
				keyDown = true;
			}
			break;
		case 'd':
			if (map[y][x + 1] != '1') {
				inp = RIGHT;
				keyDown = true;
			}
			break;
		case 'i':
			inp = INVENTORY;
			keyDown = true;
			break;
		case 'x':
			closeGame = true;
			keyDown = true;
			break;
		}
	}
}

void Logic() {
	switch (inp) {
	case UP:
		y--;
		inp = STOP;
		break;
	case LEFF:
		x--;
		inp = STOP;
		break;
	case DOWN:
		y++;
		inp = STOP;
		break;
	case RIGHT:
		x++;
		inp = STOP;
		break;
	case INVENTORY:
		inventory_on = true;
		inp = STOP;
		break;
	default:
		break;
	}
}


void createMap() {
	ifstream readmap;
	if (stage == 1) {
		readmap.open("map1.txt");
	}
	if (stage == 2) {
		readmap.open("map2.txt");
	}
	if (inventory_on == true) {
		itemUI();
		inventory_on = false;
	}
	string textline;
	int i = 0;
	while (getline(readmap, textline)) {
		for (int j = 0; j < 102; j++) {
			map[i][j] = textline[j];
		}
		i++;
	}
	readmap.close();
}

void changeMap() {
	if (stage == 1) {
		if (map[y][x] == '2') {
			stage = 2;
			x = 2;
		}
	}
	if (stage == 2) {
		if (map[y][x] == '3') {
			stage = 1;
			x = 99;
		}
	}
	createMap();
}

int main() {
	srand(time(0));
	setup();
	createMap();
	draw();
	while (1) {
		input();
		Logic();
		if (keyDown) {
			changeMap();
			if (map[y][x] == '4' && rand() % 5 == 0) {
				int rand_mon = rand() % 3;
				battleUI(rand_mon);
			}
			if (map[y][x] == '5' && rand() % 5 == 0) {
				int rand_mon = rand() % 3 + 3;
				battleUI(rand_mon);
			}
			if (map[y][x] == 'O') {

			}
			if (map[y][x] == 's') {

			}
			draw();
			if (stage == 2 && map[y][x] == 'T') {
				cout << "#                                                                                                    #\n";
				cout << "#   Congratulation. You got Ring of hero.                                                            #\n";
				cout << "#                                                                                                    #\n";
				cout << "######################################################################################################\n";
			}
			if (closeGame) {
				break;
			}
			keyDown = false;
		}
	}
	return 0;
}