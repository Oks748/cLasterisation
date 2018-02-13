object Comparison: TComparison
  Left = 160
  Top = 118
  Width = 1132
  Height = 529
  Caption = 'k-'#1089#1077#1088#1077#1076#1085#1110#1093' '#1090#1072'  k-'#1085#1072#1081#1073#1083#1080#1078#1095#1080#1093' '#1089#1091#1089#1110#1076#1110#1074
  Color = clWhite
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnPaint = FormPaint
  PixelsPerInch = 96
  TextHeight = 13
  object LabelK: TLabel
    Left = 792
    Top = 160
    Width = 165
    Height = 26
    Alignment = taCenter
    Caption = #1050#1110#1083#1100#1082#1110#1089#1090#1100' '#1082#1083#1072#1089#1090#1077#1088#1110#1074
    Color = clWhite
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Segoe Print'
    Font.Style = []
    ParentColor = False
    ParentFont = False
    WordWrap = True
  end
  object LabelNP: TLabel
    Left = 792
    Top = 35
    Width = 222
    Height = 26
    Alignment = taCenter
    Caption = #1050#1110#1083#1100#1082#1110#1089#1090#1100' '#1088#1072#1085#1076#1086#1084#1085#1080#1093' '#1090#1086#1095#1086#1082
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Segoe Print'
    Font.Style = []
    ParentFont = False
    WordWrap = True
  end
  object LabelSusidy: TLabel
    Left = 792
    Top = 288
    Width = 134
    Height = 26
    Caption = #1050#1110#1083#1100#1082#1110#1089#1090#1100' '#1089#1091#1089#1110#1076#1110#1074
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Segoe Print'
    Font.Style = []
    ParentFont = False
  end
  object Sheets: TPageControl
    Left = 24
    Top = 24
    Width = 737
    Height = 441
    ActivePage = dimension2
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Segoe Print'
    Font.Style = []
    MultiLine = True
    ParentFont = False
    TabIndex = 0
    TabOrder = 0
    TabPosition = tpRight
    OnChange = SheetsChange
    object dimension2: TTabSheet
      Caption = #1044#1074#1086#1074#1080#1084#1110#1088#1085#1080#1081' '#1074#1077#1082#1090#1086#1088' '#1086#1079#1085#1072#1082
      object kanva: TPaintBox
        Left = 24
        Top = 16
        Width = 400
        Height = 400
        Color = clWhite
        ParentColor = False
        OnMouseUp = kanvaMouseUp
      end
      object Labelstat: TLabel
        Left = 480
        Top = 16
        Width = 108
        Height = 26
        Caption = #1057#1090#1072#1090#1080#1089#1090#1080#1082#1072
      end
      object Messages: TMemo
        Left = 456
        Top = 48
        Width = 177
        Height = 273
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'Segoe UI'
        Font.Style = []
        ParentFont = False
        ReadOnly = True
        ScrollBars = ssVertical
        TabOrder = 0
      end
    end
    object dimensionN: TTabSheet
      Caption = 'N-'#1074#1080#1084#1110#1088#1085#1080#1081' '#1074#1077#1082#1090#1086#1088' '#1086#1079#1085#1072#1082
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'Segoe Print'
      Font.Style = []
      ImageIndex = 1
      ParentFont = False
      object LabelN: TLabel
        Left = 536
        Top = 152
        Width = 97
        Height = 26
        Alignment = taCenter
        BiDiMode = bdLeftToRight
        Caption = #1056#1086#1079#1084#1110#1088#1085#1110#1089#1090#1100
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = 'Segoe Print'
        Font.Style = []
        ParentBiDiMode = False
        ParentFont = False
        WordWrap = True
      end
      object Memokmeans: TMemo
        Left = 24
        Top = 16
        Width = 481
        Height = 400
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Segoe UI'
        Font.Style = []
        Lines.Strings = (
          'Memo')
        ParentFont = False
        ReadOnly = True
        ScrollBars = ssBoth
        TabOrder = 0
      end
      object EditN: TEdit
        Left = 568
        Top = 192
        Width = 33
        Height = 26
        Color = clMoneyGreen
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = 'Bookman Old Style'
        Font.Style = [fsBold]
        MaxLength = 2
        ParentFont = False
        TabOrder = 1
        Text = '2'
        OnChange = EditNChange
      end
    end
  end
  object Clear: TButton
    Left = 792
    Top = 416
    Width = 129
    Height = 41
    Caption = #1054#1095#1080#1089#1090#1080#1090#1080
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Segoe Print'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
    OnClick = ClearClick
  end
  object Count: TButton
    Left = 792
    Top = 200
    Width = 153
    Height = 41
    Caption = #1050#1083#1072#1089#1090#1077#1088#1080#1079#1091#1074#1072#1090#1080
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Segoe Print'
    Font.Style = []
    ParentFont = False
    TabOrder = 2
    OnClick = CountClick
  end
  object EditNP: TEdit
    Left = 1032
    Top = 40
    Width = 57
    Height = 26
    Color = clMoneyGreen
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Bookman Old Style'
    Font.Style = [fsBold]
    MaxLength = 5
    ParentFont = False
    TabOrder = 3
    Text = '50'
    OnChange = EditNPChange
  end
  object EditK: TEdit
    Left = 976
    Top = 160
    Width = 33
    Height = 26
    Color = clMoneyGreen
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Bookman Old Style'
    Font.Style = [fsBold]
    MaxLength = 2
    ParentFont = False
    TabOrder = 4
    Text = '5'
    OnChange = EditKChange
  end
  object RandomPoint: TButton
    Left = 792
    Top = 72
    Width = 169
    Height = 41
    Caption = #1042#1110#1076#1082#1083#1072#1076#1077#1085#1085#1103' '#1090#1086#1095#1086#1082
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Segoe Print'
    Font.Style = []
    ParentFont = False
    TabOrder = 5
    OnClick = RandomPointClick
  end
  object EditSusidy: TEdit
    Left = 944
    Top = 289
    Width = 33
    Height = 28
    Color = clMoneyGreen
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Segoe UI'
    Font.Style = [fsBold]
    MaxLength = 3
    ParentFont = False
    TabOrder = 6
    Text = '5'
  end
  object ClustTochka: TButton
    Left = 792
    Top = 328
    Width = 217
    Height = 41
    Caption = #1050#1083#1072#1089#1090#1077#1088#1080#1079#1091#1074#1072#1090#1080' '#1090#1086#1095#1082#1091
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Segoe Print'
    Font.Style = []
    ParentFont = False
    TabOrder = 7
    OnClick = ClustTochkaClick
  end
end
