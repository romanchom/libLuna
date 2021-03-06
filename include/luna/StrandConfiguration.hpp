#pragma once

#include "BitDepth.hpp"
#include "ColorChannels.hpp"
#include "ColorSpace.hpp"
#include "Point.hpp"

#include <cstdint>

namespace luna
{

struct StrandConfiguration {
    uint32_t pixelCount;
    ColorChannels colorChannels;
    BitDepth bitDepth;
    ColorSpace colorSpace;
    Point begin;
    Point end;
};

}
