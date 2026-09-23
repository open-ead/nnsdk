#pragma once

#include <cstddef>

#include <nn/audio/audio_Common.h>

namespace nn::audio {

enum AudioRendererRenderingDevice {
    AudioRendererRenderingDevice_AudioCoprocessor,
    AudioRendererRenderingDevice_Cpu,
};

enum AudioRendererExecutionMode {
    AudioRendererExecutionMode_AutoExecution,
    AudioRendererExecutionMode_ManualExecution,
};

struct AudioRendererHandle {
    void* _handle;
    void* _context;
};
static_assert(sizeof(AudioRendererHandle) == 0x10);

struct AudioRendererParameter {
    int32_t sampleRate;
    int32_t sampleCount;
    int32_t mixBufferCount;
    int32_t subMixCount;
    int32_t voiceCount;
    int32_t sinkCount;
    int32_t effectCount;
    int32_t performanceFrameCount;
    bool isVoiceDropEnabled;
    int32_t splitterCount;
    int32_t splitterSendChannelCount;
    AudioRendererRenderingDevice renderingDevice;
    AudioRendererExecutionMode executionMode;
    uint32_t _magic;

    static const int32_t MixBufferCountMax = 256;
    static const int32_t SubMixCountMax = 256;
    static const int32_t VoiceCountMax = 1024;
    static const int32_t SinkCountMax = 256;
    static const int32_t EffectCountMax = 256;
    static const int32_t PerformanceFrameCountMax = 4096;
    static const int32_t SplitterCountMax = 256;
};
static_assert(sizeof(AudioRendererParameter) == 0x38);

class VoiceInfoManager;
class MixManager;
class EffectManager;
class SinkManager;
class PerformanceBufferManager;
class MemoryPoolManager;
class BehaviorManager;
class SplitterInfoManager;
struct AudioRendererConfig {
    VoiceInfoManager* _pVoiceInfoManager;
    MixManager* _pMixManager;
    EffectManager* _pEffectManager;
    SinkManager* _pSinkManager;
    PerformanceBufferManager* _pPerformanceBufferManager;
    MemoryPoolManager* _pMemoryPoolManager;
    BehaviorManager* _pBehaviorManager;
    SplitterInfoManager* _pSplitterInfoManager;
    void* _pInParameter;
    size_t _pInParameterSize;
    void* _pOutStatus;
    size_t _pOutStatusSize;
    void* _pConfigBuffer;
    size_t _configBufferSize;
};
static_assert(sizeof(AudioRendererConfig) == 0x70);

}  // namespace nn::audio
