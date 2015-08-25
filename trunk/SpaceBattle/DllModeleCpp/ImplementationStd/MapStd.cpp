#include "StdAfx.h"
#include "MapStd.h"
#include "EmptySquareStd.h"
#include "ArtefactSquareStd.h"
#include "SquareFactoryStd.h"

/*!
* \fn void* MapStd::~MapStd()
* \brief Fonction de destruction d'un objet Mapstd
* \return
*/
MapStd::~MapStd(){
	
	for (int i=0;i<longueur;i++){
		for (int j=0;j<hauteur;i++){
			delete grid[i][j];
		}
	}
}

/*!
* \fn MapStd* MapStd::MapStd()
* \brief Fonction de creation d'une nouvelle instance d'un objet MapStd
* \return Instance nouvellement allouee d'un objet de type MapStd
*/
MapStd::MapStd(){

}

/*!
* \fn void MapStd::addSquare(int posx, int posy, Square* s)
* \brief ajoute la case s a la map en coordonnees (x,y)
* \param int posx, posy coordonneesoù il faut ajouter la case s
* \param Square* s la case a ajouter
* \return
*/
void MapStd::addSquare(int posx, int posy, Square* s){
	try{
		grid.at(posx).at(posy) = s;
	}
	catch(std::exception & e){
		std::cout << "addSquare : Impossible d'ajouter une case" << std::endl;
		std::cout << e.what() << std::endl;
	}
}

/*!
* \fn void MapStd::printConsole()
* \brief Affiche en console la map (utilise pour les tests)
* \return
*/
void MapStd::printConsole(){
	std::cout << "Affichage console de la map" <<std::endl;
	std::cout << "Axes inverses" <<std::endl;
	std::cout << "<-haut->" <<std::endl;
	int i,j;
	try{
		for(i=0;i<longueur;i++){
			for(j=0;j<hauteur;j++){	
				this->grid.at(i).at(j)->printConsole();
			}
			std::cout <<"\n"<< std::endl;
		}
	}	catch(std::exception & e){
		std::cout <<"\n"<< std::endl;
		std::cout << "Impossible d'ajouter une case" << std::endl;
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
}

/*!
* \fn int MapStd::getLongueur()
* \brief Retourne la longueur de la map
* \return int la longueur de la map
*/
int MapStd::getLongueur(){
	return this->longueur;
}

/*!
* \fn int MapStd::getHauteur()
* \brief Retourne la hauteur de la map
* \return int la hauteur de la map
*/
int MapStd::getHauteur(){
	return this->hauteur;
}

/*!
* \fn void MapStd::setLongueur(int l)
* \brief initialise la longueur de la map a l
* \param int l la longueur a assigner
* \return
*/
void MapStd::setLongueur(int l){
	this->longueur = l;
}

/*!
* \fn void MapStd::setHauteur(int h)
* \brief initialise la hauteur de la map a h
* \param int h la hauteur a assigner
* \return
*/
void MapStd::setHauteur(int h){
	  this->hauteur = h;
}

/*!
* \fn SquareType MapStd::getSquareType(int x,int y)
* \brief Retourne le type de la case de coordonnees (x,y)
* \param int x, y les coordonnees dont on desire connaitre le type de case
* \return SquareType le type de la case de coordonnees (x,y)
*/
SquareType MapStd::getSquareType(int x,int y){
	return grid[x][y]->getType();
}

/*!
* \fn void MapStd::initialize(int longueur, int hauteur)
* \brief Algorithme d'initialisation de la map
* \param int longueur longueur a attribuer a la map 
* \param int hauteur hauteur a attribuer a la map
* \return
*
* Declaration de la taille de la map
* et remplissage avec uniquement des cases vides pour l'instant 
*/
void MapStd::initialize(int longueur, int hauteur){
	this->setLongueur(longueur);
	this->setHauteur(hauteur);
	std::vector<std::vector<Square*>> v1;
	SquareFactory* sq = new SquareFactoryStd();

	for (int i=0;i<longueur;i++){
		std::vector<Square*> v;
		v1.push_back(v);
		for (int j=0;j<hauteur;j++){
			v1.at(i).push_back(sq->createEmptySquare());
		}
	}
	grid = v1;
}

/*!
* \fn Square* MapStd::getSquare(int posx, int posy)
* \brief Retourne la case de coordonnees (x,y)
* \param int x, y les coordonnees de la case
* \return Square* la case de coordonnees (x,y)
*/
Square* MapStd::getSquare(int posx, int posy){
	return grid.at(posx).at(posy);
}

/*!
* \fn void MapStd::setValidMap(bool b)
* \brief Setter de validatedMap
* \param bool b
* \return
*/
void MapStd::setValidMap(bool b){
	validMap=b;
}

/*!
* \fn bool MapStd::isValidMap()
* \brief Renvoie si la map est valide ou pas
* \return bool true si la map est valide, false sinon
*/
bool MapStd::isValidMap(){
	return validMap;
}

EXTERNC DLL MapStd* MapStd_New(){return new MapStd();}
EXTERNC DLL void MapStd_Delete(MapStd* m){delete m;}
