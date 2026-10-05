#pragma once

#include <cstdint>

namespace nn::err {
class ErrorMessageDatabaseVersion {
public:
private:
    std::int32_t m_Version;
};

static_assert(sizeof(ErrorMessageDatabaseVersion) == 4);
}  // namespace nn::err
