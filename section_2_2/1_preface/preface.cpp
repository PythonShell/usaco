/*
ID: pythons1
PROG: preface
LANG: C++
*/
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;

const int values[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
const char ch[7] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
void count(vector<vector<int> >& solutions, int n);

int main() {
	ofstream fout("preface.out");
	ifstream fin("preface.in");
    int n;
    fin >> n;
    vector<vector<int> > solutions;
    int initial[] = {0, 0, 0, 0, 0, 0, 0};
    vector<int> solution(initial, initial + sizeof(initial) / sizeof(int) );
    solutions.push_back(solution);
    count(solutions, n);
    vector<int> result(initial, initial+sizeof(initial)/sizeof(int));
    int length = solutions.size();
    for(int i=0; i<length; ++i) {
        for(int j=0; j<7; ++j) {
            result[j] += solutions[i][j];
        }
    }
    cout << solutions.size() << endl;
    for(int i=0; i<7; ++i) {
        if (result[i]!=0)
            fout << ch[i] << " " << result[i] << endl;
    }
    /*
    if(countI(n)!=0) fout << "I " << countI(n) << endl;
    if(countV(n)!=0) fout << "V " << countV(n) << endl;
    if(countX(n)!=0) fout << "X " << countX(n) << endl;
    if(countL(n)!=0) fout << "L " << countL(n) << endl;
    if(countC(n)!=0) fout << "C " << countC(n) << endl;
    if(countD(n)!=0) fout << "D " << countD(n) << endl;
    if(countM(n)!=0) fout << "M " << countM(n) << endl;
    */
	return 0;
}

void count(vector<vector<int> >& solutions, int n) {
    int size = solutions.size();
    for(int i=size; i<=n; ++i) {
        int number = i;
        for(int j=0; j<13; ++j) {
            if(number >= values[j]) {
                number -= values[j];
                vector<int> solution = solutions[number];
                solution[6-(j/2)] ++;
                if (j%2) {
                    solution[4-2*(j/4)] ++;
                }
                solutions.push_back(solution);
                break;
            }
        }
    }
}

/*
vector<int> count(int n) {
    int values[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    vector<int> result(7, 0);
    vector<vector<int> > counts;
    int number = n;
    for(int i=0; i<13; ++i) {
        int end = values[i]-1;
        while(number>end) {
            number -= (end+1);
        }
    }
    return result;
}

inline int countI(int n) {
    int result = (n/5) * 7;
    switch (n%5) {
        case 4:
            result += 1;
        case 3:
            result += 3;
        case 2:
            result += 2;
        case 1:
            result += 1;
    }
    return result;
}

int countV(int n) {
    int result = (n/10) * 5;
    if ( (n%10) > 3 && (n%10) <9 ) {
        result += (n%10) - 3;
    }
    return result;
}

int countX(int n) {
    int result = (n/50) * 67;
    return 0;
}

int countL(int n) {
    return 0;
}

int countC(int n) {
    return 0;
}

int countD(int n) {
    return 0;
}

int countM(int n) {
    return 0;
}
*/
