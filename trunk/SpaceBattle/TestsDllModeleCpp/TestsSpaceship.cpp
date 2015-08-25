#include "TestsSpaceship.h"


TestsSpaceship::TestsSpaceship(void)
{
}


TestsSpaceship::~TestsSpaceship(void)
{
}

void TestsSpaceship::run(){
	//test
	SpaceshipFactory * factory = new SpaceshipFactoryStd();
	Spaceship * ship1 =  factory->createBattlecruiser();
	Spaceship * ship2 =  factory->createMothership();

	Spaceship * ship3 =  factory->createRescuecab();
	ship3->printConsole();

	//ship3 = factory->createNextSpaceship();
}
