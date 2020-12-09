#pragma once
#include "Core.h"

#include <vector>
#include <functional>
#include <string>
#include <map>

namespace India {

	#define callback(FUNC) \
	std::bind(FUNC, this, std::placeholders::_1)

	#define callback_cxt(FUNC, CXT) \
	std::bind(FUNC, CXT, std::placeholders::_1)

	template<typename EventArgs>
	/**
	Event system which copies the C# behaviour.
	*/
	class IndiaEvent {
	public:
		void Invoke(const EventArgs& args) const
		{
			for (auto& subscriber : _subscribers)
			{
				subscriber.second(args);
			}
		}

		void operator+=(std::function<void(const EventArgs&)> callback)
		{
			std::string id{ reinterpret_cast<const char*>(&callback) };
			_subscribers[id] = callback;
		}

		void operator-=(std::function<void(const EventArgs&)> callback)
		{
			std::string id = reinterpret_cast<const char*>(&callback);
			_subscribers.erase(std::remove_if(_subscribers.begin(), _subscribers.end(), [](const std::pair<std::string, std::function<void(const EventArgs&)>>& subscriber) {
				return strcmp(subscriber.first.c_str(), id.c_str()) == 0; }), _subscribers.end());
		}

	private:
		std::map<std::string, std::function<void(const EventArgs&)>> _subscribers;
	};
}

