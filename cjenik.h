
// ************************************************************************************************************************************ //
//                                                                                                                                    
//                                                          XML Data Binding                                                          
//                                                                                                                                    
//         Generated on: 29.7.2026. 13:25:31                                                                                          
//       Generated from: C:\Users\nikol\OneDrive\Desktop\Faks\4. semestar\Razvoj poslovnih aplikacija\Gume Zelina Planer\cjenik.xml   
//   Settings stored in: C:\Users\nikol\OneDrive\Desktop\Faks\4. semestar\Razvoj poslovnih aplikacija\Gume Zelina Planer\cjenik.xdb   
//                                                                                                                                    
// ************************************************************************************************************************************ //

#ifndef   cjenikH
#define   cjenikH

#include <System.hpp>
#include <System.Variants.hpp>
#include <System.SysUtils.hpp>
#include <Xml.Xmldom.hpp>
#include <Xml.XMLIntf.hpp>
#include <Xml.XMLDoc.hpp>
#include <XMLNodeImp.h>
#include <Xml.xmlutil.hpp>


// Forward Decls 

__interface IXMLCjenikType;
typedef System::DelphiInterface<IXMLCjenikType> _di_IXMLCjenikType;
__interface IXMLUslugaType;
typedef System::DelphiInterface<IXMLUslugaType> _di_IXMLUslugaType;

// IXMLCjenikType 

__interface INTERFACE_UUID("{38D9B01E-9EA3-4F51-A02A-57EC96D86C7C}") IXMLCjenikType : public Xml::Xmlintf::IXMLNodeCollection
{
public:
public:
  // Property Accessors 
  virtual _di_IXMLUslugaType __fastcall Get_Usluga(const int Index) = 0;
  // Methods & Properties 
  virtual _di_IXMLUslugaType __fastcall Add() = 0;
  virtual _di_IXMLUslugaType __fastcall Insert(const int Index) = 0;
  __property _di_IXMLUslugaType Usluga[const int Index] = { read=Get_Usluga };/* default */
};

// IXMLUslugaType 

__interface INTERFACE_UUID("{AEDA592E-26E0-4C1C-A4FF-B2B49B8AD3D8}") IXMLUslugaType : public Xml::Xmlintf::IXMLNode
{
public:
  // Property Accessors 
  virtual System::UnicodeString __fastcall Get_Naziv() = 0;
  virtual System::UnicodeString __fastcall Get_Kategorija() = 0;
  virtual float __fastcall Get_Cijena() = 0;
  virtual System::UnicodeString __fastcall Get_Aktivno() = 0;
  virtual void __fastcall Set_Naziv(const System::UnicodeString Value) = 0;
  virtual void __fastcall Set_Kategorija(const System::UnicodeString Value) = 0;
  virtual void __fastcall Set_Cijena(const float Value) = 0;
  virtual void __fastcall Set_Aktivno(const System::UnicodeString Value) = 0;
  // Methods & Properties 
  __property System::UnicodeString Naziv = { read=Get_Naziv, write=Set_Naziv };
  __property System::UnicodeString Kategorija = { read=Get_Kategorija, write=Set_Kategorija };
  __property float Cijena = { read=Get_Cijena, write=Set_Cijena };
  __property System::UnicodeString Aktivno = { read=Get_Aktivno, write=Set_Aktivno };
};

// Forward Decls 

class TXMLCjenikType;
class TXMLUslugaType;

// TXMLCjenikType 

class TXMLCjenikType : public Xml::Xmldoc::TXMLNodeCollection, public IXMLCjenikType
{
  __IXMLNODECOLLECTION_IMPL__
protected:
  // IXMLCjenikType 
  virtual _di_IXMLUslugaType __fastcall Get_Usluga(const int Index);
  virtual _di_IXMLUslugaType __fastcall Add();
  virtual _di_IXMLUslugaType __fastcall Insert(const int Index);
public:
  virtual void __fastcall AfterConstruction(void);
};

// TXMLUslugaType 

class TXMLUslugaType : public Xml::Xmldoc::TXMLNode, public IXMLUslugaType
{
  __IXMLNODE_IMPL__
protected:
  // IXMLUslugaType 
  virtual System::UnicodeString __fastcall Get_Naziv();
  virtual System::UnicodeString __fastcall Get_Kategorija();
  virtual float __fastcall Get_Cijena();
  virtual System::UnicodeString __fastcall Get_Aktivno();
  virtual void __fastcall Set_Naziv(const System::UnicodeString Value);
  virtual void __fastcall Set_Kategorija(const System::UnicodeString Value);
  virtual void __fastcall Set_Cijena(const float Value);
  virtual void __fastcall Set_Aktivno(const System::UnicodeString Value);
};

// Global Functions 

_di_IXMLCjenikType __fastcall GetCjenik(Xml::Xmlintf::_di_IXMLDocument Doc);
_di_IXMLCjenikType __fastcall GetCjenik(Xml::Xmldoc::TXMLDocument *Doc);
_di_IXMLCjenikType __fastcall LoadCjenik(const System::UnicodeString& FileName);
_di_IXMLCjenikType __fastcall  NewCjenik();

#define TargetNamespace ""

#endif