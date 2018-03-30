#include<iostream>
using namespace std;

class Equipment{
	string name;
	int Maxhp; // Max hp.
	int Maxmp;
	double atk,matk; //m is magic.
	double def,mdef; //m is magic.
	int Str,Agi,Dex,Int,Lux,Vit;
	double Cri,Eva,Acc;
	int type; //type ID 1.weapon 2.offhand 3.armor 4.accessory.
	bool is_twohand; // offhade can't be used.
	public:
		Equipment(string,int,int,double,double,double,double,int,int,int,int,int,int,double,double,double,int,bool);
};
