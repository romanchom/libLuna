#pragma once

#include "ByteStream.hpp"

namespace luna {

class Decoder
{
public:
    virtual ~Decoder() = default;
    virtual void decode(ByteStream & stream) = 0;
};

}
