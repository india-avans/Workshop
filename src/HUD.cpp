#include "HUD.h"
#include <GameTime.h>

HUD::HUD(const HUD& other)
	: _health{ other._health }, _increase{ other._increase }, _counter{other._counter}{}

HUD::HUD() {
	
}

void HUD::Update() {
	_counter += India::Time::scaled_delta_time_ms;
	if (_counter >= 5) {
		if (_health >= 100) {
			_increase = false;
		}

		if (_health <= 0) {
			_increase = true;
		}

		if (_increase) {
			_health += 1;
		}
		else {
			_health -= 1;
		}
		_counter = 0;
	}
}

void HUD::DrawComponent(const India::Graphics2D& g) const noexcept
{
	India::Rectangle r;
	r.render_type = India::RenderType::Screen;
	r.x = 10;
	r.y = 10;
	r.width = ((float)_health / 100.0) * 200;
	r.height = 20;
	g.FillRect(r, { 255,0,0 });

	India::Rectangle fps;
	India::Text fps_t = { "FPS: " + std::to_string(India::Time::fps), "Roboto", 16 };
	auto fps_size = g.GetTextSize(fps_t);
	fps.width = fps_size.width;
	fps.height = fps_size.height;
	fps.x = g.GetWindowSize().width - fps.width - 5;
	fps.y = 5;
	fps.render_type = India::RenderType::NoResize;
	g.DrawDynamicText(fps_t, fps, { 255,0,0 }, true);
}
