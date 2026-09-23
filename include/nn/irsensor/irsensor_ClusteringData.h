#pragma once

#include <nn/irs/MomentStatistic.h>
#include <nn/irs/Rect.h>

namespace nn::irsensor {
struct ClusteringData {
    MomentStatistic momentStatistic;
    int32_t pixelCount;
    Rect bounds;
};
}  // namespace nn::irsensor
