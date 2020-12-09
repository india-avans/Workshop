#pragma once
#include "Component.h"
#include <vector>
#include <iostream>

namespace India {

	class India_EXPORT ActiveSceneComponent : public Component {
	private:
		std::string _scene_name;
		std::string _previous_scene_name;
		int _scene_index;
		int _previous_scene_index;
		bool _should_activate;
	public:
		ActiveSceneComponent(const ActiveSceneComponent& other);

		ActiveSceneComponent();
		ActiveSceneComponent(int scene_index);
		/**
		Returns index of ActiveSceneComponent
		*/
		int GetSceneIndex() const noexcept;
		/**
		Sets index of ActiveSceneComponent accordingly to value
		*/
		void SetSceneIndex(int index) noexcept;
		/**
		Returns name of ActiveSceneComponent
		*/
		std::string GetSceneName() const noexcept;
		/**
		Sets name of ActiveSceneComponent accordingly to value
		*/
		void SetSceneName(std::string name) noexcept;
		/**
		Returns true is this component has the permission to be activated
		*/
		bool HasActivationPermission() const noexcept;
		/**
		Sets activation permission to (in)active
		*/
		void SetActivationPermissions(bool perm) noexcept;
		/**
		Returns previous_index of ActiveSceneComponent
		*/
		int GetPreviousSceneIndex() const noexcept;
	};
}
