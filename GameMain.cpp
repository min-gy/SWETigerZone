#include <vector>
#include <iostream>
#include "GameEngine.h"
#include "GameState.h"
//#include "PlayerClass.cpp"

int main (int argc, char *argv[]){
    GameEngine * ourGameEngine = new GameEngine();

    //initialize game to Start state
    ourGameEngine.init();

    //game loop
    while(getCurrentStateEnum() != END){
        ourGameEngine->currentState->logic();

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