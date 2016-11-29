#include <iostream>
#include <vector>
//#include "MapClass.cpp"

#ifndef COMPTRACKER_H_
#define COMPTRACKER_H_

class CompTracker
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

	CompTracker();
	~CompTracker();
	

};

/*ComponentTrackerUpdate() WRITE IT*/

#endif