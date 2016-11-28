#include <iostream>
#include <vector>
#include <string>

#include "GameEngine.cpp"
#include "TileClass.cpp"

//#include "GameEngine.cpp"

using namespace std;

class Player{

public:
	GameEngine * myGameEngine;
	int MeepleCountMe;
	int MeepleCountYou;
	int ScoreMe;
	int ScoreYou;
	int TilesRemaining;
	int * myMovePtr;
	int myMove[5];
	string tileStack;
	vector<*Tile> tileStack;
	

	//myMovePtr = myMove;

	//int tempNextState;

	Player();
	~Player();

	void startNewGame();
	void runGame();
	void addFirstTile_p(string, int, int , int);
	int* giveMyMove_p(string);
	void placeMove_p(int*, int);
	void getTileStack(string);
	void cleanUpGame();
};

Player::Player(){

}

Player::~Player(){

}

void Player::startNewGame(){
	myGameEngine = new GameEngine();
	//myGameEngine->init();
}

// void Player::runGame(){
// 	while(myGameEngine->getCurrentStateEnum() != END){
//         tempNextState = myGameEngine->currentState->nextStateLogic();
//         myGameEngine->setNextState(tempNextState);
//         myGameEngine->changeState();
//     }
// }

void Player::addFirstTile_p(string tile, int x, int y, int orientation){
	//myGameEngine->addFirstTile_g(tile, x, y, orientation);
	cout << "addFirstTile_p function sucessfully called";
}

void Player::cleanUpGame(){
	delete myGameEngine;
}

/*
int* Player::makeMyMove_p(string tile){
	//AI algorithm to decide to make move
	myGameEngine->getSomething();

	int X;
	int Y;
	int orientation;
	//return myMovePtr;
	int myMove[3] = {X, Y, orientation};
	int* ptr = &success[0];
	return ptr;
}
*/

void Player::placeMove_p(string tile, int * move, int usOrThem){
	//something that gives function arguments below
	myGameEngine->placeMyMove_g(tile, x, y, orientation, urOrThem);

/*
void Player::placeOppoMove_p(string move[]){
	//myGameEngine->makeOppoMove_g(move argument)
}
*/


void Player::getTileStack(string tileString){
	for(size of tileString)
		take that specific string named temp
		temp2[0] = temp1[i];
		temp2[1] = temp1[i+1];
		temp2[2] = temp1[i+2];
		temp2[3] = temp1[i+3];
		temp2[4] = temp1[i+4];
		val = getTile(temp2);
		temp.push_back(val);

	//parse tileString to tileStack
}

tile getTile(char *temp2){
	char a = temp2[0];
	char b = temp2[1];
	char c = temp2[2];
	char d = temp2[3];
	char e = temp2[4];
	for(int i = 0; i < 28; i++){
		//tile structure holds all the hard coded values for each tile
		Tile temp = tileStructure(i);
		vector<char> temp1 = temp.des;
		if(a == temp1[0] && b == temp1[1] && c == temp1[2] && d == temp1[3] && e == temp1[4])
			return temp;
	}
}

Tile tileStructure(int i){
	if(i == 0){
		tile Tile_1;
		Tile tile_1 = new Tile(
						sdf,
						sdfs,
						sdf,
						sdf,
						....);
		Tile_1.des = {'J', 'J', 'J', 'J', '-'};
		Tile_1.type = {2,2,2,2,2,2,2,2};
		Tile_1.clusterid = {1,1,1,1,1,1,1,1};
		Tile_1.tiger = {false,false,false,false,false,false,false,false};
		Tile_1.croc_count = 0;
		Tile_1.Ox = false;
		Tile_1.Boar = false;
		Tile_1.Deer = false;
		Tile_1.Den = false;
		Tile_1.x = 0;
		Tile_1.y = 0;
		Tile_1.completion[4] = {false};
		return Tile_1;
	}
	else if(i == 1){
		tile Tile_2;
		Tile_2.des = {'J', 'J', 'J', 'J', 'X'};
		Tile_2.type = {2,2,2,2,2,2,2,2}; // has den
		Tile_2.clusterid = {1,1,1,1,1,1,1,1};
		Tile_2.tiger = {false,false,false,false,false,false,false,false};
		Tile_2.croc_count = 0;
		Tile_2.Ox = false;
		Tile_2.Boar = false;
		Tile_2.Deer = false;
		Tile_2.Den = true;
		Tile_2.x = 0;
		Tile_2.y = 0;
		Tile_2.completion[4] = {false};
		return Tile_2;
	}
	else if(i == 2){
		tile Tile_3;
		Tile_3.des = {'J', 'J', 'T', 'J', 'X'};
		Tile_3.type = {2,2,2,2,2,3,2,2}; // has den
		Tile_3.clusterid = {1,1,1,1,1,1,1,1};
		Tile_3.tiger = {false,false,false,false,false,false,false,false};
		Tile_3.croc_count = 0;
		Tile_3.Ox = false;
		Tile_3.Boar = false;
		Tile_3.Deer = false;
		Tile_3.Den = true;
		Tile_3.x = 0;
		Tile_3.y = 0;
		Tile_3.completion[4] = {false};
		return Tile_3;
	}
	else if(i == 3){
		tile Tile_4;
		Tile_4.des = {'T', 'T', 'T', 'T', '-'};
		Tile_4.type = {2,3,2,3,2,3,2,3};
		Tile_4.clusterid = {1,2,1,2,1,2,1,2};
		Tile_4.tiger = {false,false,false,false,false,false,false,false};	
		Tile_4.croc_count = 0;
		Tile_4.Ox = false;
		Tile_4.Boar = false;
		Tile_4.Deer = false;
		Tile_4.Den = false;
		Tile_4.x = 0;
		Tile_4.y = 0;
		Tile_4.completion[4] = {false};
		return Tile_4;
	}
	else if(i == 4){
		tile Tile_5;
		Tile_5.des = {'T', 'J', 'T', 'J', '-'};
		Tile_5.type = {2,3,2,2,2,3,2,2};
		Tile_5.clusterid = {1,2,1,1,1,2,1,1};
		Tile_5.tiger = {false,false,false,false,false,false,false,false};
		Tile_5.croc_count = 0;
		Tile_5.Ox = false;
		Tile_5.Boar = false;
		Tile_5.Deer = false;
		Tile_5.Den = false;
		Tile_5.x = 0;
		Tile_5.y = 0;
		Tile_5.completion[4] = {false};
		return Tile_5;
	}
	else if(i == 5){
		tile Tile_6;
		Tile_6.des = {'T', 'J', 'J', 'T', '-'};
		Tile_6.type = {2,3,2,2,2,2,2,3};
		Tile_6.clusterid = {1,2,1,1,1,1,1,2};
		Tile_6.tiger = {false,false,false,false,false,false,false,false};
		Tile_6.croc_count = 0;
		Tile_6.Ox = false;
		Tile_6.Boar = false;
		Tile_6.Deer = false;
		Tile_6.Den = false;
		Tile_6.x = 0;
		Tile_6.y = 0;
		Tile_6.completion[4] = {false};
		return Tile_6;
	}
	else if(i == 6){
		tile Tile_7;
		Tile_7.des = {'T', 'J', 'T', 'T', '-'};
		Tile_7.type = {2,3,2,2,2,2,3,2,3};
		Tile_7.clusterid = {1,2,1,1,1,2,1,2};
		Tile_7.tiger = {false,false,false,false,false,false,false,false};	
		Tile_7.croc_count = 0;
		Tile_7.Ox = false;
		Tile_7.Boar = false;
		Tile_7.Deer = false;
		Tile_7.Den = false;
		Tile_7.x = 0;
		Tile_7.y = 0;
		Tile_7.completion[4] = {false};
		return Tile_7;
	}
	else if(i == 7){
		tile Tile_8;
		Tile_8.des = {'L', 'L', 'L', 'L', '-'};
		Tile_8.type = {1,1,1,1,1,1,1,1};
		Tile_8.clusterid = {1,1,1,1,1,1,1};
		Tile_8.tiger = {false,false,false,false,false,false,false,false};	
		Tile_8.croc_count = 0;
		Tile_8.Ox = false;
		Tile_8.Boar = false;
		Tile_8.Deer = false;
		Tile_8.Den = false;
		Tile_8.x = 0;
		Tile_8.y = 0;
		Tile_8.completion[4] = {false};
		return Tile_8;
	}
	else if(i == 8){
		tile Tile_9;
		Tile_9.des = {'J', 'L', 'L', 'L', '-'};
		Tile_9.type = {2,2,2,1,1,1,1,1};
		Tile_9.clusterid = {1,1,1,2,2,2,2,2};
		Tile_9.tiger = {false,false,false,false,false,false,false,false};
		Tile_9.croc_count = 0;
		Tile_9.Ox = false;
		Tile_9.Boar = false;
		Tile_9.Deer = false;
		Tile_9.Den = false;
		Tile_9.x = 0;
		Tile_9.y = 0;
		Tile_9.completion[4] = {false};
		return Tile_9;
	}
	else if(i == 9){
		tile Tile_10;
		Tile_10.des = {'L', 'L', 'J', 'J', '-'};
		Tile_10.type = {2,1,1,1,2,2,2,2};
		Tile_10.clusterid = {1,2,2,2,1,1,1,1};
		Tile_10.tiger = {false,false,false,false,false,false,false,false};
		Tile_10.croc_count = 0;
		Tile_10.Ox = false;
		Tile_10.Boar = false;
		Tile_10.Deer = false;
		Tile_10.Den = false;
		Tile_10.x = 0;
		Tile_10.y = 0;
		Tile_10.completion[4] = {false};
		return Tile_10;
	}
	else if(i == 10){
		tile Tile_11;
		Tile_11.des = {'J', 'L', 'J', 'L', '-'};
		Tile_11.type = {2,2,2,1,2,2,2,1};/////
		Tile_11.clusterid = {1,1,1,2,3,3,3,2};
		Tile_11.tiger = {false,false,false,false,false,false,false,false};
		Tile_11.croc_count = 0;
		Tile_11.Ox = false;
		Tile_11.Boar = false;
		Tile_11.Deer = false;
		Tile_11.Den = false;
		Tile_11.x = 0;
		Tile_11.y = 0;
		Tile_11.completion[4] = {false};
		return Tile_11;
	}
	else if(i == 11){
		tile Tile_12;
		Tile_12.des = {'L', 'J', 'L', 'J', '-'};
		Tile_12.type = {2,1,2,2,2,1,2,2};////
		Tile_12.clusterid = {1,2,1,1,1,3,1,1};
		Tile_12.tiger = {false,false,false,false,false,false,false,false};
		Tile_12.croc_count = 0;
		Tile_12.Ox = false;
		Tile_12.Boar = false;
		Tile_12.Deer = false;
		Tile_12.Den = false;
		Tile_12.x = 0;
		Tile_12.y = 0;
		Tile_12.completion[4] = {false};
		return Tile_12;
	}
	else if(i == 12){
		tile Tile_13;
		Tile_13.des = {'L', 'J', 'J', 'J', '-'};
		Tile_13.type = {2,1,2,2,2,2,2,2};
		Tile_13.clusterid = {1,2,1,1,1,1,1,1}; 
		Tile_13.tiger = {false,false,false,false,false,false,false,false};
		Tile_13.croc_count = 0;
		Tile_13.Ox = false;
		Tile_13.Boar = false;
		Tile_13.Deer = false;
		Tile_13.Den = false;
		Tile_13.x = 0;
		Tile_13.y = 0;
		Tile_13.completion[4] = {false};
		return Tile_13;
	}
	else if(i == 13){
		tile  Tile_14;
		Tile_14.des = {'J', 'L', 'L', 'J', '-'};
		Tile_14.type = {2,2,2,1,4,1,2,2};
		Tile_14.clusterid = {1,1,1,2,0,3,1,1};
		Tile_14.tiger = {false,false,false,false,false,false,false,false};
		Tile_14.croc_count = 0;
		Tile_14.Ox = false;
		Tile_14.Boar = false;
		Tile_14.Deer = false;
		Tile_14.Den = false;
		Tile_14.x = 0;
		Tile_14.y = 0;
		Tile_14.completion[4] = {false};
		return Tile_14;
	}
	else if(i == 14){
		tile Tile_15;
		Tile_15.des = {'T', 'L', 'J', 'T', '-'};
		Tile_15.type = {2,3,2,1,2,2,2,3};
		Tile_15.clusterid = {1,2,1,3,1,1,1,2};
		Tile_15.tiger = {false,false,false,false,false,false,false,false};
		Tile_15.croc_count = 0;
		Tile_15.Ox = false;
		Tile_15.Boar = false;
		Tile_15.Deer = false;
		Tile_15.Den = false;
		Tile_15.x = 0;
		Tile_15.y = 0;
		Tile_15.completion[4] = {false};
		return Tile_15;
	}
	else if(i == 15){
		tile Tile_16;
		Tile_16.des = {'T', 'L', 'J', 'T', 'P'};
		Tile_16.type = {2,3,2,1,2,2,2,3}; // has boar
		Tile_16.clusterid = {1,2,1,3,1,1,1,2};
		Tile_16.tiger = {false,false,false,false,false,false,false,false};
		Tile_16.croc_count = 0;
		Tile_16.Ox = false;
		Tile_16.Boar = true;
		Tile_16.Deer = false;
		Tile_16.Den = false;
		Tile_16.x = 0;
		Tile_16.y = 0;
		Tile_16.completion[4] = {false};
		return Tile_16;
	}
	else if(i == 16){
		tile Tile_17;
		Tile_17.des = {'J', 'L', 'T', 'T', '-'};
		Tile_17.type = {2,2,2,1,2,3,2,3};
		Tile_17.clusterid = {1,1,1,2,1,3,4,3};
		Tile_17.tiger = {false,false,false,false,false,false,false,false};
		Tile_17.croc_count = 0;
		Tile_17.Ox = false;
		Tile_17.Boar = false;
		Tile_17.Deer = false;
		Tile_17.Den = false;
		Tile_17.x = 0;
		Tile_17.y = 0;
		Tile_17.completion[4] = {false};
		return Tile_17;
	}
	else if(i == 17){
		tile Tile_18;
		Tile_18.des = {'J', 'L', 'T', 'T', 'B'};
		Tile_18.type = {2,2,2,1,2,3,2,3}; // has ox
		Tile_18.clusterid = {1,1,1,2,1,3,4,3};
		Tile_18.tiger = {false,false,false,false,false,false,false,false};
		Tile_18.croc_count = 0;
		Tile_18.Ox = true;
		Tile_18.Boar = false;
		Tile_18.Deer = false;
		Tile_18.Den = false;
		Tile_18.x = 0;
		Tile_18.y = 0;
		Tile_18.completion[4] = {false};
		return Tile_18;
	}
	else if(i == 18){
		tile Tile_19;
		Tile_19.des = {'T', 'L', 'T', 'J', '-'};
		Tile_19.type = {2,3,2,1,2,3,2,3};
		Tile_19.clusterid = {1,2,3,4,3,2,1,1};
		Tile_19.tiger = {false,false,false,false,false,false,false,false};
		Tile_19.croc_count = 0;
		Tile_19.Ox = false;
		Tile_19.Boar = false;
		Tile_19.Deer = false;
		Tile_19.Den = false;
		Tile_19.x = 0;
		Tile_19.y = 0;
		Tile_19.completion[4] = {false};
		return Tile_19;
	}
	else if(i == 19){
		tile Tile_20;
		Tile_20.des = {'T', 'L', 'T', 'J', 'D'};
		Tile_20.type = {2,3,2,1,2,3,2,3}; // has deer	
		Tile_20.clusterid = {1,2,3,4,3,2,1,1};
		Tile_20.tiger = {false,false,false,false,false,false,false,false};
		Tile_20.croc_count = 0;
		Tile_20.Ox = false;
		Tile_20.Boar = false;
		Tile_20.Deer = true;
		Tile_20.Den = false;
		Tile_20.x = 0;
		Tile_20.y = 0;
		Tile_20.completion[4] = {false};
		return Tile_20;
	}
	else if(i == 20){
		tile Tile_21;
		Tile_21.des = {'T', 'L', 'L', 'L', '-'};
		Tile_21.type = {2,3,2,1,1,1,1,1};
		Tile_21.clusterid = {1,2,3,4,4,4,4,4};
		Tile_21.tiger = {false,false,false,false,false,false,false,false};
		Tile_21.croc_count = 0;
		Tile_21.Ox = false;
		Tile_21.Boar = false;
		Tile_21.Deer = false;
		Tile_21.Den = false;
		Tile_21.x = 0;
		Tile_21.y = 0;
		Tile_21.completion[4] = {false};
		return Tile_21;
	}
	else if(i == 21){
		tile Tile_22;
		Tile_22.des = {'T', 'L', 'T', 'T', '-'};
		Tile_22.type = {2,3,2,1,2,2,2,3};
		Tile_22.clusterid = {1,2,3,4,3,2,5,2};
		Tile_22.tiger = {false,false,false,false,false,false,false,false};
		Tile_22.croc_count = 0;
		Tile_22.Ox = false;
		Tile_22.Boar = false;
		Tile_22.Deer = false;
		Tile_22.Den = false;	
		Tile_22.x = 0;
		Tile_22.y = 0;
		Tile_22.completion[4] = {false};
		return Tile_22;
	}
	else if(i == 22){
		tile Tile_23;
		Tile_23.des = {'T', 'L', 'T', 'T', 'P'};
		Tile_23.type = {2,3,2,1,2,2,2,3}; // has boar	
		Tile_23.clusterid = {1,2,3,4,3,2,5,2};
		Tile_23.tiger = {false,false,false,false,false,false,false,false};
		Tile_23.croc_count = 0;
		Tile_23.Ox = false;
		Tile_23.Boar = true;
		Tile_23.Deer = false;
		Tile_23.Den = false;
		Tile_23.x = 0;
		Tile_23.y = 0;
		Tile_23.completion[4] = {false};
		return Tile_23;
	}	
	else if(i == 23){
		tile Tile_24;
		Tile_24.des = {'T', 'L', 'L', 'T', '-'};
		Tile_24.type = {2,3,2,1,1,1,2,3};
		Tile_24.clusterid = {1,2,3,4,4,4,3,2};
		Tile_24.tiger = {false,false,false,false,false,false,false,false};
		Tile_24.croc_count = 0;
		Tile_24.Ox = false;
		Tile_24.Boar = false;
		Tile_24.Deer = false;
		Tile_24.Den = false;
		Tile_24.x = 0;
		Tile_24.y = 0;
		Tile_24.completion[4] = {false};
		return Tile_24;
	}
	else if(i == 24){
		tile Tile_25;
		Tile_25.des = {'T', 'L', 'L', 'T', 'B'};
		Tile_25.type = {2,3,2,1,1,1,2,3}; // has ox
		Tile_25.clusterid = {1,2,3,4,4,4,3,2};
		Tile_25.tiger = {false,false,false,false,false,false,false,false};
		Tile_25.croc_count = 0;
		Tile_25.Ox = true;
		Tile_25.Boar = false;
		Tile_25.Deer = false;
		Tile_25.Den = false;
		Tile_25.x = 0;
		Tile_25.y = 0;
		Tile_25.completion[4] = {false};
		return Tile_25;
	}
	else if(i == 25){
		tile Tile_26;
		Tile_26.des = {'L', 'J', 'T', 'J', '-'};
		Tile_26.type = {2,1,2,2,2,3,2,2};
		Tile_26.clusterid = {1,2,3,3,3,4,1,1};
		Tile_26.tiger = {false,false,false,false,false,false,false,false};
		Tile_26.croc_count = 0;
		Tile_26.Ox = false;
		Tile_26.Boar = false;
		Tile_26.Deer = false;
		Tile_26.Den = false;
		Tile_26.x = 0;
		Tile_26.y = 0;
		Tile_26.completion[4] = {false};
		return Tile_26;
	}
	else if(i == 26){
		tile Tile_27;
		Tile_27.des = {'L', 'J', 'T', 'J', 'D'};
		Tile_27.type = {2,1,2,2,2,3,2,2}; // has deer
		Tile_27.clusterid = {1,2,3,3,3,4,1,1};
		Tile_27.tiger = {false,false,false,false,false,false,false,false};
		Tile_27.croc_count = 0;
		Tile_27.Ox = false;
		Tile_27.Boar = false;
		Tile_27.Deer = true;
		Tile_27.Den = false;
		Tile_27.x = 0;
		Tile_27.y = 0;
		Tile_27.completion[4] = {false};
		return Tile_27;
	}
	else if(i == 27){
		tile Tile_28;
		Tile_28.des = {'T', 'L', 'L', 'L', 'C'};
		Tile_28.type = {2,3,2,1,1,1,1,1};
		Tile_28.clusterid = {1,2,3,4,4,4,4,4};
		Tile_28.tiger = {false,false,false,false,false,false,false,false};
		Tile_28.croc_count = 1;
		Tile_28.Ox = false;
		Tile_28.Boar = false;
		Tile_28.Deer = false;
		Tile_28.Den = false;
		Tile_28.x = 0;
		Tile_28.y = 0;
		Tile_28.completion[4] = {false};
		return Tile_28;
	}
}



