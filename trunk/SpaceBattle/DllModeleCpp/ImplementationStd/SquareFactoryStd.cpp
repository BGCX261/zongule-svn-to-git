#include "StdAfx.h"
#include "SquareFactoryStd.h"


/*!
* \fn SquareFactoryStd::SquareFactoryStd(void)
* \brief Fonction de creation d'une nouvelle instance d'un objet SquareFactoryStd
* \return Instance nouvellement allouee d'un objet de type SquareFactoryStd
*/
SquareFactoryStd::SquareFactoryStd(void)
{
	refEmpty = 0;
	refEnergyStation = 0;
	refArtefact = 0;
}

/*!
* \fn SquareFactoryStd::~SquareFactoryStd(void)
* \brief Fonction de destructon d'un objet SquareFactoryStd
* \return
*/
SquareFactoryStd::~SquareFactoryStd(void)
{
	delete refEmpty;
	delete refEnergyStation;
	delete refArtefact;
}

/*!
* \fn Square* SquareFactoryStd::createArtefactSquare()
* \brief Fonction qui cree et renvoie une case artefact (Builder)
* \return Square* Instance nouvellement allouee d'un objet de type ArtefactSquareStd
*/
Square* SquareFactoryStd::createArtefactSquare(){
	if (refArtefact == 0) refArtefact = new ArtefactSquareStd();
	return refArtefact;
}

/*!
* \fn Square* SquareFactoryStd::createAsteroidSquare()
* \brief Fonction qui cree et renvoie une case asteroid (Builder)
* \return Square* Instance nouvellement allouee d'un objet de type AsteroidSquareStd
*/
Square* SquareFactoryStd::createAsteroidSquare(){
	return new AsteroidSquareStd();
}

/*!
* \fn Square* SquareFactoryStd::createOrbitalStationSquare()
* \brief Fonction qui cree et renvoie une case station orbitale (Builder)
* \return Square* Instance nouvellement allouee d'un objet de type OrbitalStationSquareStd
*/ 
Square* SquareFactoryStd::createOrbitalStationSquare(){
	return new OrbitalStationSquareStd();
}

/*!
* \fn Square* SquareFactoryStd::createEnergyStationSquare()
* \brief Fonction qui cree et renvoie une case energie (Builder)
* \return Square* Instance nouvellement allouee d'un objet de type EnergyStationSquareStd
*/ 
Square* SquareFactoryStd::createEnergyStationSquare(){
	if (refEnergyStation == 0) refEnergyStation = new EnergyStationSquareStd();
	return refEnergyStation;
}

/*!
* \fn Square* SquareFactoryStd::createEmptySquare()
* \brief Fonction qui cree et renvoie une case vide (Builder)
* \return Square* Instance nouvellement allouee d'un objet de type EmptySquareStd
*/ 
Square* SquareFactoryStd::createEmptySquare(){
	if (refEmpty == 0) refEmpty = new EmptySquareStd();
	return refEmpty;
}

EXTERNC DLL SquareFactoryStd* SquareFactoryStd_New(){return new SquareFactoryStd();}
EXTERNC DLL void SquareFactoryStd_Delete(SquareFactoryStd* m){delete m;}