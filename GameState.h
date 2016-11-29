#include <string>

#ifndef GAMESTATE_H_
#define GAMESTATE_H_

class GameState{

public:
    virtual ~GameState(){};
    virtual void processInfo() = 0;
    virtual int nextStateLogic() = 0;
};

//Game states classes declaration
class state_START : public GameState{
private:
    std::string message;
public:
    state_START();
    ~state_START();

    void processInfo();
    int nextStateLogic();
};

class state_PLAYER1TURN : public GameState{
private:
    std::string message;
public:
    state_PLAYER1TURN();
    ~state_PLAYER1TURN();

    void processInfo();
    int nextStateLogic();
};

class state_PLAYER2TURN : public GameState{
private:
    std::string message;
public:
    state_PLAYER2TURN();
    ~state_PLAYER2TURN();

    void processInfo();
    int nextStateLogic();
};

class state_END : public GameState{
public:
    std::string message;
    state_END();
    ~state_END();

    void processInfo();
    int nextStateLogic();
};

#endif