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

void drawInventory(vector<Equipment> myitem, Unit& hero, Unit& f1, Unit& f2, ieInput test) {
	int a = myitem.size();
	if (test == iRIGHT) {
		if (myitem[i].type == 1) {
			hero.item_type1 = myitem[i];
		}
		if (myitem[i].type == 2 && hero.item_type1.is_twohand == 0 ) {
			hero.item_type2 = myitem[i];
		}
		if (myitem[i].type == 3) {
			hero.item_type3 = myitem[i];
		}
		if (myitem[i].type == 4) {
			hero.item_type4 = myitem[i];
		}
	}
	if (test == iRIGHT) {
		if (myitem[i].type == 1) {
			f1.item_type1 = myitem[i];
		}
		if (myitem[i].type == 2 && hero.item_type1.is_twohand == 0) {
			f1.item_type2 = myitem[i];
		}
		if (myitem[i].type == 3) {
			f1.item_type3 = myitem[i];
		}
		if (myitem[i].type == 4) {
			f1.item_type4 = myitem[i];
		}
	}
	if (test == iRIGHT) {
		if (myitem[i].type == 1) {
			f2.item_type1 = myitem[i];
		}
		if (myitem[i].type == 2 && hero.item_type1.is_twohand == 0) {
			f2.item_type2 = myitem[i];
		}
		if (myitem[i].type == 3) {
			f2.item_type3 = myitem[i];
		}
		if (myitem[i].type == 4) {
			f2.item_type4 = myitem[i];
		}
	}
	cout << "######################################################################################################\n";
	cout << "#                                                                                                    #\n";
	cout << "#                                                ITEM                                                #\n";
	cout << "#                                                                                                    #\n";
	cout << "######################################################################################################\n";
	cout << "#                                                                                                    #\n";
	for (int b = 0; b < a; b++) {
		cout << "# " << ichoice(icommand[b]) << setw(88) << left << myitem[b].name;// << "#\n";
		if (hero.item_type1.name == myitem[b].name) {
			cout << left << " (used) " << "#\n";
		}
		else {
			if (hero.item_type2.name == myitem[b].name) {
				cout << left << " (used) " << "#\n";
			}
			else {
				if (hero.item_type3.name == myitem[b].name) {
					cout << left << " (used) " << "#\n";
				}
				else {
					if (hero.item_type4.name == myitem[b].name) {
						cout << left << " (used) " << "#\n";
					}
					else {
						cout << "        #\n";
					}
				}
			}
		}
	}
	cout << "#                                                                                                    #\n";
	cout << "######################################################################################################\n";
}

void itemUI(vector<Equipment> myitem ,Unit& hero, Unit& friend1, Unit& friend2) {
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
	ieInput test = iSTOP;
	drawInventory(myitem,hero,friend1,friend2,test);
	int how = myitem.size();
	while (stage_inventory) {
		iInput(how);
		test = iinp;
		iLogic();
		if (KeyDown) {
			system("cls");
			drawInventory(myitem,hero, friend1, friend2, test);
			hero.increaseStats();
			friend1.increaseStats();
			friend2.increaseStats();

		}
		KeyDown = false;
	}
}
