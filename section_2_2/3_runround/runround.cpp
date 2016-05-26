/*
ID: pythons1
PROG: runround
LANG: C++
*/
#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

#define DEBUG

inline vector<short> getDigits(int n) {
    vector<short> result;
    while(n) {
        result.push_back(n%10);
        n = n / 10;
    }
    return result;
}

inline bool isRunround(int n) {
    vector<short> digits = getDigits(n);
    short length = digits.size();
    short maxLength=0;
    short maxValue=0;
    for(short i=0; i<length; ++i) {
        if (digits[i]==0) return false;
        if (digits[i]>maxValue) maxValue = digits[i];
        maxLength += digits[i];
        for(short j=i+1; j<length; ++j) {
            if(digits[i]==digits[j]) return false;
        }
    }
    short times = (maxLength+maxValue)/length + 6;
    for(short i=0; i<times; ++i) {
        vector<short>::iterator it = digits.end();
        digits.insert(it, digits.begin(), digits.begin()+length);
    }
    vector<short> obtains;
    while(obtains.size()!=length+1) {
        short current = digits[digits.size()-1];
        obtains.push_back(current);
        digits.resize(digits.size()-current);
    }
    if(obtains[obtains.size()-1]!=obtains[0])
        return false;
    obtains.pop_back();
    for(short i=0; i<length; ++i) {
        for(short j=i+1; j<length; ++j) {
            if(obtains[i]==obtains[j]) return false;
        }
    }
    return true;
}

int main() {
	ofstream fout("runround.out");
	ifstream fin("runround.in");
    unsigned int m;
    fin >> m;
    fin.close();
    ++m;
    while(!isRunround(m)) {
        ++m;
    }
    fout << m << endl;
    fout.close();
	return 0;
}
