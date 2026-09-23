#pragma once

#include <nn/nn_ApplicationId.h>
#include <nn/nn_Result.h>

namespace nn::fs {

Result MountBcatSaveData(const char*, ApplicationId);
Result CreateBcatSaveData(ApplicationId, int64_t);

}  // namespace nn::fs
