#pragma once
#include <Scene.h>
#include <Components.h>

class GuiScene : public India::Scene {
public:
	GuiScene(int width, int height) noexcept;
	~GuiScene();
	void Initialize() override;
};
 