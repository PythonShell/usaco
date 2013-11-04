/*
ID: pythons1
PROG: dualpal
LANG: C++
*/
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

bool IsPal(string str);
string Change(int num, int base);
bool DoublePal(int num);

int main() {
	ofstream fout("dualpal.out");
	ifstream fin("dualpal.in");
	int n, i, count=0;
	fin >> n >> i;
	for(i = i+1; count<n; i++) {
		if(DoublePal(i)) {
			count++;
			fout << i << endl;
		}
	}
	return 0;
}

bool IsPal(string str) {
	int len = str.length();
	bool result = true;
	for(int i=0; i<((len/2)+1); i++)
		if(str[i]!=str[len-1-i]) result *= false;
	return result;
}

string Change(int num, int base) {
	string str = "";
	int temp = num, lef = 0;
	while(temp!=0) {
		lef = temp % base;
		temp = temp / base;
		switch(lef) {
		case 0: str = "0" + str; break;
		case 1: str = "1" + str; break;
		case 2: str = "2" + str; break;
		case 3: str = "3" + str; break;
		case 4: str = "4" + str; break;
		case 5: str = "5" + str; break;
		case 6: str = "6" + str; break;
		case 7: str = "7" + str; break;
		case 8: str = "8" + str; break;
		case 9: str = "9" + str; break;
		default: break;
		}
	}
	return str;
}


bool DoublePal(int num) {
	int n=0;
	for(int base=2; base<11; base++) {
		if(IsPal(Change(num, base))) n++;
		if(n==2) return true;
	}
	return false;
}