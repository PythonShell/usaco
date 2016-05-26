/*
ID: pythons1
PROG: ariprog
LANG: C++
*/
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>	// sort()

#define LIM 125001
using namespace std;

bool sort_func_1(vector<int> v1, vector<int> v2);
bool sort_func_2(vector<int> v1, vector<int> v2);

int main() {
	vector< vector<int> > result;
	ofstream fout("ariprog.out");
	ifstream fin("ariprog.in");

	int n, m, a, b;
	fin >> n >> m;
	int lim = 2*m*m;
	bool stat[LIM] = {false};

	for(int i=0; i<=m; i++)
		for(int j=0; j<=m; j++)
			stat[i*i+j*j]=true;

	//int size = 0;
	//for(int i=0; i<=lim; i++)
	//	size += stat[i];
	//if(size<n)
	//{
	//	fout << "NONE" << endl;
	//	return 0;
	//}
	for(int i=0; i<=lim ; i++)
	{
		if (stat[i])
		{
			int b_max = (lim-i)/(n-1) + 1;
			for(b=1; b<b_max; b++)
			{
				bool flag = true;
				for(int j=1; j<n; j++)
					flag *= stat[i+j*b];
				if(flag)
				{
					vector<int> temp;
					temp.push_back(i);
					temp.push_back(b);
					result.push_back(temp);
				}
			}
		}
	}


	sort(result.begin(), result.end(), sort_func_1);
	sort(result.begin(), result.end(), sort_func_2);

	if(result.size())
		for(int i=0; i<result.size(); i++)
			fout << result[i][0] << " " << result[i][1] << endl;
	else
		fout << "NONE" << endl;
	return 0;
}

bool sort_func_1(vector<int> v1, vector<int> v2)
{
	return v1[0]<v2[0];
}

bool sort_func_2(vector<int> v1, vector<int> v2)
{
	return v1[1]<v2[1];
}
