#pragma hdrstop
#pragma argsused

#include <tchar.h>
#include <stdio.h>
#include <iostream>

using namespace std;

class base
{
    public:
        virtual void giefPrint()
        {
            cout << "From base class" << endl;
        };
};

class derived : public base
{
    public:
        void notInBase()
        {
            cout << "This is in derived-class only" << endl;
        };

    private:
        virtual void giefPrint()
        {
            cout << "From derived class" << endl;
        };
};

void receiveDerivedPointer(base *r_obj)
{
    cout << "Calling from receiveDerivedPointer turned into base-pointer function" << endl;
    r_obj->giefPrint();
}

int _tmain(int argc, _TCHAR* argv[])
{
    base *pBase = new base();
    cout << "Calling from *pBase which is base-object " << endl;
    pBase->giefPrint();

    derived *pDer = new derived();
    cout << "Calling from *pDer which is derived-object" << endl;
    //pDer->giefPrint();
    receiveDerivedPointer(pDer);
    pDer->notInBase();

    system("pause");
	return 0;
}
