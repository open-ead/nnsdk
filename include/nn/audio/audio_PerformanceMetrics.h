#pragma once

#include <cstddef>
#include <cstdint>

#include <nn/util.h>

#include <nn/audio/audio_PerformanceMetricsTypes.h>

namespace nn::audio {

class PerformanceInfo {
    NN_NO_COPY(PerformanceInfo);
    NN_NO_MOVE(PerformanceInfo);

public:
    PerformanceInfo();
    ~PerformanceInfo();

    bool SetBuffer(const void* buffer, size_t bufferSize);

    bool MoveToNextFrame();

    int32_t GetTotalProcessingTime();
    uint32_t GetFrameIndex();
    const PerformanceEntry* GetEntries(int32_t* outSize);
    const PerformanceDetail* GetDetails(int32_t* outSize);

private:
    const void* m_Buffer;
    size_t m_BufferSize;
    PerformanceFrameHeader* m_Header;
    PerformanceEntry* m_Entries;
    PerformanceDetail* m_Details;
};
static_assert(sizeof(PerformanceInfo) == 0x28);

}  // namespace nn::audio
