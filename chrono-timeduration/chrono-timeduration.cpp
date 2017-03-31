#pragma hdrstop
#pragma argsused

#ifdef _WIN32
#include <tchar.h>
#else
  typedef char _TCHAR;
  #define _tmain main
#endif

#include <stdio.h>
#include <chrono>
#include <iostream>
#include <windows.h>

using namespace std::chrono;

 int _tmain(int argc, _TCHAR* argv[]) 
{
    auto startTime(steady_clock::now());

    int sleeptime(1000);
    std::cout << "Sleeping for: " << sleeptime << std::endl;
    Sleep(sleeptime);

    auto endTime(steady_clock::now());
    duration<double, std::milli> elapsedTime = endTime - startTime;

    double asDouble = elapsedTime.count();
    int asInt = (int)asDouble;

    std::cout << "As double ms: " << asDouble << std::endl;
    std::cout << "As int ms: " << asInt << std::endl;

    system("pause");

    return 0;
}


//Sleeping for: 1000
//As double ms: 1001.5
//As int ms: 1001
//Press any key to continue...