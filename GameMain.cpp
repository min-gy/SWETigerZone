#include <vector>
#include <iostream>
#include "PlayerClass.cpp"
//#include "Client.cpp"

using namespace std;

int main (int argc, char *argv[]){
    int cid;
    int roundNum;
    vector<int> rid;
    Player * player1 = new Player();
    Player * player2 = new Player();

    //Client calls 
    

    //WELCOME <pid> PLEASE WAIT FOR THE NEXT CHALLENGE
        //do nothing

    //NEW CHALLENGE <cid> YOU WILL PLAY <rounds> MATCH(ES)
        //cid = 

    //BEGIN ROUND <rid> of <rounds>

    //YOUR OPPONENT IS PLAYER <pid>

    //STARTING TILE IS <tile> AT <x> <y> <orientation>

    //THE REMAINING <number_tiles> TILES ARE [<tiles>]

        //store tile order

    //MATCH BEGINS IN <time> SECONDS

    //MAKE YOUR MOVE IN GAME <gid> WITHIN <time> SECOND(S): MOVE <#> PLACE <tile>
    
        //compute move

    //GAME <gid> MOVE <#> PLAYER <pid> (<move> or FORFEITED:)

        //update map with other player's move
    
    //GAME <gid> OVER PLAYER <pid> <score> PLAYER <pid> <score>

    //END OF ROUND <rid> OF <rounds> (PLEASE WAIT FOR THE NEXT MATCH)

    //END OF CHALLENGES

    //PLEASE WAIT FOR THE NEXT CHALLENGE TO BEGIN

    //THANK YOU FOR PLAYING! GOODBYE

    

    //player waits for client's message of "game started"
    //player1->startNewGame();
    //player1->runGame();

    //player's turn or oppo's turn
        //change game state based on that

    //if player's turn
        //game state change to player's turn
        //make decision
        //give move to server
        //give move to local game
    //if else oppo's turn
        //game state change to oppo's turn
        //wait for oppo's move from server
        //get oppo's move
    
    //change game state

    
    //player make dec
    



}

//game running
//interface with two players
//Netowrk interface will use the Player/Game Interface to call two players into two games
//Game 
//this GameMain should start the GameEngine and test the game running while allowing the game to interface with players using the Game/Player interface
//Game/Player INterface will later have its own main and take in info from server and interface with 