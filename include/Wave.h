#pragma once
#include "Enemy.h"
#include <EnemySpawnPoint.h>
#include <GameTime.h>

class Wave : public India::Object {
public:
	Wave(int wave_enemy_increment = 1);
	~Wave() override = default;

	void SetSpawners(std::vector<std::reference_wrapper<EnemySpawnPoint>> spawners);

	int GetWavesPassed();
	int GetWavesAmount();

	void Update() override;
	void Draw(const India::Graphics2D& g) const override;
	void Reset();

	India::IndiaEvent<int> on_wave_complete;
private:
	void UpdateWaveCompletion();
	void UpdateSpawnPoints();
	void LevelComplete();
	void WaveComplete();
	std::vector<std::reference_wrapper<EnemySpawnPoint>> _spawners;

	int _waves_amount;
	int _current_wave;
	bool _wave_completed;
	int _wave_enemy_increment;
	int _enemies_to_spawn;
	
	float _start_cooldown_ms;
	float _start_cooldown_time_ms;
	float _wave_duration_time_ms;
	float _wave_duration_ms;
};