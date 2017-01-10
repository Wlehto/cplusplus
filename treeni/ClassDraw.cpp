//---------------------------------------------------------------------------

#pragma hdrstop

#include "ClassDraw.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

#include <iostream>

void cCollectData::setPlayerPos(const std::vector<int> & recPlayerPos)
{
    this->playerPos = recPlayerPos;
}

void cCollectData::setMap(const std::vector< std::vector<char> > & recMap)
{
    this->map = recMap;
}

void cCollectData::mergeData(std::vector<int>& oldPos)
{
    int oldi = oldPos[0];
    int oldy = oldPos[1];

    int i = playerPos[0];
    int y = playerPos[1];

    map[oldi][oldy] = '.';
    map[i][y] = '0';
}

void cCollectData::drawData()
{
    system("cls");

    for (int i = 0; i < 20; i++)
    {
        for(int y = 0; y < 30; y++)
        {
            std::cout << map[i][y];
        }
        std::cout << std::endl;
    }
}
