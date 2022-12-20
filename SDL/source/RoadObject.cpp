#include "RoadObject.h"

RoadObject::RoadObject(std::string _carID, int _speed, int _minSpawnRate, int _maxSpawnRate):speed(_speed),carID(_carID)
{
	int spawnRate = rand() % ((_maxSpawnRate - _minSpawnRate + 1) + _minSpawnRate);

}
 