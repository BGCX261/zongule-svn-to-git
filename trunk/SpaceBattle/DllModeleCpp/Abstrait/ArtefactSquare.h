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
#include "Square.h"

	/*! \interface ArtefactSquare
	* \brief interface heritant de Square, representant une case contenant un artefact
	*
	*/
	class DLL ArtefactSquare : public Square
	{
		public:
			virtual void printConsole() = 0;
			virtual void doAction(Player* p)=0;
	};


