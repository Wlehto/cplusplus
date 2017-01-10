#pragma hdrstop
#pragma argsused

#include <tchar.h>
#include <stdio.h>
#include <iostream>

class A
{
private:
    int var_A;
    static int id;

    int objID;
public:
    A() : var_A(123){
        id++;
        this->objID = id;
    }

    ~A(){
        id--;
    }

    virtual int getVar(){
        if(var_A == 0){
            this->var_A = 1;
        }

        return this->var_A;
    }

    virtual int setVar(r_var_A){
        this->var_A = r_var_A;
    }

    virtual int getIDcount(){
        return this->id;
    }

     virtual int getID(){
        return this->objID;
    }
};

int A::id = 0;

class B: public A
{
private:
    int var_B;
public:
    B() : var_B(666) {
        std::cout << "Object B created" << std::endl;
    }
};

class C: public B
{

};

int _tmain(int argc, _TCHAR* argv[])
{
    B objectB;
    C objectC;

    std::cout << "================================" << std::endl;

    std::cout << "Object B id: " << objectB.getID() << std::endl;
    std::cout << "Object C id: " << objectC.getID() << std::endl;

    system("pause");
	return 0;
}
