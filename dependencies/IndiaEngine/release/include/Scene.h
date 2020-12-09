#pragma once
#include "Core.h"
#include "Objects.h"
#include "ObjectManager.h"

#include <vector>
#include <typeinfo>

namespace India {

	enum class India_EXPORT SceneState {
		Loaded, Active, Inactive, Unitialized, Exists
	};

	class India_EXPORT Scene
	{
	public:
		Scene() noexcept;
		Scene(float width, float height) noexcept;
		ObjectManager Objects;

		/**
		Will be called when the engine is initialized
		*/
		virtual void Initialize() = 0;
		/**
		Returns width property of scene
		*/
		float GetWidth() const noexcept;
		/**
		Returns height property of scene
		*/
		float GetHeight() const noexcept;
		/**
		Returns speed of transition
		*/
		float GetTransitionSpeed() const noexcept;
		/**
		Sets speed of transition equal to value provided in parameter
		*/
		void SetTransitionSpeed(float speed) noexcept;
		/**
		Returns color of transition overlay
		*/
		Color GetTransitionColor() const noexcept;
		/**
		Sets color of transition equal to value provided in parameter
		*/
		void SetTransitionColor(Color color) noexcept;
		/**
		Checks if scene should show a transition on leave en enter of scene
		*/
		bool ShouldTransition() const noexcept;
		/**
		Sets value of shouldTransition equal to value provided in parameter
		*/
		void SetShouldTransition(bool should_transition) noexcept;
		/**
		Sets index equal to value provided in parameter
		*/
		void SetIndex(int index) noexcept;
		/**
		Returns index property of scene
		*/
		int GetIndex() const noexcept;
		/**
		Returns SceneState ENUM value of scene
		*/
		SceneState GetState() const noexcept;
		/**
		Sets SceneState equal to value provided in parameter
		*/
		void SetState(const SceneState& state) noexcept;
		/**
		Checks if SceneState is equal to value provided in parameter. Returns true if condition is met, otherwise false.
		*/
		bool IsState(const SceneState& state) const noexcept;
		/**
		Event that occurs when the scene is activated.
		*/
		virtual void OnSceneActivated();
		/**
		Alias for ToString
		*/
		std::string GetName();
		/**
		Returns the class name of the scene.
		*/
		std::string ToString();
		virtual ~Scene() = 0;
	protected:
		float _width;
		float _height;
		float _transition_speed = 500;
	private:
		int _index;
		SceneState _state;
		Color _transition_color = { 0,0,0, 0 };
		bool _should_transition = true;
	};

}