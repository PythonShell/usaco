/*
ID: pythons1
PROG: pprime
LANG: C++
*/
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

vector<int> pal(int begin, int end);
bool prime(int num);

int main() {
	ofstream fout("pprime.out");
	ifstream fin("pprime.in");
	int a, b;
	fin >> a >> b;
	vector<int> answer = pal(a, b);
	for(int i=0; i<answer.size(); i++)
		if( !prime(answer[i]) )
		{
			answer.erase(answer.begin()+i);
			i--;
		}

	for(int i=0; i<answer.size(); i++)
		fout << answer[i] << endl;
	return 0;
}

bool prime(int num)
{
	int lim = sqrt(num) + 1;
	for(int i=2; i<lim ; i++)
		if(num%i==0)
			return false;
	return true;
}

vector<int> pal(int begin, int end)
{
	vector<int> result;
	for(int d1=1; d1<=9; d1+=2)
	{
		result.push_back(d1);
		result.push_back(11*d1);
		for(int d2=0; d2<=9; d2++)
		{
			result.push_back(101*d1+10*d2);
			result.push_back(1001*d1+110*d2);
			for(int d3=0; d3<=9; d3++)
			{
				result.push_back(10001*d1+1010*d2+100*d3);
				result.push_back(100001*d1+10010*d2+1100*d3);
				for(int d4=0; d4<=9; d4++)
				{
					result.push_back(1000001*d1+100010*d2+10100*d3+1000*d4);
					result.push_back(10000001*d1+1000010*d2+100100*d3+11000*d4);
				}
			}
		}
	}
	sort(result.begin(), result.end());
	for(int i=0; i<result.size(); i++)
		if(result[i] < begin || result[i] > end)
		{
			result.erase(result.begin()+i);
			i--;
		}
	return result;
}
