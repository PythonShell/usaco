/*
ID: python1
PROG: crypt1
LANG: C++
*/
#include<iostream>
#include<fstream>
using namespace std;

bool IsIn(int num, int *set, int size);

int main() {
        ofstream fout("crypt1.out");
        ifstream fin("crypt1.in");
        int num, *set, count=0, first, no1, no2, result;
        fin >> num;
        set = new int[num];
        for(int i=0; i<num; i++)
                fin >> set[i];
        for(int i=0; i<num; i++) {
                for(int j=0; j<num; j++) {
                        for(int k=0; k<num; k++) {
                                first = 100*set[i] + 10*set[j] + set[k];
                                for(int m=0; m<num; m++) {
                                        no1 = first * set[m];
                                        if(!IsIn(no1%10, set, num)) continue;
                                        if(!IsIn( (no1%100)/10, set, num)) continue;
                                        if(!IsIn( no1/100, set, num)) continue;
                                        for(int n=0; n<num; n++) {
                                                no2 = first * set[n];
                                                if(!IsIn(no2%10, set, num)) continue;
                                                if(!IsIn( (no2%100)/10, set, num)) continue;
                                                if(!IsIn( no2/100, set, num)) continue;
                                                result = no2*10 + no1;
                                                if(!IsIn(result%10, set, num)) continue;
                                                if(!IsIn( (result%100)/10, set, num)) continue;
                                                if(!IsIn( (result%1000)/100, set, num)) continue;
                                                if(!IsIn( (result/1000), set, num)) continue;
                                                count++;
                                        }
                                }
                        }
                }
        }
        fout << count << endl;
        return 0;
}

bool IsIn(int num, int *set, int size) {
        for(int i=0; i<size; i++)
                if(num==set[i]) return true;
        return false;
}
