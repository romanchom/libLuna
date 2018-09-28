#include "client/Encoder.hpp"

#include "Packets.hpp"

namespace luna {
namespace client {

Encoder::Encoder(StreamSink * streamSink) :
    luna::Encoder(streamSink)
{}

void Encoder::requestStrandConfiguration()
{
    send<LunaConfiguration>([](auto & stream){});
}

void Encoder::requestDataChannel()
{
    send<DataChannelConfiguration>([](auto & stream){});
}

}
}
