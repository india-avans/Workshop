#include <India.h>
#include "Level.h"
#include "GameOver.h"
#include <memory>
#include <stdlib.h>

India::IndiaEngine& India::Create()
{
	// Seed the rand() function
	srand((unsigned int)time(NULL));

	std::vector<std::unique_ptr<India::Scene>> scenes;
	scenes.push_back(std::move(std::make_unique<Level>()));
	scenes.push_back(std::move(std::make_unique<GameOver>(800, 600)));
	return IndiaEngine("Survive the Asteroids", scenes);
}