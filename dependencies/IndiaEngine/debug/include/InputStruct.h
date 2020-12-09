#pragma once
#include <functional>

namespace India {

	typedef std::function<void()> func_ptr_t;

	struct InputStruct {
	public:
		InputStruct(std::string scancode, func_ptr_t callback) : scancode{ scancode }, callback{ callback } {}
		std::string scancode;
		func_ptr_t callback;
	};

}