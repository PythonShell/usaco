/*
ID: pythons1
PROG: clocks
LANG: C++
*/
#include<iostream>
#include<fstream>
#include<string>
#include<cstdio>	// sprintf()
using namespace std;


void spin(int &a, int i) {
}

int main() {
	ofstream fout("clocks.out");
	ifstream fin("clocks.in");
	const long move[9] = {18911232, 19136512, 2363904, 16810048, 2134536, 262657, 36936, 73, 4617};
	int a = 0;
	int times[9], f[9];
	bool result = true;
	for(int i=0; i<9; i++) {
		int temp;
		fin >> temp;
		temp = (temp/3)%4;
		a = (a << 3) + temp;
	}
	for(times[0]=0; times[0]<4; times[0]++)
	for(times[1]=0; times[1]<4; times[1]++)
	for(times[2]=0; times[2]<4; times[2]++)
	for(times[3]=0; times[3]<4; times[3]++)
	for(times[4]=0; times[4]<4; times[4]++)
	for(times[5]=0; times[5]<4; times[5]++)
	for(times[6]=0; times[6]<4; times[6]++)
	for(times[7]=0; times[7]<4; times[7]++)
	for(times[8]=0; times[8]<4; times[8]++)
	{
		int temp = a;
		for(int i=0; i<9; i++)
			for(int j=0; j<times[i]; j++)
				temp = (temp + move[i]) & 57521883;
		if (temp==0 && result)
		{
			result = false;
			for(int i=0; i<9; i++)
				f[i] = times[i];
		}
	}
	char buffer[1];
	string answer("");
	for(int i=0; i<9; i++)
		for(int j=0; j<f[i]; j++)
		{
			sprintf(buffer, "%d", i+1);
			answer += buffer;
			answer += " ";
		}
	int len = answer.length();
	answer.erase(len-1,1);
	fout << answer << endl;
	return 0;
}
