#include <iostream>
#include <vector>
#include "MapClass.cpp"

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
	
	void InheritValues(CompTracker*, CompTracker*);
	int ScoreUpdate(CompTracker*);
	int DenScoreUpdate(CompTracker*);
	void MeepleUpdate(CompTracker*, Player);
	void DenCheck(Map, int, int, int, int, Player);
	void DenUpdate(Map, int, int, Player);
	void SingleUpdate(Map, Tile, Tile, int, int, int, Player);
	void FullComponentUpdate(Map, int, int, Player);
};

/*ComponentTrackerUpdate() WRITE IT*/

#endif