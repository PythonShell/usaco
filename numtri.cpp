/*
ID: pythons1
PROG: numtri
LANG: C++
*/
#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

void vec_add(vector<int> &v_s, vector<int> &v_l);

int main() {
	ofstream fout("numtri.out");
	ifstream fin("numtri.in");

	int n;
	fin >> n;
	vector< vector<int> > initial;
	for(int i=1; i<=n; i++)
	{
		vector<int> tmp;
		for(int j=0; j<i; j++)
		{
			int temp;
			fin >> temp;
			tmp.push_back(temp);
		}
		initial.push_back(tmp);
	}

	for(int i=n-1; i>0; i--)
	{
		vec_add(initial[i-1], initial[i]);
	}

	fout << initial[0][0] << endl;

	return 0;
}

void vec_add(vector<int> &v_s, vector<int> &v_l)
{
	int size = v_s.size();
	for(int i=0; i<size; i++)
		v_s[i] += ( v_l[i] > v_l[i+1] ? v_l[i] : v_l[i+1] );
}
