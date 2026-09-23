#pragma once

#include <nn/types.h>

namespace nn::svc {
struct Handle {
    uint32_t handle;

    Handle(uint32_t h) { handle = h; }

    Handle() : Handle(0) {}

    operator uint32_t() const { return handle; }
};

}  // namespace nn::svc
