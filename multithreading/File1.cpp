#pragma hdrstop
#pragma argsused

#include <tchar.h>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>

#include <windows.h>
#include <process.h>

class D6
{
public:
    unsigned int currentValue;
    D6()
    {
        currentValue = 1;
    }

    void Roll()
    {
        currentValue = rand() % 6 + 1;
    }
};

unsigned int _stdcall diceThread(void *data)
{
    srand (time(NULL));

    D6 *theDice = new D6();
    for (int i = 1; i < 61; ++i)
    {
        printf("%d. Rolled D6: ", i);
        theDice->Roll();
        printf("%d\n", theDice->currentValue);
        Sleep(1000);
    }
    delete theDice;
    return 0;
}

int _tmain(int argc, _TCHAR* argv[])
{
    HANDLE diceHandle;
    int userInput = 0;

    std::cout << "1. Start rolling: ";
    std::cin >> userInput;


    if(userInput == 1)
    {
        std::cout << "9. End rolling:" << std::endl;
        diceHandle = (HANDLE)_beginthreadex(0, 0, &diceThread, 0, 0, 0);

        while(userInput != 9)
        {
            std::cin >> userInput;
            switch (userInput)
            {
                default:
                ;
            }
        }

        WaitForSingleObject(diceHandle, 1000);
        CloseHandle(diceHandle);
    }

	return 0;
}
