
#pragma once
#define WANTDLLEXP
#ifdef WANTDLLEXP		//exportation dll
#define DLL  __declspec( dllexport )
#define EXTERNC extern "C"
#else
#define DLL		//standard
#define EXTERNC
#endif

/*! \class Position
* \brief classe representant des coordonnees de type (x,y)
*
*/
class DLL Position
{

public:
	double x;	/*!< abscisse*/
	double y;	/*!< ordonnee*/
public:
	Position();
	Position(double nx, double ny);
	~Position();

	bool equals(Position pos);


};

	EXTERNC DLL Position* Position_New();
	EXTERNC DLL void Position_Delete(Position* gd);
