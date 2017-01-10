#pragma hdrstop
#pragma argsused

#include <tchar.h>
#include <stdio.h>
#include <iostream>
#include <vector>

#include <ClassTimer.h>
#include <ClassMapper.h>
#include <ClassPlayer.h>
#include <ClassDraw.h>

#define INTERVAL 300
#define MAPHEIGHT 20
#define MAPWIDTH 30

int _tmain(int argc, _TCHAR* argv[])
{
    cTimer timer(INTERVAL);
    bool timerResult;

    cMap mapper(MAPHEIGHT, MAPWIDTH);
    cPlayer player(MAPHEIGHT, MAPWIDTH);
    cCollectData dataCollect;

    std::vector< std::vector<char> > transmitMap = mapper.returnMap();

    dataCollect.setMap(transmitMap);

    // -------------------------------
    while(1){
        timerResult = timer.runTimer();
        if(timerResult == true){
            std::vector<int> tmp = player.returnPos();
            player.setPosition();
            dataCollect.setPlayerPos(player.returnPos());
            dataCollect.mergeData(tmp);
            dataCollect.drawData();
        }
    }
    // -------------------------------

    system("pause");
	return 0;
}
