#pragma once

#include <nn/err/err_ErrorCode.h>
#include <nn/nn_Result.h>

namespace nn::err {
class ErrorResultVariant {
public:
    enum class State : std::uint32_t {
        Undefined,
        Result,
        ErrorCode,
    };

    ErrorResultVariant();
    ErrorResultVariant(const Result& result);
    ErrorResultVariant(const ErrorCode& errorCode);

    State GetState() const;

    operator ErrorCode() const;
    operator Result() const;

    ErrorResultVariant& operator=(const Result& result);
    ErrorResultVariant& operator=(const ErrorCode& errorCode);

private:
    State m_State = State::Undefined;
    union {
        Result m_Result;
        ErrorCode m_ErrorCode;
    } m_Value;
};
}  // namespace nn::err
