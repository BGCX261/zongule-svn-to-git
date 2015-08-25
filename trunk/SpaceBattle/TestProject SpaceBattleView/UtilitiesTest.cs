using SpaceBattleView;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using System;

namespace TestProject_SpaceBattleView
{
    
    
    /// <summary>
    ///Classe de test pour UtilitiesTest, destinee a contenir tous
    ///les tests unitaires UtilitiesTest
    ///</summary>
    [TestClass()]
    public class UtilitiesTest
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
        ///Test pour colorTypeToString
        ///</summary>
        [TestMethod()]
        public void colorTypeToStringTest()
        {
            Utilities.GameColors i = new Utilities.GameColors();
            i = Utilities.GameColors.Blue;
            string expected = "Blue"; // TODO: initialisez a une valeur appropriee
            string actual;
            actual = Utilities.colorTypeToString(i);
            Assert.AreEqual(expected, actual);
            Assert.Inconclusive("color blue");
            i = Utilities.GameColors.Red;
            actual = Utilities.colorTypeToString(i);
            Assert.AreEqual(expected, actual);
            Assert.Inconclusive("color red");

        }
    }
}
