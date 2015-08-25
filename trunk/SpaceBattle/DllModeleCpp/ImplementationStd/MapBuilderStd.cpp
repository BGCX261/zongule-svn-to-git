#include "StdAfx.h"
#include "MapBuilderStd.h"


/*!
* \fn MapBuilderStd* MapBuilderStd::MapBuilderStd(void)
* \brief Fonction de creation d'une nouvelle instance d'un objet MapBuilderStd
* \return Instance nouvellement allouee d'un objet de type MapBuilderStd
*/
MapBuilderStd::MapBuilderStd(void)
{
	factory = new SquareFactoryStd();
}

/*!
* \fn void MapBuilderStd::~MapBuilderStd(void)
* \brief Fonction de destruction d'un objet MapBuilderStd
* \return
*/
MapBuilderStd::~MapBuilderStd(void)
{
	delete factory;
}

/*!
* \fn void MapBuilderStd::initializeCheckers()
* \brief Initialise les attributs
* \return 
*/
void MapBuilderStd::initializeCheckers(){
	orbitalStationsNb=0;
	artefactsNb=0;
	energiesNb=0;
}

/*!
* \fn Map* MapBuilderStd::createMap(std::string filename)
* \brief Cree une map a partir du fichier de description de map
* \return Map* pointeur sur la map creee a partir du fichier passe en parametre
*/
Map* MapBuilderStd::createMap(std::string filename){
	this->initializeCheckers();
	//creation d'une Map
	MapStd* map = new MapStd();

	//ouverture du flux
	std::ifstream mapfile(filename, std::ios::in);

	if(!mapfile.fail()){
		//std::cout << "File " << filename << " successfully opened." << std::endl;

		std::string tmp_str; //string qui sera lu
		std::string square; //type de la case a construire
		int x = 0; //abcisse de la case a construire
		int y = 0; //ordonnee de la case a construire
		int longueur = 0;
		int hauteur = 0;
		std::vector<int> coordVector; //vector de coordonnees pour les asteroides

 		while(mapfile.good())
		{
			mapfile>>tmp_str;

			if(tmp_str=="P" ||tmp_str=="\'P\'" ){
				square = tmp_str;
				mapfile>>tmp_str;
				x = this->stringToInt(tmp_str);
				mapfile>>tmp_str;
				y = this->stringToInt(tmp_str);
				
				if(x>=0 && y >=0){
					map->setLongueur(x);
					longueur = x;
					map->setHauteur(y);
					hauteur = y;
					map->initialize(longueur,hauteur);
				}
				else{
					//std::cout << "Impossible to build the map" << std::endl;
					map->setValidMap(false);
					return map;
				}

			}
			else if(tmp_str=="O"||tmp_str=="\'O\'"){
				//on ajoute une station orbitale
				square = tmp_str;
				mapfile>>tmp_str;
				x = this->stringToInt(tmp_str);
				mapfile>>tmp_str;
				y = this->stringToInt(tmp_str);
				if(x>=0 && x<longueur && y>=0 && y<hauteur && orbitalStationsNb<5){
					map->addSquare(x,y,factory->createOrbitalStationSquare());
					orbitalStationsNb++;
				}
				else{
					//std::cout << "Impossible to build the map" << std::endl;
					map->setValidMap(false);
					return map;
				}
			}
			else if(tmp_str=="A"||tmp_str=="\'A\'"){
				//on ajoute un artefact
				square = tmp_str;
				mapfile>>tmp_str;
				x = this->stringToInt(tmp_str);
				mapfile>>tmp_str;
				y = this->stringToInt(tmp_str);
				if(x>=0 && x<longueur && y>=0 && y<hauteur){
					map->addSquare(x,y,factory->createArtefactSquare());
					artefactsNb++;
				}
				else{
					//std::cout << "Impossible to build the map" << std::endl;
					map->setValidMap(false);
					return map;
				}
			}
			else if(tmp_str=="E"||tmp_str=="\'E\'"){
				//on ajoute une station d'energie
				square = tmp_str;
				mapfile>>tmp_str;
				x = this->stringToInt(tmp_str);
				mapfile>>tmp_str;
				y = this->stringToInt(tmp_str);
				if(x>=0 && x<longueur && y>=0 && y<hauteur){
					map->addSquare(x,y,factory->createEnergyStationSquare());
					energiesNb++;
				}
				else{
					//std::cout << "Impossible to build the map" << std::endl;
					map->setValidMap(false);
					return map;
				}
			}
			
			else if(tmp_str=="D"||tmp_str=="\'D\'"){
				//on ajoute une asteroide composee de plusieurs coordonnees
				square = tmp_str;

				while((mapfile>>tmp_str) && (stillAnAsteroid(tmp_str))){	
					x = this->stringToInt(tmp_str);
					mapfile>>tmp_str;
					y = this->stringToInt(tmp_str);

					if(x>=0 && x<longueur && y>=0 && y<hauteur){
						coordVector.push_back(x);
						coordVector.push_back(y);
					}
					else{
						//std::cout << "Impossible to build the map" << std::endl;
						map->setValidMap(false);
						return map;
					}
				}
				try{
					for(unsigned int k=0; k<coordVector.size()-1; k=k+2){
					map->addSquare(coordVector[k],coordVector[k+1],factory->createAsteroidSquare());
					}
				}
				catch(std::exception & e){
					//std::cout << "sorti du vector" << std::endl;
					map->setValidMap(false);
					//std::cout << e.what() << std::endl;
				}
				coordVector.clear();
				//reculer d'un mot si "D", deux trois mots si "'D'"
				if (tmp_str == "\'D\'"){
					mapfile.unget();				
					mapfile.unget();
					mapfile.unget();
				}
				else mapfile.unget();
			}
			
			else if(tmp_str=="\n"){
				//std::cout << "saut de ligne" <<std::endl;
			}
			else{
				//std::cout << "Erreur dans le fichier" <<std::endl;
				map->setValidMap(false);
				return map;
			}
		}
		//std::cout << "fin de lecture" << std::endl;
		mapfile.close();
	}

	else
	{
		//std::cout << "File " << filename << " does NOT exist." << std::endl;
		map->setValidMap(false);
		return map;
	}

	if(orbitalStationsNb!=4 || artefactsNb==0 || energiesNb==0){
		//std::cout << "Contraintes du nombre d'elements pas respectees" << std::endl;
		map->setValidMap(false);
		return map;
	}
	map->setValidMap(true);
	return map;


}

/*!
* \fn int MapBuilderStd::stringToInt(const std::string & str)
* \brief Converti un entier lu dans la string str en int
* \return int entier lu dans str
*/
int MapBuilderStd::stringToInt(const std::string & str){
    std::istringstream iss(str);
	int tmp;
	iss >> tmp;
	return tmp;
}

/*!
* \fn bool MapBuilderStd::stillAnAsteroid(const std::string & str)
* \brief Appele dans createMap, permet de savoir si on lit bien la description d'un asteroide
* \return bool vrai si on lit encore la description d'un asteroide, faux sinon
*/
bool MapBuilderStd::stillAnAsteroid(const std::string & str){
	return (str!="P" && str!="\'P\'") && (str!="O" && str!="\'O\'") && (str!="A"&& str!="\'A\'") && (str!="E"&& str!="\'E\'") && (str!="D" && str!="\'D\'") && (str!="\n");
}



EXTERNC DLL MapBuilderStd* MapBuilderStd_New(){return new MapBuilderStd();}
EXTERNC DLL void MapBuilderStd_Delete(MapBuilderStd* m){delete m;}
