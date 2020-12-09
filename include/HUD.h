#pragma once
#include <GuiObject.h>

class HUD : public India::GuiObject {
public:
	HUD(const HUD& other);
	HUD(HUD&& other) = default;
	HUD& operator=(HUD&& other) = default;
	HUD();
	void Update() override;
	void DrawComponent(const India::Graphics2D& g) const noexcept override;
private:
	int _health = 100;
	float _counter = 0;
	bool _increase = false;
};