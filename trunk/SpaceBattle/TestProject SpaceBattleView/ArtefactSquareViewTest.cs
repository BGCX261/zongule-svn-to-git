using SpaceBattleView;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using System;

namespace TestProject_SpaceBattleView
{
    
    
    /// <summary>
    ///Classe de test pour ArtefactSquareViewTest, destinee a contenir tous
    ///les tests unitaires ArtefactSquareViewTest
    ///</summary>
    [TestClass()]
    public class ArtefactSquareViewTest
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
        ///Test pour setAccessible
        ///</summary>
        [TestMethod()]
        public void setAccessibleTest()
        {
            MainGame m = new MainGame(); // TODO: initialisez a une valeur appropriee
            ArtefactSquareView target = new ArtefactSquareView(m); // TODO: initialisez a une valeur appropriee
            bool acc = target.isAccessible;
            Assert.AreEqual(acc, false);
            Assert.Inconclusive("case accessible");
            target.setAccessible();
            acc = target.isAccessible;
            Assert.AreEqual(acc, true);
            Assert.Inconclusive("case accessible");
            target.setAccessible();
            acc = target.isAccessible;
            Assert.AreEqual(acc, true);
            Assert.Inconclusive("case accessible");
        }

        /// <summary>
        ///Test pour unsetAccessible
        ///</summary>
        [TestMethod()]
        public void unsetAccessibleTest()
        {
            MainGame m = new MainGame(); // TODO: initialisez a une valeur appropriee
            ArtefactSquareView target = new ArtefactSquareView(m); // TODO: initialisez a une valeur appropriee
            bool acc = target.isAccessible;
            Assert.AreEqual(acc, false);
            Assert.Inconclusive("case non accessible");
            target.unsetAccessible();
            acc = target.isAccessible;
            Assert.AreEqual(acc, true);
            Assert.Inconclusive("case non accessible");
        }
    }
}
