#pragma once

#include <cstddef>
#include <nn/util/detail/util_TypeTraits.h>

namespace nn::util {

template <typename T>
T align_up(T x, size_t align) {
    typedef typename detail::MakeUnsigned<T>::Type UIntType;
    UIntType mask = align - 1;
    return (x + mask) & ~mask;
}

template <typename T>
T align_down(T x, size_t align) {
    typedef typename detail::MakeUnsigned<T>::Type UIntType;
    UIntType mask = align - 1;
    return x & ~mask;
}

template <typename T>
bool is_aligned(T x, size_t align) {
    typedef typename detail::MakeUnsigned<T>::Type UIntType;
    UIntType mask = align - 1;
    return (x & mask) == 0;
}

template <typename T>
T isols1b(T x) {
    return x & (~x + 1);
}

template <typename T>
int32_t popcount(T x) {
    typedef typename detail::MakeUnsigned<T>::Type UIntType;
    UIntType u = x;

    const UIntType m1 = T(-1) / 3;
    const UIntType m2 = T(-1) / 5;
    const UIntType m4 = T(-1) / 17;

    u -= (u >> 1) & m1;
    u = (u & m2) + ((u >> 2) & m2);
    u = (u + (u >> 4) & m4);

    for (int32_t i = 1; i < sizeof(T) - 1; ++i) {
        const int32_t shift = 8;
        u += u >> (shift * i);
    }

    return u & 0x3f;
}

}  // namespace nn::util
