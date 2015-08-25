#include "StdAfx.h"
#include "ShootStatus.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include "Position.h"
#include <string>
#include <math.h>

/*!
* \fn ShootStatus* ShootStatus::ShootStatus_New()
* \brief Fonction de creation d'une nouvelle instance d'un objet ShootStatus
* \return Instance nouvellement allouee d'un objet de type ShootStatus
*/
ShootStatus::ShootStatus(){
}

/*!
* \fn ShootStatus* ShootStatus::ShootStatus_New(Game* g)
* \brief Fonction de creation d'une nouvelle instance d'un objet ShootStatus, en lui associant la partie g
* \param Game* g la partie a associer a l'etat "tirer"
* \return Instance nouvellement allouee d'un objet de type ShootStatus, associee a g
*/
ShootStatus::ShootStatus(Game* g){
	game = g;
}

/*!
* \fn void ShootStatus::~ShootStatus()
* \brief Fonction de destruction d'un objet ShootStatus
* \return
*/
ShootStatus::~ShootStatus(){
	delete game;
}

/*!
* \fn std::vector<Position> ShootStatus::getLastShootTrace()
* \brief retourne l'attribut getLastShootTrace
* \return std::vector<Position> l'atttribut getLastShootTrace
*/
std::vector<Position> ShootStatus::getLastShootTrace(){
	return lastShootTrace;
}

/*!
* \fn double ShootStatus::DegToRad(double x)
* \brief Conversion d'un angle en degres vers un angle en radians
* \param double x angle en degres
* \return double l'angle x converti en radians
*/
double DegToRad(double x)
{
    return x / 180 * 3.141592654;
}

/*!
* \fn double ShootStatus::RadToDeg(double x)
* \brief Conversion d'un angle en radians vers un angle en degres
* \param double x angle en radians
* \return double l'angle x converti en degres
*/
double RadToDeg(double x)
{
    return (x / 3.141592654) * 180;
}

/*!
* \fn double ShootStatus::getAngle(double xa,double ya,double xb, double yb)
* \brief Calcul de l'angle d'une droite dont les points sont en parametres
* \param xa,ya point A
* \param xn,yb point B
* \return double l'angle en degres de la droite (AB)
*/
double getAngle(double xa,double ya,double xb, double yb){
	if (xa==xb){
		if (yb<ya) return 90;
		else return 270;
	}
	else{
		if (xb>=xa && yb>=ya) return 360-RadToDeg(atan ( (yb-ya) / (xb-xa) )); 
		if (xb>=xa && yb<ya) return -RadToDeg(atan ( (yb-ya) / (xb-xa) )); 
		if (xb<xa && yb>=ya) return 180 - RadToDeg(atan ( (yb-ya) / (xb-xa) )); 
		if (xb<xa && yb<ya) return 180 - RadToDeg(atan ( (yb-ya) / (xb-xa) )); 
	}
	return 0; 
}

/*!
* \fn ShootStatusType ShootStatus::getType()
* \brief retourne le type d'etat (de l'enum StatusType)
* \return GameStatusType ShootStatus
*/
GameStatusType ShootStatus::getType(){
	return ShootType;
}

/*!
* \fn void ShootStatus::doAction(double posx,double posy,int playerNb)
* \brief realise l'action associee a l'etat "tirer", en l'occurence tirer un laser
* \param double posx, posy
* \param int playerNb
* \return
*/
void ShootStatus::doAction(double posx,double posy,int playerNb){
	int currentPlayer = game->getCurrentPlayer();
	Player* player = game->getPlayer(currentPlayer);
	lastShootTrace.clear();
	if (!(player->getSpaceship()->canShoot())) return;
	
	player->getSpaceship()->decreaseShotsRemaining();
	//+0.5 pour se placer au centre de la case
	double sourcePosX = game->getPlayerPosX(currentPlayer)+0.5;
	double sourcePosY = game->getPlayerPosY(currentPlayer)+0.5;
	lastShootTrace.push_back(Position(sourcePosX,sourcePosY));

	int reboundNumber = player->getSpaceship()->getReboundNumber();

	shoot(sourcePosX,sourcePosY,posx,posy,reboundNumber);
}

/*!
* \fn void ShootStatus::shoot(double sourcePosX,double sourcePosY,double posx,double posy,int reboundNumber)
* \brief Realise un tir laser entre les coordonnees sourcePosx,sourcePosY et posx,posy, en accord avec le nombre de rebonds restants
* \param double sourcePosx, sourcePosy les coordonnees de depart du tir
* \param double posx, posy les coordonnees d'arrivee du tir
* \param int reboundNumber le nombre de rebonds restants
* \return
*/
void ShootStatus::shoot(double sourcePosX,double sourcePosY,double posx,double posy,int reboundNumber){

	double angleDroite = getAngle(sourcePosX,sourcePosY,posx,posy);

	std::map<double,Position> casesTraversees;
	std::map<double,Position>::iterator it;
	
	//Calcul des cases traversees par le tir selon l'angle du tir
	if ((angleDroite >= 0) && (angleDroite <90)) {
		casesTraversees = shootUpRight(posx,posy,sourcePosX,sourcePosY);
	}
	if ((angleDroite >= 270) && (angleDroite <360)) {
		casesTraversees = shootDownRight(posx,posy,sourcePosX,sourcePosY);
	}
	if ((angleDroite >= 90) && (angleDroite <180)) {
		casesTraversees = shootUpLeft(posx,posy,sourcePosX,sourcePosY);
	}
	if ((angleDroite >= 180) && (angleDroite <270)) {
		casesTraversees = shootDownLeft(posx,posy,sourcePosX,sourcePosY);
	}

	std::vector<Position> playersPos = game->getPlayersPosition();
	std::vector<Position> asteroidPos = game->getAsteroidsPosition();
	 
	int reboundAsteroid = -1;

	//Iteration sur les cases traversees pour arreter le tir au bon endroit
	for (it = casesTraversees.begin();(it != casesTraversees.end()) && (reboundAsteroid==-1);it++ ){
		//case joueur : tue eventuellement le joueur
		for (int i=0;(i<playersPos.size()) ;i++){
			if (playersPos[i].equals((*it).second)) {
				std::cout << "case joueur traversee" << std::endl;
				Position rebondPos = calculateAsteroidRebound(sourcePosX,sourcePosY,posx,posy,playersPos[i]);
				lastShootTrace.push_back(rebondPos);
				int currentPlayer = game->getCurrentPlayer();
				Player* player = game->getPlayer(currentPlayer);
				int reboundPlayer = player->getSpaceship()->getReboundNumber();
				//on ne tue pas avant le premier rebond
				if (reboundNumber != reboundPlayer) game->shootPlayer(i); 
				return;
			}
		}
		//case asteroide
		for (int i=0;(i<asteroidPos.size()) && (reboundAsteroid==-1);i++){
			if (asteroidPos[i].equals((*it).second)) {
				std::cout << "case asteroid traversee: "<<(*it).second.x<<"-"<<(*it).second.y << std::endl;
				//game->shootAsteroid(asteroidPos[i].x,asteroidPos[i].y)
				reboundAsteroid = i;
			}
		}
		
	}
	//rebond sur asteroide
	if (reboundAsteroid!=-1){
		Position rebondPos = calculateAsteroidRebound(sourcePosX,sourcePosY,posx,posy,asteroidPos[reboundAsteroid]);
		std::cout << "rebond coordonnee "<<rebondPos.x<<"-"<<rebondPos.y<<std::endl;
		lastShootTrace.push_back(rebondPos);
		reboundNumber--;
		Position newPos = calculateNewPosition(angleDroite,rebondPos.x,rebondPos.y);
		if (reboundNumber>=0) shoot(rebondPos.x,rebondPos.y,newPos.x,newPos.y,reboundNumber);
	}

	//sinon rebond sur le bord
	else{
		std::map<double,Position>::reverse_iterator rit;
		rit = casesTraversees.rbegin();
		if (rit==casesTraversees.rend()) return;
		std::cout << "rebond case bord:" <<(rit->second).x<<" - "<<(rit->second).y<<std::endl;
		Position rebondPos = calculateEdgeRebound(sourcePosX,sourcePosY,posx,posy,rit->second);
	    std::cout << "rebond bord coordonnee "<<rebondPos.x<<"-"<<rebondPos.y<<std::endl;
		lastShootTrace.push_back(rebondPos);
		reboundNumber--;
		Position newPos = calculateNewPosition(angleDroite,rebondPos.x,rebondPos.y);
		if (reboundNumber>=0) shoot(rebondPos.x,rebondPos.y,newPos.x,newPos.y,reboundNumber);
	}
}

/*!
* \fn Position ShootStatus::calculateAsteroidRebound(double sourcePosX,double sourcePosY,double posx,double posy, Position square)
* \brief Fonction calculant la position exacte de rebond sur un asteroide present sur la case square
* \param double sourcePosx, sourcePosy les coordonnees de depart du tir
* \param double posx, posy les coordonnees d'arrivee du tir
* \param Position square la case sur laquelle est present l'asteroide
* \return Position la position exacte de rebond du tir sur l'asteroide
*/
Position ShootStatus::calculateAsteroidRebound(double sourcePosX,double sourcePosY,double posx,double posy, Position square){
	    double coeffDir = (posy-sourcePosY) / (posx-sourcePosX) ;
		double ordOrig =  sourcePosY - coeffDir*sourcePosX;
		double xIntersection;
		double newy;
		double yIntersection;
		double newx;
		if (sourcePosY > posy){
			//intersection de la droite avec l'axe des y inferieur de la case
			newy = square.y+1;
			xIntersection = ((newy)-ordOrig)/coeffDir;	
			std::cout<<"intersection bas ";
		}
		else{
			newy = square.y;
			//intersection de la droite avec l'axe des y superieur de la case
			xIntersection = ((newy)-ordOrig)/coeffDir;
			std::cout<<"intersection haut ";
		}
		if (sourcePosX>posx){
			newx = square.x+1;
			//intersection de la droite avec l'axe droit des x de la case
			yIntersection = coeffDir*(newx)+ordOrig;
			std::cout<<" droite "<<std::endl;
		}
		else{
			newx = square.x;
			//intersection de la droite avec l'axe gauche des x de la case
			yIntersection = coeffDir*(newx)+ordOrig;
			std::cout<<" gauche "<<std::endl;
		}

		if (!((xIntersection>=square.x)&&(xIntersection<=(square.x+1)))){ //si xIntersection non valide
			std::cout <<"xIntersection non valide"<<std::endl;
			return Position(newx,yIntersection);
		}
		else if (!((yIntersection>=square.y)&&(yIntersection<=(square.y+1)))){ // si yIntersection non valide
			std::cout <<"yIntersection non valide"<<std::endl;
			return Position(xIntersection,newy);
		}

		else{
			std::cout<<"pas normal !!"<<std::endl;
			return Position(1,1);
		}
 }

/*!
* \fn Position ShootStatus::calculateEdgeRebound(double sourcePosX,double sourcePosY,double posx,double posy, Position square)
* \brief Fonction calculant la position exacte de rebond sur le bord de la carte defini par la case square
* \param double sourcePosx, sourcePosy les coordonnees de depart du tir
* \param double posx, posy les coordonnees d'arrivee du tir
* \param Position square la case sur laquelle est present le rebord sur lequel doit se faire le rebond
* \return Position la position exacte de rebond du tir sur le bord de la carte
*/
Position ShootStatus::calculateEdgeRebound(double sourcePosX,double sourcePosY,double posx,double posy, Position square){
	    double coeffDir = (posy-sourcePosY) / (posx-sourcePosX) ;
		double ordOrig =  sourcePosY - coeffDir*sourcePosX;
		double xIntersection;
		double newy;
		double yIntersection;
		double newx;
		if (sourcePosY > posy){
			//intersection de la droite avec l'axe des y superieur de la case
			newy = square.y;
			xIntersection = ((newy)-ordOrig)/coeffDir;	
			std::cout<<"bord: intersection haut ";
		}
		else{
			newy = square.y+1;
			//intersection de la droite avec l'axe des y inferieur de la case
			xIntersection = ((newy)-ordOrig)/coeffDir;
			std::cout<<"bord : intersection bas ";
		}
		if (sourcePosX>posx){
			newx = square.x;
			//intersection de la droite avec l'axe gauche des x de la case
			yIntersection = coeffDir*(newx)+ordOrig;
			std::cout<<" bord : gauche "<<std::endl;
		}
		else{
			newx = square.x+1;
			//intersection de la droite avec l'axe droit des x de la case
			yIntersection = coeffDir*(newx)+ordOrig;
			std::cout<<"bord : droite "<<std::endl;
		}

		if (!((xIntersection>=square.x)&&(xIntersection<=(square.x+1)))){ //si xIntersection non valide
			std::cout <<"bord : xIntersection non valide"<<std::endl;
			return Position(newx,yIntersection);
		}
		else if (!((yIntersection>=square.y)&&(yIntersection<=(square.y+1)))){ // si yIntersection non valide
			std::cout <<"bord : yIntersection non valide"<<std::endl;
			return Position(xIntersection,newy);
		}

		else{
			std::cout<<"pas normal !!"<<std::endl;
			return Position(1,1);
		}
 }

/*!
* \fn Position ShootStatus::calculateNewPosition(double previousAngle,double shootPointX,double shootPointY)
* \brief Renvoie la position vers lequel le tir se dirigera apres le rebond en calculant le nouvel angle de tir
* \param double previousAngle l'angle de tir precedent le rebond
* \param double shootPointX l'abscisse du point de rebond
* \param double shootPointY l'ordonnee du point de rebond
* \return Position la position vers lequel le tir se dirigera apres le rebond
*/
Position ShootStatus::calculateNewPosition(double previousAngle,double shootPointX,double shootPointY){
	double newAngle;
	if ((previousAngle >= 0) && (previousAngle <90)) {
		if ((double)(int)shootPointX == shootPointX) //rebond côte gauche de la case
			newAngle = 180 - previousAngle;
		else //rebond côte bas
			newAngle = 270 + (90-previousAngle);		
	}
	else if ((previousAngle >= 270) && (previousAngle <360)) {
		if ((double)(int)shootPointX == shootPointX) //rebond côte gauche de la case
			newAngle = 180 + (360-previousAngle);
		else //rebond côte haut
			newAngle = (360 - previousAngle);			
	}
	else if ((previousAngle >= 90) && (previousAngle <180)) {
		if ((double)(int)shootPointX == shootPointX) //rebond côte droit de la case
			newAngle = 180 - previousAngle;
		else //rebond côte bas
			newAngle = 180 + (180-previousAngle);
	}
	else{// ((previousAngle >= 180) && (angleDroite <270)) 
		if ((double)(int)shootPointX == shootPointX) //rebond côte droit de la case
			newAngle = 360 - (previousAngle - 180);
		else //rebond côte haut
			newAngle = 180- (previousAngle-180);
	}

	double x = cos(DegToRad(newAngle));
	double y = sin(DegToRad(newAngle));
	return Position(shootPointX+x,shootPointY-y); //y inverse sur la map par rapport au cercle trigo classique
}


/*!
* \fn void ShootStatus::removeFirstSquare(double sourcePosX,double sourcePosY,std::map<double,Position>* casesTraversees)
* \brief Enleve la case où est le vaisseau qui a tire le laser du tableau des cases traversees par le laser
* \param double sourcePosX
* \param double sourcePosY
* \param std::map<double,Position>* casesTraversees
* \return
*/
void ShootStatus::removeFirstSquare(double sourcePosX,double sourcePosY,std::map<double,Position>* casesTraversees){
	Position posDepart = Position((int)sourcePosX,(int)sourcePosY);
	std::map<double,Position>::iterator it;
		for (it = casesTraversees->begin();it != casesTraversees->end();it++ ){
					if ((*it).second.equals(posDepart)){
						std::cout << std::string("erase")<<(*it).second.x<<"-"<<(*it).second.y<<std::endl;
						casesTraversees->erase(it);
						
						break;
					}
		}
}

/*!
* \fn std::map<double,Position> ShootStatus::shootUpRight(double posx,double posy,double sourcePosX,double sourcePosY)
* \brief Calcule les cases traversees par un tir avec un angle compris entre 0 et 90°
* \param double posx, posy les coordonnees d'arrivee du tir 
* \param double sourcePosX, sourcePosY les coordonnees de depart du tir
* \return std::map<double,Position> une Map comportant des couples (distance, case traversee)
*/
std::map<double,Position> ShootStatus::shootUpRight(double posx,double posy,double sourcePosX,double sourcePosY){
	 //tir direction haut-droite
	 std::cout << "shoot upright"<<std::endl;
		int xMax = game->getMapLongueur();
		int yMax = game->getMapHauteur();
		std::map<double,Position> casesTraversees;
		std::map<double,Position>::iterator it;
		double coeffDir = (posy-sourcePosY) / (posx-sourcePosX) ;
		double ordOrig =  sourcePosY - coeffDir*sourcePosX;
		//boucle sur les x
		for (int x = (int)sourcePosX+1;x<=xMax;x++){
			double yIntersection = coeffDir*x+ordOrig;
			if (yIntersection>=0 && yIntersection<=yMax) {
				Position pos = Position(x-1,(int)yIntersection);
				double distance = getDist(sourcePosX,sourcePosY,x,yIntersection);
				casesTraversees[distance] = pos;
			}
		}
		//boucle sur les y
		for(int y=0;y<=(int)sourcePosY;y++){
			double xIntersection = (y-ordOrig)/coeffDir;
			if (xIntersection>=sourcePosX && xIntersection<xMax){
				Position pos = Position((int)xIntersection,y);
				bool trouve = false;
				for (it = casesTraversees.begin();it != casesTraversees.end();it++ ){
					if ((*it).second.equals(pos)) {
						trouve=true;
						double oldDist = (*it).first;
						double newDist = getDist(sourcePosX,sourcePosY,xIntersection,y);
						if (newDist<oldDist) {
							casesTraversees.erase(it);
							casesTraversees[newDist] = pos;
							break;
						}
					}
				}
				if (!trouve){
					double distance = getDist(sourcePosX,sourcePosY,xIntersection,y);
					casesTraversees[distance]=pos;
				}
			}
		}
		//enlever la case de depart si on est pas dans un coin (coin => une seule case, a garder)
		if (casesTraversees.size() != 1){
			removeFirstSquare(sourcePosX,sourcePosY,&casesTraversees);
		}
		return casesTraversees;
 }

/*!
* \fn std::map<double,Position> ShootStatus::shootDownRight(double posx,double posy,double sourcePosX,double sourcePosY)
* \brief Calcule les cases traversees par un tir avec un angle compris entre 270 et 0°
* \param double posx, posy les coordonnees d'arrivee du tir 
* \param double sourcePosX, sourcePosY les coordonnees de depart du tir
* \return std::map<double,Position> une Map comportant des couples (distance, case traversee)
*/
std::map<double,Position> ShootStatus::shootDownRight(double posx,double posy,double sourcePosX,double sourcePosY){

	  std::cout << "shoot downright"<<std::endl;
		int xMax = game->getMapLongueur();
		int yMax = game->getMapHauteur();
		std::map<double,Position> casesTraversees;
		std::map<double,Position>::iterator it;
		double coeffDir = (posy-sourcePosY) / (posx-sourcePosX) ;
		double ordOrig =  sourcePosY - coeffDir*sourcePosX;
		//boucle sur les x
		for (int x = (int)sourcePosX+1;x<=xMax;x++){
			double yIntersection = coeffDir*x+ordOrig;
			if (yIntersection>=0 && yIntersection<=yMax) {
				Position pos = Position(x-1,(int)yIntersection);
				double distance = getDist(sourcePosX,sourcePosY,x,yIntersection);
				casesTraversees[distance] = pos;
			}
		}
		//boucle sur les y
		for(int y=(int)sourcePosY+1;y<=(int)yMax;y++){
			double xIntersection = (y-ordOrig)/coeffDir;
			if (xIntersection>=sourcePosX && xIntersection<xMax){
				Position pos = Position((int)xIntersection,y-1);
				bool trouve = false;
				for (it = casesTraversees.begin();it != casesTraversees.end();it++ ){
					if ((*it).second.equals(pos)) {
						trouve=true;
						double oldDist = (*it).first;
						double newDist = getDist(sourcePosX,sourcePosY,xIntersection,y);
						if (newDist<oldDist) {
							casesTraversees.erase(it);
							casesTraversees[newDist] = pos;
							break;
						}
					}
				}
				if (!trouve){
					double distance = getDist(sourcePosX,sourcePosY,xIntersection,y);
					casesTraversees[distance]=pos;
				}
			}
		}
		//enlever la case de depart si on est pas dans un coin (coin => une seule case, a garder)
		if (casesTraversees.size() != 1){
			if (casesTraversees.size() != 1){
			removeFirstSquare(sourcePosX,sourcePosY,&casesTraversees);
			}
		}
		return casesTraversees;

 }

/*!
* \fn std::map<double,Position> ShootStatus::shootUpLeft(double posx,double posy,double sourcePosX,double sourcePosY)
* \brief Calcule les cases traversees par un tir avec un angle compris entre 90 et 180°
* \param double posx, posy les coordonnees d'arrivee du tir 
* \param double sourcePosX, sourcePosY les coordonnees de depart du tir
* \return std::map<double,Position> une Map comportant des couples (distance, case traversee)
*/
 std::map<double,Position> ShootStatus::shootUpLeft(double posx,double posy,double sourcePosX,double sourcePosY){
	 std::cout << "shoot upleft"<<std::endl;
		int xMax = game->getMapLongueur();
		int yMax = game->getMapHauteur();
		std::map<double,Position> casesTraversees;
		std::map<double,Position>::iterator it;
		double coeffDir = (posy-sourcePosY) / (posx-sourcePosX) ;
		double ordOrig =  sourcePosY - coeffDir*sourcePosX;
		//boucle sur les x
		for (int x = 0;x<=sourcePosX;x++){
			double yIntersection = coeffDir*x+ordOrig;
			if (yIntersection>=0 && yIntersection<=sourcePosY) {
				Position pos = Position(x,(int)yIntersection);
				double distance = getDist(sourcePosX,sourcePosY,x,yIntersection);
				casesTraversees[distance] = pos;
			}
		}
		//boucle sur les y
		for(int y=0;y<=(int)sourcePosY;y++){
			double xIntersection = (y-ordOrig)/coeffDir;
			if (xIntersection>=0 && xIntersection<=sourcePosX){
				Position pos = Position((int)xIntersection,y);
				bool trouve = false;
				for (it = casesTraversees.begin();it != casesTraversees.end();it++ ){
					if ((*it).second.equals(pos)) {
						trouve=true;
						double oldDist = (*it).first;
						double newDist = getDist(sourcePosX,sourcePosY,xIntersection,y);
						if (newDist<oldDist) {
							casesTraversees.erase(it);
							casesTraversees[newDist] = pos;
							break;
						}
					}
				}
				if (!trouve){
					double distance = getDist(sourcePosX,sourcePosY,xIntersection,y);
					casesTraversees[distance]=pos;
				}
			}
		}
		//enlever la case de depart si on est pas dans un coin (coin => une seule case, a garder)
		if (casesTraversees.size() != 1){
			if (casesTraversees.size() != 1){
			removeFirstSquare(sourcePosX,sourcePosY,&casesTraversees);
			}
		}
		return casesTraversees;
 }

 /*!
* \fn std::map<double,Position> ShootStatus::shootDownLeft(double posx,double posy,double sourcePosX,double sourcePosY)
* \brief Calcule les cases traversees par un tir avec un angle compris entre 180 et 270°
* \param double posx, posy les coordonnees d'arrivee du tir 
* \param double sourcePosX, sourcePosY les coordonnees de depart du tir
* \return std::map<double,Position> une Map comportant des couples (distance, case traversee)
*/
 std::map<double,Position> ShootStatus::shootDownLeft(double posx,double posy,double sourcePosX,double sourcePosY){
	 std::cout << "shoot downleft"<<std::endl;
		int xMax = game->getMapLongueur();
		int yMax = game->getMapHauteur();
		std::map<double,Position> casesTraversees;
		std::map<double,Position>::iterator it;
		double coeffDir = (posy-sourcePosY) / (posx-sourcePosX) ;
		double ordOrig =  sourcePosY - coeffDir*sourcePosX;
		//boucle sur les x
		for (int x = 0;x<=sourcePosX;x++){
			double yIntersection = coeffDir*x+ordOrig;
			if (yIntersection>=sourcePosY && yIntersection<=yMax) {
				Position pos = Position(x,(int)yIntersection);
				double distance = getDist(sourcePosX,sourcePosY,x,yIntersection);
				casesTraversees[distance] = pos;
			}
		}
		//boucle sur les y
		for(int y=(int)sourcePosY+1;y<=yMax;y++){
			double xIntersection = (y-ordOrig)/coeffDir;
			if (xIntersection>=0 && xIntersection<sourcePosX){
				Position pos = Position((int)xIntersection,y-1);
				bool trouve = false;
				for (it = casesTraversees.begin();it != casesTraversees.end();it++ ){
					if ((*it).second.equals(pos)) {
						trouve=true;
						double oldDist = (*it).first;
						double newDist = getDist(sourcePosX,sourcePosY,xIntersection,y);
						if (newDist<oldDist) {
							casesTraversees.erase(it);
							casesTraversees[newDist] = pos;
							break;
						}
					}
				}
				if (!trouve){
					double distance = getDist(sourcePosX,sourcePosY,xIntersection,y);
					casesTraversees[distance]=pos;
				}
			}
		}
		//enlever la case de depart si on est pas dans un coin (coin => une seule case, a garder)
		if (casesTraversees.size() != 1){
			if (casesTraversees.size() != 1){
			removeFirstSquare(sourcePosX,sourcePosY,&casesTraversees);
			}
		}
		return casesTraversees;

 }

/*!
* \fn double ShootStatus::getDist(double sourcePosX,double sourcePosY,double posx,double posy)
* \brief Calcule la distance entre le point source et le 2e point en parametre
* \param double sourcePosX Abscisse du point source
* \param double sourcePosY Ordonnee du point source
* \param double posx Abscisse du 2e point
* \param double posy Ordonnee du 2e point
* \return double distance entre le point source et le 2e point
*/
double ShootStatus::getDist(double sourcePosX,double sourcePosY,double posx,double posy){

   return sqrt((sourcePosX-posx)*(sourcePosX-posx)+(sourcePosY-posy)*(sourcePosY-posy));
 }


EXTERNC DLL ShootStatus* ShootStatus_New(){return new ShootStatus();}
EXTERNC DLL void ShootStatus_Delete(ShootStatus* a){delete a;}
