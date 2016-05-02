/*
ID: pythons1
PROG: castle
LANG: C++
*/
#include<iostream>
#include<fstream>
#include<vector>
#include<queue>
using namespace std;

class Base {
    private:
        int x;
        int y;
        bool west;
        bool north;
        bool east;
        bool south;
    public:
        Base(): x(0), y(0), west(false), north(false),
                east(false), south(false) {};
        Base(int x1, int y1): x(x1), y(y1), west(false), north(false),
                east(false), south(false) { };
        Base(int x1, int y1, short value): x(x1), y(y1) {
            setConnection(value);
        };
        void setCoordinate(int x1, int y1) {x=x1; y=y1;};
        int getX() {return x;};
        int getY() {return y;};
        bool getWest() {return west;};
        bool getNorth() {return north;};
        bool getEast() {return east;};
        bool getSouth() {return south;};
        void setConnection(short value) {
            if(value & 1) west = true; else west = false;
            if(value & 2) north = true; else north = false;
            if(value & 4) east = true; else east = false;
            if(value & 8) south = true; else south = false;
        };
};

class Castle {
    private:
        int size_x;
        int size_y;
        Base* cells;
        int number_of_rooms;
        int maximum_room_size;
        int maximum_merged_room_size;
        Base* broken_base;
        bool broken_N;
    public:
        ~Castle() {delete[] cells;};
        Castle(int x, int y):size_x(x), size_y(y) {
            cells = new Base[size_x*size_y];
            for(int i=0; i<size_y; i++) {
                for(int j=0; j<size_x; j++) {
                    cells[i*size_x + j].setCoordinate(j, x);
                }
            }
        };
        void buildWalls(vector<short> values) {
            for(int i=0; i<size_x*size_y; i++) {
                cells[i].setConnection(values[i]);
            }
        };
        void caculate() {
            number_of_rooms = 0;
            vector<bool> visited(size_x*size_y, false);
            for(int i=0; i<visited.size(); i++) {
                queue<int> to_be_visited;
                if(!visited[i]) {
                    number_of_rooms += 1;
                    to_be_visited.push(i);
                    while(!to_be_visited.empty()) {
                        cout << "hello" << endl;
                        int current = to_be_visited.front();
                        visited[current] = true;
                        if(!cells[current].getWest() && !visited[current-1])
                            to_be_visited.push(current-1);
                        if(!cells[current].getNorth()
                                && !visited[current-size_x])
                            to_be_visited.push(current-size_x);
                        if(!cells[current].getEast() && !visited[current+1])
                            to_be_visited.push(current+1);
                        if(!cells[current].getSouth()
                                && !visited[current+size_x])
                            to_be_visited.push(current+size_x);
                        to_be_visited.pop();
                    }
                }
            }
        };
        int getNumberOfRooms() {
            return number_of_rooms;
        };
        int getMaximumRoomSize() {
            return maximum_room_size;
        };
        int getMaximumMergedRoomSize() {
            return maximum_merged_room_size;
        };
        Base* getBrokenBase() {
            return broken_base;
        };
        bool getBrokenWall() {
            return broken_N;
        };
};

int main() {
    ofstream fout("castle.out");
    ifstream fin("castle.in");
    int size_x=1, size_y=1;
    fin >> size_x >> size_y;
    Castle castle(size_x, size_y);
    vector<short> values;
    for(int i=0; i<size_x*size_y; i++) {
        short tmp;
        fin >> tmp;
        values.push_back(tmp);
    }
    castle.buildWalls(values);
    castle.caculate();
    fout << castle.getNumberOfRooms() << endl;
    fout << castle.getMaximumRoomSize() << endl;
    fout << castle.getMaximumMergedRoomSize() << endl;
    fout << castle.getBrokenBase()->getX() << " "
        << castle.getBrokenBase()->getY() << " ";
    if(castle.getBrokenWall()) fout << "N" << endl;
    else fout << "E" << endl;
    return 0;
}
