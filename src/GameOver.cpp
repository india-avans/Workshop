#include "GameOver.h"
#include <Button.h>
#include <Color.h>
#include <Components.h>

GameOver::GameOver(int width, int height) noexcept : India::Scene(width, height)
{
}

GameOver::~GameOver()
{
}

void GameOver::Initialize()
{
	try {
		India::Color default_color = { 255,0,100 };
		India::Color hover_color = { 255,100,0 };
		
		auto button = std::make_unique<India::Button>(10, 10, 100, 20, default_color);
		
		button->AddComponent<India::ActiveSceneComponent>();
		button->GetComponent<India::ActiveSceneComponent>().SetSceneName("Level");

		button->AddEventHandler("click", [button = button.get()](India::InputEvent& e) {
			button->GetComponent<India::ActiveSceneComponent>().SetActivationPermissions(true);
		});
		button->AddEventHandler("mouse_enter", [button = button.get(), hover_color](India::InputEvent& e) {
			button->GetComponent<India::BackgroundComponent>().SetColor(hover_color);
		});
		button->AddEventHandler("mouse_leave", [button = button.get(), default_color](India::InputEvent& e) {
			button->GetComponent<India::BackgroundComponent>().SetColor(default_color);
		});
		Objects.AddObject(std::move(button));
	}
	catch (const std::exception& exception) {
		India::Utilities::HandleException(exception);
	}
}
