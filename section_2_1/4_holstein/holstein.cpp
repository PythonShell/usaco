/*
ID: pythons1
PROG: holstein
LANG: C++
*/
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<deque>
#include<algorithm>
using namespace std;

vector<int> getSolution(vector<int> target,
        vector<int> values);

int main() {
    ofstream fout("holstein.out");
    ifstream fin("holstein.in");
    int size, length;
    vector<int> target;
    fin >> size;
    for(int i=0; i<size; ++i) {
        int tmp;
        fin >> tmp;
        target.push_back(tmp);
    }
    fin >> length;
    vector<int> values;
    for(int i=0; i<length; i++) {
        for(int j=0; j<size; ++j) {
            int tmp;
            fin >> tmp;
            values.push_back(tmp);
        }
    }
    vector<int> result = getSolution(target, values);
    int result_size = result.size();
    fout << result_size;
    for(int i=0; i<result_size; ++i)
        fout << " " << result[i]+1;
    fout << endl;
    return 0;
}

bool isSolution(vector<int> target, vector<int> values, vector<int> solution) {
    int size = target.size();
    int length = solution.size();
    for(int i=0; i<size; ++i) {
        int tmp_sum=0;
        for(int j=0; j<length; ++j) {
            tmp_sum += values[solution[j]*size+i];
        }
        if(tmp_sum<target[i])
            return false;
    }
    return true;
}

vector<int> getSolution(vector<int> target,
        vector<int> values) {
    int size = target.size();
    int length = values.size()/size;
    deque< vector<int> > solution_container;
    for(int i=0; i< length; ++i) {
        vector<int> solution(1, i);
        solution_container.push_back(solution);
    }
    while(!solution_container.empty()) {
        vector<int> current_solution = solution_container.front();
        if( isSolution(target, values, current_solution) ) {
            return current_solution;
            break;
        }
        for(int i=current_solution.back()+1; i<length; ++i) {
            current_solution.push_back(i);
            solution_container.push_back(current_solution);
            current_solution.pop_back();
        }
        solution_container.pop_front();
    }
    vector<int> result;
    return result;
}

