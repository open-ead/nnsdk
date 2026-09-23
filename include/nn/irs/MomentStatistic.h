#pragma once

#include <nn/types.h>

namespace nn::irsensor {
struct MomentStatistic {
    float averageIntensity;
    float centroidX;
    float centroidY;
};
}  // namespace nn::irsensor
