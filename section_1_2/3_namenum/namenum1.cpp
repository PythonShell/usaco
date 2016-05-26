/*
ID: pythons1
PROG: namenum
LANG: C++
*/
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

bool Find(string str1, string *dict, int low, int high);
void Add(string num, string *str, int size, string *ch);

int main() {
	ofstream fout("namenum.out");
	ifstream fin("namenum.in"), findict("dict.txt");
	string ch[24] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "R", "S", "T", "U", "V", "W", "X", "Y"};
	string str1 = "GREG", str2 = "GPDG", *strnum, num;
	string dict[4617];
	for(int i=0; i<4617; i++)
		findict >> dict[i];
	fin >> num;
	int size = 1, len = num.length();
	for(int i=0; i<len; i++) {
		size *= 3;
	}
	strnum = new string[size];
	for(int i=0; i<size; i++)
		strnum[i] = "";
	Add(num, strnum, size, ch);

	bool result = true, flag;

	for(int i=0; i<size; i++) {
		flag = Find(strnum[i], dict, 0, 4617);
		if(flag) {
			fout << strnum[i] << endl;
		}
		result *= !flag;
	}

	//string trmp = "LEA";			//		KIRABO KIRAL KIRBY
	//cout << Find(trmp, dict, 4617) << endl;
	if(result)
		fout << "NONE\n";

	delete[] strnum;
	return 0;
}

bool Find(string str1, string *dict, int low, int high){
	if(low > high)
		return false;
	int mid = (low+high)/2;
	if(str1 == dict[mid])
		return true;
	else if(str1 < dict[mid])
		return Find(str1, dict, low, mid-1);
	else
		return Find(str1, dict, mid+1, high);
}

void Add(string num, string *str, int size, string *ch) {
	if(num.length()==1) {
		int index = num[0]-48;
		for(int i=0; i<3; i++)
			str[i] += ch[(index-2)*3+i];
		return;
	}
	else {
		int index = num[0]-48;
		string numBack = num.substr(1, num.length()-1);
		for(int i=0; i<3; i++) {
			for(int j=0; j<size/3; j++) {
				str[i*(size/3)+j] += ch[(index-2)*3+i];
			}
			Add(numBack, str+(i*(size/3)) , size/3, ch);
		}
	}
}