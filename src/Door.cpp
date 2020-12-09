#include "Door.h"
#include "Character.h"

Door::Door(Object& object, std::vector<std::string> args) noexcept
	: India::GameObject(object.GetComponent<India::TransformComponent>().GetX(),
		object.GetComponent<India::TransformComponent>().GetY(),
		object.GetComponent<India::TransformComponent>().GetWidth(),
		object.GetComponent<India::TransformComponent>().GetHeight())
{
	AddComponent<India::SpriteComponent>(std::map<std::string, std::vector<India::Sprite>>{
		{"closed", { India::Sprite("levels/img/closed_door.png") }},
		{ "open", { India::Sprite("levels/img/open_door.png") } }
	}, "closed");
	auto transform = GetComponent<India::TransformComponent>();
	AddComponent<India::CollisionComponent>(India::Rectangle{ 0, 0, transform.GetWidth(), transform.GetX() },
		std::map<India::Direction, std::pair<std::function<void(Object&)>, std::function<void()>>>{
			{India::Direction::Any, {
				[this](Object& subject) {
				if (typeid(subject) == typeid(Character)) {
					GetComponent<India::SpriteComponent>().SetActiveSpriteKey("open");
				}
			},
				[this] {
				GetComponent<India::SpriteComponent>().SetActiveSpriteKey("closed");
			} }},
	});
	GetComponent<India::CollisionComponent>().SetTrigger(true);
}