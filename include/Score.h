#pragma once
#include <GuiObject.h>

class Score : public India::GuiObject {
public:
	Score();
	void DrawComponent(const India::Graphics2D& g) const noexcept override;
	void Reset();
	void SetScore(int score);
	int GetScore();
private:
	void DrawScore(const India::Graphics2D& g) const noexcept;
	int _score;
};