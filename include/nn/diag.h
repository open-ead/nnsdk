/**
 * @brief Module, logging, and symbol operations.
 */

#pragma once

#include <cstddef>
#include <cstdint>

#include <nn/nn_Result.h>

namespace nn::diag {
struct LogMetaData;

struct ModuleInfo {
    char* mPath;
    uint64_t mBaseAddr;
    uint64_t mSize;
};

enum AssertionType {};

namespace detail {
// LOG
void LogImpl(nn::diag::LogMetaData const&, char const*, ...);
[[noreturn]] void AbortImpl(const char*, const char*, const char*, int32_t);
[[noreturn]] void AbortImpl(const char*, const char*, const char*, int, const char*, ...);
[[noreturn]] void AbortImpl(const char*, const char*, const char*, int, const Result*, const char*,
                            ...);

void OnAssertionFailure(nn::diag::AssertionType, char const*, char const*, char const*, int);
}  // namespace detail

// MODULE / SYMBOL
size_t GetSymbolName(char* name, size_t nameSize, uintptr_t addr);
uint64_t GetRequiredBufferSizeForGetAllModuleInfo();
int32_t GetAllModuleInfo(nn::diag::ModuleInfo** out, void* buffer, uint64_t bufferSize);
uint64_t GetSymbolSize(uint64_t addr);
}  // namespace nn::diag

#define NN_ABORT nn::diag::detail::AbortImpl("", "", "", 0)

#define NN_ABORT_IF_FAIL(arg1)                                                                     \
    {                                                                                              \
        const nn::Result& nnDetailAssertArgValue_arg1 = arg1;                                      \
        if (nnDetailAssertArgValue_arg1.IsFailure())                                               \
            nn::diag::detail::AbortImpl("", "", "", 0, &nnDetailAssertArgValue_arg1, "");          \
    }
