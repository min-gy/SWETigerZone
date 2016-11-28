#include <iostream>
#include <vector>
#include <string>
#include "GameEngine.cpp"

using namespace std;

class Player{

public:
	GameEngine * myGameEngine;
	int MeepleCountMe;
	int MeepleCountYou;
	int ScoreMe;
	int ScoreYou;
	int TilesRemaining;
	int * myMovePtr;
	int myMove[5];
	string tileStack;

	//myMovePtr = myMove;

	//int tempNextState;

	Player();
	~Player();

	void startNewGame();
	void runGame();
	void addFirstTile_p(string, int, int , int);
	int* giveMyMove_p(string);
	void makeOppoMove_p(string);
	void placeMyMove_p(int*);
	void getTileStack(string);
	void cleanUpGame();
};

Player::Player(){

}

Player::~Player(){

}

void Player::startNewGame(){
	myGameEngine = new GameEngine();
	//myGameEngine->init();
}

// void Player::runGame(){
// 	while(myGameEngine->getCurrentStateEnum() != END){
//         tempNextState = myGameEngine->currentState->nextStateLogic();
//         myGameEngine->setNextState(tempNextState);
//         myGameEngine->changeState();
//     }
// }

void Player::addFirstTile_p(string tile, int x, int y, int orientation){
	//myGameEngine->addFirstTile_g(tile, x, y, orientation);
	cout << "addFirstTile_p function sucessfully called";
}

void Player::cleanUpGame(){
	delete myGameEngine;
}

/*
int* Player::makeMyMove_p(string tile){
	//myGameEngine->giveMyMove_g(tile);
	
	//AI algorithm to decide to make move
	
	//return myMovePtr;

	int success[5] = {0, 1};
	int* ptr = &success[0];
	return ptr;
}
*/

void Player::placeMyMove_p(int * move){
	//myGameEngine->placeMyMove_g(tile);
}

/*
void Player::placeOppoMove_p(string move[]){
	//myGameEngine->makeOppoMove_g(move argument)
}
*/

void Player::getTileStack(string tileString){
	tileStack = tileString;
}




