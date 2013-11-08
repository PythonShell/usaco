/*
ID: pythons1
PROG: calfflac
LANG: C++
*/
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class Elem {
public:
	char c;
	int pos;
};

void Find(int middle, int size, Elem *e, int *result);

int main() {
	ofstream fout("calfflac.out");
	ifstream fin("calfflac.in");
	char ch[20000];
	int count=0, max=0;
	while(fin.good()){
		char c= fin.get();
		if(fin.good()) {
			ch[count] = c;
			count++;
		}
	}
	Elem *co = new Elem[count];
	for(int i=0; i<count; i++) {
		if(ch[i]>96 && ch[i]<123) {
			co[max].c = ch[i];
			co[max].pos = i;
			max++;
		}
		if(ch[i]>64 && ch[i]<91) {
			co[max].c = ch[i] + 32;
			co[max].pos = i;
			max++;
		}
	}

	int result[3] = {0, 0, 0};
	for(int i=0; i<max; i++) {
		Find(i, max, co, result);
	}
	fout << result[2] << endl;
	for(int i=result[0]; i<=result[1]; i++)
		fout << ch[i];
	fout << endl;

	delete[] co;
	return 0;
}

void Find(int middle, int size, Elem *e, int *result) {
	int low=middle-1, high=middle+1, max;
	if(e[high].c==e[middle].c) {
		max = 1;
		high++;
		while(low>=0&&high<size&&(e[low].c==e[high].c)) {
			low--;
			high++;
			max++;
		}
		max *= 2;
		if(max > result[2]) {
			result[0] = e[low+1].pos;
			result[1] = e[high-1].pos;
			result[2] = max;
		}
	}
	else {
		max = 0;
		while(low>=0&&high<size&&(e[low].c==e[high].c)) {
			low--;
			high++;
			max++;
		}
		max = 2*max +1;
		if(max > result[2]) {
			result[0]=e[low+1].pos;
			result[1]=e[high-1].pos;
			result[2]=max;
		}
	}
}