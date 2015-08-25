#pragma once
#define WANTDLLEXP
#ifdef WANTDLLEXP		//exportation dll
#define DLL  __declspec( dllexport )
#define EXTERNC extern "C"
#else
#define DLL		//standard
#define EXTERNC
#endif
#include "..\Abstrait\MapBuilder.h"
#include "..\Abstrait\SquareFactory.h"
#include "..\Abstrait\Map.h"
#include "SquareFactoryStd.h"
#include "MapStd.h"
#include <iostream>
#include <fstream>
#include <sstream>

/*! \class MapBuilderStd
* \brief classe representant un monteur pour la map du jeu
* \implements MapBuilder
*
*  La classe construit une map a partir d'un fichier
*/
class DLL MapBuilderStd : public MapBuilder
{

private:
	SquareFactory* factory;		/*!< Monteur pour les cases de la map*/
	int orbitalStationsNb;		/*!< Compteur pour verifier qu'il y a bien 4 stations orbitales*/
	int artefactsNb;			/*!< Compteur pour verifier qu'il y a bien au moins 1 artefact*/
	int energiesNb;				/*!< Compteur pour verifier qu'il y a bien au moins 1 energie*/

public:
	MapBuilderStd(void);
	~MapBuilderStd(void);
	Map* createMap(std::string filename);
	Map* createTestMap();
	void initializeCheckers();
	int stringToInt(const std::string & str);
	bool stillAnAsteroid(const std::string & str);
};

EXTERNC DLL MapBuilderStd* MapBuilderStd_New();
EXTERNC DLL void MapBuilderStd_Delete(MapBuilderStd* m);
