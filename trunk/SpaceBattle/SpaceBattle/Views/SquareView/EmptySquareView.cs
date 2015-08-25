using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Shapes;

namespace SpaceBattleView
{
    /*! \class EmptySquareView
    * \implements SquareView
    * \brief classe implementant SquareView, representant une case de type Empty
    */
    public class EmptySquareView : SquareView
    {


        /*! 
        * \fn EmptySquareView(MainGame m)
        * \brief Constructeur standard
        * \param m Reference vers la fenetre de jeu
        * \return
        */
        public EmptySquareView(MainGame m)
            : base(m)
        {
            r.MouseUp += mouseUp;
        }


        /*! 
         * \fn void mouseUp(Object sender, MouseEventArgs e)
         * \brief Definit les actions effectuees lorsque la souris clique sur la case
         * \param sender l'objet appelant cette methode
         * \param e les actions realisees par la souris
         * \return
         */
        public virtual void mouseUp(Object sender, MouseEventArgs e)
        {
            //if (base.isAccessible)
            mainGame.onClicNormalSquare(sender, e);
        }
    }
}
