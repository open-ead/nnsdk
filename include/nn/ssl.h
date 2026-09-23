/**
 * @brief SSL implementation.
 */

#pragma once

#include <nn/nn_Result.h>

namespace nn::ssl {

enum CertificateFormat { PEM = 0x01, DER = 0x02 };

class Context {
public:
    enum SslVersion { Auto = 0x01, v10 = 0x08, v11 = 0x10, v12 = 0x20 };

    Result Create(nn::ssl::Context::SslVersion version);
    Result ImportServerPki(uint64_t*, char const* certData, uint32_t certSize,
                           nn::ssl::CertificateFormat certFormat);
};

Result Initialize();
Result Finalize();

}  // namespace nn::ssl
