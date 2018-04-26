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
bool attack = false;
bool useskill;
enum einput { SSTOP = 0, BACK, ACCEPT, UUP, DDOWN };
einput Inp;
int bi = 0;
int stage_select = 1;
int ranmon = 0;
int turn;
Skill Fireball("Fireball", 2, 1.5, 'M');
Skill Magicarrow("Magicarrow", 2, 1.5, 'M');
Skill Stap("Stap", 2, 1.5, 'P');
Unit monster[7];
Unit hero("Hero", 6, 6, 6, 6, 6, 6);
Unit notahero("ImnotaHeros", 1, 1, 1, 1, 1, 1);
Unit friendofhero("Mobu", 5, 5, 5, 5, 5, 5);
Unit herowife("Herowaifu", 3, 6, 5, 8, 6, 4);
Unit *pointtarget;
Unit wildmon;
int damagereport;
int who;
bool enemyattack;

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
		command[0] = { true };
		command[1] = { false };
		command[2] = { false };
		command[3] = { false };
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

			if (stage_select == 2) {
				attack = true;
				useskill = true;
			}
			if (stage_select == 3) {
				attack = true;
			}
			else {
				stage_select = 3;
				bi = 0;
			}
		}
		if (bi == 1) {
			stage_select = 2;
			command[bi] = false;
			bi = 0;
			command[bi] = true;
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
	hero.inputskill(&Stap);
	friendofhero.inputskill(&Magicarrow);
	herowife.inputskill(&Fireball);
}

void Dawnbattle(int rand_mon) {
	system("cls");
	cout << "######################################################################################################\n";
	cout << "#  " << setw(98) << left << wildmon.name << "#\n";
	cout << "#  HP " << setw(95) << left << wildmon.hp <<"#\n";
	cout << "#  MP " << setw(95) << left << wildmon.mp << "#\n";
	cout << "######################################################################################################\n";
	drawmonster(wildmon.name);
	cout << "######################################################################################################\n";
	cout << "# "<< setw(28) << left << hero.name << setw(28) << left << herowife.name << setw(43) << friendofhero.name << "#\n";
	cout << "# HP " << setw(4) << right << hero.hp << "/" << setw(20) << left << hero.Maxhp << "HP " << setw(4) << right << herowife.hp << "/" << setw(20) << left << herowife.Maxhp << "HP " << setw(4) << right << friendofhero.hp << "/" << setw(36) << left << friendofhero.Maxhp << "#\n";
	cout << "# MP " << setw(4) << right << hero.mp << "/" << setw(20) << left << hero.Maxmp << "HP " << setw(4) << right << herowife.mp << "/" << setw(20) << left << herowife.Maxmp << "HP " << setw(4) << right << friendofhero.mp << "/" << setw(36) << left << friendofhero.Maxmp << "#\n";;
	cout << "######################################################################################################\n";
	cout << "#                                                                                                    #\n";
	if (stage_select == 1) {
		cout << "#  " << choice(command[0]) << " Attack                                                                                         #\n";
		cout << "#  " << choice(command[1]) << " Skill                                                                                          #\n";
		cout << "#  " << choice(command[2]) << " Item                                                                                           #\n";
		cout << "#  " << choice(command[3]) << " Escape                                                                                         #\n";
	}

	if (stage_select == 3 || stage_select == 2) { // select monster
		cout << "#  " << choice(command[0]) << "  " << setw(94) << left << monster[rand_mon].name  << "#\n";
	}
	cout << "#                                                                                                    #\n";
	cout << "######################################################################################################\n";
	cout << "#                                                                                                    #\n";
	if (!enemyattack) {
		if (who == 0) cout << "#  " << hero.name << " dealt " << damagereport << " to " << wildmon.name << endl;
		else if (who == 1) cout << "#  " << herowife.name << " dealt " << damagereport << " to " << wildmon.name << endl;
		else cout << "#  " << friendofhero.name << " dealt " << damagereport << " to " << wildmon.name << endl;
	}
	else {
		if (who == 0) cout << "#  " << wildmon.name << " dealt " << damagereport << " to " << hero.name << endl;
		else if (who == 1) cout << "#  " << wildmon.name << " dealt " << damagereport << " to " << herowife.name << endl;
		else cout << "#  " << wildmon.name << " dealt " << damagereport << " to " << friendofhero.name << endl;
	}
	cout << "#                                                                                                    #\n";
	cout << "######################################################################################################\n";
}
void battleUI(int rand_mon) {
	damagereport = 0;
	is_battle = true;
	wildmon = monster[rand_mon];
	enemyattack = false;
	bi = 0;
	while (is_battle) {
		int member = 0;
		if (!hero.is_dead) member++;
		if (!friendofhero.is_dead) member++;
		if (!herowife.is_dead) member++;
		if (member == 0) return;
		for(int i = 0; i < member; i++){
			useskill = false;
			command[0] = { true };
			command[1] = { false };
			command[2] = { false };
			command[3] = { false };
			bool isincommand = true;
			attack = false;
			stage_select = 1;
			Dawnbattle(rand_mon);
			while (isincommand) {
				Input();
				logic();
				if (KeyDown) {
					KeyDown = false;
					enemyattack = false;
					if (attack) {
						switch (i)
						{
						case 0:
							if (!hero.is_dead) {
								if (useskill) damagereport = hero.attack(wildmon, 1);
								else damagereport = hero.attack(wildmon);
								who = 0;
								break;
							}
						case 1:
							if (!(hero.is_dead || herowife.is_dead) || ((hero.is_dead && i == 0) && !herowife.is_dead)) {
								if (useskill) damagereport = herowife.attack(wildmon, 1);
								else damagereport = herowife.attack(wildmon);
								who = 1;
								break;
							}
						case 2:
							if (useskill) damagereport = hero.attack(wildmon, 1);
							else damagereport = friendofhero.attack(wildmon);
							who = 2;
							break;
						}
						isincommand = false;
						if (wildmon.hp == 0) return;
					}
					else if (!is_battle) return;
					else Dawnbattle(rand_mon);
				}
			}
		}
		enemyattack = true;
		int randommonstertarget = rand()%member;
		switch (randommonstertarget)
		{
		case 0:
			if (!hero.is_dead) {
				pointtarget = &hero;
				who = 0;
				break;
			}
		case 1:
			if (!(hero.is_dead || herowife.is_dead) || ((hero.is_dead && i == 0) && !herowife.is_dead)) {
				pointtarget = &herowife;
				who = 1;
				break;
			}
		case 2:
			pointtarget = &friendofhero;
			who = 2;
			break;
		}
		damagereport = wildmon.attack(*pointtarget);
	}
}
