#pragma once
#define WANTDLLEXP
#ifdef WANTDLLEXP		//exportation dll
#define DLL  __declspec( dllexport )
#define EXTERNC extern "C"
#else
#define DLL		//standard
#define EXTERNC
#endif
#include "..\Abstrait\Game.h"
#include "..\Abstrait\Player.h"
#include "..\Abstrait\GameDices.h"
#include "..\Abstrait\Map.h"
#include "..\Abstrait\GameStatus.h"
#include "MoveStatus.h"
#include "ShootStatus.h"
#include "WaitStatus.h"
#include "SpaceshipFactoryStd.h"
#include "..\Abstrait\GameBuilder.h"
#include "GameBuilderStd.h"

#include <vector>

/*! \class GameStd
* \brief classe representant une partie de jeu
* \implements Game
*
*  La classe gere une partie de jeu
*/
class GameStd : public Game
{
	private:
		int nbPlayers;			/*!< Nombre de joueurs*/
		int currentPlayer;		/*!< numéro du joueur qui a la main (joueur courant)*/
		int nbArtefactsToWin;		/*!< Nombre d'artefacts à avoir pour gagner la partie*/
		GameStatus* currentStatus;	/*!< Etat courant de la partie*/
		MoveStatus* moveStatus;		/*!< Etat de déplacement*/
		ShootStatus* shootStatus;	/*!< Etat de tir*/
		WaitStatus* waitStatus;		/*!< Etat d'attente*/
		Map* map;			/*!< Map du jeu*/
		std::vector<Player*> players;	/*!< Tableau des joueurs*/
		int teamTab[4];  /*!< Tableau des equipes des joueurs */
		Color colorTab[4];		/*!< Tableau des couleurs des joueurs*/


	public:
		GameStd(void);
		void addPlayers(std::vector<Player*> ptab);
		void addMap(Map* nmap);
		int getMapLongueur();
		int getMapHauteur();
		SquareType getSquareType(int x,int y);
		int getCurrentPlayer();
		Spaceship* getCurrentSpaceship();
		void nextPlayer();
		void setNbPlayers(int nb);
		void setColorTab(Color c1,Color c2,Color c3,Color c4);
		void setTeamTab(std::vector<int>& teamVec);
		void setNbArtefactsToWin(int nb);
		Color getColorTab(int i);
		int getPlayerPosX(int playerNb);
		int getPlayerPosY(int playerNb);
		int getPlayerTeam(int playerNb);
		std::vector<Position> getPlayersPosition();
		std::vector<Position> getAsteroidsPosition();
		int getPlayerNbArtefacts(int playerNb);
		bool getPlayerPossesArtefact(int playerNb);
		int getPlayerShotsRemaining(int playerNb);
		void doAction(double posx,double posy);
		Square* getMapSquare(int posx,int posy);
		Player* getPlayer(int i);
		void changeCurrentStatus(GameStatusType t);
		GameStatusType getCurrentStatus();
		void shootPlayer(int playerNb);
		std::vector<Position> getLastShootTrace();
		SpaceshipType getPlayerSpaceshipType(int playerNb);
		std::vector<int> getAccessibleSquares(int diceNb);
		void addAccessibleSquare(std::vector<int>* vec,int srcx,int srcy, int posx, int posy,int dir);
		bool isAccessibleSquare(int posx,int posy);
		bool isGameEnded();
		int getGameWinner();
		bool isValidMap();

};

EXTERNC DLL GameStd* GameStd_New();
EXTERNC DLL void GameStd_Delete(GameStd* g);
