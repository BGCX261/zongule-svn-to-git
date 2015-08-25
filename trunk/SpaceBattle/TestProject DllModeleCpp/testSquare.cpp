#include "stdafx.h"
#include "assert.h"
#include "Square.h"
#include "ArtefactSquare.h"
#include "ArtefactSquareStd.h"
#include "AsteroidSquare.h"
#include "AsteroidSquareStd.h"
#include "EmptySquare.h"
#include "EmptySquareStd.h"
#include "OrbitalStationSquare.h"
#include "OrbitalStationSquareStd.h"
#include "SpaceshipFactory.h"
#include "SpaceshipFactoryStd.h"
#include "Player.h"
#include "PlayerStd.h"
#include "Mothership.h"
#include "MothershipStd.h"
#include "Battlecruiser.h"
#include "BattlecruiserStd.h"
#include "Spaceship.h"
#include "SpaceshipFactory.h"
#include "SpaceshipFactoryStd.h"
#include "Rescuecab.h"
#include "RescuecabStd.h"
#include "EnergyStationSquare.h"
#include "EnergyStationSquareStd.h"
#include "SquareFactory.h"
#include "SquareFactoryStd.h"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace TestProjectDllModeleCpp
{
	[TestClass]
	public ref class testSquare
	{
	private:
		TestContext^ testContextInstance;

	public: 
		/// <summary>
		///Obtient ou definit le contexte de test qui fournit
		///des informations sur la serie de tests active ainsi que ses fonctionnalites.
		///</summary>
		property Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ TestContext
		{
			Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ get()
			{
				return testContextInstance;
			}
			System::Void set(Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ value)
			{
				testContextInstance = value;
			}
		};

		#pragma region Additional test attributes
		//
		//Vous pouvez utiliser les attributs supplementaires suivants lorsque vous ecrivez vos tests :
		//
		//Utilisez ClassInitialize pour executer du code avant d'executer le premier test de la classe
		//[ClassInitialize()]
		//static void MyClassInitialize(TestContext^ testContext) {};
		//
		//Utilisez ClassCleanup pour executer du code une fois que tous les tests d'une classe ont ete executes
		//[ClassCleanup()]
		//static void MyClassCleanup() {};
		//
		//Utilisez TestInitialize pour executer du code avant d'executer chaque test
		//[TestInitialize()]
		//void MyTestInitialize() {};
		//
		//Utilisez TestCleanup pour executer du code apres que chaque test a ete execute
		//[TestCleanup()]
		//void MyTestCleanup() {};
		//
		#pragma endregion 

		[TestMethod]
		void TestMethod1()
		{
			Square* ess = new EnergyStationSquareStd();
			Spaceship* m = new MothershipStd();
			Player* p = new PlayerStd(Red,m,1,2);

			ess->doAction(p);
			
			int shots = p->getSpaceship()->getShotsRemaining();
			assert(shots ==3);

			delete ess;
			delete m;
			delete p;
		};

		[TestMethod]
		void TestMethod2()
		{
			Square* ess = new OrbitalStationSquareStd();
			Spaceship* m = new MothershipStd();
			m->setPosX(1);
			m->setPosY(2);
			m->takeArtefact();
			Player* p = new PlayerStd(Red,m,1,2);

			ess->doAction(p);
			
			bool resAttendu = false;
			assert(m->hasArtefact() == resAttendu);

			delete ess;
			delete m;
			delete p;
		};
	};
}
