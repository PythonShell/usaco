/*
ID: pythons1
PROG: wormhole
LANG: C++
*/
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<queue>
#include<utility>
#include<algorithm>

#define MAX 999999999
using namespace std;

// one connection for two wormhole
typedef pair<short, short> connection;
// one situation which contains several connections
typedef vector<connection> situation;

// define wormhole, which have coordinate, and two ptr to holes
class Hole {
    private:
        int x;
        int y;
        Hole* travel_to;
        Hole* walk_to;
    public:
        Hole(int a, int b):x(a), y(b), travel_to(NULL), walk_to(NULL) { };
        Hole():x(0), y(0), travel_to(NULL), walk_to(NULL) { };
        void setTravel(Hole* target) { travel_to=target; };
        void setWalk(Hole* target) { walk_to=target; };
        Hole* getTravel() { return travel_to; };
        Hole* getWalk() { return walk_to; };
        int getX() { return x; };
        int getY() { return y; };
};

// Get hole it can visit
Hole* walkTo(Hole from, Hole* holes, int number);
// make first and second connect to each other
inline void makePair(Hole* first, Hole* second);
// make connections according to a situation
inline void makePairs(Hole* holes, int length, situation sit);
// judge wether a circle exists currently
bool existCircle(Hole* holes, int length);
// judge wether a circle exists when start at some point
vector<Hole*> existCircle(Hole* holes, int length, int start);

int main() {
    ofstream fout("wormhole.out");
    ifstream fin("wormhole.in");
    int number_hole=0;
    int result=0;
    fin >> number_hole;
    vector<short> total_nodes;
    Hole holes[number_hole];
    for(int i=0; i<number_hole; i++) {
        int x, y;
        fin >> x >> y;
        holes[i] = Hole(x, y);
        total_nodes.push_back(i);
    }
    // initial walk to
    for(int i=0; i<number_hole; i++) {
        Hole* tmp = walkTo(*(holes+i), holes, number_hole);
        (holes+i)->setWalk(tmp);
    }

    queue<situation> situations;
    for(int i=1; i<number_hole; i++) {
        situation tmp;
        tmp.push_back(connection(0, i));
        situations.push(tmp);
    }
    while(!situations.empty()) {
        situation current_sit = situations.front();
        if(current_sit.size()==(number_hole/2)) {
            makePairs(holes, number_hole, current_sit);
            if (existCircle(holes, number_hole)) {
                result += 1;
            }
        } else {
            vector<short> remains = total_nodes;
            vector<short> used;
            for(int i=0; i<current_sit.size(); i++) {
                used.push_back(current_sit[i].first);
                used.push_back(current_sit[i].second);
            }
            sort(used.begin(), used.end());
            for(int i=used.size(); i>0; i--) {
                remains.erase(remains.begin()+used[i-1]);
            }
            for(int i=1; i<remains.size(); i++) {
                connection tmp(remains[0], remains[i]);
                situation newone = current_sit;
                newone.push_back(tmp);
                situations.push(newone);
            }
        }
        situations.pop();
    }

    /*
    for(int i=0; i<number_hole; i++) {
        if(((holes+i)->getWalk())==NULL) cout << "no.";
        else cout << "yes!";
        cout << " ";
        if(((holes+i)->getTravel())==NULL) cout << "no.";
        else cout << "yes!";
        cout << endl;
    }
    */
    fout << result << endl;
    return 0;
}

Hole* walkTo(Hole from, Hole* holes, int number) {
    int y = from.getY();
    int x = from.getX();
    int distance = MAX;
    Hole* result = NULL;
    for(int i=0; i<number; i++) {
        if(holes[i].getY() == y
                && (holes[i].getX()-x)>0
                && (holes[i].getX()-x)<distance ) {
            distance = holes[i].getX()-x;
            result = holes + i;
        }
    }
    return result;
}

inline void makePair(Hole* first, Hole* second) {
    first->setTravel(second);
    second->setTravel(first);
}

inline void makePairs(Hole* holes, int length, situation sit) {
    for(int i=0; i<(length/2); i++) {
        makePair(holes+sit[i].first, holes+sit[i].second);
    }
}

bool existCircle(Hole* holes, int length) {
    for(int i=0; i<length; i++) {
        if((holes+i)->getWalk()!=NULL) {
            vector<Hole*> circle = existCircle(holes, length, i);
            if(circle.size()!=0) {
                return true;
            }
        }
    }
    return false;
}

vector<Hole*> existCircle(Hole* holes, int length, int start) {
    vector<Hole*> visited;
    bool next_walk=true;
    visited.push_back(holes+start);
    Hole current_hole = *(holes + start);
    while(true) {
        if(next_walk && current_hole.getWalk()==NULL) {
            break;
        } else if(next_walk && current_hole.getWalk()!=NULL) {
            Hole* next_ptr = current_hole.getWalk();
            visited.push_back(next_ptr);
            current_hole = *next_ptr;
            next_walk = !next_walk;
        } else if(!next_walk && current_hole.getTravel()==NULL) {
            break;
        } else if(!next_walk && current_hole.getTravel()!=NULL) {
            Hole* next_ptr = current_hole.getTravel();
            if (next_ptr == (holes+start)) {
                return visited;
            }
            visited.push_back(next_ptr);
            current_hole = *next_ptr;
            next_walk = !next_walk;
        }
    }
    visited.resize(0);
    return visited;
}
