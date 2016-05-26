/*
ID: pythons1
PROG: palsquare
LANG: C++
*/
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

bool IsPal(string str);
string Change(int num, int base);

int main() {
	ofstream fout("palsquare.out");
	ifstream fin("palsquare.in");
	int base;
	fin >> base;
	for(int i=1; i<301; i++) {
		string str = Change(i*i, base);
		if(IsPal(str)) {
			fout << Change(i, base) << " " << Change(i*i, base) << endl;
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
		case 10: str = "A" + str; break;
		case 11: str = "B" + str; break;
		case 12: str = "C" + str; break;
		case 13: str = "D" + str; break;
		case 14: str = "E" + str; break;
		case 15: str = "F" + str; break;
		case 16: str = "G" + str; break;
		case 17: str = "H" + str; break;
		case 18: str = "I" + str; break;
		case 19: str = "J" + str; break;
		default: break;
		}
	}
	return str;
}