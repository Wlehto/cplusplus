//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <System.Actions.hpp>
#include <Vcl.ActnCtrls.hpp>
#include <Vcl.ActnList.hpp>
#include <Vcl.ActnMan.hpp>
#include <Vcl.ActnMenus.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.PlatformDefaultStyleActnCtrls.hpp>
#include <Vcl.StdActns.hpp>
#include <Vcl.ToolWin.hpp>
//---------------------------------------------------------------------------
class TTextEditorForm : public TForm
{
__published:	// IDE-managed Components
    TActionManager *ActionMgr;
    TActionMainMenuBar *ActionMainMenuBar1;
    TStatusBar *TextStatus;
    TMemo *TextMemo;
    TFileOpen *FileOpen1;
    TFileSaveAs *FileSaveAs1;
    TFileExit *FileExit1;
    TAction *New;
    TAction *Save;
    TEditCut *EditCut1;
    TEditCopy *EditCopy1;
    TEditPaste *EditPaste1;
    TEditSelectAll *EditSelectAll1;
    TEditUndo *EditUndo1;
    TEditDelete *EditDelete1;
    TFontEdit *FontEdit1;
    TAction *WordWrap;
    TAction *FileClose;
    void __fastcall NewExecute(TObject *Sender);
    void __fastcall FileOpen1Accept(TObject *Sender);
    void __fastcall SaveExecute(TObject *Sender);
    void __fastcall FileSaveAs1Accept(TObject *Sender);
    void __fastcall FontEdit1Accept(TObject *Sender);
    void __fastcall WordWrapExecute(TObject *Sender);
    void __fastcall TextMemoMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
    void __fastcall TextMemoKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
    void __fastcall FileCloseExecute(TObject *Sender);

private:	// User declarations
    String currentFile;
public:		// User declarations
    __fastcall TTextEditorForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TTextEditorForm *TextEditorForm;
//---------------------------------------------------------------------------
#endif
