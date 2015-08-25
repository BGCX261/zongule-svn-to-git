#pragma once
#define WANTDLLEXP
#ifdef WANTDLLEXP		//exportation dll
#define DLL  __declspec( dllexport )
#define EXTERNC extern "C"
#else
#define DLL		//standard
#define EXTERNC
#endif

#include "..\Abstrait\Spaceship.h"
#include "..\Abstrait\Player.h"
#include "SpaceshipFactoryStd.h"
#include<vector>
#pragma warning( disable: 4251 )  //<- warning sur l'utilisation de std::vector dns une dll

/*! \class PlayerStd
* \brief classe representant un joueur
* \implements Player
*
*/
class DLL PlayerStd : public Player
{

private:
	Color color;		/*!< Couleur du joueur*/
	int orbitalStationPosX;	/*!< abscisse de la station orbitale du joueur*/
	int orbitalStationPosY;	/*!< ordonnee de la station orbitale du joueur*/
	int wonArtefacts;	/*!< Artefacts deja ramasses*/
	Spaceship* spaceship;	/*!< le vaisseau que le joueur a en sa possession (vaisseau qui peut changer de type)*/
public:
	PlayerStd(void);
	~PlayerStd(void);
	PlayerStd::PlayerStd(Color c,Spaceship* &s, int orbitalPosX, int orbitalPosY);
	void winArtefact();
	Color getColor();
	int getPlayerPosX();
	int getPlayerPosY();
	int getNbArtefacts();
	bool getPlayerPossesArtefact();
	int getPlayerShotsRemaining();
	Spaceship* getSpaceship();
	bool isOnHisOrbitalStation();
	void restoreMothership();
	void replaceSpaceship(Spaceship* newSpaceship);


};
EXTERNC DLL PlayerStd* PlayerStd_New();
EXTERNC DLL void PlayerStd_Delete(PlayerStd* p);


