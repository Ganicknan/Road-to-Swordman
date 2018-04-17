#include"Equipment.h"
using namespace std;

class Unit {
	string name;
	int hp, Maxhp;
	int mp, Maxmp;
	int atk, matk;
	int def, mdef;
	int str, agi, dex, Int, luk, vit; //main stats.
	double cri, eva, acc; //sub stats.
	int money;
	int lvl; // level.
	int exp;
	int Mexp; //max exp.
	Equipment* weapon, offhand, armor, accessory;
public:
	Unit(string, int, int, int, int, int, int, int, int); // name,str,agi,dex,int,luk,vit,exp,money
};