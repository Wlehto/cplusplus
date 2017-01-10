//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TTextEditorForm *TextEditorForm;
//---------------------------------------------------------------------------
__fastcall TTextEditorForm::TTextEditorForm(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TTextEditorForm::NewExecute(TObject *Sender)
{
    if(TextMemo->Lines->Count > 0)
    {
        int userResponse = MessageDlg(
            String("This will clear the current document. ")
            + "Do you want to continue?", mtInformation,
            TMsgDlgButtons() << mbYes << mbNo, 0);

        if(userResponse == mrYes)
        {
            TextMemo->Clear();
            currentFile = "";
        }
    }
}
//---------------------------------------------------------------------------
void __fastcall TTextEditorForm::FileOpen1Accept(TObject *Sender)
{
    String fileName = FileOpen1->Dialog->FileName;
    if(FileExists(fileName))
    {
        TextMemo->Lines->LoadFromFile(fileName);
        currentFile = fileName;
        this->Caption = "Text Editor - " + ExtractFileName(fileName);
    }
}
//---------------------------------------------------------------------------
void __fastcall TTextEditorForm::SaveExecute(TObject *Sender)
{
    if(currentFile == "")
    {
        this->FileSaveAs1->Execute();
    }
    else
    {
        TextMemo->Lines->SaveToFile(currentFile);
    }
}
//---------------------------------------------------------------------------
void __fastcall TTextEditorForm::FileSaveAs1Accept(TObject *Sender)
{
    String fileName = FileSaveAs1->Dialog->FileName;

    if(FileExists(fileName))
    {
        int userResponse = MessageDlg(
            String("File already exists. ") +
            "Do you want to overwrite?", mtInformation,
            TMsgDlgButtons() << mbYes << mbNo, 0);
        if(userResponse == mrNo)
        {
            return;
        }
    }

    TextMemo->Lines->SaveToFile(fileName);
    currentFile = fileName;
    this->Caption = "Text Edito - " + ExtractFileName(fileName);
}
//---------------------------------------------------------------------------
void __fastcall TTextEditorForm::FontEdit1Accept(TObject *Sender)
{
    TextMemo->Font = FontEdit1->Dialog->Font;
}
//---------------------------------------------------------------------------
void __fastcall TTextEditorForm::WordWrapExecute(TObject *Sender)
{
    TextMemo->WordWrap = !TextMemo->WordWrap;
    WordWrap->Checked = TextMemo->WordWrap;
    if(TextMemo->WordWrap == True)
    {
        TextMemo->ScrollBars = ssVertical;
    }
    else
    {
        TextMemo->ScrollBars = ssBoth;
    }
}
//---------------------------------------------------------------------------
void __fastcall TTextEditorForm::TextMemoMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y)
{
    TextStatus->Panels->Items[0]->Text =
        "L: " + String(TextMemo->CaretPos.y + 1);
    TextStatus->Panels->Items[1]->Text =
        "C: " + String(TextMemo->CaretPos.x + 1);
    TextStatus->Panels->Items[2]->Text =
        "Lines: " + IntToStr(TextMemo->Lines->Count);
}
//---------------------------------------------------------------------------
void __fastcall TTextEditorForm::TextMemoKeyDown(TObject *Sender, WORD &Key, TShiftState Shift)

{
    TextMemoMouseDown(Sender, mbLeft, Shift, 0, 0);
}
//---------------------------------------------------------------------------
void __fastcall TTextEditorForm::FileCloseExecute(TObject *Sender)
{
    int userResponse = MessageDlg(
        String ("Closing file. ") +
        + "Are you sure?", mtInformation,
        TMsgDlgButtons() << mbYes << mbNo, 0);

    if(userResponse  == mrNo)
    {
        return;
    }
    else
    {
        TextMemo->Clear();
        currentFile = "";
        this->Caption = "Text Editor";
    }
}
//---------------------------------------------------------------------------
