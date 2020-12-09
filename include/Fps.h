#pragma once
#include <GuiObject.h>

class Fps : public India::GuiObject {
public:
	Fps();
	void DrawComponent(const India::Graphics2D& g) const noexcept override;
private:
	void DrawFPS(const India::Graphics2D& g) const noexcept;
};