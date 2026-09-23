#pragma once

#include <cstddef>

#include <nn/sf/hipc.h>
#include <nn/svc.h>

namespace nn::sf {
namespace detail {
class PointerAndSize {
public:
    constexpr PointerAndSize() : pointer(nullptr), size(0) {}
    constexpr PointerAndSize(void* ptr, size_t sz) : pointer(ptr), size(sz) {}

    void* pointer;
    size_t size;
};
}  // namespace detail

template <typename A, typename B>
class Out {
public:
    constexpr Out(A& p) : data{&p} {}
    constexpr A& GetData() { return *data; };

    A* data;
};

class OutBuffer {
public:
    constexpr OutBuffer() {}
    constexpr OutBuffer(const detail::PointerAndSize& buf) : buffer(buf) {}
    constexpr OutBuffer(void* ptr, size_t sz) : buffer(ptr, sz) {}

    detail::PointerAndSize buffer;
};

class InBuffer {
public:
    constexpr InBuffer() {}
    constexpr InBuffer(const detail::PointerAndSize& buf) : buffer(buf) {}
    constexpr InBuffer(void* ptr, size_t sz) : buffer(ptr, sz) {}

    detail::PointerAndSize buffer;
};
}  // namespace nn::sf
