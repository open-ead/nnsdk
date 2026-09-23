/**
 * @file time.h
 * @brief Time implementation.
 */

#pragma once

#include <nn/types.h>

namespace nn {
class TimeSpan {
public:
    uint64_t nanoseconds;

    static TimeSpan FromNanoSeconds(uint64_t nanoSeconds) {
        TimeSpan ret;
        ret.nanoseconds = nanoSeconds;
        return ret;
    }
    static TimeSpan FromMilliSeconds(uint64_t milliseconds) {
        return FromNanoSeconds(milliseconds * 1000 * 1000);
    }
    static TimeSpan FromSeconds(uint64_t seconds) {
        return FromNanoSeconds(seconds * 1000 * 1000 * 1000);
    }
    static TimeSpan FromMinutes(uint64_t minutes) {
        return FromNanoSeconds(minutes * 1000 * 1000 * 1000 * 60);
    }
    static TimeSpan FromHours(uint64_t hours) {
        return FromNanoSeconds(hours * 1000 * 1000 * 1000 * 60 * 60);
    }
    static TimeSpan FromDays(uint64_t days) {
        return FromNanoSeconds(days * 1000 * 1000 * 1000 * 60 * 60 * 24);
    }
};

namespace time {

Result Initialize();
bool IsInitialized();

struct CalendarTime {
    int16_t year;
    int8_t month;
    int8_t day;
    int8_t hour;
    int8_t minute;
    int8_t second;
};

enum DayOfTheWeek { Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday };

struct TimeZone {
    char standardTimeName[0x8];
    bool _9;        // daylight savings or something?
    int32_t utcOffset;  // in seconds
};

struct CalendarAdditionalInfo {
    nn::time::DayOfTheWeek dayOfTheWeek;
    int32_t dayofYear;
    nn::time::TimeZone timeZone;
};

struct PosixTime {
    uint64_t time;
};

class StandardUserSystemClock {
public:
    static Result GetCurrentTime(nn::time::PosixTime*);
};

struct TimeZoneRule;  // shrug

Result ToCalendarTime(nn::time::CalendarTime*, nn::time::CalendarAdditionalInfo*,
                      nn::time::PosixTime const&);
Result ToCalendarTime(nn::time::CalendarTime*, nn::time::CalendarAdditionalInfo*,
                      nn::time::PosixTime const&, nn::time::TimeZoneRule const&);
Result ToPosixTime(int*, PosixTime*, int, const CalendarTime&);
CalendarTime ToCalendarTimeInUtc(const PosixTime&);
PosixTime ToPosixTimeFromUtc(const CalendarTime&);
}  // namespace time
}  // namespace nn
