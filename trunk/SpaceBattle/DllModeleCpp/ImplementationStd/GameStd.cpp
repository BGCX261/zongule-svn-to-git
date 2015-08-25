#include "StdAfx.h"
#include "GameStd.h"

/*!
* \fn GameStd* GameStd::GameStd(void)
* \brief Fonction de creation d'une nouvelle instance d'un objet GameStd
* \return Instance nouvellement allouee d'un objet de type GameStd
*/
GameStd::GameStd(void)
{
	currentPlayer = 0;
	moveStatus = new MoveStatus(this);
	shootStatus = new ShootStatus(this);
	waitStatus = new WaitStatus(this);
	currentStatus = waitStatus;
}

/*!
* \fn void GameStd::addPlayers()
* \brief initialise l'attribut players avec le vector en parametre
* \param std::vector<Player*> ptab
* \return
*/
void GameStd::addPlayers(std::vector<Player*> ptab){
	players = ptab;
}

/*!
* \fn void GameStd::addMap()
* \brief initialise l'attribut map avec le Map* en parametre
* \param Map* nmap
* \return
*/
void GameStd::addMap(Map* nmap){
	map = nmap;
}

/*!
* \fn int GameStd::getMapLongueur()
* \brief retourne la longueur de map, la Map* en attribut
* \return la longueur de l'attribut map
*/
int GameStd::getMapLongueur(){
	return map->getLongueur();
}

/*!
* \fn int GameStd::getMapHauteur()
* \brief retourne la hauteur de map, la Map* en attribut
* \return la hauteur de l'attribut map
*/
int GameStd::getMapHauteur(){
	return map->getHauteur();
}

/*!
* \fn SquareType GameStd::getSquareType(int x,int y)
* \brief permet de connaitre le type de case de coordonnees (x,y) de l'attribut map
* \param int x
* \param int y
* \return le SquareType de la case de coordonnees (x,y)
*/
SquareType GameStd::getSquareType(int x,int y){
	return map->getSquareType(x,y);
}

/*!
* \fn int GameStd::getCurrentPlayer()
* \brief permet de connaitre le joueur qui a la main
* \return currentPlayer
*/
int GameStd::getCurrentPlayer(){
	return currentPlayer;
}

/*!
* \fn Player* GameStd::getCurrentPlayer(int i)
* \brief retourne un pointeur sur le joueur a l'emplacement i du vector de joueurs
* \param int i
* \return un pointeur sur le joueur i
*/
Player* GameStd::getPlayer(int i){
	return players[i];
}

/*!
* \fn void GameStd::nextPlayer()
* \brief passe la main au joueur suivant
* \return
*/
void GameStd::nextPlayer(){
	currentPlayer++;
	if (currentPlayer == nbPlayers) currentPlayer = 0;
}

/*!
* \fn void GameStd::setNbPlayers(int nb)
* \brief initialise le nombre de joueurs a nb
* \param int nb
* \return
*/
void GameStd::setNbPlayers(int nb){
	nbPlayers = nb;
}

/*!
* \fn void GameStd::setColorTab(Color c1,Color c2,Color c3,Color c4)
* \brief associe respectivement les couleurs en parametres a chacun des 4 joueurs
* \param Color c1 la couleur a assigner au joueur 1
* \param Color c2 la couleur a assigner au joueur 2
* \param Color c3 la couleur a assigner au joueur 3
* \param Color c4 la couleur a assigner au joueur 4
* \return
*/
void GameStd::setColorTab(Color c1,Color c2,Color c3,Color c4){
	colorTab[0] = c1;
	colorTab[1] = c2;
	colorTab[2] = c3;
	colorTab[3] = c4;
}

/*!
* \fn void GameStd::setTeamTab(std::vector<int>& teamVec)
* \brief associe respectivement les numeros d'equipes en parametres au joueurs
* \param std::vector<int>& teamVec les num d'equipe des quatre joueurs
* \return
*/
void GameStd::setTeamTab(std::vector<int>& teamVec){
	for (int i=0;i<4;i++){
		teamTab[i] = teamVec[i];
	}
	//debug:
	std::cout << "teams dans GameStd::setTeamTab:"<<std::endl;
	for (int i=0;i<4;i++){
		std::cout << "player "<<i<<" : team "<<teamTab[i]<<std::endl;
	}
}

/*!
* \fn void GameStd::setNbArtefactsToWin(int nb)
* \brief definit le nombre d'artefacts a avoir pour gagner
* \param int nb le nombre d'artfacts a prendre pour gagner
* \return
*/
void GameStd::setNbArtefactsToWin(int nb){
	nbArtefactsToWin = nb;
}

/*!
* \fn Color GameStd::getColorTab(int i)
* \brief donne la couleur mise dans ColorTab a l'indice i
* \param int i indice du tableau
* \return Color la couleur 
*/
Color GameStd::getColorTab(int i){
	return colorTab[i];
}

/*!
* \fn int GameStd::getPlayerPosX(int playerNb)
* \brief donne l'abscisse X du joueur de numero playerNb
* \param int playerNb
* \return int abscisse du joueur de numero playerNb 
*/
int GameStd::getPlayerPosX(int playerNb){
	return players[playerNb]->getPlayerPosX();
}

/*!
* \fn int GameStd::getPlayerPosY(int playerNb)
* \brief donne l'ordonnee Y du joueur de numero playerNb
* \param int playerNb
* \return int ordonnee du joueur de numero playerNb 
*/
int GameStd::getPlayerPosY(int playerNb){
	return players[playerNb]->getPlayerPosY();
}

/*!
* \fn int GameStd::getPlayerTeam(int playerNb)
* \brief donne le num d'equipe du joueur de numero playerNb
* \param int playerNb
* \return int num d'equipe du joueur
*/
int GameStd::getPlayerTeam(int playerNb){
	return teamTab[playerNb];
}

/*!
* \fn int GameStd::getPlayerNbArtefacts(int playerNb)
* \brief donne le nombre d'artefacts du joueur de numero playerNb
* \param int playerNb
* \return int nombre d'artefacts du joueur de numero playerNb 
*/
int GameStd::getPlayerNbArtefacts(int playerNb){
	return players[playerNb]->getNbArtefacts();
}

/*!
* \fn bool GameStd::getPlayerPossesArtefact(int playerNb)
* \brief indique si lejoueur de numero playerNb possede un artefact
* \param int playerNb
* \return bool vrai si le joueur possede un artefact, faux sinon
*/
bool GameStd::getPlayerPossesArtefact(int playerNb){
	return players[playerNb]->getPlayerPossesArtefact();
}

/*!
* \fn int GameStd::getPlayerShotsRemaining(int playerNb)
* \brief donne le nombre de tirs restants du joueur de numero playerNb
* \param int playerNb
* \return int nombre de tirs restants du joueur de numero playerNb 
*/
int GameStd::getPlayerShotsRemaining(int playerNb){
	return players[playerNb]->getPlayerShotsRemaining();
}

/*!
* \fn void GameStd::doAction(double posx,double posy)
* \brief fait l'action necessaire suivant le contexte donne en parametre
* \param double posx, posy	abcisse et ordonnee du clic
*/
void GameStd::doAction(double posx,double posy){
	return currentStatus->doAction(posx,posy,getCurrentPlayer());
}

/*!
* \fn Spaceship* GameStd::getCurrentSpaceship
* \brief rend le vaisseau du joueur qui a la main
* \return Spaceship* pointeur sur vaisseau du joueur qui a la main
*/
Spaceship* GameStd::getCurrentSpaceship(){
	return players[currentPlayer]->getSpaceship();
}

/*!
* \fn Square* GameStd::getMapSquare(int posx,int posy)
* \brief rend la case où l'utilisateur clique
* \param int posx abscisse du clic
* \param int posy ordonnee du clic
* \return Square* pointeur sur la case cliquee
*/
Square* GameStd::getMapSquare(int posx,int posy){
	return map->getSquare(posx,posy);
}

/*!
* \fn void GameStd::changeCurrentStatus(GameStatusType t)
* \brief change l'etat courant par celui passe en parametre (de type decrit dans l'enum StatusType)
* \param GameStatusType t le type d'etat par lequel on veut remplacer l'etat courant
* \return
*/
void GameStd::changeCurrentStatus(GameStatusType t){

	switch (t){
	case WaitType:
		currentStatus=waitStatus;
		break;
	case MoveType:
		currentStatus=moveStatus;
		break;
	case ShootType:
		currentStatus=shootStatus;
		break;
	}
}


/*!
* \fn GameStatusType GameStd::getCurrentStatus()
* \brief rend l'etat de jeu courant
* \return GameStatusType etat du jeu courant
*/
GameStatusType GameStd::getCurrentStatus(){
	return currentStatus->getType();
}

/*!
* \fn std::vector<Position> GameStd::getPlayersPosition()
* \brief rend un vecteur avec les position de tous les joueurs
* \return std::vector<Position> vecteur avec positions de tous les joueurs
*/
std::vector<Position> GameStd::getPlayersPosition(){
	std::vector<Position> pos;
	for (int i=0;i<nbPlayers;i++){
		int posx = getPlayerPosX(i);
	    int posy = getPlayerPosY(i);
		pos.push_back(Position(posx,posy));
	}
	return pos;
}

/*!
* \fn std::vector<Position> GameStd::getAsteroidsPosition()
* \brief parcours la map et rend un vecteur avec les position de toutes les asteroides
* \return std::vector<Position> vecteur avec positions de toutes les asteroides
*/
std::vector<Position> GameStd::getAsteroidsPosition(){
	std::vector<Position> pos;
	for (int i=0;i<getMapLongueur();i++){
		for (int j=0;j<getMapHauteur();j++){
			Square* sq = map->getSquare(i,j);
			if (sq->getType() == AsteroidSquareType) pos.push_back(Position(i,j));
		}
	}
	return pos;
}

/*!
* \fn void GameStd::shootPlayer(int playerNb)
* \brief tire sur le joueur de numero passe en parametre et realise les actions consequentes
* \param int playerNb le joueur sur lequel le tir a ete fait
* \return
*/
void GameStd::shootPlayer(int playerNb){
	SpaceshipFactory* factory = new SpaceshipFactoryStd();
	Spaceship* s = players[playerNb]->getSpaceship();
	//si Battlecruiser, l'artefact revient au shooter
	if (s->hasArtefact() && s->getType()==BattlecruiserType) 
		players[currentPlayer]->getSpaceship()->takeArtefact();
	//creation du nouveau vaisseau
	Spaceship* newSpaceship = factory->createNextSpaceship(s);
	//si Mothership, retour a la base
	if (newSpaceship->getType() == MothershipType){
		GameBuilder* builder = new GameBuilderStd();
		builder->setPosShip(newSpaceship,players[playerNb]->getColor(), getMapLongueur(), getMapHauteur());
		delete builder;
		std::cout<<"remplacement par mothership"<<std::endl;
	}
	delete factory;
	players[playerNb]->replaceSpaceship(newSpaceship);
	std::cout << "Spaceship du joueur "<<playerNb<<"remplace"<<std::endl;
}

/*!
* \fn std::vector<Position> GameStd::getLastShootTrace()
* \brief donne les coordonnees par lesquelles est passe le tir
* \return std::vector<Position> tableau des coordonnees par où passe le tir
*/
std::vector<Position> GameStd::getLastShootTrace(){
	return shootStatus->getLastShootTrace();
}

/*!
* \fn SpaceshipType GameStd::getPlayerSpaceshipType(int playerNb)
* \brief rend le type de vaisseau courant du joueur dont le numero est donne en parametre
* \param int playerNb le numero du joueur
* \return SpaceshipType le type de vaisseau courant du joueur de numero playerNb
*/
SpaceshipType GameStd::getPlayerSpaceshipType(int playerNb){
	return getPlayer(playerNb)->getSpaceship()->getType();
}

/*!
* \fn std::vector<int> GameStd::getAccessibleSquares(int diceNb)
* \brief calcule les cases accessibles depuis la position du joueur courant en fonction du resultat du de
* \param int diceNb le de a utiliser
* \return std::vector<int> vecteur des cases accessibles
*/
std::vector<int> GameStd::getAccessibleSquares(int diceNb){
	int posx = getPlayerPosX(currentPlayer);
	int posy = getPlayerPosY(currentPlayer);
	std::vector<int> vec;
	addAccessibleSquare(&vec,posx,posy,posx+diceNb,posy,0);
	addAccessibleSquare(&vec,posx,posy,posx+diceNb,posy-diceNb,1);
	addAccessibleSquare(&vec,posx,posy,posx,posy-diceNb,2);
	addAccessibleSquare(&vec,posx,posy,posx-diceNb,posy-diceNb,3);
	addAccessibleSquare(&vec,posx,posy,posx-diceNb,posy,4);
	addAccessibleSquare(&vec,posx,posy,posx-diceNb,posy+diceNb,5);
	addAccessibleSquare(&vec,posx,posy,posx,posy+diceNb,6);
	addAccessibleSquare(&vec,posx,posy,posx+diceNb,posy+diceNb,7);
	return vec;
}

/*!
* \fn void GameStd::addAccessibleSquare(std::vector<int>* vec,int srcx,int srcy, int posx, int posy,int dir)
* \brief ajoute les cases accessibles au vecteur vec passe en parametre
* \param std::vector<int>* vec	vecteur auquel la fonction ajoute les cases
* \param int srcx, srcy 	case annexe a la case de depart (bord commun ou angle commun)
* \param int posx, posy		case d'arrivee
* \param int dir		direction a prendre
* \return
*
* Directions (variable dir)
* 	3 2 1
* 	4 x 0
* 	5 6 7
*
*/
void GameStd::addAccessibleSquare(std::vector<int>* vec,int srcx,int srcy, int posx, int posy,int dir){
	
	while(srcx!=posx || srcy!=posy){
		switch (dir){
		case 0:
			srcx++;
			break;
		case 1:
			srcx++; srcy--;
			break;
		case 2:
			srcy--;
			break;
		case 3:
			srcx--; srcy--;
			break;
		case 4:
			srcx--;
			break;
		case 5:
			srcx--; srcy++;
			break;
		case 6:
			srcy++;
			break;
		case 7:
			srcx++; srcy++;
			break;		
		}	
		if (!(isAccessibleSquare(srcx,srcy))) return;
	}

	if (isAccessibleSquare(posx,posy)){
		(*vec).push_back(posx);
		(*vec).push_back(posy);
	}
}

/*!
* \fn bool GameStd::isAccessibleSquare(int posx,int posy)
* \brief rend vrai si la case (posx, posy) est accessible depuis la position du joueur
* \param int posx, posy		case d'arrivee
* \return bool true si case accessible, false sinon
*
* NB : case accessible = case où il n'y a pas d'asteroide ni de vaisseau d'un adversaire
*/
bool GameStd::isAccessibleSquare(int posx,int posy){
	if (posx<0 || posx>=getMapLongueur()) return false;
	if (posy<0 || posy>=getMapHauteur()) return false;
	if (getSquareType(posx,posy)==AsteroidSquareType) return false;
	for (int i=0;i<nbPlayers;i++){
		if ((players[i]->getPlayerPosX() == posx) && (players[i]->getPlayerPosY() == posy))
			return false;
	}
	return true;
}

/*!
* \fn bool GameStd::isGameEnded()
* \brief rend vrai si un joueur a ramasse le nombre d'artefacts necessaires pour gagner (partie gagnee)
* \return bool true si partie terminee, false sinon
*/
bool GameStd::isGameEnded(){
	int teamNbArtefacts[] = {0,0,0,0};
	for (int i=0;i<nbPlayers;i++){
		teamNbArtefacts[(teamTab[i])-1] += players[i]->getNbArtefacts();
		if (teamNbArtefacts[teamTab[i]-1] >= nbArtefactsToWin)
			return true;
	}
	//debug

	for (int i=0;i<nbPlayers;i++){
		std::cout << "team num "<<i+1 <<" :" << teamNbArtefacts[i]<<" artefacts"<<std::endl;
	}
	return false;
}

/*!
* \fn int GameStd::getGameWinner()
* \brief rend le numero de l'equipe qui a le nombre d'artefacts necessaires pour gagner (partie gagnee)
* \return int le numero de l'equipe qui a gagne
*/
int GameStd::getGameWinner(){
	int teamNbArtefacts[] = {0,0,0,0};
	for (int i=0;i<nbPlayers;i++){
		teamNbArtefacts[teamTab[i]-1] += players[i]->getNbArtefacts();
		if (teamNbArtefacts[teamTab[i]-1] >= nbArtefactsToWin)
			return teamTab[i];
	}
	return 0;
}

/*!
* \fn bool GameStd::isValidMap()
* \brief renvoie si la map est valide ou pas
* \return bool true si la map est valide, false sinon
*/
bool GameStd::isValidMap(){
	return map->isValidMap();
}




EXTERNC DLL GameStd* GameStd_New(){
	return new GameStd();
}
EXTERNC DLL void GameStd_Delete(GameStd* g){
	delete g;
}
