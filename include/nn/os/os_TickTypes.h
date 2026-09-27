#pragma once

#include <cstdint>

namespace nn::os {

// TODO - change to class and implement
// @nncbindgen typedef int64_t
struct Tick {
    Tick(uint64_t val) : m_Tick(val) {}

    int64_t m_Tick;
};

}  // namespace nn::os
