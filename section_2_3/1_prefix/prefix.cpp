/*
ID: pythons1
PROG: prefix
LANG: C++
*/
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;

// #define DEBUG

int main() {
    ifstream fin("prefix.in");
    string temp;
    vector<string> primitives;
    string target;

    bool flag = false;
    int max_length=0;
    while(true) {
        char one_char = fin.get();
        if(one_char == ' ') {
            flag = false;
            int s= temp.size();
            if(s!=0) {
                if(s > max_length) max_length = s;
                primitives.push_back(temp);
                temp.clear();
            }
        }
        else if(one_char>='A'&&one_char<='Z') {
            flag = false;
            temp.push_back(one_char);
        }
        else {
            int s= temp.size();
            if(s!=0) {
                if(s > max_length) max_length = s;
                primitives.push_back(temp);
                temp.clear();
            }
            if(flag) break;
            else flag = true;
        }
    }
    char c;
    while(fin.get(c)) {
        if(c>='A' && c<='Z') target.push_back(c);
    }
    fin.close();
#ifdef DEBUG
    cout << "max length: " << max_length << endl;
    cout << primitives.size() << endl;
    for(int i=0; i<primitives.size(); ++i) {
        cout << primitives[i] << endl;
    }
    cout << target << endl;
#endif
    int max = target.size();
    int result = 0;
    vector<bool> flags(max, false);
    for(int i=0; i<max; ++i) {
        if(i>max_length) {
            bool break_flag = false;
            for(int k=0; k<primitives.size(); ++k) {
                int j = primitives[k].size();
                break_flag = break_flag || flags[i-j];
#ifdef DEBUG
                cout << primitives[k] << " " <<
                    target.substr(i-j+1, j) << " length: " << j << endl;
#endif
                if(flags[i-j] &&
                        primitives[k].compare(target.substr(i-j+1, j))==0) {
                    flags[i] = true;
                    break;
                }
            }
            // if (!break_flag) break;
        } else {
            for(int j=0; j<primitives.size(); ++j) {
                if(primitives[j].compare(target.substr(0, i+1))==0) {
                    flags[i]=true;
                    break;
                }
            }
            if (flags[i]) continue;
            for(int k=0; k<primitives.size(); ++k) {
                int j = primitives[k].size();
                if(i<j) continue;
                if(flags[i-j] &&
                        primitives[k].compare(target.substr(i-j+1, j))==0) {
                    flags[i] = true;
                    break;
                }
            }
        }
    }
#ifdef DEBUG
    for(int i=0; i<max; ++i) {
        cout << flags[i] << " ";
    } cout << endl;
#endif
    for(int i=max-1; i>-1; --i) {
        if(flags[i]) {
            result = i+1;
            break;
        }
    }
#ifdef DEBUG
    cout << "The answer is: " << result << endl;
#endif
    ofstream fout("prefix.out");
    fout << result << endl;
    fout.close();
    return 0;
}

