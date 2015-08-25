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

/*! \enum GameStatusType
* \brief Enumeration des differents etats dans lesquels peut etre la partie en cours
*
*/
enum GameStatusType {
     WaitType,
     MoveType,
     ShootType
};

#include "Game.h"
#include <iostream>
#include <string>

/*! \interface GameStatus
* \brief interface de l'etat dans lequel se trouve la partie
*
*/
	class DLL GameStatus 
	{
		public:
		virtual void doAction(double posx,double posy,int playerNb) = 0;
		virtual GameStatusType getType() = 0;
	};

