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
	//Equipment* weapon, offhand, armor, accessory;
	public:
		Unit(string, int, int, int, int, int, int, int, int); // name,str,agi,dex,int,luk,vit,exp,money
		void statuscal();
		void asdf();
};

Unit::Unit(string rname, int rstr, int ragi, int rdex, int rint, int rluk, int rvit, int rexp, int rmoney) {
	name = rname;
	str = rstr;
	dex = rdex;
	Int = rint;
	luk = rluk;
	vit = rvit;
	exp = rexp;
	money = rmoney;
}

void Unit::statuscal() {
	Maxhp = 10 + (vit * 5);
	Maxmp = 5 + (Int * 2);
	atk = 2 + (str * 2);
	matk = 2 + (Int * 2);
	def = 2 + vit + str;
	mdef = 2 + vit + Int;
	cri = 1 + (luk * 0.5);
	eva = agi * 1.5;
	acc = dex;
}