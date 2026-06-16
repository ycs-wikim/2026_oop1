#include "Random.h"

#include <stdlib.h>
#include <time.h>

Random::Random()
{
	srand(time(NULL));
}

int Random::getRandomValue(int v)
{
	return rand() % v;
}
