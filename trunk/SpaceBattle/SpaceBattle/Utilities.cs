using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace SpaceBattleView
{
    /*! \class Utilities
     *  \brief classe Utilitaires comportant des fonctions statiques utilitaires
     */
    class Utilities
    {
        public enum GameColors { Red, Blue, Green, Yellow }; /*!< Les couleurs des joueurs */
        public enum GameSpaceshipsType { Mothership, Battlecruiser, Rescuecab }; /*!< Les types de vaisseaux utilises */
        public enum GameStatusType { WaitType, MoveType, ShootType }; /*!< Les etats (GameStatus) utilises */

        /*! 
        * \fn String colorTypeToString(GameColors i)
        * \brief Donne la chaine de caractere correspondante a un type de couleur 
        * \param GameColors i le type de couleur dont on veut le nom
        * \return String le nom de la couleur donnee en parametre
        */
        public static String colorTypeToString(GameColors i)
        {
            switch (i)
            {
                case GameColors.Red:
                    return "Red";
                case GameColors.Blue:
                    return "Blue";
                case GameColors.Green:
                    return "Green";
                case GameColors.Yellow:
                    return "Yellow";
                default:
                    return "Color problem";
            }
        }

        /*! 
        * \fn String spaceshipTypeToString(GameSpaceshipsType i)
        * \brief Donne la chaine de caractere correspondante a un type de vaisseau 
        * \param GameSpaceshipsType i le type de vaisseau dont on veut le nom
        * \return String le nom du vaisseau donnee en parametre
        */
        public static String spaceshipTypeToString(GameSpaceshipsType i)
        {
            switch (i)
            {
                case GameSpaceshipsType.Mothership:
                    return "Mothership";
                case GameSpaceshipsType.Battlecruiser:
                    return "Battlecruiser";
                case GameSpaceshipsType.Rescuecab:
                    return "Rescuecab";
                default:
                    return "Spaceship Type problem";
            }
        }
    }
}
