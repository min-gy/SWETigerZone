#include <iostream>
#include <vector>
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

	int tempNextState;

	Player();
	~Player();

	void startNewGame();
	void runGame();
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

void Player::cleanUpGame(){
	delete myGameEngine->currentState;
}

void Player::makeMyMove_p(){
	myGameEngine->makeMyMove_g(move argument);
}

void Player::makeOppoMove_p(){
	//myGameEngine->makeOppoMove_g(move argument)
}

