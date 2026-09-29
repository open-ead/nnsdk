#pragma once

#include <cstdint>

namespace nn::audio {

struct AdpcmContext {
    uint16_t predScale;
    int16_t history[2];
};
static_assert(sizeof(AdpcmContext) == 0x6);

struct AdpcmParameter {
    uint16_t coefficients[16];
};
static_assert(sizeof(AdpcmParameter) == 0x20);

}  // namespace nn::audio
