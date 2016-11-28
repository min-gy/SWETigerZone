#include <iostream>
#include <vector>
#include <string>
#include <list>

//#include "GameEngine.cpp"
#include "TileClass.cpp"

//#include "GameEngine.cpp"
typedef struct {
	bool top = false, bottom = false, left = false, right = false;
	int x, y;
} emptySpace;

typedef struct {
	int ClusterId;
	int ParentId;
	int IncompleteSides;
	int TileCount; //Includes tilecount + Shield value
	//int TileRegion; //Castle = 1, Field = 2, Path = 3
	int MeepleCountMe;
	int MeepleCountYou;
	int type;
	bool Boar;
	bool Deer;
	bool Ox;
	int CrocCount;
} ComponentTracker;

using namespace std;

class Player{

public:
	//GameEngine * myGameEngine;
	int MeepleCountMe;
 	int MeepleCountYou;
	int ScoreMe;
	int ScoreYou;
	int TilesRemaining;
	int * myMovePtr;
	int myMove[5];
	string tileStack;
	
	vector<Tile> randomTileStack;
	static const int BESTVALUE = 1000000;
	 Tile _TileGrid[153][153];
	 bool _TilePresent[153][153];
	 int tigerCount;
	 int crocodileCount;
	 int curScore;
	 Tile curTile;
	 vector<emptySpace> emptyTiles;
         ComponentTracker MainList[100];
	
	//myMovePtr = myMove;

	//int tempNextState;

	Player();
	~Player();

	void startNewGame();
	//void runGame();
	void addFirstTile_p(string, int, int , int);
	int* giveMyMove_p(int, string);
	void placeMove_p(string, int*, int);
	void getTileStack(vector<string>);
	void cleanUpGame();

        void updateBoard(Tile[153][153], int, int, Tile*, int);
        Tile* getTile(char const*);
        int* MiniMaxDecision(Tile[153][153], int,  Tile, vector<Tile>);
        void generateMoves(Tile[153][153], list<int>, Tile);
        int *MinMoveDecision(Tile[153][153], int, int, int, int, vector<Tile>, Tile);
        int *MaxMoveDecision(Tile[153][153], int, int, int, int, vector<Tile>, Tile);
        int *evaluatePosition(Tile[153][153], int, int, int, int, Tile);
        int tigerLocation(Tile[153][153], int, int, int, int, Tile);
        void tigerCheck(int[], Tile[153][153], int, int, Tile );
        void updateTigerCount(int);

        //void initiateTileGrid();
        void InheritValue(ComponentTracker, ComponentTracker);
        int ScoreUpdate(ComponentTracker);
        void SingleUpdate(Tile[153][153], Tile, Tile, int, int, int, int *);
        void DenUpdate(Tile[153][153], int , int , int * );
        void DenCheck(Tile[153][153], int , int, int , int, int *);
        int DenScoreUpdate(ComponentTracker );
        int MeepleUpdateMe(ComponentTracker );
        int MeepleUpdateYou(ComponentTracker );
        void updateComponents(Tile[153][153], int, int);
        //void gameOver();
        

};

Player::Player(){
       tigerCount = 7;
       crocodileCount =2; 
}

Player::~Player(){

}

void Player::addFirstTile_p(string tile, int x, int y, int orientation){
	//myGameEngine->addFirstTile_g(tile, x, y, orientation);
	cout << "addFirstTile_p function sucessfully called";
        
}

int Player::ScoreUpdate(ComponentTracker Region){
	//score calc
	int score;
	int game;
	game = 0;
	score = Region.TileCount;
	if ( Region.Boar > 0){
		if (Region.type == 1)
			game += 1;
		else
			game += Region.Boar;
	}
	if ( Region.Deer > 0)
	{
		if (Region.type == 1)
		{
			game += 1;
		}
		else
		{
			game += Region.Deer;
		}
	}
	if ( Region.Ox > 0)
	{
		if (Region.type == 1)
		{
			game += 1;
		}
		else
		{
			game += Region.Ox;
		}
	}
	game -= Region.CrocCount;
	if ( game > 0 )
	{
		score += game;
	}
	if ( Region.IncompleteSides == 0 )
	{
		score = score * 2;
	}
	return score;
}

int Player::DenScoreUpdate(ComponentTracker Region){
	int score;
	score = 8 - Region.IncompleteSides;
	return score;
}

int Player::MeepleUpdateMe(ComponentTracker Region){
	/*player.MeepleCountMe += Region.MeepleCountMe;
	player.MeepleCountYou += Region.MeepleCountYou;
	Region.MeepleCountMe = 0;
	Region.MeepleCountYou = 0;*/
	return Region.MeepleCountMe;
}

int Player::MeepleUpdateYou(ComponentTracker Region){
	/*player.MeepleCountMe += Region.MeepleCountMe;
	player.MeepleCountYou += Region.MeepleCountYou;
	Region.MeepleCountMe = 0;
	Region.MeepleCountYou = 0;*/
	return Region.MeepleCountYou;
}

void Player::DenCheck(Tile _TileGrid[153][153], int X, int Y, int NewX, int NewY, int * values){
	if(_TileGrid[NewX][NewY].orientation != NULL)
	{
		if(_TileGrid[X][Y].Den == true)
		{
			MainList[_TileGrid[X][Y].CenterClusterid].IncompleteSides -= 1;
			if (MainList[_TileGrid[X][Y].CenterClusterid].IncompleteSides == 0)
			{
				if (MainList[_TileGrid[X][Y].CenterClusterid].MeepleCountMe == 1)
				{
					values[3] += DenScoreUpdate(MainList[_TileGrid[X][Y].CenterClusterid]);
				}
				if (MainList[_TileGrid[X][Y].CenterClusterid].MeepleCountYou == 1)
				{
					values[4] += DenScoreUpdate(MainList[_TileGrid[X][Y].CenterClusterid]);
				}
				values[1] += MeepleUpdateMe(MainList[_TileGrid[X][Y].CenterClusterid]);
				values[2] += MeepleUpdateYou(MainList[_TileGrid[X][Y].CenterClusterid]);
			}
		}
		if(_TileGrid[NewX][NewY].Den == true)
		{
			MainList[_TileGrid[NewX][NewY].CenterClusterid].IncompleteSides -= 1;
			if (MainList[_TileGrid[NewX][NewY].CenterClusterid].IncompleteSides == 0)
			{
				if (MainList[_TileGrid[NewX][NewY].CenterClusterid].MeepleCountMe == 1)
				{
					values[3] += DenScoreUpdate(MainList[_TileGrid[NewX][NewY].CenterClusterid]);
				}
				if (MainList[_TileGrid[NewX][NewY].CenterClusterid].MeepleCountYou == 1)
				{
					values[4] += DenScoreUpdate(MainList[_TileGrid[NewX][NewY].CenterClusterid]);
				}
				values[1] += MeepleUpdateMe(MainList[_TileGrid[NewX][NewY].CenterClusterid]);
				values[2] += MeepleUpdateYou(MainList[_TileGrid[NewX][NewY].CenterClusterid]);
			}
		}
	}
}

void Player::DenUpdate(Tile _TileGrid[153][153], int X, int Y, int * values){
	if (_TileGrid[X][Y].Den == true){
		DenCheck(_TileGrid, X, Y, X+1, Y, values);
		DenCheck(_TileGrid, X, Y, X+1, Y+1, values);
		DenCheck(_TileGrid, X, Y, X+1, Y-1, values);
		DenCheck(_TileGrid, X, Y, X-1, Y, values);
		DenCheck(_TileGrid, X, Y, X-1, Y+1, values);
		DenCheck(_TileGrid, X, Y, X-1, Y-1, values);
		DenCheck(_TileGrid, X, Y, X, Y+1, values);
		DenCheck(_TileGrid, X, Y, X, Y-1, values);
	}
}

void Player::SingleUpdate(Tile _TileGrid[153][153], Tile CurrentTile, Tile OldTile, int newS, int oldS, int Side, int * values){
	int x;
	int y;
	bool DontAdd;
	DontAdd = false;
	//Catch for nonexistent tile
	if (OldTile.orientation != NULL && CurrentTile.type.at(newS) != 4){
		if (CurrentTile.type.at(newS) == OldTile.type.at(oldS)){
			//Special Check for corner Jungle . Jungle
			if ((newS % 2 == 0) && (CurrentTile.type.at(newS) == 2)){
				switch(Side){
      			  	case 1: 
      			  		if (OldTile.type.at(5) == 1)
      			  			DontAdd = true;
      			  	break;
 					case 2:
 						if (OldTile.type.at(7) == 1)
      			  			DontAdd = true;
 					break;
        			case 3:
        				if (OldTile.type.at(1) == 1)
      			  			DontAdd = true;
        			break;
        			case 4:
        				if (OldTile.type.at(3) == 1)
      			  			DontAdd = true;
        			break;
        		}
			}
			x = CurrentTile.clusterid.at(newS);
			y = OldTile.clusterid.at(oldS);
			while (x != MainList[x].ParentId)
			{
			 	x = MainList[x].ParentId;		
			 	if (x == y)
			 	{// REQUIRE CATCH FOR scenario in which y already absorbed into x.parent
			 		DontAdd = true;
			 	}	 	
			}	
			if (DontAdd == false)
			{
				while (y != MainList[y].ParentId)
			 		y = MainList[y].ParentId;			 	
				//InheritValue(ComponentTracker Child, ComponentTracker Parent)
				InheritValue(MainList[x], MainList[y]);
			}
			if ((newS % 2 == 1) && (CurrentTile.type.at(newS) != 2)) 
			{
				MainList[y].IncompleteSides -= 2;
				if ( MainList[y].IncompleteSides == 0 )
				{
					if (MainList[y].MeepleCountMe >= MainList[y].MeepleCountYou)
					{
						values[3] += ScoreUpdate(MainList[y]);	
					}
					if (MainList[y].MeepleCountMe <= MainList[y].MeepleCountYou)
					{
						values[4] += ScoreUpdate(MainList[y]);
					}
					values[1] += MeepleUpdateMe(MainList[y]);
					values[2] += MeepleUpdateMe(MainList[y]);
				}
			}
		}
	}
}

//update the components
void Player::updateComponents(Tile _TileGrid[153][153], int X, int Y){
	int * values;
	values[1] = 0;
	values[2] = 0;
	values[3] = 0;
	values[4] = 0;
	Tile CurrentTile;
	Tile LeftTile;
	Tile RightTile;
	Tile UpTile;
	Tile DownTile;

	CurrentTile = _TileGrid[X][Y];
/*
	LeftTile = _TileGrid[X-1][Y];
	RightTile = _TileGrid[X+1][Y];
	UpTile = _TileGrid[X][Y+1];
	DownTile = _TileGrid[X][Y-1];
	*/
	LeftTile = _TileGrid[X][Y-1];
	RightTile = _TileGrid[X][Y+1];
	UpTile = _TileGrid[X+1][Y];
	DownTile = _TileGrid[X-1][Y];
	//SingleUpdate(Map _TileGrid, Tile CurrentTile, Tile OldTile, int newS, int oldS);
	SingleUpdate(_TileGrid, CurrentTile, UpTile, 0, 6, 1, values);
	SingleUpdate(_TileGrid, CurrentTile, UpTile, 1, 5, 1, values);
	SingleUpdate(_TileGrid, CurrentTile, UpTile, 2, 4, 1, values);

	SingleUpdate(_TileGrid, CurrentTile, RightTile, 2, 0, 2, values);
	SingleUpdate(_TileGrid, CurrentTile, RightTile, 3, 7, 2, values);
	SingleUpdate(_TileGrid, CurrentTile, RightTile, 4, 6, 2, values);

	SingleUpdate(_TileGrid, CurrentTile, DownTile, 4, 2, 3, values);
	SingleUpdate(_TileGrid, CurrentTile, DownTile, 5, 1, 3, values);
	SingleUpdate(_TileGrid, CurrentTile, DownTile, 6, 0, 3, values);

	SingleUpdate(_TileGrid, CurrentTile, LeftTile, 6, 4, 4, values);
	SingleUpdate(_TileGrid, CurrentTile, LeftTile, 7, 3, 4, values);
	SingleUpdate(_TileGrid, CurrentTile, LeftTile, 0, 2, 4, values);

	DenUpdate(_TileGrid, X, Y, values);
	//return values;
}

/*
void Player::cleanUpGame(){
	delete myGameEngine;
}
*/
void Player::InheritValue(ComponentTracker Child, ComponentTracker Parent) 
{
	Parent.Ox += Child.Ox;
	Parent.Deer += Child.Deer;
	Parent.Boar += Child.Boar;
	Parent.CrocCount = Parent.CrocCount + Child.CrocCount;
	Parent.MeepleCountYou += Child.MeepleCountYou;
	Parent.MeepleCountMe += Child.MeepleCountMe;
	Parent.IncompleteSides += Child.IncompleteSides;
	Parent.TileCount += Child.TileCount;
	Child.ParentId = Parent.ParentId;
	//Delete Child from 'To-Check' List ```````````````WITHIN MAPCLASS``````````````````
	//Only Check parents for scoring and updates
}

int* Player::giveMyMove_p(int moveNum, string tile){

        Tile * ptr = getTile(tile.c_str())
        Tile myTile = &ptr
	tileResult = MiniMaxDecision(_TileGrid, moveNum, myTile, randomTileStack);
	//return tileResult;


	//return myMovePtr;

	int* resultPtr = &tileResult[0];
	return resultPtr;
}

void Player::placeMove_p(string tile, int * move, int usOrThem){

    Tile * temp = getTile(tile.c_str()); 
    updateBoard(_TileGrid, *(move), *(move+1), temp, *(move+2));

}

void Player::getTileStack(vector<string> tileString){
	for(int i = 0; i < tileString.size(); i++)
	{
		//take that specific string named temp
		// temp2[0] = temp1[i];
		// temp2[1] = temp1[i+1];
		// temp2[2] = temp1[i+2];
		// temp2[3] = temp1[i+3];
		// temp2[4] = temp1[i+4];
		Tile * tempTile = getTile(tileString[i].c_str());
                Tile myTile = &tempTile;
		randomTileStack.push_back(myTile);
        }
	//parse tileString to tileStack
}

void Player::updateBoard(Tile _TileGrid[153][153], int x, int y, Tile * t, int orien) {
	emptySpace temp;
	t->orientation = orien;
	_TileGrid[x][y] = *t;
	_TilePresent[x][y] = true;
	//if a newly placed value is in our emptyTiles we need to erase it
	if(!emptyTiles.empty()){
		int s = emptyTiles.size();
		for(int i = 0; i<s; i++){
			if(emptyTiles[i].x == x && emptyTiles[i].y == y){
				emptyTiles.erase(emptyTiles.begin() + i);
				break;
			}
		}
	}
	if(_TilePresent[x+1][y] == false){
		temp.x = x+1;
		temp.y = y;
		if(_TilePresent[x+2][y] == true)
			temp.top = true;
		if(_TilePresent[x+1][y+1] == true)
			temp.right = true;
		if(_TilePresent[x+1][y-1] == true)
			temp.left = true;
		emptyTiles.push_back(temp);
	}
	if(_TilePresent[x-1][y] == false){
		temp.x = x-1;
		temp.y = y;
		if(_TilePresent[x-2][y] == true)
			temp.bottom = true;
		if(_TilePresent[x-1][y+1] == true)
			temp.right = true;
		if(_TilePresent[x-1][y-1] == true)
			temp.left = true;
		emptyTiles.push_back(temp);
	}
	if(_TilePresent[x][y+1] == false){
		temp.x = x;
		temp.y = y+1;
		if(_TilePresent[x+1][y+1] == true)
			temp.top = true;
		if(_TilePresent[x-1][y+1] == true)
			temp.bottom = true;
		if(_TilePresent[x][y+2] == true)
			temp.right = true;
		emptyTiles.push_back(temp);
	}
	if(_TilePresent[x][y-1] == false){
		temp.x = x;
		temp.y = y-1;
		if(_TilePresent[x+1][y-1] == true)
			temp.top = true;
		if(_TilePresent[x-1][y-1] == true)
			temp.bottom = true;
		if(_TilePresent[x+1][y-2] == true)
			temp.left = true;
		emptyTiles.push_back(temp);
	}
}

//start of minimax algorithm 
int *Player::MiniMaxDecision(Tile _TileGrid[153][153], int moveNum, Tile t, vector<Tile> temp) {
	int bvalue = -BESTVALUE, index = 0, x, y, z;
	list<int> movelist;
	int bestmoves[4];
	//this function generates only valid possible moves
	generateMoves(_TileGrid, movelist, t);
	//if generatemoves comes up with nothing then the tile doesnt work with the current board so need to handle the exceptions
	if(movelist.size() == 0){
		//we are going to do nothing
		bestmoves[index] = 0;
		bestmoves[index+1] = 0;
		bestmoves[index+2] = 0;
		bestmoves[index+3] = 0;
		return bestmoves;
		//but we do need to know how to repond to both of these things if our opponent does this to us
	}
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
		//int value = MinMoveDecision(_TileGrid, x, y, z, moveNum+1, temp, t);
		//usually this next part wouldnt be here, because we would be going into the min move decision...
		//but for now we will just evaluate the current valid positions here
		int *value = evaluatePosition(_TileGrid, x, y, z, moveNum, t);
		if(value[0] > bvalue) {
			bvalue = value[0];
			bestmoves[index] = x;
			bestmoves[index+1] = y;
			bestmoves[index+2] = z;
			//m represents 0 for not placing anything, 1 for tiger on a feild, 2 for tiger on water, 3 for tiger on a path, and 4 for placing a croc
			bestmoves[index+3] = value[1];
			index = 0;
		}
		//since we havent chosen this location yet, I want to to go back to nothing
		//_TileGrid[x][y] = NULL;
	}
	int m = bestmoves[3];
	if(m > 0 && m < 5)
		updateTigerCount(0);
	if(m == 5)
		updateCrocodileCount();
	updateBoard(_TileGrid, x, y, t, z);
	//update components?
	//update meeplecount?
	return bestmoves;
}

//generate possible valid moves, thinking of having it stacked as x, y, z, x, y, z, ... z being the orientation
void Player::generateMoves(Tile _TileGrid[153][153], list<int> &movelist, Tile curTile) {
	vector<emptySpace> temp = emptyTiles;
	emptySpace curr;
	Tile tempTile1;
	Tile tempTile2;
	int x, y;
	bool top, bottom, left, right;
	while(!temp.empty()){
		curr = temp.back();
		x = curr.x;
		y = curr.y;
		top = curr.top;
		bottom = curr.bottom;
		left = curr.left;
		right = curr.right;
		temp.pop_back();
		tempTile1 = _TileGrid[x][y];
		for(int m = 0; m<4; m++){
			int a, b, c, d, e, f, g, h, i, j, k, l, z;
			if(m == 0)
				a = 0, b = 1, c = 2, d = 6, e = 5, f = 4, g = 2, h = 3, i = 4, j = 0, k = 7, l = 6, z = 0;
			else if(m == 1)
				a = 2, b = 3, c = 4, d = 0, e = 7, f = 6, g = 4, h = 5, i = 6, j = 2, k = 1, l = 0, z = 90;
			else if(m == 2)
				a = 4, b = 5, c = 6, d = 2, e = 1, f = 0, g = 6, h = 7, i = 0, j = 4, k = 3, l = 2, z = 180;
			else 
				a = 6, b = 7, c = 0, d = 4, e = 3, f = 2, g = 0, h = 1, i = 2, j = 6, k = 5, l = 4, z = 270;
			if(top == true){
				if(bottom == true){
					if(right == true){
						if(left == true){
							//logic for if all four sides have tiles
							tempTile2 = _TileGrid[x+1][y];
							//Up
							if(tempTile2.type[6] == tempTile1.type[a] && tempTile2.type[5] == tempTile1.type[b] && tempTile2.type[4] == tempTile1.type[c]){
								tempTile2 = _TileGrid[x-1][y];
								//Down
								if(tempTile2.type[0] == tempTile1.type[d] && tempTile2.type[1] == tempTile1.type[e] && tempTile2.type[2] == tempTile1.type[f]){
									tempTile2 = _TileGrid[x][y+1];
									//Right
									if(tempTile2.type[0] == tempTile1.type[g] && tempTile2.type[7] == tempTile1.type[h] && tempTile2.type[6] == tempTile1.type[i]){
										tempTile2 = _TileGrid[x][y-1];
										//Left
										if(tempTile2.type[2] == tempTile1.type[j] && tempTile2.type[3] == tempTile1.type[k] && tempTile2.type[4] == tempTile1.type[l]){
											movelist.push_back(x); /*x*/
											movelist.push_back(y); /*y*/
											movelist.push_back(z); /*z*/
										}
									}
								}
							}
						}
						else{
							//logic for if only the top, bottom, and right has tiles
							tempTile2 = _TileGrid[x+1][y];
							if(tempTile2.type[6] == tempTile1.type[a] && tempTile2.type[5] == tempTile1.type[b] && tempTile2.type[4] == tempTile1.type[c]){
								tempTile2 = _TileGrid[x-1][y];
								if(tempTile2.type[0] == tempTile1.type[d] && tempTile2.type[1] == tempTile1.type[e] && tempTile2.type[2] == tempTile1.type[f]){
									tempTile2 = _TileGrid[x][y+1];
									if(tempTile2.type[0] == tempTile1.type[g] && tempTile2.type[7] == tempTile1.type[h] && tempTile2.type[6] == tempTile1.type[i]){
										movelist.push_back(x); /*x*/
										movelist.push_back(y); /*y*/
										movelist.push_back(z); /*z*/
									}
								}
							}
						}
					}
					else if(left == true){
						//logic for if the top, bottom, and left have tiles
						tempTile2 = _TileGrid[x+1][y];
						if(tempTile2.type[6] == tempTile1.type[a] && tempTile2.type[5] == tempTile1.type[b] && tempTile2.type[4] == tempTile1.type[c]){
							tempTile2 = _TileGrid[x-1][y];
							if(tempTile2.type[0] == tempTile1.type[d] && tempTile2.type[1] == tempTile1.type[e] && tempTile2.type[2] == tempTile1.type[f]){
								tempTile2 = _TileGrid[x][y-1];
								if(tempTile2.type[2] == tempTile1.type[j] && tempTile2.type[3] == tempTile1.type[k] && tempTile2.type[4] == tempTile1.type[l]){
									movelist.push_back(x); /*x*/
									movelist.push_back(y); /*y*/
									movelist.push_back(z); /*z*/
								}
							}
						}
					}
					else{
						//logic for if just the top and the bottom have a tile
						tempTile2 = _TileGrid[x+1][y];
						if(tempTile2.type[6] == tempTile1.type[a] && tempTile2.type[5] == tempTile1.type[b] && tempTile2.type[4] == tempTile1.type[c]){
							tempTile2 = _TileGrid[x-1][y];
							if(tempTile2.type[0] == tempTile1.type[d] && tempTile2.type[1] == tempTile1.type[e] && tempTile2.type[2] == tempTile1.type[f]){
								movelist.push_back(x); /*x*/
								movelist.push_back(y); /*y*/
								movelist.push_back(z); /*z*/
							}
						}
					}
				}
				if(right == true){
					if(left == true){
						//logic for if top, right, and left have tiles
						tempTile2 = _TileGrid[x+1][y];
						if(tempTile2.type[6] == tempTile1.type[a] && tempTile2.type[5] == tempTile1.type[b] && tempTile2.type[4] == tempTile1.type[c]){
							tempTile2 = _TileGrid[x][y+1];
							if(tempTile2.type[0] == tempTile1.type[g] && tempTile2.type[7] == tempTile1.type[h] && tempTile2.type[6] == tempTile1.type[i]){
								tempTile2 = _TileGrid[x][y-1];
								if(tempTile2.type[2] == tempTile1.type[j] && tempTile2.type[3] == tempTile1.type[k] && tempTile2.type[4] == tempTile1.type[l]){
									movelist.push_back(x); /*x*/
									movelist.push_back(y); /*y*/
									movelist.push_back(z); /*z*/
								}
							}
						}
					}
				}
				if(left == true){
					//logic for if the top and left have tiles
					tempTile2 = _TileGrid[x+1][y];
					if(tempTile2.type[6] == tempTile1.type[a] && tempTile2.type[5] == tempTile1.type[b] && tempTile2.type[4] == tempTile1.type[c]){
						tempTile2 = _TileGrid[x][y-1];
						if(tempTile2.type[2] == tempTile1.type[j] && tempTile2.type[3] == tempTile1.type[k] && tempTile2.type[4] == tempTile1.type[l]){
							movelist.push_back(x); /*x*/
							movelist.push_back(y); /*y*/
							movelist.push_back(z); /*z*/
						}
					}
				}
				else{
					//logic for if only the top has a tile
					tempTile2 = _TileGrid[x+1][y];
					if(tempTile2.type[6] == tempTile1.type[a] && tempTile2.type[5] == tempTile1.type[b] && tempTile2.type[4] == tempTile1.type[c]){
						movelist.push_back(x); /*x*/
						movelist.push_back(y); /*y*/
						movelist.push_back(z); /*z*/
					}
				}
			}
			if(bottom == true){
				if(right == true){
					if(left == true){
						//logic for if the bottom, right, and left have tiles
						tempTile2 = _TileGrid[x-1][y];
						if(tempTile2.type[0] == tempTile1.type[d] && tempTile2.type[1] == tempTile1.type[e] && tempTile2.type[2] == tempTile1.type[f]){
							tempTile2 = _TileGrid[x][y+1];
							if(tempTile2.type[0] == tempTile1.type[g] && tempTile2.type[7] == tempTile1.type[h] && tempTile2.type[6] == tempTile1.type[i]){
								tempTile2 = _TileGrid[x][y-1];
								if(tempTile2.type[2] == tempTile1.type[j] && tempTile2.type[3] == tempTile1.type[k] && tempTile2.type[4] == tempTile1.type[l]){
									movelist.push_back(x); /*x*/
									movelist.push_back(y); /*y*/
									movelist.push_back(z); /*z*/
								}
							}
						}
					}
					else{
						//logic for if the bottom and right have tiles
						tempTile2 = _TileGrid[x-1][y];
						if(tempTile2.type[0] == tempTile1.type[d] && tempTile2.type[1] == tempTile1.type[e] && tempTile2.type[2] == tempTile1.type[f]){
							tempTile2 = _TileGrid[x][y+1];
							if(tempTile2.type[0] == tempTile1.type[g] && tempTile2.type[7] == tempTile1.type[h] && tempTile2.type[6] == tempTile1.type[i]){
								movelist.push_back(x); /*x*/
								movelist.push_back(y); /*y*/
								movelist.push_back(z); /*z*/
							}
						}
					}
				}
				if(left == true){
					//logic for if the bottom and left have tiles
					tempTile2 = _TileGrid[x-1][y];
					if(tempTile2.type[0] == tempTile1.type[d] && tempTile2.type[1] == tempTile1.type[e] && tempTile2.type[2] == tempTile1.type[f]){
						tempTile2 = _TileGrid[x][y-1];
						if(tempTile2.type[2] == tempTile1.type[j] && tempTile2.type[3] == tempTile1.type[k] && tempTile2.type[4] == tempTile1.type[l]){
							movelist.push_back(x); /*x*/
							movelist.push_back(y); /*y*/
							movelist.push_back(z); /*z*/
						}
					}
				}
				else{
					//logic for if just the bottom has a tile
					tempTile2 = _TileGrid[x-1][y];
					if(tempTile2.type[0] == tempTile1.type[d] && tempTile2.type[1] == tempTile1.type[e] && tempTile2.type[2] == tempTile1.type[f]){
						movelist.push_back(x); /*x*/
						movelist.push_back(y); /*y*/
						movelist.push_back(z); /*z*/
					}
				}
			}
			if(right == true){
				if(left == true){
					//logic for if the right and the left have tiles
					tempTile2 = _TileGrid[x][y+1];
					if(tempTile2.type[0] == tempTile1.type[g] && tempTile2.type[7] == tempTile1.type[h] && tempTile2.type[6] == tempTile1.type[i]){
						tempTile2 = _TileGrid[x][y-1];
						if(tempTile2.type[2] == tempTile1.type[j] && tempTile2.type[3] == tempTile1.type[k] && tempTile2.type[4] == tempTile1.type[l]){
							movelist.push_back(x); /*x*/
							movelist.push_back(y); /*y*/
							movelist.push_back(z); /*z*/
						}
					}
				}
				else{
					//logic for if just the right has a tile
					tempTile2 = _TileGrid[x][y+1];
					if(tempTile2.type[0] == tempTile1.type[g] && tempTile2.type[7] == tempTile1.type[h] && tempTile2.type[6] == tempTile1.type[i]){
						movelist.push_back(x); /*x*/
						movelist.push_back(y); /*y*/
						movelist.push_back(z); /*z*/
					}
				}
			}
			if(left == true){
				//logic for if just the left has a tile
				tempTile2 = _TileGrid[x][y-1];
					if(tempTile2.type[2] == tempTile1.type[j] && tempTile2.type[3] == tempTile1.type[k] && tempTile2.type[4] == tempTile1.type[l]){
						movelist.push_back(x); /*x*/
						movelist.push_back(y); /*y*/
						movelist.push_back(z); /*z*/
					}
			}
		}
	}
}

//This is the opponents future move
int *Player::MinMoveDecision(Tile _TileGrid[153][153], int x, int y, int z, int moveNum, vector<tile> temp, Tile t) {
	int *pvalue = evaluatePosition(_TileGrid, x, y, z, moveNum, t);
	if(pvalue[0] == -1)
		return pvalue;
	int bvalue[2] = {+BESTVALUE, 0};
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
		//int value = MaxMoveDecision(_TileGrid, x, y, z, moveNum+1, temp, t);
		//if we dont do use max move then we need an evaluatePosition method to get value
		int *value = evaluatePosition(_TileGrid, x, y, z, moveNum, t);
		if(value[0] > bvalue[0]){
			bvalue[0] = value[0];
			bvalue[1] = value[1];
		}
	}
	return bvalue;
}

//this is our future move
int *Player::MaxMoveDecision(Tile _TileGrid[153][153], int x, int y, int z, int moveNum, vector<tile> temp, Tile t) {
	int *pvalue = evaluatePosition(_TileGrid, x, y, z, moveNum, t);
	if(pvalue[0] == -1)
		return pvalue;
	int bvalue[2] = {+BESTVALUE, 0};
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
		//int value = MinMoveDecision(_TileGrid, x, y, z, moveNum+1, temp, t);
		//if we dont do use min move then we need an evaluatePosition method to get value
		int *value = evaluatePosition(_TileGrid, x, y, z, moveNum, t);
		if(value[0] > bvalue[0]){
			bvalue[0] = value[0];
			bvalue[1] = value[1];
		}
	}
	return bvalue;
}

//returns the value of the tile at that location also any prunning needed
//also any logic here can be changed or added, this is just a starting point for checking and such
int *Player::evaluatePosition(Tile _TileGrid[153][153], int x, int y, int z, int num, Tile t) {
	int value[2];
	int mLocation;
	//should first check to see if we are helping the other player out with this move and return '-'1, if we have time
	if((mLocation = tigerLocation(_TileGrid, x, y, z, num, t)) > 0){
		//return a value of 10 for feilds
		if(mLocation == 4){
			value[0] = 20;
			value[1] = 4;
			return value;
		}
		else if(mLocation == 1){
			value[0] = 10;
			value[1] = 1;
			return value;
		}
		//return a value of 5 for water
		else if(mLocation == 2){
			value[0] = 5;
			value[1] = 2;
			return value;
		}
		//return a value of 3 for paths
		else if(mLocation == 3){
			value[0] = 3;
			value[1] = 3;
			return value;
		}
		//return a value of 2 for crocs
		else{
			value[0] = 2;
			value[1] = 5;
			return value;
		}
	}
	else{
		value[0] = 0;
		value[1] = 0;
		return value;
	}
}

//picks tiger or croc location on tile
//also any logic here can be changed or added, this is just a starting point for checking and such
int Player::tigerLocation(Tile _TileGrid[153][153], int x, int y, int z, int moveNum, Tile t){
	int options[4];
	tigerCheck(options, _TileGrid, x, y, t);
	//moveNum is, for example, move number 2 or 3 so to get number of tiles left we subtract it from 76
	int num = 76 - moveNum;
	//options[0] = the feild, options[1] = the water, options[2] = the path, options[3] = places a crocodile, options[4] = den
	if(num >= 50){
		//in this if statement, given these conditions, the presedence would be field over water over path 
		if(options[3] == 1 && tigerCount != 0)
			return 4;
		else if(options[0] == 1 && tigerCount != 0)
			return 1;
		else if(options[1] == 1 && tigerCount != 0)
			return 2;
		else if(options[2] == 1 && tigerCount != 0)
			return 3;
		else 
			return 0;
	}
	else if(num >= 30){
		//in this if statement, given these conditions, the presedence would be water over feild over path
		if(options[3] == 1 && tigerCount != 0)
			return 4;
		else if(options[1] == 1 && tigerCount != 0)
			return 2;
		else if(options[0] == 1 && tigerCount >= 3)
			return 1;
		else if(options[2] == 1 && tigerCount != 0)
			return 3;
		else 
			return 0;
	}
	else if(num >= 10){
		//in this if statement, given these conditions, the presedence would be water over path over placing a croc
		if(options[3] == 1 && tigerCount != 0)
			return 4;
		else if(options[1] == 1 && tigerCount != 0)
			return 2;
		else if(options[2] == 1 && tigerCount != 0)
			return 3;
		else if(options[3] == 1 && crocodileCount != 0)
			return 4;
		else 
			return 0;
	}
	else if (num >= 3){
		//in this if statement, given these conditions, the presedence would be water over path over placing a croc
		if(options[3] == 1 && tigerCount != 0)
			return 4;
		else if(options[1] == 1 && tigerCount != 0)
			return 2;
		else if(options[2] == 1 && tigerCount != 0)
			return 3;
		else if(options[3] == 1 && crocodileCount != 0)
			return 4;
		else 
			return 0;
	}
}

//checks the components to see where we can legally place tigers on this tile
void Player::tigerCheck(int options[4], Tile _TileGrid[153][153], int x, int y, Tile t){
    if(tigerCount == 0){
        options[0] = 0;
		options[1] = 0;
		options[2] = 0;
		options[3] = 0;
    }
	else{
		options[0] = 0;
		options[1] = 0;
		options[2] = 0;
		options[3] = 0;
		options[4] = 0;
		int q = _TileGrid[x+1][y].clusterid.at(5);
		while (q != MainList[q].ParentId)
		{
			q = MainList[q].ParentId;
		}
		if (_TilePresent[x+1][y] == true && (_TileGrid[x+1][y].type.at(5) == 1 || _TileGrid[x+1][y].type.at(5) == 3) && MainList[q].MeepleCountMe == 0 && MainList[q].MeepleCountYou == 0) 
		{
			options[0] = 1;
		}
		q = _TileGrid[x-1][y].clusterid.at(1);
		while (q != MainList[q].ParentId)
		{
			q = MainList[q].ParentId;
		}
		if (_TilePresent[x-1][y] == true && (_TileGrid[x-1][y].type.at(1) == 1 || _TileGrid[x-1][y].type.at(1) == 3) && MainList[q].MeepleCountMe == 0 && MainList[q].MeepleCountYou == 0) 
		{
			options[1] = 1;
		}
		q = _TileGrid[x][y+1].clusterid.at(7);
		while (q != MainList[q].ParentId)
		{
			q = MainList[q].ParentId;
		}
		if (_TilePresent[x][y+1] == true && (_TileGrid[x][y+1].type.at(7) == 1 || _TileGrid[x][y+1].type.at(7) == 3) && MainList[q].MeepleCountMe == 0 && MainList[q].MeepleCountYou == 0) 
		{
			options[2] = 1;
		}
		q = _TileGrid[x][y-1].clusterid.at(3);
		while (q != MainList[q].ParentId)
		{
			q = MainList[q].ParentId;
		}
		if (_TilePresent[x][y-1] == true && (_TileGrid[x][y-1].type.at(3) == 1 || _TileGrid[x][y-1].type.at(3) == 3) && MainList[q].MeepleCountMe == 0 && MainList[q].MeepleCountYou == 0) 
		{
			options[3] = 1;
		}
		if (t.Den == true)
		{
			options[4] = 1;
		} 
	}
}
//this updates our tigerCount. If the value is zero then we used a tiger, if the number is something else then we are receiving our tiger(s)
void Player::updateTigerCount(int value){
	if (value == 0)
		tigerCount--;
	else
		tigerCount = tigerCount + value;
}


Tile tileStructure(int i){
	if(i == 0){

		Tile Tile_1;
                // = new Tile(
                //                 {'J', 'J', 'J', 'J', '-'},
                //                 {2,2,2,2,2,2,2,2},
                //                 {1,1,1,1,1,1,1,1},
                //                 {false,false,false,false,false,false,false,false},
                //                 0,
                //                 false,
                //                 false,
                //                 false,
                //                 false,
                //                 0,
                //                 0,
                //                 {false});

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

        Tile Tile_2;
        // = new Tile(
        //                        {'J', 'J', 'J', 'J', 'X'},
        //                        {2,2,2,2,2,2,2,2},
        //                        {1,1,1,1,1,1,1,1},
        //                        {false,false,false,false,false,false,false,false},
        //                        0,
        //                        false,
        //                        false,
        //                        false,
        //                        true,
        //                        0,
        //                        0,
        //                        {false});
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

        Tile Tile_3;
        // = new Tile(
        //                        {'J', 'J', 'T', 'J', 'X'},
        //                        {2,2,2,2,2,3,2,2},
        //                        {1,1,1,1,1,1,1,1},
        //                        {false,false,false,false,false,false,false,false},
        //                        0,
        //                        false,
        //                        false,
        //                        false,
        //                        true,
        //                        0,
        //                        0,
        //                        {false});
        
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

        Tile Tile_4;
        // = new Tile(
        //                        {'T', 'T', 'T', 'T', '-'},
        //                        {2,3,2,3,2,3,2,3},
        //                        {1,2,1,2,1,2,1,2},
        //                        {false,false,false,false,false,false,false,false},
        //                        0,
        //                        false,
        //                        false,
        //                        false,
        //                        false,
        //                        0,
        //                        0,
        //                        {false});
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
	
        Tile Tile_5;
        // = new Tile(
        //                        {'T', 'J', 'T', 'J', '-'},
        //                        {2,3,2,2,2,3,2,2},
        //                        {1,2,1,1,1,2,1,1},
        //                        {false,false,false,false,false,false,false,false},
        //                        0,
        //                        false,
        //                        false,
        //                        false,
        //                        false,
        //                        0,
        //                        0,
        //                        {false});
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

        Tile Tile_6; 
        // = new Tile(
        //                        {'T', 'J', 'J', 'T', '-'},
        //                        {2,3,2,2,2,2,2,3},
        //                        {1,2,1,1,1,1,1,2},
        //                        {false,false,false,false,false,false,false,false},
        //                        0,
        //                        false,
        //                        false,
        //                        false,
        //                        false,
        //                        0,
        //                        0,
        //                        {false});
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

        Tile Tile_7; 
        // = new Tile(
        //                        {'T', 'J', 'T', 'T', '-'},
        //                        {2,3,2,2,2,2,3,2,3},
        //                        {1,2,1,1,1,2,1,2},
        //                        {false,false,false,false,false,false,false,false},
        //                        0,
        //                        false,
        //                        false,
        //                        false,
        //                        false,
        //                        0,
        //                        0,
        //                        {false});
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

        Tile Tile_8; 
        // = new Tile(
        //                        {'L', 'L', 'L', 'L', '-'},
        //                        {1,1,1,1,1,1,1,1},
        //                        {1,1,1,1,1,1,1,1},
        //                        {false,false,false,false,false,false,false,false},
        //                        0,
        //                        false,
        //                        false,
        //                        false,
        //                        false,
        //                        0,
        //                        0,
        //                        {false});
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

        Tile Tile_9; 
        // = new Tile(
        //                        {'J', 'L', 'L', 'L', '-'},
        //                        {2,2,2,1,1,1,1,1},
        //                        {1,1,1,2,2,2,2,2},
        //                        {false,false,false,false,false,false,false,false},
        //                        0,
        //                        false,
        //                        false,
        //                        false,
        //                        false,
        //                        0,
        //                        0,
        //                        {false});
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

        Tile Tile_10;
        // = new Tile(
        //                        {'L', 'L', 'J', 'J', '-'},
        //                        {2,1,1,1,2,2,2,2},
        //                        {1,2,2,2,1,1,1,1},
        //                        {false,false,false,false,false,false,false,false},
        //                        0,
        //                        false,
        //                        false,
        //                        false,
        //                        false,
        //                        0,
        //                        0,
        //                        {false});
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

        Tile Tile_11;
        // = new Tile(
        //                        {'J', 'L', 'J', 'L', '-'},
        //                        {2,2,2,1,2,2,2,1},
        //                        {1,1,1,2,3,3,3,2},
        //                        {false,false,false,false,false,false,false,false},
        //                        0,
        //                        false,
        //                        false,
        //                        false,
        //                        false,
        //                        0,
        //                        0,
        //                        {false});
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
	
        Tile Tile_12;
        // = new Tile(
        //                        {'L', 'J', 'L', 'J', '-'},
        //                        {2,1,2,2,2,1,2,2},
        //                        {1,2,1,1,1,3,1,1},
        //                        {false,false,false,false,false,false,false,false},
        //                        0,
        //                        false,
        //                        false,
        //                        false,
        //                        false,
        //                        0,
        //                        0,
        //                        {false});
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

        Tile Tile_13;
        // = new Tile(
        //                        {'L', 'J', 'J', 'J', '-'},
        //                        {2,1,2,2,2,2,2,2},
        //                        {1,2,1,1,1,1,1,1},
        //                        {false,false,false,false,false,false,false,false},
        //                        0,
        //                        false,
        //                        false,
        //                        false,
        //                        false,
        //                        0,
        //                        0,
        //                        {false});
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

        Tile Tile_14;
        // = new Tile(
        //                        {'J', 'L', 'L', 'J', '-'},
        //                        {2,2,2,1,4,1,2,2},
        //                        {1,1,1,2,0,3,1,1},
        //                        {false,false,false,false,false,false,false,false},
        //                        0,
        //                        false,
        //                        false,
        //                        false,
        //                        false,
        //                        0,
        //                        0,
        //                        {false});
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

        Tile Tile_15;
        // = new Tile(
        //                        {'T', 'L', 'J', 'T', '-'},
        //                        {2,3,2,1,2,2,2,3},
        //                        {1,2,1,3,1,1,1,2},
        //                        {false,false,false,false,false,false,false,false},
        //                        0,
        //                        false,
        //                        false,
        //                        false,
        //                        false,
        //                        0,
        //                        0,
        //                        {false});
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

        Tile Tile_16;
        // = new Tile(
        //                        {'T', 'L', 'J', 'T', 'P'},
        //                        {2,3,2,1,2,2,2,3},
        //                        {1,2,1,3,1,1,1,2},
        //                        {false,false,false,false,false,false,false,false},
        //                        0,
        //                        false,
        //                        true,
        //                        false,
        //                        false,
        //                        0,
        //                        0,
        //                        {false});
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

        Tile Tile_17;
        // = new Tile(
        //                        {'J', 'L', 'T', 'T', '-'},
        //                        {2,2,2,1,2,3,2,3},
        //                        {1,1,1,2,1,3,4,3},
        //                        {false,false,false,false,false,false,false,false},
        //                        0,
        //                        false,
        //                        false,
        //                        false,
        //                        false,
        //                        0,
        //                        0,
        //                        {false});
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
	
        Tile Tile_18;
        // = new Tile(
        //                        {'J', 'L', 'T', 'T', 'B'},
        //                        {2,2,2,1,2,3,2,3},
        //                        {1,1,1,2,1,3,4,3},
        //                        {false,false,false,false,false,false,false,false},
        //                        0,
        //                        true,
        //                        false,
        //                        false,
        //                        false,
        //                        0,
        //                        0,
        //                        {false});
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
	
        Tile Tile_19;
        // = new Tile(
        //                        {'T', 'L', 'T', 'J', '-'},
        //                        {2,3,2,1,2,3,2,3},
        //                        {1,2,3,4,3,2,1,1},
        //                        {false,false,false,false,false,false,false,false},
        //                        0,
        //                        false,
        //                        false,
        //                        false,
        //                        false,
        //                        0,
        //                        0,
        //                        {false});
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

        Tile Tile_20;
        // = new Tile(
        //                        {'T', 'L', 'T', 'J', 'D'},
        //                        {2,3,2,1,2,3,2,3},
        //                        {1,2,3,4,3,2,1,1},
        //                        {false,false,false,false,false,false,false,false},
        //                        0,
        //                        false,
        //                        false,
        //                        true,
        //                        false,
        //                        0,
        //                        0,
        //                        {false});
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

        Tile Tile_21;
        // = new Tile(
        //                        {'T', 'L', 'L', 'L', '-'},
        //                        {2,3,2,1,1,1,1,1},
        //                        {1,2,3,4,4,4,4,4},
        //                        {false,false,false,false,false,false,false,false},
        //                        0,
        //                        false,
        //                        false,
        //                        false,
        //                        false,
        //                        0,
        //                        0,
        //                        {false});
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

        Tile Tile_22;
        // = new Tile(
        //                        {'T', 'L', 'T', 'T', '-'},
        //                        {2,3,2,1,2,2,2,3},
        //                        {1,2,3,4,3,2,5,2},
        //                        {false,false,false,false,false,false,false,false},
        //                        0,
        //                        false,
        //                        false,
        //                        false,
        //                        false,
        //                        0,
        //                        0,
        //                        {false});
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

        Tile Tile_23;
        // = new Tile(
        //                        {'T', 'L', 'T', 'T', 'P'},
        //                        {2,3,2,1,2,2,2,3},
        //                        {1,2,3,4,3,2,5,2},
        //                        {false,false,false,false,false,false,false,false},
        //                        0,
        //                        false,
        //                        true,
        //                        false,
        //                        false,
        //                        0,
        //                        0,
        //                        {false});
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

        Tile Tile_24;
        // = new Tile(
        //                        {'T', 'L', 'L', 'T', '-'},
        //                        {2,3,2,1,1,1,2,3},
        //                        {1,2,3,4,4,4,3,2},
        //                        {false,false,false,false,false,false,false,false},
        //                        0,
        //                        false,
        //                        false,
        //                        false,
        //                        false,
        //                        0,
        //                        0,
        //                        {false});
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

        Tile Tile_25;
        // = new Tile(
        //                        {'T', 'L', 'L', 'T', 'B'},
        //                        {2,3,2,1,1,1,2,3},
        //                        {1,2,3,4,4,4,3,2},
        //                        {false,false,false,false,false,false,false,false},
        //                        0,
        //                        true,
        //                        false,
        //                        false,
        //                        false,
        //                        0,
        //                        0,
        //                        {false});
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

        Tile Tile_26;
        // = new Tile(
        //                        {'L', 'J', 'T', 'J', '-'},
        //                        {2,1,2,2,2,3,2,2},
        //                        {1,2,3,3,3,4,1,1},
        //                        {false,false,false,false,false,false,false,false},
        //                        0,
        //                        false,
        //                        false,
        //                        false,
        //                        false,
        //                        0,
        //                        0,
        //                        {false});
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
	
        Tile Tile_27;

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
		
        Tile Tile_28;
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


Tile* Player::getTile(char const* temp2){
	char a = temp2[0];
	char b = temp2[1];
	char c = temp2[2];
	char d = temp2[3];
	char e = temp2[4];
	for(int i = 0; i < 28; i++){
		//tile structure holds all the hard coded values for each tile
		Tile temp = tileStructure(i);
                Tile * ptr = &temp;
		vector<char> temp1 = ptr->des;
		if(a == temp1[0] && b == temp1[1] && c == temp1[2] && d == temp1[3] && e == temp1[4])
			return ptr;
	}
}




