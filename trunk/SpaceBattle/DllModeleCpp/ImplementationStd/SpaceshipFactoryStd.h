#pragma once
#define WANTDLLEXP
#ifdef WANTDLLEXP		//exportation dll
#define DLL  __declspec( dllexport )
#define EXTERNC extern "C"
#else
#define DLL		//standard
#define EXTERNC
#endif
#include "..\Abstrait\SpaceshipFactory.h"

	/*! \class SpaceshipFactoryStd
	* \implements SpaceshipFactory
	* \brief Implementation de SpaceshipFactory, le monteur de vaisseaux
	*/
class DLL SpaceshipFactoryStd : public SpaceshipFactory
{
public:
	SpaceshipFactoryStd(void);
	~SpaceshipFactoryStd(void);

	Spaceship* createBattlecruiser();
	Spaceship* createMothership();
	Spaceship* createRescuecab();
	Spaceship* createNextSpaceship(Spaceship* s);
};

EXTERNC DLL SpaceshipFactoryStd* SpaceshipFactoryStd_New();
EXTERNC DLL void SpaceshipFactoryStd_Delete(SpaceshipFactoryStd* m);

