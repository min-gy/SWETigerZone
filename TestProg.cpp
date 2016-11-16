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
	Tile * Tile_1 = new Tile;
	Tile_1->type.insert(type.end(), {2,2,2,2,2,2,2,2});
	Tile_1clusterid = {1,1,1,1,1,1,1,1};
	Tile_1.meeple = {false,false,false,false,false,false,false,false};
	Tile_1.prey = "none";
	
	
	
	Tile * Tile_2 = new Tile;
	Tile_2->type.insert(type.end(), {2,2,2,2,2,2,2,2}); // has den
	Tile_2.clusterid = {};
	Tile_2.meeple = {false,false,false,false,false,false,false,false};
	Tile_2.prey = "none";	
	
        Tile * Tile_3 = new Tile;
	Tile_3->type.insert(type.end(),  {2,2,2,2,2,3,2,2}); // has den
	Tile_3.clusterid = {};
	Tile_3.meeple = {false,false,false,false,false,false,false,false};
	Tile_3.prey = "none";	
	
	Tile * Tile_4 = new Tile;
	Tile_4->type.insert(type.end(),  {2,3,2,3,2,3,2,3});
	Tile_4.clusterid = {};
	Tile_4.meeple = {false,false,false,false,false,false,false,false};
	Tile_4.prey = "none";	
	
	Tile * Tile_5 = new Tile;
	Tile_5->type.insert(type.end(), {2,3,2,2,2,3,2,2});
	Tile_5.clusterid = {};
	Tile_5.meeple = {false,false,false,false,false,false,false,false};
	Tile_5.prey = "none";	
	
	Tile * Tile_6 = new Tile;	
	Tile_6->type.insert(type.end(),  {2,3,2,2,2,2,2,3});
	Tile_6.clusterid = {}
	Tile_6.meeple = {false,false,false,false,false,false,false,false};
	Tile_6.prey = "none";	
	
	Tile * Tile_7 = new Tile;
	Tile_7->type.insert(type.end(),  {2,3,2,2,2,2,3,2,3});
	Tile_7.clusterid = {};
	Tile_7.meeple = {false,false,false,false,false,false,false,false};	
	Tile_7.prey = "none";	
	
	Tile * Tile_8 = new Tile;
	Tile_8->type.insert(type.end(), {1,1,1,1,1,1,1,1});
	Tile_8.clusterid = {};
	Tile_8.meeple = {false,false,false,false,false,false,false,false};	
	Tile_8.prey = "none";
	
	
	Tile * Tile_9 = new Tile;
	Tile_9->type.insert(type.end(), {2,2,2,1,1,1,1,1});
	Tile_9.clusterid = {};
	Tile_9.meeple = {false,false,false,false,false,false,false,false};
        Tile_9.prey = "none";
	
	
	Tile * Tile_10 = new Tile;
	Tile_10->type.insert(type.end(),   {2,1,1,1,2,2,2,2});
	Tile_10.clusterid = {};
	Tile_10.meeple = {false,false,false,false,false,false,false,false};
	Tile_10.prey = "none";
	
	
	Tile * Tile_11 = new Tile;
	Tile_11->type.insert(type.end(),  {});/////
	Tile_11.clusterid = {};
	Tile_11.meeple = {false,false,false,false,false,false,false,false};
	Tile_11.prey = "none";
	
	
	Tile * Tile_12 = new Tile;
	Tile_12->type.insert(type.end(), {});////
	Tile_12.clusterid = {};
	Tile_12.meeple = {false,false,false,false,false,false,false,false};
	Tile_12.prey = "none";
	
	Tile * Tile_13 = new Tile;
	Tile_13->type.insert(type.end(),  {2,1,2,2,2,2,2,2});
	Tile_13.clusterid = {};
	Tile_13.meeple = {false,false,false,false,false,false,false,false};
	Tile_13.prey = "none";
	
	Tile *  Tile_14 = new Tile;
	Tile_14->type.insert(type.end(), {2,2,2,1,1,1,2,2});
	Tile_14.clusterid = {};
	Tile_14.meeple = {false,false,false,false,false,false,false,false};
	Tile_14.prey = "none";
	
	Tile * Tile_15 = new Tile;
	Tile_15->type.insert(type.end(), {2,3,2,1,2,2,2,3});
	Tile_15.clusterid = {};
	Tile_15.meeple = {false,false,false,false,false,false,false,false};
	Tile_15.prey = "none";
	
	Tile * Tile_16 = new Tile;
	Tile_16->type.insert(type.end(), {2,3,2,1,2,2,2,3}); // has boar
	Tile_16.clusterid = {};
	Tile_16.meeple = {false,false,false,false,false,false,false,false};
	Tile_16.prey = "boar";
	
	Tile * Tile_17 = new Tile;
	Tile_17->type.insert(type.end(), {2,2,2,1,2,3,2,3});
	Tile_17.clusterid = {};
	Tile_17.meeple = {false,false,false,false,false,false,false,false};
	Tile_17.prey = "none";
	
	Tile * Tile_18 = new Tile;
	Tile_18->type.insert(type.end(), {2,2,2,1,2,3,2,3}); // has ox
	Tile_18.clusterid = {};
	Tile_18.meeple = {false,false,false,false,false,false,false,false};
	Tile_18.prey = "ox";
	
	Tile * Tile_19 = new Tile;
	Tile_19->type.insert(type.end(), {2,3,2,1,2,3,2,3});
	Tile_19.clusterid = {};
	Tile_19.meeple = {false,false,false,false,false,false,false,false};
	Tile_19.prey = "none";
	
	Tile * Tile_20 = new Tile;
	Tile_20->type.insert(type.end(), {2,3,2,1,2,3,2,3}); // has deer	
	Tile_20.clusterid = {};
	Tile_20.meeple = {false,false,false,false,false,false,false,false};
	Tile_20.prey = "deer";
	
	Tile * Tile_21 = new Tile;
	Tile_21->type.insert(type.end(), {2,3,2,1,1,1,1,1});
	Tile_21.clusterid = {};
	Tile_21.meeple = {false,false,false,false,false,false,false,false};
	Tile_21.prey = "none";
	
	Tile * Tile_22 = new Tile;
	Tile_22->type.insert(type.end(), {2,3,2,1,2,2,2,3});
	Tile_22.clusterid = {};
	Tile_22.meeple = {false,false,false,false,false,false,false,false};
	Tile_22.prey = "none";
	
	Tile * Tile_23 = new Tile;
	Tile_23->type.insert(type.end(), {2,3,2,1,2,2,2,3}); // has boar	
	Tile_23.clusterid = {};
	Tile_23.meeple = {false,false,false,false,false,false,false,false};
	Tile_23.prey = "boar";

        Tile * Tile_24 = new Tile;
	Tile_24->type.insert(type.end(), {2,3,2,1,1,1,2,3});
	Tile_24.clusterid = {};
	Tile_24.meeple = {false,false,false,false,false,false,false,false};
	Tile_24.prey = "none";
	
        Tile * Tile_25 = new Tile;
        Tile_25->type.insert(type.end(), {2,3,2,1,1,1,2,3}); // has ox
	Tile_25.clusterid = {};
	Tile_25.meeple = {false,false,false,false,false,false,false,false};
	Tile_25.prey = "ox";
	
        Tile * Tile_26 = new Tile;
	Tile_26->type.insert(type.end(), {2,1,2,2,2,3,2,2});
	Tile_26.clusterid = {};
	Tile_26.meeple = {false,false,false,false,false,false,false,false};
	Tile_26.prey = "none";
	
	Tile * Tile_27 = new Tile;
	Tile_27->type.insert(type.end(), {2,1,2,2,2,3,2,2}); // has deer
	Tile_27.clusterid = {};
	Tile_27.meeple = {false,false,false,false,false,false,false,false};
	Tile_27.prey = "deer";
	
	placeTile(50, 50, Mappy, TileA);
	int x = 0;
	while x<8
	{
		cout<< "TileA type side = " << x <<  Mappy.TileGrid[50][50].type(x);
	}
	
}
