#pragma once
#include "..\DllModeleCpp\Abstrait\Spaceship.h"
#include "..\DllModeleCpp\Abstrait\Battlecruiser.h"
#include "..\DllModeleCpp\Abstrait\Mothership.h"
#include "..\DllModeleCpp\Abstrait\Rescuecab.h"
#include "..\DllModeleCpp\ImplementationStd\BattlecruiserStd.h"
#include "..\DllModeleCpp\ImplementationStd\RescuecabStd.h"
#include "..\DllModeleCpp\ImplementationStd\MothershipStd.h"
#include "..\DllModeleCpp\Abstrait\SpaceshipFactory.h"
#include "..\DllModeleCpp\ImplementationStd\SpaceshipFactoryStd.h"

class TestsSpaceship
{
public:
	TestsSpaceship(void);
	~TestsSpaceship(void);
	void run();
};

