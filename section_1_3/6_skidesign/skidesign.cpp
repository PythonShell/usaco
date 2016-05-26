/*
ID: pythons1
PROG: skidesign
LANG: C++
*/
#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

#define DISTANCE 17

long long getCost(int lowest, vector<int> heights);

int main() {
	ofstream fout("skidesign.out");
	ifstream fin("skidesign.in");
    int n;
    long long cost=-1;
    vector<int> heights;
    vector<int> lowest_opt;
    int lowest=-1;
    int highest=-1;
    fin >> n;
    for(int i=0; i<n; i++) {
        int temp;
        fin >> temp;
        heights.push_back(temp);
        lowest_opt.push_back(temp);
        lowest_opt.push_back(temp-DISTANCE);
        if(lowest>temp || lowest==-1) lowest = temp;
        if(highest<temp || highest==-1) highest = temp;
    }
    highest -= DISTANCE;
    if(highest<=lowest) highest = lowest+2;
    for(int i=lowest; i<highest; i++) {
        long long temp = getCost(i, heights);
        if(cost>temp || cost==-1) cost = temp;
    }
	fout << cost << endl;
	return 0;
}

long long getCost(int lowest, vector<int> heights) {
    int cost = 0;
    for(int i=0; i<heights.size(); i++) {
        if(heights[i]<lowest) {
            cost += (lowest - heights[i])*(lowest - heights[i]);
        } else if(heights[i]>(lowest+DISTANCE)) {
            cost += (heights[i]-lowest-DISTANCE)*(heights[i]-lowest-DISTANCE);
        }
    }
    return cost;
}

