#pragma once

#include <nn/audio/audio_Common.h>

namespace nn::audio {

struct PerformanceFrameHeader;

enum PerformanceEntryType {
    PerformanceEntryType_Unknown,
    PerformanceEntryType_Voice,
    PerformanceEntryType_SubMix,
    PerformanceEntryType_FinalMix,
    PerformanceEntryType_Sink,
    PerformanceEntryType_Count
};

enum PerformanceDetailType {
    PerformanceDetailType_Unknown,
    PerformanceDetailType_PcmInt16,
    PerformanceDetailType_Adpcm,
    PerformanceDetailType_VolumeRamp,
    PerformanceDetailType_BiquadFilter,
    PerformanceDetailType_Mix,
    PerformanceDetailType_Delay,
    PerformanceDetailType_Aux,
    PerformanceDetailType_Reverb,
    PerformanceDetailType_Reverb3d,
    PerformanceDetailType_PcmFloat
};

struct PerformanceEntry {
    NodeId id;
    int32_t startTime;
    int32_t processingTime;
    int8_t entryType;
    int8_t _padding[3];
};
static_assert(sizeof(PerformanceEntry) == 0x10);

struct PerformanceDetail {
    int32_t nodeId;
    int32_t startTime;
    int32_t processingTime;
    PerformanceDetailType detailType;
    PerformanceEntryType entryType;
};
static_assert(sizeof(PerformanceDetail) == 0x14);

}  // namespace nn::audio
