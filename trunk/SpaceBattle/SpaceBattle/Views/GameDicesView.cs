using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows.Media;
using System.Windows.Media.Imaging;

namespace SpaceBattleView
{

    /*! \class GameDicesView
     *  \implements Observer
     * \brief classe representant la vue des des
     */
    class GameDicesView : Observer
    {
        int d1; /*!< Entier representant le premier de */
        int d2; /*!< Entier representant le deuxieme de*/
        MainGame mainGame; /*!< Reference vers la fenetre du jeu */


        /*! 
        * \fn GameDicesView(MainGame m)
        * \brief Constructeur standard
        * \param m Reference vers la fenetre de jeu
        * \return
        */
        public GameDicesView(MainGame m)
        {
            mainGame = m;
            update();
            App.dicesWrapper.setObserver(this);
        }


        /*! 
        * \fn getD1()
        * \brief Renvoie la valeur du premier de
                * \return Valeur du premier de
        */
        public int getD1(){
            return d1;
        }

        /*! 
       * \fn getD2()
       * \brief Renvoie la valeur du second de
              * \return Valeur du second de
       */
        public int getD2(){
            return d2;
        }

        /*! 
        * \fn int getBoth()
        * \brief Renvoie la valeur des deux des additionnee
                * \return valeur des deux des additionnee
        */
        public int getBoth()
        {
            return d1+d2;
        }

        /*! 
        * \fn void update()
        * \brief Mise a jour de la vue des des
                * \return
        */
        public void update()
        {
            
            d1 = App.dicesWrapper.getFirstDiceValue();
            d2 = App.dicesWrapper.getSecondDiceValue();
            mainGame.imageDice1.Source = new BitmapImage(new Uri("pack://application:,,,/SpaceBattleView;component/Views/img/Dice/dice" + d1 + ".png", UriKind.Absolute));
            mainGame.imageDice2.Source = new BitmapImage(new Uri("pack://application:,,,/SpaceBattleView;component/Views/img/Dice/dice" + d2 + ".png", UriKind.Absolute));
            mainGame.imageDiceBoth1.Source = new BitmapImage(new Uri("pack://application:,,,/SpaceBattleView;component/Views/img/Dice/dice" + d1 + ".png", UriKind.Absolute));
            mainGame.imageDiceBoth2.Source = new BitmapImage(new Uri("pack://application:,,,/SpaceBattleView;component/Views/img/Dice/dice" + d2 + ".png", UriKind.Absolute));
         }

        /*! 
        * \fn void updateRadio()
        * \brief Mise a jour des radioButton des des
                * \return
        */
        public void updateRadio(){
            int playerNb = App.wrapper.getCurrentPlayer();
            Utilities.GameSpaceshipsType type = (Utilities.GameSpaceshipsType)App.wrapper.getPlayerSpaceshipType(playerNb);
            if (type == Utilities.GameSpaceshipsType.Mothership)
            {
                mainGame.radioButtonSecondDice.IsEnabled = true;
                mainGame.radioButtonBothDices.IsEnabled = true;
            }
            else
            {
                mainGame.radioButtonSecondDice.IsEnabled = false;
                mainGame.radioButtonBothDices.IsEnabled = false;
            }
        }

    }
}
