#pragma once

#include "ByteStream.hpp"
#include "BitDepth.hpp"
#include "ColorChannels.hpp"

#include <vector>
#include <cstdint>

namespace luna
{

struct PointMillimeters {
    int x, y, z;
};

struct StrandConfiguration {
    //ColorSpace colorSpace;
    ColorChannels colorChannels;
    uint32_t count;
    PointMillimeters begin;
    PointMillimeters end;
    BitDepth bitDepth;
};

using IdType = uint8_t;

struct LunaConfiguration {
    enum : IdType { id = 0 };
    std::vector<StrandConfiguration> strands;
};

template<>
inline ByteStream & operator>>(ByteStream & stream, LunaConfiguration & config) {
    stream >> config.strands;
    return stream;
}

template<>
inline ByteStream & operator<<(ByteStream & stream, LunaConfiguration const & config) {
    stream << config.strands;
    return stream;
}

struct DataChannelConfiguration {
    enum : IdType { id = 1 };
    uint16_t port;
    std::vector<uint8_t> sharedKey;
};

template<>
inline ByteStream & operator>>(ByteStream & stream, DataChannelConfiguration & config) {
    stream >> config.port;
    stream >> config.sharedKey;
    return stream;
}

template<>
inline ByteStream & operator<<(ByteStream & stream, DataChannelConfiguration const & config) {
    stream << config.port;
    stream << config.sharedKey;
    return stream;
}

}
