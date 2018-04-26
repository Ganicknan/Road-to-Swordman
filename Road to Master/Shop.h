#include<iostream>
#include<iomanip>
#include<conio.h>
#include<cstdlib>
#include<string>
#include"Equipment.h"
#include<vector>
using namespace std;



bool sKeyDown = false; 
enum seinput { sSSTOP = 0, sBACK, sACCEPT, sUP, sDOWN };
seinput sInp;
bool scommand[13];
int i = 0;
int stage_shop = 1;
bool is_shop;

void sInput() {
	if (_kbhit()) {
		switch (_getch()) {
		case 'w':
			if (i != 0) {
				sInp = sUP;
				sKeyDown = true;
			}
			break;
		case 'a':
			sInp = sBACK;
			sKeyDown = true;
			break;
		case 's':
			if (i != 13) {
				sInp = sDOWN;
				sKeyDown = true;
			}
			break;
		case 'd':
			sInp = sACCEPT;
			sKeyDown = true;
			break;
		}
	}
}

void slogic() {
	switch (sInp) {
	case sUP:
		scommand[i] = false;
		i--;
		scommand[i] = true;
		sInp = sSSTOP;
		break;
	case sBACK:
		stage_shop = 1;
		if (stage_shop == 1) is_shop = false;
		sInp = sSSTOP;
		break;
	case sDOWN:
		scommand[i] = false;
		i++;
		scommand[i] = true;
		sInp = sSSTOP;
		break;
	case sACCEPT:

		sInp = sSSTOP;
		break;
	default:
		break;
	}
}

string schoice(bool sselected) {
	if (sselected) {
		return "-> ";
	}
	else {
		return "   ";
	}
}

void listItem(Equipment* equipment, int& smoney) {
	int i = 0;
	cout << "######################################################################################################\n";
	cout << "#                                                                                                    #\n";
	cout << "#                                                SHOP" << setw(44) << right << smoney << " G  #\n";
	cout << "#                                                                                                    #\n";
	cout << "######################################################################################################\n";
	cout << "#                                                                                                    #\n";
	for (int j = 0; j < 14; j++) {
		cout << "# " << schoice(scommand[i]) << setw(91) << left << equipment[i].name << setw(5) << "500" << "#\n";
		i++;
	}
	cout << "#                                                                                                    #\n";
	cout << "######################################################################################################\n";
}

void shopUI(Equipment* equipment, int& smoney, vector<Equipment>& myitem) {
	is_shop = true;
	scommand[0] = { 1 };
	scommand[1] = { 0 };
	scommand[2] = { 0 };
	scommand[3] = { 0 };
	scommand[4] = { 0 };
	scommand[5] = { 0 };
	scommand[6] = { 0 };
	scommand[7] = { 0 };
	scommand[8] = { 0 };
	scommand[9] = { 0 };
	scommand[10] = { 0 };
	scommand[11] = { 0 };
	scommand[12] = { 0 };
	system("cls");
	listItem(equipment, smoney);
	seinput sin;
	while (is_shop) {
		sInput();
		sin = sInp;
		slogic();
		if (sKeyDown) {
			system("cls");
			if (sin == sACCEPT) {
				if (smoney >= 500) {
					smoney -= 500;
					for (int a = 0; a < 14; a++) {
						if (scommand[a] == 1) {
							myitem.push_back(equipment[a]);
						}
					}
				}
			}
			listItem(equipment, smoney);
		}
		sKeyDown = false;
	}
}