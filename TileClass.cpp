#include <iostream>
#include <vector>
#include "MapClass.cpp"
#include "PlayerClass.cpp"
#include "ComponentTrackerClass.cpp"
using namespace std;

public class Tile 
{
//Face values (sides of tile), values will correlate with types ///0-castle//, 1-castle, 2-field, 3-path
vector<int> type(8); //1 - N, 2 - NE, 3 - E, 4 - SE, 5 - S, 6 - SW, 7 - W, 8 - NW   1,3,5,7 = sides 2,4,6,8 = corners
vector<int> clusterid(8);
vector<bool> meeple(8);
bool Shield;
bool Monastery;
bool MMeeple; //monastery meeple
int CenterClusterid;
int orientation = 0;
}
//rotate right function below
void rotateTile(Tile X) 
{
	X.sides.push_back( X.sides.front() );
	X.sides.pop_front();
	X.sides.push_back( X.sides.front() );
	X.sides.pop_front();
	orientation += 90;
	//include orientation specification (90 degree, 270 degree etc.)

}
void placeTile(int x, int y, Map GameMap, Tile GameTile)
{
	GameMap.TileGrid[x][y] = GameTile;
}
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
}