#include "StdAfx.h"
#include "Position.h"

/*!
* \fn Position* Position::Position_New()
* \brief Fonction de creation d'une nouvelle instance d'un objet Position
* \return Instance nouvellement allouee d'un objet de type Position
*/
Position::Position(){}

/*!
* \fn Position* Position::Position_New()
* \brief Fonction de creation d'une nouvelle instance d'un objet Position en fonction des coordonnees passees en parameter
* \param double nx abcisse a attribuer
* \param double ny ordonnee a attribuer
* \return Instance nouvellement allouee d'un objet de type Position
*/
Position::Position(double nx, double ny){
		x=nx;
		y=ny;
}

/*!
* \fn void Position::Position_Delete()
* \brief Fonction de destruction d'un objet Position
* \return
*/
Position::~Position()
{
}

/*!
* \fn bool Position::equals(Position p)
* \brief Fonction equals entre 2 positions
* \return true si memes coordonnees, false sinon
*/
bool Position::equals(Position pos){
		return (pos.x == this->x) && (pos.y==this->y);
	}


EXTERNC DLL Position* Position_New(){return new Position();}
EXTERNC DLL void Position_Delete(Position* a){delete a;}
