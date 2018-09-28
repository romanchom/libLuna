#pragma once

#include "ByteStream.hpp"
#include "server/Listener.hpp"
#include "../Decoder.hpp"

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
