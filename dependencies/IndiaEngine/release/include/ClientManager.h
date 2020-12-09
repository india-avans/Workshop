#pragma once
#include "BaseNetworkManager.h"

namespace India {
	/**
	(work in progress, unutilized)
	 */
	class ClientManager : public BaseNetworkManager
	{
	public:
		void Start() override;
		void SendPacket(NetworkPacket packet);
		void OnDataReceived(NetworkPacket* packet);
		void Subscribe(std::string event_name, std::function<void(NetworkPacket)> callback);
	private:
	private:
		struct impl;
		std::unique_ptr<impl> pimpl;
		void PollNetwork() override;
	};
}