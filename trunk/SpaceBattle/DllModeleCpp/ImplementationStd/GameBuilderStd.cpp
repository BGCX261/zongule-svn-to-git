#include "StdAfx.h"
#include "GameBuilderStd.h"


/*!
* \fn GameBuilderStd* GameBuilderStd::GameBuilderStd_New()
* \brief Fonction de creation d'une nouvelle instance d'un objet GameBuilderStd
* \return Instance nouvellement allouee d'un objet de type GameBuilderStd
*/
GameBuilderStd::GameBuilderStd(void)
{
}

/*!
* \fn GameBuilderStd::~GameBuilderStd(void)
* \brief Fonction de destruction d'un objet GameBuilderStd
* \return
*/
GameBuilderStd::~GameBuilderStd(void)
{
}

/*!
* \fn int GameBuilderStd::getOrbitalPosX(Color c,int longueur, int hauteur)
* \brief permet de savoir l'abscisse X de la station de couleur passee en parametre
* \param Color c	la couleur dont ont veut savoir l'abscisse
* \param int longueur	longueur de la map
* \param int hauteur	hauteur de la map
* \return abscisse de la couleur
*/
int GameBuilderStd::getOrbitalPosX(Color c,int longueur, int hauteur){
	switch(c){
	case Blue:
		return 0;
	case Red:
		return 0;
	case Green:
		return longueur-1;
	case Yellow:
		return longueur-1;
	default:
		return 0;
	}
}

/*!
* \fn int GameBuilderStd::getOrbitalPosY(Color c,int longueur, int hauteur)
* \brief permet de savoir l'ordonnee X de la station de couleur passee en parametre
* \param Color c	la couleur dont ont veut savoir l'ordonnee
* \param int longueur	longueur de la map
* \param int hauteur	hauteur de la map
* \return ordonnee de la couleur
*/
int GameBuilderStd::getOrbitalPosY(Color c,int longueur, int hauteur){
	switch(c){
	case Blue:
		return hauteur-1;
	case Red:
		return 0;
	case Green:
		return 0;
	case Yellow:
		return hauteur-1;
	default:
		return 0;
	}
}

/*!
* \fn void GameBuilderStd::setPosShip(Spaceship* s,Color c,int longueur, int hauteur)
* \brief place le vausseau s au bon endroit selon sa couleur
* \param Spaceship* s	le vaisseau à placer
* \param Color c	sa couleur
* \param int longueur	longueur de la map
* \param int hauteur	hauteur de la map
* \return
*/
void GameBuilderStd::setPosShip(Spaceship* s,Color c,int longueur, int hauteur)
{
	s->setPosX(getOrbitalPosX(c,longueur, hauteur));
	s->setPosY(getOrbitalPosY(c,longueur, hauteur));
}

/*!
* \fn Game* GameBuilderStd::createGame(int nbPlayers,int nbArtefact,std::string mapFile,Color c1, Color c2, Color c3, Color c4 )
* \brief cree le jeu en fonctions des parametres (à l'aide du monteur de jeu)
* \param int nbPlayers		le nombre de joueurs
* \param int nbArtefact		le nombre d'artefacts à recuperer pour gagner
* \param std::string mapFile	le fichier decrivant la map
* \param std::vector<Color>&	les 4 couleurs de joueur
* \param std::vector<int>& teamVec les num d'equipe des quatres joueurs
* \return Game* pointeur sur l'instance de Game creee avec le monteur
*/
Game* GameBuilderStd::createGame(int nbPlayers,int nbArtefact,std::string mapFile,std::vector<Color>& colorVec, std::vector<int>& teamVec ){
	Game* game = new GameStd();
	game->setNbPlayers(nbPlayers);
	Color c1 = colorVec[0];
	Color c2 = colorVec[1];
	Color c3 = colorVec[2];
	Color c4 = colorVec[3];

	game->setColorTab(c1,c2,c3,c4);
	game->setTeamTab(teamVec);
	game->setNbArtefactsToWin(nbArtefact);


	//map	
	MapBuilderStd mbuild = MapBuilderStd();
	Map* map = mbuild.createMap(mapFile);
	game->addMap(map);
	int longueur = map->getLongueur();
	int hauteur = map->getHauteur();

	//spaceships
	SpaceshipFactoryStd shipFact = SpaceshipFactoryStd();
	Color colorTab[4] = {c1,c2,c3,c4};
	std::vector<Player*> players = std::vector<Player*>();
	for (int i=0;i<nbPlayers;i++){
		Spaceship* s = shipFact.createMothership();
		setPosShip(s,colorTab[i],longueur,hauteur);
		Player* p = new PlayerStd(colorTab[i],s,getOrbitalPosX(colorTab[i],longueur, hauteur),getOrbitalPosY(colorTab[i],longueur, hauteur));
		players.push_back(p);
	}

	game->addPlayers(players);
	
	return game;
}

EXTERNC DLL GameBuilderStd* GameBuilderStd_New(){return new GameBuilderStd();}
EXTERNC DLL void GameBuilderStd_Delete(GameBuilderStd* g){delete g;}
