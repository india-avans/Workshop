#pragma once
#include <Scene.h>

class GameOver : public India::Scene {
public:
	GameOver(int width, int height) noexcept;
	~GameOver();
	void Initialize() override;
};
 