#include <PhysicsObject.h>
#include <CollisionHandlers.h>

#include <Functional>

class Enemy : public India::PhysicsObject {
public:
	Enemy(float x, float y, float mass, float width, float height, float velocity_x = 1) noexcept;
private:
	std::pair<std::function<void(India::Object&)>, std::function<void()>> HandleCollision(India::Direction direction, std::function<void(India::Object&)> on_collision = [](India::Object&) {}, std::function<void()> no_collision = [] {});
	std::map<India::Direction, std::pair<std::function<void(India::Object&)>, std::function<void()>>> GetCollisionHandlers();
};