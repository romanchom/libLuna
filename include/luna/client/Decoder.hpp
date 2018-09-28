#pragma once

#include "../ByteStream.hpp"
#include "Listener.hpp"
#include "../Decoder.hpp"

namespace luna {
namespace client {

class Decoder : public luna::Decoder
{
public:
    Decoder(Listener * listener);
    void decode(ByteStream & stream) override;
private:
    Listener * mListener;
};

}
}
