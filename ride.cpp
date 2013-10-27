/*
ID: pythons1
PROG: ride
LANG: C++
*/
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main() {
	ofstream fout("ride.out");
	ifstream fin("ride.in");
	string str1, str2;
	int num1=1, num2=1;
	fin >> str1 >> str2;
	for(int i=0; i<str1.length(); i++)
		num1 *= static_cast<int>(str1[i]) - 64;
	for(int i=0; i<str2.length(); i++)
		num2 *= static_cast<int>(str2[i]) - 64;
	num1 = num1 % 47;
	num2 = num2 % 47;
	if(num1 == num2)
		fout << "GO\n";
	else
		fout << "STAY\n";
	return 0;
}
