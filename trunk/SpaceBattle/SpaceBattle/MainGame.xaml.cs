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
using System.Media;
using WMPLib;
using System.Threading;



namespace SpaceBattleView
{
    /*! \class MainGame
     *  \implements Window,Observer
     *  \brief classe principale de la vue du jeu, chargee de l'affichage de l'ecran de jeu
     */
    public partial class MainGame : Window, Observer
    {
        Controller.Controller controller; /*!< Reference vers le contrôlleur du MVC */
        LogView log; /*!< Vue de la fenetre de log */
        public WMPLib.WindowsMediaPlayer wplayer; /*!< Lecteur de musique */
        public WMPLib.WindowsMediaPlayer player; /*!< Lecteur de sons de shoot */

        PlayerView[] playerView;    /*!< Tableau des vues des joueurs */
        SquareView[,] squares;  /*!< Tableau a deux dimensions des vues des cases */
        GameDicesView dicesView;    /*!< Vue des des */
        int nbOrbitalStationCreated;    /*!< Nombre de stations orbitales crees */

       
        public TextBlock[] textBlockArtefactsTab;   /*!< Tableau des textBlock definissant l'affichage du nombre d'artefacts des joueurs */
        public TextBlock[] textBlockSpaceshipsTab;  /*!< Tableau des textBlock definissant l'affichage du nom des vaisseaux courants des joueurs */
        public TextBlock[] textBlockShotsTab;   /*!< Tableau des textBlock definissant l'affichage du nombre de tirs restants des joueurs */
        public TextBlock[] textBlockTeamTab;    /*!< Tableau des textBlock definissant l'affichage de l'equipe des joueurs */
        public String[] strColorTab;    /*!< Tableau des strings representant les couleurs des joueurs */
        public Grid[] playersHub; /*!< Tableau des Hubs des joueurs */

        Line shootLine; /*!< Ligne de shoot affichee */
        public double sqHaut;  /*!< Hauteur d'une case */
        public double sqLong;  /*!< Longueur d'une case */


        /*! 
        * \fn MainGame()
        * \brief Constructeur standard de la vue du jeu
                * \return
        */
        public MainGame()
        {
            wplayer = new WMPLib.WindowsMediaPlayer();
            InitializeComponent();
            controller = new Controller.Controller(this);
            log = new LogView(this);
            App.wrapper.setObserver(this);
            InitializeTabs();
            InitializeGameGrid();
            InitializePlayersView();
            MouseMove += onShootMouseMove;
            MouseUp += onShootMouseUp;
            shootLine = new Line();
            ShowCurrentPlayer();
            animateBackground();

            var path = System.IO.Path.Combine(
                 System.IO.Path.GetDirectoryName(System.Reflection.Assembly.GetExecutingAssembly().Location)
                , "sounds/theme.mp3");
            wplayer.URL = path;
            wplayer.controls.play();
            wplayer.PlayStateChange += new _WMPOCXEvents_PlayStateChangeEventHandler(player_PlayStateChange);
            
        }

        private void animateBackground()
        {
            
            DoubleAnimation daX = new DoubleAnimation();
            daX.From = -100;
            daX.To = 100;
            double dX = (double)daX.To - (double)daX.From;
            daX.Duration = TimeSpan.FromMilliseconds(90000);
            daX.RepeatBehavior = RepeatBehavior.Forever;
            TranslateTransform tt = new TranslateTransform();
            imageStars.RenderTransform= tt;
            DoubleAnimation da = new DoubleAnimation();
            da.From = 0;
            da.To = 1;
            da.Duration = TimeSpan.FromMilliseconds(45000);           
            da.AutoReverse = true;
            da.RepeatBehavior = RepeatBehavior.Forever;

            DoubleAnimation daX2 = new DoubleAnimation();
            daX2.From = -100;
            daX2.To = 100;
            double dX2 = (double)daX2.To - (double)daX2.From;
            daX2.Duration = TimeSpan.FromMilliseconds(30000);
            daX2.RepeatBehavior = RepeatBehavior.Forever;
            TranslateTransform tt2 = new TranslateTransform();
            imageStars2.RenderTransform = tt2;
            DoubleAnimation da2 = new DoubleAnimation();
            da2.From = 0;
            da2.To = 1;
            da2.Duration = TimeSpan.FromMilliseconds(15000);
            da2.AutoReverse = true;
            da2.RepeatBehavior = RepeatBehavior.Forever;



            tt.BeginAnimation(TranslateTransform.XProperty, daX);
            imageStars.BeginAnimation(Image.OpacityProperty, da);
            tt2.BeginAnimation(TranslateTransform.XProperty, daX2);
            imageStars2.BeginAnimation(Image.OpacityProperty, da2);

        }


        /*! 
        * \fn void InitializeTabs()
        * \brief Initialise tous les attributs tableaux avec les donnees de l'interface correspondantes
                * \return
        */
        private void InitializeTabs()
        {
            textBlockArtefactsTab = new TextBlock[] { textBlockArtefactsPRed, textBlockArtefactsPBlue, textBlockArtefactsPGreen, textBlockArtefactsPYellow };         
            textBlockShotsTab = new TextBlock[] { textBlockShots1PRed, textBlockShots1PBlue, textBlockShots1PGreen, textBlockShots1PYellow };
            textBlockTeamTab = new TextBlock[] { textBlockTeam1, textBlockTeam2, textBlockTeam3, textBlockTeam4 };
            playersHub = new Grid[] { gridPRed, gridPBlue, gridPGreen, gridPYellow };
            strColorTab = controller.fillStrColorTab();
          
        }

        /*! 
        * \fn void disablePlayerInfos(int i)
        * \brief Desactive l'affichage des informations du joueur de numero i
        * \param i le numero du joueur
        * \return
        */
        private void disablePlayerInfos(int i)
        {
            int color = App.wrapper.getColorTab(i);
            textBlockArtefactsTab[color].Text = "";
            textBlockShotsTab[color].Text = "";
            textBlockTeamTab[color].Text = "";
        }

        /*! 
        * \fn void InitializePlayersView()
        * \brief initialise l'affichage des informations des joueurs
                * \return
        */
        private void InitializePlayersView()
        {

            if (App.nbPlayers == 3) disablePlayerInfos(3);
            else if (App.nbPlayers == 2)
            {
                disablePlayerInfos(2);
                disablePlayerInfos(3);
            }   

            playerView = new PlayerView[App.nbPlayers];
             for (int i=0;i<App.nbPlayers;i++){
                 playerView[i] = new PlayerView(this, i);
                playerView[i].update();
            }
        }

        /*! 
        * \fn void InitializeGameGrid()
        * \brief initialise l'affichage de la grille de jeu en ajoutant les bonnes cases
                * \return
        */
        private void InitializeGameGrid()
        {        
            //construction de la grid
            int longueur = App.wrapper.getMapLongueur();
            int hauteur = App.wrapper.getMapHauteur();
            squares = new SquareView[longueur, hauteur];
            for (int i = 0; i < App.wrapper.getMapLongueur(); i++)
            {
                gridGame.ColumnDefinitions.Add(new ColumnDefinition());
            }
            for (int i = 0; i < App.wrapper.getMapHauteur(); i++)
            {
                gridGame.RowDefinitions.Add(new RowDefinition());
            }

            //ajout des cases
            
            for (int i = 0; i < App.wrapper.getMapLongueur(); i++)
            {
                for (int j = 0; j < App.wrapper.getMapHauteur(); j++)
                {                
                    switch (App.wrapper.getSquareType(i,j))
                    {
                        case 0: //EmptySquareType
                            createEmptySquare(i, j);
                            break;
                        case 1: //OrbitalStationSquareType
                            createOrbitalStationSquare(i, j);
                            break;
                        case 2://EnergyStationSquareType
                            createEnergyStationSquare(i, j);
                            break;
                        case 3://ArtefactSquareType
                            createArtefactSquare(i, j);
                            break;
                        case 4://AsteroidSquareType
                            createAsteroidSquare(i, j);
                            break;
                    }              
                }
            }

            sqHaut = gridGame.ActualHeight / gridGame.RowDefinitions.Count;
            sqLong = gridGame.ActualWidth / gridGame.ColumnDefinitions.Count;

            //ajout des des
            dicesView = new GameDicesView(this);
            App.dicesWrapper.reset();
            buttonMakeAMove.IsEnabled = false;
            buttonRollDices.IsEnabled = true;

        }

        private void ShowCurrentPlayer(){
            int current = App.wrapper.getCurrentPlayer();
            log.write("> Player " + strColorTab[current] + "'s turn");
            for (int i = 0; i < 4; i++)
            {
                ImageBrush myBrush = new ImageBrush();
                String path;
                if (Utilities.colorTypeToString((Utilities.GameColors)i) == strColorTab[current])
                    path = "pack://application:,,,/SpaceBattleView;component/Views/img/players/player_" + Utilities.colorTypeToString((Utilities.GameColors)i).ToLower() + ".png";
                else
                    path = "pack://application:,,,/SpaceBattleView;component/Views/img/players/player_" + Utilities.colorTypeToString((Utilities.GameColors)i).ToLower() + "_off.png";
                myBrush.ImageSource = new BitmapImage(new Uri(path, UriKind.Absolute));
                playersHub[i].Background = myBrush;
            }
        }

        /*! 
        * \fn void update()
        * \brief Met a jour les informations des joueurs
                * \return
        */
        public void update()
        {
            foreach (PlayerView pv in playerView) pv.update();
        }

        /*! 
        * \fn void createEmptySquare(int i, int j)
        * \brief Cree une case vide
        * \param i l'abscisse de la case
        * \param j l'ordonnee de la case
        * \return
        */
        public void createEmptySquare(int i, int j)
        {           
            EmptySquareView s = new EmptySquareView(this);
            addSquareToGame(s, i, j);
        }

        /*! 
        * \fn void createOrbitalStationSquare(int i, int j)
        * \brief Cree une case Station Orbitale
        * \param i l'abscisse de la case
        * \param j l'ordonnee de la case
        * \return
        */
        public void createOrbitalStationSquare(int i, int j)
        {
            SolidColorBrush[] colorTabs = { new SolidColorBrush(Colors.Red), new SolidColorBrush(Colors.Blue),  new SolidColorBrush(Colors.Green),new SolidColorBrush(Colors.Yellow) };
            OrbitalStationSquareView s = new OrbitalStationSquareView(this, colorTabs[nbOrbitalStationCreated]);
            addSquareToGame(s, i, j);
            if (nbOrbitalStationCreated < 4) nbOrbitalStationCreated++;       
        }

        /*! 
        * \fn void createEnergyStationSquare(int i, int j)
        * \brief Cree une case Station d'energie
        * \param i l'abscisse de la case
        * \param j l'ordonnee de la case
        * \return
        */
        public void createEnergyStationSquare(int i, int j)
        {
            EnergyStationSquareView s = new EnergyStationSquareView(this);
            addSquareToGame(s, i, j);
        }

        /*! 
        * \fn void createArtefactSquare(int i, int j)
        * \brief Cree une case Artefact
        * \param i l'abscisse de la case
        * \param j l'ordonnee de la case
        * \return
        */
        public void createArtefactSquare(int i, int j)
        {
            ArtefactSquareView s = new ArtefactSquareView(this);
            addSquareToGame(s, i, j);
        }

        /*! 
        * \fn void createAsteroidSquare(int i, int j)
        * \brief Cree une case Asteroide
        * \param i l'abscisse de la case
        * \param j l'ordonnee de la case
        * \return
        */
        public void createAsteroidSquare(int i, int j)
        {
            AsteroidSquareView s = new AsteroidSquareView(this);
            addSquareToGame(s, i, j);
        }

        /*! 
        * \fn void addSquareToGame(SquareView s, int i, int j)
        * \brief Ajoute la case s au tableau des cases 
        * \param s la vue de la case a ajouter
        * \param i l'abscisse de la case a ajouter
        * \param j l'ordonnee de la case a ajouter
        * \return
        */
        public void addSquareToGame(SquareView s, int i, int j)
        {
            gridGame.Children.Add(s.r);
            Grid.SetColumn(s.r, i);
            Grid.SetRow(s.r, j);
            squares[i, j] = s;
        }

        /*! 
        * \fn void onClicNormalSquare(Object sender, MouseEventArgs e)
        * \brief Appelle le controller avec les coordonnees du clic
        * \param Object sender, MouseEventArgs e parametres standards inutilises
        * \return
        */
        public void onClicNormalSquare(Object sender, MouseEventArgs e)
        {
            player = new WMPLib.WindowsMediaPlayer();
            var path = System.IO.Path.Combine(
             System.IO.Path.GetDirectoryName(System.Reflection.Assembly.GetExecutingAssembly().Location)
            , "sounds/move.mp3");
            player.URL = path;
            player.controls.play(); 
            int posx = Grid.GetColumn((Rectangle)sender);
            int posy = Grid.GetRow((Rectangle)sender);
            controller.clicNormalSquare(posx,posy);          
        }

        /*! 
        * \fn void buttonMakeAMove_Click(object sender, RoutedEventArgs e)
        * \brief Methode appelee lors du click sur le bouton "Make a move", appelle le contrôleur pour realiser le mouvement
        * \param object sender, RoutedEventArgs e arguments standards non utilises
        * \return
        */
        private void buttonMakeAMove_Click(object sender, RoutedEventArgs e)
        {
            controller.moveCommand();
            gridGame2.Children.Remove(shootLine);  
            cleanShootTraces();
            Mouse.OverrideCursor = Cursors.Arrow;
        }

        /*! 
        * \fn void buttonShoot_Click(object sender, RoutedEventArgs e)
        * \brief  Methode appelee lors du click sur le bouton "Shoot", appelle le contrôleur pour realiser le shoot
        * \param object sender, RoutedEventArgs e arguments standards non utilises
        * \return
        */
        private void buttonShoot_Click(object sender, RoutedEventArgs e)
        {
            controller.shootCommand();
            Mouse.OverrideCursor = Cursors.ScrollAll;
        }

        /*! 
        * \fn void buttonPass_Click(object sender, RoutedEventArgs e)
        * \brief  Methode appelee lors du click sur le bouton "Pass", appelle la methode passTurn() pour passer son tour
        * \param object sender, RoutedEventArgs e arguments standards non utilises
        * \return
        */
        private void buttonPass_Click(object sender, RoutedEventArgs e)
        {
            passTurn();
        }

        /*! 
        * \fn void passTurn()
        * \brief Methode qui realise l'appel au controleur pour passer au joueur suivant, et met a jour l'affichage
                * \return
        */
        public void passTurn()
        {
            controller.passTurn();
            Mouse.OverrideCursor = Cursors.Arrow;
            List<Line> lineToDelete = new List<Line>() ;
            foreach (Line l in gridGame2.Children.OfType<Line>())
            {
                lineToDelete.Add(l);
            }
            foreach (Line l in lineToDelete)
            {
                gridGame2.Children.Remove(l);
            }
            ShowCurrentPlayer();
            buttonMakeAMove.IsEnabled = false;
            buttonRollDices.IsEnabled = true;
            int nbShots = App.wrapper.getPlayerShotsRemaining(App.wrapper.getCurrentPlayer());
            if (nbShots == 0) buttonShoot.IsEnabled = false;
            else buttonShoot.IsEnabled = true;
            foreach (SquareView sq in squares) sq.unsetAccessible();
            
        }

        /*! 
        * \fn void cleanShootTraces()
        * \brief Supprime les lignes de shoot affichees a l'ecran
                * \return
        */
        public virtual void cleanShootTraces()
        {
            
            List<Path> lineToDelete = new List<Path>();
            foreach (Path l in gridGame2.Children.OfType<Path>())
            {
                lineToDelete.Add(l);
            }
            foreach (Path l in lineToDelete)
            {
                gridGame2.Children.Remove(l);
            }
        }

        /*! 
        * \fn void onShootMouseMove(Object sender, MouseEventArgs e)
        * \brief Affiche une ligne de laser suivant le curseur a l'ecran lors des phases de visee
        * \param Object sender, MouseEventArgs e parametres standards non utilises ici
        * \return
        */
        public virtual void onShootMouseMove(Object sender, MouseEventArgs e)
        {
            if ((Utilities.GameStatusType)(App.wrapper.getCurrentStatus()) == Utilities.GameStatusType.ShootType)
            {
                gridGame2.Children.Remove(shootLine);         
                System.Windows.Point position = e.GetPosition(gridGame);
                shootLine.Stroke = System.Windows.Media.Brushes.Cyan;
                shootLine.X1 = sqLong*App.wrapper.getPlayerPosX(App.wrapper.getCurrentPlayer()) + (sqLong/2);
                shootLine.X2 = position.X;
                shootLine.Y1 = sqHaut*App.wrapper.getPlayerPosY(App.wrapper.getCurrentPlayer()) + (sqHaut/2);
                shootLine.Y2 = position.Y;
                shootLine.StrokeThickness = 2;
                gridGame2.Children.Add(shootLine);             
            }
        }

        /*! 
        * \fn void onShootMouseUp(Object sender, MouseEventArgs e)
        * \brief Realise l'action de shoot, affiche les traces du laser et passe au joueur suivant
        * \param Object sender l'objet appelant cette methode (non utilise)
        * \param MouseEventArgs e l'evenement de clic de souris, permet de recuperer les coordonnees du clic
        * \return
        */
        public virtual void onShootMouseUp(Object sender, MouseEventArgs e)
        {
            if ((Utilities.GameStatusType)(App.wrapper.getCurrentStatus()) == Utilities.GameStatusType.ShootType)
            {
                player = new WMPLib.WindowsMediaPlayer();
                var path = System.IO.Path.Combine(
                 System.IO.Path.GetDirectoryName(System.Reflection.Assembly.GetExecutingAssembly().Location)
                , "sounds/laser.mp3");
                player.URL = path;
                player.controls.play();   

                System.Windows.Point position = e.GetPosition(gridGame);

                double posx = (position.X) / sqLong;
                double posy = (position.Y) / sqHaut;
                controller.doAction(posx, posy);
                //Debug.Print("Position clic x:" + posx);
                //Debug.Print("Position clic y:" + posy);
                showShootTrace();
                passTurn();
            }
        }

        /*! 
        * \fn void showShootTrace()
        * \brief Affiche l'animation de la trace du shoot sur l'ecran de jeu
                * \return
        */
        public virtual void showShootTrace()
        {
            List<double> shootList = App.wrapper.getLastShootTrace();
            Storyboard sb = new Storyboard();
            for (int i = 0; i+2 < shootList.Count;)
            {
                LineGeometry l = new LineGeometry();
                double x1 = shootList[i] * sqLong;
                i++;
                double y1 = shootList[i] * sqHaut;
                i++;
                double x2 = shootList[i] * sqLong;
                double y2 = shootList[i + 1] * sqHaut;
                l.StartPoint = new Point(x1,y1);
                l.EndPoint = new Point(x1, y1);
                Point realEndPoint = new Point(x2, y2);
                PointAnimation pointAnim = new PointAnimation();
                PointAnimation pointAnim2 = new PointAnimation();
                pointAnim.From = l.StartPoint;
                pointAnim2.From = l.StartPoint;
                pointAnim.To = realEndPoint;
                pointAnim2.To = realEndPoint;
                pointAnim.Duration = TimeSpan.FromMilliseconds(100);
                pointAnim2.Duration = TimeSpan.FromMilliseconds(300);
                pointAnim.BeginTime = TimeSpan.FromMilliseconds(i*100 - 100);
                pointAnim2.BeginTime = TimeSpan.FromMilliseconds(i * 100);
                l.BeginAnimation(LineGeometry.EndPointProperty, pointAnim);
                l.BeginAnimation(LineGeometry.StartPointProperty, pointAnim2);
                Path myPath = new Path();
                myPath.StrokeThickness = 2;
                myPath.Stroke = System.Windows.Media.Brushes.Cyan;
                myPath.Data = l;
                gridGame2.Children.Add(myPath);        
            }
        }

        /*! 
        * \fn void buttonRollDices_Click(object sender, RoutedEventArgs e)
        * \brief Permet de lancer les deux des, appel au contrôleur et mise a jour de l'affichage a l'ecran
        * \param object sender, RoutedEventArgs e parametres standards non utilises ici
        * \return
        */
        private void buttonRollDices_Click(object sender, RoutedEventArgs e)
        {
            controller.rollDices();
            buttonMakeAMove.IsEnabled = true;
            buttonRollDices.IsEnabled = false;
            radioButtonFirstDice.IsChecked = true;
            dicesView.updateRadio();
            radioButtonFirstDice_Checked(null, null);
            buttonMakeAMove_Click(null, null);
        }

        /*! 
        * \fn void radioButtonFirstDice_Checked(object sender, RoutedEventArgs e)
        * \brief Mise a jour de l'affichage lors du clic sur le bouton radio du premier de
        * \param object sender, RoutedEventArgs e parametres standards non utilises
        * \return
        */
        private void radioButtonFirstDice_Checked(object sender, RoutedEventArgs e)
        {
            foreach (SquareView sq in squares) sq.unsetAccessible();
            List<int> accessiblePosList = App.wrapper.getAccessibleSquares(dicesView.getD1());
            for (int i = 0; i < accessiblePosList.Count; i = i + 2)
            {
                //Debug.Print("Accessible : x =" + accessiblePosList[i] + " y=" + accessiblePosList[i + 1]);
                squares[accessiblePosList[i], accessiblePosList[i + 1]].setAccessible();
            }
        }

        /*! 
        * \fn void radioButtonSecondDice_Checked(object sender, RoutedEventArgs e)
        * \brief Mise a jour de l'affichage lors du clic sur le bouton radio du second de
        * \param object sender, RoutedEventArgs e parametres standards non utilises
        * \return
        */
        private void radioButtonSecondDice_Checked(object sender, RoutedEventArgs e)
        {
            foreach (SquareView sq in squares) sq.unsetAccessible();
            List<int> accessiblePosList = App.wrapper.getAccessibleSquares(dicesView.getD2());
            for (int i = 0; i < accessiblePosList.Count; i = i + 2)
            {
               //Debug.Print("Accessible : x =" + accessiblePosList[i] + " y=" + accessiblePosList[i + 1]);
                squares[accessiblePosList[i], accessiblePosList[i + 1]].setAccessible();
            }
        }

        /*! 
        * \fn void radioButtonBothDices_Checked(object sender, RoutedEventArgs e)
        * \brief Mise a jour de l'affichage lors du clic sur le bouton radio des deux des
        * \param object sender, RoutedEventArgs e parametres standards non utilises
        * \return
        */
        private void radioButtonBothDices_Checked(object sender, RoutedEventArgs e)
        {
            foreach (SquareView sq in squares) sq.unsetAccessible();
            List<int> accessiblePosList = App.wrapper.getAccessibleSquares(dicesView.getBoth());
            for (int i = 0; i < accessiblePosList.Count; i = i + 2)
            {
                squares[accessiblePosList[i], accessiblePosList[i + 1]].setAccessible();
            }
        }

        /*! 
        * \fn void Window_SizeChanged(object sender, SizeChangedEventArgs e)
        * \brief Mise a jour de l'affichage lors du redimensionnement de la fenetre (recalcul des variables de taille)
        * \param object sender, RoutedEventArgs e parametres standards non utilises
        * \return
        */
        private void Window_SizeChanged(object sender, SizeChangedEventArgs e)
        {
            sqHaut = gridGame.ActualHeight / gridGame.RowDefinitions.Count;
            sqLong = gridGame.ActualWidth / gridGame.ColumnDefinitions.Count;
            update();
        }

        /*! 
        * \fn void write(String msg)
        * \brief ecriture dans la fenetre de log
        * \param String msg le message a ecrire
        * \return
        */
        public void write(String msg)
        {
            log.write(msg);
        }

        /*! 
        * \fn void player_PlayStateChange(int newState)
        * \brief Handler de l'evenement de changement d'etat du lecteur de musique, relance la lecture
        * \param int newState
        * \return
        */
        public void player_PlayStateChange(int newState)
        {
            if (newState == 1) wplayer.controls.play();

        }

        /*! 
        * \fn void imageMusic_MouseUp(object sender, MouseButtonEventArgs e)
        * \brief Gestion du bouton d'arret et de lancement du son
        * \param object sender, RoutedEventArgs e parametres standards non utilises
        * \return
        */
        private void imageMusic_MouseUp(object sender, MouseButtonEventArgs e)
        {
            //Debug.Print("music state : "+(int)wplayer.playState);
            
            if ((int)wplayer.playState == 2)
            { //en pause
                wplayer.controls.play();
                imageMusic.Source = new BitmapImage(new Uri("pack://application:,,,/SpaceBattleView;component/Views/img/note.png", UriKind.Absolute));
            }
            else
            {
                wplayer.controls.pause();
                imageMusic.Source = new BitmapImage(new Uri("pack://application:,,,/SpaceBattleView;component/Views/img/nonote.png", UriKind.Absolute));
            }
        }

        /*! 
        * \fn void onClosing(object sender, System.ComponentModel.CancelEventArgs e)
        * \brief Handler de la fin du programme : desactive le son
        * \param object sender, System.ComponentModel.CancelEventArgs e parametres standards non utilises
        * \return
        */
        private void onClosing(object sender, System.ComponentModel.CancelEventArgs e)
        {
            wplayer.close();
        } 




    }
}
