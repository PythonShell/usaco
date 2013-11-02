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
void Add(string str, string *strCh, int index, int len, string *dict, bool &result, string &asw);

int main() {
	ofstream fout("namenum.out");
	ifstream fin("namenum.in"), findict("dict.txt");
	string ch[24] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "R", "S", "T", "U", "V", "W", "X", "Y"};
	string num, *strCh;
	string dict[4617];
	for(int i=0; i<4617; i++)
		findict >> dict[i];
	fin >> num;
	int len = num.length();
	strCh = new string[3*len];
	for(int i=0; i<len; i++) {
		int index = num[i]-50;
		strCh[i] = ch[index*3];
		strCh[len+i] = ch[index*3+1];
		strCh[len+len+i] = ch[index*3+2];
	}

	string strTemp = "";
	bool result = true;
	string aws = "";
	Add(strTemp, strCh, 0, len, dict, result, aws);

	for(int i=0; i<(aws.length()/len); i++) {
		fout << aws.substr(i*len, len) << endl;
	}
	if(result)
		fout << "NONE\n";
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


void Add(string str, string *strCh, int index, int len, string *dict, bool &result, string &aws) {
	if(index==len) {
		bool flag = Find(str, dict, 0, 4617);
		result *= (!flag);
		if(flag)
			aws += str;
		return;
	}
	for(int j=0; j<3; j++) {
		str += strCh[j*len+index];
		Add(str, strCh, index+1, len, dict, result, aws);
		str = str.substr(0, index);
	}
}