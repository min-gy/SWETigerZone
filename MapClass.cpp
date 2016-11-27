#include <iostream>
#include <vector>
#include "TileClass.cpp"
#include "CompClass.h"
using namespace std;

class Map
{
public:
	CompTracker * MainList[100]; //Main component tracking feature of Map/Terrain
	Tile TileGrid[153][153];
};

/*void rotateTile(Tile X) 
{
	X.sides.push_back( X.sides.front() );
	X.sides.pop_front();
	X.sides.push_back( X.sides.front() );
	X.sides.pop_front();
	orientation += 90;
	//include orientation specification (90 degree, 270 degree etc.)

};*/
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
		CompTrackerUpdate(); //Not yet completed, within CompTrackerClass*/
	}
	else
	{
		GameMap.TileGrid[x][y].meeple.at(MeepleLoc) = true;
		/*CompTrackerUpdate();//GameMap.MainList[GameTile.clusterid(MeepleLoc)]*/
	}

	//id refers to choices available to place given tile
};
void placeCrocodile(int x, int y, Map* GameMap, Tile GameTile, int croc_count)
{
	if((GameMap->TileGrid[x][y].croc_count) = 0  )
	{
		GameMap->TileGrid[x][y].croc_count = 1;
	}
}