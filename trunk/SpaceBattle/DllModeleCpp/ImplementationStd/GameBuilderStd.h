#pragma once
#define WANTDLLEXP
#ifdef WANTDLLEXP		//exportation dll
#define DLL  __declspec( dllexport )
#define EXTERNC extern "C"
#else
#define DLL		//standard
#define EXTERNC
#endif
#include "..\Abstrait\GameBuilder.h"
#include "..\Abstrait\Game.h"
#include "GameStd.h"
#include "..\Abstrait\Game.h"
#include "GameDicesStd.h"
#include "MapBuilderStd.h"
#include "..\Abstrait\MapBuilder.h"
#include "SpaceshipFactoryStd.h"
#include "..\Abstrait\SpaceshipFactory.h"
#include "PlayerStd.h"
#include "..\Abstrait\Player.h"

/*!
* \class GameBuilderStd
* \implements GameBuilder
* \brief implementation du monteur de Game
*
*/
class GameBuilderStd : public GameBuilder
{
public:
	GameBuilderStd(void);
	~GameBuilderStd(void);
	Game* createGame(int nbPlayers,int nbArtefact,std::string mapFile,std::vector<Color>& colorVec,std::vector<int>& teamVec);
	int getOrbitalPosX(Color c,int longueur, int hauteur);
	int getOrbitalPosY(Color c,int longueur, int hauteur);
	void setPosShip(Spaceship* s,Color c,int longueur, int hauteur);
};

EXTERNC DLL GameBuilderStd* GameBuilderStd_New();
EXTERNC DLL void GameBuilderStd_Delete(GameBuilderStd* g);
