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
#include "Spaceship.h"

#include<vector>

/*! \class Mothership
* \brief interface heritant de Spaceship et representant un vaisseau de type mothership
*
*/
	class DLL Mothership : public Spaceship
	{
		private :

		public :
			

	}; 


