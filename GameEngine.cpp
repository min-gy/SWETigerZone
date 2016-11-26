#include <iostream>
#include <vector>
#include <string>
#include "GameState.h"
//#include "MapClass.cpp"

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
    GameState * currentState = NULL;
    int nextStateEnum = NULLSTATE;
    int currentStateEnum = NULLSTATE;

    GameEngine();
    ~GameEngine();

    void init();
    void changeState();
    void setNextState(int newStateEnum);

    int getCurrentStateEnum();

};


///////////////////////////////////////////// Above coul go in a header file

//Game engine class definition
GameEngine::GameEngine(){
    //myMap = new Map();
}

GameEngine::~GameEngine(){

}

void GameEngine::init(){
    currentStateEnum = START;
    currentState = new state_START();
}

void GameEngine::setNextState(int newStateEnum){
    this->nextStateEnum = newStateEnum;
    // if(nextStateEnum != END){
    //     this->nextStateEnum = newStateEnum;
    // }

}

void GameEngine::changeState(){
    if(nextStateEnum != NULLSTATE){
        
        // if(nextStateEnum != END){
        //     delete currentState;
        // }
        delete currentState;
        //change state for real, not just enum
        switch(nextStateEnum){
            case START:
                GameEngine::currentState = new state_START();
                break;

            case PLAYER1TURN: 
                GameEngine::currentState = new state_PLAYER1TURN();
                break;

            case PLAYER2TURN: 
                GameEngine::currentState = new state_PLAYER2TURN();
                break;

            case END: 
                GameEngine::currentState = new state_END();
                break;
        }

        currentStateEnum = nextStateEnum;
        nextStateEnum = NULLSTATE;

    }
}

int GameEngine::getCurrentStateEnum(){
    return GameEngine::currentStateEnum;
}


///////////Game states classes definition
state_START::state_START(){
    message = "START state";
    std::cout << message << "\n";
}

state_START::~state_START(){

}

void state_START::processInfo(){

}

int state_START::nextStateLogic(){
    return PLAYER1TURN;
}


state_PLAYER1TURN::state_PLAYER1TURN(){
    message = "PLAYER1TURN state";
    std::cout << message << "\n";
}

state_PLAYER1TURN::~state_PLAYER1TURN(){

}

void state_PLAYER1TURN::processInfo(){

}

int state_PLAYER1TURN::nextStateLogic(){
    return PLAYER2TURN;
}


state_PLAYER2TURN::state_PLAYER2TURN(){
    message = "PLAYER2TURN state";
    std::cout << message << "\n";
}

state_PLAYER2TURN::~state_PLAYER2TURN(){

}

void state_PLAYER2TURN::processInfo(){

}

int state_PLAYER2TURN::nextStateLogic(){
    return END;
}


state_END::state_END(){
    state_END::message = "END state";
    std::cout << message << "\n";    
}

state_END::~state_END(){

}

void state_END::processInfo(){

}

int state_END::nextStateLogic(){
    return NULLSTATE;
}


