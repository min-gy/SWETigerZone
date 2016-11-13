#include <iostream>
#include <vector>
#include "TileClass.cpp"
#include "ComponentTrackerClass.cpp"
using namespace std;

class Map
{
	ComponentTracker * MainList = ComponentTracker[100]; //Main component tracking feature of Map/Terrain
	Tile ** TileGrid = Tile[153][153];
};

void rotateTile(Tile X) 
{
	X.sides.push_back( X.sides.front() );
	X.sides.pop_front();
	X.sides.push_back( X.sides.front() );
	X.sides.pop_front();
	orientation += 90;
	//include orientation specification (90 degree, 270 degree etc.)

};
void placeTile(int x, int y, Map GameMap, Tile GameTile)
{
	GameMap.TileGrid[x][y] = GameTile;
};
void placeMeeple(int x, int y, Map GameMap, Tile GameTile, int MeepleLoc)
{
	if (MeepleLoc == 9)
	{
		bool MMeeple = true;
		/*GameMap.MainList[GameTile.CenterClusterid]
		ComponentTrackerUpdate(); //Not yet completed, within ComponentTrackerClass*/
	}
	else
	{
		GameMap.TileGrid[x][y].meeple(MeepleLoc) = true;
		/*ComponentTrackerUpdate();//GameMap.MainList[GameTile.clusterid(MeepleLoc)]*/
	)

	//id refers to choices available to place given tile
};