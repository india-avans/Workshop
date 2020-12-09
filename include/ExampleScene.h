#pragma once
#include <MapScene.h>
#include <Components.h>
#include <Sprite.h>
#include "CollisionHandlers.h"

class ExampleScene : public India::MapScene {
public:
	void Initialize() override;

	enum class WallDirection {
		Up, Down, Left, Right
	};
	ExampleScene(int stars, bool add_character = true) noexcept;
	~ExampleScene();
private:
	void AddEnemies(float start_x, float start_y, float width, float height, float star_width, float star_height, int amount) noexcept;
	void AddCharacter(float start_x, float start_y, float width, float height) noexcept;
	int _enemies = 0;
	bool _add_character;
};
