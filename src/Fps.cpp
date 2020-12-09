#include "Fps.h"
#include <GameTime.h>

Fps::Fps()
{
	SetZOrder(999);
}

void Fps::DrawComponent(const India::Graphics2D& g) const noexcept
{
	DrawFPS(g);
}

void Fps::DrawFPS(const India::Graphics2D& g) const noexcept
{
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
