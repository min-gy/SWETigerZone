#include <iostream>
#include <vector>

//#include "TileRegion.cpp"
#include <unordered_map>
#include "MapClass.cpp"
#include "PlayerClass.cpp"
//#include "ComponentTrackerClass.cpp"

using namespace std;

class Tile 
{
public:
//Face values (sides of tile), values will correlate with types ///0-castle//, 1-castle, 2-field, 3-path
vector<int> type; //1 - N, 2 - NE, 3 - E, 4 - SE, 5 - S, 6 - SW, 7 - W, 8 - NW   1,3,5,7 = sides 2,4,6,8 = corners
vector<int> clusterid;
vector<bool> meeple;
//vector<TileRegion> sides;
bool Deer;
bool Boar;
bool Ox;
bool Monastery;
bool MMeeple; //monastery meeple
int CenterClusterid;
int orientation;
int croc_count;//public:
//	Tile() : sides(8) 
//	{}
	
};
//rotate right function below
