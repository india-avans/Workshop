#pragma once
#include "BaseNetworkManager.h"

namespace India {
	/**
	(work in progress, unutilized)
	*/
	class NetworkManager : public BaseNetworkManager
	{
	public:
		void Broadcast(NetworkPacket packet);
		void SendPacket(NetworkPacket packet);
		void Enemyt() override;
		void OnDataReceived(NetworkPacket* packet);
		void RegisterNetworkEvent(std::string event_name);
		bool IsEventRegistered(std::string event_name);
	private:
	private:
		struct impl;
		std::unique_ptr<impl> pimpl;
		void PollNetwork() override;
	};
}