﻿//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated by a tool.
//     Changes to this file will be lost if the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------
#pragma once
#define WANTDLLEXP
#ifdef WANTDLLEXP		//exportation dll
#define DLL  __declspec( dllexport )
#define EXTERNC extern "C"
#else
#define DLL		//standard
#define EXTERNC
#endif
#include <string>
#include "Map.h"

	/// <remarks>Monteur</remarks>
/*! \interface MapBuilder
* \brief Interface du monteur de map, a partir d'un nom de fichier
*
*/
class DLL MapBuilder 
{
	
	public:
		virtual Map* createMap(std::string filename)=0;

};


