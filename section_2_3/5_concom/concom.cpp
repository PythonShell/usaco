/*
ID: pythons1
PROG: concom
LANG: C++
*/
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<map>
using namespace std;

void output_rect(vector<vector<int> > rect) {
    int m = rect.size();
    for(int i=0; i<m; ++i) {
        int n = rect[i].size();
        for(int j=0; j<n; ++j) {
            cout << rect[i][j] << " ";
        }
        cout << endl;
    }
}

int count_rect(vector<vector<int> > rect) {
    int result=0;
    int m = rect.size();
    for(int i=0; i<m; ++i) {
        int n = rect[i].size();
        for(int j=0; j<n; ++j) {
            result += rect[i][j];
        }
    }
    return result;
}

void update_rect(vector<vector<int> > & rect, vector<vector<int> > control) {
    int com = rect.size();
    for(int i=0; i<com; ++i) {
        for(int j=0; j<com; ++j) {
            if(rect[i][j]) continue;
            int per = 0;
            for(int k=0; k<com; ++k) {
                per += rect[i][k] * control[k][j];
            }
            if(per >50)
                rect[i][j]=1;
        }
    }
}

int main() {
	ifstream fin("concom.in");
    int number, max_com=0;
    vector<vector<int> > controls;
    fin >> number;
    for(int i=0;i<number; ++i) {
        int com1, com2, percent;
        fin >> com1 >> com2 >> percent;
        max_com = max_com>com1?max_com:com1;
        max_com = max_com>com2?max_com:com2;

        vector<int> temp;
        temp.push_back(com1-1);
        temp.push_back(com2-1);
        temp.push_back(percent);
        controls.push_back(temp);
    }
    fin.close();

    vector<vector<int> > rect;
    vector<vector<int> > control;
    for(int i=0; i<max_com; ++i) {
        vector<int> temp;
        for(int j=0; j<max_com; ++j) {
            temp.push_back(0);
        }
        control.push_back(temp);
        temp[i] = 1;
        rect.push_back(temp);
    }
    for(int i=0; i<controls.size(); ++i) {
        vector<int> cont = controls[i];
        control[cont[0]][cont[1]] = cont[2];
    }

    //output_rect(control);
    //output_rect(rect);
    int total1 = 0;
    int total2 = count_rect(rect);
    while(total2!=total1) {
        update_rect(rect, control);
        total1 = total2;
        total2 = count_rect(rect);
    }
    //output_rect(rect);
	ofstream fout("concom.out");
    for(int i=0; i<max_com; ++i) {
        for(int j=0; j<max_com; ++j) {
            if(rect[i][j]==1 && i!=j)
                fout << i+1 << " " << j+1 << endl;
        }
    }
    fout.close();
	return 0;
}
