#pragma once

#include <cstdint>

namespace nn::os {

// @nncbindgen typedef uint64_t
struct Tick {
    Tick(uint64_t val) : m_Tick(val) {}

    uint64_t m_Tick;
};

}  // namespace nn::os
