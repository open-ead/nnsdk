#pragma once

#include <nn/irsensor/irsensor_Rect.h>

namespace nn::irsensor {
struct DpdProcessorConfig {
    Rect windowOfInterest;
};
}  // namespace nn::irsensor
