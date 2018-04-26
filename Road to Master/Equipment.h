#include<iostream>
using namespace std;

class Equipment {
public:
	int maxhp; // Max hp.
	int maxmp;
	int atk, matk; //m is magic.
	int def, mdef; //m is magic.
	float cri, eva, acc;
	bool is_twohand; // offhade can't be used.
	int type; //type ID 1.weapon 2.offhand 3.armor 4.accessory.
	string name;
	Equipment(string, int, int, int, int, int, int, float, float, float, int, bool); // name,maxhp,maxmp,atk,matk,def,mdef,cri,eva,acc,type,is_twohand
};

Equipment::Equipment(string ename = "", int emaxhp = 0, int emaxmp = 0, int eatk = 0, int ematk = 0, int edef = 0, int emdef = 0, float ecri = 0, float eeva = 0, float eacc = 0, int etype = 0, bool eis_twohand = 0) {
	name = ename;
	maxhp = emaxhp;
	maxmp = emaxmp;
	atk = eatk;
	matk = ematk;
	def = edef;
	mdef = emdef;
	cri = ecri;
	eva = eeva;
	acc = eacc;
	type = etype;
	is_twohand = eis_twohand;
}