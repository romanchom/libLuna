#include "server/Encoder.hpp"

namespace luna {
namespace server {

Encoder::Encoder(StreamSink * streamSink) :
    luna::Encoder(streamSink)
{}

void Encoder::sendStrandConfiguration(LunaConfiguration const & configuration)
{
    send<LunaConfiguration>([&configuration](auto & stream){
        stream << configuration;
    });
}

void Encoder::sendDataChannelOpened(DataChannelConfiguration const & channelConfiguration)
{
    send<DataChannelConfiguration>([&channelConfiguration](auto & stream){
        stream << channelConfiguration;
    });
}

}
}
