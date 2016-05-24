/*
ID: pythons1
PROG: lamps
LANG: C++11
*/
#include<iostream>
#include<fstream>
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
    int n, c;
    fin >> n >> c;
    unsigned __int128 filter = (unsigned __int128)(1) << (n-1);
    unsigned __int128 OPER_1=0;
    OPER_1 = ~OPER_1;
    unsigned __int128 OPER_2=0;
    for(int i=0; i<64; ++i) {
        OPER_2 |= ((unsigned __int128)(1) << (i*2));
    }
    unsigned __int128 OPER_3=0;
    OPER_3 = ~OPER_2;
    unsigned __int128 OPER_4=0;
    for(int i=0; i<40; ++i) {
        OPER_4 |= ((unsigned __int128)(1) << (i*3));
    }
#ifdef DEBUG
    unsigned __int128 tt = OPER_1;
    for(int i=0; i<128; ++i) {
        if(tt & 1) cout << 1;
        else cout << 0;
        tt = tt >> 1;
    } cout << endl;
    tt = OPER_2;
    for(int i=0; i<128; ++i) {
        if(tt & 1) cout << 1;
        else cout << 0;
        tt = tt >> 1;
    } cout << endl;
    tt = OPER_3;
    for(int i=0; i<128; ++i) {
        if(tt & 1) cout << 1;
        else cout << 0;
        tt = tt >> 1;
    } cout << endl;
    tt = OPER_4;
    for(int i=0; i<128; ++i) {
        if(tt & 1) cout << 1;
        else cout << 0;
        tt = tt >> 1;
    } cout << endl;
#endif
    int tmp;
    unsigned __int128 onConfig=0;
    unsigned __int128 offConfig=0;
    while(1) {
        fin >> tmp;
        if(tmp<0) break;
        onConfig |= ((unsigned __int128)(1) << (tmp-1));
    }
    while(1) {
        fin >> tmp;
        if(tmp<0) break;
        offConfig |= ((unsigned __int128)(1) << (tmp-1));
    }
    unsigned __int128 initial = 0;
    initial = ~initial;
    vector<unsigned __int128> result;
    if(c==0) {
        result.push_back(initial);
    }
    else if (c==1) {
        result.push_back(initial ^ OPER_1);
        result.push_back(initial ^ OPER_2);
        result.push_back(initial ^ OPER_3);
        result.push_back(initial ^ OPER_4);
    }
    else if( c==2) {
        result.push_back(initial);
        result.push_back(initial ^ OPER_1);
        result.push_back(initial ^ OPER_2);
        result.push_back(initial ^ OPER_3);
        result.push_back((initial ^ OPER_1) ^ OPER_4);
        result.push_back((initial ^ OPER_2) ^ OPER_4);
        result.push_back((initial ^ OPER_3) ^ OPER_4);
    } else {
        result.push_back(initial);
        result.push_back(initial ^ OPER_1);
        result.push_back(initial ^ OPER_2);
        result.push_back(initial ^ OPER_3);
        result.push_back(initial ^ OPER_4);
        result.push_back((initial ^ OPER_1) ^ OPER_4);
        result.push_back((initial ^ OPER_2) ^ OPER_4);
        result.push_back((initial ^ OPER_3) ^ OPER_4);
    }
    vector<unsigned __int128> final_result;
    for(int j=0; j<result.size(); ++j) {
        unsigned __int128 current = result[j];
        if(~current & onConfig) continue;
        if(current & offConfig) continue;
        unsigned __int128 tmp = 0;
        for(int i=0; i<n; ++i) {
            if(current & 1) tmp = (tmp << 1) + 1;
            else tmp = tmp << 1;
            current = current >> 1;
        }
        final_result.push_back(tmp);
    }
    if(final_result.size()==0) {
        fout << "IMPOSSIBLE" << endl;
        return 0;
    }
    sort(final_result.begin(), final_result.end());
    for(int j=0; j<final_result.size(); ++j) {
        unsigned __int128 current = final_result[j];
        for(int i=0; i<n; ++i) {
            if(current & filter) fout << 1;
            else fout << 0;
            current = current << 1;
        } fout << endl;
    }
    return 0;
}

