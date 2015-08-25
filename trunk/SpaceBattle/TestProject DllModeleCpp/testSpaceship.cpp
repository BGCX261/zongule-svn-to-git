#include "stdafx.h"
#include "assert.h"
#include "Mothership.h"
#include "MothershipStd.h"
#include "Battlecruiser.h"
#include "BattlecruiserStd.h"
#include "Spaceship.h"
#include "SpaceshipFactory.h"
#include "SpaceshipFactoryStd.h"
#include "Rescuecab.h"
#include "RescuecabStd.h"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace TestProjectDllModeleCpp
{
		
	[TestClass]
	public ref class UnitTest1
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
			Spaceship* m = new MothershipStd();
			m->takeArtefact();
			bool resAttendu = true;
			assert(m->hasArtefact() == resAttendu);

			delete m;
		};

		[TestMethod]
		void TestMethod2()
		{
			Spaceship* m = new MothershipStd();
			m->takeArtefact();
			m->depositArtefact();
			bool resAttendu = false;
			assert(m->hasArtefact() == resAttendu);

			delete m;
		};

		[TestMethod]
		void TestMethod3()
		{
			Spaceship* m = new MothershipStd();
			m->setPosX(3);
			m->setPosY(4);

			m->move(5,6);
			int xAttendu = 5;
			int yAttendu = 6;
			assert((m->getPosX()==5) && (m->getPosY()==6));

			delete m;
		};

		[TestMethod]
		void TestMethod4()
		{
			SpaceshipFactory* factory = new SpaceshipFactoryStd();
			Spaceship* ship = factory->createBattlecruiser();

			Spaceship* ship2 = factory->createNextSpaceship(ship);
			Spaceship* m = new MothershipStd();
			SpaceshipType type = ship2->getType();
			SpaceshipType typeM = m->getType();

			bool resAttendu = false;
			assert(m->hasArtefact() == resAttendu);

			delete factory;
			delete ship;
			delete ship2;
			delete m;
		};
	};
}
