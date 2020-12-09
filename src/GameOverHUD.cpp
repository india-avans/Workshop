#include <GameTime.h>
#include "GameOverHUD.h"

GameOverHUD::GameOverHUD()
{
	SetZOrder(999);
}

void GameOverHUD::DrawComponent(const India::Graphics2D& g) const noexcept
{
	DrawText(g);
	DrawScore(g);
}

void GameOverHUD::SetScore(int score)
{
	_score = score;
}

void GameOverHUD::DrawText(const India::Graphics2D& g) const noexcept
{
	India::Rectangle rect;
	rect.x = 0;
	rect.y = 0;
	rect.width = g.GetWindowSize().width;
	rect.height = g.GetWindowSize().height;
	rect.render_type = India::RenderType::NoResize;
	g.DrawRect(rect, { 50,50,50,100 }, true);

	India::Rectangle game_over_text_r;
	India::Text game_over_text = { "GAME OVER", "Roboto", 64 };
	game_over_text.font_size = g.GetOptimalFontSize(game_over_text.font_size);
	auto game_over_text_size = g.GetTextSize(game_over_text);
	game_over_text_r.width = game_over_text_size.width;
	game_over_text_r.height = game_over_text_size.height;
	game_over_text_r.x = g.GetWindowSize().width / 2 - (game_over_text_size.width / 2);
	game_over_text_r.y = 0;
	game_over_text_r.render_type = India::RenderType::NoResize;
	g.DrawText(game_over_text, game_over_text_r, { 0,0,0 });

	India::Rectangle pe;
	India::Text continue_text = { "Click button to restart", "Roboto", 24 };
	continue_text.font_size = g.GetOptimalFontSize(continue_text.font_size);
	auto continue_text_size = g.GetTextSize(continue_text);
	pe.width = continue_text_size.width;
	pe.height = continue_text_size.height;
	pe.x = g.GetWindowSize().width / 2 - (continue_text_size.width / 2);
	pe.y = g.GetWindowSize().height - continue_text_size.height - 5;
	pe.render_type = India::RenderType::NoResize;
	g.DrawText(continue_text, pe, { 0,0,0 });
}

void GameOverHUD::DrawScore(const India::Graphics2D& g) const noexcept
{
	India::Rectangle score_text_r;
	India::Text score_text = { "Score: " + std::to_string(_score), "Roboto", 64 };
	score_text.font_size = g.GetOptimalFontSize(score_text.font_size);
	auto score_text_size = g.GetTextSize(score_text);
	score_text_r.width = score_text_size.width;
	score_text_r.height = score_text_size.height;
	score_text_r.x = g.GetWindowSize().width / 2 - (score_text_size.width / 2);
	score_text_r.y = g.GetWindowSize().height / 2 - (score_text_size.height / 2);;
	score_text_r.render_type = India::RenderType::NoResize;
	g.DrawText(score_text, score_text_r, { 0,0,0 });
}
