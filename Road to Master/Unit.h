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
	//skill *s1, s2;
public:
	string name;
	int hp, Maxhp;
	int mp, Maxmp;
	Unit(string, int, int, int, int, int, int, int, int); // name,str,agi,dex,int,luk,vit,exp,money
	string coutname();
	void editstatus(string, int, int, int, int, int, int, int, int);
	int attack(Unit &);
	int beAttacked(int, char);
	void action(int &, char &);
	void n_attack(char &type);
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
	cout << "build monster name " << name << endl;
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
	Maxhp = vit * 5;
	Maxmp = Int * 2;
	atk = str * 2;
	matk = Int * 2;
	def = vit + str;
	mdef = vit + Int;
	cri = luk * 0.5;
	eva = agi * 1.5;
	acc = dex;
	hp = Maxhp;
}

int Unit::attack(Unit &u) {
	int power;
	char attack_type;
	action(power, attack_type);
	u.beAttacked(power, attack_type);
	return atk;
}

int Unit::beAttacked(int opppower, char attack_type) {
	int dmg;
	if (attack_type == 'P' && opppower > def) {
		dmg = opppower - def;
	}
	else if (attack_type == 'M' && opppower > mdef) {
		dmg = opppower - mdef;
	}

	hp -= dmg;
	if (hp <= 0) { hp = 0; }

	return dmg;
}

void Unit::action(int &dmg, char &type) {
	int power = 100;
	n_attack(type);
	dmg = atk;
}

void Unit::n_attack(char &type) {
	type = 'P';
}