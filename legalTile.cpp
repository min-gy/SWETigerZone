//
//  main.cpp
//  practice
//
//  Created by Karl on 11/21/16.
//  Copyright © 2016 Karl. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include "MapClass.cpp"
using namespace std;

void checkPlay(vector<Tile> legal)
{
    if(legal.empty())
    {
        //pass
        //pick up tiger
        //double up tiger
    }else
    {
        //placeTile(<#int x#>, <#int y#>, <#Map GameMap#>, <#Tile GameTile#>);
    }
}

vector<Tile> legalTile(int x, int y, Map GameMap, Tile nextTile)
{
    vector<Tile> possibleConnections;
    vector<Tile> legalMovesFinal;
    Tile tempTile = *new Tile;
    emptySpace *tempSpot = new emptySpace;
    
    if(!GameMap.TilePresent[x][y+1])
    {
        GameMap.TileGrid[x][y].completion[0] = false;
        tempSpot->x = x;
        tempSpot->y = y + 1;
        if(GameMap.TilePresent[x][y+2])
        {
            tempSpot->top = true;
        }
        if(GameMap.TilePresent[x+1][y+1])
        {
            tempSpot->right = true;
        }
        if(GameMap.TilePresent[x-1][y+1])
        {
            tempSpot->left = true;
        }
        GameMap.emptyTiles.push_back(*tempSpot);
    }else
    {
        GameMap.TileGrid[x][y].completion[0] = true;
    }
    
    if(!GameMap.TilePresent[x+1][y])
    {
        GameMap.TileGrid[x][y].completion[1] = false;
        tempSpot->x = x + 1;
        tempSpot->y = y;
        if(GameMap.TilePresent[x+2][y])
        {
            tempSpot->right = true;
        }
        if(GameMap.TilePresent[x+1][y+1])
        {
            tempSpot->top = true;
        }
        if(GameMap.TilePresent[x+1][y-1])
        {
            tempSpot->bottom = true;
        }
        GameMap.emptyTiles.push_back(*tempSpot);
    }else
    {
        GameMap.TileGrid[x][y].completion[1] = true;
    }
    
    if(!GameMap.TilePresent[x][y-1])
    {
        GameMap.TileGrid[x][y].completion[2] = false;
        tempSpot->x = x;
        tempSpot->y = y - 1;
        if(GameMap.TilePresent[x][y-2])
        {
            tempSpot->bottom = true;
        }
        if(GameMap.TilePresent[x+1][y-1])
        {
            tempSpot->right = true;
        }
        if(GameMap.TilePresent[x-1][y-1])
        {
            tempSpot->left = true;
        }
        GameMap.emptyTiles.push_back(*tempSpot);
    }else
    {
        GameMap.TileGrid[x][y].completion[2] = true;
    }
    
    if(!GameMap.TilePresent[x-1][y])
    {
        GameMap.TileGrid[x][y].completion[3] = false;
        tempSpot->x = x - 1;
        tempSpot->y = y;
        if(GameMap.TilePresent[x-2][y])
        {
            tempSpot->left = true;
        }
        if(GameMap.TilePresent[x-1][y+1])
        {
            tempSpot->top = true;
        }
        if(GameMap.TilePresent[x-1][y+1])
        {
            tempSpot->bottom = true;
        }
        GameMap.emptyTiles.push_back(*tempSpot);
    }else
    {
        GameMap.TileGrid[x][y].completion[3] = true;
    }
    
    
    for(int k = 0; k < GameMap.emptyTiles.size(); k++)
    {
        if(GameMap.emptyTiles[k].top)
        {
            possibleConnections.push_back(GameMap.TileGrid[GameMap.emptyTiles[k].x][GameMap.emptyTiles[k].y + 1]);
        }else if(GameMap.emptyTiles[k].right)
        {
            possibleConnections.push_back(GameMap.TileGrid[GameMap.emptyTiles[k].x + 1][GameMap.emptyTiles[k].y]);
        }else if(GameMap.emptyTiles[k].bottom)
        {
            possibleConnections.push_back(GameMap.TileGrid[GameMap.emptyTiles[k].x][GameMap.emptyTiles[k].y - 1]);
        }else if(GameMap.emptyTiles[k].left)
        {
            possibleConnections.push_back(GameMap.TileGrid[GameMap.emptyTiles[k].x - 1][GameMap.emptyTiles[k].y]);
        }
    }
    
    for(int i = 0; i < possibleConnections.size(); i++)
    {
        
        //0 references top side
        if(!possibleConnections[i].completion[0])
        {
            for(int z = 0; z < 4; z++)
            {
                if(possibleConnections[i].type[0] == nextTile.type[6])
                {
                    if(possibleConnections[i].type[1] == nextTile.type[5])
                    {
                        if(possibleConnections[i].type[2] == nextTile.type[4])
                        {
                            if(!tempSpot->top && !tempSpot->left && !tempSpot->right)
                            {
                                tempTile = nextTile;
                                tempTile.x = possibleConnections[i].x;
                                tempTile.y = possibleConnections[i].y + 1;
                                //rotate tile 0
                                
                                legalMovesFinal.push_back(tempTile);
                            }else if(tempSpot->top)
                            {
                                if(GameMap.TileGrid[possibleConnections[i].x][possibleConnections[i].y + 2].type[6] == nextTile.type[0])
                                {
                                    if(GameMap.TileGrid[possibleConnections[i].x][possibleConnections[i].y + 2].type[5] == nextTile.type[1])
                                    {
                                        if(GameMap.TileGrid[possibleConnections[i].x][possibleConnections[i].y + 2].type[4] == nextTile.type[2])
                                        {
                                            if(tempSpot->right)
                                            {
                                                if(GameMap.TileGrid[possibleConnections[i].x + 1][possibleConnections[i].y + 1].type[0] == nextTile.type[2])
                                                {
                                                    if(GameMap.TileGrid[possibleConnections[i].x + 1][possibleConnections[i].y + 1].type[7] == nextTile.type[3])
                                                    {
                                                        if(GameMap.TileGrid[possibleConnections[i].x + 1][possibleConnections[i].y + 1].type[6] == nextTile.type[4])
                                                        {
                                                            if(tempSpot->left)
                                                            {
                                                                if(GameMap.TileGrid[possibleConnections[i].x - 1][possibleConnections[i].y + 1].type[2] == nextTile.type[0])
                                                                {
                                                                    if(GameMap.TileGrid[possibleConnections[i].x - 1][possibleConnections[i].y + 1].type[3] == nextTile.type[7])
                                                                    {
                                                                        if(GameMap.TileGrid[possibleConnections[i].x - 1][possibleConnections[i].y + 1].type[4] == nextTile.type[6])
                                                                        {
                                                                            tempTile = nextTile;
                                                                            tempTile.x = possibleConnections[i].x;
                                                                            tempTile.y = possibleConnections[i].y + 1;
                                                                            //rotate tile 0
                                                                            
                                                                            legalMovesFinal.push_back(tempTile);
                                                                        }
                                                                    }
                                                                }
                                                            }else
                                                            {
                                                                tempTile = nextTile;
                                                                tempTile.x = possibleConnections[i].x;
                                                                tempTile.y = possibleConnections[i].y + 1;
                                                                //rotate tile 0
                                                                
                                                                legalMovesFinal.push_back(tempTile);
                                                            }
                                                            
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }else if(tempSpot->right)
                            {
                                if(GameMap.TileGrid[possibleConnections[i].x][possibleConnections[i].y + 2].type[0] == nextTile.type[2])
                                {
                                    if(GameMap.TileGrid[possibleConnections[i].x][possibleConnections[i].y + 2].type[7] == nextTile.type[3])
                                    {
                                        if(GameMap.TileGrid[possibleConnections[i].x][possibleConnections[i].y + 2].type[6] == nextTile.type[4])
                                        {
                                            if(tempSpot->left)
                                            {
                                                if(GameMap.TileGrid[possibleConnections[i].x - 1][possibleConnections[i].y + 1].type[2] == nextTile.type[0])
                                                {
                                                    if(GameMap.TileGrid[possibleConnections[i].x - 1][possibleConnections[i].y + 1].type[3] == nextTile.type[7])
                                                    {
                                                        if(GameMap.TileGrid[possibleConnections[i].x - 1][possibleConnections[i].y + 1].type[4] == nextTile.type[6])
                                                        {
                                                            tempTile = nextTile;
                                                            tempTile.x = possibleConnections[i].x;
                                                            tempTile.y = possibleConnections[i].y + 1;
                                                            //rotate tile 0
                                                            
                                                            legalMovesFinal.push_back(tempTile);
                                                        }
                                                    }
                                                }
                                            }else
                                            {
                                                tempTile = nextTile;
                                                tempTile.x = possibleConnections[i].x;
                                                tempTile.y = possibleConnections[i].y + 1;
                                                //rotate tile 0
                                                
                                                legalMovesFinal.push_back(tempTile);
                                            }
                                        }
                                    }
                                }
                            }else if(tempSpot->left)
                            {
                                if(GameMap.TileGrid[possibleConnections[i].x - 1][possibleConnections[i].y + 1].type[2] == nextTile.type[0])
                                {
                                    if(GameMap.TileGrid[possibleConnections[i].x - 1][possibleConnections[i].y + 1].type[3] == nextTile.type[7])
                                    {
                                        if(GameMap.TileGrid[possibleConnections[i].x - 1][possibleConnections[i].y + 1].type[4] == nextTile.type[6])
                                        {
                                            tempTile = nextTile;
                                            tempTile.x = possibleConnections[i].x;
                                            tempTile.y = possibleConnections[i].y + 1;
                                            //rotate tile 0
                                            
                                            legalMovesFinal.push_back(tempTile);
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                
                //rotate nextTile 90 degrees
            }
        }
        
            
        //1 if open side is right side
        if(!possibleConnections[i].completion[1])
        {
            for(int z = 0; z < 4; z++)
            {
                if(possibleConnections[i].type[2] == nextTile.type[0])
                {
                    if(possibleConnections[i].type[3] == nextTile.type[7])
                    {
                        if(possibleConnections[i].type[4] == nextTile.type[6])
                        {
                            if(!tempSpot->top && !tempSpot->right && !tempSpot->bottom)
                            {
                                tempTile = nextTile;
                                tempTile.x = possibleConnections[i].x + 1;
                                tempTile.y = possibleConnections[i].y;
                                
                                legalMovesFinal.push_back(tempTile);
                            }else if(tempSpot->top)
                            {
                                if(GameMap.TileGrid[possibleConnections[i].x + 1][possibleConnections[i].y + 1].type[6] == nextTile.type[0])
                                {
                                    if(GameMap.TileGrid[possibleConnections[i].x + 1][possibleConnections[i].y + 1].type[5] == nextTile.type[1])
                                    {
                                        if(GameMap.TileGrid[possibleConnections[i].x + 1][possibleConnections[i].y + 1].type[4] == nextTile.type[2])
                                        {
                                            if(tempSpot->right)
                                            {
                                                if(GameMap.TileGrid[possibleConnections[i].x + 2][possibleConnections[i].y].type[0] == nextTile.type[2])
                                                {
                                                    if(GameMap.TileGrid[possibleConnections[i].x + 2][possibleConnections[i].y].type[7] == nextTile.type[3])
                                                    {
                                                        if(GameMap.TileGrid[possibleConnections[i].x + 2][possibleConnections[i].y].type[6] == nextTile.type[4])
                                                        {
                                                            if(tempSpot->bottom)
                                                            {
                                                                if(GameMap.TileGrid[possibleConnections[i].x + 1][possibleConnections[i].y - 1].type[0] == nextTile.type[6])
                                                                {
                                                                    if(GameMap.TileGrid[possibleConnections[i].x + 1][possibleConnections[i].y - 1].type[1] == nextTile.type[5])
                                                                    {
                                                                        if(GameMap.TileGrid[possibleConnections[i].x + 1][possibleConnections[i].y - 1].type[2] == nextTile.type[4])
                                                                        {
                                                                            tempTile = nextTile;
                                                                            tempTile.x = possibleConnections[i].x + 1;
                                                                            tempTile.y = possibleConnections[i].y;
                                                                            //rotate tile 0
                                                                            
                                                                            legalMovesFinal.push_back(tempTile);
                                                                        }
                                                                    }
                                                                }
                                                            }else
                                                            {
                                                                tempTile = nextTile;
                                                                tempTile.x = possibleConnections[i].x + 1;
                                                                tempTile.y = possibleConnections[i].y;
                                                                //rotate tile 0
                                                                
                                                                legalMovesFinal.push_back(tempTile);
                                                            }
                                                            
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }else if(tempSpot->right)
                            {
                                if(GameMap.TileGrid[possibleConnections[i].x + 2][possibleConnections[i].y].type[0] == nextTile.type[2])
                                {
                                    if(GameMap.TileGrid[possibleConnections[i].x + 2][possibleConnections[i].y].type[7] == nextTile.type[3])
                                    {
                                        if(GameMap.TileGrid[possibleConnections[i].x + 2][possibleConnections[i].y].type[6] == nextTile.type[4])
                                        {
                                            if(tempSpot->bottom)
                                            {
                                                if(GameMap.TileGrid[possibleConnections[i].x + 1][possibleConnections[i].y - 1].type[0] == nextTile.type[6])
                                                {
                                                    if(GameMap.TileGrid[possibleConnections[i].x + 1][possibleConnections[i].y - 1].type[1] == nextTile.type[5])
                                                    {
                                                        if(GameMap.TileGrid[possibleConnections[i].x + 1][possibleConnections[i].y - 1].type[2] == nextTile.type[4])
                                                        {
                                                            tempTile = nextTile;
                                                            tempTile.x = possibleConnections[i].x + 1;
                                                            tempTile.y = possibleConnections[i].y;
                                                            
                                                            legalMovesFinal.push_back(tempTile);
                                                        }
                                                    }
                                                }
                                            }else
                                            {
                                                tempTile = nextTile;
                                                tempTile.x = possibleConnections[i].x + 1;
                                                tempTile.y = possibleConnections[i].y;
                                                
                                                legalMovesFinal.push_back(tempTile);
                                            }
                                        }
                                    }
                                }
                            }else if(tempSpot->bottom)
                            {
                                if(GameMap.TileGrid[possibleConnections[i].x + 1][possibleConnections[i].y - 1].type[0] == nextTile.type[6])
                                {
                                    if(GameMap.TileGrid[possibleConnections[i].x + 1][possibleConnections[i].y - 1].type[1] == nextTile.type[5])
                                    {
                                        if(GameMap.TileGrid[possibleConnections[i].x + 1][possibleConnections[i].y - 1].type[2] == nextTile.type[4])
                                        {
                                            tempTile = nextTile;
                                            tempTile.x = possibleConnections[i].x + 1;
                                            tempTile.y = possibleConnections[i].y;
                                            
                                            legalMovesFinal.push_back(tempTile);
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                
                //rotate nextTile 90 degrees
            }
        }
        
        
        //2 if bottom is uncompleted
        
        if(!possibleConnections[i].completion[2])
        {
            for(int z = 0; z < 4; z++)
            {
                if(possibleConnections[i].type[2] == nextTile.type[0])
                {
                    if(possibleConnections[i].type[3] == nextTile.type[7])
                    {
                        if(possibleConnections[i].type[4] == nextTile.type[6])
                        {
                            if(!tempSpot->bottom && !tempSpot->left && !tempSpot->right)
                            {
                                tempTile = nextTile;
                                tempTile.x = possibleConnections[i].x;
                                tempTile.y = possibleConnections[i].y - 1;
                                
                                legalMovesFinal.push_back(tempTile);
                            }else if(tempSpot->bottom)
                            {
                                if(GameMap.TileGrid[possibleConnections[i].x][possibleConnections[i].y - 2].type[0] == nextTile.type[6])
                                {
                                    if(GameMap.TileGrid[possibleConnections[i].x][possibleConnections[i].y - 2].type[1] == nextTile.type[5])
                                    {
                                        if(GameMap.TileGrid[possibleConnections[i].x][possibleConnections[i].y - 2].type[2] == nextTile.type[4])
                                        {
                                            if(tempSpot->right)
                                            {
                                                if(GameMap.TileGrid[possibleConnections[i].x + 1][possibleConnections[i].y - 1].type[0] == nextTile.type[2])
                                                {
                                                    if(GameMap.TileGrid[possibleConnections[i].x + 1][possibleConnections[i].y - 1].type[7] == nextTile.type[3])
                                                    {
                                                        if(GameMap.TileGrid[possibleConnections[i].x + 1][possibleConnections[i].y - 1].type[6] == nextTile.type[4])
                                                        {
                                                            if(tempSpot->left)
                                                            {
                                                                if(GameMap.TileGrid[possibleConnections[i].x - 1][possibleConnections[i].y - 1].type[2] == nextTile.type[0])
                                                                {
                                                                    if(GameMap.TileGrid[possibleConnections[i].x - 1][possibleConnections[i].y - 1].type[3] == nextTile.type[7])
                                                                    {
                                                                        if(GameMap.TileGrid[possibleConnections[i].x - 1][possibleConnections[i].y - 1].type[4] == nextTile.type[6])
                                                                        {
                                                                            tempTile = nextTile;
                                                                            tempTile.x = possibleConnections[i].x;
                                                                            tempTile.y = possibleConnections[i].y - 1;
                                                                            
                                                                            legalMovesFinal.push_back(tempTile);
                                                                        }
                                                                    }
                                                                }
                                                            }else
                                                            {
                                                                tempTile = nextTile;
                                                                tempTile.x = possibleConnections[i].x;
                                                                tempTile.y = possibleConnections[i].y - 1;
                                                                
                                                                legalMovesFinal.push_back(tempTile);
                                                            }
                                                            
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }else if(tempSpot->right)
                            {
                                if(GameMap.TileGrid[possibleConnections[i].x + 1][possibleConnections[i].y - 1].type[0] == nextTile.type[2])
                                {
                                    if(GameMap.TileGrid[possibleConnections[i].x + 1][possibleConnections[i].y - 1].type[7] == nextTile.type[3])
                                    {
                                        if(GameMap.TileGrid[possibleConnections[i].x + 1][possibleConnections[i].y - 1].type[6] == nextTile.type[4])
                                        {
                                            if(tempSpot->left)
                                            {
                                                if(GameMap.TileGrid[possibleConnections[i].x - 1][possibleConnections[i].y - 1].type[2] == nextTile.type[0])
                                                {
                                                    if(GameMap.TileGrid[possibleConnections[i].x - 1][possibleConnections[i].y - 1].type[3] == nextTile.type[7])
                                                    {
                                                        if(GameMap.TileGrid[possibleConnections[i].x - 1][possibleConnections[i].y - 1].type[4] == nextTile.type[6])
                                                        {
                                                            tempTile = nextTile;
                                                            tempTile.x = possibleConnections[i].x;
                                                            tempTile.y = possibleConnections[i].y - 1;
                                                            
                                                            legalMovesFinal.push_back(tempTile);
                                                        }
                                                    }
                                                }
                                            }else
                                            {
                                                tempTile = nextTile;
                                                tempTile.x = possibleConnections[i].x;
                                                tempTile.y = possibleConnections[i].y - 1;
                                                
                                                legalMovesFinal.push_back(tempTile);
                                            }
                                        }
                                    }
                                }
                            }else if(tempSpot->left)
                            {
                                if(GameMap.TileGrid[possibleConnections[i].x - 1][possibleConnections[i].y - 1].type[2] == nextTile.type[0])
                                {
                                    if(GameMap.TileGrid[possibleConnections[i].x - 1][possibleConnections[i].y - 1].type[3] == nextTile.type[7])
                                    {
                                        if(GameMap.TileGrid[possibleConnections[i].x - 1][possibleConnections[i].y - 1].type[4] == nextTile.type[6])
                                        {
                                            tempTile = nextTile;
                                            tempTile.x = possibleConnections[i].x;
                                            tempTile.y = possibleConnections[i].y - 1;
                                            
                                            legalMovesFinal.push_back(tempTile);
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                
                //rotate nextTile 90 degrees
            }
        }
        
        if(!possibleConnections[i].completion[3])
        {
            for(int z = 0; z < 4; z++)
            {
                if(possibleConnections[i].type[2] == nextTile.type[0])
                {
                    if(possibleConnections[i].type[3] == nextTile.type[7])
                    {
                        if(possibleConnections[i].type[4] == nextTile.type[6])
                        {
                            if(!tempSpot->top && !tempSpot->left && !tempSpot->bottom)
                            {
                                tempTile = nextTile;
                                tempTile.x = possibleConnections[i].x - 1;
                                tempTile.y = possibleConnections[i].y;
                                
                                legalMovesFinal.push_back(tempTile);
                            }else if(tempSpot->top)
                            {
                                if(GameMap.TileGrid[possibleConnections[i].x - 1][possibleConnections[i].y + 1].type[6] == nextTile.type[0])
                                {
                                    if(GameMap.TileGrid[possibleConnections[i].x - 1][possibleConnections[i].y + 1].type[5] == nextTile.type[1])
                                    {
                                        if(GameMap.TileGrid[possibleConnections[i].x - 1][possibleConnections[i].y + 1].type[4] == nextTile.type[2])
                                        {
                                            if(tempSpot->left)
                                            {
                                                if(GameMap.TileGrid[possibleConnections[i].x - 2][possibleConnections[i].y].type[2] == nextTile.type[0])
                                                {
                                                    if(GameMap.TileGrid[possibleConnections[i].x - 2][possibleConnections[i].y].type[3] == nextTile.type[7])
                                                    {
                                                        if(GameMap.TileGrid[possibleConnections[i].x - 2][possibleConnections[i].y].type[4] == nextTile.type[6])
                                                        {
                                                            if(tempSpot->bottom)
                                                            {
                                                                if(GameMap.TileGrid[possibleConnections[i].x - 1][possibleConnections[i].y - 1].type[0] == nextTile.type[6])
                                                                {
                                                                    if(GameMap.TileGrid[possibleConnections[i].x - 1][possibleConnections[i].y - 1].type[1] == nextTile.type[5])
                                                                    {
                                                                        if(GameMap.TileGrid[possibleConnections[i].x - 1][possibleConnections[i].y - 1].type[2] == nextTile.type[4])
                                                                        {
                                                                            tempTile = nextTile;
                                                                            tempTile.x = possibleConnections[i].x - 1;
                                                                            tempTile.y = possibleConnections[i].y;
                                                                            //rotate tile 0
                                                                            
                                                                            legalMovesFinal.push_back(tempTile);
                                                                        }
                                                                    }
                                                                }
                                                            }else
                                                            {
                                                                tempTile = nextTile;
                                                                tempTile.x = possibleConnections[i].x - 1;
                                                                tempTile.y = possibleConnections[i].y;
                                                                //rotate tile 0
                                                                
                                                                legalMovesFinal.push_back(tempTile);
                                                            }
                                                            
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }else if(tempSpot->left)
                            {
                                if(GameMap.TileGrid[possibleConnections[i].x - 2][possibleConnections[i].y].type[2] == nextTile.type[0])
                                {
                                    if(GameMap.TileGrid[possibleConnections[i].x - 2][possibleConnections[i].y].type[3] == nextTile.type[7])
                                    {
                                        if(GameMap.TileGrid[possibleConnections[i].x - 2][possibleConnections[i].y].type[4] == nextTile.type[6])
                                        {
                                            if(tempSpot->bottom)
                                            {
                                                if(GameMap.TileGrid[possibleConnections[i].x - 1][possibleConnections[i].y - 1].type[0] == nextTile.type[6])
                                                {
                                                    if(GameMap.TileGrid[possibleConnections[i].x - 1][possibleConnections[i].y - 1].type[1] == nextTile.type[5])
                                                    {
                                                        if(GameMap.TileGrid[possibleConnections[i].x - 1][possibleConnections[i].y - 1].type[2] == nextTile.type[4])
                                                        {
                                                            tempTile = nextTile;
                                                            tempTile.x = possibleConnections[i].x - 1;
                                                            tempTile.y = possibleConnections[i].y;
                                                            
                                                            legalMovesFinal.push_back(tempTile);
                                                        }
                                                    }
                                                }
                                            }else
                                            {
                                                tempTile = nextTile;
                                                tempTile.x = possibleConnections[i].x - 1;
                                                tempTile.y = possibleConnections[i].y;
                                                
                                                legalMovesFinal.push_back(tempTile);
                                            }
                                        }
                                    }
                                }
                            }else if(tempSpot->bottom)
                            {
                                if(GameMap.TileGrid[possibleConnections[i].x - 1][possibleConnections[i].y - 1].type[0] == nextTile.type[6])
                                {
                                    if(GameMap.TileGrid[possibleConnections[i].x - 1][possibleConnections[i].y - 1].type[1] == nextTile.type[5])
                                    {
                                        if(GameMap.TileGrid[possibleConnections[i].x - 1][possibleConnections[i].y - 1].type[2] == nextTile.type[4])
                                        {
                                            tempTile = nextTile;
                                            tempTile.x = possibleConnections[i].x - 1;
                                            tempTile.y = possibleConnections[i].y;
                                            
                                            legalMovesFinal.push_back(tempTile);
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                
                //rotate nextTile 90 degrees
            }
        }
    }

    return legalMovesFinal;
}


int main()
{

    
    
    return 0;
}
