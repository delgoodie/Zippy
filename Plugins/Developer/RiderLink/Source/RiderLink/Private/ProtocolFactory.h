#pragma once

#include <protocol/Protocol.h>
#include "wire/SocketWire.h"

#include "Templates/UniquePtr.h"

namespace ProtocolFactory {
    void InitRdLogging();
    std::shared_ptr<rd::SocketWire::Server> CreateWire(rd::IScheduler* Scheduler, rd::Lifetime SocketLifetime);
    TUniquePtr<rd::Protocol> CreateProtocol(rd::IScheduler* Scheduler, rd::Lifetime SocketLifetime, std::shared_ptr<rd::SocketWire::Server> wire);
};
