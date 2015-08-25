#include "StdAfx.h"
#include "PlayerStd.h"

/*!
* \fn PlayerStd* PlayerStd::PlayerStd_New()
* \brief Fonction de creation d'une nouvelle instance d'un objet PlayerStd
* \return Instance nouvellement allouee d'un objet de type PlayerStd
*/
PlayerStd::PlayerStd(void)
{
	
}

/*!
* \fn PlayerStd* PlayerStd::PlayerStd_New()
* \brief Fonction de creation d'une nouvelle instance d'un objet PlayerStd d'apres les parametres
* \param Color c couleur du joueur
* \param Spaceship* &s vaisseau a attribuer au joueur
* \param int orbitalPosX abscisse de la station orbitale du joueur
* \param int orbitalPosY ordonnee de la station orbitale du joueur
* \return Instance nouvellement allouee d'un objet de type PlayerStd
*/
PlayerStd::PlayerStd(Color c,Spaceship* &s, int orbitalPosX, int orbitalPosY){
	color =c;
	spaceship = s;
	wonArtefacts = 0;
	orbitalStationPosX = orbitalPosX;
	orbitalStationPosY = orbitalPosY;

}

/*!
* \fn void PlayerStd::PlayerStd_Delete()
* \brief Fonction de destruction d'un objet PlayerStd
* \return
*/
PlayerStd::~PlayerStd(void)
{
}

/*!
* \fn void PlayerStd::winArtefact()
* \brief Ajoute un artefact a ceux deja ramasses
* \return
*/
void PlayerStd::winArtefact(){
	wonArtefacts ++;
}

/*!
* \fn Color PlayerStd::getColor()
* \brief Retourne la couleur du joueur
* \return Color couleur du joueur
*/
Color PlayerStd::getColor(){
	return color;
}

/*!
* \fn int PlayerStd::getPlayerPosX()
* \brief Retourne l'abcisse x du vaisseau du joueur
* \return int abcisse du vaisseau du joueur
*/
int PlayerStd::getPlayerPosX(){
	return spaceship->getPosX();
}

/*!
* \fn int PlayerStd::getPlayerPosY()
* \brief Retourne l'ordonnee y du vaisseau du joueur
* \return int ordonnee du vaisseau du joueur
*/
int PlayerStd::getPlayerPosY(){
	return spaceship->getPosY();
}

/*!
* \fn int PlayerStd::getNbArtefacts()
* \brief retourne le nombre d'artefacts ramasses par le joueur
* \return int ombre d'artefacts ramasses par le joueur
*/
int PlayerStd::getNbArtefacts(){
	return wonArtefacts;
}

/*!
* \fn bool PlayerStd::getPlayerPossesArtefact()
* \brief Indique si le vaisseau du joueur transporte ou non un artefact
* \return bool true si le vaisseau transporte un artefact, false sinon
*/
bool PlayerStd::getPlayerPossesArtefact(){
	return spaceship->hasArtefact();
}

/*!
* \fn int PlayerStd::getPlayerShotsRemaining()
* \brief Retourne le nombre de tirs restants du joueur
* \return int le nombre de tirs restants du joueur
*/
int PlayerStd::getPlayerShotsRemaining(){
	return spaceship->getShotsRemaining();
}

/*!
* \fn Spaceship* PlayerStd::getSpaceship()
* \brief Retourne le vaisseau du joueur
* \return Spaceship* pointeur sur le vaisseau du joueur
*/
Spaceship* PlayerStd::getSpaceship(){
	return spaceship;
}

/*!
* \fn bool PlayerStd::isOnHisOrbitalStation()
* \brief Indique si le vaisseau du joueur se trouve sur la meme case que sa station orbritale
* \return bool true si vaisseau sur station orbitale, false sinon
*/
bool PlayerStd::isOnHisOrbitalStation(){
	return (getPlayerPosX() == orbitalStationPosX) && (getPlayerPosY() == orbitalStationPosY);
}

/*!
* \fn void PlayerStd::restoreMothership()
* \brief remplace le vaisseau du joueur par un Mothership a la meme case
* \return
*/
void PlayerStd::restoreMothership(){
	int posx = spaceship->getPosX();
	int posy = spaceship->getPosY();
	delete spaceship;
	SpaceshipFactoryStd shipFact = SpaceshipFactoryStd();
	spaceship = shipFact.createMothership();
	spaceship->setPosX(posx);
	spaceship->setPosY(posy);
}

/*!
* \fn void PlayerStd::replaceSpaceship(Spaceship* newSpaceship)
* \brief remplace le vaisseau du joueur par newSpaceship
* \param Spaceship* newSpaceship le vaisseau qui remplace le vaisseau actuel
* \return
*/
void PlayerStd::replaceSpaceship(Spaceship* newSpaceship){
	delete spaceship;
	spaceship = newSpaceship;

}

EXTERNC DLL PlayerStd* PlayerStd_New(){return new PlayerStd();}
EXTERNC DLL void PlayerStd_Delete(PlayerStd* p){delete p;}
