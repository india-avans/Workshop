#pragma once
#include "Core.h"
#include "Manager.h"
#include "Exceptions.h"
#include "Singleton.h"
#include <unordered_map>
#include <string>
#include <typeinfo>

namespace India {

	

	/**
	* Holds a collection of Manager instances. Maximum one for each class.
	*/
	class India_EXPORT ManagerPool : public Singleton<ManagerPool> {
	private:
		std::unordered_map<std::string, std::unique_ptr<Manager>> _managers;
	public:
		~ManagerPool();

		template<typename ManagerType = Manager, typename ...Args>
		void Register(Args&&... args);

		template<class ManagerType = Manager>
		ManagerType& GetManager() const noexcept;

		template<class ManagerType = Manager>
		bool Unregister() noexcept;

		void Clear() noexcept;
	};

	/**
	* Registers a manager in the pool.
	*/
	template<typename ManagerType, typename ...Args>
	void ManagerPool::Register(Args&&... args)
	{
		if (std::is_base_of<Manager, ManagerType>::value) {
			_managers[typeid(ManagerType).name()] = std::make_unique<ManagerType>(std::forward<Args>(args)...);
		}
		else {
			throw ManagerPoolException("Could not register manager: " + std::string{ typeid(ManagerType).name() });
		}
	}

	/**
	* Retrieves a manager from the pool. Returns a nullptr when it doesn't exist.
	*/
	template<class ManagerType>
	ManagerType& ManagerPool::GetManager() const noexcept {
		if (std::is_base_of<Manager, ManagerType>::value) {
			if (_managers.find(typeid(ManagerType).name()) != _managers.end()) {
				return static_cast<ManagerType&>(*_managers.at(typeid(ManagerType).name()));
			}
		}
		throw ManagerPoolException("Could not get manager: " + std::string{ typeid(ManagerType).name() });
	}

	/**
	* Unregisters a manager from the pool.
	*/
	template<class ManagerType>
	bool ManagerPool::Unregister() noexcept {
		if (this->GetManager<ManagerType>() != nullptr) {
			_managers[typeid(ManagerType).name()] = nullptr;
			return true;
		}
		return false;
	}

}
