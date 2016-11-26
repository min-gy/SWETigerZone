//Component Tracking
//x and y will refer to Coordinates of tile being placed
#include <iostream>
#include <vector>
#include "MapClass.cpp"
#include "PlayerClass.cpp"
using namespace std;
void InheritValue(ComponentTracker* Child, ComponentTracker* Parent) 
{
	if ( Child->Ox == true)
	{
		Parent->Ox = true;
	}
	if ( Child->Deer == true)
	{
		Parent->Deer = true;
	}
	if ( Child->Boar == true)
	{
		Parent->Boar = true;
	}
	Parent->CrocCount = Parent->CrocCount + Child->CrocCount;
	Parent->MeepleCountYou += Child->MeepleCountYou;
	Parent->MeepleCountMe += Child->MeepleCountMe;
	Parent->IncompleteSides += Child->IncompleteSides;
	Child->ParentId = Parent->ParentId;
	//Delete Child from 'To-Check' List ```````````````WITHIN MAPCLASS``````````````````
	//Only Check parents for scoring and updates
}
int ScoreUpdate(ComponentTracker* Region)
{
	//score calc
	int score;
	int game;
	game = 0;
	score = Region->TileCount;
	if ( Region->Boar == true)
	{
		game += 1;
	}
	if ( Region->Deer == true)
	{
		game += 1;
	}
	if ( Region->Ox == true)
	{
		game += 1;
	}
	game -= Region->CrocCount;
	if ( game > 0 )
	{
		score += game;
	}
	if ( Region->IncompleteSides == 0 )
	{
		score = score * 2;
	}
	return score;
}
void MeepleUpdate(ComponentTracker* Region, Player player)
{
	player.MeepleCountMe += Region->MeepleCountMe;
	player.MeepleCountYou += Region->MeepleCountYou;
	Region->MeepleCountMe = 0;
	Region->MeepleCountYou = 0;
}
void SingleUpdate(Map Mappy, Tile CurrentTile, Tile OldTile, int newS, int oldS, int Side, Player player)
{
	int x;
	int y;
	bool DontAdd;
	DontAdd = false;
	//Catch for nonexistent tile
	if (OldTile.orientation != NULL)
	{
		if (CurrentTile.type.at(newS) == OldTile.type.at(oldS))
		{
			//Special Check for corner Jungle -> Jungle
			if ((newS % 2 == 1) && (CurrentTile.type.at(newS) == 2))
			{
				switch(Side)
				{
      			  	case 1: 
      			  		if (OldTile.type.at(6) == 1)
      			  		{
      			  			DontAdd = true;
      			  		}
      			  	break;
 					case 2:
 						if (OldTile.type.at(8) == 1)
      			  		{
      			  			DontAdd = true;
      			  		}
 					break;
        			case 3:
        				if (OldTile.type.at(2) == 1)
      			  		{
      			  			DontAdd = true;
      			  		}
        			break;
        			case 4:
        				if (OldTile.type.at(4) == 1)
      			  		{
      			  			DontAdd = true;
      			  		}
        			break;
        		}
				/*MAKE A SPECIAL CATCH FOR WHEN 2 SEPERATE CASTLE SECTIONS OVERLAP AT CORNER ----> Corner section type = 4? throwaway?
````````````
````````````
````````````
````````````````
				*/

			}
			x = CurrentTile.clusterid.at(newS);
			y = OldTile.clusterid.at(oldS);

			while (x != Mappy.MainList[x]->ParentId)
			{
			 	x = Mappy.MainList[x]->ParentId;		
			 	if (x == y)
			 	{// REQUIRE CATCH FOR scenario in which y already absorbed into x->parent
			 		DontAdd = true;
			 	}	 	
			}	
			if (DontAdd == false)
			{
				while (y != Mappy.MainList[y]->ParentId)
				{
			 		y = Mappy.MainList[y]->ParentId;			 	
				}
				//InheritValue(ComponentTracker Child, ComponentTracker Parent)
				InheritValue(Mappy.MainList[x], Mappy.MainList[y]);
			}
			if ((newS % 2 == 0) && (CurrentTile.type.at(newS) != 2)) 
			{
				Mappy.MainList[y]->IncompleteSides -= 2;
				if ( Mappy.MainList[y]->IncompleteSides == 0 )
				{
					if (Mappy.MainList[y]->MeepleCountMe >= Mappy.MainList[y]->MeepleCountYou)
					{
						player.ScoreMe += ScoreUpdate(Mappy.MainList[y]);	
					}
					if (Mappy.MainList[y]->MeepleCountMe <= Mappy.MainList[y]->MeepleCountYou)
					{
						player.ScoreYou += ScoreUpdate(Mappy.MainList[y]);
					}
					MeepleUpdate(Mappy.MainList[y], player);
				}
			}
		}
	}
}
void FullComponentUpdate(Map Mappy, int X, int Y, Player player)
{
	Tile CurrentTile;
	Tile LeftTile;
	Tile RightTile;
	Tile UpTile;
	Tile DownTile;

	CurrentTile = Mappy.TileGrid[X][Y];

	LeftTile = Mappy.TileGrid[X-1][Y];
	RightTile = Mappy.TileGrid[X+1][Y];
	UpTile = Mappy.TileGrid[X][Y+1];
	DownTile = Mappy.TileGrid[X][Y-1];

	//SingleUpdate(Map Mappy, Tile CurrentTile, Tile OldTile, int newS, int oldS);
	SingleUpdate(Mappy, CurrentTile, UpTile, 1, 7, 1, player);
	SingleUpdate(Mappy, CurrentTile, UpTile, 2, 6, 1, player);
	SingleUpdate(Mappy, CurrentTile, UpTile, 3, 5, 1, player);

	SingleUpdate(Mappy, CurrentTile, RightTile, 3, 1, 2, player);
	SingleUpdate(Mappy, CurrentTile, RightTile, 4, 8, 2, player);
	SingleUpdate(Mappy, CurrentTile, RightTile, 5, 7, 2, player);

	SingleUpdate(Mappy, CurrentTile, DownTile, 5, 3, 3, player);
	SingleUpdate(Mappy, CurrentTile, DownTile, 6, 2, 3, player);
	SingleUpdate(Mappy, CurrentTile, DownTile, 7, 1, 3, player);

	SingleUpdate(Mappy, CurrentTile, LeftTile, 7, 5, 4, player);
	SingleUpdate(Mappy, CurrentTile, LeftTile, 8, 4, 4, player);
	SingleUpdate(Mappy, CurrentTile, LeftTile, 1, 3, 4, player);

}