#pragma once

#include "StreamSink.hpp"

#include <cstddef>
#include <cstdint>

namespace luna
{

class Decoder;

class Defragmenter : public StreamSink
{
public:
    explicit Defragmenter(Decoder * decoder);

    void receiveStream(uint8_t const * buffer, size_t size) override;
    void reset() noexcept;
private:
    void copyToBuffer(uint8_t const * buffer, size_t size);
    size_t occupiedSpace() const noexcept;

    using PayloadSize = uint16_t;

    static constexpr size_t BUFFER_SIZE = 1024;

    Decoder * mDecoder;

    uint8_t mBuffer[BUFFER_SIZE];
    uint8_t * mBeginPointer;
    uint8_t * mEndPointer;
};

}
