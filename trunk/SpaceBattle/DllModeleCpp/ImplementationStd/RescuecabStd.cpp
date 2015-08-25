#include "StdAfx.h"
#include "RescuecabStd.h"

/**
* \fn RescuecabStd::RescuecabStd_New ()
* \brief Fonction de creation d'une nouvelle instance d'un objet RescuecabStd
*
* \return Instance nouvellement allouee d'un objet de type RescuecabStd
*/
RescuecabStd::RescuecabStd(void)
{
	diceNumber = 1;
	remainingShotsNumber = 0;
	maxShotsNumber = 1;
	reboundNumber = 3;
}

/**
* \fn RescuecabStd::RescuecabStd_Delete ()
* \brief Fonction de destruction d'objet RescuecabStd
*
* \return
*/
RescuecabStd::~RescuecabStd(void)
{
}


/**
* \fn void RescuecabStd::printType()
* \brief Affiche en console le type de vaisseau (utilise pour les tests)
* \return
*/
void RescuecabStd::printType(){
	std::cout<< "Rescuecab";
}

/**
* \fn RescuecabStd::SpaceshipType getType()
* \brief Indique quel type de vaisseau (dans l'enum decrite dans Spaceship)
* \return RescuecabType
*/
SpaceshipType RescuecabStd::getType(){
	return RescuecabType;
}



EXTERNC DLL RescuecabStd* RescuecabStd_New(){return new RescuecabStd();}
EXTERNC DLL void RescuecabStd_Delete(RescuecabStd* a){delete a;}