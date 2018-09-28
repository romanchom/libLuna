#pragma once

#include "../Packets.hpp"

namespace luna {
namespace client {

class Listener
{
public:
    virtual ~Listener() = default;

    virtual void strandConfigurationReceived(LunaConfiguration const & configuration) = 0;
    virtual void dataChannelOpened(DataChannelConfiguration const & configuration) = 0;
};

}
}

