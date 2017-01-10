#pragma hdrstop
#pragma argsused

#include <tchar.h>
#include <stdio.h>
#include <iostream>

namespace ds
{
    namespace system
    {
        enum Status
        {
            Offline = 1,
            Idle = 2,
            InControl = 3,
            NofStatuses = 4
        };
    }

    class cDSClient
    {
        public:
            system::Status status;
    };
}

class cDoStuff
{
    ds::cDSClient *mc1;

    public:
        cDoStuff(ds::cDSClient *recMC1){
            mc1 =  recMC1;
            std::cout << "Tuodaan dostuffille mc1 olio: " << mc1 << std::endl;
        };

        void SetStuff(recStatus) //joko (ds::system::Status recStatus)
        {
            mc1->status = (ds::system::Status)recStatus; //tai tähän (ds::system::Status) castaus
        };

        ~cDoStuff()
        {
            std::cout << "bye bye :'( " << std::endl;
        }
};

int _tmain(int argc, _TCHAR* argv[])
{
    ds::cDSClient mc1;
    std::cout << "Luodaan mainissa mc1 olio: " << &mc1 << std::endl;

    cDoStuff *p = NULL;
    p = new cDoStuff(&mc1);

    if(!p)
    {
        std::cout << "Ee onnistun" << std::endl;
        system("pause");
        return 0;
    }
    else
    {
        std::cout << "dostuff pointteri *p onnistunna!" << std::endl;
        p->SetStuff(ds::system::Idle);

        std::cout << "MC1 enum arvo: " << mc1.status << std::endl;

        delete p;
        system("pause");
        return 0;
    }


    system("pause");
	return 0;
}
