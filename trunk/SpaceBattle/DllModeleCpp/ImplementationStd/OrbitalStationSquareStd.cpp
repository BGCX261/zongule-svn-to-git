#include "StdAfx.h"
#include "OrbitalStationSquareStd.h"

/*!
* \fn OrbitalStationSquareStd* OrbitalStationSquareStd::OrbitalStationSquareStd(void)
* \brief Fonction de creation d'une nouvelle instance d'un objet OrbitalStationSquareStd
* \return Instance nouvellement allouee d'un objet de type OrbitalStationSquareStd
*/
OrbitalStationSquareStd::OrbitalStationSquareStd(void)
{
}

/*!
* \fn bool OrbitalStationSquareStd::isAccessible()
* \brief Indique si la case est accessible
* \return true
*/
bool OrbitalStationSquareStd::isAccessible(){
	return true;
}

/*!
* \fn void OrbitalStationSquareStd::printConsole()
* \brief Affiche en console la case (utilise pour les tests)
* \return
*/
void OrbitalStationSquareStd::printConsole(){
	std::cout << "O";
}
  
/*!
* \fn SquareType OrbitalStationSquareStd::getType()
* \brief permet de connaitre le type de la case (types decrits dans l'enum de Square.h)
* \return EnergyStationSquareType
*/
SquareType OrbitalStationSquareStd::getType(){
	return OrbitalStationSquareType;
}

/*!
* \fn void OrbitalStationSquareStd::doAction()
* \brief realise l'action necessaire lorsque le joueur p arrive sur cette case
* \param Player* p
* \return
*/
void OrbitalStationSquareStd::doAction(Player* p){
	Spaceship* s = p->getSpaceship();
	if(p->isOnHisOrbitalStation()){
		if (s->hasArtefact()) {
			s->depositArtefact();	
			p->winArtefact();
		}
		p->restoreMothership();
	}
}


EXTERNC DLL OrbitalStationSquareStd* OrbitalStationSquareStd_New(){return new OrbitalStationSquareStd();}
EXTERNC DLL void OrbitalStationSquareStd_Delete(OrbitalStationSquareStd* e){delete e;}
