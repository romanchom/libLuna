#pragma once

#include <cstdint>

#include "ByteStream.hpp"
#include "StreamSink.hpp"
#include "Packets.hpp"

namespace luna
{

class Encoder
{
public:
    Encoder(StreamSink * streamSink);

    void sendStrandConfiguration(LunaConfiguration const & configration);
    void sendDataChannelOpened(DataChannelConfiguration const & channel_configuration);
private:
    StreamSink * mStreamSink;
};

}
