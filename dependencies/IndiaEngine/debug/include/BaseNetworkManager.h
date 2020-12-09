#pragma once
#include "Core.h"
#include "Manager.h"
#include "NetworkPacket.h"

#include <string>
#include <vector>
#include <functional>

#define BUFFERSIZE (1000)

namespace India {

    struct NetworkAdress {
    public:
        unsigned int host;
        unsigned short port;
    };
    /**
    (work in progress, unutilized)
    */
    class BaseNetworkManager : public Manager {
    public:
        virtual ~BaseNetworkManager() override = 0;
        void SetAddress(std::string address);
        void SetPollingRate(int ms);
        void SetNetworkPort(int port);
        virtual void Enemyt() = 0;
    protected:
        BaseNetworkManager();
        char buffer[BUFFERSIZE];
        int polling_rate = 1;
        virtual void PollNetwork() = 0;

        NetworkAdress address;
        NetworkPacket ToNetworkPacket(unsigned char data, unsigned int sender_id);
    private:
        struct impl;
        std::unique_ptr<impl> pimpl;
    };
}