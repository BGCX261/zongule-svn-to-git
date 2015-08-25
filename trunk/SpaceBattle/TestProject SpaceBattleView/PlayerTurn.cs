using SpaceBattleView;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using System;
using System.Collections.Generic;

namespace TestProject_SpaceBattleView
{
    
    
    /// <summary>
    ///Classe de test pour MainGameTest, destinee a contenir tous
    ///les tests unitaires MainGameTest
    ///</summary>
    [TestClass()]
    public class PlayerTurn
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
        ///Test pour passTurn
        ///</summary>
        [TestMethod()]
        public void passTurnTest()
        {
            MainGame target = new MainGame(); // TODO: initialisez a une valeur appropriee
            target.passTurn();
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
            App.wrapper.createGame(3, 3, colorList, teamList, "map.txt");
            int player = App.wrapper.getCurrentPlayer();
            Assert.AreEqual(player, 0);
            Assert.Inconclusive("num premier joueur");
            target.passTurn();
            player = App.wrapper.getCurrentPlayer();
            Assert.AreEqual(player, 1);
            Assert.Inconclusive("num deuxieme joueur");
        }

        /// <summary>
        ///Test pour ShowCurrentPlayer
        ///</summary>
        [TestMethod()]
        [DeploymentItem("SpaceBattleView.exe")]
        public void ShowCurrentPlayerTest()
        {
            MainGame_Accessor target = new MainGame_Accessor(); // TODO: initialisez a une valeur appropriee
            target.passTurn();
            target.ShowCurrentPlayer();
            Assert.Inconclusive("Joueur courant = premier joueur");
        }
    }
}
