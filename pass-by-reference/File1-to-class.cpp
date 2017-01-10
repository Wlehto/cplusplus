#pragma hdrstop
#pragma argsused

#include <tchar.h>
#include <stdio.h>
#include <iostream>

class refInit
{
public:
    std::string *var;
    refInit(std::string &refVar) : var(&refVar)
    {
        std::cout << "refInit obj var address: " << var << std::endl;
    };
};

int _tmain(int argc, _TCHAR* argv[])
{
    std::string foo = "bar";
    std::cout << "main::foo address: " << &foo << std::endl;
    refInit obj(foo);

    system("pause");
	return 0;
}
