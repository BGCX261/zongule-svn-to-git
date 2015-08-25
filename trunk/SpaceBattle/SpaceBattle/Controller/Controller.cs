using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using SpaceBattleView;
using mWrapper;

namespace Controller
{
    /*! \class Controller
    * \brief classe representant le controlleur du MVC du jeu
    */

    class Controller
    {
        MainGame mainGame; /*!< Reference vers la fenetre de jeu*/


        /*! 
        * \fn Controller(MainGame m)
        * \brief Constructeur standard
        * \param m Reference vers la fenetre de jeu
        * \return
        */
        public Controller(MainGame m)
        {
            mainGame = m;
        }

        /*!
        * \fn String[] fillStrColorTab()
        * \brief Creation d'un tableau des noms de couleur associees aux joueurs, selon leur ordre
        * \return le tableau de noms de couleurs
        */
        public String[] fillStrColorTab(){

            String[] strColorTab = new String[4];
            for (int i = 0; i < 4; i++)
            {
                strColorTab[i] = Utilities.colorTypeToString((Utilities.GameColors)App.wrapper.getColorTab(i));
            }
            return strColorTab;
        }

        /*!
        * \fn void rollDices()
        * \brief Lancement des des
                * \return
        */
        public void rollDices()
        {
            App.dicesWrapper.rollFirstDice();
            App.dicesWrapper.rollSecondDice();         
        }

        /*!
        * \fn void clicNormalSquare(int posx,int posy)
        * \brief Realise l'action de mouvement sur une case definie
        * \param posx l'abscisse de la case cliquee
        * \param posy l'ordonnee de la case cliquee
        * \return
        */
        public void clicNormalSquare(int posx,int posy)
        {
            if ((Utilities.GameStatusType)(App.wrapper.getCurrentStatus()) == Utilities.GameStatusType.MoveType)
            {
                App.wrapper.doAction(posx, posy);
                mainGame.passTurn();
            }      
        }

        /*!
        * \fn void passTurn()
        * \brief Fonction permettant de passer au joueur suivant, verifie si la partie est terminee
                * \return
        */
        public void passTurn()
        {
            App.wrapper.nextPlayer();
            App.dicesWrapper.reset();
            App.wrapper.changeCurrentStatus((int)Utilities.GameStatusType.WaitType);
            if (App.wrapper.isGameEnded())
            {
                App.endGame(App.wrapper.getGameWinner());
            }
        }

        /*!
        * \fn void moveCommand()
        * \brief Choix de deplacement, change l'etat du jeu
                * \return
        */
        public void moveCommand()
        {
            App.wrapper.changeCurrentStatus((int)(Utilities.GameStatusType.MoveType));
        }

        /*!
        * \fn void shootCommand()
        * \brief Choix de tir, change l'etat du jeu
                * \return
        */
        public void shootCommand(){
             App.wrapper.changeCurrentStatus((int)(Utilities.GameStatusType.ShootType));
        }

        /*!
        * \fn void doAction(double posx, double posy)
        * \brief Realise l'action necessaire lors du clic sur la case donnee
        * \param posx l'abscisse de la case cliquee
        * \param posy l'ordonnee de la case cliquee
        * \return
        */
        public void doAction(double posx, double posy)
        {
            App.wrapper.doAction(posx, posy);
        }
            
    }
}
