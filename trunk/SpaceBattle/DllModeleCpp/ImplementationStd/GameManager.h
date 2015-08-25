#pragma once
#define WANTDLLEXP
#ifdef WANTDLLEXP               //exportation dll
#define DLL  __declspec( dllexport )
#define EXTERNC extern "C"
#else
#define DLL             //standard
#define EXTERNC
#endif
#include "..\Abstrait\Game.h"
#include "..\Abstrait\GameBuilder.h"
#include "GameBuilderStd.h"

/*!
* \class GameManager
* \brief classe servant a gerer la partie
*
*/
class DLL GameManager
{

private:
	Game* game;		/*!< la partie a gerer*/
	GameDices* dices;	/*!< Des*/
public:
	GameManager(void);
	~GameManager(void);

		void createGame(int nbPlayers, int nbArtefact,std::vector<Color>& colorVec,std::vector<int>& teamVec,std::string strMapFilename);
		int rollFirstDice();
		int rollSecondDice();
		int getFirstDiceValue();
		int getSecondDiceValue();
		void resetDices();
		int getMapLongueur();
		int getMapHauteur();
		SquareType getSquareType(int x,int y);
		int getCurrentPlayer() ;
		void nextPlayer();
		Color getColorTab(int i);
		int getPlayerPosX(int playerNb);
		int getPlayerPosY(int playerNb);
		int getPlayerTeam(int playerNb);
		int getPlayerNbArtefacts(int playerNb);
		bool getPlayerPossesArtefact(int playerNb);
		int getPlayerShotsRemaining(int playerNb);
		SpaceshipType getPlayerSpaceshipType(int playerNb);
		void doAction(double posx,double posy);
		void changeCurrentStatus(int t);
		int getCurrentStatus();
		std::vector<double> getLastShootTrace();
		std::vector<int> getAccessibleSquares(int radioIndice);
		bool isGameEnded();
		int getGameWinner();
		bool isValidMap();

};

        EXTERNC DLL GameManager* GameManager_New();
        EXTERNC DLL void GameManager_Delete(GameManager* gd);


