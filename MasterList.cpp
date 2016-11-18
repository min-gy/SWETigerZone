#include <iostream>
#include <vector>
#include "TileClass.cpp"
#include "MapClass.cpp"

using namespace std;

int main
{
/// 1 = River, 2 = Jungle, 3 = Trail.
/// cluster IDs are arbitrary 
/// for the sake of "competeing corners" jungle takes presedense over river.  
/// there doesn't seem to be anyway to determine the differnece between tiles 12 and 13 soley by edge detection.
/// May need variable to detect the center of the tile to detect differnce. 

Map Mappy = new Map;
	Tile * Tile_1 = new Tile;
	Tile_1->type.insert(type.end(), {2,2,2,2,2,2,2,2});
	Tile_1->clusterid.insert(clusterid.end(),{1,1,1,1,1,1,1,1});
	Tile_1.meeple = {false,false,false,false,false,false,false,false};
	Tile_1.Ox = false;
	Tile_1.Boar = false;
	Tile_1.Deer = false;
	
	
	
	
	Tile * Tile_2 = new Tile;
	Tile_2->type.insert(type.end(), {2,2,2,2,2,2,2,2}); // has den
	Tile_2->clusterid.insert(clusterid.end(), {1,1,1,1,1,1,1,1});
	Tile_2.meeple = {false,false,false,false,false,false,false,false};
	//Tile_2.prey = "none";	
	Tile_2.Ox = false;
	Tile_2.Boar = false;
	Tile_2.Deer = false;
	
        Tile * Tile_3 = new Tile;
	Tile_3->type.insert(type.end(),  {2,2,2,2,2,3,2,2}); // has den
	Tile_3->clusterid.insert(clusterid.end(),{1,1,1,1,1,1,1,1});
	Tile_3.meeple = {false,false,false,false,false,false,false,false};
	//Tile_3.prey = "none";	
	Tile_3.Ox = false;
	Tile_3.Boar = false;
	Tile_3.Deer = false;
	
	Tile * Tile_4 = new Tile;
	Tile_4->type.insert(type.end(),  {2,3,2,3,2,3,2,3});
	Tile_4->clusterid.insert(clusterid.end(),{1,2,1,2,1,2,1,2});
	Tile_4.meeple = {false,false,false,false,false,false,false,false};
	//Tile_4.prey = "none";	
	Tile_4.Ox = false;
	Tile_4.Boar = false;
	Tile_4.Deer = false;
	
	Tile * Tile_5 = new Tile;
	Tile_5->type.insert(type.end(), {2,3,2,2,2,3,2,2});
	Tile_5->clusterid.insert(clusterid.end(),{1,2,1,1,1,2,1,1});
	Tile_5.meeple = {false,false,false,false,false,false,false,false};
	//Tile_5.prey = "none";	
	Tile_5.Ox = false;
	Tile_5.Boar = false;
	Tile_5.Deer = false;
	
	Tile * Tile_6 = new Tile;	
	Tile_6->type.insert(type.end( {2,3,2,2,2,2,2,3});
	Tile_6->clusterid.insert(clusterid.end(),{1,2,1,1,1,1,1,2});
	Tile_6.meeple = {false,false,false,false,false,false,false,false};
	//Tile_6.prey = "none";	
	Tile_6.Ox = false;
	Tile_6.Boar = false;
	Tile_6.Deer = false;
	
	Tile * Tile_7 = new Tile;
	Tile_7->type.insert(type.end(),  {2,3,2,2,2,2,3,2,3});
	Tile_7->clusterid.insert(clusterid.end(),{1,2,1,1,1,2,1,2});
	Tile_7.meeple = {false,false,false,false,false,false,false,false};	
	//Tile_7.prey = "none";	
	Tile_7.Ox = false;
	Tile_7.Boar = false;
	Tile_7.Deer = false;
	
	Tile * Tile_8 = new Tile;
	Tile_8->type.insert(type.end(), {1,1,1,1,1,1,1,1});
	Tile_8->clusterid.insert(clusterid.end(),{1,1,1,1,1,1,1});
	Tile_8.meeple = {false,false,false,false,false,false,false,false};	
	//Tile_8.prey = "none";
	Tile_8.Ox = false;
	Tile_8.Boar = false;
	Tile_8.Deer = false;
	
	
	Tile * Tile_9 = new Tile;
	Tile_9->type.insert(type.end(), {2,2,2,1,1,1,1,1});
	Tile_9->clusterid.insert(clusterid.end(),{1,1,1,2,2,2,2,2});
	Tile_9.meeple = {false,false,false,false,false,false,false,false};
       // Tile_9.prey = "none";
       Tile_9.Ox = false;
	Tile_9.Boar = false;
	Tile_9.Deer = false;
	
	
	Tile * Tile_10 = new Tile;
	Tile_10->type.insert(type.end(),   {2,1,1,1,2,2,2,2});
	Tile_10->clusterid.insert(clusterid.end(),{1,2,2,2,1,1,1,1});
	Tile_10.meeple = {false,false,false,false,false,false,false,false};
	//Tile_10.prey = "none";
	Tile_10.Ox = false;
	Tile_10.Boar = false;
	Tile_10.Deer = false;
	
	
	Tile * Tile_11 = new Tile;
	Tile_11->type.insert(type.end(),  {2,2,2,1,2,2,2,1});/////
	Tile_11->clusterid.insert(clusterid.end(),{1,1,1,2,3,3,3,2});
	Tile_11.meeple = {false,false,false,false,false,false,false,false};
	//Tile_11.prey = "none";
	Tile_11.Ox = false;
	Tile_11.Boar = false;
	Tile_11.Deer = false;
	
	
	Tile * Tile_12 = new Tile;
	Tile_12->type.insert(type.end(), {2,1,2,2,2,1,2,2});////
	Tile_12->clusterid.insert(clusterid.end(),{1,2,1,1,1,3,1,1});
	Tile_12.meeple = {false,false,false,false,false,false,false,false};
	//Tile_12.prey = "none";
	Tile_12.Ox = false;
	Tile_12.Boar = false;
	Tile_12.Deer = false;
	
	Tile * Tile_13 = new Tile;
	Tile_13->type.insert(type.end(),  {2,1,2,2,2,2,2,2});
	Tile_13->clusterid.insert(clusterid.end(),{1,2,1,1,1,1,1,1});
	Tile_13.meeple = {false,false,false,false,false,false,false,false};
	//Tile_13.prey = "none";
	Tile_13.Ox = false;
	Tile_13.Boar = false;
	Tile_13.Deer = false;
	
	Tile *  Tile_14 = new Tile;
	Tile_14->type.insert(type.end(), {2,2,2,1,1,1,2,2});
	Tile_14->clusterid.insert(clusterid.end(),{1,1,1,2,2,2,1,1});
	Tile_14.meeple = {false,false,false,false,false,false,false,false};
	//Tile_14.prey = "none";
	Tile_14.Ox = false;
	Tile_14.Boar = false;
	Tile_14.Deer = false;
	
	Tile * Tile_15 = new Tile;
	Tile_15->type.insert(type.end(), {2,3,2,1,2,2,2,3});
	Tile_15->clusterid.insert(clusterid.end(),{1,2,1,3,1,1,1,2});
	Tile_15.meeple = {false,false,false,false,false,false,false,false};
	//Tile_15.prey = "none";
	Tile_15.Ox = false;
	Tile_15.Boar = false;
	Tile_15.Deer = false;
	
	Tile * Tile_16 = new Tile;
	Tile_16->type.insert(type.end(), {2,3,2,1,2,2,2,3}); // has boar
	Tile_16->clusterid.insert(clusterid.end(),{1,2,1,3,1,1,1,2});
	Tile_16.meeple = {false,false,false,false,false,false,false,false};
	//Tile_16.prey = "boar";
	Tile_16.Ox = false;
	Tile_16.Boar = true;
	Tile_16.Deer = false;
	
	Tile * Tile_17 = new Tile;
	Tile_17->type.insert(type.end(), {2,2,2,1,2,3,2,3});
	Tile_17->clusterid.insert(clusterid.end(),{1,1,1,2,1,3,4,3});
	Tile_17.meeple = {false,false,false,false,false,false,false,false};
	//Tile_17.prey = "none";
	Tile_17.Ox = false;
	Tile_17.Boar = false;
	Tile_17.Deer = false;
	
	Tile * Tile_18 = new Tile;
	Tile_18->type.insert(type.end(), {2,2,2,1,2,3,2,3}); // has ox
	Tile_18->clusterid.insert(clusterid.end(),{1,1,1,2,1,3,4,3});
	Tile_18.meeple = {false,false,false,false,false,false,false,false};
	//Tile_18.prey = "ox";
	Tile_18.Ox = true;
	Tile_18.Boar = false;
	Tile_18.Deer = false;
	
	Tile * Tile_19 = new Tile;
	Tile_19->type.insert(type.end(), {2,3,2,1,2,3,2,3});
	Tile_19->clusterid.insert(clusterid.end(),{1,2,3,4,3,2,1,1});
	Tile_19.meeple = {false,false,false,false,false,false,false,false};
	//Tile_19.prey = "none";
	Tile_19.Ox = false;
	Tile_19.Boar = false;
	Tile_19.Deer = false;
	
	Tile * Tile_20 = new Tile;
	Tile_20->type.insert(type.end(), {2,3,2,1,2,3,2,3}); // has deer	
	Tile_20->clusterid.insert(clusterid.end(),{1,2,3,4,3,2,1,1});
	Tile_20.meeple = {false,false,false,false,false,false,false,false};
	//Tile_20.prey = "deer";
	Tile_20.Ox = false;
	Tile_20.Boar = false;
	Tile_20.Deer = true;
	
	Tile * Tile_21 = new Tile;
	Tile_21->type.insert(type.end(), {2,3,2,1,1,1,1,1});
	Tile_21->clusterid.insert(clusterid.end(),{1,2,3,4,4,4,4,4});
	Tile_21.meeple = {false,false,false,false,false,false,false,false};
	//Tile_21.prey = "none";
	Tile_21.Ox = false;
	Tile_21.Boar = false;
	Tile_21.Deer = false;
	
	Tile * Tile_22 = new Tile;
	Tile_22->type.insert(type.end(), {2,3,2,1,2,2,2,3});
	Tile_22->clusterid.insert(clusterid.end(),{1,2,3,4,3,2,5,2});
	Tile_22.meeple = {false,false,false,false,false,false,false,false};
	//Tile_22.prey = "none";
	Tile_22.Ox = false;
	Tile_22.Boar = false;
	Tile_22.Deer = false;
	
	Tile * Tile_23 = new Tile;
	Tile_23->type.insert(type.end(), {2,3,2,1,2,2,2,3}); // has boar	
	Tile_23->clusterid.insert(clusterid.end(),{1,2,3,4,3,2,5,2});
	Tile_23.meeple = {false,false,false,false,false,false,false,false};
	//Tile_23.prey = "boar";
	Tile_23.Ox = false;
	Tile_23.Boar = true;
	Tile_23.Deer = false;

        Tile * Tile_24 = new Tile;
	Tile_24->type.insert(type.end(), {2,3,2,1,1,1,2,3});
	Tile_24->clusterid.insert(clusterid.end(),{1,2,3,4,4,4,3,2});
	Tile_24.meeple = {false,false,false,false,false,false,false,false};
	//Tile_24.prey = "none";
	Tile_24.Ox = false;
	Tile_24.Boar = false;
	Tile_24.Deer = false;
	
        Tile * Tile_25 = new Tile;
        Tile_25->type.insert(type.end(), {2,3,2,1,1,1,2,3}); // has ox
	Tile_25->clusterid.insert(clusterid.end(),{1,2,3,4,4,4,3,2});
	Tile_25.meeple = {false,false,false,false,false,false,false,false};
	//Tile_25.prey = "ox";
	Tile_25.Ox = true;
	Tile_25.Boar = false;
	Tile_25.Deer = false;
	
        Tile * Tile_26 = new Tile;
	Tile_26->type.insert(type.end(), {2,1,2,2,2,3,2,2});
	Tile_26->clusterid.insert(clusterid.end(),{1,2,3,3,3,4,1,1});
	Tile_26.meeple = {false,false,false,false,false,false,false,false};
	//Tile_26.prey = "none";
	Tile_26.Ox = false;
	Tile_26.Boar = false;
	Tile_26.Deer = false;
	
	Tile * Tile_27 = new Tile;
	Tile_27->type.insert(type.end(), {2,1,2,2,2,3,2,2}); // has deer
	Tile_27->clusterid.insert(clusterid.end(),{1,2,3,3,3,4,1,1});
	Tile_27.meeple = {false,false,false,false,false,false,false,false};
	//Tile_27.prey = "deer";
	Tile_27.Ox = false;
	Tile_27.Boar = false;
	Tile_27.Deer = true;
	
	placeTile(50, 50, Mappy, TileA);
	int x = 0;
	while (x<8)
	{
		cout<< "TileA type side = " << x <<  Mappy.TileGrid[50][50].type(x);
	}
	
}
