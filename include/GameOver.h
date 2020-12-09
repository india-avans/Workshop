#pragma once
#include <Scene.h>
#include <Button.h>

class GameOver : public India::Scene {
public:
	GameOver(int width, int height) noexcept;
	~GameOver();
	void Initialize() override;
	void OnSceneActivated() override;
private:
	std::unique_ptr<India::Button> CreateRestartButton(float x, float y, float width, float height, India::Color default_color, India::Color hover_color);
};
 