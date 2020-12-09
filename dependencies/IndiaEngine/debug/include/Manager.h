#pragma once
#include "Core.h"
#include "Object.h"
#include <memory>

namespace India {

	/**
	* Base class for managers used to identify them.
	*/
	class India_EXPORT Manager {
	public:
		Manager(Manager&& other) = default;
		Manager& operator=(Manager&& other) = default;
		Manager() noexcept;
		virtual ~Manager() = 0;
	private:
		
	};

}
