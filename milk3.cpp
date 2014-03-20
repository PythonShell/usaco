/*
D: pythons1
PROG: milk3
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>	// sort()
#include <cstdio>	// sprintf() 

using namespace std;

vector< vector<int> > pour_once(vector<int> v, int a, int b, int c);
bool check_it(vector<int> v, vector< vector<int> > v_base);
bool sort_func(vector<int> v1, vector<int> v2);

int main() {
	vector< vector<int> > result;
	queue< vector<int> > mid;
	ofstream fout("milk3.out");
	ifstream fin("milk3.in");

	int a, b, c;
	fin >> a >> b >> c;
	vector<int> ini;
	ini.push_back(0);
	ini.push_back(0);
	mid.push(ini);

	while(mid.size())
	{
		vector<int> tmp = mid.front();
		mid.pop();
		vector< vector<int> > mid_res = pour_once(tmp, a, b, c);
		for(int i=0; i<mid_res.size(); i++)
		{
			if( !check_it(mid_res[i], result) )
			{
				result.push_back(mid_res[i]);
				mid.push(mid_res[i]);
			}
		}
	}

	sort(result.begin(), result.end(), sort_func);
	string answer = "";
	char buffer[4];
	for(int i=0; i<result.size(); i++)
	{
		if(!result[i][0])
		{
			int tmp = c - result[i][1];
			sprintf(buffer, "%d", tmp);
			answer += buffer;
			answer += " ";
		}
	}
	int len = answer.length();
	answer.erase(len-1,1);
	fout << answer << endl;
	return 0;
}

vector< vector<int> > pour_once(vector<int> v, int a, int b, int c)
{
        vector< vector<int> > ans;
        int a_beg = v[0], b_beg = v[1], c_beg = (c-v[0]-v[1]), a_end, b_end;
        if(a_beg)
        {
                // pour a
                if(b_beg!=b)
                {
                        // to b
                        if(a_beg<(b-b_beg))
                        {
                                a_end = 0;
                                b_end = b_beg + a_beg;
                                vector<int> tmp;
                                tmp.push_back(a_end);
                                tmp.push_back(b_end);
                                ans.push_back(tmp);
                        }
                        else
                        {
                                a_end = a_beg - (b-b_beg);
                                b_end = b;
                                vector<int> tmp;
                                tmp.push_back(a_end);
                                tmp.push_back(b_end);
                                ans.push_back(tmp);
                        }
                }
                if(c_beg!=c)
                {
                        // to c
                        if(a_beg<(c-c_beg))
                        {
                                a_end = 0;
                                b_end = b_beg;
                                vector<int> tmp;
                                tmp.push_back(a_end);
                                tmp.push_back(b_end);
                                ans.push_back(tmp);
                        }
                        else
                        {
                                a_end = a_beg - (c-c_beg);
                                b_end = b_beg;
                                vector<int> tmp;
                                tmp.push_back(a_end);
                                tmp.push_back(b_end);
                                ans.push_back(tmp);
                        }
                }
        }
        if(b_beg)
        {
                // pour b
                if(a_beg!=a)
                {
                        // to a
                        if(b_beg<(a-a_beg))
                        {
                                b_end = 0;
                                a_end = a_beg + b_beg;
                                vector<int> tmp;
                                tmp.push_back(a_end);
                                tmp.push_back(b_end);
                                ans.push_back(tmp);
                        }
                        else
                        {
                                a_end = a;
                                b_end = b_beg - (a-a_beg);
                                vector<int> tmp;
                                tmp.push_back(a_end);
                                tmp.push_back(b_end);
                                ans.push_back(tmp);
                        }
                }
                if(c_beg!=c)
                {
                        // to c
                        if(b_beg<(c-c_beg))
                        {
                                a_end = a_beg;
                                b_end = 0;
                                vector<int> tmp;
                                tmp.push_back(a_end);
                                tmp.push_back(b_end);
                                ans.push_back(tmp);
                        }
                        else
                        {
                                a_end = a_beg;
                                b_end = b_beg - (c-c_beg);
                                vector<int> tmp;
                                tmp.push_back(a_end);
                                tmp.push_back(b_end);
                                ans.push_back(tmp);
                        }
                }
        }
        if(c_beg)
        {
                // pour c
                if(a_beg!=a)
                {
                        // to a
                        if(c_beg<(a-a_beg))
                        {
                                a_end = a_beg + c_beg;
                                b_end = b_beg;
                                vector<int> tmp;
                                tmp.push_back(a_end);
                                tmp.push_back(b_end);
                                ans.push_back(tmp);
                        }
                        else
                        {
                                a_end = a;
                                b_end = b_beg;
                                vector<int> tmp;
                                tmp.push_back(a_end);
                                tmp.push_back(b_end);
                                ans.push_back(tmp);
                        }
                }
                if(b_beg!=b)
                {
                        // to b
                        if(c_beg<(b-b_beg))
                        {
                                a_end = a_beg;
                                b_end = b_beg + c_beg;
                                vector<int> tmp;
                                tmp.push_back(a_end);
                                tmp.push_back(b_end);
                                ans.push_back(tmp);
                        }
                        else
                        {
                                a_end = a_beg;
                                b_end = b;
                                vector<int> tmp;
                                tmp.push_back(a_end);
                                tmp.push_back(b_end);
                                ans.push_back(tmp);
                        }
                }
        }

        return ans;
}

bool check_it(vector<int> v, vector< vector<int> > v_base)
{
        for(int i=0; i<v_base.size(); i++)
                if(v_base[i][0]==v[0] && v_base[i][1]==v[1])
                        return true;
        return false;
}

bool sort_func(vector<int> v1, vector<int> v2)
{
        return v1[1]>v2[1];
}
