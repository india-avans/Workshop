#pragma once
#include "Core.h"
#include "Manager.h"
#include "Object.h"
#include <algorithm>
#include <vector>
#include <memory>

namespace India {

	template class India_EXPORT std::allocator<Object*>;
	template class India_EXPORT std::vector<Object*>;

	class India_EXPORT ObjectManager : public Manager {
	public:
		/**
		Moves an object to the collection of existing objects.
		*/
		template<typename ObjectType = Object>
		int AddObject(std::unique_ptr<ObjectType> object);

		/**
		Copies an object to the collection of existing objects.
		*/
		template<typename ObjectType = Object>
		int AddObject(const ObjectType& object);

		/**
		Returns true if an Object at the specified index is removed succesfully.
		*/
		bool RemoveObject(int index) noexcept;

		/**
		Returns a collection of objects which contain all the specified components.
		*/
		template< class ComponentType, typename ...OtherTypes >
		std::vector< std::reference_wrapper<Object> > GetObjectsWithComponents() const noexcept;

		/**
		Returns a collection of objects which contain all the specified components.
		*/
		template< class ObjectType = Object>
		std::vector< std::reference_wrapper<ObjectType> > GetObjects() const noexcept;

		/**
		Returns true if an object within this collection has the specified index.
		*/
		bool HasObject(int index);

		/**
		Returns the object with the specified index.
		*/
		template< class ObjectType = Object>
		ObjectType& GetObject(int index) const;

		/**
		Returns and removes the object with the specified index.
		*/
		template< class ObjectType = Object>
		std::unique_ptr<Object> PopObject(int index);

		/**
		Removes all objects with the 'ToBeDestroyed' ObjectState.
		*/
		void DestroyObjects();
		/**
		Clears all objects; empties Object collection.
		*/
		void ClearObjects();
		/**
		Sorts the current collection descending by their ZOrder attribute.
		*/
		void SortObjectsByZOrder();
		std::vector<std::reference_wrapper<Object>> GetObjectsWithTag(std::string tag);

		ObjectManager() noexcept;
		~ObjectManager() override;
	private:
		int _object_id_increment;
		std::vector<std::unique_ptr<Object>> _objects;
	};

	/**
	Moves an object to the collection of existing objects.
	*/
	template<typename ObjectType>
	int ObjectManager::AddObject(std::unique_ptr<ObjectType> object)
	{
		if (object.get() && std::is_base_of<Object, ObjectType>::value) {
			_objects.push_back(std::move(object));
			_objects.back()->SetIndex(_object_id_increment);
			_objects.back()->SetState(ObjectState::Active);
			++_object_id_increment;
			SortObjectsByZOrder();
			return _object_id_increment - 1;
		}
		return -1;
	}

	/**
	Copies an object to the collection of existing objects.
	*/
	template<typename ObjectType>
	int ObjectManager::AddObject(const ObjectType& object)
	{
		if (std::is_base_of<Object, ObjectType>::value) {
			_objects.push_back(std::make_unique<ObjectType>(object));
			_objects.back()->SetIndex(_object_id_increment);
			_objects.back()->SetState(ObjectState::Active);
			++_object_id_increment;
			SortObjectsByZOrder();
			return _object_id_increment - 1;
		}
		return -1;
	}

	/**
	Returns the existing collection of objects.
	*/
	template< class ObjectType >
	std::vector< std::reference_wrapper<ObjectType>> ObjectManager::GetObjects() const noexcept
	{
		bool get_all_objects = std::is_same<Object, ObjectType>::value;
		std::vector<std::reference_wrapper<ObjectType>> objects = {};
		if (!_objects.empty()) {
			for (int object_index = 0; object_index < _objects.size(); object_index++)
			{
				if (_objects.at(object_index).get() != nullptr
					&& !_objects.at(object_index)->IsState(ObjectState::ToBeDestroyed)
					&& (dynamic_cast<ObjectType*>(_objects.at(object_index).get()) || get_all_objects)) {
					objects.push_back(static_cast<ObjectType&>(*_objects.at(object_index)));
				}
			}
		}
		return objects;
	}

	/**
	Returns the object with the specified index.
	*/
	template<class ObjectType>
	ObjectType& ObjectManager::GetObject(int index) const
	{
		for (int object_index = 0; object_index < _objects.size(); object_index++)
		{
			if (_objects.at(object_index).get() != nullptr
				&& _objects.at(object_index)->GetIndex() == index
				&& !_objects.at(object_index)->IsState(ObjectState::ToBeDestroyed)
				&& dynamic_cast<ObjectType*>(_objects.at(object_index).get())) {
				return static_cast<ObjectType&>(*_objects.at(object_index));
			};
		}
		throw ObjectException("Tried getting non-existent object at index: " + std::to_string(index));
	}

	/**
	Returns and removes the object with the specified index.
	*/
	template<class ObjectType>
	inline std::unique_ptr<Object> ObjectManager::PopObject(int index)
	{
		for (int object_index = 0; object_index < _objects.size(); object_index++)
		{
			if (_objects.at(object_index).get() != nullptr
				&& !_objects.at(object_index)->IsState(ObjectState::ToBeDestroyed)
				&& _objects.at(object_index)->GetIndex() == index) {
				return std::move(_objects.at(object_index));
			};
		}
		return nullptr;
	}

	/**
	Returns true if an Object at the specified index is removed succesfully.
	*/
	inline bool ObjectManager::RemoveObject(int object_index) noexcept
	{
		for (int i = 0; i < _objects.size(); ++i) {
			if (_objects.at(i).get() != nullptr
				&& _objects.at(i)->GetIndex() == object_index) {
				_objects.at(i)->SetState(ObjectState::ToBeDestroyed);
				return true;
			}
		}
		return false;
	}

	/**
	Returns a collection of objects which contain all the specified components.
	*/
	template< typename ComponentType, typename ...OtherTypes >
	inline std::vector<std::reference_wrapper<Object>> ObjectManager::GetObjectsWithComponents() const noexcept
	{
		std::vector<std::reference_wrapper<Object>> objects = {};
		if(!_objects.empty()){
			for (int object_index = 0; object_index < _objects.size(); object_index++)
			{
				if (_objects.at(object_index).get() != nullptr
					&& !_objects.at(object_index)->IsState(ObjectState::ToBeDestroyed)
					&& _objects.at(object_index)->HasComponents<ComponentType, OtherTypes ...>()) {
					objects.push_back(*_objects.at(object_index));
				}
			}
		}
		return objects;
	}

}
