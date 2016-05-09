/*
ID: pythons1
PROG: frac1
LANG: C++
*/
#include<iostream>
#include<fstream>
#include<string>
#include<list>
using namespace std;

inline int getCommon(int a, int b) {
    if(a==b) return a;
    if(a==1 || b==1) return 1;
    int min = a>b?b:a;
    int max = a<b?b:a;
    while(min!=0) {
        int tmp = max % min;
        max = min;
        min = tmp;
    }
    return max;
};

class Fraction {
    public:
        int above;
        int below;
        Fraction(int a=0, int b=1):above(a), below(b) { reduction(); };
        void reduction() {
            int big= getCommon(above, below);
            above /= big;
            below /= big;
        };
};

inline bool operator==(const Fraction f1, const Fraction f2) {
    return (f1.above==f2.above && f1.below== f2.below);
};

inline bool operator<(const Fraction f1, const Fraction f2) {
    int n_below = getCommon(f1.below, f2.below);
    int n_above_1 = f1.above * (f2.below/n_below);
    int n_above_2 = f2.above * (f1.below/n_below);
    return n_above_1<n_above_2;
};

int main() {
	ofstream fout("frac1.out");
	ifstream fin("frac1.in");
	int n;
	fin >> n;
    list<Fraction> my_fractions;
    list<Fraction>::iterator my_it=my_fractions.begin();
    // Add 0/1 and 1/1 into my_fractions
    my_fractions.push_back(Fraction(0, 1));
    my_fractions.push_back(Fraction(1, 1));
    for(int i=1; i<n; ++i) {
        int below = i+1;
        for(int j=1; j<below; ++j) {
            int above = j;
            my_fractions.push_back(Fraction(above, below));
        }
    }
    my_fractions.sort();
    my_fractions.unique();
    for(list<Fraction>::iterator it=my_fractions.begin(), e=my_fractions.end();
            it!=e; ++it) {
        fout << it->above << "/" << it->below << endl;
    }
	return 0;
}
