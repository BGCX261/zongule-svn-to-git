#include "StdAfx.h"
#include "GameManager.h"


/*!
* \fn GameManager* GameManager::GameManager_New()
* \brief Fonction de creation d'une nouvelle instance d'un objet GameManager
* \return Instance nouvellement allouee d'un objet de type GameManager
*/
GameManager::GameManager(void)
{
	dices = new GameDicesStd();
}


/*!
* \fn GameManager::~GameManager(void)
* \brief Fonction de destruction d'un objet GameManager
* \return
*/
GameManager::~GameManager(void)
{
}

/*!
* \fn void GameManager::createGame(int nbPlayers,int nbArtefact, std::vector<Color>& colorVec, std::vector<int>& teamVec)
* \brief Cree une partie en fonction des parametres passes
* \param int nbPlayers le nombre de joueurs
* \param int nbArtefact le nombre d'artefacts
* \param std::vector<Color>& colorVec le tableau des correspondances joueurs/couleurs
* \param std::vector<int>& teamVec le tableau des equipes
* \param std::string strMapFilename le nom du fichier de la map a utiliser
* \return
*/
void GameManager::createGame(int nbPlayers,int nbArtefact, std::vector<Color>& colorVec, std::vector<int>& teamVec, std::string strMapFilename){
	GameBuilder* builder = new GameBuilderStd();
	
	game = builder->createGame(nbPlayers,nbArtefact,strMapFilename,colorVec,teamVec);

}

/*!
* \fn int GameManager::rollFirstDice()
* \brief lance et donne la valeur du 1er de
* \return int valeur du 1er de
*/
int GameManager::rollFirstDice(){
	return dices->rollFirstDice();
}

/*!
* \fn int GameManager::rollSecondDice()
* \brief lance et donne la valeur du 2e de
* \return int valeur du 2e de
*/
int GameManager::rollSecondDice(){
	return dices->rollSecondDice();
}

/*!
* \fn int GameManager::getFirstDiceValue()
* \brief rend la valeur du 1er de sans le lancer
* \return int valeur du 1er de
*/
int GameManager::getFirstDiceValue(){
	return dices->getFirstDiceValue();
}

/*!
* \fn int GameManager::getSecondDiceValue()
* \brief rend la valeur du 2e de sans le lancer
* \return int valeur du 2e de
*/
int GameManager::getSecondDiceValue(){
	return dices->getSecondDiceValue();
}

/*!
* \fn void GameManager::resetDices()
* \brief remet les des a zero
* \return
*/
void GameManager::resetDices(){
	dices->reset();
}

/*!
* \fn int GameManager::getMapLongueur()
* \brief retourne la longueur de la map
* \return la longueur de la map
*/
int GameManager::getMapLongueur(){
	return game->getMapLongueur();
}

/*!
* \fn int GameManager::getMapHauteur()
* \brief retourne la hauteur de la map
* \return la hauteur de la map
*/
int GameManager::getMapHauteur(){
	return game->getMapHauteur();
}

/*!
* \fn int GameManager::getCurrentPlayer()
* \brief permet de connaitre le joueur qui a la main
* \return currentPlayer
*/
int GameManager::getCurrentPlayer(){
	return game->getCurrentPlayer();
}

/*!
* \fn void GameManager::nextPlayer()
* \brief passe la main au joueur suivant
* \return
*/
void GameManager::nextPlayer(){
	return game->nextPlayer();
}

/*!
* \fn SquareType GameManager::getSquareType(int x,int y)
* \brief permet de connaitre le type de case de coordonnees (x,y) de la map
* \param int x
* \param int y
* \return le SquareType de la case de coordonnees (x,y)
*/
SquareType GameManager::getSquareType(int x,int y){
	return game->getSquareType(x,y);
}

/*!
* \fn Color GameManager::getColorTab(int i)
* \brief donne la couleur mise dans ColorTab a l'indice i
* \param int i indice du tableau
* \return Color la couleur 
*/
Color GameManager::getColorTab(int i){
	return game->getColorTab(i);
}

/*!
* \fn int GameManager::getPlayerPosX(int playerNb)
* \brief donne l'abscisse X du joueur de numero playerNb
* \param int playerNb
* \return int abscisse du joueur de numero playerNb 
*/
int GameManager::getPlayerPosX(int playerNb){
	return game->getPlayerPosX(playerNb);
}

/*!
* \fn int GameManager::getPlayerPosY(int playerNb)
* \brief donne l'ordonnee Y du joueur de numero playerNb
* \param int playerNb
* \return int ordonnee du joueur de numero playerNb 
*/
int GameManager::getPlayerPosY(int playerNb){
	return game->getPlayerPosY(playerNb);
}

/*!
* \fn int GameManager::getPlayerTeam(int playerNb)
* \brief donne l'equipe du joueur de numero playerNb
* \param int playerNb
* \return int numero de l'equipe du joueur numero Nb
*/
int GameManager::getPlayerTeam(int playerNb){
	return game->getPlayerTeam(playerNb);
}

/*!
* \fn int GameManager::getPlayerNbArtefact(int playerNb)
* \brief retourne le nombre d'artefact que le joueur numero Nb possede
* \param playerNb
* \return int le nombre d'artefact ramasses par le joueur numero Nb
*/
int GameManager::getPlayerNbArtefacts(int playerNb){
	return game->getPlayerNbArtefacts(playerNb);
}

/*!
* \fn bool GameManager::getPlayerPossesArtefact(int playerNb)
* \brief indique si le joueur possede ou non un artefact
* \param playerNb
* \return bool true si le joueur numero Nb possede un artefact, faux sinon
*/
bool GameManager::getPlayerPossesArtefact(int playerNb){
	return game->getPlayerPossesArtefact(playerNb);
}

/*!
* \fn void GameManager::doAction(double posx,double posy)
* \brief realise l'action necessaire en fonction de la position du vaisseau qui a la main
* \param int posx, posy coordonnees du vaisseau qui a la main
* \return 
*/
void GameManager::doAction(double posx,double posy){
	return game->doAction(posx,posy);
}

/*!
* \fn void GameManager::changeCurrentStatus(int t)
* \brief change l'etat de la partie par celui passe en parametre
* \param int t etat de la partie
* \return 
*/
void GameManager::changeCurrentStatus(int t){
	game->changeCurrentStatus((GameStatusType)t);
}

/*!
* \fn int GameManager::getCurrentStatus()
* \brief retourne (caste en int) l'etat de la partie
* \return etat de la partie caste en int
*/
int GameManager::getCurrentStatus(){
	return (int)(game->getCurrentStatus());
}

/*!
* \fn int GameManager::getPlayerShotsRemaining(int playerNb)
* \brief retourne le nombre de tirs restants du joueur de numero playerNb
* \param int playerNb numero du joueur
* \return nombre de tirs restants du joueur de numero playerNb
*/
int GameManager::getPlayerShotsRemaining(int playerNb){
	return game->getPlayerShotsRemaining(playerNb);
}

/*!
* \fn std::vector<double> GameManager::getLastShootTrace()
* \brief donne les coordonnees par lesquelles est passe le tir
* \return std::vector<double> tableau des x puis y par où passe le tir
*/
std::vector<double> GameManager::getLastShootTrace(){
	std::vector<Position> vecPos = game->getLastShootTrace();
	std::vector<double> doubledVecPos;


	for (int i=0; i< vecPos.size(); i++){
		doubledVecPos.push_back(vecPos[i].x);
		doubledVecPos.push_back(vecPos[i].y);
	}
	return doubledVecPos;
}

/*!
* \fn SpaceshipType GameManager::getPlayerSpaceshipType(int playerNb)
* \brief rend le type de vaisseau courant du joueur dont le numero est donne en parametre
* \param int playerNb le numero du joueur
* \return SpaceshipType le type de vaisseau courant du joueur de numero playerNb
*/
SpaceshipType GameManager::getPlayerSpaceshipType(int playerNb){
	return game->getPlayerSpaceshipType(playerNb);
}

/*!
* \fn std::vector<int> GameManager::getAccessibleSquares(int diceNb)
* \brief calcule les cases accessibles depuis la position du joueur de la partie courant en fonction du resultat du de
* \param int diceNb le de a utiliser
* \return std::vector<int> vecteur des cases accessibles
*/
std::vector<int> GameManager::getAccessibleSquares(int diceNb){
	return game->getAccessibleSquares(diceNb);
}

/*!
* \fn bool GameManager::isGameEnded()
* \brief rend vrai si un joueur a ramasse le nombre d'artefacts necessaires pour gagner (partie gagnee)
* \return bool true si partie terminee, false sinon
*/
bool GameManager::isGameEnded(){
	return game->isGameEnded();
}

/*!
* \fn int GameManager::getGameWinner()
* \brief rend le numero de l'equipe qui a le nombre d'artefacts necessaires pour gagner (partie gagnee)
* \return int le numero de l'equipe qui a gagne
*/
int GameManager::getGameWinner(){
	return game->getGameWinner();
}

/*!
* \fn bool GameManager::isValidMap()
* \brief rend si la map est valide ou pas
* \return  bool true si la map est valide, false sinon
*/
bool GameManager::isValidMap(){
	return game->isValidMap();
}

EXTERNC DLL GameManager* GameManager_New(){return new GameManager();}
EXTERNC DLL void GameManager_Delete(GameManager* a){delete a;}
