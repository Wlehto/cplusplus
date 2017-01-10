//---------------------------------------------------------------------------

#pragma hdrstop

#include "ClassPlayer.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

void cPlayer::setPosition()
{
    int dirResult = rand() % 4 + 1;

    switch (dirResult) {
        case 1:     //up
            if(position[0] > 1)
                position[0] = position[0] - 1;
            break;
        case 2:     //right
            if(position[1] < this->widthLimit)
                position[1] = position[1] + 1;
            break;
        case 3:     //down
            if(position[0] < this->heightLimit)
                position[0] = position[0] + 1;
            break;
        case 4:     //left
            if(position[1] > 1)
                position[1] = position[1] - 1;
            break;
    }
}

std::vector<int> cPlayer::returnPos()
{
    return position;
}
