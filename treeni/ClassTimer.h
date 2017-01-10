//---------------------------------------------------------------------------

#ifndef ClassTimerH
#define ClassTimerH
//---------------------------------------------------------------------------
#endif

class cTimer
{
    private:
        clock_t origTimer;
        clock_t tmpTimer;

        bool timerMark;
        int timerInterval;

    public:
        cTimer(int rInterval){
            this->timerInterval = rInterval;
            this->origTimer = clock();
            this->tmpTimer = this->origTimer + timerInterval;
            this->timerMark = false;
        };

        bool runTimer();
};
