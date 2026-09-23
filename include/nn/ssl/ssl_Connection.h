#pragma once

#include <nn/ssl/ssl_Context.h>

namespace nn::ssl {

class Connection {
public:
    enum class VerifyOption {
        PeerCa = 1 << 0,
        HostName = 1 << 1,
        DateCheck = 1 << 2,
        EvCertPartial = 1 << 3,
        EvPolicyOid = 1 << 4,        // [6.0.0+]
        EvCertFingerprint = 1 << 5,  // [6.0.0+]
    };

    enum class IoMode { Blocking = 1, NonBlocking = 2 };

    enum class SessionCacheMode { None, SessionId, SessionTicket };

    enum class RenegotiationMode { None, Secure };

    enum class PollEvent { Read = 1 << 0, Write = 1 << 1, Except = 1 << 2 };

    enum class OptionType {
        DoNotCloseSocket,
        GetServerCertChain,  // [3.0.0+]
        SkipDefaultVerify,   // [5.0.0+]
        EnableAlpn,          // [9.0.0+]
    };

    // TODO
    struct ServerCertDetail;

    Connection();
    ~Connection();

    Result Create(Context* context);
    Result Destroy();
    Result SetSocketDescriptor(int32_t socketDescriptor);
    Result SetHostName(const char* hostName, uint32_t hostNameSize);
    Result SetVerifyOption(VerifyOption verifyOption);
    Result SetServerCertBuffer(const char* serverCertificateBuffer,
                               uint32_t serverCertificateBufferSize);
    Result SetIoMode(IoMode ioMode);
    Result SetSessionCacheMode(SessionCacheMode sessionCacheMode);
    Result SetRenegotiationMode(RenegotiationMode renegotiationMode);
    Result GetSocketDescriptor(int32_t* outSocketDescriptor);
    Result GetHostName(const char* outHostName, uint32_t* outHostNameSize,
                       uint32_t maxHostNameSize);
    Result GetVerifyOption(VerifyOption* outVerifyOption);
    Result GetIoMode(IoMode* outIoMode);
    Result GetSessionCacheMode(SessionCacheMode* outSessionCacheMode);
    Result GetRenegotiationMode(RenegotiationMode* outRenegotiationMode);
    Result FlushSessionCache();
    Result DoHandshake();
    Result DoHandshake(uint32_t* outServerCertificateBufferSize, uint32_t* outNumCertificates);
    Result DoHandshake(uint32_t* outServerCertificateBufferSize, uint32_t* outNumCertificates,
                       char* outServerCertificateBuffer, uint32_t serverCertificateBufferMaxSize);
    Result GetServerCertDetail(ServerCertDetail*, const char*, uint32_t);
    Result Read(char* outBuffer, uint32_t maxBufferSize);
    Result Read(char* outBuffer, int32_t* outBufferSize, uint32_t maxBufferSize);
    Result Write(const char* buffer, uint32_t maxBufferSize);
    Result Write(const char* buffer, int32_t* outWrittenBufferSize, uint32_t maxBufferSize);
    Result Pending();
    Result Pending(int32_t*);
    Result Peek(char* outBuffer, int32_t* outBufferSize, uint32_t maxBufferSize);
    Result Poll(PollEvent*, PollEvent*, uint32_t timeout);
    Result GetLastError(Result* outErrorResult);
    Result GetVerifyCertError(Result* outErrorResult);
    Result GetVerifyCertErrors(Result* outErrorResults, uint32_t*, uint32_t*,
                               uint32_t maxErrorResultCount);
    Result GetNeededServerCertBufferSize(uint32_t* outNeededServerCertBufferSize);
    Result GetContextId(uint64_t* outContextId);
    Result GetConnectionId(uint64_t* outConnectionId);
    Result SetOption(OptionType option, bool value);
    Result GetOption(bool* outValue, OptionType option);

private:
    uint64_t mConnectionId;
    uint64_t mContextId;
    unsigned char _10[8];
    const char* mServerCertificateBuffer;
    uint32_t mServerCertificateBufferSize;
    Result _24;
};
}  // namespace nn::ssl
