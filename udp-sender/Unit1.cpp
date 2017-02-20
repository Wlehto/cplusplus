//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"

#include <stdio.h>
#include <winsock2.h>

#pragma comment(lib, "ws2_32.lib")
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
class upd
{
    private:
        struct sockaddr_in si_other;
        int s, slen;
        char buf;
        char message;
        WSAData wsa;

        int port;
        std::string serverIP;

        TLabel *statField;
    public:
        upd(int rport, const std::string &rServerIP, TLabel* rStatField)
            : port(rport), serverIP(rServerIP), statField(rStatField), slen(sizeof(si_other))
        {
            bool initOK = true;

            if(WSAStartup(MAKEWORD(2,2), &wsa) != 0){
                statField->Caption = "Last stat: failed to initialize winsock";
                initOK = false;
            }

            if(initOK && (s=socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == SOCKET_ERROR){
                statField->Caption = "Last stat: socket() failed with error code: " + WSAGetLastError();
                initOK = false;
            }

            if(initOK){
                memset((char *) &si_other, 0, sizeof(si_other));
                si_other.sin_family = AF_INET;
                si_other.sin_port = htons(port);
                si_other.sin_addr.S_un.S_addr = inet_addr(serverIP.c_str());
                statField->Caption = "Last stat: socket() ready";
            }
        }

        void send_msg(const std::string &msg)
        {
            if(sendto(s, msg.c_str(), strlen(msg.c_str()), 0, (struct sockaddr *) &si_other, slen) == SOCKET_ERROR){
                statField->Caption = "Last stat: socket() failed with error code: " + WSAGetLastError();
            }
            else{
                statField->Caption = "Last stat: no error on socket()";
            }
        }

        ~upd(){
            closesocket(s);
            WSACleanup();
        }
};
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
    //packetSender = new upd(502, "255.255.255.0", Label1);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    //
    int port = Edit2->Text.ToInt();
    AnsiString temp = Edit1->Text;
    std::string address = temp.c_str();
    temp = Edit3->Text;
    std::string message = temp.c_str();

    packetSender = new upd(port, address, Label1);
    packetSender->send_msg(message);

    delete packetSender;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit3Change(TObject *Sender)
{
//
    Label3->Caption = Edit3->GetTextLen();
}
//---------------------------------------------------------------------------

