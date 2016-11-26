#include <iostream>
#include <vector>
//#include "MapClass.cpp"
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

	//Map * PlayerMap;
};

	int tempNextState;

	Player();
	~Player();

	void startNewGame();
	void runGame();
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

