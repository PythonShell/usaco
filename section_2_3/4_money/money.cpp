/*
ID: pythons1
PROG: money
LANG: C++
*/
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

//void output(vector<vector<long long> > results) {
//    for(int i=0; i<results.size(); ++i) {
//        for(int j=0; j<results[0].size(); ++j) {
//            cout << results[i][j] << " ";
//        }
//        cout << endl;
//    }
//    cout << endl;
//}

int main() {
    int V, N, temp;
    vector<int> moneySystem;

    ifstream fin("money.in");
    fin >> V >> N;
    for(int i=0; i<V; ++i) {
        fin >> temp;
        moneySystem.push_back(temp);
    }
    fin.close();
    sort(moneySystem.begin(), moneySystem.end());

    vector<vector<long long> > results;
    for(int money=1; money <= N; ++ money) {
        vector<long long> record;
        if(money % moneySystem[0]==0) record.push_back(1);
        else record.push_back(0);
        for(int n=1; n<V; ++n) {
            long long r=record.back();
            int value = money;
            while(value>=moneySystem[n]) {
                value = value - moneySystem[n];
                if(value==0) r += 1;
                else r += results[value-1][n-1];
            }
            record.push_back(r);
        }
        results.push_back(record);
        //cout << results.size() << endl;
        //output(results);
    }

    long long result = results[N-1][V-1];
    ofstream fout("money.out");
    fout << result << endl;
    fout.close();
    return 0;
}
