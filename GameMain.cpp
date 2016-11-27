#include <vector>
#include <iostream>
#include "PlayerClass.cpp"
//#include "Client.cpp"

using namespace std;

int main (int argc, char *argv[]){
    Player * player1 = new Player();
    Player * player2 = new Player();

    //Client * client = new Client();

    

    player1->startNewGame();
    player1->runGame();



}

//game running
//interface with two players
//Netowrk interface will use the Player/Game Interface to call two players into two games
//Game 
//this GameMain should start the GameEngine and test the game running while allowing the game to interface with players using the Game/Player interface
//Game/Player INterface will later have its own main and take in info from server and interface with 