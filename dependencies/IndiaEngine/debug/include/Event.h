#pragma once
#include <string>
#include "Core.h"

namespace India {

	template<typename EventType>
	class Event {
	public: 
		/**
		Returns the type of event
		*/
		virtual EventType GetType() const noexcept = 0;
		/**
		 Sets the InputEvent type.
		*/
		virtual void SetType(const EventType& type) noexcept = 0;
	};
}