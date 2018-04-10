#include<iostream>
#include<vector>
using namespace std;

class Equipment{
	//string name;
	int Maxhp; // Max hp.
	int Maxmp;
	int atk,matk; //m is magic.
	int def,mdef; //m is magic.
	int Str,Agi,Dex,Int,Luk,Vit;
	double Crit,Eva,Acc;
	int Type; //type ID 1.weapon 2.offhand 3.armor 4.accessory.
	bool is_twohand; // offhand can't be used.
	public :Equipment(string,int,int,int,int,int,int,int,int,int,int,int,int,double,double,double,int,bool); 
		// name,maxhp,maxmp,atk,matk,def,mdef,str,agi,des,int,luk,vit,cri,eva,acc,type,is_twohand
			vector<int> getStat();
};
	Equipment::Equipment(string n,int hp,int mp,int att,int matt,int df,int mdf,int str,int agi,int dex,int in,int luk,int vit,double cri,double ev,double ac,int type,bool twohand){
	//name = n;
	Maxhp = hp;// Max hp.
	Maxmp = mp;
	atk = att;
	matk = matt;//m is magic.
	def = df;
	mdef = mdf;//m is magic.
	Str = str;
	Agi = agi;
	Dex = dex;
	Int = in;
	Luk = luk;
	Vit = vit;
	Crit = cri;
	Eva = ev;
	Acc = ac;
	Type = type;//type ID 1.weapon 2.offhand 3.armor 4.accessory.
	is_twohand = twohand;
}
	vector<int> Equipment::getStat(){
		vector<int> Stat;
//		Stat.push_back(name);//0
		Stat.push_back(Maxhp);//1
		Stat.push_back(Maxmp);//2
		Stat.push_back(atk);//3
		Stat.push_back(matk);//4
		Stat.push_back(def);//5
		Stat.push_back(mdef);//6
		Stat.push_back(Str);//7
		Stat.push_back(Agi);//8
		Stat.push_back(Dex);//9
		Stat.push_back(Int);//10
		Stat.push_back(Luk);//11
		Stat.push_back(Vit);//12
		Stat.push_back(Crit);//13
		Stat.push_back(Eva);//14
		Stat.push_back(Acc);//15
		Stat.push_back(Type);//16
		Stat.push_back(is_twohand);//17	
		return Stat;
	}
	//void Unit::equip(Equipment *eq){
		if(equipment != NULL){
		vector<int> Stat1=equipment->getStat() ;	
			//name -= Stat1[0];
			Maxhp -= Stat1[1];
			Maxmp -= Stat1[2];
			atk -= Stat1[3];
			matk -= Stat1[4];
			def -= Stat1[5];
			mdef -= Stat1[6];
			Str -= Stat1[7];
			Agi -= Stat1[8];
			Dex -= Stat1[9];
			Int -= Stat1[10];
			Luk -= Stat1[11];
			Vit -= Stat1[12];
			Crit -= Stat1[13];
			Eva -= Stat1[14];
			Acc -= Stat1[15];
			//Type
			//is_twohand	
		}
		vector<int> Stat2 = eq->getStat();
		//	name += Stat1[0];
			Maxhp += Stat1[1];
			Maxmp += Stat1[2];
			atk += Stat1[3];
			matk += Stat1[4];
			def += Stat1[5];
			mdef += Stat1[6];
			Str += Stat1[7];
			Agi += Stat1[8];
			Dex += Stat1[9];
			Int += Stat1[10];
			Luk += Stat1[11];
			Vit += Stat1[12];
			Crit += Stat1[13];
			Eva += Stat1[14];
			Acc += Stat1[15];
			//Type
			//is_twohand
				
		
}

/*Equipment type sword one hand "A" (name? ,10,0 ,2,0,0,0,5 ,0,0,0,0,0,3,5,80,1,false); 
//Equipment type sword one hand "B" (name? ,12,0 ,3,0,0,0,10,0,0,0,0,0,3,4,80,1,false); 
//Equipment type sword one hand "C" (name? ,15,0 ,4,0,0,0,15,0,0,0,0,0,3,3,80,1,false); 
//Equipment type sword one hand "D" (name? ,20,0 ,6,0,0,0,20,0,0,0,0,0,3,2,80,1,false); 

//Equipment type sword two hand "A" (name? ,0 ,0 ,6 ,0,0,0,5 ,0,1,0,0,0,3,0,80,1,true);
//Equipment type sword two hand "B" (name? ,5 ,0 ,8 ,0,0,0,10,0,1,0,0,0,3,0,80,1,true); 
//Equipment type sword two hand "C" (name? ,10,0 ,10,0,0,0,15,0,1,0,0,0,3,0,80,1,true); 
//Equipment type sword two hand "D" (name? ,10,0 ,12,0,0,0,20,0,1,0,0,0,3,0,80,1,true);  

//Equipment type Staff one hand "A" (name? ,0 ,5 ,1,4 ,0,0,0,0,0,5 ,0,0,3,0,85,1,false); 
//Equipment type Staff one hand "B" (name? ,0 ,10,1,6 ,0,0,0,0,0,10,0,0,3,0,85,1,false); 
//Equipment type Staff one hand "C" (name? ,0 ,15,1,8 ,0,0,0,0,0,15,0,0,3,0,85,1,false); 
//Equipment type Staff one hand "D" (name? ,0 ,20,1,10,0,0,0,0,0,20,0,0,3,0,85,1,false); 
 



