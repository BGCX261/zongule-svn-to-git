﻿using System;
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
    /*! \class OrbitalStationSquareView
    * \implements SquareView
    * \brief classe implementant SquareView, representant une case de type OrbitalStation
    */
    public class OrbitalStationSquareView : SquareView
    {

        /*! 
          * \fn OrbitalStationSquareView(MainGame m, SolidColorBrush color)
          * \brief Constructeur standard
          * \param m Reference vers la fenetre de jeu
          * \return
          */
        public OrbitalStationSquareView(MainGame m, SolidColorBrush color)
            : base(m)
        {
            r.Fill = color;
            r.Opacity = 0.8;
            r.MouseEnter += mouseOver;
            r.MouseLeave += mouseOut;
            r.MouseUp += mouseUp;
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
                r.Opacity = 1;
            
        }


        /*! 
         * \fn void mouseUp(Object sender, MouseEventArgs e)
         * \brief Definit les actions effectuees lorsque la souris clique sur la case
         * \param sender l'objet appelant cette methode
         * \param e les actions realisees par la souris
         * \return
         */
        public void mouseUp(Object sender, MouseEventArgs e)
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
                r.Opacity = 0.8;
            
        }

        /*! 
        * \fn void unsetAccessible()
        * \brief Realise les actions d'affichage necessaires lorsque l'ont veut rendre la case inaccessible
                * \return
        */
        public override void unsetAccessible()
        {
            isAccessible = false;
            r.Fill.BeginAnimation(SolidColorBrush.OpacityProperty, null);
            r.Fill.Opacity = 0.8;

        }  
    }
}
