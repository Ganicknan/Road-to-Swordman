#include<iostream>
using namespace std;

class Equipment{
	string name;
	int Maxhp; // Max hp.
	int Maxmp;
	int atk,matk; //m is magic.
	int def,mdef; //m is magic.
	int Str,Agi,Dex,Int,Luk,Vit;
	double Cri,Eva,Acc;
	int type; //type ID 1.weapon 2.offhand 3.armor 4.accessory.
	bool is_twohand; // offhade can't be used.
	public:
		Equipment(string,int,int,int,int,int,int,int,int,int,int,int,int,double,double,double,int,bool); // name,maxhp,maxmp,atk,matk,def,mdef,str,agi,des,int,luk,vit,cri,eva,acc,type,is_twohand
};
