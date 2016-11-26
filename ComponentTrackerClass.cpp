#include <iostream>
#include <vector>
using namespace std;
class ComponentTracker
{
public:
	int ClusterId;
	int ParentId;
	int IncompleteSides;
	int TileCount; //Includes tilecount + Shield value
	//int TileRegion; //Castle = 1, Field = 2, Path = 3
	int MeepleCountMe;
	int MeepleCountYou;
	bool Boar;
	bool Deer;
	bool Ox;
	int CrocCount;
};

/*ComponentTrackerUpdate() WRITE IT*/
