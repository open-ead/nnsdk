#pragma once

#include <nn/nn_Result.h>
#include <nn/ssl/ssl_Types.h>

namespace nn::ssl {
// TODO: find the size of this struct
class Context {
public:
    enum class SslVersion {
        Auto = 0x01,
        v10 = 0x08,
        v11 = 0x10,
        v12 = 0x20,
        v13 = 0x40,          // [11.0.0+]
        Auto24 = 0x1000000,  // [11.0.0+]
    };

    enum class InternalPki { DeviceClientCertDefault = 1 };

    enum class ContextOption { CrlImportDateCheckEnable = 1 };

    Context();
    ~Context();

    Result Create(SslVersion version);
    Result Destroy();
    Result SetOption(ContextOption option, int32_t value);
    Result GetOption(int32_t* outValue, ContextOption option);
    Result GetContextId(uint64_t* outId);
    Result ImportServerPki(uint64_t* outId, const char* certificateBuffer,
                           uint32_t certificateBufferSize, CertificateFormat certificateFormat);
    Result ImportClientPki(uint64_t* outId, const char* certificateBuffer,
                           const char* certificatePassword, uint32_t certificateBufferSize,
                           uint32_t certificatePasswordSize);
    Result RemovePki(uint64_t id);
    Result RegisterInternalPki(uint64_t* outId, InternalPki pki);
    Result AddPolicyOid(const char* policyOidBuffer, uint32_t policyOidBufferSize);
    Result ImportCrl(uint64_t* outId, const char* certificateRevocationListBuffer,
                     uint32_t certificateRevocationListBufferSize);

private:
    uint64_t mContextId;
};

// TODO: I'm pretty sure there is inheritance between ContextPrivate and Context
class ContextPrivate {
public:
    enum class SslVersion {
        // TODO
    };

    Result Create(SslVersion version);

private:
    Context context;
};
}  // namespace nn::ssl
