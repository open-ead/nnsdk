#pragma once

#include <cstddef>
#include <cstdint>

namespace nn::audio {

struct WaveBuffer {
    const void* buffer;
    size_t size;
    int32_t startSampleOffset;
    int32_t endSampleOffset;
    bool loop;
    bool isEndOfStream;
    const void* pContext;
    size_t contextSize;
};
static_assert(sizeof(WaveBuffer) == 0x30);

}  // namespace nn::audio
