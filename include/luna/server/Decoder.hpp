#pragma once

#include "../ByteStream.hpp"
#include "../Decoder.hpp"
#include "Listener.hpp"

namespace luna {
namespace server {

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
