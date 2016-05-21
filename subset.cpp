/*
ID: pythons1
PROG: subset
LANG: C++
*/
#include<iostream>
#include<fstream>
#include<vector>
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
    n = n-1;
    vector<int> counts(sum*n, 0);
    for(int i=0; i<n; ++i) {
        counts[i] = 1;
    }
    for(int i=1; i<sum; ++i) {
        for(int j=1; j<n; ++j) {
            if(j>i) {
                counts[i*n+j] = counts[i*n+j-1];
            } else if (j==i) {
                counts[i*n+j] = counts[i*n+j-1] + 1;
            } else {
                counts[i*n+j] = counts[i*n+j-1] + counts[(i-j-1)*n+j-1];
            }
        }
    }
    fout << counts[sum*n-1] << endl;
	return 0;
}
