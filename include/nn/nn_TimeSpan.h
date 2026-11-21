#pragma once

#include <cstdint>

namespace nn {

struct TimeSpanType {
public:
    static TimeSpanType FromNanoSeconds(int64_t nanoSeconds) {
        TimeSpanType ret;
        ret._nanoSeconds = nanoSeconds;
        return ret;
    }

    static TimeSpanType FromMicroSeconds(int64_t microSeconds) {
        return FromNanoSeconds(microSeconds * 1000);
    }

    static TimeSpanType FromMilliSeconds(int64_t milliSeconds) {
        return FromMicroSeconds(milliSeconds * 1000);
    }

    static TimeSpanType FromSeconds(int64_t seconds) { return FromMilliSeconds(seconds * 1000); }

    static TimeSpanType FromMinutes(int64_t minutes) { return FromSeconds(minutes * 60); }

    static TimeSpanType FromHours(int64_t hours) { return FromMinutes(hours * 60); }

    static TimeSpanType FromDays(int64_t days) { return FromHours(days * 24); }

    int64_t GetDays() const { return DivideNanoSeconds(_nanoSeconds, 7512003556908026083, 45); }

    int64_t GetHours() const { return DivideNanoSeconds(_nanoSeconds, 11268005335362039125u, 41); }

    int64_t GetMinutes() const { return DivideNanoSeconds(_nanoSeconds, 82529335952358685, 28); }

    int64_t GetSeconds() const { return DivideNanoSeconds(_nanoSeconds, 1237940039285380275, 26); }

    int64_t GetMilliSeconds() const {
        return DivideNanoSeconds(_nanoSeconds, 4835703278458516699, 18);
    }

    int64_t GetMicroSeconds() const {
        return DivideNanoSeconds(_nanoSeconds, 2361183241434822607, 7);
    }

    int64_t GetNanoSeconds() const { return _nanoSeconds; }

    TimeSpanType& operator=(int64_t rhs) {
        _nanoSeconds = rhs;
        return *this;
    }

    operator int64_t() { return _nanoSeconds; }

    TimeSpanType& operator*=(const TimeSpanType& rhs) {
        _nanoSeconds *= rhs._nanoSeconds;
        return *this;
    }

    TimeSpanType operator*(const TimeSpanType& rhs) {
        TimeSpanType ret = *this;
        return ret *= rhs;
    }

    TimeSpanType& operator/=(const TimeSpanType& rhs) {
        _nanoSeconds /= rhs._nanoSeconds;
        return *this;
    }

    TimeSpanType operator/(const TimeSpanType& rhs) {
        TimeSpanType ret = *this;
        return ret /= rhs;
    }

    TimeSpanType& operator+=(const TimeSpanType& rhs) {
        _nanoSeconds += rhs._nanoSeconds;
        return *this;
    }

    TimeSpanType operator+(const TimeSpanType& rhs) {
        TimeSpanType ret = *this;
        return ret += rhs;
    }

    TimeSpanType& operator-=(const TimeSpanType& rhs) {
        _nanoSeconds -= rhs._nanoSeconds;
        return *this;
    }

    TimeSpanType operator-(const TimeSpanType& rhs) {
        TimeSpanType ret = *this;
        return ret -= rhs;
    }

    bool operator==(const TimeSpanType& rhs) { return _nanoSeconds == rhs._nanoSeconds; }

    bool operator!=(const TimeSpanType& rhs) { return !(*this == rhs); }

    bool operator<(const TimeSpanType& rhs) { return _nanoSeconds < rhs._nanoSeconds; }

    bool operator>(const TimeSpanType& rhs) { return _nanoSeconds > rhs._nanoSeconds; }

    bool operator<=(const TimeSpanType& rhs) { return !(*this > rhs); }

    bool operator>=(const TimeSpanType& rhs) { return !(*this < rhs); }

    int64_t _nanoSeconds;

private:
    static int64_t DivideNanoSeconds(const int64_t nanoSeconds, const int64_t magic,
                                     const int32_t rightShift) {
        int64_t n = MultiplyRightShift(nanoSeconds, magic);
        n >>= rightShift;
        n += static_cast<uint64_t>(nanoSeconds) >> 63;
        return n;
    }

    static int64_t MultiplyRightShift(const int64_t x, const int64_t y) {
        const uint64_t x_lo = static_cast<uint64_t>(x & 0xffffffff);
        const int64_t x_hi = x >> 32;

        const uint64_t y_lo = static_cast<uint64_t>(y & 0xffffffff);
        const int64_t y_hi = y >> 32;

        const int64_t z = static_cast<int64_t>(x_hi * y_lo + ((x_lo * y_lo) >> 32));
        const int64_t z_lo = z & 0xffffffff;
        const int64_t z_hi = z >> 32;

        return x_hi * y_hi + (static_cast<int64_t>(x_lo * y_hi + z_lo) >> 32) + z_hi;
    }
};

// @nncbindgen typedef int64_t
class TimeSpan {
public:
    class ZeroOnlyTag {};  // TODO
    using ZeroOnly = const ZeroOnlyTag*;

    TimeSpan(ZeroOnly);

    TimeSpan(const TimeSpanType& timeSpanType) : m_TimeSpan(timeSpanType) {}

    static TimeSpan FromNanoSeconds(int64_t nanoSeconds) {
        return TimeSpanType::FromNanoSeconds(nanoSeconds);
    }

    static TimeSpan FromMicroSeconds(int64_t microSeconds) {
        return TimeSpanType::FromMicroSeconds(microSeconds);
    }

    static TimeSpan FromMilliSeconds(int64_t milliSeconds) {
        return TimeSpanType::FromMilliSeconds(milliSeconds);
    }

    static TimeSpan FromSeconds(int64_t seconds) { return TimeSpanType::FromSeconds(seconds); }

    static TimeSpan FromMinutes(int64_t minutes) { return TimeSpanType::FromMinutes(minutes); }

    static TimeSpan FromHours(int64_t hours) { return TimeSpanType::FromHours(hours); }

    static TimeSpan FromDays(int64_t days) { return TimeSpanType::FromDays(days); }

    int64_t GetDays() const { return m_TimeSpan.GetDays(); }

    int64_t GetHours() const { return m_TimeSpan.GetHours(); }

    int64_t GetMinutes() const { return m_TimeSpan.GetMinutes(); }

    int64_t GetSeconds() const { return m_TimeSpan.GetSeconds(); }

    int64_t GetMilliSeconds() const { return m_TimeSpan.GetMilliSeconds(); }

    int64_t GetMicroSeconds() const { return m_TimeSpan.GetMicroSeconds(); }

    int64_t GetNanoSeconds() const { return m_TimeSpan.GetNanoSeconds(); }

    TimeSpan& operator=(int64_t rhs) {
        m_TimeSpan = rhs;
        return *this;
    }

    operator int64_t() { return m_TimeSpan; }

    TimeSpan& operator*=(const TimeSpan& rhs) {
        m_TimeSpan *= rhs.m_TimeSpan;
        return *this;
    }

    TimeSpan operator*(const TimeSpan& rhs) {
        TimeSpan ret = *this;
        return ret *= rhs;
    }

    TimeSpan& operator/=(const TimeSpan& rhs) {
        m_TimeSpan /= rhs.m_TimeSpan;
        return *this;
    }

    TimeSpan operator/(const TimeSpan& rhs) {
        TimeSpan ret = *this;
        return ret /= rhs;
    }

    TimeSpan& operator+=(const TimeSpan& rhs) {
        m_TimeSpan += rhs.m_TimeSpan;
        return *this;
    }

    TimeSpan operator+(const TimeSpan& rhs) {
        TimeSpan ret = *this;
        return ret += rhs;
    }

    TimeSpan& operator-=(const TimeSpan& rhs) {
        m_TimeSpan -= rhs.m_TimeSpan;
        return *this;
    }

    TimeSpan operator-(const TimeSpan& rhs) {
        TimeSpan ret = *this;
        return ret -= rhs;
    }

    bool operator==(const TimeSpan& rhs) { return m_TimeSpan == rhs.m_TimeSpan; }

    bool operator!=(const TimeSpan& rhs) { return !(*this == rhs); }

    bool operator<(const TimeSpan& rhs) { return m_TimeSpan < rhs.m_TimeSpan; }

    bool operator>(const TimeSpan& rhs) { return m_TimeSpan > rhs.m_TimeSpan; }

    bool operator<=(const TimeSpan& rhs) { return m_TimeSpan <= rhs.m_TimeSpan; }

    bool operator>=(const TimeSpan& rhs) { return m_TimeSpan >= rhs.m_TimeSpan; }

    operator TimeSpanType() const { return m_TimeSpan; }

private:
    TimeSpanType m_TimeSpan;
};

}  // namespace nn
