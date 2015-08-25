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

namespace SpaceBattleView
{
    /*! \class PlayerSelection
     *  \implements Window
     *  \brief classe gerant l'affichage de la selection des joueurs
     */
    public partial class PlayerSelection : Window
    {
        String mapFilename = "map.txt"; /*!< nom du fichier de la map*/


        /*! 
        * \fn PlayerSelection()
        * \brief Constructeur standard de l'ecran de choix des joueurs
                * \return
        */
        public PlayerSelection()
        {
            InitializeComponent();
            comboBoxPlayerNb.SelectionChanged += comboBoxPlayerNb_SelectionChanged;
        }

        /*! 
        * \fn void comboBoxPlayerNb_SelectionChanged(object sender, SelectionChangedEventArgs e)
        * \brief Modifie l'affichage lors du changement de nombre de joueurs
        * \param object sender l'objet appelant cette methode
        * \param SelectionChangedEventArgs e les evenements associes au changement
        * \return
        */
        private void comboBoxPlayerNb_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            if ((sender as ComboBox).SelectedItem != null)
            {
                App.nbPlayers = comboBoxPlayerNb.SelectedIndex + 2;
     
                 switch (App.nbPlayers)
                 {
                     case 2:
                         labelP3.IsEnabled = false;
                         comboBoxColor3.IsEnabled = false;
                         buttonDicesP3.IsEnabled = false;
                         comboBoxTeam3.IsEnabled = false;
                         labelP4.IsEnabled = false;
                         comboBoxColor4.IsEnabled = false;
                         buttonDicesP4.IsEnabled = false;
                         comboBoxTeam4.IsEnabled = false;
                         break;
                     case 3:
                         labelP3.IsEnabled = true;
                         comboBoxColor3.IsEnabled = true;
                         buttonDicesP3.IsEnabled = true;
                         comboBoxTeam3.IsEnabled = true;
                         labelP4.IsEnabled = false;
                         comboBoxColor4.IsEnabled = false;
                         buttonDicesP4.IsEnabled = false;
                         comboBoxTeam4.IsEnabled = false;
                         break;
                     case 4:
                         labelP3.IsEnabled = true;
                         comboBoxColor3.IsEnabled = true;
                         buttonDicesP3.IsEnabled = true;
                         comboBoxTeam3.IsEnabled = true;
                         labelP4.IsEnabled = true;
                         comboBoxColor4.IsEnabled = true;
                         buttonDicesP4.IsEnabled = true;
                         comboBoxTeam4.IsEnabled = true;
                         break;
                 }
            }
        }

        /*! 
        * \fn void buttonStart_Click(object sender, RoutedEventArgs e)
        * \brief Actions a effectuer lors du clic sur Start: lance la fenetre de jeu
        * \param object sender l'objet appelant cette methode
        * \param SelectionChangedEventArgs e les evenements associes au changement
        * \return
        */
        private void buttonStart_Click(object sender, RoutedEventArgs e)
        {
            if (checkColorChoice() && checkDicesRolled())
            {
                List<int> colorList = getColorRank();
                int nbArtefacts = comboBoxArtefacts.SelectedIndex + 2;
                List<int> teamList = getTeamRank();
                if (!App.launchGame(colorList, teamList, nbArtefacts, mapFilename))
                    textBlockError.Text = "The MapFile is not valid, please check User manual.";
            }
        }

        /*! 
        * \fn List<int> getColorRank()
        * \brief Donne la liste des couleurs des joueurs selon l'ordre etabli aux des
                * \return List<int> la liste des couleurs ordonnees
        */
        private List<int> getColorRank()
        {
            List<int> choosenList = new List<int>();

            System.Collections.Generic.Dictionary<int, int> myDict = new Dictionary<int, int>();
            
            myDict.Add(comboBoxColor1.SelectedIndex, Convert.ToInt16(textBlockDicesP1.Text));
            myDict.Add(comboBoxColor2.SelectedIndex, Convert.ToInt16(textBlockDicesP2.Text));
            choosenList.Add(comboBoxColor1.SelectedIndex);
            choosenList.Add(comboBoxColor2.SelectedIndex);

            switch (App.nbPlayers)
            {
                case 2:
                    int missing1 = missingColor(choosenList);
                    myDict.Add(missing1, 1);
                    choosenList.Add(missing1);
                    int missing2 = missingColor(choosenList);
                    myDict.Add(missing2, 1);
                    choosenList.Add(missing2);
                    break;
                case 3:
                    myDict.Add(comboBoxColor3.SelectedIndex, Convert.ToInt16(textBlockDicesP3.Text));
                    choosenList.Add(comboBoxColor3.SelectedIndex);
                    int missing3 = missingColor(choosenList);
                   // Debug.Print("missing case 3 : " + missing3);
                    myDict.Add(missing3, 1);
                    choosenList.Add(missing3);
                    break;
                case 4:
                     myDict.Add(comboBoxColor3.SelectedIndex, Convert.ToInt16(textBlockDicesP3.Text));
                    choosenList.Add(comboBoxColor3.SelectedIndex);
                    myDict.Add(comboBoxColor4.SelectedIndex, Convert.ToInt16(textBlockDicesP4.Text));
                    choosenList.Add(comboBoxColor4.SelectedIndex);
                    break;
                default:
                    break;
            }
            
            System.Collections.Generic.Dictionary<int, int> sortedDict = new Dictionary<int, int>();
            sortedDict = (from entry in myDict orderby entry.Value ascending select entry).ToDictionary(pair => pair.Key, pair => pair.Value);
            List<int> sortedList = new List<int>(sortedDict.Keys);
            sortedList.Reverse();
            Debug.Assert(sortedList.Count() == 4);
            return sortedList;
        }

        /*! 
        * \fn List<int> getTeamRank()
        * \brief Donne la liste des equipes des joueurs selon l'ordre etabli aux des
                * \return List<int> la liste des equipes des joueurs ordonnees
        */
        private List<int> getTeamRank()
        {
            List<int> choosenList = new List<int>();


            List<KeyValuePair<int, int>> myDict = new List<KeyValuePair<int, int>>();

            myDict.Add(new KeyValuePair<int, int>(comboBoxTeam1.SelectedIndex + 1, Convert.ToInt16(textBlockDicesP1.Text)));
            myDict.Add(new KeyValuePair<int, int>(comboBoxTeam2.SelectedIndex + 1, Convert.ToInt16(textBlockDicesP2.Text)));
            choosenList.Add(comboBoxTeam1.SelectedIndex + 1);
            choosenList.Add(comboBoxTeam2.SelectedIndex + 1);

            switch (App.nbPlayers)
            {
                case 2:
                    myDict.Add(new KeyValuePair<int, int>(comboBoxTeam3.SelectedIndex+1, 1));
                    choosenList.Add(comboBoxTeam3.SelectedIndex + 1);
                    myDict.Add(new KeyValuePair<int, int>(comboBoxTeam4.SelectedIndex + 1, 1));
                    choosenList.Add(comboBoxTeam4.SelectedIndex + 1);
                    break;
                case 3:
                    myDict.Add(new KeyValuePair<int, int>(comboBoxTeam3.SelectedIndex+1, Convert.ToInt16(textBlockDicesP3.Text)));
                    choosenList.Add(comboBoxTeam3.SelectedIndex+1);
                    myDict.Add(new KeyValuePair<int, int>(comboBoxTeam4.SelectedIndex + 1, 1));
                    choosenList.Add(comboBoxTeam4.SelectedIndex + 1);
                    break;
                case 4:
                    myDict.Add(new KeyValuePair<int, int>(comboBoxTeam3.SelectedIndex +1, Convert.ToInt16(textBlockDicesP3.Text)));
                    choosenList.Add(comboBoxTeam3.SelectedIndex + 1);
                    myDict.Add(new KeyValuePair<int, int>(comboBoxTeam4.SelectedIndex + 1, Convert.ToInt16(textBlockDicesP4.Text)));
                    choosenList.Add(comboBoxTeam4.SelectedIndex + 1);
                    break;
                default:
                    break;
            }

            List<KeyValuePair<int, int>> sortedDict = new List<KeyValuePair<int, int>>();
            sortedDict = (from entry in myDict orderby entry.Value ascending select entry).ToList();
            List<int> sortedList = new List<int>();
            for (int i = 0; i < sortedDict.Count; i++) sortedList.Add(sortedDict[i].Key);
            sortedList.Reverse();
            //for (int i = 0; i < 4; i++) Debug.Print("joueur num" + i + " team num" + sortedList[i]);
            return sortedList;
        }

        /*! 
        * \fn int missingColor(List<int> l)
        * \brief Donne une couleur non contenue dans la liste l (utilisee par getRank())
        * \param List<int> l la liste dans laquelle chercher la couleur non presente
        * \return int l'entier correspondant a la couleur non presente
        */
        private int missingColor(List<int> l)
        {
            for (int i = 0; i < 4; i++)
            {
                if (!l.Contains(i)) return i;
            }
            return 0; //n'arrivera jamais.
        }

        /*! 
        * \fn bool checkColorChoice()
        * \brief Verifie que chaque joueur a selectionne une couleur differente
                * \return bool Vrai si chaque joueur a selectionne une couleur differente, faux sinon.
        */
        private bool checkColorChoice()
        {
            textBlockError.Text = "";
            bool[] isUsed = new bool[] { false, false, false, false };
            isUsed[comboBoxColor1.SelectedIndex] = true;
            isUsed[comboBoxColor2.SelectedIndex] = true;
            if (App.nbPlayers >= 3) isUsed[comboBoxColor3.SelectedIndex] = true;
            if (App.nbPlayers == 4) isUsed[comboBoxColor4.SelectedIndex] = true;

            int nbTrue = 0;
            foreach (bool b in isUsed)
            {
                if (b) nbTrue++;
            }
            if (nbTrue == App.nbPlayers) return true;
            textBlockError.Text = "You should select a different color for each player !";
            return false;
        }

        /*! 
        * \fn bool checkDicesRolled()
        * \brief Verifie que chaque joueur a lance les des
                * \return bool Vrai si chaque joueur a lance ses des, faux sinon
        */
        private bool checkDicesRolled()
        {
            textBlockError.Text = "";
            bool[] isRolled = new bool[] { false, false, false, false };
            isRolled[0] = (textBlockDicesP1.Text!="");
            isRolled[1] = (textBlockDicesP2.Text != "");
            if (App.nbPlayers >= 3) isRolled[2] = (textBlockDicesP3.Text != "");
            if (App.nbPlayers == 4) isRolled[3] = (textBlockDicesP4.Text != "");

            int nbTrue = 0;
            foreach (bool b in isRolled)
            {
                if (b) nbTrue++;
            }
            if (nbTrue == App.nbPlayers) return true;
            textBlockError.Text = "Every player should roll his dices !";
            return false;
        }

        /*! 
        * \fn void buttonDicesP1_Click(object sender, RoutedEventArgs e)
        * \brief Lancement des des du joueur 1
        * \param object sender, RoutedEventArgs e parametres standards non utilises
        * \return
        */
        private void buttonDicesP1_Click(object sender, RoutedEventArgs e)
        {
            int d1 = App.dicesWrapper.rollFirstDice();
            int d2 = App.dicesWrapper.rollSecondDice();
            int result = d1 + d2;
            player1dice1.Source = new BitmapImage(new Uri("../../Views/img/Dice/dice" + d1 + ".png", UriKind.Relative));
            player1dice2.Source = new BitmapImage(new Uri("../../Views/img/Dice/dice" + d2 + ".png", UriKind.Relative));
            textBlockDicesP1.Text = result.ToString();
        }

        /*! 
        * \fn void buttonDicesP2_Click(object sender, RoutedEventArgs e)
        * \brief Lancement des des du joueur 2
        * \param object sender, RoutedEventArgs e parametres standards non utilises
        * \return
        */
        private void buttonDicesP2_Click(object sender, RoutedEventArgs e)
        {
            int d1 = App.dicesWrapper.rollFirstDice();
            int d2 = App.dicesWrapper.rollSecondDice();
            int result = d1 + d2;
            player2dice1.Source = new BitmapImage(new Uri("../../Views/img/Dice/dice" + d1 + ".png", UriKind.Relative));
            player2dice2.Source = new BitmapImage(new Uri("../../Views/img/Dice/dice" + d2 + ".png", UriKind.Relative));
            textBlockDicesP2.Text = result.ToString();
        }

        /*! 
        * \fn void buttonDicesP3_Click(object sender, RoutedEventArgs e)
        * \brief Lancement des des du joueur 3
        * \param object sender, RoutedEventArgs e parametres standards non utilises
        * \return
        */
        private void buttonDicesP3_Click(object sender, RoutedEventArgs e)
        {
            int d1 = App.dicesWrapper.rollFirstDice();
            int d2 = App.dicesWrapper.rollSecondDice();
            int result = d1 + d2;
            player3dice1.Source = new BitmapImage(new Uri("../../Views/img/Dice/dice" + d1 + ".png", UriKind.Relative));
            player3dice2.Source = new BitmapImage(new Uri("../../Views/img/Dice/dice" + d2 + ".png", UriKind.Relative));
            textBlockDicesP3.Text = result.ToString();
        }

        /*! 
        * \fn void buttonDicesP4_Click(object sender, RoutedEventArgs e)
        * \brief Lancement des des du joueur 4
        * \param object sender, RoutedEventArgs e parametres standards non utilises
        * \return
        */
        private void buttonDicesP4_Click(object sender, RoutedEventArgs e)
        {
            int d1 = App.dicesWrapper.rollFirstDice();
            int d2 = App.dicesWrapper.rollSecondDice();
            int result = d1 + d2;
            player4dice1.Source = new BitmapImage(new Uri("../../Views/img/Dice/dice" + d1 + ".png", UriKind.Relative));
            player4dice2.Source = new BitmapImage(new Uri("../../Views/img/Dice/dice" + d2 + ".png", UriKind.Relative));
            textBlockDicesP4.Text = result.ToString();
        }

        /*! 
       * \fn void buttonSelectMap_Click(object sender, RoutedEventArgs e)
       * \brief Ouverture d'une boite de dialogue de choix de fichier pour la map
       * \param object sender, RoutedEventArgs e parametres standards non utilises
       * \return
       */
        private void buttonSelectMap_Click(object sender, RoutedEventArgs e)
        {
            Microsoft.Win32.OpenFileDialog dlg = new Microsoft.Win32.OpenFileDialog();
            dlg.FileName = "map"; // Default file name
            dlg.DefaultExt = ".txt"; // Default file extension
            dlg.Filter = "Text documents (.txt)|*.txt"; // Filter files by extension

            // Show open file dialog box
            Nullable<bool> result = dlg.ShowDialog();

            // Process open file dialog box results
            if (result == true)
            {
                // Open document
                mapFilename = dlg.FileName;
            }
        }

  
    }
}
