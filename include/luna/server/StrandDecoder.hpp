#pragma once

#include "../Strand.hpp"
#include "../Packets.hpp"

#include <cstdint>
#include <vector>

namespace luna {
namespace server {

class StrandDecoder
{
public:
    void decode(uint8_t const * data, size_t length);
    void addStrand(Strand * strand);
    void enabled(bool value);
    LunaConfiguration getConfiguration() const noexcept;

private:
    std::vector<Strand *> mStrands;
};

}
}
