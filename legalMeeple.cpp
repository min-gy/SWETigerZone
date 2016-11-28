//
//  legalMeeple.cpp
//  practice
//
//  Created by Karl on 11/27/16.
//  Copyright © 2016 Karl. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include "MapClass.cpp"
using namespace std;


vector<int> placeMeeple(int x, int y, Map GameMap, Tile nextTile)
{
    vector<int> meepleLocation;
    
    if(/*Meeple count is equal to zero*/false)
    {
        return meepleLocation;
    }
    
    int q = 0;
    for(int w = 0; w < 9; w++)
    {
        q = nextTile.clusterid[w];
        
        while (q != GameMap.MainList[q]->ParentId)
        {
            q = GameMap.MainList[q]->ParentId;
        }
        
        if(GameMap.MainList[q]->MeepleCountMe == 0 && GameMap.MainList[q]->MeepleCountYou == 0)
        {
            meepleLocation.push_back(w+1);
        }
    }
    
    return meepleLocation;
}

int main()
{
    
}
