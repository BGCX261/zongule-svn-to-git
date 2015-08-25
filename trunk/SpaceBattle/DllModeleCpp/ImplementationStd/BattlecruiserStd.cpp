#include "StdAfx.h"
#include "BattlecruiserStd.h"

/*!
* \fn BattlecruiserStd::BattlecruiserStd_New ()
* \brief Fonction de creation d'une nouvelle instance d'un objet BattlecruiserStd
*
* \return Instance nouvellement allouee d'un objet de type BattlecruiserStd
*/
BattlecruiserStd::BattlecruiserStd(void)
{
	diceNumber = 1;
	remainingShotsNumber = 0;
	maxShotsNumber = 2;
	reboundNumber = 4;
}

/*!
* \fn BattlecruiserStd::~BattlecruiserStd(void)
* \brief Fonction de destruction d'objet BattlecruiserStd
*
* \return
*/
BattlecruiserStd::~BattlecruiserStd(void)
{
}

/*!
* \fn void BattlecruiserStd::printType()
* \brief Affiche en console le type de vaisseau (utilise pour les tests)
* \return
*/
void BattlecruiserStd::printType(){
	std::cout << "Battlecruiser";
}

/*!
* \fn SpaceshipType BattlecruiserStd::getType()
* \brief Indique quel type de vaisseau (dans l'enum decrite dans Spaceship)
* \return BattlecruiserType
*/
SpaceshipType BattlecruiserStd::getType(){
	return BattlecruiserType;
}

EXTERNC DLL BattlecruiserStd* BattlecruiserStd_New(){ return new BattlecruiserStd();}
EXTERNC DLL void BattlecruiserStd_Delete(BattlecruiserStd* a){delete a;}
