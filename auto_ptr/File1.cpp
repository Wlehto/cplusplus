#pragma hdrstop
#pragma argsused

#include <tchar.h>
#include <stdio.h>
#include <iostream>
#include <memory>

using namespace std;

class cExample
{
    private:
        int value;
    public:
        cExample() : value(10) {};

        void giefValue()
        {
            cout << value << endl;
        };
};

int _tmain(int argc, _TCHAR* argv[])
{
    auto_ptr<cExample> pEx (new cExample);

    pEx->giefValue();

    system("pause");
	return 0;
}
