#include "server/StrandDecoder.hpp"

namespace luna {
namespace server {

static size_t bitDepthSize(BitDepth depth)
{
    switch (depth) {
        case BitDepth::integer8:
            return 1;
        case BitDepth::integer16:
            return 2;
        default:
            throw 5; // TODO
    }
}


#ifdef _MSC_VER
#include <intrin.h>
#endif

static size_t channelCount(uint8_t depth)
{
#ifdef _MSC_VER
    return __popcnt(depth);
#else
    return __builtin_popcount(depth);
#endif
}

void StrandDecoder::decode(uint8_t const * data, size_t length)
{
    for (auto const & strand : mStrands) {
        auto const & config = strand->configuration();
        size_t strandByteCount =
            config.pixelCount
            * channelCount(config.colorChannels)
            * bitDepthSize(config.bitDepth);

        strand->display(data, strandByteCount);

        data += strandByteCount;
    }
}

void StrandDecoder::addStrand(Strand * strand)
{
    mStrands.emplace_back(strand);
}


void StrandDecoder::enabled(bool value)
{
    for (auto strand : mStrands) {
        strand->enabled(value);
    }
}

LunaConfiguration StrandDecoder::getConfiguration() const noexcept
{
    LunaConfiguration config;
    auto & strands = config.strands;
    strands.reserve(mStrands.size());
    for (auto const & strand : mStrands) {
        strands.emplace_back(strand->configuration());
    }

    return config;
}

}
}
