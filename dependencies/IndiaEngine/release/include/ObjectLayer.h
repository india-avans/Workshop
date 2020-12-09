#pragma once
#include "Core.h"
#include "Layer.h"
#include "LevelObject.h"
#include <vector>

namespace India {

	class India_EXPORT ObjectLayer : public Layer {
	public:
		ObjectLayer() noexcept;
		ObjectLayer(const ObjectLayer& other);
		ObjectLayer& operator=(ObjectLayer& other) noexcept = default;
		ObjectLayer(ObjectLayer&& other) noexcept = default;
		ObjectLayer& operator=(ObjectLayer&& other) noexcept = default;
		~ObjectLayer() override;
		/**
		 Adds the object to this ObjectLayer.
		*/
		void AddObject(std::unique_ptr<LevelObject> object);
		/**
		 Returns a vector containing all objects from this ObjectLayer.
		*/
		std::vector<std::reference_wrapper<LevelObject>> GetObjects() noexcept;
	private:
		std::vector<std::unique_ptr<LevelObject>> _objects;
	};

}
