#include <iostream>
#include <vector>

//#include "TileRegion.cpp"
//#include <unordered_map>
//#include "MapClass.cpp"
//#include "PlayerClass.cpp"
//#include "ComponentTrackerClass.cpp"

using namespace std;

class Tile
{
public:
    //Face values (sides of tile), values will correlate with types ///0-castle//, 1-castle, 2-field, 3-path
    int orientation;
    vector<char> des;
    vector<int> type; //1 - N, 2 - NE, 3 - E, 4 - SE, 5 - S, 6 - SW, 7 - W, 8 - NW   1,3,5,7 = sides 2,4,6,8 = corners
    vector<int> clusterid;
    vector<bool> tiger;
    int croc_count;
    bool Ox;
    bool Boar;
    bool Deer;
    bool Den;
    int x;
    int y;
    //0 = top, 1 = right, 2 = bottom, 3 = left
    bool completion[4];

    Tile(vector<char>, vector<int>, vector<int>, vector<bool>, int, bool, bool, bool, bool, int, int, bool[]);
    ~Tile();
	
};

Tile::Tile(vector<char> description, vector<int> geoType, vector<int> clust, vector<bool> bigCat, int crocodile, bool ox, bool hog, bool deer, bool den, int X, int Y, bool completedSides[]){
    des  = description;
    type = geoType;
    clusterid = clust;
    tiger = bigCat;
    croc_count = crocodile;
    Ox = ox;
    Boar = hog;
    Deer = deer;
    Den = den;
    x = X;
    y = Y;
    completion = completedSides;
}

Tile::~Tile(){

}
