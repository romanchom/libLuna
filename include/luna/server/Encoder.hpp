#pragma once

#include "../Encoder.hpp"
#include "../Packets.hpp"
#include "../StreamSink.hpp"

namespace luna {
namespace server {

class Encoder : private luna::Encoder
{
public:
    Encoder(StreamSink * streamSink);

    void sendStrandConfiguration(LunaConfiguration const & configuration);
    void sendDataChannelOpened(DataChannelConfiguration const & channel_configuration);
};

}
}
