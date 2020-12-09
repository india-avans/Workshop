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

Level::Level() noexcept : India::MapScene(1024, 1024, "level")
{
	REGISTER_TILED_TYPE("EnemySpawnPoint", EnemySpawnPoint);
}

void Level::Initialize()
{
	India::MapScene::Initialize();

	float character_width = 50;
	float character_height = 40;

	AddCharacter((_width - character_width) / 2, _height * 0.05, character_width, character_height);

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
	ResetCharacters();
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
	for (auto& enemy : Objects.GetObjects<Enemy>()) {
		enemy.get().SetState(India::ObjectState::ToBeDestroyed);
	}
	Objects.DestroyObjects();
}

void Level::ResetCharacters()
{
	for (auto& character : Objects.GetObjects<Character>()) {
		auto& transform = character.get().GetComponent<India::TransformComponent>();
		transform.SetX((_width - transform.GetWidth()) / 2);
		transform.SetY(_height * 0.05);
	}
}

void Level::ResetWaves()
{
	for (auto& score : Objects.GetObjects<Wave>()) {
		score.get().Reset();
	}
}
