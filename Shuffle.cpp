// File holding function that shuffles the Tiles for testing
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

vector<int> shuffleTiles();

vector<int> shuffleTiles()
{
  vector<int> numTiles;
  vector<int> tileOrder;

  //Fill vector with number of each type of tile
  //associated with tileID by index in vector
  numTiles.push_back(1);
  numTiles.push_back(4);
  numTiles.push_back(2);
  numTiles.push_back(1);
  numTiles.push_back(8);
  numTiles.push_back(9);
  numTiles.push_back(4);
  numTiles.push_back(1);
  numTiles.push_back(4);
  numTiles.push_back(5);
  numTiles.push_back(3);
  numTiles.push_back(3);
  numTiles.push_back(5);
  numTiles.push_back(2);
  numTiles.push_back(1);
  numTiles.push_back(2);
  numTiles.push_back(1);
  numTiles.push_back(2);
  numTiles.push_back(3);
  numTiles.push_back(2);
  numTiles.push_back(3);
  numTiles.push_back(1);
  numTiles.push_back(2);
  numTiles.push_back(3);
  numTiles.push_back(2);
  numTiles.push_back(1);
  numTiles.push_back(2);

  int numTilesRemaining = 77;

  //Tile 19 is always first tile (19-1=18)
  tileOrder.push_back(18);
  numTiles[18] = numTiles[18] - 1;
  numTilesRemaining--;

  //Generate random numbers from 0 to 26 (27 tile types)
  //Add the random index to the tileOrder vector
  //Decrement count for that tile type
  int randomNum = 0;
  srand(time(0));
  while(numTilesRemaining > 0)
  {
    randomNum = ( rand() % 27 );
    if(numTiles[randomNum] > 0)
    {
      tileOrder.push_back(randomNum);
      numTiles[randomNum] = numTiles[randomNum] - 1;
      numTilesRemaining--;
    }
  }

  return tileOrder; 
}

/*
int main()
{
  vector<int> tiles = shuffleTiles();
  cout << "Size is " << tiles.size() << endl;
  for(int i = 0; i < tiles.size(); i++)
  {
    cout << tiles[i] << endl;
  }
return 0;
}
*/
