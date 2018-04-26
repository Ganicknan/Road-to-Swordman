#include<iostream>
#include<ctime>
#include<string>
#include<cstdlib>
#include<iomanip>
#include<conio.h>
#include"Monster.h"
using namespace std;

bool KeyDown = false;
bool command[4];
bool is_battle = false;
enum einput { SSTOP = 0, BACK, ACCEPT, UUP, DDOWN };
einput Inp;
int bi = 0;
int stage_select = 1;
int ranmon = 0;
Unit monster[7];
Unit hero("hero", 1, 1, 1, 1, 1, 1, 1, 1000);

void Input() {
	if (_kbhit()) {
		switch (_getch()) {
		case 'w':
			if (bi != 0) {
				Inp = UUP;
				KeyDown = true;
			}
			break;
		case 'a':
			if (stage_select == 1) break;
			Inp = BACK;
			KeyDown = true;
			break;
		case 's':
			if (bi != 3) {
				Inp = DDOWN;
				KeyDown = true;
			}
			break;
		case 'd':
			Inp = ACCEPT;
			KeyDown = true;
			break;
		}
	}
}

void logic() {
	switch (Inp) {
	case UUP:
		command[bi] = false;
		bi--;
		command[bi] = true;
		Inp = SSTOP;
		break;
	case BACK:
		stage_select = 1;
		Inp = SSTOP;
		break;
	case DDOWN:
		command[bi] = false;
		bi++;
		command[bi] = true;
		Inp = SSTOP;
		break;
	case ACCEPT:
		if (bi == 0) {
			//select monster to attack.
			stage_select = 2;
		}
		if (bi == 3) {
			is_battle = false;
		}
		Inp = SSTOP;
		break;
	default:
		break;
	}
}

string choice(bool selected) {
	if (selected) {
		return "->";
	}
	else {
		return "  ";
	}
}

void monstersetup() {
	ifstream readmon("monster.txt");
	string textline;
	string mname;
	int mstr, magi, mdex, mint, mluk, mvit, mexp, mmoney;
	int i = 0;
	int loc;
	while (getline(readmon, textline)) {
		loc = textline.find_first_of(':');
		mname = textline.substr(0, loc);
		cout << mname << endl;
		textline = textline.substr(loc + 1, textline.size() - 1);
		sscanf_s(textline.c_str(), "%d,%d,%d,%d,%d,%d,%d,%d", &mstr, &magi, &mdex, &mint, &mluk, &mvit, &mexp, &mmoney);
		monster[i].editstatus(mname, mstr, magi, mdex, mint, mluk, mvit, mexp, mmoney);
		i++;
	}
	readmon.close();
}

void Dawnbattle(int rand_mon) {
	system("cls");
	string nam = monster[rand_mon].name;
	cout << "######################################################################################################\n";
	cout << "#  " << setw(98) << left << nam << "#\n";
	cout << "#  HP " << setw(95) << left << monster[rand_mon].hp <<"#\n";
	cout << "#  MP " << setw(95) << left << monster[rand_mon].mp << "#\n";
	cout << "######################################################################################################\n";
	drawmonster(nam);
	cout << "######################################################################################################\n";
	cout << "# \n";
	cout << "# HP\n";
	cout << "# MP\n";
	cout << "######################################################################################################\n";
	cout << "#                                                                                                    #\n";
	if (stage_select == 1) {
		cout << "#  " << choice(command[0]) << " Attack                                                                                         #\n";
		cout << "#  " << choice(command[1]) << " Skill                                                                                          #\n";
		cout << "#  " << choice(command[2]) << " Item                                                                                           #\n";
		cout << "#  " << choice(command[3]) << " Escape                                                                                         #\n";
	}

	if (stage_select == 2) { // select monster
		cout << "#  " << choice(command[0]) << "  " << setw(94) << left << monster[rand_mon].name  << "#\n";
	}
	cout << "#                                                                                                    #\n";
	cout << "######################################################################################################\n";
	cout << "#                                                                                                    #\n";
	cout << "#                                                                                                    #\n";
	cout << "#                                                                                                    #\n";
	cout << "######################################################################################################\n";
}
void battleUI(int rand_mon) {
	is_battle = true;
	bi = 0;
	command[0] = { true };
	command[1] = { false };
	command[2] = { false };
	command[3] = { false };
	Dawnbattle(rand_mon);
	while (is_battle) {
		Input();
		logic();

		if (KeyDown) {
			Dawnbattle(rand_mon);
			KeyDown = false;
		}
	}
}
