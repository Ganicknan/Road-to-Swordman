#include"Shop.h"
#include<vector>
using namespace std;

class Skill {
	string name;
	double power;
	char type;
public:
	int mpcost;
	Skill(string, int, double, char);
	void useskill(char &, double &);
};

class Unit {
	int atk, matk;
	int def, mdef;
	int str, agi, dex, Int, luk, vit; //main stats.
	double cri, eva, acc; //sub stats.
	int lvl; // level.
	int exp;
	int Mexp; //max exp.
			  //Equipment* weapon, offhand, armor, accessory;
	Skill *s1;
public:
	vector<Equipment> ownitem;
	string name;
	int hp, Maxhp;
	int mp, Maxmp;
	int money;
	Equipment item_type1, item_type2, item_type3, item_type4;
	bool is_dead = false;
	Unit(string, int, int, int, int, int, int, int, int); // name,str,agi,dex,int,luk,vit,exp,money
	void statuscal();
	void coutstatus();
	void editstatus(string, int, int, int, int, int, int, int, int);
	int attack(Unit &, int);
	int beAttacked(int, char);
	void n_attack(char &type);
	void heal();
	void operator=(Unit);
	void inputskill(Skill *);
	void increaseStats();
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
	mp = Maxmp;
}

void Unit::coutstatus() {
	cout << name << endl;
	cout << "MaxHP:" << Maxhp << endl;
	cout << "MaxMP:" << Maxmp << endl;
	cout << "atk:  " << atk << endl;
	cout << "matk: " << matk << endl;
	cout << "def:  " << def << endl;
	cout << "mdef: " << mdef << endl;
	cout << "cri:  " << cri << endl;
	cout << "eva:  " << agi << endl;
	cout << "acc:  " << acc << endl;
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
	statuscal();
}

int Unit::attack(Unit &u, int command = 0) {
	double power = 1;
	char attack_type;
	if (command == 1 && s1->mpcost <= mp) { 
		s1->useskill(attack_type, power); 
		mp -= s1->mpcost; 
	}
	else n_attack(attack_type);

	if (attack_type == 'P') power *= double(atk);
	else power *= double(matk);
	return u.beAttacked(int(power), attack_type);
}

int Unit::beAttacked(int opppower, char attack_type) {
	int dmg;
	if (attack_type == 'P' && opppower > def) {
		dmg = opppower - def;
	}
	else if (attack_type == 'M' && opppower > mdef) {
		dmg = opppower - mdef;
	}
	else dmg = 1;
	hp -= dmg;
	if (hp < 0) hp = 0, is_dead = true;
	return dmg;
}

void Unit::n_attack(char &type) {
	type = 'P';
}

void Unit::heal() {
	hp = Maxhp;
}

void Unit::operator=(Unit target) {
	name = target.name;
	str = target.str;
	dex = target.dex;
	Int = target.Int;
	luk = target.luk;
	vit = target.vit;
	exp = target.exp;
	money = target.money;
	statuscal();
}

void Unit::inputskill(Skill *s) {
	s1 = s;
}

Skill::Skill(string rname, int mp, double rpower, char rtype) {
	name = rname, power = rpower, type = rtype;
	mpcost = mp;
}

void Skill::useskill(char &t, double &p) {
	t = type, p = power;
}

void Unit::increaseStats() {
	Maxhp += item_type1.maxhp;
	Maxmp += item_type1.maxmp;
	atk += item_type1.atk;
	matk += item_type1.matk;
	def += item_type1.def;
	mdef += item_type1.mdef;
	cri += item_type1.cri;
	eva += item_type1.eva;
	acc += item_type1.acc;

	Maxhp += item_type2.maxhp;
	Maxmp += item_type2.maxmp;
	atk += item_type2.atk;
	matk += item_type2.matk;
	def += item_type2.def;
	mdef += item_type2.mdef;
	cri += item_type2.cri;
	eva += item_type2.eva;
	acc += item_type2.acc;

	Maxhp += item_type3.maxhp;
	Maxmp += item_type3.maxmp;
	atk += item_type3.atk;
	matk += item_type3.matk;
	def += item_type3.def;
	mdef += item_type3.mdef;
	cri += item_type3.cri;
	eva += item_type3.eva;
	acc += item_type3.acc;

}