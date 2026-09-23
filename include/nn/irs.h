#pragma once

#include <nn/irs/MomentStatistic.h>
#include <nn/irs/Rect.h>
#include <nn/types.h>
#include <nn/util.h>

namespace nn::irsensor {
struct ClusteringProcessorConfig;
struct ClusteringProcessorState;

#if NN_SDK_VER <= NN_MAKE_VER(4, 0, 0)
struct DpdProcessorConfig;
struct DpdProcessorPointingState;
struct DpdProcessorState;
#endif

struct HandAnalysisConfig;
struct ImageTransferProcessorConfig;
struct ImageTransferProcessorState;
struct MomentProcessorConfig;
struct MomentProcessorState;
struct TeraPluginProcessorConfig;
struct TeraPluginProcessorState;

enum class IrCameraStatus : uint32_t {
    Available,
    Unsupported,
    Unconnected,
};

struct IrCameraHandle {
    uint8_t playerNumber;
    uint8_t deviceType;
    uint8_t reserved[2];
};

IrCameraHandle GetIrCameraHandle(const uint32_t&);
void Initialize(const IrCameraHandle& handle);
void Finalize(const IrCameraHandle& handle);
IrCameraStatus GetIrCameraStatus(const IrCameraHandle& handle);
void StopImageProcessor(const IrCameraHandle& handle);

void GetMomentProcessorDefaultConfig(MomentProcessorConfig* outConfig);
void RunMomentProcessor(const IrCameraHandle& handle, const MomentProcessorConfig& config);
Result GetMomentProcessorState(MomentProcessorState* outState, const IrCameraHandle& handle);
Result GetMomentProcessorStates(MomentProcessorState* outStates, int32_t* outCount, int32_t,
                                const IrCameraHandle& handle);
MomentStatistic CalculateMomentRegionStatistic(const MomentProcessorState* state, const Rect&, int32_t,
                                               int32_t, int32_t, int32_t);

void GetClusteringProcessorDefaultConfig(ClusteringProcessorConfig* outConfig);
void RunClusteringProcessor(const IrCameraHandle& handle, const ClusteringProcessorConfig& config);
Result GetClusteringProcessorState(ClusteringProcessorState* outState,
                                   const IrCameraHandle& handle);
Result GetClusteringProcessorStates(ClusteringProcessorState* outStates, int32_t* outCount, int32_t,
                                    const IrCameraHandle& handle);

void GetImageTransferProcessorDefaultConfig(ImageTransferProcessorConfig* outConfig);
void RunImageTransferProcessor(const IrCameraHandle& handle,
                               const ImageTransferProcessorConfig& config, void*, uint64_t);
Result GetImageTransferProcessorState(ImageTransferProcessorState* outState, void*, uint64_t,
                                      const IrCameraHandle& handle);

Result RunHandAnalysis(const IrCameraHandle& handle, const HandAnalysisConfig& config);

Result RunTeraPluginProcessor(const IrCameraHandle& handle,
                              const TeraPluginProcessorConfig& config);

#if NN_SDK_VER <= NN_MAKE_VER(4, 0, 0)
void RunDpdProcessor(const IrCameraHandle& handle);
void GetDpdProcessorDefaultConfig(DpdProcessorConfig* outConfig);
void RunDpdProcessor(const IrCameraHandle& handle, const DpdProcessorConfig& config);
Result GetDpdProcessorStates(DpdProcessorPointingState* outStates, int32_t* outCount, int32_t,
                             const IrCameraHandle& handle);
Result GetDpdProcessorStates(DpdProcessorState* outStates, int32_t* outCount, int32_t,
                             const IrCameraHandle& handle);
#endif

Result GetTeraPluginProcessorStates(TeraPluginProcessorState* outStates, int32_t* outCount, int32_t, long,
                                    uint32_t, int32_t, const IrCameraHandle& handle);

Rect MakeRect(int32_t x, int32_t y, int32_t width, int32_t height);
}  // namespace nn::irsensor
