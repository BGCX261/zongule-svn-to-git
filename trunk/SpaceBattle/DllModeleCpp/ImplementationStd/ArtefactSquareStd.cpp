#include "StdAfx.h"
#include "ArtefactSquareStd.h"
#include <iostream>

/*!
* \fn ArtefactSquareStd* ArtefactSquareStd::ArtefactSquareStd_New()
* \brief Fonction de creation d'une nouvelle instance d'un objet ArtefactSquareStd
* \return Instance nouvellement allouee d'un objet de type ArtefactSquareStd
*/
ArtefactSquareStd::ArtefactSquareStd(){

}

/*!
* \fn bool ArtefactSquareStd::isAccessible()
* \brief Indique si la case est accessible
* 
* \return true
*/
bool ArtefactSquareStd::isAccessible(){
	return true;
}

/*!
* \fn void ArtefactSquareStd::printConsole()
* \brief Affiche en console la case (utilise pour les tests)
* \return
*/
void ArtefactSquareStd::printConsole(){
	std::cout << "a";
}

/*!
* \fn SquareType ArtefactSquareStd::getType()
* \brief permet de connaitre le type de la case (types decrits dans l'enum de Square.h)
* \return ArtefactSquareType
*/
SquareType ArtefactSquareStd::getType(){
	return ArtefactSquareType;
}

/*!
* \fn void ArtefactSquareStd::doAction()
* \brief realise l'action necessaire lorsque le joueur p arrive sur cette case
* \param Player* p
* \return
*/
void ArtefactSquareStd::doAction(Player* p){
	if (p->getSpaceship()->getType() != RescuecabType)
	p->getSpaceship()->takeArtefact();
}

EXTERNC DLL  ArtefactSquareStd* ArtefactSquareStd_New(){return new ArtefactSquareStd();}
EXTERNC DLL  void ArtefactSquareStd_Delete(ArtefactSquareStd* a){delete a;}
