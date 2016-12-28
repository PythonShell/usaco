/*
ID: pythons1
PROG: zerosum
LANG: C++
*/
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<cmath>
using namespace std;

bool equalZero(int number, int oper);
string getFormula(int number, int oper);

bool equalZero(int number, int oper) {
    int sum = 0;
    int temp = 0;
    int times = 1;
    int o = oper;
    for(int i=number; i>1; --i) {
        int op = o% 3;
        o = o / 3;
        if(op==0) {
            temp += i*times;
            times *= 10;
        }
        else if(op==1) {
            temp += i * times;
            sum += temp;
            temp = 0;
            times = 1;
        }
        else if(op==2) {
            temp += i * times;
            sum -= temp;
            temp = 0;
            times = 1;
        }
    }
    sum += 1 * times + temp;
    if(sum==0)
    cout << getFormula(number, oper) << " = " << sum << endl;
    return sum==0;
}

string getFormula(int number, int oper) {
    string result(2*number-1, '*');
    result[0] = 49;
    for(int i=number; i>1; --i) {
        result[2*i-2] = 48 + i;
        int op = oper % 3;
        oper = oper / 3;
        int idx = 2*i-3;
        if(op==0) result[idx] = ' ';
        else if(op==1) result[idx] = '+';
        else if(op==2) result[idx] = '-';
    }
    return result;
}

int main() {
	ifstream fin("zerosum.in");
	ofstream fout("zerosum.out");
    int number;
	fin >> number;
    fin.close();

    int upper = pow(3, number-1);
    for(int i=0; i<upper; ++i) {
        if(equalZero(number, i)) {
            fout << getFormula(number, i) << endl;
        }
    }

    fout.close();
	return 0;
}
