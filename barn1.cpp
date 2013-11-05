/*
ID: pythons1
PROG: barn1
LANG: C++
*/
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

void QuickSort(int *arr, int low, int high);

int main() {
	ofstream fout("barn1.out");
	ifstream fin("barn1.in");
	int boardn, total, num, temp, max, min;
	bool *nm;
	fin >> boardn >> total >> num;
	nm = new bool[total];
	max = 0;
	min = total;
	for(int i=0; i<total; i++)
		nm[i] = false;
	for(int i=0; i<num; i++) {
		fin >> temp;
		max = max > temp ? max : temp;
		min = min > temp ? temp : min;
		nm[temp] = true;
	}
	int index=0;
	int *len = new int[total];
	for(int i=0; i<total; i++) {
		len[i] = 0;
	}
	bool flag=true;
	for(int i=min; i<=max; i++) {
		if(nm[i]==true && flag==true) {
			index++;
			flag=false;
		}
		if(nm[i]==false && flag==false) {
			flag = true;
		}
		if (nm[i]==false && flag==true) {
			len[index]++;
		}
	}
	QuickSort(len, 0, total-1);
	int length = max-min+1;
	for(int i=0; i<( (boardn-1) > total ? total-1 : (boardn-1) ); i++) {
		length -=len[i];
	}
	fout << length << endl;
	delete[] nm;
	return 0;
}

void QuickSort(int *arr, int low, int high) {
	int i, j, temp;
	if(low<high) {
		i=low; j=high; temp=arr[i];
		while(i<j) {
			while(i<j && arr[j]<temp) j--;
			if(i<j) arr[i++]=arr[j];
			while(i<j && arr[i]>temp) i++;
			if(i<j) arr[j--]=arr[i];
		}
		arr[i] = temp;
		QuickSort(arr, low, i-1);
		QuickSort(arr, i+1, high);
	}
}