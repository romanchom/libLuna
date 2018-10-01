#pragma once

#include "StrandConfiguration.hpp"

#include <cstdint>
#include <cstddef>

namespace luna
{

class Strand
{
protected:
    explicit Strand(StrandConfiguration const & configuration) :
        mConfiguration(configuration)
    {}

public:
    virtual ~Strand() = default;
    virtual void display(uint8_t const * data, size_t length) = 0;
    virtual void enabled(bool value) = 0;
    StrandConfiguration const & configuration() const noexcept { return mConfiguration; }

protected:
    StrandConfiguration mConfiguration;
};

}
