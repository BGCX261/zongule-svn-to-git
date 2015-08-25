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

	/// <remarks>Fly-Weight</remarks>
/*! \interface SquareFactory
 * \brief Interface du monteur de Square
 */
	class DLL SquareFactory 
	{
		public:
		virtual Square* createArtefactSquare()=0;
		virtual Square* createAsteroidSquare()=0;
		virtual Square* createOrbitalStationSquare()=0;
		virtual Square* createEmptySquare()=0;
		virtual Square* createEnergyStationSquare()=0;

	};


