#pragma once
#include "Graphics2D.h"
#include "Core.h"
#include "Component.h"
#include "TransformComponent.h"
#include "Exceptions.h"
#include "Utilities.h"

#include <unordered_map>
#include <string>
#include <memory>
#include <typeinfo>

namespace India {

	enum class India_EXPORT  ObjectState {
		Active, Inactive, ToBeDestroyed, Unintialized
	};

	class India_EXPORT Object {
	private:
		std::unique_ptr<TransformComponent> _transform;
		std::unordered_map<std::string, std::unique_ptr<Component>> _components;
		ObjectState _state;
		int _index = -1;
		int _z_order = 0;
		std::string _tag = "";
		RenderType _render_type = RenderType::World;
	protected:
		Object(float x, float y, float width, float height);
	public:
		Object();
		Object(const Object& other);

		template<typename ComponentType = Component, typename ...Args>
		void  AddComponent(Args&&... args);
		
		/**
		 Removes the specified component of the object if the object containts the component.
		*/
		template< typename ComponentType = Component >
		bool  RemoveComponent() noexcept;

		/**
		 Adds the component to the object, if the object does not have a component of the same type already.
		*/
		template<class ComponentType = Component>
		ComponentType& GetComponent() const;

		/**
		 Returns true if this Object has the specified type of Component.
		*/
		template<class ComponentType = Component>
		bool HasComponent() const noexcept;

		/**
		 Returns true if this Object has all specified types of Components.
		*/
		template<class ComponentType = Component, typename ...Args>
		bool HasComponents() noexcept;

		/**
		 Returns the state of the object.
		*/
		ObjectState GetState() const noexcept;

		/**
		 Sets the state of the object.
		*/
		void SetState(const ObjectState& state) noexcept;

		/**
		 Returns the drawing order of the object (0 is all the way back).
		*/
		int GetZOrder() const noexcept;

		/**
		 Sets the drawing order of the object (0 is all the way back).
		*/
		void SetZOrder(int z) noexcept;

		/**
		 Returns true if the object's state equals the provided state.
		*/
		bool IsState(const ObjectState& state) const noexcept;

		/**
		 Returns the render type of the object.
		*/
		RenderType GetRenderType() const noexcept;

		/**
		 Sets the render type of the object.
		*/
		void SetRenderType(const RenderType& type) noexcept;

		/**
		 Returns the tag of the object.
		*/
		std::string GetTag() const noexcept;

		/**
		 Sets the tag of the object.
		*/
		void SetTag(const std::string& tag) noexcept;

		/**
		 Returns the index of the object.
		*/
		int  GetIndex() const noexcept;

		/**
		 Sets the index of the object.
		*/
		void SetIndex(int index) noexcept;

		/**
		 Originally calls the Draw() function, but can be extended with more functions. Make sure to call the base function when overriding.
		*/
		virtual void DrawComponent(const Graphics2D& g) const noexcept;

		/**
		 Template method which describes how to draw a concrete object.
		*/
		virtual void Draw(const Graphics2D& g) const = 0;

		/**
		 Will be called every tick. Optional override.
		*/
		virtual void Update();

		virtual ~Object() = 0;
	};

	/**
	 Adds the component to the object, if the object does not have a component of the same type already.
	*/
	template<class ComponentType, typename ...Args>
	void Object::AddComponent(Args&&... args)
	{
		if (std::is_base_of<Component, ComponentType>::value)
		{
			if (!this->HasComponent<ComponentType>()) {
				_components[typeid(ComponentType).name()] = std::make_unique<ComponentType>(std::forward<Args>(args)...);
				_components[typeid(ComponentType).name()]->SetState(ComponentState::Active);
			}
		}
	}

	/**
	 Removes the specified component of the object if the object containts the component.
	*/
	template<class ComponentType>
	bool Object::RemoveComponent() noexcept
	{
		if (this->HasComponent<ComponentType>()) {
			auto component_iterator = _components.find(typeid(ComponentType).name());
			_components.erase(component_iterator);
			return true;
		}
		return false;
	}

	/**
	 Returns the specified component of the object if available.
	*/
	template<class ComponentType>
	ComponentType& Object::GetComponent() const
	{
		if (typeid(ComponentType) == typeid(TransformComponent) && _transform.get()){
			return dynamic_cast<ComponentType&>(*_transform);
		}
		else if (std::is_base_of<Component, ComponentType>::value) {
			if (this->HasComponent<ComponentType>()) {
				return static_cast<ComponentType&>(*_components.at(typeid(ComponentType).name()));
			}
		}
		throw ObjectException("Tried getting non-existent component: " + std::string(typeid(ComponentType).name()) + " for index: " + std::to_string(GetIndex()));
	}

	/**
	Returns true if this Object has the specified type of Component.
	*/
	template<class ComponentType>
	inline bool Object::HasComponent() const noexcept
	{
		return (_transform.get() && dynamic_cast<ComponentType*>(_transform.get()))
			|| _components.find(typeid(ComponentType).name()) != _components.end()
			&& _components.find(typeid(ComponentType).name())->second.get();
	}

	/**
	 Returns true if the object has all specified components
	 Returns false if any of the specified components are not found in the object
	*/
	template<class ComponentType, typename ...OtherTypes>
	bool Object::HasComponents() noexcept {
		if (std::is_base_of<Component, ComponentType>::value)
		{
			if (sizeof...(OtherTypes) == 0) {
				return this->HasComponent<ComponentType>();
			}
			return this->HasComponent<ComponentType>() && this->HasComponents< OtherTypes ... >();
		}
	}
}
