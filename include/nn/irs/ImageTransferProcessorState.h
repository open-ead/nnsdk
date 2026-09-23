#pragma once

#include <nn/types.h>

namespace nn::irsensor {
struct ImageTransferProcessorState {
    int64_t samplingNumber;
    int32_t ambientNoiseLevel;
    uint8_t reserved[4];
};
}  // namespace nn::irsensor
