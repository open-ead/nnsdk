#pragma once

#include <nn/irs/Rect.h>
#include <nn/types.h>

namespace nn::irsensor {
struct DpdProcessorPointingState {
    int64_t samplingNumber;
    int64_t timeStamp;
    struct {
        uint8_t pointingStatus;
        int32_t _4;
        float _8;
        float positionX;
        float positionY;
        float _14;
        Rect windowOfInterest;
    } data[3];
};
}  // namespace nn::irsensor
