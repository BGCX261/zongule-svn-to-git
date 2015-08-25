#include "TestsMap.h"




using namespace std;

TestsMap::TestsMap(void){}
TestsMap::~TestsMap(void){}

void TestsMap::runLectureSimple(){
	MapBuilderStd* mapBuilder = new MapBuilderStd();
	//Map* map = mapBuilder->createTestMap();
	//map->printConsole();

	//tests sur la lecture dans un fichier
	std::string filename = "testmap2.txt";
	std::ifstream mapfile(filename, std::ios::in);
	if(!mapfile.fail()){
		std::cout << "File " << filename << " successfully opened." << std::endl;
		std::string tmp; //string qui sera lu
		int x = 0; //abcisse de la case a construire
		int y = 0; //ordonnee de la case a construire
		
		mapfile>>tmp;
		std::cout << tmp <<std::endl;

		mapfile>>tmp;
		x = mapBuilder->stringToInt(tmp);
		std::cout << x <<std::endl;

		mapfile>>tmp;
		y = mapBuilder->stringToInt(tmp);
		std::cout << tmp <<std::endl;
				
		mapfile.close();
	}
	else
	{
		std::cout << "File " << filename << " does NOT exist." << std::endl;
	}
}

void TestsMap::runLecturePlateau(){
	std::string filename = "testmap3.txt";
	MapBuilderStd* mapBuilder = new MapBuilderStd();
	Map* map = mapBuilder->createMap(filename);
	//map->printConsole();
}

void TestsMap::runLectureSansAsteroides(){
	std::string filename = "testmap4.txt";
	MapBuilderStd* mapBuilder = new MapBuilderStd();
	Map* map = mapBuilder->createMap(filename);
	map->printConsole();
}

void TestsMap::runLectureTotale(){
	std::string filename = "testmap2.txt";
	MapBuilderStd* mapBuilder = new MapBuilderStd();
	Map* map = mapBuilder->createMap(filename);
	map->printConsole();
}