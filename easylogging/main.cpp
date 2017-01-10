#pragma hdrstop
#pragma argsused

#include <tchar.h>
#include <stdio.h>

#include <easylogging++.h>

_INITIALIZE_EASYLOGGINGPP

int _tmain(int argc, _TCHAR* argv[])
{
    LINFO << "first log";
    system("pause");
	return 0;
}
