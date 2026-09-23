#pragma once

#include <cstddef>

#include <nn/fs/fs_Types.h>
#include <nn/nn_ApplicationId.h>
#include <nn/nn_Result.h>

namespace nn::fs {

Result QueryMountRomCacheSize(size_t* size);
Result QueryMountRomCacheSize(size_t* size, nn::ApplicationId);
Result QueryMountAddOnContentCacheSize(size_t* size, int id);
Result MountRom(const char* name, void* cache, size_t cache_size);
Result MountAddOnContent(const char* name, int id, void* cache, size_t cache_size);
bool CanMountRomForDebug();
Result CanMountRom(nn::ApplicationId);
Result QueryMountRomOnFileCacheSize(uint64_t*, FileHandle);
Result MountRomOnFile(const char*, FileHandle, void*, uint64_t);

}  // namespace nn::fs
