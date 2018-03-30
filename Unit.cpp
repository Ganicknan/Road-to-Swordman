#include<iostream>
#include"Equipment.cpp"
using namespace std;

class Unit{
	string name;
	int hp,Maxhp;
	int mp,Maxmp;
	double atk,matk;
	double def,mdef;
	int Str,Agi,Dex,Int,Lux,Vit; //main stats.
	double Cri,Eva,Acc; //sub stats.
	int money;
	int lvl; // level.
	int exp;
	int Mexp; //max exp.
	Equipment* weapon,offhand,armor,accessory;
	public:
		Unit(string,int,int,int,int,int,int);
};
