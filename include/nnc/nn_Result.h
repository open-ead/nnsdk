#pragma once

#include <nnc/result/result_ResultBase.h>
#include <stdbool.h>

typedef struct nnResult {
    nnResultInnerType _value;
} nnResult;

#ifdef __cplusplus
extern "C" {
#endif

bool nnResultIsFailure(nnResult result);
bool nnResultIsSuccess(nnResult result);
uint32_t nnResultGetModule(nnResult result);
uint32_t nnResultGetDescription(nnResult result);

#ifdef __cplusplus
}
#endif

static bool isResultDifferent(nnResult a, nnResult b) {
    return nnResultGetModule(a) != nnResultGetModule(b) ||
           nnResultGetDescription(a) != nnResultGetDescription(b);
}

static bool isResultEqual(nnResult a, nnResult b) {
    return nnResultGetModule(a) == nnResultGetModule(b) &&
           nnResultGetDescription(a) == nnResultGetDescription(b);
}
