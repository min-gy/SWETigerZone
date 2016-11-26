#include <vector>
#include <iostream>
#include "GameEngine.cpp"
//#include "GameState.h"
//#include "PlayerClass.cpp"

using namespace std;

int main (int argc, char *argv[]){
    GameEngine * ourGameEngine = new GameEngine();
    int tempNextState;

    //initialize game to Start state
    ourGameEngine->init();

    //cout << ourGameEngine->getCurrentStateEnum() << endl;

    //game loop
    while(ourGameEngine->getCurrentStateEnum() != END){
        tempNextState = ourGameEngine->currentState->nextStateLogic();
        ourGameEngine->setNextState(tempNextState);
        ourGameEngine->changeState();
    }

    delete ourGameEngine->currentState;

}

//game running
//interface with two players
//Netowrk interface will use the Player/Game Interface to call two players into two games
//Game 
//this GameMain should start the GameEngine and test the game running while allowing the game to interface with players using the Game/Player interface
//Game/Player INterface will later have its own main and take in info from server and interface with 