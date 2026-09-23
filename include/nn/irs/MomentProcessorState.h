#pragma once

#include <nn/irs/MomentStatistic.h>
#include <nn/types.h>

namespace nn::irsensor {
struct MomentProcessorState {
    int64_t samplingNumber;
    int64_t timeStamp;
    int32_t ambientNoiseLevel;
    uint8_t reserved[4];
    MomentStatistic statistics[48];
};
}  // namespace nn::irsensor
