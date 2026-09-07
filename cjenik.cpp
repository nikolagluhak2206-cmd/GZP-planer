
// ************************************************************************************************************************************ //
//                                                                                                                                    
//                                                          XML Data Binding                                                          
//                                                                                                                                    
//         Generated on: 29.7.2026. 13:25:31                                                                                          
//       Generated from: C:\Users\nikol\OneDrive\Desktop\Faks\4. semestar\Razvoj poslovnih aplikacija\Gume Zelina Planer\cjenik.xml   
//   Settings stored in: C:\Users\nikol\OneDrive\Desktop\Faks\4. semestar\Razvoj poslovnih aplikacija\Gume Zelina Planer\cjenik.xdb   
//                                                                                                                                    
// ************************************************************************************************************************************ //

#include <System.hpp>
#pragma hdrstop

#include "cjenik.h"


// Global Functions 

_di_IXMLCjenikType __fastcall GetCjenik(Xml::Xmlintf::_di_IXMLDocument Doc)
{
  return (_di_IXMLCjenikType) Doc->GetDocBinding("Cjenik", __classid(TXMLCjenikType), TargetNamespace);
};

_di_IXMLCjenikType __fastcall GetCjenik(Xml::Xmldoc::TXMLDocument *Doc)
{
  Xml::Xmlintf::_di_IXMLDocument DocIntf;
  Doc->GetInterface(DocIntf);
  return GetCjenik(DocIntf);
};

_di_IXMLCjenikType __fastcall LoadCjenik(const System::UnicodeString& FileName)
{
  return (_di_IXMLCjenikType) Xml::Xmldoc::LoadXMLDocument(FileName)->GetDocBinding("Cjenik", __classid(TXMLCjenikType), TargetNamespace);
};

_di_IXMLCjenikType __fastcall  NewCjenik()
{
  return (_di_IXMLCjenikType) Xml::Xmldoc::NewXMLDocument()->GetDocBinding("Cjenik", __classid(TXMLCjenikType), TargetNamespace);
};

// TXMLCjenikType 

void __fastcall TXMLCjenikType::AfterConstruction(void)
{
  RegisterChildNode(System::UnicodeString("Usluga"), __classid(TXMLUslugaType));
  ItemTag = "Usluga";
  ItemInterface = __uuidof(IXMLUslugaType);
  Xml::Xmldoc::TXMLNodeCollection::AfterConstruction();
};

_di_IXMLUslugaType __fastcall TXMLCjenikType::Get_Usluga(const int Index)
{
  return (_di_IXMLUslugaType) List->Nodes[Index];
};

_di_IXMLUslugaType __fastcall TXMLCjenikType::Add()
{
  return (_di_IXMLUslugaType) AddItem(-1);
};

_di_IXMLUslugaType __fastcall TXMLCjenikType::Insert(const int Index)
{
  return (_di_IXMLUslugaType) AddItem(Index);
};

// TXMLUslugaType 

System::UnicodeString __fastcall TXMLUslugaType::Get_Naziv()
{
  return GetChildNodes()->Nodes[System::UnicodeString("Naziv")]->Text;
};

void __fastcall TXMLUslugaType::Set_Naziv(const System::UnicodeString Value)
{
  GetChildNodes()->Nodes[System::UnicodeString("Naziv")]->NodeValue = Value;
};

System::UnicodeString __fastcall TXMLUslugaType::Get_Kategorija()
{
  return GetChildNodes()->Nodes[System::UnicodeString("Kategorija")]->Text;
};

void __fastcall TXMLUslugaType::Set_Kategorija(const System::UnicodeString Value)
{
  GetChildNodes()->Nodes[System::UnicodeString("Kategorija")]->NodeValue = Value;
};

float __fastcall TXMLUslugaType::Get_Cijena()
{
  return XmlStrToFloatExt(GetChildNodes()->Nodes[System::UnicodeString("Cijena")]->Text);
};

void __fastcall TXMLUslugaType::Set_Cijena(const float Value)
{
  GetChildNodes()->Nodes[System::UnicodeString("Cijena")]->NodeValue = Value;
};

System::UnicodeString __fastcall TXMLUslugaType::Get_Aktivno()
{
  return GetChildNodes()->Nodes[System::UnicodeString("Aktivno")]->Text;
};

void __fastcall TXMLUslugaType::Set_Aktivno(const System::UnicodeString Value)
{
  GetChildNodes()->Nodes[System::UnicodeString("Aktivno")]->NodeValue = Value;
};
