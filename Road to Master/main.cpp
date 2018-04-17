#include<conio.h>
#include<fstream>
#include<string>
#include"Map.h"
#include"Unit.h"
using namespace std;

bool closeGame;
int x, y, stage;
int width = 102;
int height = 32;
char map[32][102];
enum eInput { STOP = 0, LEFF, RIGHT, UP, DOWN };
eInput inp;
bool keyDown = false;

void setup() {
	closeGame = false;
	x = width / 2;
	y = height / 2;
	stage = 1;

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
			}
		}
		cout << "\n";
	}
}

	void input() {
	if (_kbhit()) {
		switch (_getch()) {
		case 'w':
			inp = UP;
			keyDown = true;
			break;
		case 'a':
			inp = LEFF;
			keyDown = true;
			break;
		case 's':
			inp = DOWN;
			keyDown = true;
			break;
		case 'd':
			inp = RIGHT;
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
	default:
		break;
	}
}


void changeMap(int stage, int x, int y) {
	if (stage == 1) {
		ifstream readmap("map1.txt");
		string textline;
		int i = 0;
		while (getline(readmap, textline)) {
			for (int j = 0; j < 102; j++) {
				map[i][j] = textline[j];
			}
			i++;
		}
	}
}

int main() {
	setup();
	changeMap(stage,x,y);
	draw();
	while (1) {
		input();
		Logic();
		if (keyDown) {
			changeMap(stage,x,y);
			if (closeGame) {
				break;
			}
			keyDown = false;
		}
	}
	return 0;
}