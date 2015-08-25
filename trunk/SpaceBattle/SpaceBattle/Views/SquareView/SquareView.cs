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
using System.Diagnostics;
using System.Windows.Media.Animation;


namespace SpaceBattleView
{

    /*! \class SquareView
    * \brief classe abstraite representant la vue d'une case
    */

    public abstract class SquareView
    {
        public Rectangle r;  /*!< Rectangle contenant les donnees de la case */
        protected MainGame mainGame;   /*!< Reference vers la fenetre de jeu */
        public bool isAccessible;   /*!< Indique si la case est accessible au deplacement */

        /*! 
       * \fn SquareView(MainGame m)
       * \brief Constructeur standard
       * \param m Reference vers la fenetre de jeu
       * \return
       */
        public SquareView(MainGame m)
        {
            mainGame = m;
            r = new Rectangle();
            r.HorizontalAlignment = HorizontalAlignment.Stretch;
            r.VerticalAlignment = VerticalAlignment.Stretch;
            SolidColorBrush pEmptyCase = new SolidColorBrush(Colors.White);
            r.Fill = pEmptyCase;
            
            r.Opacity = 1;
            r.Fill.Opacity = 0;
            r.MouseEnter += mouseOver;
            r.MouseLeave += mouseOut;
            r.Stroke = new SolidColorBrush(Colors.White);
            r.StrokeThickness = 0.5;

            Line shootLine = new Line();
        }

        /*! 
       * \fn void mouseOver(Object sender, MouseEventArgs e)
       * \brief Definit les actions effectuees lorsque la souris passe sur la case
       * \param sender l'objet appelant cette methode
       * \param e les actions realisees par la souris
       * \return
       */
        public virtual void mouseOver(Object sender, MouseEventArgs e)
        {
            r.Stroke = new SolidColorBrush(Colors.Cyan);
            r.StrokeThickness = 2;   
        }


        /*! 
       * \fn void mouseOut(Object sender, MouseEventArgs e)
       * \brief Definit les actions effectuees lorsque la souris sort de la case
       * \param sender l'objet appelant cette methode
       * \param e les actions realisees par la souris
       * \return
       */
        public virtual void mouseOut(Object sender, MouseEventArgs e)
        {
            
                r.Stroke = new SolidColorBrush(Colors.White);
                r.StrokeThickness = 0.5;

            
        }

        /*! 
       * \fn void setAccessible()
       * \brief Realise les actions d'affichage necessaires lorsque l'ont veut rendre la case accessible
              * \return
       */
        public virtual void setAccessible()
        {
            r.Fill.Opacity = 0.8;
            isAccessible = true;
            DoubleAnimation da = new DoubleAnimation();
            da.From = 0.3;
            da.To = 0.7;
            da.AutoReverse = true;
            da.RepeatBehavior = RepeatBehavior.Forever;   
            r.Fill.BeginAnimation(SolidColorBrush.OpacityProperty, da);
        }

        /*! 
        * \fn void unsetAccessible()
        * \brief Realise les actions d'affichage necessaires lorsque l'ont veut rendre la case inaccessible
                * \return
        */
        public virtual void unsetAccessible()
        {
            isAccessible = false;
            r.Fill.BeginAnimation(SolidColorBrush.OpacityProperty, null);
            r.Fill.Opacity = 0;
           
        }     
    } 
}
