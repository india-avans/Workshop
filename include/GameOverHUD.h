#pragma once
#include <GuiObject.h>

class GameOverHUD : public India::GuiObject {
public:
	GameOverHUD();
	void DrawComponent(const India::Graphics2D& g) const noexcept override;
	void SetScore(int score);
private:
	int _score;
	void DrawText(const India::Graphics2D& g) const noexcept;
	void DrawScore(const India::Graphics2D& g) const noexcept;
};