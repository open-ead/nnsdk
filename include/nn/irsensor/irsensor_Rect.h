#pragma once

#include <nn/types.h>

namespace nn::irsensor {
struct Rect {
    uint16_t x = 0;
    uint16_t y = 0;
    uint16_t width = 320;
    uint16_t height = 240;
};
}  // namespace nn::irsensor
