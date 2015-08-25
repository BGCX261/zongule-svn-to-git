#pragma once
#include "..\Abstrait\SquareFactory.h"
#include "..\Abstrait\EmptySquare.h"
#include "..\Abstrait\EnergyStationSquare.h"
#include "..\Abstrait\ArtefactSquare.h"
#include "ArtefactSquareStd.h"
#include "AsteroidSquareStd.h"
#include "EmptySquareStd.h"
#include "OrbitalStationSquareStd.h"
#include "EnergyStationSquareStd.h"


	/*! \class SquareFactoryStd
	* \implements SquareFactory
	* \brief Implementation de SquareFactory, le monteur de cases
	*/

class SquareFactoryStd : public SquareFactory
{
private:
	EmptySquare* refEmpty;	/*!< pointeur sur case vide*/
	EnergyStationSquare* refEnergyStation;	/*!< pointeur case energie*/
	ArtefactSquare* refArtefact;	/*!< pointeur sur case artefact*/

public:
	SquareFactoryStd(void);
	~SquareFactoryStd(void);

	Square* createArtefactSquare();
	Square* createAsteroidSquare();
	Square* createOrbitalStationSquare();
	Square* createEnergyStationSquare();
	Square* createEmptySquare();
};

EXTERNC DLL SquareFactoryStd* SquareFactoryStd_New();
EXTERNC DLL void SquareFactoryStd_Delete(SquareFactoryStd* m);
