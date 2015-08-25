#include "StdAfx.h"
#include "MothershipStd.h"

/**
* \fn MothershipStd::MothershipStd(void)
* \brief Fonction de creation d'une nouvelle instance d'un objet MothershipStd
*
* \return Instance nouvellement allouee d'un objet de type MothershipStd
*/
MothershipStd::MothershipStd(void)
{
	diceNumber = 2;
	remainingShotsNumber = 0;
	maxShotsNumber = 3;
	reboundNumber = 5;
}

/**
* \fn MothershipStd::~MothershipStd(void)
* \brief Fonction de destruction d'objet MothershipStd
*
* \return
*/
MothershipStd::~MothershipStd(void)
{
}

/**
* \fn void MothershipStd::printType()
* \brief Affiche en console le type de vaisseau (utilise pour les tests)
* \return
*/
void MothershipStd::printType(){
	std::cout << "Mothership";
}

/**
* \fn SpaceshipType MothershipStd::getType()
* \brief Indique quel type de vaisseau (dans l'enum decrite dans Spaceship)
* \return BattlecruiserType
*/
SpaceshipType MothershipStd::getType(){
	return MothershipType;
}


EXTERNC DLL MothershipStd* MothershipStd_New(){return new MothershipStd();}
EXTERNC DLL void MothershipStd_Delete(MothershipStd* a){delete a;}
