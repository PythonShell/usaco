/*
ID: pythons1
PROG: milk
LANG: C++
*/
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

void Sort(int *price, int *limit, int low, int high);

int main() {
	ofstream fout("milk.out");
	ifstream fin("milk.in");
	int total, n, *price, *limit, t=0, p=0;
	fin >> total >> n;
	price = new int[n];
	limit = new int[n];
	for(int i=0; i<n; i++)
		fin >> price[i] >> limit[i];
	Sort(price, limit, 0, n);
	for(int i=0; t<total; i++) {
		if(t+limit[i] < total) {
			p += limit[i]*price[i];
			t = t+limit[i];
		}
		else {
			p += price[i]*(total-t);
			t = total;
		}
	}
	fout << p << endl;
	delete[] price, limit;
	return 0;
}

void Sort(int *price, int *limit, int low, int high) {
	int i, j, temp, l;
	if(low<high) {
		i = low;
		j = high;
		temp = price[i];
		l = limit[i];
		while(i<j) {
			while(i<j && price[j] > temp)
				j--;
			if(i<j) {
				price[i++]=price[j];
				limit[i-1]=limit[j];
			}
			while(i<j && price[i] < temp)
				i++;
			if(i<j) {
				price[j--]=price[i];
				limit[j+1]=limit[i];
			}
		}
		price[i] = temp;
		limit[i] = l;
		Sort(price, limit, low, i-1);
		Sort(price, limit, i+1, high);
	}
}