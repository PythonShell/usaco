/*
ID: pythons1
PROG: gift1
LANG: C++
*/
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class Person{
public:
	void SetName(string nm) {name = nm;};
	string GetName() {return name;};
	void SetMoney(int mon) {money = mon; postMoney=0;};
	int GetMoney() {return money;};
	void SetFriNum(int fri) {jIndex=0;friNum = fri; friList = new Person*[friNum];};
	int GetFriNum() {return friNum;};
	void SetFri(string nm, Person* p, int n);
	string GetFri();
	int GetPostMoney() {return postMoney;};

	void ReMoney(int amount);
	void SendMoney();
private:
	string name;
	int money;
	int friNum;
	Person **friList;
	int jIndex;
	int postMoney;
};

int main() {
	ofstream fout("gift1.out");
	ifstream fin("gift1.in");
	int number;
	fin >> number;
	Person per[number];
	string tempName;
	int tempMoney, tempFriNum;
	Person* tempPer;
	for(int i=0; i<number; i++) {
		fin >> tempName;
		per[i].SetName(tempName);
	}
	for(int i=0; i<number; i++){
		fin >> tempName >> tempMoney >> tempFriNum;
		for(int k=0; k<number; k++) {
			if(per[k].GetName()==tempName) {
				tempPer = per+k;
			}
		}
		tempPer->SetMoney(tempMoney);
		tempPer->SetFriNum(tempFriNum);
		if(tempFriNum!=0){
			for(int j=0;j<tempFriNum;j++){
				fin >> tempName;
				tempPer->SetFri(tempName, per, number);
			}
		}
	}
	for(int i=0; i<number; i++)
		per[i].SendMoney();
	for(int i=0; i<number; i++) {
		fout << per[i].GetName() << " " << per[i].GetPostMoney() << endl;
	}
}

void Person::SetFri(string nm, Person* p, int n) {
	for(int i=0; i<n; i++) {
		if(nm==p[i].GetName()){
			friList[jIndex] = p+i;
			jIndex++;
		}
	}
}

string Person::GetFri() {
	if(friNum==0) {
		return this->name;
	}
	string tempString = "";
	for(int i=0; i<friNum; i++) {
		tempString += " ";
		tempString += friList[i]->GetName();
	}
	return tempString;
}

void Person::ReMoney(int amount) {
	postMoney +=amount;
}

void Person::SendMoney() {
	if (friNum==0)
		return;
	int tempMoney = money / friNum;
	postMoney -= tempMoney*friNum;
	for(int i=0; i<friNum; i++) {
		friList[i]->ReMoney(tempMoney);
	}
}