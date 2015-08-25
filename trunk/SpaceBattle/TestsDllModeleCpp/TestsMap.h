#pragma once

#include <iostream>
#include "..\DllModeleCpp\Abstrait\Map.h"
#include "..\DllModeleCpp\ImplementationStd\MapStd.h"
#include "..\DllModeleCpp\ImplementationStd\MapBuilderStd.h"

class TestsMap
{
public:
	TestsMap(void);
	~TestsMap(void);
	void runLectureSimple();
	void runLecturePlateau();
	void runLectureTotale();
	void runLectureSansAsteroides();
};

