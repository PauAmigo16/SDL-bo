#include "RIverObject.h"

RiverObject::RiverObject(int _minLenght, int _maxLenght, int _crocodileChance, int _secondChance, int _minSpawnRate, int _maxSpawnRate):crocodileChance(_crocodileChance),secondChance(_secondChance)
{
	int lenght = rand() % (_maxLenght - _minLenght + 1) + _minLenght;
	int spawnRate = rand() % (_maxSpawnRate - _minSpawnRate + 1) + _minSpawnRate;
}

RiverObject::RiverObject(int _minLenght, int _maxLenght, int _minSpawnRate, int _maxSpawnRate, int _secondChance):secondChance(_secondChance)
{
	int lenght = rand() % (_maxLenght - _minLenght + 1) + _minLenght;
	int spawnRate = rand() % ((_maxSpawnRate - _minSpawnRate + 1) + _minSpawnRate);
}
