using System;
using System.Collections.Generic;
using System.Configuration;
using System.Data;
using System.Linq;
using System.Windows;
using mWrapper;

namespace SpaceBattleView
{
    /*! \class App
     *  \implements Application
     * \brief classe principale de l'application, chargee du lancement et de la fin du jeu
     */
    public partial class App : Application
    {
        public static int nbPlayers = 2;   /*!< Nombre de joueurs */
        public static WrapperGameManager wrapper = new WrapperGameManager(); /*!< Reference vers le wrapper du jeu */
        public static WrapperDices dicesWrapper = new WrapperDices(); /*!< Reference vers le wrapper des des */
        public static MainGame mainGameWnd; /*!< Reference vers la fenetre de jeu */


        /*! 
        * \fn App()
        * \brief Constructeur standard
                * \return
        */
        public App()
        {
            InitializeComponent();
        }


        /*! 
        * \fn void launchGame(List<int> colorList,List<int> teamList,int nbArtefact)
        * \brief Lancement et ouverture de la fenetre de jeu
        * \param colorList la liste des couleurs des joueurs ordonnee selon le resultat des des
        * \param teamList la liste des equipes des joueurs ordonnee selon le resultat des des
        * \param nbArtefact le nombre d'artefacts a remporter dans la partie
        * \param mapFilename le nom du fichier de la map a utiliser
        * \return bool vrai si le jeu a pu etre lance, faux sinon (erreur de map)
        */
        public static bool launchGame(List<int> colorList,List<int> teamList,int nbArtefact,String mapFilename){
            wrapper.createGame(nbPlayers, nbArtefact, colorList,teamList,mapFilename);
            if (wrapper.isValidMap())
            {
                mainGameWnd = new MainGame();
                mainGameWnd.ShowDialog();
                return true;
            }
            return false;
        }

        /*! 
        * \fn void endGame(int teamNb)
        * \brief Fin du jeu et fermeture de la fenetre de jeu
        * \param teamNb le numero de l'equipe gagnante
        * \return
        */
        public static void endGame(int teamNb)
        {
            //string color =  Utilities.colorTypeToString((Utilities.GameColors)wrapper.getColorTab(playerNb));
            MessageBox.Show("Congratulations ! The winner is team " + teamNb + " ! Now you possess enough PascalGarcium to be the Master of the Universe.");
            mainGameWnd.wplayer.close();
            mainGameWnd.Close();
        }




    }
}
