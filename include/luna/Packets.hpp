#pragma once

#include "ByteStream.hpp"
#include "StrandConfiguration.hpp"

#include <vector>
#include <cstdint>

namespace luna
{

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
