#pragma once

#include <cstdint>

namespace nn::audio {

struct VoiceInfo;

struct BiquadFilterParameter {
    bool enable;
    int16_t numerator[3];
    int16_t denominator[2];
};
static_assert(sizeof(BiquadFilterParameter) == 0xc);

struct VoiceType {
    enum PlayState {
        PlayState_Play,
        PlayState_Stop,
        PlayState_Pause,
    };

    static const int PriorityHighest = 0;
    static const int PriorityLowest = 255;
    static const int WaveBufferCountMax = 4;
    static const int ChannelCountMax = 6;

    static float GetPitchMax();
    static float GetPitchMin();
    static float GetVolumeMax();
    static float GetVolumeMin();

    static const int BiquadFilterCountMax = 2;

    VoiceInfo* _pVoiceInfo{};
};
static_assert(sizeof(VoiceType) == 0x8);

}  // namespace nn::audio
