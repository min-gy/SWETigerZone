#ifndef GAMESTATE_H_
#define GAMESTATE_H_

class GameState{

public:
    virtual ~GameState(){};
    virtual void processInfo() = 0;
    virtual void logic() = 0;
};

#endif