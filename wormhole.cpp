/*
ID: pythons1
PROG: wormhole
LANG: C++
*/
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<utility>

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

int main() {
    ofstream fout("wormhole.out");
    ifstream fin("wormhole.in");
    int number_hole=0;
    int result=0;
    fin >> number_hole;
    Hole holes[number_hole];
    for(int i=0; i<number_hole; i++) {
        int x, y;
        fin >> x >> y;
        holes[i] = Hole(x, y);
    }
    for(int i=0; i<number_hole; i++) {
        Hole* tmp = walkTo(*(holes+i), holes, number_hole);
        (holes+i)->setWalk(tmp);
    }
    for(int i=0; i<(number_hole/2); i++) {
        makePair(holes+i, holes+number_hole/2+i);
    }

    for(int i=0; i<number_hole; i++) {
        if(((holes+i)->getWalk())==NULL) cout << "no.";
        else cout << "yes!";
        cout << " ";
        if(((holes+i)->getTravel())==NULL) cout << "no.";
        else cout << "yes!";
        cout << endl;
    }
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
    return true;
}

