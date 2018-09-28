#pragma once

namespace luna {
namespace server {

class Listener
{
public:
    virtual ~Listener() = default;
    virtual void strandConfigurationRequested() = 0;
    virtual void dataChannelRequested() = 0;
    virtual void dataChannelClosed() = 0;
    virtual void disconnected() = 0;
};

}
}
