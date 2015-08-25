using System;
using System.Collections.Generic;
using System.Text.RegularExpressions;
using System.Windows.Input;
using System.Windows.Forms;
using System.Drawing;
using Microsoft.VisualStudio.TestTools.UITesting;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using Microsoft.VisualStudio.TestTools.UITest.Extension;
using Keyboard = Microsoft.VisualStudio.TestTools.UITesting.Keyboard;


namespace TestProject_SpaceBattleView
{
    /// <summary>
    /// Description resumee pour CodedUITest
    /// </summary>
    [CodedUITest]
    public class ClicInterfaceJeu
    {
        public ClicInterfaceJeu()
        {
        }

        [TestMethod]
        public void CodedUITestMethod1()
        {
            // Pour generer le code de ce test, selectionnez "Generer le code pour le test code de l'interface utilisateur" dans le menu contextuel et selectionnez un des elements de menu.
            // Pour plus d'informations sur le code genere, consultez http://go.microsoft.com/fwlink/?LinkId=179463
            this.UIMap.TestInterfaceStandard();
        }

        #region Attributs de tests supplementaires

        // Vous pouvez utiliser les attributs supplementaires suivants lorsque vous ecrivez vos tests :

        ////Utilisez TestInitialize pour executer du code avant d'executer chaque test 
        //[TestInitialize()]
        //public void MyTestInitialize()
        //{        
        //    // Pour generer le code de ce test, selectionnez "Generer le code pour le test code de l'interface utilisateur" dans le menu contextuel et selectionnez un des elements de menu.
        //    // Pour plus d'informations sur le code genere, consultez http://go.microsoft.com/fwlink/?LinkId=179463
        //}

        ////Utilisez TestCleanup pour executer du code apres que chaque test a ete execute
        //[TestCleanup()]
        //public void MyTestCleanup()
        //{        
        //    // Pour generer le code de ce test, selectionnez "Generer le code pour le test code de l'interface utilisateur" dans le menu contextuel et selectionnez un des elements de menu.
        //    // Pour plus d'informations sur le code genere, consultez http://go.microsoft.com/fwlink/?LinkId=179463
        //}

        #endregion

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
        private TestContext testContextInstance;

        public UIMap UIMap
        {
            get
            {
                if ((this.map == null))
                {
                    this.map = new UIMap();
                }

                return this.map;
            }
        }

        private UIMap map;
    }
}
