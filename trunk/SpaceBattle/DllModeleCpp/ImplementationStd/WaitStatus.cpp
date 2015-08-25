 #include "StdAfx.h"
#include "WaitStatus.h"


/*!
* \fn WaitStatus* WaitStatus::WaitStatus()
* \brief Fonction de creation d'une nouvelle instance d'un objet WaitStatus
* \return Instance nouvellement allouee d'un objet de type WaitStatus
*/
WaitStatus::WaitStatus(){

}

/*!
* \fn WaitStatus* WaitStatus::WaitStatus(Game* g)
* \brief Fonction de creation d'une nouvelle instance d'un objet WaitStatus, en lui associant la partie g
* \param Game* g la partie a associer a l'etat "attendre son tour"
* \return Instance nouvellement allouee d'un objet de type WaitStatus, associee a g
*/
WaitStatus::WaitStatus(Game* g){
	game = g;
}

/*!
* \fn void WaitStatus::~WaitStatus()
* \brief Fonction de destruction d'un objet WaitStatus
* \return
*/
WaitStatus::~WaitStatus(){
	delete game;
}


/*!
* \fn void WaitStatus::doAction(double posx,double posy,int playerNb)
* \brief realise l'action associee a l'etat "bouger", en l'occurence ne rien faire
* \param posx, posy
* \param playerNb
* \return
*/
void WaitStatus::doAction(double posx,double posy,int playerNb){
}

/*!
* \fn WaitStatusType WaitStatus::getType()
* \brief retourne le type d'etat (de l'enum StatusType)
* \return WaitStatusType WaitStatus
*/
GameStatusType WaitStatus::getType(){
	return WaitType;
}
EXTERNC DLL WaitStatus* WaitStatus_New(){return new WaitStatus();}
EXTERNC DLL void WaitStatus_Delete(WaitStatus* a){delete a;}
