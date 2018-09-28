#include "server/Decoder.hpp"
#include "server/Listener.hpp"

#include "Packets.hpp"

#include <cstdint>

namespace luna {
namespace server {

Decoder::Decoder(Listener * listener) :
    mListener(listener)
{
}

void Decoder::decode(ByteStream & stream)
{
    uint8_t id;
    stream >> id;
    switch (id) {
        case LunaConfiguration::id:
            mListener->strandConfigurationRequested();
            break;
        case DataChannelConfiguration::id:
            mListener->dataChannelRequested();
            break;
        default:
            throw std::runtime_error("Unrecognised packet id.");
    }
}

}
}
