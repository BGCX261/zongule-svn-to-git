#include "StdAfx.h"
#include "SpaceshipFactoryStd.h"
#include "BattlecruiserStd.h"
#include "MothershipStd.h"
#include "RescuecabStd.h"

/*!
* \fn SpaceshipFactoryStd::SpaceshipFactoryStd(void)
* \brief Fonction de creation d'une nouvelle instance d'un objet SpaceshipFactoryStd
* \return Instance nouvellement allouee d'un objet de type SpaceshipFactoryStd
*/
SpaceshipFactoryStd::SpaceshipFactoryStd(void)
{
}

/*!
* \fn SpaceshipFactoryStd::~SpaceshipFactoryStd(void)
* \brief Fonction de destructon d'un objet SpaceshipFactoryStd
* \return
*/
SpaceshipFactoryStd::~SpaceshipFactoryStd(void)
{
}

/*!
* \fn Spaceship* SpaceshipFactoryStd::createBattlecruiser()
* \brief creation d'un battlecruiser (monteur)
* \return Instance nouvellement allouee d'un objet de type BattlecruiserStd
*/
Spaceship* SpaceshipFactoryStd::createBattlecruiser(){
	return new BattlecruiserStd();
}

/*!
* \fn Spaceship* SpaceshipFactoryStd::createMothership()
* \brief creation d'un mothership (monteur)
* \return Instance nouvellement allouee d'un objet de type MothershipStd
*/
Spaceship* SpaceshipFactoryStd::createMothership(){
	return new MothershipStd();
}

/*!
* \fn Spaceship* SpaceshipFactoryStd::createRescuecab()
* \brief creation d'une rescuecab (monteur)
* \return Instance nouvellement allouee d'un objet de type RescuecabStd
*/
Spaceship* SpaceshipFactoryStd::createRescuecab(){
	return new RescuecabStd();
}

/*!
* \fn Spaceship* SpaceshipFactoryStd::createNextSpaceship(Spaceship* s)
* \brief remplace le vaisseau par le vaisseau downgrade
* \param Spaceship* s le vaisseau a remplacer
* \return Instance nouvellement allouee d'un objet de type Spaceship
*/
Spaceship* SpaceshipFactoryStd::createNextSpaceship(Spaceship* s){
	Spaceship* newSpaceship;
	bool hasArt = s->hasArtefact();
	int posx = s->getPosX();
	int posy = s->getPosY();
	SpaceshipType type = s->getType();
	if (type == MothershipType) {
		newSpaceship = createBattlecruiser();
		if (hasArt) newSpaceship->takeArtefact();
		newSpaceship->setPosX(posx);
		newSpaceship->setPosY(posy);
	}
	else if (type == BattlecruiserType) {
		newSpaceship = createRescuecab();
		//if (hasArt) newSpaceship->takeArtefact();
		newSpaceship->setPosX(posx);
		newSpaceship->setPosY(posy);
	}
	else{
		newSpaceship = createMothership();
	}
	return newSpaceship;	
}