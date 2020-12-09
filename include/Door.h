#pragma once
#include "Objects.h"
#include <iostream>

class Door : public India::GameObject {
public:
	Door(Object& object, std::vector<std::string> args) noexcept;
};