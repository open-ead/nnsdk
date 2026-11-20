#pragma once

#include <cstddef>
#include <nn/util/util_BitUtil.h>

namespace nn::util {

class BytePtr {
public:
    explicit BytePtr(void* ptr) : m_Ptr(ptr) {}
    BytePtr(void* ptr, ptrdiff_t offset) : BytePtr(ptr) { Advance(offset); }

    void Reset(void* ptr) { m_Ptr = ptr; }

    void* Get() const { return m_Ptr; }

    template <typename T>
    T* Get() const {
        return static_cast<T*>(Get());
    }

    BytePtr& Advance(ptrdiff_t offset) {
        m_Ptr = Get<char>() + offset;
        return *this;
    }

    ptrdiff_t Distance(const void* other) const {
        return static_cast<const char*>(other) - Get<char>();
    }

    bool IsAligned(size_t alignment) const {
        return is_aligned(reinterpret_cast<uintptr_t>(m_Ptr), alignment);
    }

    BytePtr& AlignUp(size_t alignment) {
        uintptr_t& ptr = reinterpret_cast<uintptr_t&>(m_Ptr);
        ptr = align_up(ptr, alignment);
        return *this;
    }

    BytePtr& AlignDown(size_t alignment) {
        uintptr_t& ptr = reinterpret_cast<uintptr_t&>(m_Ptr);
        ptr = align_down(ptr, alignment);
        return *this;
    }

    BytePtr& operator+=(ptrdiff_t offset) { return Advance(offset); }
    BytePtr& operator-=(ptrdiff_t offset) { return Advance(-offset); }

    BytePtr operator+(ptrdiff_t offset) const { return BytePtr(*this) += offset; }
    BytePtr operator-(ptrdiff_t offset) const { return BytePtr(*this) -= offset; }

    BytePtr operator++(int) { return BytePtr(*this) + 1; }
    BytePtr& operator++() { return Advance(1); }

    BytePtr operator--(int) { return BytePtr(*this) - 1; }
    BytePtr& operator--() { return Advance(-1); }

private:
    void* m_Ptr;
};

class ConstBytePtr {
public:
    explicit ConstBytePtr(const void* ptr) : m_Ptr(ptr) {}
    explicit ConstBytePtr(const BytePtr& bytePtr) : m_Ptr(bytePtr.Get()) {}
    ConstBytePtr(const void* ptr, ptrdiff_t offset) : ConstBytePtr(ptr) { Advance(offset); }

    void Reset(const void* ptr) { m_Ptr = ptr; }

    const void* Get() const { return m_Ptr; }

    template <typename T>
    const T* Get() const {
        return static_cast<const T*>(Get());
    }

    ConstBytePtr& Advance(ptrdiff_t offset) {
        m_Ptr = Get<char>() + offset;
        return *this;
    }

    ptrdiff_t Distance(const void* other) const {
        return static_cast<const char*>(other) - Get<char>();
    }

    bool IsAligned(size_t alignment) const {
        return is_aligned(reinterpret_cast<uintptr_t>(m_Ptr), alignment);
    }

    ConstBytePtr& AlignUp(size_t alignment) {
        uintptr_t& ptr = reinterpret_cast<uintptr_t&>(m_Ptr);
        ptr = align_up(ptr, alignment);
        return *this;
    }

    ConstBytePtr& AlignDown(size_t alignment) {
        uintptr_t& ptr = reinterpret_cast<uintptr_t&>(m_Ptr);
        ptr = align_down(ptr, alignment);
        return *this;
    }

    ConstBytePtr& operator+=(ptrdiff_t offset) { return Advance(offset); }
    ConstBytePtr& operator-=(ptrdiff_t offset) { return Advance(-offset); }

    ConstBytePtr operator+(ptrdiff_t offset) const { return ConstBytePtr(*this) += offset; }
    ConstBytePtr operator-(ptrdiff_t offset) const { return ConstBytePtr(*this) -= offset; }

    ConstBytePtr operator++(int) { return ConstBytePtr(*this) + 1; }
    ConstBytePtr& operator++() { return Advance(1); }

    ConstBytePtr operator--(int) { return ConstBytePtr(*this) - 1; }
    ConstBytePtr& operator--() { return Advance(-1); }

private:
    const void* m_Ptr;
};

}  // namespace nn::util
