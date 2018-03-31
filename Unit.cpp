#include<iostream>
#include"Equipment.cpp"
using namespace std;

class Unit{
	string name;
	int hp,Maxhp;
	int mp,Maxmp;
	int atk,matk;
	int def,mdef;
	int Str,Agi,Dex,Int,Luk,Vit; //main stats.
	double Cri,Eva,Acc; //sub stats.
	int money;
	int lvl; // level.
	int exp;
	int Mexp; //max exp.
	Equipment* weapon,offhand,armor,accessory;
	public:
		Unit(string,int,int,int,int,int,int,int,int); // name,str,agi,dex,int,luk,vit,exp,money
};
