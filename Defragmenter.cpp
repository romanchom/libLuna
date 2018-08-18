#include "Defragmenter.hpp"

#include "ByteStream.hpp"
#include "Decoder.hpp"

namespace luna
{

Defragmenter::Defragmenter(Decoder * decoder) :
    mDecoder(decoder),
    mBeginPointer(mBuffer),
    mEndPointer(mBuffer)
{
}

void Defragmenter::receiveStream(uint8_t const * buffer, size_t size)
{
    copyToBuffer(buffer, size);

    // while you can read at least the size of the payload
    while (occupiedSpace() >= sizeof(PayloadSize)) {
        ByteStream binaryStream(mBeginPointer, occupiedSpace());
        PayloadSize payloadSize;
        binaryStream >> payloadSize;

        // if you you the have entire payload
        if(payloadSize + sizeof(PayloadSize) <= occupiedSpace()) {
            mDecoder->decode(binaryStream);
            mBeginPointer += payloadSize + sizeof(PayloadSize);
        }
    }
}

void Defragmenter::copyToBuffer(uint8_t const * buffer, size_t size)
{
    auto availableSpace = static_cast<size_t>(mBuffer + BUFFER_SIZE - mEndPointer);

    if (size > availableSpace) {
        availableSpace = BUFFER_SIZE - occupiedSpace();
        if (size > availableSpace) {
            throw std::runtime_error("Insufficient space in Defragmenter");
        } else {
            memmove(mBuffer, mBeginPointer, occupiedSpace());
            mEndPointer = mBuffer + occupiedSpace();
            mBeginPointer = mBuffer;
        }
    }

    memcpy(mEndPointer, buffer, size);
    mEndPointer += size;
}

size_t Defragmenter::occupiedSpace() const noexcept
{
    return static_cast<size_t>(mEndPointer - mBeginPointer);
}

void Defragmenter::reset() noexcept
{
    mBeginPointer = mBuffer;
    mEndPointer = mBuffer;
}

}
