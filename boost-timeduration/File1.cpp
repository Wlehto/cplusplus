#pragma hdrstop
#pragma argsused

#ifdef _WIN32
#include <tchar.h>
#else
  typedef char _TCHAR;
  #define _tmain main
#endif

#include <stdio.h>
#include <iostream>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <windows.h>

//quick chekup how boost time measuring works
 int _tmain(int argc, _TCHAR* argv[]) 
{
    boost::posix_time::ptime startTicks(boost::posix_time::microsec_clock::local_time());

    int sleeptime = 1632;
    std::cout << "Sleeping for: " << sleeptime << std::endl;
    Sleep(sleeptime);

    boost::posix_time::ptime endTicks(boost::posix_time::microsec_clock::local_time());
    boost::posix_time::time_duration tickCount = endTicks - startTicks;
    long longTicks = tickCount.total_milliseconds();
    int asMs = (int)longTicks;

    std::cout << "As long ms: " << longTicks << std::endl;
    std::cout << "Casted to int: " << asMs << std::endl;

    system("pause");
    return 0;
}
