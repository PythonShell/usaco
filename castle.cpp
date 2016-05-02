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

int size_x=1;
int size_y=1;

class mycomparison {
    public:
        bool operator() (const int&lhs, const int&rhs) const {
            int index_l = lhs>>1;
            int index_r = rhs>>1;
            int index_lx = index_l % size_x + 1;
            int index_ly = index_l / size_x + 1;
            int index_rx = index_r % size_x + 1;
            int index_ry = index_r / size_x + 1;
            bool N_l = lhs&1;
            bool N_r = lhs&1;
            if(index_lx > index_rx) return true;
            else if(index_lx == index_rx && index_ly > index_ry) return true;
            else if(index_lx == index_rx && index_ly== index_ry && !N_l)
                return true;
            /*
            else if(index_ly > index_ry) return true;
            else if(!N_l) return true;
            */
            else return false;
        };
};
typedef priority_queue<int, vector<int>, mycomparison> mypq_type;

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
        void setWest(bool v) {west=v;};
        void setNorth(bool v) {north=v;};
        void setEast(bool v) {east=v;};
        void setSouth(bool v) {south=v;};
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
        bool wallRemovable(int index, bool N) {
            if(N && index>=size_x) {
                return cells[index].getNorth();
            } else if(!N && ((index+1)%size_x!=0)) {
                return cells[index].getEast();
            } else {
                return false;
            }
        };
        void addWall(int index, bool add_N) {
            if(add_N && index>=size_x) {
                cells[index].setNorth(true);
                cells[index-size_x].setSouth(true);
            } else if(!add_N && ((index+1)%size_x!=0)){
                cells[index].setEast(true);
                cells[index+1].setWest(true);
            }
        };
        void removeWall(int index, bool break_N) {
            if(break_N && index>=size_x) {
                cells[index].setNorth(false);
                cells[index-size_x].setSouth(false);
            } else if(!break_N && ((index+1)%size_x!=0)){
                cells[index].setEast(false);
                cells[index+1].setWest(false);
            }
        };
        void caculate() {
            number_of_rooms = 0;
            maximum_room_size = -1;
            vector<bool> visited(size_x*size_y, false);
            for(int i=0; i<visited.size(); i++) {
                queue<int> to_be_visited;
                if(!visited[i]) {
                    number_of_rooms += 1;
                    int room_size = 0;
                    to_be_visited.push(i);
                    while(!to_be_visited.empty()) {
                        room_size += 1;
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
                    if(room_size > maximum_room_size)
                        maximum_room_size = room_size;
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
    int maximum_merged_room_size=-1;
    vector<int> solutions;
    for(int i=0; i<size_x*size_y; i++) {
        if(castle.wallRemovable(i, true)) {
            castle.removeWall(i, true);
            castle.caculate();
            int temp_size = castle.getMaximumRoomSize();
            if(temp_size>maximum_merged_room_size) {
                maximum_merged_room_size = temp_size;
                solutions.resize(0);
                solutions.push_back((i<<1)+1);
            } else if(temp_size==maximum_merged_room_size) {
                solutions.push_back((i<<1)+1);
            }
            castle.addWall(i, true);
        }
        if(castle.wallRemovable(i, false)) {
            castle.removeWall(i, false);
            castle.caculate();
            int temp_size = castle.getMaximumRoomSize();
            if(temp_size>maximum_merged_room_size) {
                maximum_merged_room_size = temp_size;
                solutions.resize(0);
                solutions.push_back((i<<1));
            } else if(temp_size==maximum_merged_room_size) {
                solutions.push_back((i<<1));
            }
            castle.addWall(i, false);
        }
    }
    fout << maximum_merged_room_size << endl;
    mypq_type mypq;
    for(int i=0; i<solutions.size(); i++) {
        /*
        cout << ((solutions[i]>>1) / size_x + 1) << " ";
        cout << ((solutions[i]>>1) % size_x + 1) << " ";
        cout << (solutions[i]&1) << endl;
        */
        mypq.push(solutions[i]);
    }
    int final_val = mypq.top();
    fout << ((final_val>>1) / size_x + 1) << " ";
    fout << ((final_val>>1) % size_x + 1) << " ";
    if(final_val&1) fout << "N" << endl;
    else fout << "E" << endl;
    return 0;
}
