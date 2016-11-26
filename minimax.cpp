#include <windows.h>
#include <iostream>
#include <string>
#include <list>
#include <vector>
using namespace std;

static const int BESTVALUE = 1000000;
static tile *TileGrid[153][153] = {{0}};
static int tigerCount = 7;
static int crocodileCount = 2;
static int curScore;
static tile *curTile;

//structure for map
typedef struct {
	vector<int> type;
	vector<int> sides;
} map;

//structure for the tile
typedef struct {
	int orientation;
	char *des[5];
	vector<int> type;
	vector<int> clusterid;
	vector<int> tiger;
	int croc_count;
	bool Ox;
	bool Boar;
	bool Deer;
	bool Den;
} tile;

void initiateTileGrid();
void updateBoard(tile *_TileGrid[153][153], int x, int y, tile tile, int orien);
int *MiniMaxDecision(tile *_TileGrid[153][153], int moveNum, tile t, tile *temp);
void generateMoves(tile *_TileGrid[153][153], list<int> &move_list);
int *MinMoveDecision(tile *_TileGrid[153][153], int x, int y, int z, int moveNum, tile *temp);
int *MaxMoveDecision(tile *_TileGrid[153][153], int x, int y, int z, int moveNum, tile *temp);
int *evaluatePosition(tile *_TileGrid[153][153], int x, int y, int z, int moveNum);
int tigerLocation(tile *_TileGrid[153][153], int x, int y, int z, int num);
void componentsCheck(int options[3], tile *_TileGrid[153][153], int x, int y);
tile getTile(char *temp2);
void updateScore(tile *_TileGrid[153][153], int x, int y, tile tile, int orientation, int m);
void updateTigerCount(int value);
void gameOver();
void updateCrocodileCount();
tile *tileStructure(int i);

//initiates the tile grid to all -1s to show the spaces are empty
void initiateTileGrid(){
	for(int i = 0; i<153; i++){
		for(int j = 0; j<153; j++){
			_TileGrid[i][j] = -1;
		}
	}
}

//update tiles on board
void updateBoard(tile *_TileGrid[153][153], int x, int y, tile *tile, int orien) {
	tile.orientation = orien;
	_TileGrid[x][y] = tile;
}

//start of minimax algorithm 
int *MiniMaxDecision(tile *_TileGrid[153][153], int moveNum, tile *t, tile *temp) {
	int bvalue = -BESTVALUE, index = 0, x, y, z;
	list<int> movelist;
	int bestmoves[4] = {0, 0, 0, 0};
	//this function generates only valid possible moves
	generateMoves(_TileGrid, movelist, t);
	//this next part evaluates the possible move and compares it with future moves
	while(!movelist.empty()) {
		x = movelist.front();
		movelist.pop_front();
		y = movelist.front();
		movelist.pop_front();
		z = movelist.front();
		movelist.pop_front();
		t.orientation = z;
		_TileGrid[x][y] = t;
		//this next move is the opponent playing with the board we created after placing a valid tile
		//int value = MinMoveDecision(_TileGrid, x, y, z, moveNum+1, temp);
		//usually this next part wouldnt be here, because we would be going into the min move decision
		//but for now we will just evaluate the current valid positions here
		int *value = evaluatePosition(_TileGrid, x, y, z, moveNum);
		if(value[0] > bvalue) {
			bvalue = value[0];
			bestmoves[index] = x;
			bestmoves[index+1] = y;
			bestmoves[index+2] = z;
			//m represents 0 for not placing anything, 1 for tiger on a feild, 2 for tiger on water, 3 for tiger on a path, and 4 for placing a croc
			int m = value[1];
			bestmoves[index+3] = m;
			index = 0;
		}
		//since we havent chosen this location yet, I want to to go back to nothing
		_TileGrid[x][y] = -1;
	}
	int m = bestmoves[3];
	if(m > 0 && m < 4)
		updateTigerCount(0);
	if(m == 4)
		updateCrocodileCount();
	updateBoard(_TileGrid, x, y, tile, orientation);
	updateScore(_TileGrid, x, y, tile, orientation, m);
	return bestmoves;
}

//generate possible valid moves, thinking of having it stacked as x, y, z, x, y, z, ... z being the orientation
void generateMoves(tile *_TileGrid[153][153], list<int> &move_list, int _curTile) {
	for(int i = 0; i < 153; i++) {
		//since the middle of the board is 0,0, the first for loop goes from the middle of the board and expands right
		//once it hits an empty spot (-1) then it checks if it will be a valid move and breaks from the loop 
		for(int j = 0; j < 153; j++){
			if(_TileGrid[i][j] == -1){
				//now decide if its a valid move if the spot is empty
				break;
			}
		}
		//the second for loop goes from the middle and expands left
		for(int j = 0; j < -153; j--){
			if(_TileGrid[i][j] == -1){
				//now decide if its a valid move if the spot is empty
				break;
			}
		}
	}
}

//This is the opponents future move
int *MinMoveDecision(tile *_TileGrid[153][153], int x, int y, int z, int moveNum, tile *temp) {
	int *pvalue = evaluatePosition(_TileGrid, x, y, z, moveNum);
	if(pvalue[0] == -1)
		return pvalue;
	int bvalue = +BESTVALUE;
	list<int> movelist;
	//current tile searches the temp list, which holds the order of the tiles, for the tile we need
	curTile = temp[moveNum-1];
	generateMoves(_TileGrid, movelist, curTile);
	while(!movelist.empty()) {
		int x = movelist.front();
		movelist.pop_front();
		int y = movelist.front();
		movelist.pop_front();
		int z = movelist.front();
		movelist.pop_front();
		curTile.orientation = z;
		_TileGrid[x][y] = curTile;
		//this would be after we placed a valid move and then the opponent placed a valid move, it would come back to us
		//int value = MaxMoveDecision(_TileGrid, x, y, z, moveNum+1, temp);
		//if we dont do use max move then we need an evaluatePosition method to get value
		if(value[0] > bvalue)
			bvalue = value;
	}
	return bvalue;
}

//this is our future move
int *MaxMoveDecision(tile *_TileGrid[153][153], int x, int y, int z, int moveNum, tile *temp) {
	int *pvalue = evaluatePosition(_TileGrid, x, y, z, moveNum);
	if(pvalue[0] == -1)
		return pvalue;
	int bvalue = -BESTVALUE;
	list<int> movelist;
	//current tile searches the temp list, which holds the order of the tiles, for the tile we need
	curTile = temp[moveNum];
	generateMoves(_TileGrid, movelist, curTile);
	while(!movelist.empty()) {
		int x = movelist.front();
		movelist.pop_front();
		int y = movelist.front();
		movelist.pop_front();
		int z = movelist.front();
		movelist.pop_front();
		curTile.orientation = z;
		_TileGrid[x][y] = curTile;
		//just like the last one but the opposite, this will keep going until the last move
		//int value = MinMoveDecision(_TileGrid, x, y, z, moveNum+1, temp);
		//if we dont do use min move then we need an evaluatePosition method to get value
		if(value[0] > bvalue)
			bvalue = value;
	}
	return bvalue;
}

//returns the value of the tile at that location also any prunning needed
//also any logic here can be changed or added, this is just a starting point for checking and such
int evaluatePosition(tile *_TileGrid[153][153], int x, int y, int z, int num) {
	int mLocation;
	//should first check to see if we are helping the other player out with this move and return -1, if we have time
	if((mLocation = tigerLocation(_TileGrid, x, y, z, num)) > 0){
		//return a value of 10 for feilds
		if(mLocation == 1)
			return 10;
		//return a value of 5 for water
		else if(mLocation == 2)
			return 5;
		//return a value of 3 for paths
		else if(mLocation == 3)
			return 3;
		//return a value of 2 for crocs
		else
			return 2;
	}
	else
		return 0;
}

//picks tiger or croc location on tile
//also any logic here can be changed or added, this is just a starting point for checking and such
int tigerLocation(tile *_TileGrid[153][153], int x, int y, int z, int moveNum){
	int options[] = {0,0,0,0};
	componentsCheck(options, TileGrid, x, y);
	//moveNum is, for example, move number 2 or 3 so to get number of tiles left we subtract it from 76
	int num = 76 - moveNum;
	//options[0] = the feild, options[1] = the water, options[2] = the path, options[3] = places a crocodile
	if(num >= 50){
		//in this if statement, given these conditions, the presedence would be field over water over path 
		if(options[0] == 1 && tigerCount != 0)
			return 1;
		if(options[1] == 1 && tigerCount != 0)
			return 2;
		if(options[2] == 1 && tigerCount != 0)
			return 3;
	}
	else if(num >= 30){
		//in this if statement, given these conditions, the presedence would be water over feild over path
		if(options[1] == 1 && tigerCount != 0)
			return 2;
		if(options[0] == 1 && tigerCount >= 3)
			return 1;
		if(options[2] == 1 && tigerCount != 0)
			return 3;
	}
	else if(num >= 10){
		//in this if statement, given these conditions, the presedence would be water over path over placing a croc
		if(options[1] == 1 && tigerCount != 0)
			return 2;
		if(options[2] == 1 && tigerCount != 0)
			return 3;
		if(options[3] == 1 && crocodileCount != 0)
			return 4;
	}
	else if (num >= 3){
		//in this if statement, given these conditions, the presedence would be water over path over placing a croc
		if(options[1] == 1 && tigerCount != 0)
			return 2;
		if(options[2] == 1 && tigerCount != 0)
			return 3;
		if(options[3] == 1 && crocodileCount != 0)
			return 4;
	}
	else 
		return 0;
}

//checks the components to see where we can legally place tigers on this tile
void componentsCheck(int options[3], tile *_TileGrid[153][153], int x, int y){
	//return the values 1 for yes, 0 for no, in the order feild, water, path, crocs into the options array
	//example: options[] = {0,1,1,0} would represent we could place a tiger on in the water and the path but not an the feild or place a croc
	//daniels part
}

//get the character representing the tile
tile getTile(char *temp2){
	char a = temp2[0];
	char b = temp2[1];
	char c = temp2[2];
	char d = temp2[3];
	char e = temp2[4];
	for(int i = 0; i < 28; i++){
		//tile structure holds all the hard coded values for each tile
		tile *temp = tileStructure(i);
		char *temp1 = temp->des;
		if(a == temp1[0] && b == temp1[1] && c == temp1[2] && d == temp1[3] && e == temp1[4])
			return temp;
	}
}

//update our score
void updateScore(tile *_TileGrid[153][153], int x, int y, tile tile, int orientation, int m, int player){
	//score only updates when a tiger is returned, so need to check for any completed components
	//daniels part
}

//this updates our tigerCount. If the value is zero then we used a tiger, if the number is something else then we are receiving our tiger(s)
void updateTigerCount(int value){
	if (value == 0)
		tigerCount--;
	else
		tigerCount = tigerCount + value;
}

//this updates the crocodile count, we can only subtract because we never get a croc back until the end of the game
void updateCrocodileCount(){
	crocodileCount--;
}

int main(){
	string startTile, tileInput, moveAndPlace;
	initiateTileGrid();
	char *temp2 = new char[5];
	int count = 0;
	//receive a message saying this is sparta
	cout<< "JOIN <tournament password>" << endl;
	//receive a message saying hello
	cout<< "I AM <username><password>" << endl;
	//receive a message saying welcome <pid> please wait for the next challenge
	//receive a message saying new challenge <cid> you will play <rounds> match(es)
	//receive a message saying begin round <rid> of <rounds>
	//receive a message saying your opponent is player <pid>
	//receive a message saying starting tile is <tile> at <x><y><orientation>
	cin>> startTile;
	//all this information is given in the last messae we received but we also know the starting tile and then we update the board
	int x = 0, y = 0, orientation = 0;
	temp2[5] = {T, L, T, J, -};
	tile *val = getTile(temp2);
	tile t = val;
	updateBoard(_TileGrid, x, y, t, orientation);
	//receive a message saying the remaining <number_tiles> tiles are [<tiles>]
	cin>> tileInput;
	//the next chunk of information is given from the last receive message
	char *temp1 = new char[tileInput.size()+1];
	tile *temp = new tile[tileInput.size()+1];
	temp1[tileInput.size()] = 0;
	memcpy(temp1,tileInput.c_str(),tileInput.size());
	//this will put the tiles, in the correct order, into an array of tiles called temp
	for(int i = 29; i < tileInput.size()-1; i=i+6){
		temp2[0] = temp1[i];
		temp2[1] = temp1[i+1];
		temp2[2] = temp1[i+2];
		temp2[3] = temp1[i+3];
		temp2[4] = temp1[i+4];
		val = getTile(temp2);
		temp[count] = val;
		count++;
	}
	//receive a message saying match begins in <time> seconds
	//receive a message saying make your move in game <gid> within <time> second: move <#> place <tile>
	cin>> moveAndPlace;
	char *move = new char[moveAndPlace.size()+1];
	memcpy(move,moveAndPlace.c_str(),moveAndPlace.size());
	int tileNum = 76, moveNum = (int)((move[moveAndPlace.size()-13]));
	int *tileResult;
	//decide if we are the first player because that would affect the moveNum and the tile
	if((77 - moveNum) == tileNum){
		t = temp[moveNum-1];
		tileResult = MiniMaxDecision(_TileGrid, moveNum, t, temp);
		//return values to the server and wait for a reply
	}
	while(moveNum > 0){
		//receive values from other player and message saying its our turn
		//with the new values we would update x, y, t, and orientation before calling the updateBoard funtion
		updateBoard(_TileGrid, x, y, t, orientation);
		tileResult = MiniMaxDecision(_TileGrid, moveNum, t, temp);
		//return values to the server and wait for a reply
	}
	//now that the moves have run out the game is over
    return 0;
}

//tile info
tile *tileStructure(int i){
	if(i == 0){
		Tile * Tile_1 = new Tile;
		Tile_1->des.insert(des.end(), {J, J, J, J, -});
		Tile_1->type.insert(type.end(), {2,2,2,2,2,2,2,2});
		Tile_1->clusterid.insert(clusterid.end(),{1,1,1,1,1,1,1,1});
		Tile_1->tiger.insert(tiger.end(),{false,false,false,false,false,false,false,false});
		Tile_1->croc_count = 0;
		Tile_1->Ox = false;
		Tile_1->Boar = false;
		Tile_1->Deer = false;
		Tile_1->Den = false;
		return Tile_1;
	}
	else if(i == 1){
		Tile * Tile_2 = new Tile;
		Tile_2->des.insert(des.end(), {J, J, J, J, X});
		Tile_2->type.insert(type.end(), {2,2,2,2,2,2,2,2}); // has den
		Tile_2->clusterid.insert(clusterid.end(), {1,1,1,1,1,1,1,1});
		Tile_2->tiger.insert(tiger.end(), {false,false,false,false,false,false,false,false});
		Tile_2->croc_count = 0;
		Tile_2->Ox = false;
		Tile_2->Boar = false;
		Tile_2->Deer = false;
		Tile_2->Den = true;
		return Tile_2;
	}
	else if(i == 2){
		Tile * Tile_3 = new Tile;
		Tile_3->des.insert(des.end(), {J, J, T, J, X});
		Tile_3->type.insert(type.end(),  {2,2,2,2,2,3,2,2}); // has den
		Tile_3->clusterid.insert(clusterid.end(),{1,1,1,1,1,1,1,1});
		Tile_3->tiger.insert(tiger.end(), {false,false,false,false,false,false,false,false});
		Tile_3->croc_count = 0;
		Tile_3->Ox = false;
		Tile_3->Boar = false;
		Tile_3->Deer = false;
		Tile_3->Den = true;
		return Tile_3;
	}
	else if(i == 3){
		Tile * Tile_4 = new Tile;
		Tile_4->des.insert(des.end(), {T, T, T, T, -});
		Tile_4->type.insert(type.end(),  {2,3,2,3,2,3,2,3});
		Tile_4->clusterid.insert(clusterid.end(),{1,2,1,2,1,2,1,2});
		Tile_4->tiger.insert(tiger.end(), {false,false,false,false,false,false,false,false});	
		Tile_4->croc_count = 0;
		Tile_4->Ox = false;
		Tile_4->Boar = false;
		Tile_4->Deer = false;
		Tile_4->Den = false;
		return Tile_4;
	}
	else if(i == 4){
		Tile * Tile_5 = new Tile;
		Tile_5->des.insert(des.end(), {T, J, T, J, -});
		Tile_5->type.insert(type.end(), {2,3,2,2,2,3,2,2});
		Tile_5->clusterid.insert(clusterid.end(),{1,2,1,1,1,2,1,1});
		Tile_5->tiger.insert(tiger.end(), {false,false,false,false,false,false,false,false});
		Tile_5->croc_count = 0;
		Tile_5->Ox = false;
		Tile_5->Boar = false;
		Tile_5->Deer = false;
		Tile_5->Den = false;
		return Tile_5;
	}
	else if(i == 5){
		Tile * Tile_6 = new Tile;
		Tile_6->des.insert(des.end(), {T, J, J, T, -});
		Tile_6->type.insert(type.end( {2,3,2,2,2,2,2,3});
		Tile_6->clusterid.insert(clusterid.end(),{1,2,1,1,1,1,1,2});
		Tile_6->tiger.insert(tiger.end(), {false,false,false,false,false,false,false,false});
		Tile_6->croc_count = 0;
		Tile_6->Ox = false;
		Tile_6->Boar = false;
		Tile_6->Deer = false;
		Tile_6->Den = false;
		return Tile_6;
	}
	else if(i == 6){
		Tile * Tile_7 = new Tile;
		Tile_7->des.insert(des.end(), {T, J, T, T, -});
		Tile_7->type.insert(type.end(),  {2,3,2,2,2,2,3,2,3});
		Tile_7->clusterid.insert(clusterid.end(),{1,2,1,1,1,2,1,2});
		Tile_7->tiger.insert(tiger.end(), {false,false,false,false,false,false,false,false});	
		Tile_7->croc_count = 0;
		Tile_7->Ox = false;
		Tile_7->Boar = false;
		Tile_7->Deer = false;
		Tile_7->Den = false;
		return Tile_7;
	}
	else if(i == 7){
		Tile * Tile_8 = new Tile;
		Tile_8->des.insert(des.end(), {L, L, L, L, -});
		Tile_8->type.insert(type.end(), {1,1,1,1,1,1,1,1});
		Tile_8->clusterid.insert(clusterid.end(),{1,1,1,1,1,1,1});
		Tile_8->tiger.insert(tiger.end(), {false,false,false,false,false,false,false,false});	
		Tile_8->croc_count = 0;
		Tile_8->Ox = false;
		Tile_8->Boar = false;
		Tile_8->Deer = false;
		Tile_8->Den = false;
		return Tile_8;
	}
	else if(i == 8){
		Tile * Tile_9 = new Tile;
		Tile_9->des.insert(des.end(), {J, L, L, L, -});
		Tile_9->type.insert(type.end(), {2,2,2,1,1,1,1,1});
		Tile_9->clusterid.insert(clusterid.end(),{1,1,1,2,2,2,2,2});
		Tile_9->tiger.insert(tiger.end(), {false,false,false,false,false,false,false,false});
		Tile_9->croc_count = 0;
		Tile_9->Ox = false;
		Tile_9->Boar = false;
		Tile_9->Deer = false;
		Tile_9->Den = false;
		return Tile_9;
	}
	else if(i == 9){
		Tile * Tile_10 = new Tile;
		Tile_10->des.insert(des.end(), {L, L, J, J, -});
		Tile_10->type.insert(type.end(),   {2,1,1,1,2,2,2,2});
		Tile_10->clusterid.insert(clusterid.end(),{1,2,2,2,1,1,1,1});
		Tile_10->tiger.insert(tiger.end(), {false,false,false,false,false,false,false,false});
		Tile_10->croc_count = 0;
		Tile_10->Ox = false;
		Tile_10->Boar = false;
		Tile_10->Deer = false;
		Tile_10->Den = false;
		return Tile_10;
	}
	else if(i == 10){
		Tile * Tile_11 = new Tile;
		Tile_11->des.insert(des.end(), {J, L, J, L, -});
		Tile_11->type.insert(type.end(),  {2,2,2,1,2,2,2,1});/////
		Tile_11->clusterid.insert(clusterid.end(),{1,1,1,2,3,3,3,2});
		Tile_11->tiger.insert(tiger.end(), {false,false,false,false,false,false,false,false});
		Tile_11->croc_count = 0;
		Tile_11->Ox = false;
		Tile_11->Boar = false;
		Tile_11->Deer = false;
		Tile_11->Den = false;
		return Tile_11;
	}
	else if(i == 11){
		Tile * Tile_12 = new Tile;
		Tile_12->des.insert(des.end(), {L, J, L, J, -});
		Tile_12->type.insert(type.end(), {2,1,2,2,2,1,2,2});////
		Tile_12->clusterid.insert(clusterid.end(),{1,2,1,1,1,3,1,1});
		Tile_12->tiger.insert(tiger.end(), {false,false,false,false,false,false,false,false});
		Tile_12->croc_count = 0;
		Tile_12->Ox = false;
		Tile_12->Boar = false;
		Tile_12->Deer = false;
		Tile_12->Den = false;
		return Tile_12;
	}
	else if(i == 12){
		Tile * Tile_13 = new Tile;
		Tile_13->des.insert(des.end(), {L, J, J, J, -});
		Tile_13->type.insert(type.end(),  {2,1,2,2,2,2,2,2});
		Tile_13->clusterid.insert(clusterid.end(),{1,2,1,1,1,1,1,1}); 
		Tile_13->tiger.insert(tiger.end(), {false,false,false,false,false,false,false,false});
		Tile_13->croc_count = 0;
		Tile_13->Ox = false;
		Tile_13->Boar = false;
		Tile_13->Deer = false;
		Tile_13->Den = false;
		return Tile_13;
	}
	else if(i == 13){
		Tile *  Tile_14 = new Tile;
		Tile_14->des.insert(des.end(), {J, L, L, J, -});
		Tile_14->type.insert(type.end(), {2,2,2,1,4,1,2,2});
		Tile_14->clusterid.insert(clusterid.end(),{1,1,1,2,0,3,1,1});
		Tile_14->tiger.insert(tiger.end(), {false,false,false,false,false,false,false,false});
		Tile_14->croc_count = 0;
		Tile_14->Ox = false;
		Tile_14->Boar = false;
		Tile_14->Deer = false;
		Tile_14->Den = false;
		return Tile_14;
	}
	else if(i == 14){
		Tile * Tile_15 = new Tile;
		Tile_15->des.insert(des.end(), {T, L, J, T, -});
		Tile_15->type.insert(type.end(), {2,3,2,1,2,2,2,3});
		Tile_15->clusterid.insert(clusterid.end(),{1,2,1,3,1,1,1,2});
		Tile_15->tiger.insert(tiger.end(), {false,false,false,false,false,false,false,false});
		Tile_15->croc_count = 0;
		Tile_15->Ox = false;
		Tile_15->Boar = false;
		Tile_15->Deer = false;
		Tile_15->Den = false;
		return Tile_15;
	}
	else if(i == 15){
		Tile * Tile_16 = new Tile;
		Tile_16->des.insert(des.end(), {T, L, J, T, P});
		Tile_16->type.insert(type.end(), {2,3,2,1,2,2,2,3}); // has boar
		Tile_16->clusterid.insert(clusterid.end(),{1,2,1,3,1,1,1,2});
		Tile_16->tiger.insert(tiger.end(), {false,false,false,false,false,false,false,false});
		Tile_16->croc_count = 0;
		Tile_16->Ox = false;
		Tile_16->Boar = true;
		Tile_16->Deer = false;
		Tile_16->Den = false;
		return Tile_16;
	}
	else if(i == 16){
		Tile * Tile_17 = new Tile;
		Tile_17->des.insert(des.end(), {J, L, T, T, -});
		Tile_17->type.insert(type.end(), {2,2,2,1,2,3,2,3});
		Tile_17->clusterid.insert(clusterid.end(),{1,1,1,2,1,3,4,3});
		Tile_17->tiger.insert(tiger.end(), {false,false,false,false,false,false,false,false});
		Tile_17->croc_count = 0;
		Tile_17->Ox = false;
		Tile_17->Boar = false;
		Tile_17->Deer = false;
		Tile_17->Den = false;
		return Tile_17;
	}
	else if(i == 17){
		Tile * Tile_18 = new Tile;
		Tile_18->des.insert(des.end(), {J, L, T, T, B});
		Tile_18->type.insert(type.end(), {2,2,2,1,2,3,2,3}); // has ox
		Tile_18->clusterid.insert(clusterid.end(),{1,1,1,2,1,3,4,3});
		Tile_18->tiger.insert(tiger.end(), {false,false,false,false,false,false,false,false});
		Tile_18->croc_count = 0;
		Tile_18->Ox = true;
		Tile_18->Boar = false;
		Tile_18->Deer = false;
		Tile_18->Den = false;
		return Tile_18;
	}
	else if(i == 18){
		Tile * Tile_19 = new Tile;
		Tile_19->des.insert(des.end(), {T, L, T, J, -});
		Tile_19->type.insert(type.end(), {2,3,2,1,2,3,2,3});
		Tile_19->clusterid.insert(clusterid.end(),{1,2,3,4,3,2,1,1});
		Tile_19->tiger.insert(tiger.end(), {false,false,false,false,false,false,false,false});
		Tile_19->croc_count = 0;
		Tile_19->Ox = false;
		Tile_19->Boar = false;
		Tile_19->Deer = false;
		Tile_19->Den = false;
		return Tile_19;
	}
	else if(i == 19){
		Tile * Tile_20 = new Tile;
		Tile_20->des.insert(des.end(), {T, L, T, J, D});
		Tile_20->type.insert(type.end(), {2,3,2,1,2,3,2,3}); // has deer	
		Tile_20->clusterid.insert(clusterid.end(),{1,2,3,4,3,2,1,1});
		Tile_20->tiger.insert(tiger.end(), {false,false,false,false,false,false,false,false});
		Tile_20->croc_count = 0;
		Tile_20->Ox = false;
		Tile_20->Boar = false;
		Tile_20->Deer = true;
		Tile_20->Den = false;
		return Tile_20;
	}
	else if(i == 20){
		Tile * Tile_21 = new Tile;
		Tile_21->des.insert(des.end(), {T, L, L, L, -});
		Tile_21->type.insert(type.end(), {2,3,2,1,1,1,1,1});
		Tile_21->clusterid.insert(clusterid.end(),{1,2,3,4,4,4,4,4});
		Tile_21->tiger.insert(tiger.end(), {false,false,false,false,false,false,false,false});
		Tile_21->croc_count = 0;
		Tile_21->Ox = false;
		Tile_21->Boar = false;
		Tile_21->Deer = false;
		Tile_21->Den = false;
		return Tile_21;
	}
	else if(i == 21){
		Tile * Tile_22 = new Tile;
		Tile_22->des.insert(des.end(), {T, L, T, T, -});
		Tile_22->type.insert(type.end(), {2,3,2,1,2,2,2,3});
		Tile_22->clusterid.insert(clusterid.end(),{1,2,3,4,3,2,5,2});
		Tile_22->tiger.insert(tiger.end(), {false,false,false,false,false,false,false,false});
		Tile_22->croc_count = 0;
		Tile_22->Ox = false;
		Tile_22->Boar = false;
		Tile_22->Deer = false;
		Tile_22->Den = false;	
		return Tile_22;
	}
	else if(i == 22){
		Tile * Tile_23 = new Tile;
		Tile_23->des.insert(des.end(), {T, L, T, T, P});
		Tile_23->type.insert(type.end(), {2,3,2,1,2,2,2,3}); // has boar	
		Tile_23->clusterid.insert(clusterid.end(),{1,2,3,4,3,2,5,2});
		Tile_23->tiger.insert(tiger.end(), {false,false,false,false,false,false,false,false});
		Tile_23->croc_count = 0;
		Tile_23->Ox = false;
		Tile_23->Boar = true;
		Tile_23->Deer = false;
		Tile_23->Den = false;
		return Tile_23;
	}	
	else if(i == 23){
		Tile * Tile_24 = new Tile;
		Tile_24->des.insert(des.end(), {T, L, L, T, -});
		Tile_24->type.insert(type.end(), {2,3,2,1,1,1,2,3});
		Tile_24->clusterid.insert(clusterid.end(),{1,2,3,4,4,4,3,2});
		Tile_24->tiger.insert(tiger.end(), {false,false,false,false,false,false,false,false});
		Tile_24->croc_count = 0;
		Tile_24->Ox = false;
		Tile_24->Boar = false;
		Tile_24->Deer = false;
		Tile_24->Den = false;
		return Tile_24;
	}
	else if(i == 24){
		Tile * Tile_25 = new Tile;
		Tile_25->des.insert(des.end(), {T, L, L, T, B});
		Tile_25->type.insert(type.end(), {2,3,2,1,1,1,2,3}); // has ox
		Tile_25->clusterid.insert(clusterid.end(),{1,2,3,4,4,4,3,2});
		Tile_25->tiger.insert(tiger.end(), {false,false,false,false,false,false,false,false});
		Tile_25->croc_count = 0;
		Tile_25->Ox = true;
		Tile_25->Boar = false;
		Tile_25->Deer = false;
		Tile_25->Den = false;
		return Tile_25;
	}
	else if(i == 25){
		Tile * Tile_26 = new Tile;
		Tile_26->des.insert(des.end(), {L, J, T, J, -});
		Tile_26->type.insert(type.end(), {2,1,2,2,2,3,2,2});
		Tile_26->clusterid.insert(clusterid.end(),{1,2,3,3,3,4,1,1});
		Tile_26->tiger.insert(tiger.end(), {false,false,false,false,false,false,false,false});
		Tile_26->croc_count = 0;
		Tile_26->Ox = false;
		Tile_26->Boar = false;
		Tile_26->Deer = false;
		Tile_26->Den = false;
		return Tile_26;
	}
	else if(i == 26){
		Tile * Tile_27 = new Tile;
		Tile_27->des.insert(des.end(), {L, J, T, J, D});
		Tile_27->type.insert(type.end(), {2,1,2,2,2,3,2,2}); // has deer
		Tile_27->clusterid.insert(clusterid.end(),{1,2,3,3,3,4,1,1});
		Tile_27->tiger.insert(tiger.end(), {false,false,false,false,false,false,false,false});
		Tile_27->croc_count = 0;
		Tile_27->Ox = false;
		Tile_27->Boar = false;
		Tile_27->Deer = true;
		Tile_27->Den = false;
		return Tile_27;
	}
	else if(i == 27){
		Tile * Tile_28 = new Tile;
		Tile_28->des.insert(des.end(), {T, L, L, L, C});
		Tile_28->type.insert(type.end(),{2,3,2,1,1,1,1,1});
		Tile_28->clusterid.insert(clusterid.end(),{1,2,3,4,4,4,4,4});
		Tile_28->tiger.insert(tiger.end(), {false,false,false,false,false,false,false,false});
		Tile_28->croc_count = 1;
		Tile_28->Ox = false;
		Tile_28->Boar = false;
		Tile_28->Deer = false;
		Tile_28->Den = false;
		return Tile_28;
	}
}
