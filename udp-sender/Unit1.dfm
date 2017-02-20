object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'UPD-sender'
  ClientHeight = 108
  ClientWidth = 256
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 8
    Top = 86
    Width = 49
    Height = 13
    Caption = 'Last stat: '
  end
  object Label2: TLabel
    Left = 8
    Top = 62
    Width = 31
    Height = 13
    Caption = 'Bytes:'
  end
  object Label3: TLabel
    Left = 45
    Top = 62
    Width = 20
    Height = 13
  end
  object Edit1: TEdit
    Left = 8
    Top = 8
    Width = 121
    Height = 21
    TabOrder = 0
    TextHint = 'IP X.X.X.X'
  end
  object Edit2: TEdit
    Left = 135
    Top = 8
    Width = 34
    Height = 21
    TabOrder = 1
    TextHint = 'Port'
  end
  object Edit3: TEdit
    Left = 8
    Top = 35
    Width = 161
    Height = 21
    TabOrder = 2
    TextHint = 'String data'
    OnChange = Edit3Change
  end
  object Button1: TButton
    Left = 175
    Top = 8
    Width = 66
    Height = 48
    Caption = 'Send'
    TabOrder = 3
    OnClick = Button1Click
  end
end
