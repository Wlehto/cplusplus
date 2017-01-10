#pragma hdrstop
#pragma argsused

#include <tchar.h>
#include <stdio.h>
#include <iostream>

using namespace std;

void PassByRef(std::string &refString){
    cout << "PassByRef &refString address: " << &refString <<  endl;
    cout << "with value of: " << refString.data() << endl;
    refString = "trumppa";
    cout << "edited value of refString to: " << refString.data() << endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
    std::string stringit = "Stringande";

    cout << "Main stringin address: " << &stringit << endl;
    cout << "with value of: " << stringit.data() << endl;
    PassByRef(stringit);
    cout << "New value in main should be: " << stringit.data() << endl;

    system("pause");
	return 0;
}
