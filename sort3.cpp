/*
ID: pythons1
PROG: sort3
LANG: C++
*/
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;

int main() {
	ofstream fout("sort3.out");
	ifstream fin("sort3.in");
    int n;
    fin >> n;
    vector<short> numbers;
    int number_of[3]={0, 0, 0};
    for(int i=0; i<n; ++i) {
        short tmp;
        fin >> tmp;
        numbers.push_back(tmp);
        ++number_of[tmp-1];
    }
    // delete non exchange data
    for(int i=numbers.size()-1; i>=0; --i) {
        if( i>=(number_of[0]+number_of[1]) ) {
            if(numbers[i]==3) {
                numbers.erase(numbers.begin()+i);
                --number_of[2];
            }
        } else if(i>=number_of[0]) {
            if(numbers[i]==2) {
                numbers.erase(numbers.begin()+i);
                --number_of[1];
            }
        } else {
            if(numbers[i]==1) {
                numbers.erase(numbers.begin()+i);
                --number_of[0];
            }
        }
    }
    int N12=0;
    int N13=0;
    int N21=0;
    int N23=0;
    int N31=0;
    int N32=0;
    for(int i=0; i<number_of[0]; ++i) {
        if(numbers[i]==2) ++N12;
        if(numbers[i]==3) ++N13;
    }
    for(int i=number_of[0]; i<number_of[0]+number_of[1]; ++i) {
        if(numbers[i]==1) ++N21;
        if(numbers[i]==3) ++N23;
    }
    for(int i=number_of[0]+number_of[1];
            i<number_of[0]+number_of[1]+number_of[2]; ++i) {
        if(numbers[i]==1) ++N31;
        if(numbers[i]==2) ++N32;
    }
    /*
    cout << "N12 = " << N12 << endl;
    cout << "N13 = " << N13 << endl;
    cout << "N21 = " << N21 << endl;
    cout << "N23 = " << N23 << endl;
    cout << "N31 = " << N31 << endl;
    cout << "N32 = " << N32 << endl;
    */
    int result=0;
    result += (N12>N21?N21:N12);
    result += (N13>N31?N31:N13);
    result += (N23>N32?N32:N23);
    result += 2*(N12>N21?(N12-N21):(N21-N12));
    // cout << result << endl;
    fout << result << endl;
	return 0;
}

