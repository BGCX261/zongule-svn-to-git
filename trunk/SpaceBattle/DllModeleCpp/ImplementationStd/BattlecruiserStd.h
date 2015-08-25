#pragma once
#define WANTDLLEXP
#ifdef WANTDLLEXP		//exportation dll
#define DLL  __declspec( dllexport )
#define EXTERNC extern "C"
#else
#define DLL		//standard
#define EXTERNC
#endif
#include<vector>
#include "..\Abstrait\Battlecruiser.h"

/*! \class BattlecruiserStd
* \implements Battlecruiser
* \brief classe implementant Battlecruiser, representant un vaisseau de type Battlecruiser
*
*/
class DLL BattlecruiserStd : public Battlecruiser
{
	public:
		BattlecruiserStd(void);
		~BattlecruiserStd(void);
		void printType();
		SpaceshipType getType();
};

EXTERNC DLL BattlecruiserStd* BattlecruiserStd_New();
EXTERNC DLL void BattlecruiserStd_Delete(BattlecruiserStd* a);