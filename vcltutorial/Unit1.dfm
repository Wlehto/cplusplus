object TextEditorForm: TTextEditorForm
  Left = 0
  Top = 0
  Caption = 'Text Editor'
  ClientHeight = 362
  ClientWidth = 384
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  PixelsPerInch = 96
  TextHeight = 13
  object ActionMainMenuBar1: TActionMainMenuBar
    Left = 0
    Top = 0
    Width = 384
    Height = 25
    ActionManager = ActionMgr
    Caption = 'ActionMainMenuBar1'
    Color = clMenuBar
    ColorMap.DisabledFontColor = 7171437
    ColorMap.HighlightColor = clWhite
    ColorMap.BtnSelectedFont = clBlack
    ColorMap.UnusedColor = clWhite
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clMenuText
    Font.Height = -12
    Font.Name = 'Segoe UI'
    Font.Style = []
    Spacing = 0
    ExplicitLeft = 128
    ExplicitTop = 184
    ExplicitWidth = 150
    ExplicitHeight = 29
  end
  object TextStatus: TStatusBar
    Left = 0
    Top = 343
    Width = 384
    Height = 19
    Panels = <
      item
        Width = 50
      end
      item
        Width = 50
      end
      item
        Width = 50
      end>
    ExplicitLeft = 200
    ExplicitTop = 192
    ExplicitWidth = 0
  end
  object TextMemo: TMemo
    Left = 0
    Top = 25
    Width = 384
    Height = 318
    Align = alClient
    ScrollBars = ssBoth
    TabOrder = 2
    WordWrap = False
    OnKeyDown = TextMemoKeyDown
    OnMouseDown = TextMemoMouseDown
  end
  object ActionMgr: TActionManager
    ActionBars = <
      item
        Items = <
          item
            Items = <
              item
                Action = New
                Caption = '&New'
                ShortCut = 16462
              end
              item
                Action = FileOpen1
                ImageIndex = 7
                ShortCut = 16463
              end
              item
                Action = Save
                Caption = '&Save'
                ShortCut = 16467
              end
              item
                Action = FileSaveAs1
                ImageIndex = 30
              end
              item
                Action = FileClose
                Caption = '&Close'
              end
              item
                Action = FileExit1
                ImageIndex = 43
              end>
            Caption = 'F&ile'
          end
          item
            Items = <
              item
                Action = EditCut1
                ImageIndex = 0
                ShortCut = 16472
              end
              item
                Action = EditCopy1
                ImageIndex = 1
                ShortCut = 16451
              end
              item
                Action = EditPaste1
                ImageIndex = 2
                ShortCut = 16470
              end
              item
                Action = EditSelectAll1
                ShortCut = 16449
              end
              item
                Action = EditUndo1
                ImageIndex = 3
                ShortCut = 16474
              end
              item
                Action = EditDelete1
                ImageIndex = 5
                ShortCut = 46
              end>
            Caption = '&Edit'
          end
          item
            Items = <
              item
                Action = FontEdit1
                Caption = '&Font'
              end
              item
                Action = WordWrap
                Caption = '&Word Wrap'
              end>
            Caption = 'F&ormat'
          end>
        ActionBar = ActionMainMenuBar1
      end>
    Left = 184
    Top = 184
    StyleName = 'Platform Default'
    object New: TAction
      Category = 'File'
      Caption = 'New'
      ShortCut = 16462
      OnExecute = NewExecute
    end
    object FileOpen1: TFileOpen
      Category = 'File'
      Caption = '&Open...'
      Hint = 'Open|Opens an existing file'
      ImageIndex = 7
      ShortCut = 16463
      OnAccept = FileOpen1Accept
    end
    object Save: TAction
      Category = 'File'
      Caption = 'Save'
      ShortCut = 16467
      OnExecute = SaveExecute
    end
    object FileSaveAs1: TFileSaveAs
      Category = 'File'
      Caption = 'Save &As...'
      Hint = 'Save As|Saves the active file with a new name'
      ImageIndex = 30
      OnAccept = FileSaveAs1Accept
    end
    object FileClose: TAction
      Category = 'File'
      Caption = 'Close'
      OnExecute = FileCloseExecute
    end
    object FileExit1: TFileExit
      Category = 'File'
      Caption = 'E&xit'
      Hint = 'Exit|Quits the application'
      ImageIndex = 43
    end
    object EditCut1: TEditCut
      Category = 'Edit'
      Caption = 'Cu&t'
      Hint = 'Cut|Cuts the selection and puts it on the Clipboard'
      ImageIndex = 0
      ShortCut = 16472
    end
    object EditCopy1: TEditCopy
      Category = 'Edit'
      Caption = '&Copy'
      Hint = 'Copy|Copies the selection and puts it on the Clipboard'
      ImageIndex = 1
      ShortCut = 16451
    end
    object EditPaste1: TEditPaste
      Category = 'Edit'
      Caption = '&Paste'
      Hint = 'Paste|Inserts Clipboard contents'
      ImageIndex = 2
      ShortCut = 16470
    end
    object EditSelectAll1: TEditSelectAll
      Category = 'Edit'
      Caption = 'Select &All'
      Hint = 'Select All|Selects the entire document'
      ShortCut = 16449
    end
    object EditUndo1: TEditUndo
      Category = 'Edit'
      Caption = '&Undo'
      Hint = 'Undo|Reverts the last action'
      ImageIndex = 3
      ShortCut = 16474
    end
    object EditDelete1: TEditDelete
      Category = 'Edit'
      Caption = '&Delete'
      Hint = 'Delete|Erases the selection'
      ImageIndex = 5
      ShortCut = 46
    end
    object FontEdit1: TFontEdit
      Category = 'Format'
      Caption = 'Font'
      Dialog.Font.Charset = DEFAULT_CHARSET
      Dialog.Font.Color = clWindowText
      Dialog.Font.Height = -11
      Dialog.Font.Name = 'Tahoma'
      Dialog.Font.Style = []
      Hint = 'Font Select'
      OnAccept = FontEdit1Accept
    end
    object WordWrap: TAction
      Category = 'Format'
      Caption = 'Word Wrap'
      OnExecute = WordWrapExecute
    end
  end
end
