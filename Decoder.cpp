#include "Decoder.hpp"

#include "Packets.hpp"
#include "ByteStream.hpp"
#include "CommandListener.hpp"

#include <cstdint>

namespace luna {

Decoder::Decoder(CommandListener * commandListener) :
    mCommandListener(commandListener)
{
}

void Decoder::decode(ByteStream & stream)
{
    uint8_t id;
    stream >> id;
    switch (id) {
        case LunaConfiguration::id:
            mCommandListener->strandConfigurationRequested();
            break;
        case DataChannelConfiguration::id:
            mCommandListener->dataChannelRequested();
            break;
        default:
            throw std::runtime_error("Unrecognised packet id.");
    }
}

}