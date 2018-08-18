#pragma once

#include <cstdint>
#include <cstring>
#include <stdexcept>
#include <vector>

namespace luna
{

class ByteStream
{
public:
    explicit ByteStream(uint8_t * buffer, size_t size) :
        mBuffer(buffer),
        mEnd(mBuffer + size),
        mPointer(mBuffer)
    {
    }

    void write(uint8_t const * source, size_t size)
    {
        if (mPointer + size > mEnd) {
            throw std::out_of_range("Attempting to write beyond allowed ByteStream range.");
        }
        memcpy(mPointer, source, size);
        mPointer += size;
    }

    void read(uint8_t * destination, size_t size)
    {
        if (mPointer + size > mEnd) {
            throw std::out_of_range("Attempting to read beyond allowed ByteStream range.");
        }
        memcpy(destination, mPointer, size);
        mPointer += size;
    }

    uint8_t const * data() const noexcept { return mBuffer; }
    size_t size() const noexcept { return static_cast<size_t>(mPointer - mBuffer); }
    void reset() noexcept { mPointer = mBuffer; }
private:
    uint8_t * const mBuffer;
    uint8_t * const mEnd;
    uint8_t * mPointer;
};


template<typename T>
ByteStream & operator<<(ByteStream & stream, T && object) {
    auto source = reinterpret_cast<uint8_t const *>(&object);
    stream.write(source, sizeof(T));
    return stream;
}

template<typename T>
ByteStream & operator>>(ByteStream & stream, T & object) {
    auto source = reinterpret_cast<uint8_t *>(&object);
    stream.read(source, sizeof(T));
    return stream;
}

template<typename T>
ByteStream & operator<<(ByteStream & stream, std::vector<T> const & vector) {
    auto size = static_cast<uint16_t>(vector.size());
    stream << size;
    for(auto && item : vector) {
        stream << item;
    }
    return stream;
}

template<typename T>
ByteStream & operator>>(ByteStream & stream, std::vector<T> & vector) {
    vector.clear();
    uint16_t size;
    stream >> size;
    vector.reserve(size);
    for (uint16_t i = 0; i < size; ++i) {
        vector.emplace_back();
        stream >> vector.back();
    }
    return stream;
}

}
