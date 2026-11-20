#pragma once

#include <nn/fs/fs_Bcat.h>
#include <nn/fs/fs_Directories.h>
#include <nn/fs/fs_Files.h>
#include <nn/fs/fs_Mount.h>
#include <nn/fs/fs_Priority.h>
#include <nn/fs/fs_Rom.h>
#include <nn/fs/fs_Save.h>
#include <nn/fs/fs_Types.h>

namespace nn::fs {

void SetPriorityOnCurrentThread(fs::Priority priority);

}  // namespace nn::fs
