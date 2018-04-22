#include<iostream>
#include<conio.h>
using namespace std;


enum ieInput { iSTOP = 0, iLEFT, iRIGHT, iUP, iDOWN };
ieInput iinp;
bool stage_inventory;

void iInput() {
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
			iinp = iDOWN;
			KeyDown = true;
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
		iinp = iSTOP;
		break;
	case iLEFT:
		if (stage_inventory == 1) {
			stage_inventory = false;
		}
		iinp = iSTOP;
		break;
	case iDOWN:
		iinp = iSTOP;
		break;
	case iRIGHT:
		iinp = iSTOP;
		break;
	default:
		break;
	}
}

void drawInventory() {
	cout << "######################################################################################################\n";
	cout << "#                                                                                                    #\n";
	cout << "#                                                ITEM                                                #\n";
	cout << "#                                                                                                    #\n";
	cout << "######################################################################################################\n";
	cout << "#                                                                                                    #\n";
	cout << "# ";
}

void itemUI() {
	system("cls");
	stage_inventory = true;
	drawInventory();
	while (stage_inventory) {
		iInput();
		iLogic();
		if (KeyDown) {
			system("cls");
			drawInventory();
		}
		KeyDown = false;
	}
}
