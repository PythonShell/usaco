/*
ID: pythons1
PROG: hamming
LANG: C++
*/
#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

inline short getHammingDistance(int a, int b) {
    int c = a ^ b;
    short r = 0;
    while(c!=0) {
        if (c&1) ++r;
        c = c >> 1;
    }
    return r;
}

int main() {
	ofstream fout("hamming.out");
	ifstream fin("hamming.in");
    short N, B, D;
    fin >> N >> B >> D;
    // test wether getHammingDistance is correct
    // cout << getHammingDistance(0x554, 0x234) << endl;
    vector<int> result;
    result.push_back(0);
    for(int i=0; i<(1<<B); ++i) {
        bool continue_flag = false;
        for(int j=0, length=result.size(); j<length; ++j) {
            if( getHammingDistance(i, result[j]) < D ) {
                continue_flag = true;
                break;
            }
        }
        if (continue_flag) continue;
        result.push_back(i);
        if (result.size()==N) break;
    }
    for(int i=0; i<N-1; ++i) {
        fout << result[i];
        if((i+1)%10==0) fout << endl;
        else fout << " ";
    }
    fout << result[N-1] << endl;
	return 0;
}
