/**
 * @brief SSL implementation.
 */
#pragma once

#include <nn/nn_Result.h>
#include <nn/ssl/ssl_BuiltInManager.h>
#include <nn/ssl/ssl_CBindings.h>
#include <nn/ssl/ssl_Connection.h>
#include <nn/ssl/ssl_Context.h>
#include <nn/ssl/ssl_Debug.h>
#include <nn/ssl/ssl_ISslConnection.h>
#include <nn/ssl/ssl_ISslContext.h>
#include <nn/ssl/ssl_ISslService.h>
#include <nn/ssl/ssl_Types.h>

namespace nn::ssl {

Result Initialize();
Result Initialize(uint32_t concurrencyLimit);
Result Finalize();
Result GetSslResultFromValue(Result*, const char*, uint32_t);

}  // namespace nn::ssl
