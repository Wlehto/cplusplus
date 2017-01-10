#pragma hdrstop
#pragma argsused

#include <tchar.h>
#include <stdio.h>
#include <iostream>

class a{
    public:
        virtual void givenInput(int input){
            std::cout << "Given parameter was int, using function from a" << std::endl;
        }

        virtual void givenInput(char input){
            std::cout << "Given paramenter was char, using function from a" << std::endl;
        }

        virtual void givenInput(int, int, bool){
            std::cout << "Two int with bool, using function from a!" << std::endl;
        }
};

class b: public a{
    public:
        using a::givenInput;
        virtual void givenInput(double input){
            std::cout << "Given parameter was double, using function from b" << std::endl;
        }

        virtual void givenInput(int i1, int i2){
            std::cout << "Two parameters(int) given, using function from b!" << std::endl;
        }
};

int _tmain(int argc, _TCHAR* argv[])
{
    a alpha;
    b beta;
    double testInput = 123.44;

    alpha.givenInput(1);
    alpha.givenInput('a');
    beta.givenInput('c');
    beta.givenInput(testInput);
    beta.givenInput(1, 2);
    beta.givenInput(1,2, false),

    system("pause");
	return 0;
}
