object FUpravljanjeCrnomListom: TFUpravljanjeCrnomListom
  Left = 0
  Top = 0
  BorderIcons = [biSystemMenu]
  Caption = 'Upravljanje crnom listom'
  ClientHeight = 490
  ClientWidth = 970
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -17
  Font.Name = 'Segoe UI'
  Font.Style = []
  Position = poMainFormCenter
  TextHeight = 23
  object LSoritraj: TLabel
    Left = 823
    Top = 125
    Width = 129
    Height = 28
    Caption = 'Sortiraj silazno'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object DBGTablica: TDBGrid
    Left = 8
    Top = 9
    Width = 729
    Height = 185
    DataSource = DSCrnaLista
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -12
    TitleFont.Name = 'Segoe UI'
    TitleFont.Style = []
    Columns = <
      item
        Expanded = False
        FieldName = 'ID'
        Width = 100
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'termin_id'
        Width = 100
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'razlog'
        Width = 100
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'datum'
        Width = 100
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'TerminRegistracija'
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Dana na crnoj listi'
        Visible = True
      end>
  end
  object DBNav: TDBNavigator
    Left = 8
    Top = 287
    Width = 440
    Height = 25
    DataSource = DSCrnaLista
    TabOrder = 1
  end
  object DBGTablica1: TDBGrid
    Left = 8
    Top = 200
    Width = 441
    Height = 81
    DataSource = DSTermini
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 2
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -12
    TitleFont.Name = 'Segoe UI'
    TitleFont.Style = []
    Columns = <
      item
        Expanded = False
        FieldName = 'ID'
        Width = 70
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'datum'
        Width = 70
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'registracija'
        Width = 70
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'korisnik_id'
        Width = 70
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'vrijeme'
        Width = 70
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'opis'
        Width = 70
        Visible = True
      end>
  end
  object BSortiraj: TButton
    Left = 799
    Top = 159
    Width = 163
    Height = 35
    Caption = 'Sortiraj'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 3
    OnClick = BSortirajClick
  end
  object RBid: TRadioButton
    Left = 799
    Top = 8
    Width = 122
    Height = 22
    Caption = 'ID'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 4
  end
  object RBtermin_id: TRadioButton
    Left = 799
    Top = 36
    Width = 122
    Height = 31
    Caption = 'termin_id'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 5
  end
  object RBrazlog: TRadioButton
    Left = 799
    Top = 68
    Width = 130
    Height = 26
    Caption = 'razlog'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 6
  end
  object RBdatum: TRadioButton
    Left = 799
    Top = 100
    Width = 130
    Height = 23
    Caption = 'datum'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 7
  end
  object CBSilazno: TCheckBox
    Left = 799
    Top = 136
    Width = 25
    Height = 17
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 8
  end
  object FilterPanel: TPanel
    Left = 455
    Top = 200
    Width = 507
    Height = 282
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -17
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 9
    object Lid: TLabel
      Left = 109
      Top = 27
      Width = 21
      Height = 23
      Alignment = taRightJustify
      Caption = 'ID:'
    end
    object Ltermin_id: TLabel
      Left = 55
      Top = 69
      Width = 75
      Height = 23
      Alignment = taRightJustify
      Caption = 'termin_id:'
    end
    object Lrazlog: TLabel
      Left = 75
      Top = 98
      Width = 55
      Height = 23
      Alignment = taRightJustify
      Caption = 'Razlog:'
    end
    object LOd: TLabel
      Left = 103
      Top = 143
      Width = 27
      Height = 23
      Alignment = taRightJustify
      Caption = 'Od:'
    end
    object LDo: TLabel
      Left = 104
      Top = 172
      Width = 26
      Height = 23
      Alignment = taRightJustify
      Caption = 'Do:'
    end
    object Eid: TEdit
      Left = 136
      Top = 24
      Width = 369
      Height = 31
      TabOrder = 0
      OnChange = EidChange
    end
    object Erazlog: TEdit
      Left = 136
      Top = 98
      Width = 369
      Height = 31
      TabOrder = 2
      OnChange = ErazlogChange
    end
    object Etermin_id: TEdit
      Left = 136
      Top = 61
      Width = 369
      Height = 31
      TabOrder = 1
      OnChange = Etermin_idChange
    end
    object DTPOd: TDateTimePicker
      Left = 136
      Top = 135
      Width = 369
      Height = 31
      Date = 46211.000000000000000000
      Time = 0.813737268515978900
      TabOrder = 3
      OnChange = DTPOdChange
    end
    object DTPDo: TDateTimePicker
      Left = 136
      Top = 172
      Width = 369
      Height = 31
      Date = 46211.000000000000000000
      Time = 0.814080567128257800
      TabOrder = 4
      OnChange = DTPDoChange
    end
    object BPonistiFiltere: TButton
      Left = 8
      Top = 242
      Width = 489
      Height = 31
      Caption = 'Poni'#353'ti filtere'
      TabOrder = 5
      OnClick = BPonistiFiltereClick
    end
  end
  object BIzvjesce: TButton
    Left = 8
    Top = 318
    Width = 217
    Height = 35
    Caption = 'Pokreni izvje'#353#263'e crne liste'
    TabOrder = 10
    OnClick = BIzvjesceClick
  end
  object ADOTCrnaLista: TADOTable
    Active = True
    Connection = FPrijava.ADOConnection1
    CursorType = ctStatic
    OnCalcFields = ADOTCrnaListaCalcFields
    IndexFieldNames = 'termin_id'
    TableName = 'crna_lista'
    Left = 88
    Top = 40
    object ADOTCrnaListaID: TAutoIncField
      FieldName = 'ID'
      ReadOnly = True
    end
    object ADOTCrnaListatermin_id: TIntegerField
      FieldName = 'termin_id'
    end
    object ADOTCrnaListarazlog: TWideStringField
      FieldName = 'razlog'
      Size = 255
    end
    object ADOTCrnaListadatum: TDateTimeField
      FieldName = 'datum'
    end
    object ADOTCrnaListaTerminRegistracija: TStringField
      FieldKind = fkLookup
      FieldName = 'TerminRegistracija'
      LookupDataSet = ADOTTermini
      LookupKeyFields = 'ID'
      LookupResultField = 'registracija'
      KeyFields = 'termin_id'
      Lookup = True
    end
    object ADOTCrnaListaDananacrnojlisti: TIntegerField
      Alignment = taLeftJustify
      FieldKind = fkCalculated
      FieldName = 'Dana na crnoj listi'
      Calculated = True
    end
  end
  object DSCrnaLista: TDataSource
    DataSet = ADOTCrnaLista
    Left = 88
    Top = 104
  end
  object ADOTTermini: TADOTable
    Active = True
    Connection = FPrijava.ADOConnection1
    CursorType = ctStatic
    IndexFieldNames = 'ID'
    MasterFields = 'termin_id'
    MasterSource = DSCrnaLista
    TableName = 'termini'
    Left = 136
    Top = 232
    object ADOTTerminiID: TAutoIncField
      FieldName = 'ID'
      ReadOnly = True
    end
    object ADOTTerminidatum: TDateTimeField
      FieldName = 'datum'
    end
    object ADOTTerminiregistracija: TWideStringField
      FieldName = 'registracija'
      Size = 255
    end
    object ADOTTerminikorisnik_id: TIntegerField
      FieldName = 'korisnik_id'
    end
    object ADOTTerminivrijeme: TWideStringField
      FieldName = 'vrijeme'
      Size = 255
    end
    object ADOTTerminiopis: TWideStringField
      FieldName = 'opis'
      Size = 255
    end
  end
  object DSTermini: TDataSource
    DataSet = ADOTTermini
    Left = 64
    Top = 232
  end
  object ADOQuery1: TADOQuery
    Connection = FPrijava.ADOConnection1
    Parameters = <>
    Left = 928
    Top = 16
  end
  object siLangLinked_FUpravljanjeCrnomListom: TsiLangLinked
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
    Left = 632
    Top = 160
    TranslationData = {
      73007400430061007000740069006F006E0073005F0055006E00690063006F00
      640065000D000A0054004600550070007200610076006C006A0061006E006A00
      6500430072006E006F006D004C006900730074006F006D000100550070007200
      610076006C006A0061006E006A0065002000630072006E006F006D0020006C00
      6900730074006F006D00010042006C00610063006B0020006C00690073007400
      20006D0061006E00610067006500720001000D000A004C0053006F0072006900
      7400720061006A00010053006F00720074006900720061006A00200073006900
      6C0061007A006E006F000100440065007300630065006E00640069006E006700
      01000D000A00420053006F00720074006900720061006A00010053006F007200
      74006900720061006A00010053006F007200740001000D000A00520042006900
      640001004900440001004900440001000D000A00520042007400650072006D00
      69006E005F006900640001007400650072006D0069006E005F00690064000100
      6100700070006F0069006E0074006D0065006E0074005F006900640001000D00
      0A0052004200720061007A006C006F0067000100720061007A006C006F006700
      010072006500610073006F006E0001000D000A00520042006400610074007500
      6D00010064006100740075006D000100640061007400650001000D000A004C00
      690064000100490044003A000100490044003A00200001000D000A004C007400
      650072006D0069006E005F006900640001007400650072006D0069006E005F00
      690064003A0001006100700070006F0069006E0074006D0065006E0074005F00
      690064003A00200001000D000A004C00720061007A006C006F00670001005200
      61007A006C006F0067003A00010052006500610073006F006E003A0020000100
      0D000A004C004F00640001004F0064003A000100460072006F006D003A002000
      01000D000A004C0044006F00010044006F003A00010054006F003A0020000100
      0D000A00420050006F006E006900730074006900460069006C00740065007200
      6500010050006F006E0069006101740069002000660069006C00740065007200
      65000100520065007300650074002000660069006C0074006500720073000100
      0D000A00420049007A0076006A006500730063006500010050006F006B007200
      65006E006900200069007A0076006A0065006101070165002000630072006E00
      650020006C0069007300740065000100470065006E0065007200610074006500
      20006100200062006C00610063006B0020006C00690073007400200072006500
      70006F007200740001000D000A0073007400480069006E00740073005F005500
      6E00690063006F00640065000D000A007300740044006900730070006C006100
      79004C006100620065006C0073005F0055006E00690063006F00640065000D00
      0A00410044004F005400430072006E0061004C00690073007400610049004400
      01004900440001004900440001000D000A00410044004F005400430072006E00
      61004C0069007300740061007400650072006D0069006E005F00690064000100
      7400650072006D0069006E005F006900640001006100700070006F0069006E00
      74006D0065006E0074005F006900640001000D000A00410044004F0054004300
      72006E0061004C006900730074006100720061007A006C006F00670001007200
      61007A006C006F006700010072006500610073006F006E0001000D000A004100
      44004F005400430072006E0061004C0069007300740061006400610074007500
      6D00010064006100740075006D000100640061007400650001000D000A004100
      44004F005400430072006E0061004C0069007300740061005400650072006D00
      69006E0052006500670069007300740072006100630069006A00610001005400
      650072006D0069006E0052006500670069007300740072006100630069006A00
      610001004100700070006F0069006E0074006D0065006E007400520065006700
      01000D000A00410044004F005400430072006E0061004C006900730074006100
      440061006E0061006E006100630072006E006F006A006C006900730074006900
      0100440061006E00610020006E0061002000630072006E006F006A0020006C00
      690073007400690001004400610079007300200062006C00610063006B006C00
      6900730074006500640001000D000A00410044004F0054005400650072006D00
      69006E0069004900440001004900440001004900440001000D000A0041004400
      4F0054005400650072006D0069006E00690064006100740075006D0001006400
      6100740075006D000100640061007400650001000D000A00410044004F005400
      5400650072006D0069006E006900720065006700690073007400720061006300
      69006A006100010072006500670069007300740072006100630069006A006100
      010072006500670069007300740072006100740069006F006E0001000D000A00
      410044004F0054005400650072006D0069006E0069006B006F00720069007300
      6E0069006B005F006900640001006B006F007200690073006E0069006B005F00
      69006400010075007300650072005F006900640001000D000A00410044004F00
      54005400650072006D0069006E0069007600720069006A0065006D0065000100
      7600720069006A0065006D0065000100740069006D00650001000D000A004100
      44004F0054005400650072006D0069006E0069006F0070006900730001006F00
      70006900730001006400650073006300720069007000740069006F006E000100
      0D000A007300740046006F006E00740073005F0055006E00690063006F006400
      65000D000A0054004600550070007200610076006C006A0061006E006A006500
      430072006E006F006D004C006900730074006F006D0001005300650067006F00
      650020005500490001005300650067006F00650020005500490001000D000A00
      4C0053006F00720069007400720061006A0001005300650067006F0065002000
      55004900010001000D000A004400420047005400610062006C00690063006100
      01005300650067006F006500200055004900010001000D000A00440042004700
      5400610062006C00690063006100310001005300650067006F00650020005500
      4900010001000D000A00420053006F00720074006900720061006A0001005300
      650067006F006500200055004900010001000D000A0052004200690064000100
      5300650067006F006500200055004900010001000D000A005200420074006500
      72006D0069006E005F006900640001005300650067006F006500200055004900
      010001000D000A0052004200720061007A006C006F0067000100530065006700
      6F006500200055004900010001000D000A005200420064006100740075006D00
      01005300650067006F006500200055004900010001000D000A00430042005300
      69006C0061007A006E006F0001005300650067006F0065002000550049000100
      01000D000A00460069006C00740065007200500061006E0065006C0001005300
      650067006F006500200055004900010001000D000A00730074004D0075006C00
      740069004C0069006E00650073005F0055006E00690063006F00640065000D00
      0A00440042004E00610076002E00480069006E00740073000100220046006900
      72007300740020007200650063006F007200640022002C002200500072006900
      6F00720020007200650063006F007200640022002C0022004E00650078007400
      20007200650063006F007200640022002C0022004C0061007300740020007200
      650063006F007200640022002C00220049006E00730065007200740020007200
      650063006F007200640022002C002200440065006C0065007400650020007200
      650063006F007200640022002C00220045006400690074002000720065006300
      6F007200640022002C00220050006F0073007400200065006400690074002200
      2C002200430061006E00630065006C002000650064006900740022002C002200
      52006500660072006500730068002000640061007400610022002C0022004100
      700070006C0079002000750070006400610074006500730022002C0022004300
      61006E00630065006C0020007500700064006100740065007300220001000100
      0D000A006600720078005200650070006F007200740031002E00530063007200
      6900700074005400650078007400010062006500670069006E002C002C006500
      6E0064002E00010001000D000A007300740053007400720069006E0067007300
      5F0055006E00690063006F00640065000D000A00730074004F00740068006500
      720053007400720069006E00670073005F0055006E00690063006F0064006500
      0D000A00410044004F0054005400650072006D0069006E0069002E0049006E00
      6400650078004600690065006C0064004E0061006D0065007300010049004400
      01004900440001000D000A00410044004F005400430072006E0061004C006900
      7300740061002E0049006E006400650078004600690065006C0064004E006100
      6D006500730001007400650072006D0069006E005F0069006400010001000D00
      0A006600720078005200650070006F007200740031002E0049006E0069004600
      69006C00650001005C0053006F006600740077006100720065005C0046006100
      7300740020005200650070006F00720074007300010001000D000A0066007200
      78005200650070006F007200740031002E005300630072006900700074004C00
      61006E00670075006100670065000100500061007300630061006C0053006300
      7200690070007400010001000D000A0066007200780044004200440061007400
      6100730065007400430072006E0061004C0069007300740061002E0055007300
      650072004E0061006D0065000100660072007800440042004400610074006100
      730065007400430072006E0061004C006900730074006100010001000D000A00
      6600720078004400420044006100740061007300650074005400650072006D00
      69006E0069002E0055007300650072004E0061006D0065000100660072007800
      4400420044006100740061007300650074005400650072006D0069006E006900
      010001000D000A007300740043006F006C006C0065006300740069006F006E00
      73005F0055006E00690063006F00640065000D000A0044004200470054006100
      62006C006900630061002E0043006F006C0075006D006E0073005B0030005D00
      2E005400690074006C0065002E00430061007000740069006F006E0001004900
      440001004900440001000D000A004400420047005400610062006C0069006300
      61002E0043006F006C0075006D006E0073005B0031005D002E00540069007400
      6C0065002E00430061007000740069006F006E0001007400650072006D006900
      6E005F006900640001006100700070006F0069006E0074006D0065006E007400
      5F006900640001000D000A004400420047005400610062006C00690063006100
      2E0043006F006C0075006D006E0073005B0032005D002E005400690074006C00
      65002E00430061007000740069006F006E000100720061007A006C006F006700
      010072006500610073006F006E0001000D000A00440042004700540061006200
      6C006900630061002E0043006F006C0075006D006E0073005B0033005D002E00
      5400690074006C0065002E00430061007000740069006F006E00010064006100
      740075006D000100640061007400650001000D000A0044004200470054006100
      62006C006900630061002E0043006F006C0075006D006E0073005B0034005D00
      2E005400690074006C0065002E00430061007000740069006F006E0001005400
      650072006D0069006E0052006500670069007300740072006100630069006A00
      610001004100700070006F0069006E0074006D0065006E007400520065006700
      01000D000A004400420047005400610062006C006900630061002E0043006F00
      6C0075006D006E0073005B0035005D002E005400690074006C0065002E004300
      61007000740069006F006E000100440061006E00610020006E00610020006300
      72006E006F006A0020006C006900730074006900010044006100790073002000
      62006C00610063006B006C006900730074006500640001000D000A0044004200
      47005400610062006C0069006300610031002E0043006F006C0075006D006E00
      73005B0030005D002E005400690074006C0065002E0043006100700074006900
      6F006E0001004900440001004900440001000D000A0044004200470054006100
      62006C0069006300610031002E0043006F006C0075006D006E0073005B003100
      5D002E005400690074006C0065002E00430061007000740069006F006E000100
      64006100740075006D000100640061007400650001000D000A00440042004700
      5400610062006C0069006300610031002E0043006F006C0075006D006E007300
      5B0032005D002E005400690074006C0065002E00430061007000740069006F00
      6E00010072006500670069007300740072006100630069006A00610001007200
      6500670069007300740072006100740069006F006E0001000D000A0044004200
      47005400610062006C0069006300610031002E0043006F006C0075006D006E00
      73005B0033005D002E005400690074006C0065002E0043006100700074006900
      6F006E0001006B006F007200690073006E0069006B005F006900640001007500
      7300650072005F006900640001000D000A004400420047005400610062006C00
      69006300610031002E0043006F006C0075006D006E0073005B0034005D002E00
      5400690074006C0065002E00430061007000740069006F006E00010076007200
      69006A0065006D0065000100740069006D00650001000D000A00440042004700
      5400610062006C0069006300610031002E0043006F006C0075006D006E007300
      5B0035005D002E005400690074006C0065002E00430061007000740069006F00
      6E0001006F007000690073000100640065007300630072006900700074006900
      6F006E0001000D000A0073007400430068006100720053006500740073005F00
      55006E00690063006F00640065000D000A005400460055007000720061007600
      6C006A0061006E006A006500430072006E006F006D004C006900730074006F00
      6D000100440045004600410055004C0054005F00430048004100520053004500
      54000100440045004600410055004C0054005F00430048004100520053004500
      540001000D000A004C0053006F00720069007400720061006A00010044004500
      4600410055004C0054005F004300480041005200530045005400010044004500
      4600410055004C0054005F00430048004100520053004500540001000D000A00
      4400420047005400610062006C00690063006100010044004500460041005500
      4C0054005F004300480041005200530045005400010044004500460041005500
      4C0054005F00430048004100520053004500540001000D000A00440042004700
      5400610062006C0069006300610031000100440045004600410055004C005400
      5F0043004800410052005300450054000100440045004600410055004C005400
      5F00430048004100520053004500540001000D000A00420053006F0072007400
      6900720061006A000100440045004600410055004C0054005F00430048004100
      52005300450054000100440045004600410055004C0054005F00430048004100
      520053004500540001000D000A00520042006900640001004400450046004100
      55004C0054005F00430048004100520053004500540001004400450046004100
      55004C0054005F00430048004100520053004500540001000D000A0052004200
      7400650072006D0069006E005F00690064000100440045004600410055004C00
      54005F0043004800410052005300450054000100440045004600410055004C00
      54005F00430048004100520053004500540001000D000A005200420072006100
      7A006C006F0067000100440045004600410055004C0054005F00430048004100
      52005300450054000100440045004600410055004C0054005F00430048004100
      520053004500540001000D000A005200420064006100740075006D0001004400
      45004600410055004C0054005F00430048004100520053004500540001004400
      45004600410055004C0054005F00430048004100520053004500540001000D00
      0A0043004200530069006C0061007A006E006F00010044004500460041005500
      4C0054005F004300480041005200530045005400010044004500460041005500
      4C0054005F00430048004100520053004500540001000D000A00460069006C00
      740065007200500061006E0065006C000100440045004600410055004C005400
      5F0043004800410052005300450054000100440045004600410055004C005400
      5F00430048004100520053004500540001000D000A00}
  end
  object frxReport1: TfrxReport
    Version = '2024.1.2'
    DotMatrixReport = False
    IniFile = '\Software\Fast Reports'
    PreviewOptions.Buttons = [pbPrint, pbLoad, pbSave, pbExport, pbZoom, pbFind, pbOutline, pbPageSetup, pbTools, pbEdit, pbNavigator, pbExportQuick, pbCopy, pbSelection, pbWatermarks]
    PreviewOptions.Zoom = 1.000000000000000000
    PrintOptions.Printer = 'Default'
    PrintOptions.PrintOnSheet = 0
    ReportOptions.CreateDate = 46245.863491307900000000
    ReportOptions.LastChange = 46266.848761041660000000
    ScriptLanguage = 'PascalScript'
    ScriptText.Strings = (
      'begin'
      ''
      'end.')
    Left = 112
    Top = 368
    Datasets = <
      item
        DataSet = frxDBDatasetCrnaLista
        DataSetName = 'frxDBDatasetCrnaLista'
      end
      item
        DataSet = frxDBDatasetTermini
        DataSetName = 'frxDBDatasetTermini'
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
        Height = 41.574829110000000000
        Top = 18.897650000000000000
        Width = 718.110700000000000000
        object Memo1: TfrxMemoView
          AllowVectorExport = True
          Width = 548.031850730000000000
          Height = 34.015769770000000000
          ContentScaleOptions.Constraints.MaxIterationValue = 0
          ContentScaleOptions.Constraints.MinIterationValue = 0
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -21
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = []
          HAlign = haCenter
          Memo.UTF8W = (
            'Izvje'#353#263'e crne liste')
          ParentFont = False
        end
        object MemoDate: TfrxMemoView
          IndexTag = 1
          AllowVectorExport = True
          Left = 548.031850000000000000
          Top = 0.000000660000000000
          Width = 79.370130000000000000
          Height = 18.897650000000000000
          ContentScaleOptions.Constraints.MaxIterationValue = 0
          ContentScaleOptions.Constraints.MinIterationValue = 0
          Frame.Typ = []
          Memo.UTF8W = (
            '[Date]')
        end
        object MemoTime: TfrxMemoView
          IndexTag = 1
          AllowVectorExport = True
          Left = 627.401980000000000000
          Top = 0.000000660000000000
          Width = 79.370130000000000000
          Height = 18.897650000000000000
          ContentScaleOptions.Constraints.MaxIterationValue = 0
          ContentScaleOptions.Constraints.MinIterationValue = 0
          Frame.Typ = []
          Memo.UTF8W = (
            '[Time]')
        end
      end
      object MasterData1: TfrxMasterData
        FillType = ftBrush
        FillGap.Top = 0
        FillGap.Left = 0
        FillGap.Bottom = 0
        FillGap.Right = 0
        Frame.Typ = []
        Height = 71.811071670000000000
        Top = 120.944960000000000000
        Width = 718.110700000000000000
        DataSet = frxDBDatasetCrnaLista
        DataSetName = 'frxDBDatasetCrnaLista'
        KeepTogether = True
        RowCount = 0
        object Memo2: TfrxMemoView
          AllowVectorExport = True
          Top = 30.236238160000000000
          Width = 113.385900730000000000
          Height = 18.897651670000000000
          ContentScaleOptions.Constraints.MaxIterationValue = 0
          ContentScaleOptions.Constraints.MinIterationValue = 0
          Frame.Typ = []
          Memo.UTF8W = (
            'Razlog crne liste:')
        end
        object MemofrxDBDatasetCrnaListarazlog: TfrxMemoView
          IndexTag = 1
          AllowVectorExport = True
          Left = 105.826840000000000000
          Top = 30.236240000000000000
          Width = 400.630180000000000000
          Height = 18.897650000000000000
          ContentScaleOptions.Constraints.MaxIterationValue = 0
          ContentScaleOptions.Constraints.MinIterationValue = 0
          DataField = 'razlog'
          DataSet = frxDBDatasetCrnaLista
          DataSetName = 'frxDBDatasetCrnaLista'
          Frame.Typ = []
          Memo.UTF8W = (
            '[frxDBDatasetCrnaLista."razlog"]')
        end
        object Memo3: TfrxMemoView
          AllowVectorExport = True
          Top = 49.133890000000000000
          Width = 192.756030730000000000
          Height = 18.897651670000000000
          ContentScaleOptions.Constraints.MaxIterationValue = 0
          ContentScaleOptions.Constraints.MinIterationValue = 0
          Frame.Typ = []
          Memo.UTF8W = (
            'Datum dodavanja na crnu listu:')
        end
        object MemofrxDBDatasetCrnaListadatum: TfrxMemoView
          IndexTag = 1
          AllowVectorExport = True
          Left = 185.196970000000000000
          Top = 49.133890000000000000
          Width = 79.370130000000000000
          Height = 18.897650000000000000
          ContentScaleOptions.Constraints.MaxIterationValue = 0
          ContentScaleOptions.Constraints.MinIterationValue = 0
          DataField = 'datum'
          DataSet = frxDBDatasetCrnaLista
          DataSetName = 'frxDBDatasetCrnaLista'
          Frame.Typ = []
          Memo.UTF8W = (
            '[frxDBDatasetCrnaLista."datum"]')
        end
        object MemofrxDBDatasetCrnaListaTerminRegistracija: TfrxMemoView
          IndexTag = 1
          AllowVectorExport = True
          Left = -3.779530000000000000
          Top = 3.779530000000000000
          Width = 396.850650000000000000
          Height = 18.897650000000000000
          ContentScaleOptions.Constraints.MaxIterationValue = 0
          ContentScaleOptions.Constraints.MinIterationValue = 0
          DataField = 'TerminRegistracija'
          DataSet = frxDBDatasetCrnaLista
          DataSetName = 'frxDBDatasetCrnaLista'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -19
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = []
          Memo.UTF8W = (
            '[frxDBDatasetCrnaLista."TerminRegistracija"]')
          ParentFont = False
        end
      end
      object DetailData1: TfrxDetailData
        FillType = ftBrush
        FillGap.Top = 0
        FillGap.Left = 0
        FillGap.Bottom = 0
        FillGap.Right = 0
        Frame.Typ = []
        Height = 75.590609300000000000
        Top = 215.433210000000000000
        Width = 718.110700000000000000
        DataSet = frxDBDatasetTermini
        DataSetName = 'frxDBDatasetTermini'
        KeepTogether = True
        RowCount = 0
        object Memo4: TfrxMemoView
          AllowVectorExport = True
          Left = 68.031540000000000000
          Top = 3.779522980000000000
          Width = 98.267780730000000000
          Height = 18.897659300000000000
          ContentScaleOptions.Constraints.MaxIterationValue = 0
          ContentScaleOptions.Constraints.MinIterationValue = 0
          Frame.Typ = []
          Memo.UTF8W = (
            'Datum termina:')
        end
        object MemofrxDBDatasetTerminidatum: TfrxMemoView
          IndexTag = 1
          AllowVectorExport = True
          Left = 162.519790000000000000
          Top = 3.779530000000000000
          Width = 79.370130000000000000
          Height = 18.897650000000000000
          ContentScaleOptions.Constraints.MaxIterationValue = 0
          ContentScaleOptions.Constraints.MinIterationValue = 0
          DataField = 'datum'
          DataSet = frxDBDatasetTermini
          DataSetName = 'frxDBDatasetTermini'
          Frame.Typ = []
          Memo.UTF8W = (
            '[frxDBDatasetTermini."datum"]')
        end
        object Line1: TfrxLineView
          AllowVectorExport = True
          Left = 11.338590050000000000
          Top = 68.031544810000000000
          Width = 710.551646710000000000
          Color = clBlack
          Frame.Typ = []
          Diagonal = True
        end
        object MemofrxDBDatasetTerminivrijeme: TfrxMemoView
          IndexTag = 1
          AllowVectorExport = True
          Left = 166.299320000000000000
          Top = 26.456710000000000000
          Width = 400.630180000000000000
          Height = 18.897650000000000000
          ContentScaleOptions.Constraints.MaxIterationValue = 0
          ContentScaleOptions.Constraints.MinIterationValue = 0
          DataField = 'vrijeme'
          DataSet = frxDBDatasetTermini
          DataSetName = 'frxDBDatasetTermini'
          Frame.Typ = []
          Memo.UTF8W = (
            '[frxDBDatasetTermini."vrijeme"]')
        end
        object Memo5: TfrxMemoView
          AllowVectorExport = True
          Left = 68.031540000000000000
          Top = 26.456710000000000000
          Width = 105.826840730000000000
          Height = 18.897659300000000000
          ContentScaleOptions.Constraints.MaxIterationValue = 0
          ContentScaleOptions.Constraints.MinIterationValue = 0
          Frame.Typ = []
          Memo.UTF8W = (
            'Vrijeme termina:')
        end
        object Memo6: TfrxMemoView
          AllowVectorExport = True
          Left = 68.031540000000000000
          Top = 49.133890000000000000
          Width = 83.149660730000000000
          Height = 18.897659300000000000
          ContentScaleOptions.Constraints.MaxIterationValue = 0
          ContentScaleOptions.Constraints.MinIterationValue = 0
          Frame.Typ = []
          Memo.UTF8W = (
            'Opis termina:')
        end
        object MemofrxDBDatasetTerminiopis: TfrxMemoView
          IndexTag = 1
          AllowVectorExport = True
          Left = 154.960730000000000000
          Top = 49.133890000000000000
          Width = 400.630180000000000000
          Height = 18.897650000000000000
          ContentScaleOptions.Constraints.MaxIterationValue = 0
          ContentScaleOptions.Constraints.MinIterationValue = 0
          DataField = 'opis'
          DataSet = frxDBDatasetTermini
          DataSetName = 'frxDBDatasetTermini'
          Frame.Typ = []
          Memo.UTF8W = (
            '[frxDBDatasetTermini."opis"]')
        end
      end
    end
  end
  object frxDBDatasetCrnaLista: TfrxDBDataset
    UserName = 'frxDBDatasetCrnaLista'
    CloseDataSource = False
    DataSet = ADOTCrnaLista
    BCDToCurrency = False
    DataSetOptions = []
    Left = 48
    Top = 416
    FieldDefs = <
      item
        FieldName = 'ID'
      end
      item
        FieldName = 'termin_id'
      end
      item
        FieldName = 'razlog'
        FieldType = fftString
        Size = 255
      end
      item
        FieldName = 'datum'
        FieldType = fftDateTime
      end
      item
        FieldName = 'TerminRegistracija'
        FieldType = fftString
        Size = 20
      end
      item
        FieldName = 'Dana na crnoj listi'
      end>
  end
  object frxDBDatasetTermini: TfrxDBDataset
    UserName = 'frxDBDatasetTermini'
    CloseDataSource = False
    DataSet = ADOTTermini
    BCDToCurrency = False
    DataSetOptions = []
    Left = 176
    Top = 416
    FieldDefs = <
      item
        FieldName = 'ID'
      end
      item
        FieldName = 'datum'
        FieldType = fftDateTime
      end
      item
        FieldName = 'registracija'
        FieldType = fftString
        Size = 255
      end
      item
        FieldName = 'korisnik_id'
      end
      item
        FieldName = 'vrijeme'
        FieldType = fftString
        Size = 255
      end
      item
        FieldName = 'opis'
        FieldType = fftString
        Size = 255
      end>
  end
end
