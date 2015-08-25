using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace SpaceBattleView
{
    /*! \class LogView
     * \brief classe representant la fenetre de log 
     */
    class LogView
    {
        MainGame mainGame;

        /*! 
      * \fn LogView(MainGame m)
      * \brief Constructeur standard
      * \param m Reference vers la fenetre de jeu
      * \return
      */
        public LogView(MainGame m){
            mainGame = m;
        }

        /*! 
      * \fn void write(String msg)
      * \brief Ecriture d'un message dans la fenetre
      * \param String msg le message a ecrire
      * \return
      */
        public void write(String msg){
            mainGame.richTextBoxLog.AppendText(msg+"."+Environment.NewLine);
            mainGame.richTextBoxLog.ScrollToEnd();
        }

    }
}
