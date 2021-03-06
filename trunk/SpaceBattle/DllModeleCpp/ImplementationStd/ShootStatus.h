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
#include "..\Abstrait\GameStatus.h"
#include <vector>
#include "Position.h"
#include <map>
#pragma warning( disable: 4018 )
#pragma warning( disable: 4251 )

/*! \class ShootStatus
* \brief classe representant, durant une partie, l'etat "un joueur tire"
* \implements GameStatus
*
*/
	class DLL ShootStatus : public GameStatus
	{
		private:
		Game* game;	/*!< La partie dans laquelle l'etat est associe*/
		std::vector<Position> lastShootTrace;	/*!< Tableau des coordonnees par lesquelles passe le laser*/

		public :
			ShootStatus();
			ShootStatus(Game* g);
			~ShootStatus();

			void doAction(double posx,double posy,int playerNb);
			GameStatusType getType();
			std::map<double,Position> shootUpRight(double posx,double posy,double sourcePosX,double sourcePosY);
			std::map<double,Position> shootDownRight(double posx,double posy,double sourcePosX,double sourcePosY);
			std::map<double,Position> shootUpLeft(double posx,double posy,double sourcePosX,double sourcePosY);
			std::map<double,Position> shootDownLeft(double posx,double posy,double sourcePosX,double sourcePosY);
			double getDist(double sourcePosX,double sourcePosY,double posx,double posy);
			Position calculateAsteroidRebound(double sourcePosX,double sourcePosY,double posx,double posy, Position square);
			Position calculateEdgeRebound(double sourcePosX,double sourcePosY,double posx,double posy, Position square);
			void shoot(double sourcePosX,double sourcePosY,double posx,double posy,int reboundNumber);
			Position calculateNewPosition(double previousAngle,double shootPointX,double shootPointY);
			Position getPosFromAngle(double newAngle, double posx,double posy);
			std::vector<Position> getLastShootTrace();
			void removeFirstSquare(double sourcePosX,double sourcePosY,std::map<double,Position>* casesTraversees);
	}; 
	EXTERNC DLL ShootStatus* ShootStatus_New();
	EXTERNC DLL void ShootStatus_Delete(ShootStatus* a);
