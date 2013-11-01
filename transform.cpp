/*
ID: pythons1
PROG: transform
LANG: C++
*/
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

void T1(string *str1, string *str2, int size);
void T2(string *str1, string *str2, int size);
void T3(string *str1, string *str2, int size);
void T4(string *str1, string *str2, int size);
bool T5(string *str1, string *str2, int size);
bool T6(string *str1, string *str2, int size);

int main() {
	ofstream fout("transform.out");
	ifstream fin("transform.in");
	int n;
	fin >> n;
	string * str1, * str2, * str3;
	str1 = new string[n];
	str2 = new string[n];
	str3 = new string[n];
	for(int i=0; i<n; i++)
		fin >> str1[i];
	for(int i=0; i<n; i++)
		fin >> str2[i];
	T1(str1, str3, n);
	if(T6(str2, str3, n))
		fout << 1 << endl;
	else {
		T2(str1, str3, n);
		if(T6(str2, str3, n))
			fout << 2 << endl;
		else {
			T3(str1, str3, n);
			if(T6(str2, str3, n))
				fout << 3 << endl;
			else {
				T4(str1, str3, n);
				if(T6(str2, str3, n))
					fout << 4 << endl;
				else if(T5(str1, str2, n))
					fout << 5 << endl;
				else if(T6(str1, str2, n))
					fout << 6 << endl;
				else
					fout << 7 << endl;
			}
		}
	}
	return 0;
}

void T1(string *str1, string *str2, int size) {
	string * temp1, *temp2;
	temp1 = new string[size];
	temp2 = new string[size];
	T3(str1, temp1, size);
	T3(temp1, temp2, size);
	T3(temp2, str2, size);
	delete[] temp1, temp2;
}

void T2(string *str1, string *str2, int size) {
	string * temp;
	temp = new string[size];
	T3(str1, temp, size);
	T3(temp, str2, size);
	delete[] temp;
}

void T3(string *str1, string *str2, int size) {
	for(int i=0; i<size; i++)
		str2[i] = "";
	for(int i=0; i<size; i++) {
		for(int j=0; j<size; j++) {
			str2[size-1-j] += str1[i][j];
		}
	}
}

void T4(string *str1, string *str2, int size) {
	for(int i=0; i<size; i++)
		str2[i] = "";
	for(int i=0; i<size; i++) {
		for(int j=0; j<size; j++)
			str2[i] += str1[i][size-1-j];
	}
}

bool T5(string *str1, string *str2, int size) {
	string *temp1, *temp2, *temp3, *temp4;
	temp1 = new string[size];
	temp2 = new string[size];
	temp3 = new string[size];
	temp4 = new string[size];
	T4(str1, temp1, size);
	T1(temp1, temp2, size);
	bool result = T6(str2, temp2, size);
	if(!result) {
		T1(temp2, temp3, size);
		result = T6(str2, temp3, size);
		if(!result) {
			T1(temp3, temp4, size);
			result = T6(str2, temp4, size);
		}
	}
	delete[] temp1, temp2, temp3, temp4;
	return result;
}

bool T6(string *str1, string *str2, int size) {
	bool flag = true;
	for(int i=0; i<size; i++) {
		flag *= (str1[i]==str2[i]);
	}
	return flag;
}