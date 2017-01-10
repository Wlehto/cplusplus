//---------------------------------------------------------------------------

#pragma hdrstop
#include <time.h>
#include "ClassTimer.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

bool cTimer::runTimer()
{
    if(this->origTimer > this->tmpTimer)
    {
        this->tmpTimer = this->origTimer + this->timerInterval;
        return true;
    }

    this->origTimer = clock();
    return false;
}