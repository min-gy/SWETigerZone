#include <iostream>
#include <vector>
#include <unordered_map>
//#include "MapClass.cpp"
//#include "PlayerClass.cpp"
//#include "ComponentTrackerClass.cpp"

using namespace std;

class Map;
class Player;
class ComponentTracker;

class Tile 
{
public:
	//Face values (sides of tile), values will correlate with types ///0-castle//, 1-castle, 2-field, 3-path
	vector<int> type; //1 - N, 2 - NE, 3 - E, 4 - SE, 5 - S, 6 - SW, 7 - W, 8 - NW   1,3,5,7 = sides 2,4,6,8 = corners
	vector<int> clusterid;
	vector<bool> meeple;
	vector<bool> croc;
	vector<int> sides;
	
	bool Ox;
	bool Deer;
	bool Boar;
	bool Den; 
	bool Crocodile;
	//bool MMeeple; //monastery meeple
	int CenterClusterid;
	void rotateTile(Tile);
};
int orientation;
//rotate right function below
void rotateTile(Tile X) 
{
	X.sides.push_back( X.sides.front() );
	X.sides.erase(X.sides.begin());
	X.sides.push_back( X.sides.front() );
	X.sides.erase(X.sides.begin());
	orientation += 90;
	//include orientation specification (90 degree, 270 degree etc.)

}
void placeTile(int x, int y, Map * GameMap, Tile * GameTile)
{
	GameMap->TileGrid[x][y] = GameTile;
}
void placeMeeple(int x, int y, Map * GameMap, Tile GameTile, int MeepleLoc)
{
	if (Den == 5)
	{
		bool Den = true;
		/*GameMap.MainList[GameTile.CenterClusterid]
		ComponentTrackerUpdate(); //Not yet completed, within ComponentTrackerClass*/
	}
	else
	{
		GameMap->TileGrid[x][y].meeple.at(MeepleLoc) = true;
		/*ComponentTrackerUpdate();//GameMap.MainList[GameTile.clusterid(MeepleLoc)]*/
	}

	//id refers to choices available to place given tile
}
