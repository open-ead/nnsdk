#pragma once

#include <nn/fs/fs_Types.h>
#include <nn/nn_Result.h>

namespace nn::ncm {
enum class SystemDataId : std::uint64_t { Err = 0x10000000000801 };  // TODO: move
}  // namespace nn::ncm

namespace nn::fs {

/*
    Mount SD card. Must have explicit permission.
    mount: drive to mount to.
*/
bool MountSdCardForDebug(const char* mount);

Result MountSdCard(const char* mountPoint);
Result MountSystemData(const char* mountPoint, ncm::SystemDataId id);
bool IsSdCardInserted();
Result FormatSdCard();
Result FormatSdCardDryRun();
bool IsExFatSupported();

Result MountHost(const char* mount, const char* path);
Result MountHostRoot();
Result UnmountHostRoot();

Result Unmount(const char* mountPoint);

}  // namespace nn::fs
