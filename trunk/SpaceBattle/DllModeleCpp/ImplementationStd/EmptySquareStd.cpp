#include "StdAfx.h"
#include "EmptySquareStd.h"
#include <iostream>

/*!
* \fn EmptySquareStd* EmptySquareStd::EmptySquareStd_New()
* \brief Fonction de creation d'une nouvelle instance d'un objet EmptySquareStd
* \return Instance nouvellement allouee d'un objet de type EmptySquareStd
*/
EmptySquareStd::EmptySquareStd(void)
{
}

/*!
* \fn bool EmptySquareStd::isAccessible()
* \brief Indique si la case est accessible
* \return true
*/
bool EmptySquareStd::isAccessible(){
	return true;
}

/*!
* \fn void EmptySquareStd::printConsole()
* \brief Affiche en console la case (utilise pour les tests)
* \return
*/
void EmptySquareStd::printConsole(){
	std::cout << ".";
}

/*!
* \fn SquareType EmptySquareStd::getType()
* \brief permet de connaitre le type de la case (types decrits dans l'enum de Square.h)
* \return EmptySquareType
*/
SquareType EmptySquareStd::getType(){
	return EmptySquareType;
}

/*!
* \fn void EmptySquareStd::doAction()
* \brief realise l'action necessaire lorsque le joueur p arrive sur cette case
* \param Player* p
* \return
*/
void EmptySquareStd::doAction(Player* p){
	//nothing.
}



EXTERNC DLL EmptySquareStd* EmptySquareStd_New(){return new EmptySquareStd();}
EXTERNC DLL void EmptySquareStd_Delete(EmptySquareStd* s){delete s;}
