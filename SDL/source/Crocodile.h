#pragma once
#include "Log.h"

class Crocodile :
	public Log
{
private:
	float openMouthDuration;
	float closedMouthDuration;
	float elapsedTime;

	bool mouthOpen;

	std::string bodyPath;
	std::string openMouthPath;
	std::string closedMouthPath;

public:
	Crocodile(float openMouthDuration, float closedMouthDuration, int length);

	bool isMouthOpen();

	void Load() override;
	void Update() override;
	void Render() override;
};