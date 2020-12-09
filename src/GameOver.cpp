#include "GameOver.h"
#include <Button.h>
#include <Color.h>
#include <Components.h>
#include <GameOverHUD.h>
#include <ManagerPool.h>
#include <SceneManager.h>
#include <Score.h>

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

		float button_width = 100;
		float button_height = 30;

		Objects.AddObject(std::move(CreateRestartButton((_width - button_width) / 2, (_height - button_height) - _height * 0.10, button_width, button_height, default_color, hover_color)));
		Objects.AddObject(std::make_unique<GameOverHUD>());
	}
	catch (const std::exception& exception) {
		India::Utilities::HandleException(exception);
	}
}

void GameOver::OnSceneActivated()
{
	auto& level_scene = India::ManagerPool::GetInstance().GetManager<India::SceneManager>().GetScene("Level");
	for (auto& score : level_scene.Objects.GetObjects<Score>()) {
		for (auto& gameover_hud : Objects.GetObjects<GameOverHUD>()) {
			gameover_hud.get().SetScore(score.get().GetScore());
		}
	}
}

std::unique_ptr<India::Button> GameOver::CreateRestartButton(float x, float y, float width, float height, India::Color default_color, India::Color hover_color)
{
	auto button = std::make_unique<India::Button>(x, y, width, height, default_color);

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
	return std::move(button);
}
