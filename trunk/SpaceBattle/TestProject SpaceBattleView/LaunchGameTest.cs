using SpaceBattleView;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using System;
using System.Collections.Generic;

namespace TestProject_SpaceBattleView
{
    
    
    /// <summary>
    ///Classe de test pour AppTest, destinee a contenir tous
    ///les tests unitaires AppTest
    ///</summary>
    [TestClass()]
    public class LaunchGameTest
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
        ///Test pour launchGame
        ///</summary>
        [TestMethod()]
        public void launchGameTest()
        {
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
            int nbArtefact = 3; // TODO: initialisez a une valeur appropriee
            string mapFilename = string.Empty; // TODO: initialisez a une valeur appropriee
            bool expected = false; // TODO: initialisez a une valeur appropriee
            bool actual;
            actual = App.launchGame(colorList, teamList, nbArtefact, mapFilename);
            Assert.AreEqual(expected, actual);
            Assert.Inconclusive("Test avec nom de la map vide");
            mapFilename = "lsdjklskjdf/oizlj.txt";
            actual = App.launchGame(colorList, teamList, nbArtefact, mapFilename);
            Assert.AreEqual(expected, actual);
            Assert.Inconclusive("Test avec nom de la map mauvais");
            mapFilename = "map.txt";
            Assert.AreEqual(expected, actual);
            Assert.Inconclusive("Test avec bon nom de la map");
        }
    }
}
