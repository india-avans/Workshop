#include "Enemy.h"

Enemy::Enemy(float x, float y, float width, float height, float mass, float velocity_x, float velocity_y) noexcept : PhysicsObject(India::PhysicsObjectData{ { x,y,width,height, 1, {
		std::pair<std::string, std::vector<India::Sprite>>{"idle", {India::Sprite("sprites/player_placeholder.png")}}
		}, "idle" }, mass
	}) {
	AddComponent<India::VelocityComponent>(velocity_x, velocity_y);
	AddComponent<India::CollisionComponent>(India::Rectangle{ 0, 0, width, height }, GetCollisionHandlers());
	SetZOrder(69);
};

std::pair<std::function<void(India::Object&)>, std::function<void()>> Enemy::HandleCollision(India::Direction direction, std::function<void(Object&)> on_collision, std::function<void()> no_collision)
{
	return {
		[this, direction, on_collision](Object& subject) {
			Collision::RepositionTarget(*this, subject, direction);
			Collision::UpdateVelocity(*this, direction, Collision::Handlers::RevertDirection);
			Collision::ToggleVelocityDirection(*this, direction, false);
			on_collision(subject);
		},
		[this, direction, no_collision] {
			Collision::ToggleVelocityDirection(*this, direction, true);
			no_collision();
		}
	};
}

std::map<India::Direction, std::pair<std::function<void(India::Object&)>, std::function<void()>>> Enemy::GetCollisionHandlers()
{
	return 	std::map<India::Direction, std::pair<std::function<void(India::Object&)>, std::function<void()>>>{
		{ India::Direction::Left, HandleCollision(India::Direction::Left) },
		{ India::Direction::Right, HandleCollision(India::Direction::Right) },
		{ India::Direction::Up, HandleCollision(India::Direction::Up)},
		{ India::Direction::Down, HandleCollision(India::Direction::Down
			,[this](India::Object&) {Collision::ToggleGravity(*this, false); }
			,[this]() {Collision::ToggleGravity(*this, true); })
		}
	};
}
