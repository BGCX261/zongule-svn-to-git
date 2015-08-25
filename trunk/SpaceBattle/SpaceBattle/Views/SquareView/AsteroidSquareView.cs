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
using System.Windows.Media.Animation;

namespace SpaceBattleView
{

    /*! \class AsteroidSquareView
    * \implements SquareView
    * \brief classe implementant SquareView, representant une case de type Asteroid
    */
    public class AsteroidSquareView : SquareView
    {

        /*! 
     * \fn AsteroidSquareView(MainGame m)
     * \brief Constructeur standard
     * \param m Reference vers la fenetre de jeu
     * \return
     */
        public AsteroidSquareView(MainGame m)
            : base(m)
        {
            r.MouseEnter += mouseOver;
            r.MouseLeave += mouseOut;
            ImageBrush myBrush = new ImageBrush();
            myBrush.ImageSource =
                new BitmapImage(new Uri("pack://application:,,,/SpaceBattleView;component/Views/img/elements/asteroid.png", UriKind.Absolute));
            myBrush.Stretch = Stretch.Fill;
           r.Fill = myBrush;
           r.Fill.Opacity = 1;
           r.Opacity = 1;
        }


        /*! 
      * \fn void mouseOver(Object sender, MouseEventArgs e)
      * \brief Definit les actions effectuees lorsque la souris passe sur la case
      * \param sender l'objet appelant cette methode
      * \param e les actions realisees par la souris
      * \return
      */
        public override void mouseOver(Object sender, MouseEventArgs e)
        {
            if (sender is Rectangle)
            {
                ((Rectangle)sender).Fill.Opacity = 1;
            }
        }


        /*! 
       * \fn void mouseOut(Object sender, MouseEventArgs e)
       * \brief Definit les actions effectuees lorsque la souris sort de la case
       * \param sender l'objet appelant cette methode
       * \param e les actions realisees par la souris
       * \return
       */
        public override void mouseOut(Object sender, MouseEventArgs e)
        {
            if (sender is Rectangle)
            {
                ((Rectangle)sender).Fill.Opacity = 1;
            }
        }

        /*! 
        * \fn void unsetAccessible()
        * \brief Realise les actions d'affichage necessaires lorsque l'ont veut rendre la case inaccessible
                * \return
        */
        public override void unsetAccessible()
        {
            isAccessible = false;
            r.Fill.Opacity = 1;
        }

    }
}
