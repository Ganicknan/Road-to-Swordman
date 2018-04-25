#include<iostream>
#include<iomanip>
#include<conio.h>
#include"Equipment.h"
using namespace std;



bool sKeyDown = false; 
enum seinput { sSSTOP = 0, sBACK, sACCEPT, sUP, sDOWN };
seinput sInp;
bool scommand[14];
bool scommamndbuy[2];
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

void listItem(Equipment* equipment) {
	int i = 0;
	cout << "######################################################################################################\n";
	cout << "#                                                                                                    #\n";
	cout << "#                                                SHOP                                                #\n";
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

void shopUI(Equipment* equipment) {
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
	scommand[13] = { 0 };
	system("cls");
	listItem(equipment);
	while (is_shop) {
		sInput();
		slogic();
		if (sKeyDown) {
			system("cls");
			listItem(equipment);
		}
		sKeyDown = false;
	}
}