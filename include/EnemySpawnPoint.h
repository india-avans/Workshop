#pragma once
#include "Objects.h"
#include <iostream>
#include <IndiaEvent.h>
#include <Enemy.h>

class EnemySpawnPoint : public India::GameObject {
public:
	EnemySpawnPoint(Object& object, std::vector<std::string> args) noexcept;
	India::Vector2 GetSpawn() const noexcept;
	std::unique_ptr<Enemy> CreateRandomEnemy(float x, float y);
	void SpawnEnemy();
	bool CanSpawnEnemy();
	std::map<std::string, std::vector<India::Sprite>> GetSprites();
	India::IndiaEvent<Enemy&> on_enemy_spawned;
private:
	India::Vector2 _spawn_location;
	bool _can_spawn;
};