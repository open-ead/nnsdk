#pragma once

#include <cstdint>

namespace nn::audio {

using NodeId = uint32_t;
const int BufferAlignSize = 64;

struct AudioDeviceName {
    char raw_name[0x100];
};
static_assert(sizeof(AudioDeviceName) == 0x100);

struct DelayType {
    uint64_t* _0;
};
}  // namespace nn::audio
