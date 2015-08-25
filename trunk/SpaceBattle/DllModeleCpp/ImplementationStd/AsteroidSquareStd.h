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
#include "..\Abstrait\AsteroidSquare.h"
#include <iostream>

	/*! \class AsteroidSquareStd
	* \brief classe implementant AsteroidSquare, representant une case contenant une asteroide
	*
	*/
	class DLL AsteroidSquareStd : public AsteroidSquare
	{

		public :
			AsteroidSquareStd();
			bool isAccessible();
			void printConsole();
			SquareType getType();
			void doAction(Player* p);

	}; 
	EXTERNC DLL AsteroidSquareStd* AsteroidSquareStd_New();
	EXTERNC DLL void AsteroidSquareStd_Delete(AsteroidSquareStd* a);