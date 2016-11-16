#include <iostream>
#include <vector>
//#include "MapClass.cpp"

using namespace std;

class Map;

class Player
{
public:
	int MeepleCountMe;
	int MeepleCountYou;
	int ScoreMe;
	int ScoreYou;
	int TilesRemaining;
	Map PlayerMap = new Map;
};