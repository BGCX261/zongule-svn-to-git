
#include <iostream>
#include "..\TestsDllModeleCpp\TestsMap.h"

#pragma comment (lib,"DllModeleCpp.lib")

using namespace std;

int main( int argc, const char* argv[] )
{
	std::cout << "Tests" <<std::endl ;

	//TestsDice td;
	//td.run();

	TestsMap tm;
	tm.runLectureTotale();




	char a;
	std::cin >> a;

}
