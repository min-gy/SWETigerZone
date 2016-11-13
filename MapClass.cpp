#include <iostream>
#include <vector>
#include "TileClass.cpp"
#include "ComponentTrackerClass.cpp"
using namespace std;

public class Map
{
	ComponentTracker * MainList = ComponentTracker[100]; //Main component tracking feature of Map/Terrain
	Tile ** TileGrid = Tile[153][153];
}