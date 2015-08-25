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
using System.Threading;


namespace SpaceBattleView
{

    /*! \class PlayerView
     *  \implements Observer
     * \brief classe representant la vue d'un joueur
     */
    class PlayerView : Observer
    {
        MainGame mainGame; /*!< Reference vers la fenetre de jeu */
        public Image image; /*!< Image du vaisseau du joueur */

        int playerNb;  /*!< Numero du joueur */
        int posx = 0;  /*!< Abscisse de la position du vaisseau du joueur  */
        int posy = 0;  /*!< Ordonnee de la position du vaisseau du joueur */
        int nbArtefacts = 0;   /*!< Nombre d'artefacts en possession du joueur */
        bool shipPossesesArtefact = false;  /*!< Indique si le joueur possede un artefact sur son vaisseau */
        int shotsRemaining = 0;  /*!< Nombre de tirs restants du vaisseau */
        Utilities.GameSpaceshipsType spaceshipType;  /*!< Type de vaisseau courant du joueur */
        WMPLib.WindowsMediaPlayer player;


        /*! 
       * \fn PlayerView(MainGame m,int nb)
       * \brief Constructeur standard
       * \param m Reference vers la fenetre de jeu
       * \param nb Numero du joueur
       * \return
       */
        public PlayerView(MainGame m,int nb)
        {
            mainGame = m;
            playerNb = nb;
            mainGame.textBlockTeamTab[App.wrapper.getColorTab(playerNb)].Text = App.wrapper.getPlayerTeam(playerNb).ToString();
            image = new Image();
            mainGame.gridGame.Children.Add(image);
            posx = App.wrapper.getPlayerPosX(playerNb);
            posy = App.wrapper.getPlayerPosY(playerNb);
            updateImage();
            updateSpaceshipType();
            updatePosition();
        }

        /*! 
        * \fn void update()
        * \brief Mise a jour des informations du joueur depuis le modele
        * \param m
        * \return
        */
        public void update()
        {
            updatePosition();

            bool oldArtPossess = shipPossesesArtefact;
            nbArtefacts = App.wrapper.getPlayerNbArtefacts(playerNb);
            shipPossesesArtefact = App.wrapper.getPlayerPossesArtefact(playerNb);

            int oldShotsRemaining = shotsRemaining;
            shotsRemaining = App.wrapper.getPlayerShotsRemaining(playerNb);
            if (shotsRemaining > oldShotsRemaining)
            {
                mainGame.write(mainGame.strColorTab[playerNb] + " spaceship's laser canon is now fully loaded");
                player = new WMPLib.WindowsMediaPlayer();
                var path = System.IO.Path.Combine(
                 System.IO.Path.GetDirectoryName(System.Reflection.Assembly.GetExecutingAssembly().Location)
                , "sounds/energy.mp3");
                player.URL = path;
                player.controls.play(); 
            }

            if (!oldArtPossess && shipPossesesArtefact)
            {
                mainGame.write("A PascalGarcium ore is loaded in spaceship " + mainGame.strColorTab[playerNb]);
                player = new WMPLib.WindowsMediaPlayer();
                var path = System.IO.Path.Combine(
                 System.IO.Path.GetDirectoryName(System.Reflection.Assembly.GetExecutingAssembly().Location)
                , "sounds/getartefact.mp3");
                player.URL = path;
                player.controls.play(); 
            }
            if (oldArtPossess && !shipPossesesArtefact)
            {
                player = new WMPLib.WindowsMediaPlayer();
                var path = System.IO.Path.Combine(
                 System.IO.Path.GetDirectoryName(System.Reflection.Assembly.GetExecutingAssembly().Location)
                , "sounds/wonartefact.mp3");
                player.URL = path;
                player.controls.play(); 
                mainGame.write("A PascalGarcium ore is brought back by player " + mainGame.strColorTab[playerNb]);
            }
            Utilities.GameColors color = (Utilities.GameColors)App.wrapper.getColorTab(playerNb);

            mainGame.textBlockArtefactsTab[(int)color].Text = nbArtefacts.ToString();
            mainGame.textBlockShotsTab[(int)color].Text = shotsRemaining.ToString();
            updateSpaceshipType();
            updateImage();
            
        }

        /*! 
       * \fn void updateSpaceshipType()
       * \brief Mise a jour de la position du vaisseau du joueur
              * \return
       */
        void updatePosition()
        {
            Grid.SetColumn(image, posx);
            Grid.SetRow(image, posy);

            int posxOld = posx;
            int posyOld = posy;
            posx = App.wrapper.getPlayerPosX(playerNb);
            posy = App.wrapper.getPlayerPosY(playerNb);

            DoubleAnimation daX = new DoubleAnimation();
            daX.From = 0;
            daX.To = (posx - posxOld) * mainGame.sqLong;
            double dX = (double)daX.To - (double)daX.From;
            daX.Duration = TimeSpan.FromMilliseconds(500);
            DoubleAnimation daY = new DoubleAnimation();
            daY.From = 0;
            daY.To = (posy - posyOld) * mainGame.sqHaut;
            double dY = (double)daY.To - (double)daY.From;
            daY.Duration = TimeSpan.FromMilliseconds(500);

            TranslateTransform tt = new TranslateTransform();
            image.RenderTransform = tt;
            tt.BeginAnimation(TranslateTransform.XProperty, daX);
            tt.BeginAnimation(TranslateTransform.YProperty, daY);
        }

        /*! 
       * \fn void updateSpaceshipType()
       * \brief Mise a jour du type du vaisseau du joueur
              * \return
       */
        public void updateSpaceshipType()
        {
            int color = App.wrapper.getColorTab(playerNb);
            Utilities.GameSpaceshipsType oldType = spaceshipType;
            spaceshipType = (Utilities.GameSpaceshipsType)App.wrapper.getPlayerSpaceshipType(playerNb); 
            String type = Utilities.spaceshipTypeToString(spaceshipType);
            if (spaceshipType > oldType)
            {
                mainGame.write(mainGame.strColorTab[playerNb] + "player's " + Utilities.spaceshipTypeToString(oldType) + " is now replaced by a " + type);
                player = new WMPLib.WindowsMediaPlayer();
                var path = System.IO.Path.Combine(
                 System.IO.Path.GetDirectoryName(System.Reflection.Assembly.GetExecutingAssembly().Location)
                , "sounds/hit.mp3");
                player.URL = path;
                player.controls.play(); 
            }
            if (spaceshipType < oldType) mainGame.write(mainGame.strColorTab[playerNb] + "player's " + Utilities.spaceshipTypeToString(oldType) + " is now upgraded to a " + type);
        }

        /*! 
       * \fn void updateImage()
       * \brief Mise a jour de l'image du vaisseau du joueur
              * \return
       */
        public void updateImage()
        {
            String color = mainGame.strColorTab[playerNb];
            String type = Utilities.spaceshipTypeToString(spaceshipType);
            String art;
            if (shipPossesesArtefact) art = "_artefact";
            else art = "";
           // Debug.Print("color player num" + playerNb + " " + color);
            
            image.Visibility = Visibility.Visible;

            String path = "pack://application:,,,/SpaceBattleView;component/Views/img/Spaceship/" + color + "/" + type + art + ".png";
            BitmapImage logo = new BitmapImage();
            logo.BeginInit();
            logo.UriSource = new Uri(path);
            logo.EndInit();
            image.Source = logo;
            //image.Source =
             //  new BitmapImage(new Uri("../../Views/img/Spaceship/"+color+"/"+type+art+".png", UriKind.Relative));
        }
    }
}
