cmake_minimum_required(VERSION 3.24)

project(NintendoSDK C CXX)

set(NVN_API "C" CACHE STRING "Set NVN platform type")
set_property(CACHE NVN_API PROPERTY STRINGS "C" "CPP")
set(NN_GFX_TARGET "NVN" CACHE STRING "Set nn::gfx build target")
set_property(CACHE NN_GFX_TARGET PROPERTY STRINGS "" "NVN")
if(NN_GFX_TARGET STREQUAL "NVN" AND NVN_API STREQUAL "C")
  set(NVN_API "")
endif()

add_library(nnSdk INTERFACE)
target_sources(nnSdk INTERFACE
  FILE_SET HEADERS
  BASE_DIRS include/
  FILES

# Run 'task configure' to update this list
# SOURCES_START

    include/nn/account.h
    include/nn/album.h
    include/nn/album/album_Types.h
    include/nn/am.h
    include/nn/aoc.h
    include/nn/applet.h
    include/nn/audio.h
    include/nn/audio/audio_Adpcm.h
    include/nn/audio/audio_AudioRendererTypes.h
    include/nn/audio/audio_Common.h
    include/nn/audio/audio_EffectTypes.h
    include/nn/audio/audio_FinalMixTypes.h
    include/nn/audio/audio_MemoryPoolTypes.h
    include/nn/audio/audio_PerformanceMetrics.h
    include/nn/audio/audio_PerformanceMetricsTypes.h
    include/nn/audio/audio_SampleFormat.h
    include/nn/audio/audio_SinkTypes.h
    include/nn/audio/audio_SubMixTypes.h
    include/nn/audio/audio_VoiceTypes.h
    include/nn/audio/audio_WaveBuffer.h
    include/nn/bcat.h
    include/nn/bcat/bcat_DeliveryCache.h
    include/nn/bcat/bcat_DeliveryCacheDirectory.h
    include/nn/bcat/bcat_DeliveryCacheFile.h
    include/nn/bcat/bcat_DeliveryCacheProgress.h
    include/nn/bcat/bcat_Util.h
    include/nn/bcat/detail/bcat_DeliveryCacheProgressImpl.h
    include/nn/bcat/detail/bcat_Error.h
    include/nn/bcat/detail/bcat_Ipc.h
    include/nn/bcat/detail/bcat_ShimLibraryGlobal.h
    include/nn/crypto.h
    include/nn/diag.h
    include/nn/err.h
    include/nn/friends.h
    include/nn/fs.h
    include/nn/fs/fs_Bcat.h
    include/nn/fs/fs_Directories.h
    include/nn/fs/fs_Files.h
    include/nn/fs/fs_Mount.h
    include/nn/fs/fs_Rom.h
    include/nn/fs/fs_Save.h
    include/nn/fs/fs_Types.h
    include/nn/hid.h
    include/nn/image.h
    include/nn/init.h
    include/nn/irsensor.h
    include/nn/irsensor/irsensor_ClusteringData.h
    include/nn/irsensor/irsensor_ClusteringProcessorConfig.h
    include/nn/irsensor/irsensor_ClusteringProcessorState.h
    include/nn/irsensor/irsensor_DpdProcessorConfig.h
    include/nn/irsensor/irsensor_DpdProcessorPointingState.h
    include/nn/irsensor/irsensor_DpdProcessorState.h
    include/nn/irsensor/irsensor_HandAnalysisConfig.h
    include/nn/irsensor/irsensor_HandAnalysisMode.h
    include/nn/irsensor/irsensor_ImageTransferProcessorConfig.h
    include/nn/irsensor/irsensor_ImageTransferProcessorFormat.h
    include/nn/irsensor/irsensor_ImageTransferProcessorState.h
    include/nn/irsensor/irsensor_MomentProcessorConfig.h
    include/nn/irsensor/irsensor_MomentProcessorState.h
    include/nn/irsensor/irsensor_MomentStatistic.h
    include/nn/irsensor/irsensor_Rect.h
    include/nn/irsensor/irsensor_System.h
    include/nn/irsensor/irsensor_TeraPluginProcessorConfig.h
    include/nn/irsensor/irsensor_TeraPluginProcessorState.h
    include/nn/mem.h
    include/nn/mem/mem_NumberLineAllocator.h
    include/nn/mem/mem_StandardAllocator.h
    include/nn/nfp.h
    include/nn/nfp/nfp_Types.h
    include/nn/nifm.h
    include/nn/nlibsdk.h
    include/nn/nlibsdk/nlibsdk_CentralHeap.h
    include/nn/nlibsdk/nlibsdk_HeapError.h
    include/nn/nlibsdk/nlibsdk_LockFreePlaceHolderPool.h
    include/nn/nn.h
    include/nn/nn_ApplicationId.h
    include/nn/nn_BitTypes.h
    include/nn/nn_Result.h
    include/nn/nnmusl.h
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
    include/nn/ro/detail/ro_RoModule.h
    include/nn/ro/ro_Types.h
    include/nn/settings.h
    include/nn/sf.h
    include/nn/sf/detail/sf_PointerAndSize.h
    include/nn/sf/sf_Hipc.h
    include/nn/sf/sf_InBuffer.h
    include/nn/sf/sf_Out.h
    include/nn/sf/sf_OutBuffer.h
    include/nn/socket.h
    include/nn/ssl.h
    include/nn/svc.h
    include/nn/swkbd.h
    include/nn/time.h
    include/nn/util.h
    include/nn/util/detail/util_ArithmeticImpl.h
    include/nn/util/detail/util_TypeTraits.h
    include/nn/util/util_AccessorBase.h
    include/nn/util/util_Arithmetic.h
    include/nn/util/util_BinTypes.h
    include/nn/util/util_BinaryFormat.h
    include/nn/util/util_BitArray.h
    include/nn/util/util_BitFlagSet.h
    include/nn/util/util_BitPack.h
    include/nn/util/util_BitUtil.h
    include/nn/util/util_BytePtr.h
    include/nn/util/util_IntrusiveList.h
    include/nn/util/util_MathTypes.h
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
function(nnsdk_ver ID)
  set(VER ${${ID}})
  string(REPLACE "." ";" VER "${VER}")

  list(LENGTH VER SEGS)
  if(SEGS LESS 3)
    set(DEF_VER 1 0 0)
    list(SUBLIST DEF_VER ${SEGS} -1 DEF_VER)
    list(APPEND VER ${DEF_VER})

    message(AUTHOR_WARNING "${ID} semver is malformed (should be %d.%d.%d): ${${ID}}")
  endif()

  list(POP_FRONT VER MAJOR MINOR PATCH)
  
  foreach(VAR IN ITEMS MAJOR MINOR PATCH)
      target_compile_definitions(nnSdk INTERFACE ${ID}_${VAR}=${${VAR}})
  endforeach()
endfunction()
nnsdk_ver(NN_SDK)
target_compile_definitions(nnSdk INTERFACE NN_SDK_TYPE="${NN_SDK_TYPE}")

# these flags are shared with modules (e.g. gfx, nvn)
set(NNSDK_COMPILE_FLAGS
  -fno-strict-aliasing
  -fno-exceptions
  -Wall
  -Wextra
  -Wno-invalid-offsetof
)
function(nnsdk_header_verification_compile_options TARGET)
  target_compile_options(${TARGET} INTERFACE
    "$<$<STREQUAL:$<TARGET_PROPERTY:NAME>,${TARGET}_verify_interface_header_sets>:${NNSDK_COMPILE_FLAGS}>"
  )
endfunction()
# note we do not define flags directly on nnSdk target,
# since as an INTERFACE target we cannot define PRIVATE flags
nnsdk_header_verification_compile_options(nnSdk)

add_subdirectory(lib/gfx)
add_subdirectory(lib/nvn)
