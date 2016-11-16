#include <iostream>
#include <vector>

using namespace std;

class ComponentTracker
{
public:
	int ClusterId;
	int IncompleteSides;
	int Value; //Includes tilecount + Shield value
	int TileRegion; //Castle = 1, Field = 2, Path = 3
};