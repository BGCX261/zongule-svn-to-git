#include "StdAfx.h"
#include "..\Abstrait\Spaceship.h"
#include <iostream>

/*!
* \fn Spaceship::Spaceship(void)
* \brief Fonction de creation d'une nouvelle instance d'un objet Spaceship
*
* \return Instance nouvellement allouee d'un objet de type Spaceship
*/
Spaceship::Spaceship(void)
{
	posx=0;
	posy=0;
	diceNumber = 2;
	remainingShotsNumber = 0;
	maxShotsNumber = 3;
	reboundNumber = 5;
	possesArtefact = false;
}

/*!
* \fn Spaceship::~Spaceship(void)
* \brief Fonction de destruction d'objet Spaceship
*
* \return
*/
Spaceship::~Spaceship(void)
{
}

/*!
* \fn void Spaceship::takeArtefact()
* \brief passe l'attribut possesArtefact a true
*
* \return
*/
void Spaceship::takeArtefact(){
	possesArtefact = true;
}

/*!
* \fn bool Spaceship::hasArtefact()
* \brief indique si le vaisseau transporte (ou non) un artefact
*
* \return possesArtefact
*/
bool Spaceship::hasArtefact(){
	return possesArtefact;
}

/*!
* \fn void Spaceship::chargeLaser()
* \brief charge le nombre de tirs au maximum
*
* \return
*/
void Spaceship::chargeLaser(){
	remainingShotsNumber = maxShotsNumber;
}

/*!
* \fn void Spaceship::depositArtefact()
* \brief passe possesArtefact a false (depose l'artefact a la base)
*
* \return
*/
void Spaceship::depositArtefact(){
	possesArtefact = false;
}

/*!
* \fn void Spaceship::printType()
* \brief Affiche en console le type de vaisseau (utilise pour les tests)
* \return
*/
void Spaceship::printType(){
	std::cout << "Spaceship";
}

/*!
* \fn void Spaceship::printConsole()
* \brief Affiche en console le vaisseau et ses attributs (utilise pour les tests)
* \return
*/
void Spaceship::printConsole(){
	std::cout << "Affichage du vaisseau" << std::endl;
	std::cout << "-Type :";
		printType();
		std::cout << std::endl;

	std::cout << "-RemainingShotsNumber : " << remainingShotsNumber << std::endl;

	std::cout << "-ReboundNumber : " << reboundNumber << std::endl;
	std::cout << "-Artefact : " << hasArtefact() << std::endl;
}

/*!
* \fn int Spaceship::getPosX()
* \brief retourne l'abcisse du vaisseau
* \return posx
*/
int Spaceship::getPosX(){
	return posx;
}

/*!
* \fn int Spaceship::getPosY()
* \brief retourne l'ordonnee du vaisseau
* \return posy
*/
int Spaceship::getPosY(){
	return posy;
}

/*!
* \fn void Spaceship::setPosX(int x)
* \brief change l'abcisse du vaisseau par x
* \param int x
* \return
*/
void Spaceship::setPosX(int x){
	posx = x;
}

/*!
* \fn void Spaceship::setPosY(int y)
* \brief change l'ordonnee du vaisseau par y
* \param int y
* \return
*/
void Spaceship::setPosY(int y){
	posy = y;
}

/*!
* \fn int Spaceship::getShotsRemaining()
* \brief retourne le nombre de tirs restants
* \return remainingShotsNumber
*/
int Spaceship::getShotsRemaining(){
	return remainingShotsNumber;
}

/*!
* \fn int Spaceship::getReboundNumber()
* \brief retourne le nombre de rebonds
* \return reboundNumber
*/
int Spaceship::getReboundNumber(){
	return reboundNumber;
}

/*!
* \fn int Spaceship::move(int x,int y)
* \brief change les coordonnees du vaisseau par x et y
* \param int x
* \param int y
* \return
*/
void Spaceship::move(int x,int y){
	posx = x;
	posy = y;
}

/*!
* \fn void Spaceship::decreaseShotsRemaining()
* \brief diminue d'1 le nombre de tirs restants
* \return
*/
void Spaceship::decreaseShotsRemaining(){
	if (remainingShotsNumber>0) remainingShotsNumber--;
}

/*!
* \fn Spaceship::bool canShoot()
* \brief indique si le vaisseau peut tirer ou non
* \return true si remainingShotsNumber>0, faux sinon
*/
bool Spaceship::canShoot(){
	return remainingShotsNumber>0;
}