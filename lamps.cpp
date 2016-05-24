/*
ID: pythons1
PROG: lamps
LANG: C++11
*/
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

// #define DEBUG

/*
#define OPER_1 (unsigned __int128)(0xFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF)
#define OPER_2 (unsigned __int128)(0x5555555555555555555555555555555555555555)
#define OPER_3 (unsigned __int128)(0xAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA)
#define OPER_4 (unsigned __int128)(0x9249249249249249249249249249249249249249)
*/


int main() {
    ofstream fout("lamps.out");
    ifstream fin("lamps.in");
    vector<string> situations;
    situations.push_back(string("1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111"));
    situations.push_back(string("0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"));
    situations.push_back(string("0101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101"));
    situations.push_back(string("1010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010"));
    situations.push_back(string("0110110110110110110110110110110110110110110110110110110110110110110110110110110110110110110110110110"));
    situations.push_back(string("1001001001001001001001001001001001001001001001001001001001001001001001001001001001001001001001001001"));
    situations.push_back(string("1100011100011100011100011100011100011100011100011100011100011100011100011100011100011100011100011100"));
    situations.push_back(string("0011100011100011100011100011100011100011100011100011100011100011100011100011100011100011100011100011"));
    int n, c;
    fin >> n >> c;
    for(int i=0; i<8; ++i) {
        situations[i].resize(n);
    }
    int tmp;
    vector<int> onConfig;
    vector<int> offConfig;
    while(1) {
        fin >> tmp;
        if(tmp<0) break;
        onConfig.push_back(tmp);
    }
    while(1) {
        fin >> tmp;
        if(tmp<0) break;
        offConfig.push_back(tmp);
    }
    fin.close();
    if(c==0) {
        situations.resize(1);
    }
    else if (c==1) {
        situations.resize(5);
        situations.erase(situations.begin());
    }
    else if (c==2) {
        situations.erase(situations.begin()+4);
    }
    for(int i=situations.size()-1; i>-1; --i) {
        bool flag = false;
        for(int j=0; j<onConfig.size(); ++j) {
            if(situations[i][onConfig[j]-1]!='1') {
                flag = true;
                break;
            }
        }
        for(int j=0; j<offConfig.size(); ++j) {
            if(situations[i][offConfig[j]-1]!='0') {
                flag = true;
                break;
            }
        }
        if(flag) {
            situations.erase(situations.begin()+i);
        }
    }
    if(situations.size()==0) {
        fout << "IMPOSSIBLE" << endl;
        return 0;
    }
    sort(situations.begin(), situations.end());
    for(int j=0; j<situations.size(); ++j) {
        fout << situations[j] << endl;
    }
    fout.close();
    return 0;
}

