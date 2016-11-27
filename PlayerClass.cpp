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
	int myMove[5];

	//int tempNextState;

	Player();
	~Player();

	void startNewGame();
	void runGame();
	void addFirstTile_p(string, int, int , int);
	void makeMyMove_p();
	void makeOppoMove_p();


	void cleanUpGame();
};

Player::Player(){

}

Player::~Player(){

}

void Player::startNewGame(){
	myGameEngine = new GameEngine();
	myGameEngine->init();
}

void Player::runGame(){
	while(myGameEngine->getCurrentStateEnum() != END){
        tempNextState = myGameEngine->currentState->nextStateLogic();
        myGameEngine->setNextState(tempNextState);
        myGameEngine->changeState();
    }
}

void Player::addFirstTile_p(string tile, int x, int y, int orientation){
	myGameEngine->addFirstTile_g(tile, x, y, orientation);
}

void Player::cleanUpGame(){
	delete myGameEngine->currentState;
}

int* Player::makeMyMove_p(string tile){
	//myGameEngine->makeMyMove_g(tile);
	//AI algorithm to decide to make move
	myMove[0]
}

void Player::makeOppoMove_p(){
	//myGameEngine->makeOppoMove_g(move argument)
}




