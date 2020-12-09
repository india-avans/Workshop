#include "Wave.h"
#include <ManagerPool.h>
#include <SceneManager.h>

Wave::Wave(int wave_enemy_increment)
	: _wave_duration_ms{ 1000 }, _wave_duration_time_ms{ 0 },
	_start_cooldown_ms{ 3000 }, _start_cooldown_time_ms{ 0 },
	_wave_enemy_increment{ wave_enemy_increment },
	_wave_completed{ false }, _current_wave{ 0 },
	_enemies_to_spawn{ 0 }, _spawners{}, _waves_amount{ 100 }
{
	SetZOrder(990);
}

void Wave::SetSpawners(std::vector<std::reference_wrapper<EnemySpawnPoint>> spawners)
{
	_spawners = spawners;
	for (auto& spawner : _spawners) {
		spawner.get().on_enemy_spawned += [this](Enemy& e) {--_enemies_to_spawn; };
	}
}

int Wave::GetWavesPassed()
{
	return _current_wave - 1;
}

int Wave::GetWavesAmount()
{
	return _waves_amount;
}

void Wave::LevelComplete()
{

}

void Wave::WaveComplete()
{
	on_wave_complete.Invoke(_current_wave);
	++_current_wave;
	_wave_completed = true;
	_enemies_to_spawn = _wave_enemy_increment;
	_wave_duration_time_ms = 0;

	if (GetWavesPassed() == _waves_amount)
	{
		LevelComplete();
	}
}

void Wave::Update()
{
	if (_start_cooldown_time_ms >= _start_cooldown_ms) {
		UpdateWaveCompletion();
		UpdateSpawnPoints();
	}
	else {
		_start_cooldown_time_ms += India::Time::scaled_delta_time_ms;
	}
}

void Wave::Draw(const India::Graphics2D& g) const
{
}

void Wave::Reset()
{
	_start_cooldown_time_ms = 0;
	_current_wave = 0;
	_enemies_to_spawn = 0;
	WaveComplete();
}

void Wave::UpdateWaveCompletion()
{
	if (_wave_duration_time_ms >= _wave_duration_ms
		&& _enemies_to_spawn == 0)
	{
		WaveComplete();
	}
	_wave_duration_time_ms += India::Time::scaled_delta_time_ms;
}

void Wave::UpdateSpawnPoints()
{
	if (_enemies_to_spawn > 0) {
		for (auto& spawner : _spawners)
		{
			if (spawner.get().CanSpawnEnemy()) {
				spawner.get().SpawnEnemy();
			}
		}
	}
	else {
		on_wave_complete.Invoke(_current_wave);
	}
}