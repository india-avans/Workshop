#pragma once
#include "Core.h"
#include "Object.h"
#include "Singleton.h"
#include <string>
#include <functional>
#include <map>

#define REGISTER_TILED_TYPE(NAME, TYPE) \
India::TiledObjectFactory::GetInstance().Register(NAME, &India::TiledObjectFactory::CreateInstance<TYPE>);

namespace India {
	class India_EXPORT TiledObjectFactory : public India::Singleton<TiledObjectFactory> {
	public:
		/**
		Calls the constructor with the object parameter of type T
		*/
		template<typename T> static std::unique_ptr<Object> CreateInstance(Object& object, std::vector<std::string> args) { 
			return std::unique_ptr<Object>(new T(object, args)); 
		}
		/**
		Binds a string to a typeid in the factory.
		The first parameter is the Type property in Tiled objects.
		The second parameter binds to an object its constructor.
		*/
		void Register(std::string type, std::function<std::unique_ptr<Object>(Object&, std::vector<std::string>)> constructor) noexcept;
		/**
		Instantiates the class that is bound to the provided type.
		The type must be registered before being called, else this function will throw a TiledObjectFactoryException.
		*/
		std::unique_ptr<Object> Create(std::string type, Object& object, std::vector<std::string> args);
		~TiledObjectFactory();
	private:
		std::map<std::string, std::function<std::unique_ptr<Object>(Object&, std::vector<std::string>)>> _types = {};
	};
}