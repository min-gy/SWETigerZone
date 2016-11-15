#include <iostream>
#include <vector>
#include "TileClass.cpp"
#include "MapClass.cpp"

using namespace std;

int main
{
/// 1 = River, 2 = Jungle, 3 = Trail.
/// for the sake of "competeing corners" jungle takes presedense over river.  
/// there doesn't seem to be anyway to determine the differnece between tiles 12 and 13 soley by edge detection.
/// May need variable to detect the center of the tile to detect differnce. 

Map Mappy = new Map;
	Tile Tile_1 = new Tile;
	Tile_1.type = {2,2,2,2,2,2,2,2};
	//Tile_1.clusterid = {1,2,1,3,1,1,1,3};
	Tile_1.meeple = {false,false,false,false,false,false,false,false};
	Tile.Den(false);
	
	
	Tile Tile_2 = new Tile;
	Tile_2.type = {2,2,2,2,2,2,2,2}; // has den
	Tile_2.meeple = {false,false,false,false,false,false,false,false};
	
        Tile Tile_3 = new Tile;
	Tile_3.type = {2,2,2,2,2,3,2,2}; // has den
	Tile_3.meeple = {false,false,false,false,false,false,false,false};	
	
	Tile Tile_4 = new Tile;
	Tile_4.type = {2,3,2,3,2,3,2,3};
	Tile_4.meeple = {false,false,false,false,false,false,false,false};	
	
	Tile Tile_5 = new Tile;
	Tile_5.type = {2,3,2,2,2,3,2,2};
	Tile_5.meeple = {false,false,false,false,false,false,false,false};	
	
	Tile Tile_6 = new Tile;	
	Tile_6.type = {2,3,2,2,2,2,2,3};
	Tile_6.meeple = {false,false,false,false,false,false,false,false};	
	
	Tile Tile_7 = new Tile;
	Tile_7.type = {2,3,2,2,2,2,3,2,3};
	Tile_7.meeple = {false,false,false,false,false,false,false,false};	
	
	Tile Tile_8 = new Tile;
	Tile_8.type = {1,1,1,1,1,1,1,1};
	Tile_8.meeple = {false,false,false,false,false,false,false,false};	
	
	Tile Tile_9 = new Tile;
	Tile_9.type = {2,2,2,1,1,1,1,1};
	Tile_9.meeple = {false,false,false,false,false,false,false,false};

	
	Tile Tile_10 = new Tile;
	Tile_10.type = {2,1,1,1,2,2,2,2};
	Tile_10.meeple = {false,false,false,false,false,false,false,false};
	
	Tile Tile_11 = new Tile;
	Tile_11.type = {};/////
	Tile_11.meeple = {false,false,false,false,false,false,false,false};
	
	Tile Tile_12 = new Tile;
	
	
	Tile_12.type = {};////
	Tile_12.meeple = {false,false,false,false,false,false,false,false};
	
	
	Tile Tile_13 = new Tile;
	Tile_13.type = {2,1,2,2,2,2,2,2};
	Tile_13.meeple = {false,false,false,false,false,false,false,false};
	
	Tile Tile_14 = new Tile;
	Tile_14.type = {2,2,2,1,1,1,2,2};
	Tile_14.meeple = {false,false,false,false,false,false,false,false};
	
	Tile Tile_15 = new Tile;
	Tile_15.type = {2,3,2,1,2,2,2,3};
	Tile_15.meeple = {false,false,false,false,false,false,false,false};
	
	Tile Tile_16 = new Tile;
	Tile_16.type = {2,3,2,1,2,2,2,3}; // has boar
	Tile_16.meeple = {false,false,false,false,false,false,false,false};
	
	Tile Tile_17 = new Tile;
	Tile_17.type = {2,2,2,1,2,3,2,3};
	Tile_17.meeple = {false,false,false,false,false,false,false,false};
	
	Tile Tile_18 = new Tile;
	Tile_18.type = {2,2,2,1,2,3,2,3}; // has ox
	Tile_18.meeple = {false,false,false,false,false,false,false,false};
	
	Tile Tile_19 = new Tile;
	Tile_19.type = {2,3,2,1,2,3,2,3};
	Tile_19.meeple = {false,false,false,false,false,false,false,false};
	
	Tile Tile_20 = new Tile;
	Tile_20.type =	{2,3,2,1,2,3,2,3}; // has deer	
	Tile_20.meeple = {false,false,false,false,false,false,false,false};
	
	Tile Tile_21 = new Tile;
	Tile_21.type =	{2,3,2,1,1,1,1,1};
	Tile_21.meeple = {false,false,false,false,false,false,false,false};
	
	Tile Tile_22 = new Tile;
	Tile_22.type =	{2,3,2,1,2,2,2,3};
	Tile_22.meeple = {false,false,false,false,false,false,false,false};
	
	Tile Tile_23 = new Tile;
	Tile_23.type ={2,3,2,1,2,2,2,3}; // has boar	
	Tile_23.meeple = {false,false,false,false,false,false,false,false};

        Tile Tile_24 = new Tile;
	Tile_24.type =	{2,3,2,1,1,1,2,3};
	Tile_24.meeple = {false,false,false,false,false,false,false,false};
	
        Tile Tile_25 = new Tile;
        Tile_25.type = {2,3,2,1,1,1,2,3}; // has ox
	Tile_25.meeple = {false,false,false,false,false,false,false,false};
	
        Tile Tile_26 = new Tile;
	Tile_26.type = {2,1,2,2,2,3,2,2};
	Tile_26.meeple = {false,false,false,false,false,false,false,false};
	
	Tile Tile_27 = new Tile;
	Tile_27.type = {2,1,2,2,2,3,2,2}; // has deer
	Tile_27.meeple = {false,false,false,false,false,false,false,false};
	
	placeTile(50, 50, Mappy, TileA);
	int x = 0;
	while x<8
	{
		cout<< "TileA type side = " << x <<  Mappy.TileGrid[50][50].type(x);
	}
	
}
