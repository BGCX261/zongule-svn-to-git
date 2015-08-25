using SpaceBattleView;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using System;
using System.Collections.Generic


namespace TestProject_SpaceBattleView
{
    
    
    /// <summary>
    ///Classe de test pour GameDicesViewTest, destinee a contenir tous
    ///les tests unitaires GameDicesViewTest
    ///</summary>
    [TestClass()]
    public class GameDicesViewTest
    {


        private TestContext testContextInstance;

        /// <summary>
        ///Obtient ou definit le contexte de test qui fournit
        ///des informations sur la serie de tests active ainsi que ses fonctionnalites.
        ///</summary>
        public TestContext TestContext
        {
            get
            {
                return testContextInstance;
            }
            set
            {
                testContextInstance = value;
            }
        }

        #region Attributs de tests supplementaires
        // 
        //Vous pouvez utiliser les attributs supplementaires suivants lorsque vous ecrivez vos tests :
        //
        //Utilisez ClassInitialize pour executer du code avant d'executer le premier test dans la classe
        //[ClassInitialize()]
        //public static void MyClassInitialize(TestContext testContext)
        //{
        //}
        //
        //Utilisez ClassCleanup pour executer du code apres que tous les tests ont ete executes dans une classe
        //[ClassCleanup()]
        //public static void MyClassCleanup()
        //{
        //}
        //
        //Utilisez TestInitialize pour executer du code avant d'executer chaque test
        //[TestInitialize()]
        //public void MyTestInitialize()
        //{
        //}
        //
        //Utilisez TestCleanup pour executer du code apres que chaque test a ete execute
        //[TestCleanup()]
        //public void MyTestCleanup()
        //{
        //}
        //
        #endregion


        /// <summary>
        ///Test pour update
        ///</summary>
        [TestMethod()]
        public void updateTest()
        {
            MainGame m = new MainGame(); // TODO: initialisez a une valeur appropriee
            GameDicesView target = new GameDicesView(m); // TODO: initialisez a une valeur appropriee
            target.update();
            
        }

        /// <summary>
        ///Test pour getD2
        ///</summary>
        [TestMethod()]
        public void getD2Test()
        {
            App app = new App();
            MainGame m = new MainGame(); // TODO: initialisez a une valeur appropriee
             List<int> colorList = new List<int>(); // TODO: initialisez a une valeur appropriee
            colorList.Add(1);
            colorList.Add(2);
            colorList.Add(3);
            colorList.Add(4);
            List<int> teamList = new List<int>();
            teamList.Add(1);
            teamList.Add(2);
            teamList.Add(3);
            teamList.Add(4);
            App.wrapper.createGame(3, 3, colorList, teamList,"map.txt");
            GameDicesView target = new GameDicesView(m); // TODO: initialisez a une valeur appropriee
            int expected = 0; 
            int actual;
            actual = target.getD2();
            Assert.AreEqual(expected, actual);
            Assert.Inconclusive("Test d2: 0");
            App.dicesWrapper.rollSecondDice();
            actual = target.getD2();
            Assert.AreNotEqual(actual,0);
            Assert.Inconclusive("Test d2: random");
        }

        /// <summary>
        ///Test pour getD1
        ///</summary>
        [TestMethod()]
        public void getD1Test()
        {
           App app = new App();
            MainGame m = new MainGame(); // TODO: initialisez a une valeur appropriee
             List<int> colorList = new List<int>(); // TODO: initialisez a une valeur appropriee
            colorList.Add(1);
            colorList.Add(2);
            colorList.Add(3);
            colorList.Add(4);
            List<int> teamList = new List<int>();
            teamList.Add(1);
            teamList.Add(2);
            teamList.Add(3);
            teamList.Add(4);
            App.wrapper.createGame(3, 3, colorList, teamList,"map.txt");
            GameDicesView target = new GameDicesView(m); // TODO: initialisez a une valeur appropriee
            int expected = 0; 
            int actual;
            actual = target.getD1();
            Assert.AreEqual(expected, actual);
            Assert.Inconclusive("Test d1: 0");
            App.dicesWrapper.rollSecondDice();
            actual = target.getD1();
            Assert.AreNotEqual(actual,0);
            Assert.Inconclusive("Test d1: random");
        }

        /// <summary>
        ///Test pour getBoth
        ///</summary>
        [TestMethod()]
        public void getBothTest()
        {
           App app = new App();
            MainGame m = new MainGame(); // TODO: initialisez a une valeur appropriee
             List<int> colorList = new List<int>(); // TODO: initialisez a une valeur appropriee
            colorList.Add(1);
            colorList.Add(2);
            colorList.Add(3);
            colorList.Add(4);
            List<int> teamList = new List<int>();
            teamList.Add(1);
            teamList.Add(2);
            teamList.Add(3);
            teamList.Add(4);
            App.wrapper.createGame(3, 3, colorList, teamList,"map.txt");
            GameDicesView target = new GameDicesView(m); // TODO: initialisez a une valeur appropriee
            int expected = 0; 
            int actual;
            actual = target.getBoth();
            Assert.AreEqual(expected, actual);
            Assert.Inconclusive("Test both: 0");
            App.dicesWrapper.rollSecondDice();
            actual = target.getBoth();
            Assert.AreNotEqual(actual,0);
            Assert.Inconclusive("Test both: random");
        }

        /// <summary>
        ///Test pour Constructeur GameDicesView
        ///</summary>
        [TestMethod()]
        public void GameDicesViewConstructorTest()
        {
            MainGame m = null; // TODO: initialisez a une valeur appropriee
            GameDicesView target = new GameDicesView(m);
            Assert.Inconclusive("TODO: implementez le code pour verifier la cible");
        }

        /// <summary>
        ///Test pour updateRadio
        ///</summary>
        [TestMethod()]
        public void updateRadioTest()
        {
            MainGame m = null; // TODO: initialisez a une valeur appropriee
            GameDicesView target = new GameDicesView(m); // TODO: initialisez a une valeur appropriee
            target.updateRadio();
            Assert.Inconclusive("Une methode qui ne retourne pas une valeur ne peut pas etre verifiee.");
        }
    }
}
