#pragma once

#include <nn/fs/fs_types.h>

namespace nn::fs {

Result MountBcatSaveData(const char*, ApplicationId);
Result CreateBcatSaveData(ApplicationId, int64_t);

}  // namespace nn::fs
