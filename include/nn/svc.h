#pragma once

#include <cstddef>
#include <cstdint>
#include <nn/util.h>
#include <nn/nn_Result.h>

namespace nn::svc {

#ifdef __aarch64__
#define aarch aarch64
#define lp lp64
#define svc_instruction "svc"
#else
#ifdef __arm__
#define aarch aarch32
#define lp ilp32
#define svc_instruction "swi"
#else

#endif
#endif

#ifdef svc_instruction
inline __attribute__((always_inline)) void svc(uint8_t i) {
    asm(svc_instruction " %[i]" ::[i] "i"(i));
}
#endif

struct Handle {
    uint32_t handle;

    Handle(uint32_t h) { handle = h; }

    Handle() : Handle(0) {}

    operator uint32_t() const { return handle; }
};

enum class MemoryPermission { Read = 0, Write = 1, Execute = 2, DontCare = 28 };

enum class MemoryType {
    Free,
    Io,
    Static,
    Code,
    CodeData,
    Normal,
    Shared,
    Alias,
    AliasCode,
    AliasCodeData,
    Ipc,
    Stack,
    ThreadLocal,
    Transferred,
    SharedTransferred,
    SharedCode,
    Inaccessible,
    NonSecureIpc,
    NonDeviceIpc,
    Kernel,
    GeneratedCode,
    CodeOut,
    Coverage,
    Insecure,
};

enum class MemoryAttribute {
    Locked,
    IpcLocked,
    DeviceShared,
    Uncached,
    PermissionLocked,
    GpuSharable,
    GpuShared,
};

struct PageInfo {};  // TODO

namespace lp {
struct MemoryInfo {
    uintptr_t baseAddress;
    size_t size;
    MemoryType memoryType;
    MemoryAttribute memoryAttribute;
    MemoryPermission memoryPermission;
    int32_t ipcRefCount;
    int32_t deviceRefCount;
};
}  // namespace lp


#ifdef aarch
#if NN_SDK_VER >= NN_MAKE_VER(1, 0, 0)  // TODO: find when lp namespace was introduced
namespace aarch::lp {
#endif

Result SetHeapSize(uintptr_t* outHeapAddress, size_t heapSize);
Result SetMemoryPermission(uintptr_t address, size_t regionSize, MemoryPermission memoryPermission);
Result SetMemoryAttribute(uintptr_t address, size_t size, uint32_t mask, uint32_t attr);
Result MapMemory(uintptr_t dstAddress, uintptr_t srcAddress, size_t size);
Result UnmapMemory(uintptr_t dstAddress, uintptr_t srcAddress, size_t size);
Result QueryMemory(svc::lp::MemoryInfo* outMemoryInfo, PageInfo* outPageInfo, uintptr_t address);
void ExitProcess();
Result CreateThread(Handle* outHandle, uintptr_t entryPointAddress, uintptr_t threadContextAddress,
                    uintptr_t stackAddress, int32_t priority, int32_t coreId);
Result StartThread(Handle Handle);
void ExitThread();
void SleepThread(int64_t ns);
Result GetThreadPriority(int32_t* outPriority, Handle handle);
Result SetThreadPriority(Handle handle, int32_t priority);
Result GetThreadCoreMask(int32_t* outCoreId, uint64_t* outAffinityMask, Handle handle);
Result SetThreadCoreMask(Handle handle, int32_t coreId, uint64_t affinityMask);
int32_t GetCurrentProcessorNumber();
Result SignalEvent(Handle handle);
Result ClearEvent(Handle handle);
Result MapSharedMemory(Handle handle, uintptr_t address, size_t size,
                       MemoryPermission memoryPermission);
Result UnmapSharedMemory(Handle handle, uintptr_t address, size_t size);
Result CreateTransferMemory(Handle* outHandle, uintptr_t address, size_t size,
                            MemoryPermission memoryPermission);
Result CloseHandle(Handle handle);
Result ResetSignal(Handle handle);
Result WaitSynchronization(int32_t* outHandleIndex, const Handle* handles, int32_t handleCount,
                           int64_t timeoutNs);

#if NN_SDK_VER >= NN_MAKE_VER(1, 0, 0)
} // namespace aarch::lp
#endif
#endif



}  // namespace nn::svc
