//------------------------------------------------------------------------------
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

#include<vector>
#include "..\Abstrait\EmptySquare.h"
#include <iostream>

	/*! \class EmptySquareStd
	* \brief classe implementant EmptySquare, representant une case contenant rien
	* destine a etre utilise en poids-mouche
	*/
	class DLL EmptySquareStd: public EmptySquare
	{
		

		public :
			EmptySquareStd();
			bool isAccessible();
			void printConsole();
			SquareType getType();
			void doAction(Player* p);

	}; 
	EXTERNC DLL EmptySquareStd* EmptySquareStd_New();
	EXTERNC DLL void EmptySquareStd_Delete(EmptySquareStd* s);
