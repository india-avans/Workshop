#include "GuiScene.h"
#include <iostream>
#include <Button.h>
#include <MapLoader.h>
#include "Color.h"

GuiScene::GuiScene(int width, int height) noexcept : India::Scene(width, height)
{
}

GuiScene::~GuiScene()
{
}

void GuiScene::Initialize()
{
	try {
		auto button = std::make_unique<India::Button>(10, 10, 100, 20, "sprites/wall_placeholder.png");
		button->AddComponent<India::ActiveSceneComponent>();
		button->GetComponent<India::ActiveSceneComponent>().SetSceneIndex(1);
		button->AddEventHandler("click", [button = button.get()](India::InputEvent& e) {
			button->GetComponent<India::ActiveSceneComponent>().SetActivationPermissions(true);
		});
		button->AddEventHandler("mouse_enter", [button = button.get()](India::InputEvent& e) {
			button->GetComponent<India::BackgroundComponent>().SetColor({ 255,0,0 });
		});
		button->AddEventHandler("mouse_leave", [button = button.get()](India::InputEvent& e) {
			button->GetComponent<India::BackgroundComponent>().SetColor({ 0,255,0 });
		});
		Objects.AddObject(std::move(button));
	}
	catch (const std::exception& exception) {
		India::Utilities::HandleException(exception);
	}
}
