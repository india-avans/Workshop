#include "Character.h"
#include "Door.h"
#include "Utilities.h"
#include "string"
#include "CollisionHandlers.h"
#include <Managers.h>
#include <Components.h>

Character::Character(const Character& other) : India::GameObject(other)
{
	AddComponent<India::ActiveSceneComponent>(other.GetComponent<India::ActiveSceneComponent>());
	AddComponent<India::VelocityComponent>(other.GetComponent<India::VelocityComponent>());
	AddComponent<India::CollisionComponent>(other.GetComponent <India::CollisionComponent>().GetBounds(), GetCollisionHandlers());
	AddComponent<India::InputComponent>(GetKeybinds());
	if (other.HasComponent<India::CameraComponent>()) {
		AddComponent<India::CameraComponent>(other.GetComponent<India::CameraComponent>());
	}
	SetZOrder(other.GetZOrder());
}

Character::Character(float x, float y, float mass, float width, float height) noexcept
	: GameObject(India::GameObjectData{ x,y,width,height, 100, GetSprites(), "walkLeft" }) {
	SetZOrder(69);

	AddComponent<India::ActiveSceneComponent>();
	AddComponent<India::VelocityComponent>(0, 0);
	AddComponent<India::CollisionComponent>(India::Rectangle{ 0, 0, width, height }, GetCollisionHandlers());
	AddComponent<India::InputComponent>(GetKeybinds());

	GetComponent<India::VelocityComponent>().SetDecayX(_movement_speed / 4);
	GetComponent<India::VelocityComponent>().SetDecayY(_movement_speed / 4);
	GetComponent<India::SpriteComponent>().SetAnimationDelay(200, "idle");
}

void Character::Update() {
	auto velocity = GetComponent<India::VelocityComponent>();
	auto& sprite = GetComponent<India::SpriteComponent>();

	if (velocity.GetX() == 0 && velocity.GetY() == 0) {
		sprite.SetActiveSpriteKey("idle");
	}
	else if (velocity.GetX() < 0) {
		sprite.SetActiveSpriteKey("walkLeft");
	}
	else if (velocity.GetX() > 0) {
		sprite.SetActiveSpriteKey("walkRight");
	}
}

std::pair<std::function<void(India::Object&)>, std::function<void()>> Character::HandleCollision(India::Direction direction)
{
	return
	{ 
		[this, direction](Object& subject) {
			Collision::RepositionTarget(*this, subject, direction);
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
		{ India::Direction::Down, HandleCollision(India::Direction::Down)},
		{ India::Direction::Left, HandleCollision(India::Direction::Left)},
		{ India::Direction::Right, HandleCollision(India::Direction::Right)}
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
	std::string base_path{ "sprites/Character_" };
	std::map < std::string, std::pair<std::string, int>> sprite_paths{
		{"idle", {base_path + "Idle/Idle_Animation_",3}},
		{"walkLeft", {base_path + "WalkLeft/WalkLeft_Animation_",4}},
		{"walkRight", {base_path + "WalkRight/",4}},
	};
	std::map<std::string, std::vector<India::Sprite>> sprites;
	for (auto sprite_path : sprite_paths) {
		for (int i = 1; i < sprite_path.second.second; i++) {
			sprites[sprite_path.first].push_back(India::Sprite(sprite_path.second.first + std::to_string(i) + ".png"));
		}
	}
	return sprites;
}
