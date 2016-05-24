/*
ID: pythons1
PROG: lamps
LANG: C++
*/
#include<iostream>
#include<fstream>
using namespace std;

#define DEBUG

int main() {
	ofstream fout("lamps.out");
	ifstream fin("lamps.in");
    int n, c;
    fin >> n >> c;
    int tmp;
    unsigned long long onConfig=0;
    unsigned long long offConfig=0;
    while(1) {
        fin >> tmp;
        if(tmp<0) break;
        onConfig |= (unsigned long long(1) << (tmp-1));
    }
    while(1) {
        fin >> tmp;
        if(tmp<0) break;
        offConfig |= (unsigned long long(1) << (tmp-1));
    }
#ifdef DEBUG
    cout << onConfig << endl << offConfig << endl;
#endif
    unsigned long long initial = 0;
    initial = ~initial;
    vector<unsigned long long> result;
    result.push_back(initial);
    cout << endl;
    return 0;
}
