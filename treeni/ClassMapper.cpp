//---------------------------------------------------------------------------

#pragma hdrstop

#include "ClassMapper.h"
#include <iostream>
#include <vector>
//---------------------------------------------------------------------------
#pragma package(smart_init)

void cMap::initMap()
{
    int i, y;

    for(i = 0; i < height; i++)
    {
        std::vector<char> row;
        for(y = 0; y < width; y++)
        {
            if(i == 0 || i == (height-1) || y == 0 || y == (width-1))
            {
                row.push_back('#');
            }
            else
            {
                row.push_back('.');
            }
        }
        iMap.push_back(row);
    }
}

void cMap::debugPrint()
{
    std::cout << height << " " << width << std::endl;

    for (int i = 0; i < height; i++)
    {
        for(int y = 0; y < width; y++)
        {
            std::cout << iMap[i][y];
        }
        std::cout << std::endl;
    }
}

std::vector< std::vector<char> > cMap::returnMap()
{
    return this->iMap;
}
