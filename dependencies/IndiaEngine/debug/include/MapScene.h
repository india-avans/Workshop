#pragma once
#include "Core.h"
#include "Scene.h"

#include <string>


namespace India {

	class India_EXPORT MapScene : public Scene
	{
	public:
		MapScene(float width, float height, std::string map_filename) noexcept;
		virtual void Initialize() override;
	private:
		std::string _map_filename;
	};

}