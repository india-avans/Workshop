#pragma once
#include "Core.h"
#include "Manager.h"
#include "Scene.h"
#include <vector>

namespace India {

	class India_EXPORT SceneManager : public Manager
	{
	public:
		SceneManager();
		/**
		Returns the active scene if there is one. If there is no active scene, this function wil throw a SceneManagerException.
		*/
		Scene& GetActiveScene() const;
		/**
		Returns true if there is an active scene. False if there is no scene active.
		*/
		bool HasActiveScene() const noexcept;
		/**
		Sets the active scene. Deactivates all objects in the old scene and activates all objects in the new scene. If the index is out of bounds, a SceneManagerException will be thrown.
		*/
		void SetActiveScene(int index);
		/**
		Converts the scene name to the index and calls SetActiveScene with the index. Throws a SceneManagerException if the name doesn't exist.
		*/
		void SetActiveScene(std::string name);
		/**
		Moves an object from one scene to another. Parameters are the scene indexes (to and from), and the object id. Converts the scene names to the indexes and calls MoveObjectToScene with the indexes. Throws a SceneManagerException if one of the names doesn't exist.
		*/
		template<class ObjectType = Object>
		int MoveObjectToScene(int to, int from, int object_index);
		/**
		Moves an object from one scene to another. Parameters are the scene names (to and from), and the object id.
		*/
		template<class ObjectType = Object>
		int MoveObjectToScene(std::string to, std::string from, int object_index);
		/**
		Adds a scene to the engine's scene collection. If a nullpointer is passed, a SceneManagerException will be thrown.
		*/
		template<class SceneType = Scene>
		void AddScene(std::unique_ptr<SceneType> scene) noexcept;
		/**
		Tries to remove the scene with the provided index. If it was successful, this function will return true. If the index doesn't exist, this function will return false.
		*/
		bool RemoveScene(int index) noexcept;
		/**
		Converts the scene name to the index and calls RemoveScene with the index. Throws a SceneManagerException if the name doesn't exist.
		*/
		bool RemoveScene(std::string name) noexcept;
		int GetLastActiveSceneIndex() const noexcept;
		/**
		Returns the Scene with the provided index. Throws a SceneManagerException if the index is out of bounds. 
		*/
		Scene& GetScene(int index) const noexcept;
		/**
		Returns the Scene with the provided name. Throws a SceneManagerException if the name doesn't exist.
		*/
		Scene& GetScene(std::string name) const noexcept;
		/**
		Returns all scenes with the provided template SceneState.
		*/
		template<typename SceneType = Scene>
		std::vector<std::reference_wrapper<Scene>> GetScenes() const;
	private:
		void LoadScene(int index);
		int _last_active_scene_index;
		int _active_scene_index;
		int _scene_id_increment;
		std::vector<std::unique_ptr<Scene>> _scenes;
		std::map<std::string, std::reference_wrapper<Scene>> _scene_dictionary;
	};

	/**
	Moves an object from one scene to another. Parameters are the scene indexes (to and from), and the object id.
	*/
	template<class ObjectType>
	inline int SceneManager::MoveObjectToScene(int to, int from, int object_index)
	{
		int new_index = -1;
		Scene& source = GetScene(from);
		Scene& destination = GetScene(to);
		try {
			std::unique_ptr<Object> object = source.Objects.PopObject<ObjectType>(object_index);
			if (object.get()) {
				new_index = destination.Objects.AddObject(std::move(object));
			}
		}
		catch (const std::exception& exception) {
			India::Utilities::HandleException(exception);
		}
		return new_index;
	}

	/**
	Moves an object from one scene to another. Parameters are the scene names (to and from), and the object id.
	*/
	template<class ObjectType>
	inline int SceneManager::MoveObjectToScene(std::string to, std::string from, int object_index)
	{
		return MoveObjectToScene<ObjectType>(GetScene(to).GetIndex(), GetScene(from).GetIndex(), object_index);
	}

	/**
	Adds a scene to the engine's scene collection. If a nullpointer is passed, a SceneManagerException will be thrown.
	*/
	template<class SceneType>
	inline void SceneManager::AddScene(std::unique_ptr<SceneType> scene) noexcept
	{
		if (scene.get() != nullptr) {
			_scenes.push_back(std::move(scene));
			_scenes.back()->SetIndex(_scene_id_increment);
			++_scene_id_increment;
			_scene_dictionary.emplace(_scenes.back()->ToString(), *_scenes.back());
			LoadScene(_scenes.size() - 1);
		}
		else {
			throw SceneManagerException("Tried adding non-existent scene");
		}
	}

	/**
	Returns all scenes with the provided type.
	*/
	template<typename SceneType>
	inline std::vector<std::reference_wrapper<Scene>> SceneManager::GetScenes() const
	{
		std::vector<std::reference_wrapper<Scene>> scenes = {};
		bool get_all_scenes = std::is_same<Scene, SceneType>::value;
		for (auto& scene : _scenes) {
			if (get_all_scenes || dynamic_cast<SceneType*>(scene.get())) {
				scenes.push_back(*scene.get());
			}
		}
		return scenes;
	}

}
