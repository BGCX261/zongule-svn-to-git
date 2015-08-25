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
    /*! \class EnergyStationSquareView
    * \implements SquareView
    * \brief classe implementant SquareView, representant une case de type EnergyStation
    */
    public class EnergyStationSquareView : SquareView
    {

        /*! 
        * \fn EnergyStationSquareView(MainGame m)
        * \brief Constructeur standard
        * \param m Reference vers la fenetre de jeu
        * \return
        */
        public EnergyStationSquareView(MainGame m)
            : base(m)
        {
            r.MouseEnter += mouseOver;
            r.MouseLeave += mouseOut;
            r.MouseUp += mouseUp;
            ImageBrush myBrush = new ImageBrush();
            myBrush.ImageSource =
               new BitmapImage(new Uri("pack://application:,,,/SpaceBattleView;component/Views/img/elements/canon.png", UriKind.Absolute));
            myBrush.Stretch = Stretch.Fill;
           r.Fill = myBrush;
           r.Fill.Opacity = 0.8;
           r.Opacity = 1;
        }


        public virtual void mouseUp(Object sender, MouseEventArgs e)
        {
            //if (base.isAccessible)
            mainGame.onClicNormalSquare(sender, e);
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
             r.Stroke = new SolidColorBrush(Colors.White);
             r.StrokeThickness = 0.5;
             r.Fill.Opacity = 0.8;
            
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
            r.Stroke = new SolidColorBrush(Colors.Cyan);
            r.StrokeThickness = 2;   
               r.Fill.Opacity = 1;
            
        }


        /*! 
      * \fn void setAccessible()
      * \brief Realise les actions d'affichage necessaires lorsque l'ont veut rendre la case accessible
            * \return
      */
        public override void setAccessible()
        {
            ImageBrush myBrush = new ImageBrush();
            myBrush.ImageSource =
               new BitmapImage(new Uri("pack://application:,,,/SpaceBattleView;component/Views/img/elements/canon_white.png", UriKind.Absolute));
            myBrush.Stretch = Stretch.Fill;
            r.Fill = myBrush;
            r.Fill.Opacity = 0.8;
            isAccessible = true;
            DoubleAnimation da = new DoubleAnimation();
            da.From = 0.5;
            da.To = 1;
            da.AutoReverse = true;
            da.RepeatBehavior = RepeatBehavior.Forever;
            r.Fill.BeginAnimation(ImageBrush.OpacityProperty, da);

        }

        /*! 
        * \fn void unsetAccessible()
        * \brief Realise les actions d'affichage necessaires lorsque l'ont veut rendre la case inaccessible
                * \return
        */
        public override void unsetAccessible()
        {
            ImageBrush myBrush = new ImageBrush();
            myBrush.ImageSource =
               new BitmapImage(new Uri("pack://application:,,,/SpaceBattleView;component/Views/img/elements/canon.png", UriKind.Absolute));
            myBrush.Stretch = Stretch.Fill;
            r.Fill = myBrush;
            isAccessible = false;
            r.Fill.BeginAnimation(ImageBrush.OpacityProperty, null);
            r.Fill.Opacity = 0.8;
        }

    }
}
