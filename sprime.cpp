/*
ID: pythons1
PROG: sprime
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

bool prime(int num);
vector<int> get(int n);

int main() {
	ofstream fout("sprime.out");
	ifstream fin("sprime.in");
	int len;
	fin >> len;

	vector<int> res = get(len);
	for(int i=0; i<res.size(); i++)
		fout << res[i] << endl;
	return 0;
}

bool prime(int num)
{
	if(num==2)
		return true;
	for(int i=2; i<sqrt(num)+1; i++)
		if(num%i==0)
			return false;
	return true;
}

vector<int> get(int n)
{
	if(n==1)
	{
		vector<int> ans;
		ans.push_back(2);
		ans.push_back(3);
		ans.push_back(5);
		ans.push_back(7);

		return ans;
	}
	vector<int> tmp = get(n-1);
	vector<int> result;
	for(int i=0; i<tmp.size(); i++)
	{
		int temp = tmp[i]*10+1;
		for(int j=0; j<5; j++)
		{
			if(prime(temp))
				result.push_back(temp);
			temp += 2;
		}
	}
	return result;
}

