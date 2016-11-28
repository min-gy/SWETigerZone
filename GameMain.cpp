#include <vector>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string>
#include <sstream>

#include "PlayerClass.cpp"
//#include "Client.cpp"

using namespace std;
void error(const char *msg);

int main (int argc, char *argv[]){
    string ourPlayerID;
    string oppoPlayerID;

    string gameID1 = "";
    string gameID2 = "";

    //move order: classification(holla for explaination), x, y, orientation, ZONE
    int ourGameMove1[5];
    int ourGameMove2[5];
    string tile;

    //move order: tile, x, y, orientation, NONE OR CROC OR TRIGER ,zone, 
    string theirGameMove1[6];
    string theirGameMove2[6];

    string tileStackString;

    int challengeID;
    int roundNum;
    vector<int> rid;




    Player * player1 = new Player();
    Player * player2 = new Player();

    //Client calls 
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    //char buffer[256];
    //std::string serverMsg;
    //char replyMsg[256];
    //std::string reply;

    if (argc < 6) {
       fprintf(stderr,"usage %s hostname port\n", argv[0]);
       exit(0);
    }
    portno = atoi(argv[2]);
    std::string tournamentPassword(argv[3]);
    std::string teamUserName(argv[4]);
    std::string teamPassword(argv[5]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
        error("ERROR opening socket");

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }

    printf("Port Number: %d\nTournament Password: %s\nTeam UserName: %s\nTeam Password: %s\n\n",
            portno, tournamentPassword.c_str(), teamUserName.c_str(), teamPassword.c_str());
    //std::cout << "Port Number: " + portno + "\nTournament Password: " + tournamentPassword +
    //        "\nTeam UserName: " + teamUserName + "\nTeam Password: " + teamPassword + "\n";

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, 
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) 
        error("ERROR connecting");

    char buffer[1024];
    std::string serverMsg;
    char replyMsg[1024];
    std::string reply;

    while(1)
    {
      //read from server
      bzero(buffer, 1024);
      n = read(sockfd, buffer, 1023);
      if (n < 0) 
           error("ERROR reading from socket");
//      printf("%s\n", buffer);
    
      //convert message from server from char[] to string
      serverMsg = std::string(buffer);

      std::vector<std::string> strs;
      std::string tempstr;
      std::stringstream strstr;
      strstr.str(serverMsg);
      while(std::getline(strstr, tempstr, '\n'))
      {
        strs.push_back(tempstr);
      }
      for(int p = 0; p < strs.size(); p++)
      {
        //printf("%s\n\n\n", strs[p].c_str());
	serverMsg = strs[p];
      //}

      printf("%s\n\n\n", serverMsg.c_str());

//      reply = handleServerMessage(serverMsg);
      std::string arr[1024];
      std::stringstream ssin(serverMsg);
      for(int i = 0; ssin.good(); i++)
      {
        ssin >> arr[i];
      }
      
      if(arr[0].compare("THIS") == 0)
      {
        //THIS IS SPARTA!
        reply = "JOIN " + tournamentPassword + "\r\n";
      }
      else if(arr[0].compare("HELLO!") == 0)
      {
        //HELLO!
         reply = "I AM " + teamUserName + " " +  teamPassword + "\r\n";
      }
      else if(arr[0].compare("WELCOME") == 0)
      {
        //WELCOME <pid> PLEASE WAIT FOR THE NEXT CHALLENGE
        ourPlayerID = arr[1];
        reply = "wait\r\n";
      }
      else if(arr[0].compare("NEW") == 0)
      {
        //NEW CHALLENGE <cid> YOU WILL PLAY <rounds> MATCH(ES)
        challengeID = atoi(arr[2].c_str());
        roundNum = atoi(arr[6].c_str());
        reply = "wait\r\n";
      }
      else if(arr[0].compare("BEGIN") == 0)
      {
        //BEGIN ROUND <rid> of <rounds>
        rid.push_back(atoi(arr[2].c_str()));

        //start new game
        Player * player1 = new Player();
        player1->startNewGame();

        Player * player2 = new Player();
        player2->startNewGame();
        
        //player1->runGame();

        reply = "wait\r\n";
      }
      else if(arr[0].compare("YOUR") == 0)
      {
        //YOUR OPPONENT IS PLAYER <pid>
        oppoPlayerID = atoi(arr[4].c_str());
        reply = "wait\r\n";
      }
      else if(arr[0].compare("STARTING") == 0)
      {
        //STARTING TILE IS <tile> AT <x> <y> <orientation>
        player1->addFirstTile_p(arr[3], atoi(arr[5].c_str()), atoi(arr[6].c_str()), atoi(arr[7].c_str()) );
        player2->addFirstTile_p(arr[3], atoi(arr[5].c_str()), atoi(arr[6].c_str()), atoi(arr[7].c_str()) );
        reply = "wait\r\n";
      }
      else if(arr[0].compare("THE") == 0)
      {
        //THE REMAINING <number_tiles> TILES ARE [<tiles>]

        //make empty string
        tileStackString = "";
        for(int i = 6; 6 < 82; i++){
            tileStackString.append(arr[i] + " ");
        }
        
        player1->getTileStack(tileStackString);
        player2->getTileStack(tileStackString);
 
        //store tile order

        reply = "wait\r\n";
      }
      else if(arr[0].compare("MATCH") == 0)
      {
        //MATCH BEGINS IN <time> SECONDS
        reply = "wait\r\n";
      }
      else if(arr[0].compare("MAKE") == 0)
      {
        //MAKE YOUR MOVE IN GAME <gid> WITHIN <time> SECOND(S): MOVE <#> PLACE <tile>
        
        //if this is not for game2
        if (arr[5] != gameID2) {

            if(gameID1 == ""){
                gameID1 = arr[5];
            }

            //player compute move given Tile ID

            tile = arr[12];

            ourGameMove1 = player1->giveMyMove_p(arr[12]);
            

	    // if(ourGameMove1[0] == 0){

            reply = *(ourGameMove1) + *(ourGameMove1+1);

            

            // if(ourGameMove1[0] == 0){

            //     reply = "GAME " + gameID1 + "  PLACE " + arr[12] + " AT " + ourGameMove1[1] + " " + ourGameMove1[2] + " " + ourGameMove1[3] + " NONE\r\n";
            // }
            // else if(ourGameMove1[0] == 1){
            //     reply = "GAME " + gameID1 + " PLACE " + arr[12] + " AT " + ourGameMove1[1] + " " + ourGameMove1[2] + " " + ourGameMove1[3] + " CROCODILE\r\n";
            // }
            // else if(ourGameMove1[0] == 2){
            //      reply = "GAME " + gameID1 + " PLACE " + arr[12] + " AT " + ourGameMove1[1] + " " + ourGameMove1[2] + " " + ourGameMove1[3] + " TIGER " + ourGameMove1[4] + "\r\n";
            // }
            // else if(ourGameMove1[0] == 3){
            //     reply = "GAME " + gameID1 + " TILE " + arr[12] + " UNPLACEABLE PASS\r\n";
            // }
            // else if(ourGameMove1[0] == 4){
            //     reply = "GAME " + gameID1 + " TILE " + arr[12] + " UNPLACEABLE RETRIEVE TIGER AT " + ourGameMove1[1] + " " + ourGameMove1[2] + "\r\n";
            // }
            // else if(ourGameMove1[0] == 5){
            //     reply = "GAME " + gameID1 + " TILE " + arr[12] + " UNPLACEABLE ADD ANOTHER TIGER TO " + ourGameMove1[1] + " " + ourGameMove1[2] + "\r\n";
            // }

        } 
        //if this is not for game 1
        else if(arr[5] != gameID1 ){

            if(gameID2 == ""){
                gameID2 = arr[5];
            }
            tile = arr[12];
            //player compute move given Tile ID
            ourGameMove2 = player2->giveMyMove_p(arr[12]);
            reply = *(ourGameMove2) + *(ourGameMove2+1);

            // if(ourGameMove2[0] == 0){
            //     reply = "GAME " + gameID2 + "  PLACE " + arr[12] + " AT " + ourGameMove2[1] + " " + ourGameMove2[2] + " " + ourGameMove2[3] + " NONE\r\n";
            // }
            // else if(ourGameMove2[0] == 1){
            //     reply = "GAME " + gameID2 + " PLACE " + arr[12] + " AT " + ourGameMove2[1] + " " + ourGameMove2[2] + " " + ourGameMove2[3] + " CROCODILE\r\n";
            // }
            // else if(ourGameMove2[0] == 2){
            //      reply = "GAME " + gameID2 + " PLACE " + arr[12] + " AT " + ourGameMove2[1] + " " + ourGameMove2[2] + " " + ourGameMove2[3] + " TIGER " + ourGameMove2[4] + "\r\n";
            // }
            // else if(ourGameMove2[0] == 3){
            //     reply = "GAME " + gameID2 + " TILE " + arr[12] + " UNPLACEABLE PASS\r\n";
            // }
            // else if(ourGameMove2[0] == 4){
            //     reply = "GAME " + gameID2 + " TILE " + arr[12] + " UNPLACEABLE RETRIEVE TIGER AT " + ourGameMove2[1] + " " + ourGameMove2[2] + "\r\n";
            // }
            // else if(ourGameMove2[0] == 5){
            //     reply = "GAME " + gameID2 + " TILE " + arr[12] + " UNPLACEABLE ADD ANOTHER TIGER TO " + ourGameMove2[1] + " " + ourGameMove2[2] + "\r\n";
            // }
            
        }
        
      }


      else if(arr[0].compare("GAME") == 0 && arr[2].compare("MOVE") == 0)
      {
        //GAME <gid> MOVE <#> PLAYER <pid> (<move> or FORFEITED:)
        if(arr[6] != "FORFEITED:"){
            //update map with other player's move

            //check if for game1 or game2
            //if it's not for game 2 aka if it's for game1
            if (arr[1] != gameID2) {

                if(gameID1 == ""){
                    gameID1 = arr[1];
                }

                //if this move info is from opponent
                if(arr[5] == oppoPlayerID){
                    if(arr[6] == "PLACED"){

                        theirGameMove1[0] = arr[7];
                        theirGameMove1[1] = arr[8];
                        theirGameMove1[2] = arr[10];
                        theirGameMove1[3] = arr[11];

                        //classification: none, croc, or tiger
                        theirGameMove1[4] = arr[12];
                        
                        //if it's tiger, store zone
                        if(theirGameMove1[4] == "TIGER"){
                            theirGameMove1[5] = arr[13];
                        }
                    }
                    else if(arr[6] == "TILE"){
                        theirGameMove1[0] = arr[7];

                        if (arr[9] == "PASSED"){
                            //MAKE NOTE OF ITS
                        }
                        else if (arr[9] == "RETRIEVED"){
                            theirGameMove1[1] = arr[12];
                            theirGameMove1[2] = arr[13];
                        }
                        else if (arr[9] == "ADDED"){
                            theirGameMove1[1] = arr[13];
                            theirGameMove1[2] = arr[14];
                        }
                    }
                    //placing opponent's move
                    player1->placeMove_p(theirGameMove1, 1);
                }
                else{
                    //update my stuff
                    player1->placeMove_p(ourGameMove1, 0);
                }
                
            }
            //if this is not for game 1 aka if it's for game 2
            else if(arr[1] != gameID1 ){
                
                if(gameID2 == ""){
                    gameID2 = arr[1];
                }
                
                if(arr[5] == oppoPlayerID){
                    if(arr[6] == "PLACED"){

                        theirGameMove2[0] = arr[7];
                        theirGameMove2[1] = arr[8];
                        theirGameMove2[2] = arr[10];
                        theirGameMove2[3] = arr[11];

                        //classification: none, croc, or tiger
                        theirGameMove2[4] = arr[12];
                        
                        //if it's tiger, store zone
                        if(theirGameMove2[4] == "TIGER"){
                            theirGameMove2[5] = arr[13];
                        }
                    }
                    else if(arr[6] == "TILE"){
                        theirGameMove2[0] = arr[7];

                        if (arr[9] == "PASSED"){
                            //MAKE NOTE OF ITS
                        }
                        else if (arr[9] == "RETRIEVED"){
                            theirGameMove2[1] = arr[12];
                            theirGameMove2[2] = arr[13];
                        }
                        else if (arr[9] == "ADDED"){
                            theirGameMove2[1] = arr[13];
                            theirGameMove2[2] = arr[14];
                        }
                    }
                    //placing opponent's move
                    player2->placeMove_p(theirGameMove2, 1);
                }
                else{
                    //update my stuff
                    player2->placeMove_p(ourGameMove2, 0);
                }
                
            }
            //check
        }

        //modify our game based on given ....
        

        reply = "wait\r\n";
      }
      else if(arr[0].compare("GAME") == 0 && arr[2].compare("OVER") == 0)
      {
        //GAME <gid> OVER PLAYER <pid> <score> PLAYER <pid> <score>
        reply = "wait\r\n";
      }
      else if(arr[0].compare("END") == 0 && arr[2].compare("ROUND") == 0)
      {
        //END OF ROUND <rid> OF <rounds> (PLEASE WAIT FOR THE NEXT MATCH)
        player1->cleanUpGame();
        player2->cleanUpGame();

        delete player1;
        delete player2;
        reply = "wait\r\n";
      }
      else if(arr[0].compare("END") == 0 && arr[2].compare("CHALLENGES") == 0)
      {
        //END OF CHALLENGES
        reply = "wait\r\n";
      }
      else if(arr[0].compare("PLEASE") == 0)
      {
        //PLEASE WAIT FOR THE NEXT CHALLENGE TO BEGIN
        reply = "wait\r\n";
      }
      else if(arr[0].compare("THANK") == 0)
      {
        //THANK YOU FOR PLAYING! GOODBYE
        reply = "wait\r\n";
      }
      else
      {
        printf("Else Reached\r\n");
        reply = "wait\r\n";
      }

      //if the client needs to reply
      if(reply.compare("wait\r\n") != 0)
      {
        strncpy(replyMsg, reply.c_str(), sizeof(replyMsg));
        replyMsg[sizeof(replyMsg) - 1] = 0;

        n = write(sockfd, replyMsg, strlen(replyMsg));
        if (n < 0) 
             error("ERROR writing to socket");
      }

      } //end of '\n' for loop

/*      //reading
      bzero(buffer,256);
      n = read(sockfd, buffer, 255);
      if (n < 0) 
           error("ERROR reading from socket");
      printf("%s\n", buffer);
*/
 
 
/*      //writting
      reply = handleServerMessage(serverMsg);
      strncpy(replyMsg, reply.c_str(), sizeof(replyMsg));
      replyMsg[sizeof(replyMsg) - 1] = 0;
      n = write(sockfd, replyMsg, strlen(replyMsg));
      if (n < 0) 
           error("ERROR writing to socket");
*/


      //wait for user to want to continue
      //printf("Please press enter to continue: ");
      //bzero(buffer,256);
      //fgets(buffer,255,stdin);
    }

    close(sockfd);
    return 0;

    

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

void error(const char *msg)
{
    perror(msg);
    exit(0);
}
