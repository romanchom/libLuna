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
        size_t strandByteCount =
            strand->pixelCount()
            * channelCount(strand->colorChannels())
            * bitDepthSize(strand->bitDepth());

        strand->display(data, strandByteCount);

        data += strandByteCount;
    }
}

void StrandDecoder::addStrand(Strand * strand)
{
    mStrands.emplace_back(strand);
}

LunaConfiguration StrandDecoder::getConfiguration() const noexcept
{
    LunaConfiguration config;
    auto & strands = config.strands;
    strands.reserve(mStrands.size());
    for (auto const & strand : mStrands) {
        luna::StrandConfiguration strandConfig = {
            strand->colorChannels(),
            static_cast<uint32_t>(strand->pixelCount()),
            {1000, 200, 300},
            {100, 200, 300},
            strand->bitDepth()
        };
        strands.emplace_back(strandConfig);
    }

    return config;
}

}
}
