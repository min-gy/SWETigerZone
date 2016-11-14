#include <iostream>
#include <vector>
#include "TileClass.cpp"
#include "MapClass.cpp"

using namespace std;

int main
{
///// 1 = River, 2 = Jungle, 3 = Trail
	Map Mappy = new Map;
	Tile Tile_1 = new Tile;
	Tile_1.type = {2,2,2,2,2,2,2,2};
	//Tile_1.clusterid = {1,2,1,3,1,1,1,3};
	Tile_1.meeple = {false,false,false,false,false,false,false,false};
	Tile Tile_2 = new Tile;
	Tile_1.type = {2,2,2,2,2,2,2,2}; // has den
	Tile Tile_3 = new Tile;
	Tile_3.type = {2,2,2,2,2,3,2,2}; // has den
	
	Tile Tile_4 = new Tile;
	Tile_4.type = {2,3,2,3,2,3,2,3};
	
	Tile Tile_5 = new Tile;
	Tile_5.type = {2,3,2,2,2,3,2,2};
	
	Tile Tile_6 = new Tile;	
	Tile_6.type = {2,3,2,2,2,2,2,3};
	
	Tile Tile_7 = new Tile;
	Tile_7.type = {2,3,2,2,2,2,3,2,3};
	
	Tile Tile_8 = new Tile;
	Tile_8.type = {1,1,1,1,1,1,1,1};
	
	Tile Tile_9 = new Tile;
	Tile_9.type = {2,2,2,1,1,1,1,1};
	
	Tile Tile_10 = new Tile;
	Tile_6.type = {};
	
	Tile Tile_11 = new Tile;
	Tile_6.type = {};
	
	Tile Tile_12 = new Tile;
	Tile_6.type = {};
	
	Tile Tile_13 = new Tile;
	Tile_6.type = {};
	
	Tile Tile_14 = new Tile;
	Tile_6.type = {};
	
	Tile Tile_15 = new Tile;
	Tile_6.type = {};
	
	Tile Tile_16 = new Tile;
	Tile_6.type = {};
	
	Tile Tile_17 = new Tile;
	Tile_6.type = {};
	
	Tile Tile_18 = new Tile;	
	Tile Tile_19 = new Tile;	
	Tile Tile_20 = new Tile;
	Tile Tile_21 = new Tile;
	Tile Tile_22 = new Tile;
	Tile Tile_23 = new Tile;
	Tile Tile_24 = new Tile;	
	Tile Tile_25 = new Tile;	
	Tile Tile_26 = new Tile;	
	Tile Tile_27 = new Tile;	
	
	placeTile(50, 50, Mappy, TileA);
	int x = 0;
	while x<8
	{
		cout<< "TileA type side = " << x <<  Mappy.TileGrid[50][50].type(x);
	}
	
}
