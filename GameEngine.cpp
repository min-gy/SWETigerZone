#include <iostream>
#include <vector>
#include <string>
//#include "GameEngine.h"
#include "GameState.h"

using namespace std;

enum GameStates{
        NULLSTATE,
        START,
        PLAYER1TURN,
        PLAYER2TURN,
        END,
};

//Game Engine declarations
class GameEngine{

public:
    int nextStateEnum = NULLSTATE;
    GameState * currentState = NULL;
    int currentStateEnum = NULLSTATE;

    GameEngine();
    ~GameEngine();

    init();
    changeState();
    setNextState();

    int getCurrentStateEnum();

};


//Game states classes declaration
class state_START : public GameState{
private:
    string message;
public:
    state_START();
    ~state_START();

    void processInfo();
    void logic();
};

class state_PLAYER1TURN : public GameState{
private:
    string message;
public:
    state_PLAYER1TURN();
    ~state_PLAYER1TURN();

    void processInfo();
    void logic();
};

class state_PLAYER2TURN : public GameState{
private:
    string message;
public:
    state_PLAYER2TURN();
    ~state_PLAYER2TURN();

    void processInfo();
    void logic();
};

class state_END : public GameState{
private:
    string message;
public:
    state_END();
    ~state_END();

    void processInfo();
    void logic();
};

///////////////////////////////////////////// Above coul go in a header file

//Game engine class definition
GameEngine::GameEngine(){

}

GameEngine::~GameEngine(){

}

GameEngine::init(){
    currentStateEnum = START;
    currentState = new state_START()
}

void setNextState(int newState){

    if(GameEngine::nextStateEnum != END){
        GameEngine:nextStateEnum = newState;
    }
    //if next state is end...
}

void changeState(){
    if(GameEngine::nextStateEnum != NULLSTATE){
        
        if(GameEngine::nextStateEnum != END){
            delete currentState;
        }

        //change state for real, not just enum
        switch(GameEngine::nextStateEnum){
            case START:
                GameEngine::currentState = new START();
                break;

            case PLAYER1TURN: 
                GameEngine::currentState = new PLAYER1TURN();
                break;

            case PLAYER1TURN: 
                GameEngine::currentState = new PLAYER1TURN();
                break;

            case PLAYER1TURN: 
                GameEngine::currentState = new PLAYER1TURN();
                break;
        }

        GameEngine::currentStateEnum = GameEngine::nextStateEnum;
        GameEngine::nextStateEnum = NULLSTATE;

    }
}

int getCurrentStateEnum(){
    return currentState;
}

//Game states classes definition
state_START::state_START(){
    message = "START state";
}

state_START::~state_START(){

}

void state_START::processInfo(){

}

void state_START::logic(){
    setNextState = PLAYER1TURN;
}


state_PLAYER1TURN::state_PLAYER1TURN(){
    message = "PLAYER1TURN state";
}

state_PLAYER1TURN::~state_PLAYER1TURN(){

}

void state_PLAYER1TURN::processInfo(){

}

void state_PLAYER1TURN::logic(){
    setNextState = PLAYER2TURN;
}


state_PLAYER2TURN::state_PLAYER2TURN(){
    message = "PLAYER2TURN state";
}

state_PLAYER2TURN::~state_PLAYER2TURN(){

}

void state_PLAYER2TURN::processInfo(){

}

void state_PLAYER2TURN::logic(){
    setNextState = END;
}


state_END::state_END(){
    message = "END state";      
}

state_END::~state_END(){

}

void state_END::processInfo(){

}

void state_END::logic(){
    
}

