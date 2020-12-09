#include "Character.h"

#include "Utilities.h"
#include "CollisionHandlers.h"
#include <Managers.h>
#include <Components.h>
#include <Enemy.h>

Character::Character(float x, float y, float mass, float width, float height) noexcept
	: GameObject(India::GameObjectData{ x,y,width,height, 100, GetSprites(), "idleLeft" }) {
	SetZOrder(69);

	AddComponent<India::CameraComponent>(896, 504);
	AddComponent<India::ActiveSceneComponent>();
	AddComponent<India::VelocityComponent>(0, 0);
	AddComponent<India::CollisionComponent>(India::Rectangle{ 0, 0, width, height }, GetCollisionHandlers());
	AddComponent<India::InputComponent>(GetKeybinds());

	GetComponent<India::ActiveSceneComponent>().SetSceneName("GameOver");
	GetComponent<India::VelocityComponent>().SetDecayX(_movement_speed / 4);
	GetComponent<India::VelocityComponent>().SetDecayY(_movement_speed / 4);
	GetComponent<India::SpriteComponent>().SetAnimationDelay(200);
}

void Character::Update() {
	auto velocity = GetComponent<India::VelocityComponent>();
	auto& sprite = GetComponent<India::SpriteComponent>();

	if (velocity.GetX() <= 0 && _went_left) {
		sprite.SetActiveSpriteKey("idleLeft");
	}
	else if (velocity.GetX() > 0) {
		sprite.SetActiveSpriteKey("idleRight");
	}
	_went_left = velocity.GetX() != 0 ? velocity.GetX() < 0 : _went_left;
}

std::pair<std::function<void(India::Object&)>, std::function<void()>> Character::HandleCollision(India::Direction direction)
{
	return
	{
		[this, direction](Object& subject) {
			if (dynamic_cast<Enemy*>(&subject)) {
				GetComponent<India::ActiveSceneComponent>().SetActivationPermissions(true);
			}
			if (!subject.HasComponent<India::VelocityComponent>()) {
			Collision::RepositionTarget(*this, subject, direction);
			}
			Collision::ToggleVelocityDirection(*this, direction, false);
		},
		[this, direction] {
			Collision::ToggleVelocityDirection(*this, direction, true);
		}
	};
}

std::map<India::Direction, std::pair<std::function<void(India::Object&)>, std::function<void()>>> Character::GetCollisionHandlers()
{
	return 	std::map<India::Direction, std::pair<std::function<void(India::Object&)>, std::function<void()>>>{
		{ India::Direction::Up, HandleCollision(India::Direction::Up)},
		{ India::Direction::Down, HandleCollision(India::Direction::Down) },
		{ India::Direction::Left, HandleCollision(India::Direction::Left) },
		{ India::Direction::Right, HandleCollision(India::Direction::Right) }
	};
}

std::vector<std::tuple<std::string, std::function<void()>>> Character::GetKeybinds()
{
	std::vector<std::tuple<std::string, std::function<void()>>> keybinds;
	keybinds.emplace_back("Left", [this] {
		GetComponent<India::VelocityComponent>().SetX(-_movement_speed);
		});
	keybinds.emplace_back("Right", [this] {
		GetComponent<India::VelocityComponent>().SetX(_movement_speed);
		});
	keybinds.emplace_back("Up", [this] {
		GetComponent<India::VelocityComponent>().SetY(-_jump_speed);
		});
	keybinds.emplace_back("Down", [this] {
		GetComponent<India::VelocityComponent>().SetY(_jump_speed);
		});
	return keybinds;
}

std::map<std::string, std::vector<India::Sprite>> Character::GetSprites()
{
	std::string base_path{ "sprites/Character/" };
	std::map < std::string, std::pair<std::string, int>> sprite_paths{
		{"idleLeft", {base_path + "/",4}},
		{"idleRight", {base_path + "/",4}},
	};
	std::map<std::string, std::vector<India::Sprite>> sprites;
	for (auto sprite_path : sprite_paths) {
		bool is_right = strcmp(sprite_path.first.c_str(), "idleRight") == 0;
		for (int i = 1; i < sprite_path.second.second; i++) {
			if (is_right) {
				sprites[sprite_path.first].push_back(India::Sprite(sprite_path.second.first + std::to_string(i) + ".png", {-1,-1,-1,-1}, India::FlipType::Horizontal));
			}
			else {
				sprites[sprite_path.first].push_back(India::Sprite(sprite_path.second.first + std::to_string(i) + ".png"));
			}
		}
	}
	return sprites;
}
