object FHotelGume: TFHotelGume
  Left = 0
  Top = 0
  BorderIcons = [biSystemMenu]
  Caption = 'Hotel za gume'
  ClientHeight = 482
  ClientWidth = 1113
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  Position = poMainFormCenter
  TextHeight = 15
  object LVlasnik: TLabel
    Left = 689
    Top = 80
    Width = 73
    Height = 28
    Alignment = taRightJustify
    Caption = '*Vlasnik:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object LBrojMobitela: TLabel
    Left = 632
    Top = 136
    Width = 130
    Height = 28
    Alignment = taRightJustify
    Caption = '*Broj mobitela:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object LMarkaDimenzija: TLabel
    Left = 611
    Top = 191
    Width = 151
    Height = 28
    Alignment = taRightJustify
    Caption = 'Marka/dimenzije:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object LLokacija: TLabel
    Left = 688
    Top = 247
    Width = 74
    Height = 28
    Alignment = taRightJustify
    Caption = 'Lokacija:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object LNapomena: TLabel
    Left = 661
    Top = 303
    Width = 101
    Height = 28
    Alignment = taRightJustify
    Caption = 'Napomena:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object LDatumZaprimanja: TLabel
    Left = 598
    Top = 360
    Width = 164
    Height = 28
    Alignment = taRightJustify
    Caption = 'Datum zaprimanja:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object Lista: TListView
    Left = 16
    Top = 8
    Width = 576
    Height = 380
    Columns = <
      item
        Caption = 'Vlasnik'
        Width = 95
      end
      item
        Caption = 'Broj mobitela'
        Width = 95
      end
      item
        Caption = 'Marka/dimenzije'
        Width = 95
      end
      item
        Caption = 'Lokacija'
        Width = 95
      end
      item
        Caption = 'Napomena'
        Width = 95
      end
      item
        Caption = 'Datum zaprimanja'
        Width = 95
      end>
    RowSelect = True
    TabOrder = 0
    ViewStyle = vsReport
    OnChange = ListaChange
  end
  object EVlasnik: TEdit
    Left = 768
    Top = 72
    Width = 337
    Height = 36
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
  end
  object EBrojMobitela: TEdit
    Left = 768
    Top = 128
    Width = 337
    Height = 36
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 2
  end
  object EMarkaDimenzija: TEdit
    Left = 768
    Top = 183
    Width = 337
    Height = 36
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 3
  end
  object ELokacija: TEdit
    Left = 768
    Top = 239
    Width = 337
    Height = 36
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 4
  end
  object ENapomena: TEdit
    Left = 768
    Top = 295
    Width = 337
    Height = 36
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 5
  end
  object DatumZaprimanja: TDateTimePicker
    Left = 768
    Top = 352
    Width = 337
    Height = 36
    Date = 46226.000000000000000000
    Time = 0.839031875002547200
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 6
  end
  object BReset: TButton
    Left = 952
    Top = 8
    Width = 153
    Height = 33
    Caption = 'Resetiraj polja'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 7
    OnClick = BResetClick
  end
  object BDodaj: TButton
    Left = 992
    Top = 394
    Width = 113
    Height = 33
    Caption = 'Dodaj'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 8
    OnClick = BDodajClick
  end
  object BUpdate: TButton
    Left = 768
    Top = 394
    Width = 218
    Height = 33
    Caption = 'A'#382'uriraj odabranog'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 9
    OnClick = BUpdateClick
  end
  object EPretraga: TEdit
    Left = 16
    Top = 394
    Width = 576
    Height = 36
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 10
    TextHint = 'Pretra'#382'i zapis...'
    OnChange = EPretragaChange
  end
  object BObrisi: TButton
    Left = 598
    Top = 8
    Width = 193
    Height = 33
    Caption = 'Obri'#353'i odabranog'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 11
    OnClick = BObrisiClick
  end
  object BPotvrda: TButton
    Left = 16
    Top = 436
    Width = 576
    Height = 33
    Caption = 'Generiraj potvrdu o zaprimamnju guma na '#269'uvanje'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 12
    OnClick = BPotvrdaClick
  end
  object siLangLinked_FHotelGume: TsiLangLinked
    Version = '7.9.11'
    StringsTypes.Strings = (
      'TIB_STRINGLIST'
      'TSTRINGLIST'
      'TWIDESTRINGS')
    NumOfLanguages = 2
    LangDispatcher = FPrijava.siLangDispatcher1
    LangDelim = 1
    LangNames.Strings = (
      'HRV'
      'ENG')
    Language = 'HRV'
    CommonContainer = FPrijava.siLang_FPrijava
    ExcludedProperties.Strings = (
      'Category'
      'SecondaryShortCuts'
      'HelpKeyword'
      'InitialDir'
      'HelpKeyword'
      'ActivePage'
      'ImeName'
      'DefaultExt'
      'FileName'
      'FieldName'
      'PickList'
      'DisplayFormat'
      'EditMask'
      'KeyList'
      'LookupDisplayFields'
      'DropDownSpecRow'
      'TableName'
      'DatabaseName'
      'IndexName'
      'MasterFields'
      'SQL'
      'DeleteSQL'
      'UpdateSQL'
      'ModifySQL'
      'KeyFields'
      'LookupKeyFields'
      'LookupResultField'
      'DataField'
      'KeyField'
      'ListField')
    Left = 552
    Top = 248
    TranslationData = {
      73007400430061007000740069006F006E0073005F0055006E00690063006F00
      640065000D000A005400460048006F00740065006C00470075006D0065000100
      48006F00740065006C0020007A0061002000670075006D006500010054006900
      72006500200068006F00740065006C0001000D000A004C0056006C0061007300
      6E0069006B0001002A0056006C00610073006E0069006B003A0001002A004F00
      77006E006500720001000D000A004C00420072006F006A004D006F0062006900
      740065006C00610001002A00420072006F006A0020006D006F00620069007400
      65006C0061003A0001002A00500068006F006E0065002000620075006D006200
      650072003A0001000D000A004C004D00610072006B006100440069006D006500
      6E007A0069006A00610001004D00610072006B0061002F00640069006D006500
      6E007A0069006A0065003A0001004D0061006B0065002F00640069006D006500
      6E00730069006F006E00730001000D000A004C004C006F006B00610063006900
      6A00610001004C006F006B006100630069006A0061003A0001004C006F006300
      6100740069006F006E003A0001000D000A004C004E00610070006F006D006500
      6E00610001004E00610070006F006D0065006E0061003A00010043006F006D00
      6D0065006E0074003A0001000D000A004C0044006100740075006D005A006100
      7000720069006D0061006E006A006100010044006100740075006D0020007A00
      61007000720069006D0061006E006A0061003A00010044006100740065002000
      6F006600200072006500630065006900700074003A0001000D000A0042005200
      65007300650074000100520065007300650074006900720061006A0020007000
      6F006C006A00610001005200650073006500740020006600690065006C006400
      730001000D000A00420044006F00640061006A00010044006F00640061006A00
      010041006400640020006E006500770001000D000A0042005500700064006100
      74006500010041007E01750072006900720061006A0020006F00640061006200
      720061006E006F00670001005500700064006100740065002000730065006C00
      6500630074006500640001000D000A0042004F00620072006900730069000100
      4F006200720069006101690020006F00640061006200720061006E006F006700
      0100440065006C006500740065002000530065006C0065006300740065006400
      01000D000A00420050006F00740076007200640061000100470065006E006500
      72006900720061006A00200070006F007400760072006400750020006F002000
      7A0061007000720069006D0061006D006E006A0075002000670075006D006100
      20006E00610020000D017500760061006E006A0065000100470065006E006500
      720061007400650020006100200074006900720065002000730074006F007200
      6100670065002000720065006300650069007000740001000D000A0073007400
      480069006E00740073005F0055006E00690063006F00640065000D000A007300
      740044006900730070006C00610079004C006100620065006C0073005F005500
      6E00690063006F00640065000D000A007300740046006F006E00740073005F00
      55006E00690063006F00640065000D000A005400460048006F00740065006C00
      470075006D00650001005300650067006F006500200055004900010053006500
      67006F00650020005500490001000D000A004C0056006C00610073006E006900
      6B0001005300650067006F006500200055004900010001000D000A004C004200
      72006F006A004D006F0062006900740065006C00610001005300650067006F00
      6500200055004900010001000D000A004C004D00610072006B00610044006900
      6D0065006E007A0069006A00610001005300650067006F006500200055004900
      010001000D000A004C004C006F006B006100630069006A006100010053006500
      67006F006500200055004900010001000D000A004C004E00610070006F006D00
      65006E00610001005300650067006F006500200055004900010001000D000A00
      4C0044006100740075006D005A0061007000720069006D0061006E006A006100
      01005300650067006F006500200055004900010001000D000A00450056006C00
      610073006E0069006B0001005300650067006F00650020005500490001000100
      0D000A004500420072006F006A004D006F0062006900740065006C0061000100
      5300650067006F006500200055004900010001000D000A0045004D0061007200
      6B006100440069006D0065006E007A0069006A00610001005300650067006F00
      6500200055004900010001000D000A0045004C006F006B006100630069006A00
      610001005300650067006F006500200055004900010001000D000A0045004E00
      610070006F006D0065006E00610001005300650067006F006500200055004900
      010001000D000A0044006100740075006D005A0061007000720069006D006100
      6E006A00610001005300650067006F006500200055004900010001000D000A00
      42005200650073006500740001005300650067006F0065002000550049000100
      01000D000A00420044006F00640061006A0001005300650067006F0065002000
      55004900010001000D000A004200550070006400610074006500010053006500
      67006F006500200055004900010001000D000A00450050007200650074007200
      61006700610001005300650067006F006500200055004900010001000D000A00
      42004F006200720069007300690001005300650067006F006500200055004900
      010001000D000A00420050006F00740076007200640061000100530065006700
      6F006500200055004900010001000D000A00730074004D0075006C0074006900
      4C0069006E00650073005F0055006E00690063006F00640065000D000A006600
      720078005200650070006F007200740031002E00530063007200690070007400
      5400650078007400010062006500670069006E002C002C0065006E0064002E00
      010001000D000A007300740053007400720069006E00670073005F0055006E00
      690063006F00640065000D000A0055004E00450053004900540045005F004F00
      42004100560045005A004E0041005F0050004F004C004A004100010055006E00
      65007300690074006500200070006F006C006A00610020006F007A006E006100
      0D0165006E00610020007300610020007A00760069006A0065007A0064006900
      63006F006D002100010050006C0065006100730065002000660069006C006C00
      200069006E00200061006C006C00200072006500710075006900720065006400
      20006600690065006C0064007300210001000D000A004F004400410042004500
      52004900540045005F005A00410050004900530001004F006400610062006500
      720069007400650020007A0061007000690073002E00010050006C0065006100
      730065002000730065006C006500630074002000610020007200650063006F00
      720064002E0001000D000A00730074004F007400680065007200530074007200
      69006E00670073005F0055006E00690063006F00640065000D000A0045005000
      72006500740072006100670061002E005400650078007400480069006E007400
      01005000720065007400720061007E01690020007A0061007000690073002E00
      2E002E0001005300650061007200630068002E002E002E0001000D000A006600
      720078005200650070006F007200740031002E00440061007400610053006500
      74004E0061006D00650001006600720078005500730065007200440061007400
      61005300650074003100010001000D000A006600720078005200650070006F00
      7200740031002E0049006E006900460069006C00650001005C0053006F006600
      740077006100720065005C00460061007300740020005200650070006F007200
      74007300010001000D000A006600720078005200650070006F00720074003100
      2E005300630072006900700074004C0061006E00670075006100670065000100
      500061007300630061006C00530063007200690070007400010001000D000A00
      6600720078005500730065007200440061007400610053006500740031002E00
      55007300650072004E0061006D00650001006600720078005500730065007200
      44006100740061005300650074003100010001000D000A007300740043006F00
      6C006C0065006300740069006F006E0073005F0055006E00690063006F006400
      65000D000A004C0069007300740061002E0043006F006C0075006D006E007300
      5B0030005D002E00430061007000740069006F006E00010056006C0061007300
      6E0069006B0001004F0077006E006500720001000D000A004C00690073007400
      61002E0043006F006C0075006D006E0073005B0031005D002E00430061007000
      740069006F006E000100420072006F006A0020006D006F006200690074006500
      6C0061000100500068006F006E00650020006E0075006D006200650072000100
      0D000A004C0069007300740061002E0043006F006C0075006D006E0073005B00
      32005D002E00430061007000740069006F006E0001004D00610072006B006100
      2F00640069006D0065006E007A0069006A00650001004D0061006B0065002F00
      640069006D0065006E00730069006F006E00730001000D000A004C0069007300
      740061002E0043006F006C0075006D006E0073005B0033005D002E0043006100
      7000740069006F006E0001004C006F006B006100630069006A00610001004C00
      6F0063006100740069006F006E0001000D000A004C0069007300740061002E00
      43006F006C0075006D006E0073005B0034005D002E0043006100700074006900
      6F006E0001004E00610070006F006D0065006E006100010043006F006D006D00
      65006E0074003A0001000D000A004C0069007300740061002E0043006F006C00
      75006D006E0073005B0035005D002E00430061007000740069006F006E000100
      44006100740075006D0020007A0061007000720069006D0061006E006A006100
      0100440061007400650020006F00660020007200650063006500690070007400
      01000D000A0073007400430068006100720053006500740073005F0055006E00
      690063006F00640065000D000A005400460048006F00740065006C0047007500
      6D0065000100440045004600410055004C0054005F0043004800410052005300
      450054000100440045004600410055004C0054005F0043004800410052005300
      4500540001000D000A004C0056006C00610073006E0069006B00010044004500
      4600410055004C0054005F004300480041005200530045005400010044004500
      4600410055004C0054005F00430048004100520053004500540001000D000A00
      4C00420072006F006A004D006F0062006900740065006C006100010044004500
      4600410055004C0054005F004300480041005200530045005400010044004500
      4600410055004C0054005F00430048004100520053004500540001000D000A00
      4C004D00610072006B006100440069006D0065006E007A0069006A0061000100
      440045004600410055004C0054005F0043004800410052005300450054000100
      440045004600410055004C0054005F0043004800410052005300450054000100
      0D000A004C004C006F006B006100630069006A00610001004400450046004100
      55004C0054005F00430048004100520053004500540001004400450046004100
      55004C0054005F00430048004100520053004500540001000D000A004C004E00
      610070006F006D0065006E0061000100440045004600410055004C0054005F00
      43004800410052005300450054000100440045004600410055004C0054005F00
      430048004100520053004500540001000D000A004C0044006100740075006D00
      5A0061007000720069006D0061006E006A006100010044004500460041005500
      4C0054005F004300480041005200530045005400010044004500460041005500
      4C0054005F00430048004100520053004500540001000D000A00450056006C00
      610073006E0069006B000100440045004600410055004C0054005F0043004800
      410052005300450054000100440045004600410055004C0054005F0043004800
      4100520053004500540001000D000A004500420072006F006A004D006F006200
      6900740065006C0061000100440045004600410055004C0054005F0043004800
      410052005300450054000100440045004600410055004C0054005F0043004800
      4100520053004500540001000D000A0045004D00610072006B00610044006900
      6D0065006E007A0069006A0061000100440045004600410055004C0054005F00
      43004800410052005300450054000100440045004600410055004C0054005F00
      430048004100520053004500540001000D000A0045004C006F006B0061006300
      69006A0061000100440045004600410055004C0054005F004300480041005200
      5300450054000100440045004600410055004C0054005F004300480041005200
      53004500540001000D000A0045004E00610070006F006D0065006E0061000100
      440045004600410055004C0054005F0043004800410052005300450054000100
      440045004600410055004C0054005F0043004800410052005300450054000100
      0D000A0044006100740075006D005A0061007000720069006D0061006E006A00
      61000100440045004600410055004C0054005F00430048004100520053004500
      54000100440045004600410055004C0054005F00430048004100520053004500
      540001000D000A00420052006500730065007400010044004500460041005500
      4C0054005F004300480041005200530045005400010044004500460041005500
      4C0054005F00430048004100520053004500540001000D000A00420044006F00
      640061006A000100440045004600410055004C0054005F004300480041005200
      5300450054000100440045004600410055004C0054005F004300480041005200
      53004500540001000D000A004200550070006400610074006500010044004500
      4600410055004C0054005F004300480041005200530045005400010044004500
      4600410055004C0054005F00430048004100520053004500540001000D000A00
      4500500072006500740072006100670061000100440045004600410055004C00
      54005F0043004800410052005300450054000100440045004600410055004C00
      54005F00430048004100520053004500540001000D000A0042004F0062007200
      6900730069000100440045004600410055004C0054005F004300480041005200
      5300450054000100440045004600410055004C0054005F004300480041005200
      53004500540001000D000A00420050006F007400760072006400610001004400
      45004600410055004C0054005F00430048004100520053004500540001004400
      45004600410055004C0054005F00430048004100520053004500540001000D00
      0A00}
  end
  object frxReport1: TfrxReport
    Version = '2024.1.2'
    DotMatrixReport = False
    IniFile = '\Software\Fast Reports'
    PreviewOptions.Buttons = [pbPrint, pbLoad, pbSave, pbExport, pbZoom, pbFind, pbOutline, pbPageSetup, pbTools, pbEdit, pbNavigator, pbExportQuick, pbCopy, pbSelection, pbWatermarks]
    PreviewOptions.Zoom = 1.000000000000000000
    PrintOptions.Printer = 'Default'
    PrintOptions.PrintOnSheet = 0
    ReportOptions.CreateDate = 46245.933925034700000000
    ReportOptions.LastChange = 46245.972879027780000000
    ScriptLanguage = 'PascalScript'
    ScriptText.Strings = (
      'begin'
      ''
      'end.')
    Left = 160
    Top = 408
    Datasets = <
      item
        DataSet = frxUserDataSet1
        DataSetName = 'frxUserDataSet1'
      end>
    Variables = <>
    Style = <>
    Watermarks = <>
    object Data: TfrxDataPage
      Height = 1000.000000000000000000
      Width = 1000.000000000000000000
    end
    object Page1: TfrxReportPage
      PaperWidth = 210.000000000000000000
      PaperHeight = 297.000000000000000000
      PaperSize = 9
      LeftMargin = 10.000000000000000000
      RightMargin = 10.000000000000000000
      TopMargin = 10.000000000000000000
      BottomMargin = 10.000000000000000000
      Frame.Typ = []
      MirrorMode = []
      object Memo1: TfrxMemoView
        AllowVectorExport = True
        Left = 7.559060100000000000
        Top = 18.897649770000000000
        Width = 347.716759780000000000
        Height = 105.826839770000000000
        ContentScaleOptions.Constraints.MaxIterationValue = 0
        ContentScaleOptions.Constraints.MinIterationValue = 0
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -15
        Font.Name = 'Arial'
        Font.Style = []
        Frame.Typ = []
        Memo.UTF8W = (
          'GUME ZELINA j.d.o.o. '
          'Adresa: Sajmi'#353'na ulica 18, 10380, Sveti Ivan Zelina'
          'OIB: 51307213322'
          'e-mail: adrianjakse001@gmail.com'
          'Mobitel: 0981305446 ')
        ParentFont = False
      end
      object Memo2: TfrxMemoView
        AllowVectorExport = True
        Left = 0.000000050000000000
        Top = 188.976496410000000000
        Width = 714.331166440000000000
        Height = 41.574839300000000000
        ContentScaleOptions.Constraints.MaxIterationValue = 0
        ContentScaleOptions.Constraints.MinIterationValue = 0
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -28
        Font.Name = 'Arial'
        Font.Style = []
        Frame.Typ = []
        HAlign = haCenter
        Memo.UTF8W = (
          'Potvrda o zaprimanju guma na '#269'uvanje')
        ParentFont = False
      end
      object Memo3: TfrxMemoView
        AllowVectorExport = True
        Left = 442.205004610000000000
        Top = -0.000003680000000000
        Width = 170.078850730000000000
        Height = 18.897659300000000000
        ContentScaleOptions.Constraints.MaxIterationValue = 0
        ContentScaleOptions.Constraints.MinIterationValue = 0
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -15
        Font.Name = 'Arial'
        Font.Style = []
        Frame.Typ = []
        Memo.UTF8W = (
          'Datum izdavanja potvrde: ')
        ParentFont = False
      end
      object MemoDate: TfrxMemoView
        IndexTag = 1
        AllowVectorExport = True
        Left = 616.063390000000000000
        Width = 120.944960000000000000
        Height = 18.897650000000000000
        ContentScaleOptions.Constraints.MaxIterationValue = 0
        ContentScaleOptions.Constraints.MinIterationValue = 0
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -15
        Font.Name = 'Arial'
        Font.Style = []
        Frame.Typ = []
        Memo.UTF8W = (
          '[Date]')
        ParentFont = False
      end
      object Memo4: TfrxMemoView
        AllowVectorExport = True
        Left = 3.779530050000000000
        Top = 317.480529790000000000
        Width = 702.992576440000000000
        Height = 68.031534040000000000
        ContentScaleOptions.Constraints.MaxIterationValue = 0
        ContentScaleOptions.Constraints.MinIterationValue = 0
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -15
        Font.Name = 'Arial'
        Font.Style = []
        Frame.Typ = []
        HAlign = haCenter
        Memo.UTF8W = (
          
            'Potvr'#273'uje se da je korisnik [frxUserDataSet1."Vlasnik"] dana [fr' +
            'xUserDataSet1."Datum zaprimanja"] predao gume navedene u ovoj po' +
            'tvrdi na '#269'uvanje dru'#353'tvu Gume Zelina j.d.o.o.'
          'Gume se zaprimaju i '#269'uvaju prema uvjetima usluge '#269'uvanja guma.')
        ParentFont = False
        Formats = <
          item
          end
          item
          end>
      end
      object Line1: TfrxLineView
        AllowVectorExport = True
        Left = -3.779529900000000000
        Top = 377.953009620000000000
        Width = 759.685536660000000000
        Color = clBlack
        Frame.Typ = []
        Diagonal = True
      end
      object Memo5: TfrxMemoView
        AllowVectorExport = True
        Left = 3.779530050000000000
        Top = 396.850646970000000000
        Width = 166.299316440000000000
        Height = 18.897644040000000000
        ContentScaleOptions.Constraints.MaxIterationValue = 0
        ContentScaleOptions.Constraints.MinIterationValue = 0
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -15
        Font.Name = 'Arial'
        Font.Style = []
        Frame.Typ = []
        Memo.UTF8W = (
          'PODACI O KORISNIKU')
        ParentFont = False
      end
      object Memo6: TfrxMemoView
        AllowVectorExport = True
        Left = 37.795300000000000000
        Top = 434.645950000000000000
        Width = 98.267776440000000000
        Height = 18.897644040000000000
        ContentScaleOptions.Constraints.MaxIterationValue = 0
        ContentScaleOptions.Constraints.MinIterationValue = 0
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -15
        Font.Name = 'Arial'
        Font.Style = []
        Frame.Typ = []
        Memo.UTF8W = (
          'Ime i prezime:')
        ParentFont = False
      end
      object Memo7: TfrxMemoView
        AllowVectorExport = True
        Left = 37.795300000000000000
        Top = 468.661720000000000000
        Width = 98.267776440000000000
        Height = 18.897644040000000000
        ContentScaleOptions.Constraints.MaxIterationValue = 0
        ContentScaleOptions.Constraints.MinIterationValue = 0
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -15
        Font.Name = 'Arial'
        Font.Style = []
        Frame.Typ = []
        Memo.UTF8W = (
          'Broj mobitela:')
        ParentFont = False
      end
      object Memo8: TfrxMemoView
        AllowVectorExport = True
        Left = 37.795300000000000000
        Top = 510.236550000000000000
        Width = 128.504016440000000000
        Height = 18.897644040000000000
        ContentScaleOptions.Constraints.MaxIterationValue = 0
        ContentScaleOptions.Constraints.MinIterationValue = 0
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -15
        Font.Name = 'Arial'
        Font.Style = []
        Frame.Typ = []
        Memo.UTF8W = (
          'Datum zaprimanja:')
        ParentFont = False
      end
      object MemofrxUserDataSet1Vlasnik: TfrxMemoView
        IndexTag = 1
        AllowVectorExport = True
        Left = 136.063080000000000000
        Top = 434.645950000000000000
        Width = 188.976500000000000000
        Height = 18.897650000000000000
        ContentScaleOptions.Constraints.MaxIterationValue = 0
        ContentScaleOptions.Constraints.MinIterationValue = 0
        DataField = 'Vlasnik'
        DataSet = frxUserDataSet1
        DataSetName = 'frxUserDataSet1'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -15
        Font.Name = 'Arial'
        Font.Style = []
        Frame.Typ = []
        Memo.UTF8W = (
          '[frxUserDataSet1."Vlasnik"]')
        ParentFont = False
      end
      object MemofrxUserDataSet1Brojmobitela: TfrxMemoView
        IndexTag = 1
        AllowVectorExport = True
        Left = 136.063080000000000000
        Top = 468.661720000000000000
        Width = 226.771800000000000000
        Height = 18.897650000000000000
        ContentScaleOptions.Constraints.MaxIterationValue = 0
        ContentScaleOptions.Constraints.MinIterationValue = 0
        DataField = 'Broj mobitela'
        DataSet = frxUserDataSet1
        DataSetName = 'frxUserDataSet1'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -15
        Font.Name = 'Arial'
        Font.Style = []
        Frame.Typ = []
        Memo.UTF8W = (
          '[frxUserDataSet1."Broj mobitela"]')
        ParentFont = False
      end
      object MemofrxUserDataSet1Datumzaprimanja: TfrxMemoView
        IndexTag = 1
        AllowVectorExport = True
        Left = 166.299320000000000000
        Top = 510.236550000000000000
        Width = 260.787570000000000000
        Height = 18.897650000000000000
        ContentScaleOptions.Constraints.MaxIterationValue = 0
        ContentScaleOptions.Constraints.MinIterationValue = 0
        DataField = 'Datum zaprimanja'
        DataSet = frxUserDataSet1
        DataSetName = 'frxUserDataSet1'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -15
        Font.Name = 'Arial'
        Font.Style = []
        Frame.Typ = []
        Memo.UTF8W = (
          '[frxUserDataSet1."Datum zaprimanja"]')
        ParentFont = False
      end
      object Memo9: TfrxMemoView
        AllowVectorExport = True
        Top = 585.827150000000000000
        Width = 166.299316440000000000
        Height = 18.897644040000000000
        ContentScaleOptions.Constraints.MaxIterationValue = 0
        ContentScaleOptions.Constraints.MinIterationValue = 0
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -15
        Font.Name = 'Arial'
        Font.Style = []
        Frame.Typ = []
        Memo.UTF8W = (
          'PODACI O GUMAMA')
        ParentFont = False
      end
      object Memo10: TfrxMemoView
        AllowVectorExport = True
        Left = 37.795300000000000000
        Top = 623.622450000000000000
        Width = 117.165426440000000000
        Height = 18.897644040000000000
        ContentScaleOptions.Constraints.MaxIterationValue = 0
        ContentScaleOptions.Constraints.MinIterationValue = 0
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -15
        Font.Name = 'Arial'
        Font.Style = []
        Frame.Typ = []
        Memo.UTF8W = (
          'Marka/dimenzije:')
        ParentFont = False
      end
      object Memo11: TfrxMemoView
        AllowVectorExport = True
        Left = 37.795300000000000000
        Top = 661.417750000000000000
        Width = 64.252006440000000000
        Height = 18.897644040000000000
        ContentScaleOptions.Constraints.MaxIterationValue = 0
        ContentScaleOptions.Constraints.MinIterationValue = 0
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -15
        Font.Name = 'Arial'
        Font.Style = []
        Frame.Typ = []
        Memo.UTF8W = (
          'Lokacija:')
        ParentFont = False
      end
      object MemofrxUserDataSet1Markadimenzije: TfrxMemoView
        IndexTag = 1
        AllowVectorExport = True
        Left = 154.960730000000000000
        Top = 623.622450000000000000
        Width = 253.228510000000000000
        Height = 18.897650000000000000
        ContentScaleOptions.Constraints.MaxIterationValue = 0
        ContentScaleOptions.Constraints.MinIterationValue = 0
        DataField = 'Marka/dimenzije'
        DataSet = frxUserDataSet1
        DataSetName = 'frxUserDataSet1'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -15
        Font.Name = 'Arial'
        Font.Style = []
        Frame.Typ = []
        Memo.UTF8W = (
          '[frxUserDataSet1."Marka/dimenzije"]')
        ParentFont = False
      end
      object MemofrxUserDataSet1Lokacija: TfrxMemoView
        IndexTag = 1
        AllowVectorExport = True
        Left = 102.047310000000000000
        Top = 661.417750000000000000
        Width = 306.141930000000000000
        Height = 18.897650000000000000
        ContentScaleOptions.Constraints.MaxIterationValue = 0
        ContentScaleOptions.Constraints.MinIterationValue = 0
        DataField = 'Lokacija'
        DataSet = frxUserDataSet1
        DataSetName = 'frxUserDataSet1'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -15
        Font.Name = 'Arial'
        Font.Style = []
        Frame.Typ = []
        Memo.UTF8W = (
          '[frxUserDataSet1."Lokacija"]')
        ParentFont = False
      end
      object Memo12: TfrxMemoView
        AllowVectorExport = True
        Top = 737.008350000000000000
        Width = 170.078846440000000000
        Height = 18.897644040000000000
        ContentScaleOptions.Constraints.MaxIterationValue = 0
        ContentScaleOptions.Constraints.MinIterationValue = 0
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -15
        Font.Name = 'Arial'
        Font.Style = []
        Frame.Typ = []
        Memo.UTF8W = (
          'DODATNA NAPOMENA')
        ParentFont = False
      end
      object MemofrxUserDataSet1Napomena: TfrxMemoView
        IndexTag = 1
        AllowVectorExport = True
        Left = 37.795300000000000000
        Top = 774.803650000000000000
        Width = 642.520100000000000000
        Height = 37.795300000000000000
        ContentScaleOptions.Constraints.MaxIterationValue = 0
        ContentScaleOptions.Constraints.MinIterationValue = 0
        DataField = 'Napomena'
        DataSet = frxUserDataSet1
        DataSetName = 'frxUserDataSet1'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -15
        Font.Name = 'Arial'
        Font.Style = []
        Frame.Typ = []
        Memo.UTF8W = (
          '[frxUserDataSet1."Napomena"]')
        ParentFont = False
      end
      object Line2: TfrxLineView
        AllowVectorExport = True
        Left = -7.559059950000000000
        Top = 831.496582030000000000
        Width = 729.449318740000000000
        Color = clBlack
        Frame.Typ = []
        Diagonal = True
      end
      object Memo13: TfrxMemoView
        AllowVectorExport = True
        Left = -0.000000470000000000
        Top = 839.055641130000000000
        Width = 714.331174550000000000
        Height = 41.574824040000000000
        ContentScaleOptions.Constraints.MaxIterationValue = 0
        ContentScaleOptions.Constraints.MinIterationValue = 0
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -13
        Font.Name = 'Arial'
        Font.Style = []
        Frame.Typ = []
        HAlign = haCenter
        Memo.UTF8W = (
          
            'Korisnik svojim potpisom potvr'#273'uje da su podaci navedeni u ovoj ' +
            'potvrdi to'#269'ni te da je upoznat s uvjetima '#269'uvanja.'
          '***Jedan primjerak ostaje korisniku usluge***')
        ParentFont = False
      end
      object Line3: TfrxLineView
        AllowVectorExport = True
        Left = 37.795299530000000000
        Top = 982.677795410000000000
        Width = 188.976505280000000000
        Color = clBlack
        Frame.Typ = []
        Diagonal = True
      end
      object Line4: TfrxLineView
        AllowVectorExport = True
        Left = 680.315429690000000000
        Top = 982.677795410000000000
        Width = -188.976543000000000000
        Color = clBlack
        Frame.Typ = []
        Diagonal = True
      end
      object Memo14: TfrxMemoView
        AllowVectorExport = True
        Left = 37.795299530000000000
        Top = 994.016418460000000000
        Width = 188.976504550000000000
        Height = 18.897644040000000000
        ContentScaleOptions.Constraints.MaxIterationValue = 0
        ContentScaleOptions.Constraints.MinIterationValue = 0
        Frame.Typ = []
        HAlign = haCenter
        Memo.UTF8W = (
          'Potpis korisnika')
      end
      object Memo15: TfrxMemoView
        AllowVectorExport = True
        Left = 491.338900000000000000
        Top = 994.016390000000000000
        Width = 188.976504550000000000
        Height = 41.574824040000000000
        ContentScaleOptions.Constraints.MaxIterationValue = 0
        ContentScaleOptions.Constraints.MinIterationValue = 0
        Frame.Typ = []
        HAlign = haCenter
        Memo.UTF8W = (
          'Gume Zelina j.d.o.o.'
          '(ovla'#353'tena osoba)')
      end
    end
  end
  object frxUserDataSet1: TfrxUserDataSet
    UserName = 'frxUserDataSet1'
    OnCheckEOF = frxUserDataSet1CheckEOF
    OnFirst = frxUserDataSet1First
    OnNext = frxUserDataSet1Next
    Fields.Strings = (
      'Vlasnik'
      'Broj mobitela'
      'Marka/dimenzije'
      'Lokacija'
      'Napomena'
      'Datum zaprimanja')
    OnGetValue = frxUserDataSet1GetValue
    Left = 328
    Top = 416
  end
  object SimetricniCodec: TCodec
    AsymetricKeySizeInBits = 1024
    AdvancedOptions2 = []
    CryptoLibrary = CryptographicLibrary1
    Left = 608
    Top = 88
    StreamCipherId = 'native.StreamToBlock'
    BlockCipherId = 'native.AES-256'
    ChainId = 'native.CBC'
  end
  object CryptographicLibrary1: TCryptographicLibrary
    Left = 592
    Top = 152
  end
end
