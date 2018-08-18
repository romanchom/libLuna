#pragma once 

#include <cstdint>
#include <cstddef>

namespace luna
{

class StreamSink
{
public:
    virtual ~StreamSink() = default;
    virtual void receiveStream(uint8_t const * data, size_t size) = 0;
};

}
