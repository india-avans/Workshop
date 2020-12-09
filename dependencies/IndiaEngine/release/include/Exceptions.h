#pragma once
#include <stdexcept>

namespace India {

	class MapLoaderException : public std::runtime_error {
		using std::runtime_error::runtime_error;
	};

	class BitmapFontParserException : public std::runtime_error {
		using std::runtime_error::runtime_error;
	};

	class SceneManagerException : public std::runtime_error {
		using std::runtime_error::runtime_error;
	};

	class ManagerPoolException : public std::runtime_error {
		using std::runtime_error::runtime_error;
	};

	class ObjectManagerException : public std::runtime_error {
		using std::runtime_error::runtime_error;
	};

	class ObjectException : public std::runtime_error {
		using std::runtime_error::runtime_error;
	};

	class SpriteComponentException : public std::runtime_error {
		using std::runtime_error::runtime_error;
	};

	class ObjectQuadtreeException : public std::runtime_error {
		using std::runtime_error::runtime_error;
	};

	class ObjectLayerException : public std::runtime_error {
		using std::runtime_error::runtime_error;
	};

	class TaskLoopException : public std::runtime_error {
		using std::runtime_error::runtime_error;
	};

	class TileLayerException : public std::runtime_error {
		using std::runtime_error::runtime_error;
	};

	class CollisionComponentException : public std::runtime_error {
		using std::runtime_error::runtime_error;
	};

	class CustomPropertiesException : public std::runtime_error {
		using std::runtime_error::runtime_error;
	};

	class TiledObjectFactoryException : public std::runtime_error {
		using std::runtime_error::runtime_error;
	};

}