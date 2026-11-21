#pragma once

#include <nn/nn_Result.h>

namespace nn::err {
class ResultBacktrace {
public:
    static void Make(ResultBacktrace* outBackTrace, const Result*, std::int32_t);

private:
    // TODO
};
}  // namespace nn::err
