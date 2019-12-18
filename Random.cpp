#include "Random.hpp"

Random::Random()
{}


Random::~Random()
{}

const int Random::getRandomNumber(int high, int low)
{
	srand(time(NULL));
	return rand() % high + low;
}
