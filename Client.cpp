//first start the server
//then the client
//./server.o 20001
//./client.o 127.0.0.1 20001

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

void error(const char *msg)
{
    perror(msg);
    exit(0);
}

std::string handleServerMessage(std::string message)
{
  std::string arr[13];
  std::stringstream ssin(message);
  for(int i = 0; ssin.good(); i++)
  {
    ssin >> arr[i];
  }

  if(arr[0].compare("THIS") == 0)
  {
    //THIS IS SPARTA!
    return "Join <tournament password>\r\n";
  }
  else if(arr[0].compare("HELLO!") == 0)
  {
    //HELLO!
    return "I AM <username> <password>\r\n";
  }
  else if(arr[0].compare("WELCOME") == 0)
  {
    //WELCOME <pid> PLEASE WAIT FOR THE NEXT CHALLENGE
    return "wait\r\n";
  }
  else if(arr[0].compare("NEW") == 0)
  {
    //NEW CHALLENGE <cid> YOU WILL PLAY <rounds> MATCH(ES)
    return "wait\r\n";
  }
  else if(arr[0].compare("BEGIN") == 0)
  {
    //BEGIN ROUND <rid> of <rounds>
    return "wait\r\n";
  }
  else if(arr[0].compare("YOUR") == 0)
  {
    //YOUR OPPONENT IS PLAYER <pid>
    return "wait\r\n";
  }
  else if(arr[0].compare("STARTING") == 0)
  {
    //STARTING TILE IS <tile> AT <x> <y> <orientation>
    return "wait\r\n";
  }
  else if(arr[0].compare("THE") == 0)
  {
    //THE REMAINING <number_tiles> TILES ARE [<tiles>]

    //store tile order

    return "wait\r\n";
  }
  else if(arr[0].compare("MATCH") == 0)
  {
    //MATCH BEGINS IN <time> SECONDS
    return "wait\r\n";
  }
  else if(arr[0].compare("MAKE") == 0)
  {
    //MAKE YOUR MOVE IN GAME <gid> WITHIN <time> SECOND(S): MOVE <#> PLACE <tile>
    
    //compute move

    //if(unplaceable)
    //{
    //  return "GAME <gid> TILE <tile> Unplaceable
    //          (PASS or RETRIEVE TIGER AT <x> <y> or ADD ANOTHER TIGER TO <x> <y>)\r\n";
    //}
    //else
    //{
      return "GAME <gid> PLACE <tile> AT <x> <y> <orientation> (NONE or CROCODILE or TIGER <zone>)\r\n";
    //}
  }
  else if(arr[0].compare("GAME") == 0 && arr[2].compare("MOVE") == 0)
  {
    //GAME <gid> MOVE <#> PLAYER <pid> (<move> or FORFEITED:)

    //update map with other player's move

    return "wait\r\n";
  }
  else if(arr[0].compare("GAME") == 0 && arr[2].compare("OVER") == 0)
  {
    //GAME <gid> OVER PLAYER <pid> <score> PLAYER <pid> <score>
    return "wait\r\n";
  }
  else if(arr[0].compare("END") == 0 && arr[2].compare("ROUND") == 0)
  {
    //END OF ROUND <rid> OF <rounds> (PLEASE WAIT FOR THE NEXT MATCH)
    return "wait\r\n";
  }
  else if(arr[0].compare("END") == 0 && arr[2].compare("ROUND") == 0)
  {
    //END OF CHALLENGES
    return "wait\r\n";
  }
  else if(arr[0].compare("PLEASE") == 0)
  {
    //PLEASE WAIT FOR THE NEXT CHALLENGE TO BEGIN
    return "wait\r\n";
  }
  else if(arr[0].compare("THANK") == 0)
  {
    //THANK YOU FOR PLAYING! GOODBYE
    return "wait\r\n";
  }
  else
  {
    return "Error: Else Reached";
    exit(1);
  }
}

int main(int argc, char *argv[])
{
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[256];
    std::string serverMsg;
    char replyMsg[256];
    std::string reply;

    if (argc < 3) {
       fprintf(stderr,"usage %s hostname port\n", argv[0]);
       exit(0);
    }
    portno = atoi(argv[2]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
        error("ERROR opening socket");

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, 
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) 
        error("ERROR connecting");

    while(1)
    {
      //read from server
      bzero(buffer,256);
      n = read(sockfd, buffer, 255);
      if (n < 0) 
           error("ERROR reading from socket");
      printf("%s\n", buffer);
    
      //convert message from server from char[] to string
      serverMsg = std::string(buffer);
      reply = handleServerMessage(serverMsg);

      //if the client needs to reply
      if(reply.compare("wait\r\n") != 0)
      {
        strncpy(replyMsg, reply.c_str(), sizeof(replyMsg));
        replyMsg[sizeof(replyMsg) - 1] = 0;

        n = write(sockfd, replyMsg, strlen(replyMsg));
        if (n < 0) 
             error("ERROR writing to socket");
      }


      //wait for user to want to continue
      //printf("Please press enter to continue: ");
      //bzero(buffer,256);
      //fgets(buffer,255,stdin);
    }

    close(sockfd);
    return 0;
}
