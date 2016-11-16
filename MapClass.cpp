#include <iostream>
#include <vector>
//#include "TileClass.cpp"
//#include "ComponentTrackerClass.cpp"

using namespace std;

class Tile;
class ComponentTracker;

class Map
{
public:
	ComponentTracker * MainList[100]; //Main component tracking feature of Map/Terrain
	Tile TileGrid[153][153];
};