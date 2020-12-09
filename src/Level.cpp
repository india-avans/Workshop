#include "Level.h"

#include <Utilities.h>
#include <MapLoader.h>
#include <CameraComponent.h>
#include <TiledObjectFactory.h>

#include "Score.h"
#include "Fps.h"
#include "EnemySpawnPoint.h"
#include "Character.h"
#include "Wave.h"

Level::Level() noexcept : India::MapScene(992, 608, "level1")
{
	REGISTER_TILED_TYPE("EnemySpawnPoint", EnemySpawnPoint);
}

void Level::Initialize()
{
	India::MapScene::Initialize();

	float enemy_width = 40;
	float enemy_height = 40;

	float character_width = 30;
	float character_height = 30;

	AddCharacter(800, 200, character_width, character_height);
	
	Objects.AddObject(std::make_unique<Fps>());
	Objects.AddObject(std::make_unique<Score>());
	Objects.AddObject(std::make_unique<Wave>());
	for (auto& wave : Objects.GetObjects<Wave>()) {
		wave.get().SetSpawners(Objects.GetObjects<EnemySpawnPoint>());
		for (auto& score : Objects.GetObjects<Score>()) {
			wave.get().on_wave_complete += [score](int s) {score.get().SetScore(s); };
		}
	}
}

void Level::OnSceneActivated()
{
	DestroyEnemies();
	ResetWaves();
}

Level::~Level()
{
	Objects.~ObjectManager();
}

void Level::AddCharacter(float start_x, float start_y, float width, float height) noexcept
{
	try {
		int margin_x = 10;
		int margin_y = 10;

		float x = start_x + margin_x;
		float y = start_y + margin_y;

		Objects.AddObject<Character>(std::make_unique<Character>(x, y, 5, width, height));
	}
	catch (const std::exception& exception) {
		India::Utilities::HandleException(exception);
	}
}

void Level::DestroyEnemies()
{
	for (auto& score : Objects.GetObjects<Enemy>()) {
		score.get().SetState(India::ObjectState::ToBeDestroyed);
	}
	Objects.DestroyObjects();
}

void Level::ResetWaves()
{
	for (auto& score : Objects.GetObjects<Wave>()) {
		score.get().Reset();
	}
}
