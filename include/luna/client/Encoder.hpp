#pragma once

#include "../Encoder.hpp"

namespace luna {
namespace client {

class Encoder : private luna::Encoder
{
public:
    Encoder(StreamSink * streamSink);

    void requestStrandConfiguration();
    void requestDataChannel();
private:
    StreamSink * mStreamSink;
};

}
}
