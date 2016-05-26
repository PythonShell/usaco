/*
ID: pythons1
PROG: beads
LANG: C++
*/
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

void Prev(string str, int size, int n, int *sum);
void Post(string str, int size, int n, int *sum);
int Max(int *sum, int size);

int main() {
	ofstream fout("beads.out");
	ifstream fin("beads.in");
	int n, *sum;
	fin >> n;
	sum = new int[4*n];
	for(int i=0; i<4*n; i++) sum[i] = 0;
	string str, strC;
	fin >> str;
	strC = str + str + str;
	string strR, strB;
	strR = strC;
	strB = strC;
	for(int i=0; i<3*n; i++) {
		if(strC[i]=='w') {
			strR[i] = 'r';
			strB[i] = 'b';
		}
	}
	for(int i=0; i<n; i++) {
		Prev(strR, n, n+i, sum);
		Post(strR, n, n+i, sum);
	}
	for(int i=0; i<n; i++) {
		Prev(strB, n, n+i, sum+n);
		Post(strB, n, n+i, sum+n);
	}
	for(int i=0; i<n; i++) {
		Prev(strR, n, n+i, sum+2*n);
		Post(strB, n, n+i, sum+2*n);
	}
	for(int i=0; i<n; i++) {
		Prev(strB, n, n+i, sum+3*n);
		Post(strR, n, n+i, sum+3*n);
	}
	if(Max(sum, 4*n) > n)
		fout << n <<endl;
	else
		fout << Max(sum, 4*n) << endl;
	delete[] sum;
	return 0;
}

void Prev(string str, int size, int n, int *sum) {
  int index = n;
	sum[n-size]++;
	while(str[index-1] == str[index-2]) {
		sum[n-size]++;
		index--;
		if(index == 2 || index == 3*size-2) break;
	}
}

void Post(string str, int size, int n, int *sum) {
	int index = n;
	sum[n-size] += 1;
	while(str[index] == str[index+1]) {
		sum[n-size]++;
		index++;
		if(index == 2 || index == 3*size-2) break;
	}
}

int Max(int *sum, int size) {
	int temp = 0;
	for(int i=0; i<size; i++){
		if(sum[i]>temp)
			temp = sum[i];
	}
	return temp;
}
