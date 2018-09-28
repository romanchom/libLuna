#include "client/Decoder.hpp"

#include "Packets.hpp"

#include <cstdint>

namespace luna {
namespace client {

Decoder::Decoder(Listener * listener) :
    mListener(listener)
{}

void Decoder::decode(ByteStream & stream)
{
    uint8_t id;
    stream >> id;
    switch (id) {
        case LunaConfiguration::id:
            {
                LunaConfiguration config;
                stream >> config;
                mListener->strandConfigurationReceived(config);
            }
            break;
        case DataChannelConfiguration::id:
            {
                DataChannelConfiguration config;
                stream >> config;
                mListener->dataChannelOpened(config);
            }
            break;
        default:
            throw std::runtime_error("Unrecognised packet id.");
    }
}

}
}
