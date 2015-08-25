#include "StdAfx.h"
#include "EnergyStationSquareStd.h"
#include <iostream>

/*!
* \fn EnergyStationSquareStd* EnergyStationSquareStd::EnergyStationSquaretd_New()
* \brief Fonction de creation d'une nouvelle instance d'un objet EnergyStationSquareStd
* \return Instance nouvellement allouee d'un objet de type EnergyStationSquareStd
*/
EnergyStationSquareStd::EnergyStationSquareStd(void)
{
}

/*!
* \fn bool EnergyStationSquareStd::isAccessible()
* \brief Indique si la case est accessible
* \return true
*/
bool EnergyStationSquareStd::isAccessible(){
	return true;
}

/*!
* \fn void EnergyStationSquareStd::printConsole()
* \brief Affiche en console la case (utilise pour les tests)
* \return
*/
void EnergyStationSquareStd::printConsole(){
	std::cout << "e";
}

/*!
* \fn SquareType EnergyStationSquareStd::getType()
* \brief permet de connaitre le type de la case (types decrits dans l'enum de Square.h)
* \return EnergyStationSquareType
*/
SquareType EnergyStationSquareStd::getType(){
	return EnergyStationSquareType;
}

/*!
* \fn void EnergyStationSquareStd::doAction()
* \brief realise l'action necessaire lorsque le joueur p arrive sur cette case
* \param Player* p le joueur
* \return
*/
void EnergyStationSquareStd::doAction(Player* p){
	p->getSpaceship()->chargeLaser();
}

EXTERNC DLL EnergyStationSquareStd* EnergyStationSquareStd_New(){return new EnergyStationSquareStd();}
EXTERNC DLL void EnergyStationSquareStd_Delete(EnergyStationSquareStd* e){delete e;}
