#pragma once

#include <cstdint>

namespace nn::err {
class ErrorCode {
public:
    static ErrorCode GetInvalidErrorCode();

    ErrorCode() {}
    ErrorCode(std::uint32_t category, std::uint32_t number)
        : m_Category(category), m_Number(number) {}

    bool IsValid() const;

    std::uint32_t GetCategory() const { return m_Category; }
    std::uint32_t GetNumber() const { return m_Number; }

private:
    std::uint32_t m_Category = 0;
    std::uint32_t m_Number = 0;
};
}  // namespace nn::err
