#pragma once

#include <stdlib.h>
#include <time.h>

class Random
{
public:
	Random();
	~Random();

	const int getRandomNumber(int high, int low);
};

