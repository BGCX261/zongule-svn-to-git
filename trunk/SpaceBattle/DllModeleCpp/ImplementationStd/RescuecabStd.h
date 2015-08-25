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
#include "..\Abstrait\Rescuecab.h"

/*! \class RescuecabStd
* \implements Rescuecab
* \brief classe implementant Rescuecab, representant un vaisseau de type Rescuecab
*
*/
class DLL RescuecabStd : public Rescuecab
{
	public:
		RescuecabStd(void);
		~RescuecabStd(void);
		void printType();
		SpaceshipType getType();
};

EXTERNC DLL RescuecabStd* RescuecabStd_New();
EXTERNC DLL void RescuecabStd_Delete(RescuecabStd* a);
