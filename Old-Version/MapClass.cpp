#include <iostream>
#include <vector>
#include <algorithm>
#include "TileClass.cpp"
#include "CompTracker.h"
using namespace std;


typedef struct
{
    int x, y;
    bool top = false;
    bool right = false;
    bool bottom = false;
    bool left = false;
}emptySpace;

class Map
{
public:
	CompTracker * MainList[100]; //Main component tracking feature of Map/Terrain
	Tile TileGrid[153][153];
    bool TilePresent[153][153];
    vector<emptySpace> emptyTiles;
    Map();
    ~Map();

    void rotateTile(Tile, int);
    void placeTile(int, int, Tile);
    void placeMeeple(int, int, Tile, int);
    void placeCrocodile(int, int, Tile, int);
    
};



void Map::rotateTile(Tile X, int orientation)
{
	if(orientation == 90)
    {
        rotate(X.type.begin(), X.type.begin() + 3, X.type.end());
        rotate(X.clusterid.begin(), X.clusterid.begin() + 3, X.clusterid.end());
    }else if(orientation == 180)
    {
        rotate(X.type.begin(), X.type.begin() + 6, X.type.end());
        rotate(X.clusterid.begin(), X.clusterid.begin() + 6, X.clusterid.end());
    }else if(orientation == 270)
    {
        rotate(X.type.begin(), X.type.begin() + 6, X.type.end());
        rotate(X.type.begin(), X.type.begin() + 3, X.type.end());
        rotate(X.clusterid.begin(), X.clusterid.begin() + 6, X.clusterid.end());
        rotate(X.clusterid.begin(), X.clusterid.begin() + 3, X.clusterid.end());
    }else
    {
        cerr<<"Invalid"<<endl;
    }
	//include orientation specification (90 degree, 270 degree etc.)

}
void Map::placeTile(int x, int y, Tile GameTile)
{
	TileGrid[x][y] = GameTile;
    TileGrid[x][y].x = x;
    TileGrid[x][y].y = y;
}

void Map::placeMeeple(int x, int y, Tile GameTile, int MeepleLoc)
{
	if (MeepleLoc == 9)
	{
		bool MMeeple = true;
		/*GameMap.MainList[GameTile.CenterClusterid]
		CompTrackerUpdate(); //Not yet completed, within CompTrackerClass*/
	}
	else
	{
		TileGrid[x][y].meeple.at(MeepleLoc) = true;
		/*CompTrackerUpdate();//GameMap.MainList[GameTile.clusterid(MeepleLoc)]*/
	}

	//id refers to choices available to place given tile
}
void Map::placeCrocodile(int x, int y, Tile GameTile, int croc_count)
{
	if((TileGrid[x][y].croc_count) == 0  )
	{
		TileGrid[x][y].croc_count = 1;
	}
}
