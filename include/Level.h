#pragma once
#include <MapScene.h>

class Level : public India::MapScene {
public:
	Level() noexcept;
	~Level();

	void Initialize() override;
	void OnSceneActivated() override;
private:
	void AddCharacter(float start_x, float start_y, float width, float height) noexcept;
	void DestroyEnemies();
	void ResetCharacters();
	void ResetWaves();
};
