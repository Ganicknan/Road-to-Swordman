#include<iostream>
#include<conio.h>
using namespace std;



bool sKeyDown = false; 
enum seinput { sSSTOP = 0, sBACK, sACCEPT, sUP, sDOWN };
seinput sInp;
bool scommand[4];
int i = 0;

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
			if (stage_select == 1) break;
			sInp = sBACK;
			sKeyDown = true;
			break;
		case 's':
			if (i != 3) {
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
		stage_select = 1;
		sInp = sSSTOP;
		break;
	case sDOWN:
		command[i] = false;
		i++;
		command[i] = true;
		sInp = sSSTOP;
		break;
	case sACCEPT:
		sInp = sSSTOP;
		break;
	default:
		break;
	}
}

void shopUI() {

}