#include <iostream>
#include <vector>
//#include "MapClass.cpp"

using namespace std;

class Player
{
	int MeepleCountMe;
	int MeepleCountYou;
	int ScoreMe;
	int ScoreYou;
	int TilesRemaining;
	Map PlayerMap = new Map;
};