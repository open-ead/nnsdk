cmake_minimum_required(VERSION 3.15)

project(NintendoSDK C CXX)
set(NINTENDOSDK_PATH "${CMAKE_CURRENT_SOURCE_DIR}")

add_library(nnSdk INTERFACE)
target_sources(nnSdk PUBLIC
  FILE_SET HEADERS
  BASE_DIRS include/
  FILES

# Run 'task configure' to update this list
# SOURCES_START

    include/nn/account.h
    include/nn/album/album_types.h
    include/nn/am.h
    include/nn/aoc.h
    include/nn/applet.h
    include/nn/atk.h
    include/nn/audio.h
    include/nn/bcat.h
    include/nn/crypto.h
    include/nn/diag.h
    include/nn/err.h
    include/nn/friends.h
    include/nn/fs.h
    include/nn/fs/fs_bcat.h
    include/nn/fs/fs_directories.h
    include/nn/fs/fs_files.h
    include/nn/fs/fs_mount.h
    include/nn/fs/fs_rom.h
    include/nn/fs/fs_save.h
    include/nn/fs/fs_types.h
    include/nn/hid.h
    include/nn/image.h
    include/nn/init.h
    include/nn/irs.h
    include/nn/irs/ClusteringData.h
    include/nn/irs/ClusteringProcessorConfig.h
    include/nn/irs/ClusteringProcessorState.h
    include/nn/irs/DpdProcessorConfig.h
    include/nn/irs/DpdProcessorPointingState.h
    include/nn/irs/DpdProcessorState.h
    include/nn/irs/HandAnalysisConfig.h
    include/nn/irs/HandAnalysisMode.h
    include/nn/irs/ImageTransferProcessorConfig.h
    include/nn/irs/ImageTransferProcessorFormat.h
    include/nn/irs/ImageTransferProcessorState.h
    include/nn/irs/MomentProcessorConfig.h
    include/nn/irs/MomentProcessorState.h
    include/nn/irs/MomentStatistic.h
    include/nn/irs/Rect.h
    include/nn/irs/TeraPluginProcessorConfig.h
    include/nn/irs/TeraPluginProcessorState.h
    include/nn/irs/sys.h
    include/nn/mem.h
    include/nn/nfp.h
    include/nn/nfp/nfp.h
    include/nn/nfp/nfp_types.h
    include/nn/nifm.h
    include/nn/nn.h
    include/nn/nn_BitTypes.h
    include/nn/nnmusl.hpp
    include/nn/oe.h
    include/nn/os.h
    include/nn/os/detail/os_InternalConditionVariable-os.horizon.h
    include/nn/os/detail/os_InternalConditionVariable.h
    include/nn/os/detail/os_InternalCriticalSection-os.horizon.h
    include/nn/os/detail/os_InternalCriticalSection.h
    include/nn/os/detail/os_ThreadTypes-os.horizon.h
    include/nn/os/os_ConditionVariableCommon.h
    include/nn/os/os_Event.h
    include/nn/os/os_EventCommon.h
    include/nn/os/os_EventTypes.h
    include/nn/os/os_MessageQueue.h
    include/nn/os/os_MessageQueueTypes.h
    include/nn/os/os_Mutex.h
    include/nn/os/os_MutexTypes.h
    include/nn/os/os_ThreadCommon.h
    include/nn/os/os_ThreadTypes.h
    include/nn/pl.h
    include/nn/prepo.h
    include/nn/ro.h
    include/nn/settings.h
    include/nn/sf.h
    include/nn/sf/hipc.h
    include/nn/socket.h
    include/nn/ssl.h
    include/nn/svc.h
    include/nn/swkbd/swkbd.h
    include/nn/time.h
    include/nn/types.h
    include/nn/util.h
    include/nn/util/AccessorBase.h
    include/nn/util/MathTypes.h
    include/nn/util/detail/util_ArithmeticImpl.h
    include/nn/util/detail/util_TypeTraits.h
    include/nn/util/util_Arithmetic.h
    include/nn/util/util_BinTypes.h
    include/nn/util/util_BinaryFormat.h
    include/nn/util/util_BitArray.h
    include/nn/util/util_BitFlagSet.h
    include/nn/util/util_BitPack.h
    include/nn/util/util_BitUtil.h
    include/nn/util/util_BytePtr.h
    include/nn/util/util_IntrusiveList.h
    include/nn/util/util_ResDic.h
    include/nn/util/util_StringUtil.h
    include/nn/util/util_StringView.h
    include/nn/util/util_TypedStorage.h
    include/nn/vi.h
    include/nn/xcd.h

# SOURCES_END
)

set_target_properties(nnSdk PROPERTIES VERIFY_INTERFACE_HEADER_SETS ON)

# Downstream projects should set something like:
# set(NN_SDK 4.4.0)
# set(NN_SDK_TYPE "Release")
function(nn_ver ID)
  set(VER ${${ID}})
  string(REPLACE "." ";" VER "${VER}")

  list(LENGTH VER SEGS)
  if(SEGS LESS 3)
    set(DEF_VER 1 0 0)
    list(SUBLIST DEF_VER ${SEGS} -1 DEF_VER)
    list(APPEND VER ${DEF_VER})

    message(AUTHOR_WARNING "${ID} semver is not complete (%d.%d.%d): ${${ID}}")
  endif()

  list(POP_FRONT VER MAJOR MINOR PATCH)
  
  foreach(VAR IN ITEMS MAJOR MINOR PATCH)
      target_compile_definitions(nnSdk INTERFACE ${ID}_${VAR}=${${VAR}})
  endforeach()
endfunction()
nn_ver(NN_SDK)
target_compile_definitions(nnSdk INTERFACE NN_SDK_TYPE="${NN_SDK_TYPE}")

target_include_directories(nnSdk INTERFACE include/)
target_compile_options(nnSdk INTERFACE
    -fno-strict-aliasing
    -fno-exceptions
    -Wall
    -Wextra
    -Wno-invalid-offsetof
)

add_subdirectory(lib/nvn)
add_subdirectory(lib/gfx)
