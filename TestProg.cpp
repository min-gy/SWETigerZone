#include <iostream>
#include <vector>
#include "TileClass.cpp"
#include "MapClass.cpp"

using namespace std;

int main
{
	Map Mappy = new Map;
	Tile TileA = new Tile;
	TileA.type = {2,1,2,3,2,2,2,3};
	TileA.clusterid = {1,2,1,3,1,1,1,3};
	TileA.meeple = {false,false,false,false,false,false,false,false};
	Tile TileB = new Tile;
	Tile TileC = new Tile;
	placeTile(50, 50, Mappy, TileA);
	int x = 0;
	while x<8
	{
		cout<< "TileA type side = " << x <<  Mappy.TileGrid[50][50].type(x);
	}
	
}