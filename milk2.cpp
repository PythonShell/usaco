/*
ID: pythons1
PROG: milk2
LANG: C++
*/
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

bool Add(int &start1, int &end1, int &start2, int &end2);

int main() {
	ofstream fout("milk2.out");
	ifstream fin("milk2.in");
	int n;
	fin >> n;
	bool res = true;
	int * start, * end, * max, * gap, tempMax = 0, tempGap = 0;
	int *postStart, *postEnd;
	start = new int[n];
	end = new int[n];
	for(int i=0; i<n; i++)
		fin >> start[i] >> end[i];

	for(int i=n-1; i>0; i--)
		for(int j=i-1; j>=0; j--)
			if(Add(start[j], end[j], start[i], end[i])) {
				break;
			}

	int count = 0;
	for(int i=0; i<n; i++)
		if(start[i]==-1)
			count++;
	count = n - count;

	postStart = new int[count];
	postEnd = new int[count];
	max = new int[count];
	gap = new int[count];

	int index = 0;
	for(int i=0; i<n; i++)
		if(start[i]!=-1) {
			postStart[index] = start[i];
			postEnd[index] = end[i];
			index++;
		}

	for(int i=0; i<count; i++) {
		max[i] = postEnd[i] - postStart[i];
	}

	for(int i=0; i<count; i++) {
		gap[i] = 1000000;
		for(int j=0; j<count; j++) {
			int temp = postStart[j] - postEnd[i];
			if(temp>0)
				gap[i] = gap[i] > temp ? temp : gap[i];
		}
	}

	for(int i=0; i<count; i++)
		tempMax = max[i] > tempMax ? max[i] : tempMax;
	for(int i=0; i<count; i++)
		if(gap[i] != 1000000) tempGap = gap[i] > tempGap ? gap[i] : tempGap;
	if(count==1)
		tempGap = 0;

	fout << tempMax << " " << tempGap << endl;

	delete[] start, end, max, gap;
	return 0;
}


bool Add(int &start1, int &end1, int &start2, int &end2) {
	if(end1 < start2)
		return false;
	else if(end2 < start1)
		return false;
	else if(start1 <= start2 && start2 <= end1) {
		end1 = end1 > end2 ? end1 : end2;
		start2 = -1;
		end2 = -1;
		return true;
	}
	else if(start1 <= end2 && end2 <= end1) {
		start1 = start1 < start2 ? start1 : start2;
		start2 = -1;
		end2 = -1;
		return true;
	}
	else if(start1 >= start2 && end1 <= end2) {
		start1 = start2;
		end1 = end2;
		start2 = -1;
		end2 = -1;
		return true;
	}
	return false;
}