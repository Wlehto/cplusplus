//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------
class upd;

class TForm1 : public TForm
{
__published:	// IDE-managed Components
    TEdit *Edit1;
    TEdit *Edit2;
    TEdit *Edit3;
    TButton *Button1;
    TLabel *Label1;
    TLabel *Label2;
    TLabel *Label3;
    void __fastcall Button1Click(TObject *Sender);
    void __fastcall Edit3Change(TObject *Sender);
private:	// User declarations
    upd *packetSender;
public:		// User declarations
    __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
