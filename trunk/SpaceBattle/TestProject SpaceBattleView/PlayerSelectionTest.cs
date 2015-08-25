using SpaceBattleView;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using System;

namespace TestProject_SpaceBattleView
{
    
    
    /// <summary>
    ///Classe de test pour PlayerSelectionTest, destinee a contenir tous
    ///les tests unitaires PlayerSelectionTest
    ///</summary>
    [TestClass()]
    public class PlayerSelectionTest
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
        ///Test pour checkDicesRolled
        ///</summary>
        [TestMethod()]
        [DeploymentItem("SpaceBattleView.exe")]
        public void checkDicesRolledTest()
        {
            PlayerSelection_Accessor target = new PlayerSelection_Accessor(); 
            bool expected = false; 
            bool actual;
            actual = target.checkDicesRolled();
            Assert.AreEqual(expected, actual);
            Assert.Inconclusive("Test no dices rolled");
            target.textBlockDicesP1.Text = 5.ToString();
            target.textBlockDicesP2.Text = 12.ToString();
            actual = target.checkDicesRolled();
            expected = true;
            Assert.AreEqual(expected, actual);
            Assert.Inconclusive("Test 2 dices rolled");
            target.textBlockDicesP3.Text = 5.ToString();
            target.textBlockDicesP4.Text = 12.ToString();
            actual = target.checkDicesRolled();
            expected = true;
            Assert.AreEqual(expected, actual);
            Assert.Inconclusive("Test 4 dices rolled");       
        }

        /// <summary>
        ///Test pour checkColorChoice
        ///</summary>
        [TestMethod()]
        [DeploymentItem("SpaceBattleView.exe")]
        public void checkColorChoiceTest()
        {
            PlayerSelection_Accessor target = new PlayerSelection_Accessor(); // TODO: initialisez a une valeur appropriee
            bool expected = true; // TODO: initialisez a une valeur appropriee
            bool actual;
            actual = target.checkColorChoice();
            Assert.AreEqual(expected, actual);
            Assert.Inconclusive("Test deux joueurs deux couleurs diff");
            target.comboBoxColor2.SelectedIndex = target.comboBoxColor2.SelectedIndex;
            expected = false;
            actual = target.checkColorChoice();
            Assert.AreEqual(expected, actual);
            Assert.Inconclusive("Test deux premiers joueurs deux couleurs egales");
        }
    }
}
