#include "ExampleScene.h"

#include <Utilities.h>
#include <MapLoader.h>
#include <CameraComponent.h>
#include <TiledObjectFactory.h>

#include "HUD.h"
#include "Door.h"
#include "Character.h"
#include "Enemy.h"

ExampleScene::ExampleScene(int enemies, bool add_character) noexcept : India::MapScene(992, 608, "level1")
{
	REGISTER_TILED_TYPE("DungeonEntrance", Door);
	_enemies = enemies;
	_add_character = add_character;
}

void ExampleScene::Initialize()
{
	India::MapScene::Initialize();
	float Enemy_width = 40;
	float Enemy_height = 40;

	float warrior_width = 30;
	float warrior_height = 30;

	
	if (_add_character) {
		AddCharacter(800, 200, warrior_width, warrior_height);
	}
	AddEnemies(30, 30, _width * 0.9, _height * 0.8, Enemy_width, Enemy_height, _enemies);
	Objects.AddObject(std::make_unique<HUD>());
}

ExampleScene::~ExampleScene()
{
	Objects.~ObjectManager();
}

void ExampleScene::AddEnemies(float Enemyt_x, float Enemyt_y, float width, float height, float Enemy_width, float Enemy_height, int amount) noexcept
{

	int margin_x = Enemy_width / 5;
	int margin_y = Enemy_height / 5;

	float x = Enemyt_x + margin_x;
	float y = Enemyt_y + margin_y;

	try {
		for (int i = 0; i < amount; i++) {
			float mass = 3;
			auto enemy = std::make_unique<Enemy>(x, y, mass, Enemy_width, Enemy_height, 5);
			
			Objects.AddObject(std::move(enemy));
			if (x + Enemy_width + margin_x < width) {
				x += Enemy_width + margin_x;
			}
			else {
				y += Enemy_height + margin_y;
				x = Enemyt_x + margin_x;
			}

		}
	}
	catch (const std::exception& exception) {
		India::Utilities::HandleException(exception);
	}
}

void ExampleScene::AddCharacter(float Enemyt_x, float Enemyt_y, float width, float height) noexcept
{
	try {
		int margin_x = 10;
		int margin_y = 10;

		float x = Enemyt_x + margin_x;
		float y = Enemyt_y + margin_y;

		auto warrior = Character{ x,y, 5,width,height };
		warrior.AddComponent<India::CameraComponent>(896, 504);
		Objects.AddObject<Character>(warrior);
	}
	catch (const std::exception& exception) {
		India::Utilities::HandleException(exception);
	}
}
