#include <iostream>
#include <vector>
using namespace std;

class TileRegion
{
	int type; //1 - N, 2 - NE, 3 - E, 4 - SE, 5 - S, 6 - SW, 7- - W, 8 - NW   1,3,5,7 = sides 2,4,6,8 = corners
	int clusterid;
	bool meeple;
public:
	TileRegion() : type(8), clusterid(8), meeple(8) {}
};