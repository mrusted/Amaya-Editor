#ifndef TEMPLATE_TEMPLATES
#define TEMPLATE_TEMPLATES

#define THOT_EXPORT extern
#include "amaya.h"
#include "document.h"
#include "mydictionary.h"

/* Structure of a template */
struct _XTigerTemplate;
typedef struct _XTigerTemplate *XTigerTemplate;

//Private structure of a template
struct _XTigerTemplate
{	
  ThotBool        isLibrary;			//Is this a library? (otherway it's a template)
  ThotBool        isPredefined;   //Is this the predefined library
  DicDictionary   libraries;			//Imported libraries
  DicDictionary   simpleTypes;		//All simple types declared in the document
  DicDictionary   elements;				//All element types declared in the document
  DicDictionary   components;			//All component types declared in the document
  DicDictionary   unions;				  //All union types declared in the document
  Document        doc;            //Use to store component structures
  int             users;          //Number of documents using this template
};

typedef enum _TypeNature {SimpleTypeNat, XmlElementNat, ComponentNat,
                          UnionNat} TypeNature;

// XTiger simple type
typedef enum _SimpleTypeType {XTNumber, XTString, XTBoolean} SimpleTypeType;

/* Structure of a Declaration */

typedef struct _XmlElement
{
	char	*name;
} XmlElement;

typedef struct _SimpleType
{
	SimpleTypeType type;
} SimpleType;

typedef struct _Component
{
	Element        content;
} Component;

typedef struct _Union
{
	DicDictionary  include; //Dictionary<Declaration>
	DicDictionary  exclude; //Dictionary<Declaration>
} Union;

/* Structure of a declaration */
struct _Declaration;
typedef struct _Declaration *Declaration;

struct _Declaration
{
	char          *name;
	TypeNature     nature;
	XTigerTemplate declaredIn;
	union
	{
		SimpleType   simpleType;
		Component    componentType;
		Union        unionType;
		XmlElement   elementType;
	};
};

struct menuType
{
	char        *label;
	TypeNature   type;
};

#endif /* TEMPLATE_TEMPLATES */