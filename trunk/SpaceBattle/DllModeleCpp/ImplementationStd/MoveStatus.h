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
#include "..\Abstrait\GameStatus.h"
#include "..\Abstrait\Game.h"

/*! \class MoveStatus
* \brief classe representant, durant une partie, l'etat "un joueur bouge un vaisseau"
* \implements GameStatus
*
*/
	class DLL MoveStatus : public GameStatus
	{
		private:
		Game* game;	/*!< La partie dans laquelle l'etat est associe*/
		public :
			MoveStatus();
			MoveStatus(Game* g);
			~MoveStatus();
			void doAction(double posx,double posy,int playerNb);
			GameStatusType getType();

	}; 
	EXTERNC DLL MoveStatus* MoveStatus_New();
	EXTERNC DLL void MoveStatus_Delete(MoveStatus* a);
