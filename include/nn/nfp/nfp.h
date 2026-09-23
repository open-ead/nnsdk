#pragma once

#include <nn/types.h>

namespace nn::os {
struct SystemEventType;
}  // namespace nn::os

namespace nn::nfp {

enum State : uint32_t;
enum DeviceState : uint32_t;
enum ModelType : uint32_t;
enum MountTarget : uint32_t;

struct CommonInfo;
struct DeviceHandle;
struct ModelInfo;
struct RegisterInfo;
struct TagInfo;

Result Initialize();
Result Finalize();

Result ListDevices(nn::nfp::DeviceHandle* out, int32_t* totalOut, int32_t count);
Result StartDetection(const nn::nfp::DeviceHandle& handle);
Result StopDetection(const nn::nfp::DeviceHandle& handle);
Result Mount(const nn::nfp::DeviceHandle& handle, nn::nfp::ModelType modelType,
             nn::nfp::MountTarget mountTarget);
Result Unmount(const nn::nfp::DeviceHandle& handle);

Result OpenApplicationArea(const nn::nfp::DeviceHandle& handle, uint32_t appId);
Result GetApplicationArea(void* buf, uint32_t* outSize, const nn::nfp::DeviceHandle& handle,
                          uint64_t bufSize);
Result SetApplicationArea(const nn::nfp::DeviceHandle& handle, const void* buf, uint64_t bufSize);
Result Flush(const nn::nfp::DeviceHandle& handle);
Result Restore(const nn::nfp::DeviceHandle& handle);

Result GetTagInfo(nn::nfp::TagInfo* out, const nn::nfp::DeviceHandle& handle);
Result GetRegisterInfo(nn::nfp::RegisterInfo* out, const nn::nfp::DeviceHandle& handle);
Result GetCommonInfo(nn::nfp::CommonInfo* out, const nn::nfp::DeviceHandle& handle);
Result GetModelInfo(nn::nfp::ModelInfo* out, const nn::nfp::DeviceHandle& handle);

Result AttachActivateEvent(nn::os::SystemEventType* outEvent, const nn::nfp::DeviceHandle& handle);
Result AttachDeactivateEvent(nn::os::SystemEventType* outEvent,
                             const nn::nfp::DeviceHandle& handle);
Result AttachAvailabilityChangeEvent(nn::os::SystemEventType* outEvent);

nn::nfp::State GetState();
nn::nfp::DeviceState GetDeviceState(const nn::nfp::DeviceHandle& handle);
Result GetNpadId(uint32_t* out, const nn::nfp::DeviceHandle& handle);

}  // namespace nn::nfp
