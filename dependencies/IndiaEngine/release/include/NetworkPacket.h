#pragma once
#include <string>
#include <map>
#include <iostream>
#include "Core.h"

namespace India {
	/**
	(work in progress, unutilized)
	*/
	struct NetworkPacket {
		std::string type;
		std::string target;
		std::string data;
		std::string senderId;
	};
}