#include<iostream>
#include<iomanip>
#include<conio.h>
using namespace std;


enum ieInput { iSTOP = 0, iLEFT, iRIGHT, iUP, iDOWN };
ieInput iinp;
bool stage_inventory;
bool icommand[13];

void iInput(int how) {
	if (_kbhit()) {
		switch (_getch()) {
		case 'w':
			if (i != 0) {
				iinp = iUP;
				KeyDown = true;
			}
			break;
		case 'a':
			iinp = iLEFT;
			KeyDown = true;
			break;
		case 's':
			if (i != how-1) {
				iinp = iDOWN;
				KeyDown = true;
			}
			break;
		case 'd':
			iinp = iRIGHT;
			KeyDown = true;
			break;
		}
	}
}

void iLogic() {
	switch (iinp) {
	case iUP:
		icommand[i] = false;
		i--;
		icommand[i] = true;
		iinp = iSTOP;
		break;
	case iLEFT:
		if (stage_inventory == 1) {
			stage_inventory = false;
		}
		iinp = iSTOP;
		break;
	case iDOWN:
		icommand[i] = false;
		i++;
		icommand[i] = true;
		iinp = iSTOP;
		break;
	case iRIGHT:
		iinp = iSTOP;
		break;
	default:
		break;
	}
}
string ichoice(bool selected) {
	if (selected) {
		return "-> ";
	}
	else {
		return "   ";
	}
}

void drawInventory(vector<Equipment> myitem) {
	int a = myitem.size();
	cout << "######################################################################################################\n";
	cout << "#                                                                                                    #\n";
	cout << "#                                                ITEM                                                #\n";
	cout << "#                                                                                                    #\n";
	cout << "######################################################################################################\n";
	cout << "#                                                                                                    #\n";
	for (int b = 0; b < a; b++) {
		cout << "# "  << ichoice(icommand[b]) << setw(96) << left << myitem[b].name  << "#\n";
	}
	cout << "#                                                                                                    #\n";
	cout << "######################################################################################################\n";

}

void itemUI(vector<Equipment> myitem) {
	i = 0;
	icommand[0] = { 1 };
	icommand[1] = { 0 };
	icommand[2] = { 0 };
	icommand[3] = { 0 };
	icommand[4] = { 0 };
	icommand[5] = { 0 };
	icommand[6] = { 0 };
	icommand[7] = { 0 };
	icommand[8] = { 0 };
	icommand[9] = { 0 };
	icommand[10] = { 0 };
	icommand[11] = { 0 };
	icommand[12] = { 0 };
	system("cls");
	stage_inventory = true;
	drawInventory(myitem);
	int how = myitem.size();
	cout << how;
	while (stage_inventory) {
		iInput(how);
		iLogic();
		if (KeyDown) {
			system("cls");
			drawInventory(myitem);
		}
		KeyDown = false;
	}
}
