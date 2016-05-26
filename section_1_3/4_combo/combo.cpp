/*
ID: pythons1
PROG: combo
LANG: C++
*/
#include<iostream>
#include<fstream>
#include<string>
#include<list>
#include<vector>
using namespace std;

typedef vector<int> solve;

list<solve> getCombine( solve, int );

int main() {
	ofstream fout("combo.out");
	ifstream fin("combo.in");
    // ifstream fin("combo.in2");
	int n, tmp, total;
    solve farmer, master;
    list<solve> f_result, m_result;

	fin >> n;
    for (int i=0; i<3; i++) {
        fin >> tmp;
        farmer.push_back(tmp);
    }
    for (int i=0; i<3; i++) {
        fin >> tmp;
        master.push_back(tmp);
    }

    f_result = getCombine( farmer, n );
    m_result = getCombine( master, n );
    f_result.merge( m_result );
    f_result.sort();
    f_result.unique();
    total = f_result.size();

    /* Debug
    for(list<solve>::iterator it = f_result.begin();
            it != f_result.end();
            it ++) {
        cout << "(" << it->at(0) << " "
            << it->at(1) << " "
            << it->at(2) << ")";
    }
    cout << endl; */

    fout << total << endl;
	return 0;
}

list<solve> getCombine(solve input, int n) {
    list<solve> res;
    solve tmp;
    tmp.push_back(0);
    tmp.push_back(0);
    tmp.push_back(0);
    int x[5], y[5], z[5];
    for (int i=0; i<5; i++) {
        x[i] = (input[0] +n+i-2)%n;
        if(!x[i]) x[i]=n;
        y[i] = (input[1] +n+i-2)%n;
        if(!y[i]) y[i]=n;
        z[i] = (input[2] +n+i-2)%n;
        if(!z[i]) z[i]=n;
    }
    for(int i=0; i<5; i++) {
        tmp[0] = x[i];
        for(int j=0; j<5; j++) {
            tmp[1] = y[j];
            for(int k=0; k<5; k++) {
                tmp[2] = z[k];
                res.push_back(tmp);
            }
        }
    }
    return res;
}

