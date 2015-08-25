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
#include "..\Abstrait\Mothership.h"

/*! \class MothershipStd
* \implements Mothership
* \brief classe implementant Mothership, representant un vaisseau de type Mothership
*
*/
class DLL MothershipStd : public Mothership
{
	public:
		MothershipStd(void);
		~MothershipStd(void);
		void printType();
		SpaceshipType getType();
};

EXTERNC DLL MothershipStd* MothershipStd_New();
EXTERNC DLL void MothershipStd_Delete(MothershipStd* a);
