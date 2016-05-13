/*
ID: pythons1
PROG: subset
LANG: C++
*/
#include<iostream>
#include<fstream>
#include<vector>
#include<deque>
using namespace std;

int main() {
	ofstream fout("subset.out");
	ifstream fin("subset.in");
    int n;
    fin >> n;
    int sum=n*(n+1)/2;
    if (sum%2) {
        fout << 0 << endl;
        return 0;
    }
    sum /= 2;
    sum -= n;
    // code below is correct but with much more memory
    // killed when input equals 39
    deque<vector<int> > solutions;
    int count=0;
    for(int i=n-1; i>0; --i) {
        vector<int> solution(1, i);
        solutions.push_back(solution);
    }
    while(!solutions.empty()) {
        vector<int> current = solutions.front();
        int tmp_sum=0;
        for(int i=0; i<current.size(); ++i) {
            tmp_sum += current[i];
        }
        if(tmp_sum==sum) ++count;
        solutions.pop_front();
        if(tmp_sum>sum) continue;
        for(int i=current.back()-1; i>0; --i) {
            current.push_back(i);
            solutions.push_back(current);
            current.pop_back();
        }
    }
    fout << count << endl;
	return 0;
}
