#pragma once

#include "BitDepth.hpp"
#include "ColorChannels.hpp"

#include <cstdint>
#include <cstddef>

namespace luna
{

class Strand
{
protected:
    explicit Strand(size_t pixelCount, BitDepth bitDepth, ColorChannels colorChannels) :
        mPixelCount(pixelCount),
        mBitDepth(bitDepth),
        mColorChannels(colorChannels)
    {}
public:
    virtual ~Strand() = default;
    virtual void display(uint8_t const * data, size_t length) = 0;
    size_t pixelCount() const noexcept { return mPixelCount; }
    BitDepth bitDepth() const noexcept { return mBitDepth; }
    ColorChannels colorChannels() const noexcept { return mColorChannels; }

    // ColorSpace colorSpace() const noexcept;
private:
    size_t const mPixelCount;
    BitDepth const mBitDepth;
    ColorChannels const mColorChannels;
};

}
