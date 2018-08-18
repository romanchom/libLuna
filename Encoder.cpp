#include "Encoder.hpp"

#include "Packets.hpp"

#include <esp_log.h>

namespace luna
{

using PacketSize = uint16_t;
constexpr size_t BUFFER_SIZE = 1024;

struct Packet
{
    PacketSize size;
    uint8_t data[BUFFER_SIZE];
};

Encoder::Encoder(StreamSink * streamSink) :
    mStreamSink(streamSink)
{
}

void send(Packet * packet, size_t dataSize, StreamSink * streamSink)
{
    packet->size = static_cast<PacketSize>(dataSize);
    streamSink->receiveStream(reinterpret_cast<uint8_t const *>(packet), dataSize + sizeof(PacketSize));
}

void Encoder::sendStrandConfiguration(LunaConfiguration const & configration)
{
    Packet packet;
    ByteStream stream(packet.data, BUFFER_SIZE);
    stream << LunaConfiguration::id << configration;
    send(&packet, stream.size(), mStreamSink);
}

void Encoder::sendDataChannelOpened(DataChannelConfiguration const & channelConfiguration)
{
    Packet packet;
    ByteStream stream(packet.data, BUFFER_SIZE);
    stream << DataChannelConfiguration::id << channelConfiguration;
    send(&packet, stream.size(), mStreamSink);
}

}
