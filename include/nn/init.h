/**
 * @file init.h
 * @brief Initialization functions for OS related functions.
 */

#pragma once

#include <nn/mem.h>
#include <nn/types.h>

namespace nn {
namespace init {
void InitializeAllocator(void* addr, uint64_t size);
nn::mem::StandardAllocator* GetAllocator();

namespace detail {
void* DefaultAllocatorForThreadLocal(uint64_t, uint64_t);
void* DefaultDeallocatorForThreadLocal(void*, uint64_t);
}  // namespace detail
}  // namespace init
}  // namespace nn
