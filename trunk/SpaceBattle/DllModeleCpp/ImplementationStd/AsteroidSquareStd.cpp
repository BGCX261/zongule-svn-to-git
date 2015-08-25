#include "StdAfx.h"
#include "AsteroidSquareStd.h"
#include <iostream>

/*!
* \fn AsteroidSquareStd* AsteroidSquareStd::AsteroidSquareStd_New()
* \brief Fonction de creation d'une nouvelle instance d'un objet AsteroidSquareStd
* \return Instance nouvellement allouee d'un objet de type AsteroidSquareStd
*/
AsteroidSquareStd::AsteroidSquareStd(void)
{
}

/*!
* \fn bool AsteroidSquareStd::isAccessible()
* \brief Indique si la case est accessible
* \return false
*/
bool AsteroidSquareStd::isAccessible(){
	return false;
}

/*!
* \fn void AsteroidSquareStd::printConsole()
* \brief Affiche en console la case (utilise pour les tests)
* \return
*/
void AsteroidSquareStd::printConsole(){
	std::cout << "A";
}

/*!
* \fn SquareType AsteroidSquareStd::getType()
* \brief permet de connaitre le type de la case (types decrits dans l'enum de Square.h)
* \return AsteroidSquareType
*/
SquareType AsteroidSquareStd::getType(){
	return AsteroidSquareType;
}

/*!
* \fn void AsteroidSquareStd::doAction()
* \brief realise l'action necessaire lorsque le joueur p arrive sur cette case
* \param Player* p
* \return
*/
void AsteroidSquareStd::doAction(Player* p){
	//nothing.
}

EXTERNC DLL AsteroidSquareStd* AsteroidSquareStd_New(){return new AsteroidSquareStd();}
EXTERNC DLL void AsteroidSquareStd_Delete(AsteroidSquareStd* a){delete a;}
