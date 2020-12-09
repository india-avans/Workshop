#pragma once 
#include "Utilities.h"
#include <iostream>
#include <type_traits>
#include <crtdbg.h>

namespace India {

	// generic Singleton via CRTP
	template <typename T>
	class Singleton
	{
	protected:
		Singleton(const Singleton&) = delete; // to prevent CASE 3
		Singleton& operator=(const Singleton&) = delete; // to prevent CASE 4
		Singleton() noexcept = default; // to allow creation of Singleton<Foo>
		// by the derived class Foo, since otherwise the (deleted)
		// copy constructor prevents the compiler from generating
		// a default constructor;
		// declared protected to prevent CASE 5
	public:
		static T& GetInstance()
		{
			static T instance;
			return instance;
		}
	};
}