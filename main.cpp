#include "Unit.cpp"
#include<conio.h>
//#include "Map.cpp" (uncomplete)
using namespace std;

bool closeGame;
const int width = 100;
const int height = 40;
int x,y;
enum eInput { STOP = 0 , LEFF , RIGHT , UP , DOWN };
eInput inp;
bool keyDown = false;

void setup(){
	closeGame = false;
	x = width/2;
	y = height/2;
	
}

void draw(){
	system("cls");
	for(int i = 0;i < width+2; i++){
		cout << "#";
	}
	cout << endl;
	for(int i = 0;i < height; i++){
		for(int j = 0;j < width+2; j++){
			if(j == 0){
				cout << "#";
			}else {
				if(j == x && i == y){
					cout << "U";
				}else {
					cout << " ";
				}
			}
			if(j == width){
				cout << "#";
			}
		}
		cout << endl;
	}
	for(int i = 0 ;i < width+2; i++){
		cout << "#";
	}
}

void input(){
	if(_kbhit()){
		switch(_getch()){
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

void Logic(){
	switch(inp){
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

int main(){
	setup();
	draw();
	while(1){
		input();
		Logic();
		if(keyDown){
			draw();
			if(closeGame){
				break;
			}
			keyDown = false;
		}
	}
	return 0;
}
