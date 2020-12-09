#include "Score.h"
#include <GameTime.h>

Score::Score()
	: _score{ 0 } {
	SetZOrder(999);
}

void Score::DrawComponent(const India::Graphics2D& g) const noexcept
{
	DrawScore(g);
}

void Score::Reset()
{
	_score = 0;
}

void Score::SetScore(int score)
{
	_score = score;
}

int Score::GetScore()
{
	return _score;
}

void Score::DrawScore(const India::Graphics2D& g) const noexcept
{
	India::Rectangle score;
	India::Text score_t = { "Score: " + std::to_string(_score), "Roboto", 16 };
	auto score_size = g.GetTextSize(score_t);
	score.width = score_size.width;
	score.height = score_size.height;
	score.x = 5;
	score.y = 5;
	score.render_type = India::RenderType::Screen;

	India::Rectangle score_background = score;
	float padding = 4;
	score_background.x -= padding / 2;
	score_background.width += padding;

	g.DrawRect(score_background, { 100,100,100 }, true);
	g.DrawDynamicText(score_t, score, { 255,255,255 }, true);
}
