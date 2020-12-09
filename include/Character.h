#pragma once
#include "Objects.h"
#include "Managers.h"
#include <iostream>

class Character : public India::GameObject {
public:
	Character(float x, float y, float mass, float width, float height) noexcept;
	void Update();
private:
	bool _can_interact = false;
	float _movement_speed = 5.0f;
	float _jump_speed = 9.0f;
	bool _went_left;

	std::pair<std::function<void(India::Object&)>, std::function<void()>> HandleCollision(India::Direction direction);
	std::map<India::Direction, std::pair<std::function<void(Object&)>, std::function<void()>>> GetCollisionHandlers();
	std::vector<std::tuple<std::string, std::function<void()>>> GetKeybinds();
	std::map<std::string, std::vector<India::Sprite>> GetSprites();
};