/*
ID: pythons1
PROG: friday
LANG: C++
*/
#include<iostream>
#include<fstream>
using namespace std;

void AddYear(int i, int * day);

int main() {
  ofstream fout("friday.out");
  ifstream fin("friday.in");
  int n;
  int dayNum[7] = {0, 0, 0, 0, 0, 0, 0};
  fin >> n;
  for(int i=0; i<1900+n; i++)
    AddYear(i, dayNum);
  for(int i=0; i<7; i++)
    cout << dayNum[i] << " ";
  cout << endl;
  return 0;
}

void AddYear(int i, int * day){
  return;
}
