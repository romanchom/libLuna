#pragma once

namespace luna
{

class CommandListener
{
public:
    virtual ~CommandListener() = default;
    virtual void strandConfigurationRequested() = 0;
    virtual void dataChannelRequested() = 0;
    virtual void dataChannelClosed() = 0;
    virtual void disconnected() = 0;
};

}
