#include <iostream>
#include <vector>
#include <string>
#include "GameEngine.cpp"
#include "TileClass.cpp"

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
	void placeMove_p(int*, int);
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

int* Player::makeMyMove_p(string tile){
	//AI algorithm to decide to make move
	myGameEngine->getSomething();

	int X;
	int Y;
	int orientation;
	//return myMovePtr;
	int myMove[3] = {X, Y, orientation};
	int* ptr = &success[0];
	return ptr;
}

void Player::placeMove_p(string tile, int * move, int usOrThem){
	//something that gives function arguments below
	myGameEngine->placeMyMove_g(tile, x, y, orientation, urOrThem);

	//
}


void Player::getTileStack(string tileString){
	tileStack = tileString;
}




