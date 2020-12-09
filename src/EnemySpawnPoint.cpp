#include "EnemySpawnPoint.h"
#include "Character.h"

EnemySpawnPoint::EnemySpawnPoint(Object& object, std::vector<std::string> args) noexcept : India::GameObject(
	object.GetComponent<India::TransformComponent>().GetX(),
	object.GetComponent<India::TransformComponent>().GetY(),
	object.GetComponent<India::TransformComponent>().GetWidth(),
	object.GetComponent<India::TransformComponent>().GetHeight()
)
, _spawn_location{ GetComponent<India::TransformComponent>().GetLocation() }
, _can_spawn{ false }
{
	auto dimensions = GetComponent<India::TransformComponent>().GetRectangle();

	AddComponent<India::SpriteComponent>(GetSprites(), "idle", 75);
	AddComponent<India::CollisionComponent>(India::Rectangle{ 0,0,dimensions.width, dimensions.height },
		std::map<India::Direction, std::pair<std::function<void(Object&)>, std::function<void()>>> {
			{India::Direction::Any, {
				[this](Object& subject) {
					_can_spawn = false;
				},
				[this] {
					_can_spawn = true;
				}
			}},
	});
	GetComponent<India::CollisionComponent>().SetTrigger(true);
}

India::Vector2 EnemySpawnPoint::GetSpawn() const noexcept
{
	return _spawn_location;
}

std::unique_ptr<Enemy> EnemySpawnPoint::CreateRandomEnemy(float x, float y) {
	float mass = rand() % 5 + 1;
	float width = rand() % 30 + 10;
	float height = rand() % 30 + 10;
	float velocity_x = rand() % 5 + 1;
	float velocity_y = rand() % 5 + 1;
	return std::make_unique<Enemy>(x, y, width, height, mass, velocity_x, velocity_y);
}

void EnemySpawnPoint::SpawnEnemy()
{
	auto& spawnpoint = GetComponent<India::TransformComponent>();
	auto& scene_manager = India::ManagerPool::GetInstance().GetManager<India::SceneManager>();
	auto& active_scene = scene_manager.GetActiveScene();

	float x = spawnpoint.GetX() + spawnpoint.GetWidth() * 0.35;
	float y = spawnpoint.GetY() + spawnpoint.GetHeight() * 0.35;
	auto enemy = CreateRandomEnemy(x, y);
	if (enemy.get()) {
		on_enemy_spawned.Invoke(*enemy);
		active_scene.Objects.AddObject(std::move(enemy));
	}
}

bool EnemySpawnPoint::CanSpawnEnemy()
{
	return _can_spawn;
}

std::map<std::string, std::vector<India::Sprite>> EnemySpawnPoint::GetSprites()
{
	std::map<std::string, std::vector<India::Sprite>> sprites;
	for (int i = 0; i < 12; i++) {
		sprites["idle"].push_back(India::Sprite("sprites/Spawn/Enemy/idle_" + std::to_string(i) + ".png"));
	}
	return sprites;
}