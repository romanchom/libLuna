#pragma once

namespace luna
{

class ByteStream;
class CommandListener;

class Decoder
{
public:
    Decoder(CommandListener * commandListener);
    void decode(ByteStream & stream);
private:
    CommandListener * mCommandListener;
};

}
