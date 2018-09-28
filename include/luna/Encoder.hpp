#pragma once

#include "ByteStream.hpp"
#include "StreamSink.hpp"

namespace luna {

using PacketSize = uint16_t;

constexpr size_t BUFFER_SIZE = 1024;

struct Packet
{
    PacketSize size;
    uint8_t data[BUFFER_SIZE];
};

class Encoder
{
public:
    Encoder(StreamSink * streamSink) : mStreamSink(streamSink) {}

    template<typename P, typename F>
    void send(F && function);
private:
    StreamSink * mStreamSink;
};

template<typename P, typename F>
void Encoder::send(F && function)
{
    Packet packet;
    ByteStream stream(packet.data, BUFFER_SIZE);

    stream << P::id;
    function(stream);

    auto payloadSize = stream.size();
    packet.size = static_cast<PacketSize>(payloadSize);
    mStreamSink->receiveStream(reinterpret_cast<uint8_t const *>(&packet), payloadSize + sizeof(PacketSize));
}

}
