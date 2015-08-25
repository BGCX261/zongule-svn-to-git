// mWrapper.h

#pragma once
#pragma comment(lib,"DllModeleCpp.lib")
#include "..\DllModeleCpp\ImplementationStd\GameManager.h"
#include "Observer\Observable.h"
#include "Observer\Observer.h"

#include <iostream>
#include <string>
#include <vector>
using namespace System;
using namespace std;
using namespace System::Collections::Generic;

namespace mWrapper {

	public ref class WrapperGameManager : Observable
	{
	private:
		GameManager* gameManager;	/*!< manager de partie*/
		Observer^ observer;			/*!< observer*/

	public:
		/*!
		* \fn WrapperGameManager* OrbitalStationSquaretd_New()
		* \brief Instancie l'objet C++ correspondant
				* \return Instance nouvellement allouee d'un objet de type WrapperGameManager
		*/
		WrapperGameManager(){
			gameManager = GameManager_New();
		}

		/*!
		* \fn void ~WrapperGameManager()
		* \brief Detruit l'objet C++ correspondant
				* \return
		*/
		~WrapperGameManager(){
			GameManager_Delete(gameManager);
		}

		/*!
		* \fn void setObserver(Observer^ o)
		* \brief Definir l'observer du gameManager
		* \param Observer^ o
		* \return
		*/
		virtual void setObserver(Observer^ o){
			observer = o;
		}

		/*!
		* \fn void notify(Observer^ o)
		* \brief
		* \param Observer^ o
		* \return
		*/
		virtual void notify(Observer^ o){
			o->update();
		}

		/*!
		* \fn void createGame(int nbPlayers,int nbArtefact, List<int>^ colorList, List<int>^ teamList,String^ mapFilename)
		* \brief conversions necessaires puis appel de createGame(nbPlayers,nbArtefact, colorVec, teamVec,strMapFilename)
		* \param int nbPlayers	nb de joueurs
		* \param int nbArtefact nb d'artefacts pour gagner
		* \param List<int>^ colorList	liste des couleurs des joueurs
		* \param List<int>^ teamList	liste des equipes
		* \param String^ mapFilename	fichier de map
		* \return
		*/
		void createGame(int nbPlayers,int nbArtefact, List<int>^ colorList, List<int>^ teamList,String^ mapFilename){
			vector<Color> colorVec; 
			vector<int> teamVec;

			for (int i=0;i<4;i++){
				colorVec.push_back((Color)colorList[i]);
				teamVec.push_back(teamList[i]);
				}

			char* chaineChar = static_cast<char *>(System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(mapFilename).ToPointer());
			std::string strMapFilename(chaineChar);
			System::Runtime::InteropServices::Marshal::FreeHGlobal(safe_cast<IntPtr>(chaineChar));
			std::cout<<strMapFilename<<std::endl;

			gameManager->createGame(nbPlayers,nbArtefact, colorVec, teamVec,strMapFilename);
		}

		/*!
		* \fn int getMapLongueur()
		* \brief rend la longueur de la map
				* \return int longueur de la map
		*/
		int getMapLongueur(){
			return gameManager->getMapLongueur();
			}

		/*!
		* \fn int getMapHauteur()
		* \brief rend la hauteur de la map
				* \return int hauteur de la map
		*/
		int getMapHauteur(){
			return gameManager->getMapHauteur();
		}

		/*!
		* \fn int getSquareType(int x,int y)
		* \brief rend le type de case de coordonnees (x,y)
		* \param int x
		* \param int y
		* \return int le type de case (enum SquareType)
		*/
		int getSquareType(int x,int y){
			return gameManager->getSquareType(x,y);
		}

		/*!
		* \fn int getCurrentPlayer()
		* \brief rend le numero du joueur qui a la main
				* \return int numero du joueur qui a la main
		*/
		int getCurrentPlayer(){
			return gameManager->getCurrentPlayer();
		}

		/*!
		* \fn void nextPlayer()
		* \brief passe la main au joueur suivant
				* \return
		*/
		void nextPlayer(){
			gameManager->nextPlayer();
		}

		/*!
		* \fn int getColorTab(int i)
		* \brief Renvoie la couleur du joueur numero i
		* \param int i numero du joueur
		* \return int la couleur du joueur de numero i
		*/
		int getColorTab(int i){
			return gameManager->getColorTab(i);
		}

		/*!
		* \fn int getPlayerPosX(int playerNb)
		* \brief Renvoie le x du joueur numero playerNb
		* \param int playerNb numero du joueur
		* \return int le x du joueur de numero payerNb
		*/
		int getPlayerPosX(int playerNb){
			return gameManager->getPlayerPosX(playerNb);
		}

		/*!
		* \fn int getPlayerPosY(int playerNb)
		* \brief Renvoie le y du joueur numero playerNb
		* \param int playerNb numero du joueur
		* \return int le y du joueur de numero payerNb
		*/
		int getPlayerPosY(int playerNb){
			return gameManager->getPlayerPosY(playerNb);
		}

		/*!
		* \fn int getPlayerTeam(int playerNb)
		* \brief Renvoie le numero d'equipe du joueur numero playerNb
		* \param int playerNb numero du joueur
		* \return int le numero d'equipe du joueur de numero payerNb
		*/
		int getPlayerTeam(int playerNb){
			return gameManager->getPlayerTeam(playerNb);
		}

		/*!
		* \fn int getPlayerNbArtefacts(int playerNb)
		* \brief Renvoie le nb d'artefacts du joueur numero playerNb
		* \param int playerNb numero du joueur
		* \return int le nb d'artefacts du joueur de numero payerNb
		*/
		int getPlayerNbArtefacts(int playerNb){
			return gameManager->getPlayerNbArtefacts(playerNb);
		}

		/*!
		* \fn bool getPlayerPossesArtefact(int playerNb)
		* \brief Indique si le joueur numero playerNb possede un artefact
		* \param int playerNb numero du joueur
		* \return bool true si joueur de numero payerNb possede un artefact, faux sinon
		*/
		bool getPlayerPossesArtefact(int playerNb){
			return gameManager->getPlayerPossesArtefact(playerNb);
		}

		/*!
		* \fn int getPlayerShotsRemaining(int playerNb)
		* \brief Renvoie le nb de tirs restants du joueur numero playerNb
		* \param int playerNb numero du joueur
		* \return int le nb de tirs restants du joueur de numero payerNb
		*/
		int getPlayerShotsRemaining(int playerNb){
			return gameManager->getPlayerShotsRemaining(playerNb);
		}

		/*!
		* \fn int getPlayerSpaceshipType(int playerNb)
		* \brief Renvoie le type de vaisseau du joueur numero playerNb
		* \param int playerNb numero du joueur
		* \return int le type de vaisseau du joueur de numero payerNb
		*/
		int getPlayerSpaceshipType(int playerNb){
			return gameManager->getPlayerSpaceshipType(playerNb);
		}

		/*!
		* \fn void doAction(double posx,double posy)
		* \brief execute l'action necessaire quant a la case (x,y)
		* \param double posx abscisse de la case
		* \param double posy ordonnee de la case
		* \return
		*/
		void doAction(double posx,double posy){
			gameManager->doAction(posx,posy);
			notify(observer);
		}

		/*!
		* \fn void changeCurrentStatus(int t)
		* \brief change la valeur de l'etat du jeu par t 
		* \param int t
		* \return
		*/
		void changeCurrentStatus(int t){
			gameManager->changeCurrentStatus(t);
		}

		/*!
		* \fn int getCurrentStatus()
		* \brief renvoie l'etat de la partie
				* \return int getCurrentStatuts
		*/
		int getCurrentStatus(){
			return gameManager->getCurrentStatus();
		}

		/*!
		* \fn List<double>^ getLastShootTrace()
		* \brief renvoie la liste des coordonnees traversees par le laser
				* \return List<double>^ liste des coordonnees traversees par le laser
		*/
		List<double>^ getLastShootTrace(){
			List<double>^ l = gcnew List<double>();
			vector<double> vecPos = gameManager->getLastShootTrace();

			for ( unsigned int i = 0; i < vecPos.size(); i = i++ ) {
				l->Add(vecPos[i]);
			}
			return l;
		}

		/*!
		* \fn List<int>^ getAccessibleSquares(int radioIndice)
		* \brief renvoie la liste des cases accessibles suivant le nb de des choisis par le joueur
		* \param int radioIndice numero du bouton de choix de des
		* \return List<int>^ liste des coordonnees accessibles
		*/
		List<int>^ getAccessibleSquares(int radioIndice){
			List<int>^ l = gcnew List<int>();
			vector<int> vecPos = gameManager->getAccessibleSquares(radioIndice);

			for ( unsigned int i = 0; i < vecPos.size(); i = i++ ) {
				l->Add(vecPos[i]);
			}
			return l;
		}

		/*!
		* \fn bool isGameEnded()
		* \brief Indique si la partie est finie
				* \return bool true si la partie est finie, false sinon
		*/
		bool isGameEnded(){
			return gameManager->isGameEnded();
		}

		/*!
		* \fn int getGameWiner()
		* \brief Renvoie le numero de l'equipe gagnante
				* \return int numero de l'equipe gagnante
		*/
		int getGameWinner(){
			return gameManager->getGameWinner();
		}

		/*!
		* \fn bool isValidMap()
		* \brief rend si la map est valide ou pas
				* \return  bool true si la map est valide, false sinon
		*/
		bool isValidMap(){
			return gameManager->isValidMap();
		}

	protected:
		/*!
		* \fn !WrapperGameManager()
		* \brief Destructeur
				* \return
		*/
		!WrapperGameManager(){
			GameManager_Delete(gameManager);
		}

	};
}
