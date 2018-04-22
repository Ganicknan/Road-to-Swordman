#include"Equipment.h"
#include<vector>
using namespace std;

class Unit {
	vector<Equipment> ownitem;
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
	string name;
	int hp, Maxhp;
	int mp, Maxmp;
	Unit(string, int, int, int, int, int, int, int, int); // name,str,agi,dex,int,luk,vit,exp,money
	void statuscal();
	string coutname();
	void editstatus(string, int, int, int, int, int, int, int, int);
	void attack();
};

Unit::Unit(string rname = "", int rstr = 0, int ragi = 0, int rdex = 0, int rint = 0, int rluk = 0, int rvit = 0, int rexp = 0, int rmoney = 0) {
	name = rname;
	str = rstr;
	dex = rdex;
	Int = rint;
	luk = rluk;
	vit = rvit;
	exp = rexp;
	money = rmoney;
	cout << "build monster name " << name << endl;
	statuscal();
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
	hp = Maxhp;
}

string Unit::coutname() {
	return name;
}

void Unit::editstatus(string rname, int rstr, int ragi, int rdex, int rint, int rluk, int rvit, int rexp, int rmoney) {
	name = rname;
	str = rstr;
	dex = rdex;
	Int = rint;
	luk = rluk;
	vit = rvit;
	exp = rexp;
	money = rmoney;
	cout << "edit monster name " << name << endl;
	statuscal();
}

void Unit::attack() {

}