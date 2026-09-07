object FIzradaCjenika: TFIzradaCjenika
  Left = 0
  Top = 0
  BorderIcons = [biSystemMenu]
  Caption = 'Izrada cjenika'
  ClientHeight = 500
  ClientWidth = 1043
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  Position = poMainFormCenter
  TextHeight = 15
  object LNaziv: TLabel
    Left = 661
    Top = 88
    Width = 53
    Height = 28
    Alignment = taRightJustify
    Caption = 'Naziv:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object LKategorija: TLabel
    Left = 620
    Top = 144
    Width = 94
    Height = 28
    Alignment = taRightJustify
    Caption = 'Kategorija:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object LCijena: TLabel
    Left = 657
    Top = 200
    Width = 57
    Height = 28
    Alignment = taRightJustify
    Caption = 'Cijena:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object Label4: TLabel
    Left = 642
    Top = 251
    Width = 72
    Height = 28
    Alignment = taRightJustify
    Caption = 'Aktivno:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object Lista: TListView
    Left = 8
    Top = 32
    Width = 513
    Height = 305
    Columns = <
      item
        Caption = 'Naziv'
        Width = 300
      end
      item
        Caption = 'Kategorija'
        Width = 100
      end
      item
        Caption = 'Cijena'
      end
      item
        Caption = 'Aktivno'
        Width = 60
      end>
    RowSelect = True
    TabOrder = 0
    ViewStyle = vsReport
    OnChange = ListaChange
  end
  object ENaziv: TEdit
    Left = 720
    Top = 80
    Width = 315
    Height = 36
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
  end
  object EKategorija: TEdit
    Left = 720
    Top = 136
    Width = 315
    Height = 36
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 2
  end
  object ECijena: TEdit
    Left = 720
    Top = 192
    Width = 315
    Height = 36
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 3
  end
  object ComboAktivno: TComboBox
    Tag = -1
    Left = 720
    Top = 248
    Width = 315
    Height = 36
    Style = csDropDownList
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 4
    Items.Strings = (
      'DA'
      'NE')
  end
  object BResetiraj: TButton
    Left = 883
    Top = 32
    Width = 152
    Height = 33
    Caption = 'Resetiraj polja'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 5
    OnClick = BResetirajClick
  end
  object BDodaj: TButton
    Left = 851
    Top = 304
    Width = 184
    Height = 33
    Caption = 'Dodaj u cjenik'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 6
    OnClick = BDodajClick
  end
  object BUpdate: TButton
    Left = 641
    Top = 304
    Width = 204
    Height = 33
    Caption = 'A'#382'uriraj stavku'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 7
    OnClick = BUpdateClick
  end
  object BObrisi: TButton
    Left = 527
    Top = 32
    Width = 210
    Height = 33
    Caption = 'Obri'#353'i odabranu stavku'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 8
    OnClick = BObrisiClick
  end
  object BIzvjesce: TButton
    Left = 8
    Top = 343
    Width = 242
    Height = 33
    Caption = 'Pokreni izvje'#353#263'e'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 9
    OnClick = BIzvjesceClick
  end
  object CBAktivno: TCheckBox
    Left = 256
    Top = 343
    Width = 265
    Height = 32
    Caption = 'Prika'#382'i samo aktivne stavke'
    Checked = True
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    State = cbChecked
    TabOrder = 10
    OnClick = CBAktivnoClick
  end
  object XMLDokument: TXMLDocument
    FileName = 
      'C:\Users\nikol\OneDrive\Desktop\Faks\4. semestar\Razvoj poslovni' +
      'h aplikacija\Gume Zelina Planer\cjenik.xml'
    Options = [doNodeAutoCreate, doNodeAutoIndent, doAttrNull, doAutoPrefix, doNamespaceDecl]
    Left = 240
    Top = 160
  end
  object frxReport1: TfrxReport
    Version = '2024.1.2'
    DotMatrixReport = False
    IniFile = '\Software\Fast Reports'
    PreviewOptions.Buttons = [pbPrint, pbLoad, pbSave, pbExport, pbZoom, pbFind, pbOutline, pbPageSetup, pbTools, pbEdit, pbNavigator, pbExportQuick, pbCopy, pbSelection, pbWatermarks]
    PreviewOptions.Zoom = 1.000000000000000000
    PrintOptions.Printer = 'Default'
    PrintOptions.PrintOnSheet = 0
    ReportOptions.CreateDate = 46245.799465173600000000
    ReportOptions.LastChange = 46246.284680208340000000
    ScriptLanguage = 'PascalScript'
    ScriptText.Strings = (
      'begin'
      ''
      'end.')
    Left = 48
    Top = 392
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
      object ReportTitle1: TfrxReportTitle
        FillType = ftBrush
        FillGap.Top = 0
        FillGap.Left = 0
        FillGap.Bottom = 0
        FillGap.Right = 0
        Frame.Typ = []
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -13
        Font.Name = 'Arial'
        Font.Style = []
        Height = 26.456710000000000000
        ParentFont = False
        Top = 18.897650000000000000
        Width = 718.110700000000000000
        object Memo1: TfrxMemoView
          AllowVectorExport = True
          Left = 3.779530050000000000
          Width = 714.331166440000000000
          Height = 41.574829770000000000
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
            'Gume zelina j.d.o.o. cjenik')
          ParentFont = False
        end
      end
      object MasterData1: TfrxMasterData
        FillType = ftBrush
        FillGap.Top = 0
        FillGap.Left = 0
        FillGap.Bottom = 0
        FillGap.Right = 0
        Frame.Typ = []
        Height = 34.015770000000000000
        Top = 151.181200000000000000
        Width = 718.110700000000000000
        DataSet = frxUserDataSet1
        DataSetName = 'frxUserDataSet1'
        RowCount = 0
        object MemofrxUserDataSet1Naziv: TfrxMemoView
          IndexTag = 1
          AllowVectorExport = True
          Left = 37.795300000000000000
          Width = 219.212740000000000000
          Height = 18.897650000000000000
          ContentScaleOptions.Constraints.MaxIterationValue = 0
          ContentScaleOptions.Constraints.MinIterationValue = 0
          DataField = 'Naziv'
          DataSet = frxUserDataSet1
          DataSetName = 'frxUserDataSet1'
          Frame.Typ = []
          Memo.UTF8W = (
            '[frxUserDataSet1."Naziv"]')
        end
        object MemofrxUserDataSet1Cijena: TfrxMemoView
          IndexTag = 1
          AllowVectorExport = True
          Left = 302.362400000000000000
          Top = 3.779530000000000000
          Width = 124.724490000000000000
          Height = 18.897650000000000000
          ContentScaleOptions.Constraints.MaxIterationValue = 0
          ContentScaleOptions.Constraints.MinIterationValue = 0
          DataField = 'Cijena'
          DataSet = frxUserDataSet1
          DataSetName = 'frxUserDataSet1'
          Frame.Typ = []
          Memo.UTF8W = (
            '[frxUserDataSet1."Cijena"]')
        end
        object Line1: TfrxLineView
          AllowVectorExport = True
          Top = 22.677183180000000000
          Width = 714.331176760000000000
          Color = clBlack
          Frame.Typ = []
          Diagonal = True
        end
        object MemofrxUserDataSet1Kategorija: TfrxMemoView
          IndexTag = 1
          AllowVectorExport = True
          Left = 604.724800000000000000
          Top = 3.779530000000000000
          Width = 147.401670000000000000
          Height = 18.897650000000000000
          ContentScaleOptions.Constraints.MaxIterationValue = 0
          ContentScaleOptions.Constraints.MinIterationValue = 0
          DataField = 'Kategorija'
          DataSet = frxUserDataSet1
          DataSetName = 'frxUserDataSet1'
          Frame.Typ = []
          Memo.UTF8W = (
            '[frxUserDataSet1."Kategorija"]')
        end
      end
      object PageHeader1: TfrxPageHeader
        FillType = ftBrush
        FillGap.Top = 0
        FillGap.Left = 0
        FillGap.Bottom = 0
        FillGap.Right = 0
        Frame.Typ = []
        Height = 22.677180000000000000
        Top = 68.031540000000000000
        Width = 718.110700000000000000
        object Memo2: TfrxMemoView
          AllowVectorExport = True
          Left = 37.795300050000000000
          Top = 3.779529920000000000
          Width = 75.590596440000000000
          Height = 18.897651670000000000
          ContentScaleOptions.Constraints.MaxIterationValue = 0
          ContentScaleOptions.Constraints.MinIterationValue = 0
          Frame.Typ = []
          Memo.UTF8W = (
            'Naziv')
        end
        object Memo4: TfrxMemoView
          AllowVectorExport = True
          Left = 306.141930000000000000
          Width = 75.590596440000000000
          Height = 18.897651670000000000
          ContentScaleOptions.Constraints.MaxIterationValue = 0
          ContentScaleOptions.Constraints.MinIterationValue = 0
          Frame.Typ = []
          Memo.UTF8W = (
            'Cijena')
        end
        object Memo3: TfrxMemoView
          AllowVectorExport = True
          Left = 604.724800000000000000
          Top = 3.779530000000000000
          Width = 75.590596440000000000
          Height = 18.897651670000000000
          ContentScaleOptions.Constraints.MaxIterationValue = 0
          ContentScaleOptions.Constraints.MinIterationValue = 0
          Frame.Typ = []
          Memo.UTF8W = (
            'Kategorija')
        end
      end
      object PageFooter1: TfrxPageFooter
        FillType = ftBrush
        FillGap.Top = 0
        FillGap.Left = 0
        FillGap.Bottom = 0
        FillGap.Right = 0
        Frame.Typ = []
        Height = 22.677180000000000000
        Top = 245.669450000000000000
        Width = 718.110700000000000000
      end
      object Memo6: TfrxMemoView
        AllowVectorExport = True
        Top = 1016.693570000000000000
        Width = 714.331166440000000000
        Height = 22.677179770000000000
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
          'Cjenik je prikazan u EUR s ura'#269'unatim PDV-om')
        ParentFont = False
      end
    end
  end
  object frxUserDataSet1: TfrxUserDataSet
    UserName = 'frxUserDataSet1'
    OnCheckEOF = frxUserDataSet1CheckEOF
    OnFirst = frxUserDataSet1First
    OnNext = frxUserDataSet1Next
    Fields.Strings = (
      'Naziv'
      'Kategorija'
      'Cijena'
      'Aktivno')
    OnGetValue = frxUserDataSet1GetValue
    Left = 160
    Top = 384
  end
  object siLangLinked_FIzradaCjenika: TsiLangLinked
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
    Left = 512
    Top = 256
    TranslationData = {
      73007400430061007000740069006F006E0073005F0055006E00690063006F00
      640065000D000A005400460049007A00720061006400610043006A0065006E00
      69006B006100010049007A007200610064006100200063006A0065006E006900
      6B00610001005000720069006300650020006C0069007300740020006D006100
      6B006500720001000D000A004C004E0061007A006900760001004E0061007A00
      690076003A000100430061007000740069006F006E003A0001000D000A004C00
      4B0061007400650067006F00720069006A00610001004B006100740065006700
      6F00720069006A0061003A000100430061007400650067006F00720079003A00
      01000D000A004C00430069006A0065006E0061000100430069006A0065006E00
      61003A000100500072006900630065003A0001000D000A004C00610062006500
      6C003400010041006B007400690076006E006F003A0001004100630074006900
      7600650001000D000A004200520065007300650074006900720061006A000100
      520065007300650074006900720061006A00200070006F006C006A0061000100
      5200650073006500740020006600690065006C006400730001000D000A004200
      44006F00640061006A00010044006F00640061006A0020007500200063006A00
      65006E0069006B000100410064006400200069006E0074006F00200070007200
      6900630065006C0069007300740001000D000A00420055007000640061007400
      6500010041007E01750072006900720061006A00200073007400610076006B00
      750001005500700064006100740065002000730065006C006500630074006500
      640020006900740065006D0001000D000A0042004F0062007200690073006900
      01004F006200720069006101690020006F00640061006200720061006E007500
      200073007400610076006B0075000100440065006C0065007400650020007300
      65006C006500630074006500640020006900740065006D0001000D000A004200
      49007A0076006A006500730063006500010050006F006B00720065006E006900
      200069007A0076006A0065006101070165000100470065006E00650072006100
      740065002000610020007000720069006300650020006C006900730074000100
      0D000A004300420041006B007400690076006E006F0001005000720069006B00
      61007E0169002000730061006D006F00200061006B007400690076006E006500
      200073007400610076006B0065000100530068006F00770020006F006E006C00
      7900200061006300740069007600650020006900740065006D00730001000D00
      0A0073007400480069006E00740073005F0055006E00690063006F0064006500
      0D000A007300740044006900730070006C00610079004C006100620065006C00
      73005F0055006E00690063006F00640065000D000A007300740046006F006E00
      740073005F0055006E00690063006F00640065000D000A005400460049007A00
      720061006400610043006A0065006E0069006B00610001005300650067006F00
      6500200055004900010001000D000A004C004E0061007A006900760001005300
      650067006F006500200055004900010001000D000A004C004B00610074006500
      67006F00720069006A00610001005300650067006F0065002000550049000100
      01000D000A004C00430069006A0065006E00610001005300650067006F006500
      200055004900010001000D000A004C006100620065006C003400010053006500
      67006F006500200055004900010001000D000A0045004E0061007A0069007600
      01005300650067006F006500200055004900010001000D000A0045004B006100
      7400650067006F00720069006A00610001005300650067006F00650020005500
      4900010001000D000A004500430069006A0065006E0061000100530065006700
      6F006500200055004900010001000D000A0043006F006D0062006F0041006B00
      7400690076006E006F0001005300650067006F00650020005500490001000100
      0D000A004200520065007300650074006900720061006A000100530065006700
      6F006500200055004900010001000D000A00420044006F00640061006A000100
      5300650067006F006500200055004900010001000D000A004200550070006400
      61007400650001005300650067006F006500200055004900010001000D000A00
      42004F006200720069007300690001005300650067006F006500200055004900
      010001000D000A00420049007A0076006A006500730063006500010053006500
      67006F006500200055004900010001000D000A004300420041006B0074006900
      76006E006F0001005300650067006F006500200055004900010001000D000A00
      730074004D0075006C00740069004C0069006E00650073005F0055006E006900
      63006F00640065000D000A0043006F006D0062006F0041006B00740069007600
      6E006F002E004900740065006D0073000100440041002C004E00450001005900
      450053002C004E004F0001000D000A006600720078005200650070006F007200
      740031002E005300630072006900700074005400650078007400010062006500
      670069006E002C002C0065006E0064002E00010001000D000A00660072007800
      5500730065007200440061007400610053006500740031002E00460069006500
      6C006400730001004E0061007A00690076002C004B0061007400650067006F00
      720069006A0061002C00430069006A0065006E0061002C0041006B0074006900
      76006E006F00010001000D000A007300740053007400720069006E0067007300
      5F0055006E00690063006F00640065000D000A005300560041005F0050004F00
      4C004A004100010055006E006500730069007400650020007300760061002000
      70006F006C006A0061002100010050006C006500610073006500200066006900
      6C006C00200061006C006C0020006600690065006C0064007300210001000D00
      0A00420052004900530041004E004A00450001004F0064006100620065007200
      690074006500200073007400610076006B00750020006B006F006A0075002000
      7E0165006C0069007400650020006F0062007200690073006100740069002100
      0100430068006F006F0073006500200061006E0020006900740065006D002000
      79006F0075002000770061006E007400200074006F002000640065006C006500
      74006500210001000D000A0055005200450010014900560041004E004A004500
      01004F0064006100620065007200690074006500200073007400610076006B00
      750020006B006F006A00750020007E0165006C00690074006500200075007200
      6500640069007400690021000100430068006F006F0073006500200061006E00
      20006900740065006D00200079006F0075002000770061006E00740020007400
      6F0020006500640069007400210001000D000A00730074004F00740068006500
      720053007400720069006E00670073005F0055006E00690063006F0064006500
      0D000A006600720078005200650070006F007200740031002E0049006E006900
      460069006C00650001005C0053006F006600740077006100720065005C004600
      61007300740020005200650070006F00720074007300010001000D000A006600
      720078005200650070006F007200740031002E00530063007200690070007400
      4C0061006E00670075006100670065000100500061007300630061006C005300
      63007200690070007400010001000D000A006600720078005500730065007200
      440061007400610053006500740031002E0055007300650072004E0061006D00
      6500010066007200780055007300650072004400610074006100530065007400
      3100010001000D000A007300740043006F006C006C0065006300740069006F00
      6E0073005F0055006E00690063006F00640065000D000A004C00690073007400
      61002E0043006F006C0075006D006E0073005B0030005D002E00430061007000
      740069006F006E0001004E0061007A0069007600010043006100700074006900
      6F006E0001000D000A004C0069007300740061002E0043006F006C0075006D00
      6E0073005B0031005D002E00430061007000740069006F006E0001004B006100
      7400650067006F00720069006A0061000100430061007400650067006F007200
      790001000D000A004C0069007300740061002E0043006F006C0075006D006E00
      73005B0032005D002E00430061007000740069006F006E000100430069006A00
      65006E00610001005000720069006300650001000D000A004C00690073007400
      61002E0043006F006C0075006D006E0073005B0033005D002E00430061007000
      740069006F006E00010041006B007400690076006E006F000100410063007400
      69007600650001000D000A007300740043006800610072005300650074007300
      5F0055006E00690063006F00640065000D000A005400460049007A0072006100
      6400610043006A0065006E0069006B0061000100440045004600410055004C00
      54005F0043004800410052005300450054000100440045004600410055004C00
      54005F00430048004100520053004500540001000D000A004C004E0061007A00
      690076000100440045004600410055004C0054005F0043004800410052005300
      450054000100440045004600410055004C0054005F0043004800410052005300
      4500540001000D000A004C004B0061007400650067006F00720069006A006100
      0100440045004600410055004C0054005F004300480041005200530045005400
      0100440045004600410055004C0054005F004300480041005200530045005400
      01000D000A004C00430069006A0065006E006100010044004500460041005500
      4C0054005F004300480041005200530045005400010044004500460041005500
      4C0054005F00430048004100520053004500540001000D000A004C0061006200
      65006C0034000100440045004600410055004C0054005F004300480041005200
      5300450054000100440045004600410055004C0054005F004300480041005200
      53004500540001000D000A0045004E0061007A00690076000100440045004600
      410055004C0054005F0043004800410052005300450054000100440045004600
      410055004C0054005F00430048004100520053004500540001000D000A004500
      4B0061007400650067006F00720069006A006100010044004500460041005500
      4C0054005F004300480041005200530045005400010044004500460041005500
      4C0054005F00430048004100520053004500540001000D000A00450043006900
      6A0065006E0061000100440045004600410055004C0054005F00430048004100
      52005300450054000100440045004600410055004C0054005F00430048004100
      520053004500540001000D000A0043006F006D0062006F0041006B0074006900
      76006E006F000100440045004600410055004C0054005F004300480041005200
      5300450054000100440045004600410055004C0054005F004300480041005200
      53004500540001000D000A004200520065007300650074006900720061006A00
      0100440045004600410055004C0054005F004300480041005200530045005400
      0100440045004600410055004C0054005F004300480041005200530045005400
      01000D000A00420044006F00640061006A000100440045004600410055004C00
      54005F0043004800410052005300450054000100440045004600410055004C00
      54005F00430048004100520053004500540001000D000A004200550070006400
      6100740065000100440045004600410055004C0054005F004300480041005200
      5300450054000100440045004600410055004C0054005F004300480041005200
      53004500540001000D000A0042004F0062007200690073006900010044004500
      4600410055004C0054005F004300480041005200530045005400010044004500
      4600410055004C0054005F00430048004100520053004500540001000D000A00
      420049007A0076006A0065007300630065000100440045004600410055004C00
      54005F0043004800410052005300450054000100440045004600410055004C00
      54005F00430048004100520053004500540001000D000A004300420041006B00
      7400690076006E006F000100440045004600410055004C0054005F0043004800
      410052005300450054000100440045004600410055004C0054005F0043004800
      4100520053004500540001000D000A00}
  end
end
