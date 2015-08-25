#include "StdAfx.h"
#include "MoveStatus.h"

/*!
* \fn MoveStatus* MoveStatus::MoveStatus()
* \brief Fonction de creation d'une nouvelle instance d'un objet MoveStatus
* \return Instance nouvellement allouee d'un objet de type MoveStatus
*/
MoveStatus::MoveStatus(){
}

/*!
* \fn MoveStatus* MoveStatus::MoveStatus(Game* g)
* \brief Fonction de creation d'une nouvelle instance d'un objet MoveStatus, en lui associant la partie g
* \param Game* g la partie a associer a l'etat "bouger"
* \return Instance nouvellement allouee d'un objet de type MoveStatus, associee a g
*/
MoveStatus::MoveStatus(Game* g){
	game = g;
}

/*!
* \fn void MoveStatus::~MoveStatus()
* \brief Fonction de destruction d'un objet MoveStatus
* \return
*/
MoveStatus::~MoveStatus(){
	delete game;
}

/*!
* \fn void MoveStatus::doAction(double posx,double posy,int playerNb)
* \brief realise l'action associee a l'etat "bouger", en l'occurence deplacer le vaisseau
* \param posx, posy
* \param playerNb
* \return
*/
void MoveStatus::doAction(double posx,double posy,int playerNb){
	//faire le mouvement
	game->getCurrentSpaceship()->move((int)posx,(int)posy);
	//doaction case
	game->getMapSquare((int)posx,(int)posy)->doAction(game->getPlayer(game->getCurrentPlayer()));
}

/*!
* \fn GameStatusType MoveStatus::getType()
* \brief retourne le type d'etat (de l'enum StatusType)
* \return GameStatusType MoveStatus
*/
GameStatusType MoveStatus::getType(){
	return MoveType;
}

EXTERNC DLL MoveStatus* MoveStatus_New(){return new MoveStatus();}
EXTERNC DLL void MoveStatus_Delete(MoveStatus* a){delete a;}
