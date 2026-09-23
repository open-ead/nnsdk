#pragma once

#include <nn/types.h>

namespace nn {
namespace atk {

class SoundArchive {
public:
    struct SequenceSoundInfo;

    const char* GetItemLabel(uint32_t id) const;
    uint32_t GetItemId(const char* label) const;
};

class SoundActor  // Inherits SoundStartable, size: 0x7C
{
public:
    virtual ~SoundActor();
    uint8_t data[0x7C - 0x4];
};

}  // namespace atk
}  // namespace nn
