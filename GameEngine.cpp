#include <iostream>
#include <vector>
#include <string>
//#include "GameState.h"
//#include "MapClass.cpp"

using namespace std;

//gamestates tracker
const int NULLSTATE = 0;
const int START = 1;
const int PLAYER1TURN = 2;
const int PLAYER2TURN = 3;
const int END = 4;

//Game Engine declarations
class GameEngine{

public:
    //Map * myMap;
    //GameState * currentState = NULL;
    //int nextStateEnum = NULLSTATE;
    //int currentStateEnum = NULLSTATE;
    int score;

    GameEngine();
    ~GameEngine();

    void init();
    void makeMyMove_g();
    void addFirstTile_g(string, int, int, int);
    void placeMyMove_g(string, int, int, int);
    //void placeOppoMove_g();

    //int getCurrentStateEnum();

    //void changeState();
    //void setNextState(int newStateEnum);

};


///////////////////////////////////////////// Above coul go in a header file

//Game engine class definition
GameEngine::GameEngine(){
    //myMap = new Map();
}

GameEngine::~GameEngine(){

}

void GameEngine::init(){
    //currentStateEnum = START;
    //currentState = new state_START();
}

void GameEngine::addFirstTile_g(string tile, int x, int y, int orientation){
    //myMap->addTile(tile, x, y, orientation);
}

void GameEngine::placeMyMove_g(string tile, int x, int y, int orientation){
    // take in int * move, int usOrThem
	//place myMove
    //modifie map
    //if usOrThem = 0;//us
        //update OUR comptrackers
        //update OUR meeples
    //if usOrThem = 1; //them
        //update THEIR comptrackers
        //update THEIR meeples
    //returning int* meeple count....
}
// void GameEngine::setNextState(int newStateEnum){
//     this->nextStateEnum = newStateEnum;
//     // if(nextStateEnum != END){
//     //     this->nextStateEnum = newStateEnum;
//     // }

// }

// void GameEngine::changeState(){
//     if(nextStateEnum != NULLSTATE){
        
//         // if(nextStateEnum != END){
//         //     delete currentState;
//         // }
//         delete currentState;
//         //change state for real, not just enum
//         switch(nextStateEnum){
//             case START:
//                 GameEngine::currentState = new state_START();
//                 break;

//             case PLAYER1TURN: 
//                 GameEngine::currentState = new state_PLAYER1TURN();
//                 break;

//             case PLAYER2TURN: 
//                 GameEngine::currentState = new state_PLAYER2TURN();
//                 break;

//             case END: 
//                 GameEngine::currentState = new state_END();
//                 break;
//         }

//         currentStateEnum = nextStateEnum;
//         nextStateEnum = NULLSTATE;

//     }
// }

//get parent tracker
// int GameEngine::makeMyMove_g(){
//     FullComponentUpdate()
// }

// void InheritValue(ComponentTracker* Child, ComponentTracker* Parent) 
// {
// 	if ( Child->Ox == true)
// 	{
// 		Parent->Ox = true;
// 	}
// 	if ( Child->Deer == true)
// 	{
// 		Parent->Deer = true;
// 	}
// 	if ( Child->Boar == true)
// 	{
// 		Parent->Boar = true;
// 	}
// 	Parent->CrocCount = Parent->CrocCount + Child->CrocCount;
// 	Parent->MeepleCountYou += Child->MeepleCountYou;
// 	Parent->MeepleCountMe += Child->MeepleCountMe;
// 	Parent->IncompleteSides += Child->IncompleteSides;
// 	Parent->TileCount += Child->TileCount;
// 	Child->ParentId = Parent->ParentId;
// 	//Delete Child from 'To-Check' List ```````````````WITHIN MAPCLASS``````````````````
// 	//Only Check parents for scoring and updates
// }
// int ScoreUpdate(ComponentTracker* Region)
// {
// 	//score calc
// 	int score;
// 	int game;
// 	game = 0;
// 	score = Region->TileCount;
// 	if ( Region->Boar == true)
// 	{
// 		game += 1;
// 	}
// 	if ( Region->Deer == true)
// 	{
// 		game += 1;
// 	}
// 	if ( Region->Ox == true)
// 	{
// 		game += 1;
// 	}
// 	game -= Region->CrocCount;
// 	if ( game > 0 )
// 	{
// 		score += game;
// 	}
// 	if ( Region->IncompleteSides == 0 )
// 	{
// 		score = score * 2;
// 	}
// 	return score;
// }
// int DenScoreUpdate(ComponentTracker* Region)
// {
// 	int score;
// 	score = 8 - Region->IncompleteSides;
// 	return score;
// }
// int MeepleUpdateMe(ComponentTracker* Region)
// {
// 	/*player.MeepleCountMe += Region->MeepleCountMe;
// 	player.MeepleCountYou += Region->MeepleCountYou;
// 	Region->MeepleCountMe = 0;
// 	Region->MeepleCountYou = 0;*/
// 	return Region->MeepleCountMe;

// }
// int MeepleUpdateYou(ComponentTracker* Region)
// {
// 	/*player.MeepleCountMe += Region->MeepleCountMe;
// 	player.MeepleCountYou += Region->MeepleCountYou;
// 	Region->MeepleCountMe = 0;
// 	Region->MeepleCountYou = 0;*/
// 	return Region->MeepleCountYou;

// }
// void DenCheck(Map Mappy, int X, int Y, int NewX, int NewY, int * values)
// {
// 	if(Mappy.TileGrid[NewX][NewY].orientation != NULL)
// 	{
// 		if(Mappy.TileGrid[X][Y].Monastery == true)
// 		{
// 			Mappy.MainList[Mappy.TileGrid[X][Y].CenterClusterid]->IncompleteSides -= 1;
// 			if (Mappy.MainList[Mappy.TileGrid[X][Y].CenterClusterid]->IncompleteSides == 0)
// 			{
// 				if (Mappy.MainList[Mappy.TileGrid[X][Y].CenterClusterid]->MeepleCountMe == 1)
// 				{
// 					values[3] += DenScoreUpdate(Mappy.MainList[Mappy.TileGrid[X][Y].CenterClusterid]);
// 				}
// 				if (Mappy.MainList[Mappy.TileGrid[X][Y].CenterClusterid]->MeepleCountYou == 1)
// 				{
// 					values[4] += DenScoreUpdate(Mappy.MainList[Mappy.TileGrid[X][Y].CenterClusterid]);
// 				}
// 				values[1] += MeepleUpdateMe(Mappy.MainList[Mappy.TileGrid[X][Y].CenterClusterid]);
// 				values[2] += MeepleUpdateYou(Mappy.MainList[Mappy.TileGrid[X][Y].CenterClusterid]);
// 			}
// 		}
// 		if(Mappy.TileGrid[NewX][NewY].Monastery == true)
// 		{
// 			Mappy.MainList[Mappy.TileGrid[NewX][NewY].CenterClusterid]->IncompleteSides -= 1;
// 			if (Mappy.MainList[Mappy.TileGrid[NewX][NewY].CenterClusterid]->IncompleteSides == 0)
// 			{
// 				if (Mappy.MainList[Mappy.TileGrid[NewX][NewY].CenterClusterid]->MeepleCountMe == 1)
// 				{
// 					values[3] += DenScoreUpdate(Mappy.MainList[Mappy.TileGrid[NewX][NewY].CenterClusterid]);
// 				}
// 				if (Mappy.MainList[Mappy.TileGrid[NewX][NewY].CenterClusterid]->MeepleCountYou == 1)
// 				{
// 					values[4] += DenScoreUpdate(Mappy.MainList[Mappy.TileGrid[NewX][NewY].CenterClusterid]);
// 				}
// 				values[1] += MeepleUpdateMe(Mappy.MainList[Mappy.TileGrid[NewX][NewY].CenterClusterid]);
// 				values[2] += MeepleUpdateYou(Mappy.MainList[Mappy.TileGrid[NewX][NewY].CenterClusterid]);
// 			}
// 		}
// 	}
// }
// void DenUpdate(Map Mappy, int X, int Y, int * values)
// {
// 	if (Mappy.TileGrid[X][Y].Monastery == true)
// 	{
// 		DenCheck(Mappy, X, Y, X+1, Y, values);
// 		DenCheck(Mappy, X, Y, X+1, Y+1, values);
// 		DenCheck(Mappy, X, Y, X+1, Y-1, values);
// 		DenCheck(Mappy, X, Y, X-1, Y, values);
// 		DenCheck(Mappy, X, Y, X-1, Y+1, values);
// 		DenCheck(Mappy, X, Y, X-1, Y-1, values);
// 		DenCheck(Mappy, X, Y, X, Y+1, values);
// 		DenCheck(Mappy, X, Y, X, Y-1, values);
// 	}
// }
// void SingleUpdate(Map Mappy, Tile CurrentTile, Tile OldTile, int newS, int oldS, int Side, int * values)
// {
// 	int x;
// 	int y;
// 	bool DontAdd;
// 	DontAdd = false;
// 	//Catch for nonexistent tile
// 	if (OldTile.orientation != NULL && CurrentTile.type.at(newS) != 4)
// 	{
// 		if (CurrentTile.type.at(newS) == OldTile.type.at(oldS))
// 		{
// 			//Special Check for corner Jungle -> Jungle
// 			if ((newS % 2 == 1) && (CurrentTile.type.at(newS) == 2))
// 			{
// 				switch(Side)
// 				{
//       			  	case 1: 
//       			  		if (OldTile.type.at(6) == 1)
//       			  		{
//       			  			DontAdd = true;
//       			  		}
//       			  	break;
//  					case 2:
//  						if (OldTile.type.at(8) == 1)
//       			  		{
//       			  			DontAdd = true;
//       			  		}
//  					break;
//         			case 3:
//         				if (OldTile.type.at(2) == 1)
//       			  		{
//       			  			DontAdd = true;
//       			  		}
//         			break;
//         			case 4:
//         				if (OldTile.type.at(4) == 1)
//       			  		{
//       			  			DontAdd = true;
//       			  		}
//         			break;
//         		}
// 			}
// 			x = CurrentTile.clusterid.at(newS);
// 			y = OldTile.clusterid.at(oldS);

// 			while (x != Mappy.MainList[x]->ParentId)
// 			{
// 			 	x = Mappy.MainList[x]->ParentId;		
// 			 	if (x == y)
// 			 	{// REQUIRE CATCH FOR scenario in which y already absorbed into x->parent
// 			 		DontAdd = true;
// 			 	}	 	
// 			}	
// 			if (DontAdd == false)
// 			{
// 				while (y != Mappy.MainList[y]->ParentId)
// 				{
// 			 		y = Mappy.MainList[y]->ParentId;			 	
// 				}
// 				//InheritValue(ComponentTracker Child, ComponentTracker Parent)
// 				InheritValue(Mappy.MainList[x], Mappy.MainList[y]);
// 			}
// 			if ((newS % 2 == 0) && (CurrentTile.type.at(newS) != 2)) 
// 			{
// 				Mappy.MainList[y]->IncompleteSides -= 2;
// 				if ( Mappy.MainList[y]->IncompleteSides == 0 )
// 				{
// 					if (Mappy.MainList[y]->MeepleCountMe >= Mappy.MainList[y]->MeepleCountYou)
// 					{
// 						values[3] += ScoreUpdate(Mappy.MainList[y]);	
// 					}
// 					if (Mappy.MainList[y]->MeepleCountMe <= Mappy.MainList[y]->MeepleCountYou)
// 					{
// 						values[4] += ScoreUpdate(Mappy.MainList[y]);
// 					}
// 					values[1] += MeepleUpdateMe(Mappy.MainList[y]);
// 					values[2] += MeepleUpdateMe(Mappy.MainList[y]);
// 				}
// 			}
// 		}
// 	}
// }
// int * FullComponentUpdate(Map Mappy, int X, int Y)
// {
// 	int * values;
// 	values[1] = 0;
// 	values[2] = 0;
// 	values[3] = 0;
// 	values[4] = 0;
// 	Tile CurrentTile;
// 	Tile LeftTile;
// 	Tile RightTile;
// 	Tile UpTile;
// 	Tile DownTile;

// 	CurrentTile = Mappy.TileGrid[X][Y];

// 	LeftTile = Mappy.TileGrid[X-1][Y];
// 	RightTile = Mappy.TileGrid[X+1][Y];
// 	UpTile = Mappy.TileGrid[X][Y+1];
// 	DownTile = Mappy.TileGrid[X][Y-1];

// 	//SingleUpdate(Map Mappy, Tile CurrentTile, Tile OldTile, int newS, int oldS);
// 	SingleUpdate(Mappy, CurrentTile, UpTile, 1, 7, 1, values);
// 	SingleUpdate(Mappy, CurrentTile, UpTile, 2, 6, 1, values);
// 	SingleUpdate(Mappy, CurrentTile, UpTile, 3, 5, 1, values);

// 	SingleUpdate(Mappy, CurrentTile, RightTile, 3, 1, 2, values);
// 	SingleUpdate(Mappy, CurrentTile, RightTile, 4, 8, 2, values);
// 	SingleUpdate(Mappy, CurrentTile, RightTile, 5, 7, 2, values);

// 	SingleUpdate(Mappy, CurrentTile, DownTile, 5, 3, 3, values);
// 	SingleUpdate(Mappy, CurrentTile, DownTile, 6, 2, 3, values);
// 	SingleUpdate(Mappy, CurrentTile, DownTile, 7, 1, 3, values);

// 	SingleUpdate(Mappy, CurrentTile, LeftTile, 7, 5, 4, values);
// 	SingleUpdate(Mappy, CurrentTile, LeftTile, 8, 4, 4, values);
// 	SingleUpdate(Mappy, CurrentTile, LeftTile, 1, 3, 4, values);

// 	DenUpdate(Mappy, X, Y, values);
// 	return values;

// }
// int FullComponentUpdate(sdfs){

// }














//////////////////////////////////////////////////////////Game states classes definition//////////////////////////////
// state_START::state_START(){
//     message = "START state";
//     std::cout << message << "\n";
// }

// state_START::~state_START(){

// }

// void state_START::processInfo(){

// }

// int state_START::nextStateLogic(){
//     return PLAYER1TURN;
// }


// state_PLAYER1TURN::state_PLAYER1TURN(){
//     message = "PLAYER1TURN state";
//     std::cout << message << "\n";
// }

// state_PLAYER1TURN::~state_PLAYER1TURN(){

// }

// void state_PLAYER1TURN::processInfo(){

// }

// int state_PLAYER1TURN::nextStateLogic(){
//     return PLAYER2TURN;
// }


// state_PLAYER2TURN::state_PLAYER2TURN(){
//     message = "PLAYER2TURN state";
//     std::cout << message << "\n";
// }

// state_PLAYER2TURN::~state_PLAYER2TURN(){

// }

// void state_PLAYER2TURN::processInfo(){

// }

// int state_PLAYER2TURN::nextStateLogic(){
//     return END;
// }


// state_END::state_END(){
//     state_END::message = "END state";
//     std::cout << message << "\n";    
// }

// state_END::~state_END(){

// }

// void state_END::processInfo(){

// }

// int state_END::nextStateLogic(){
//     return NULLSTATE;
// }


