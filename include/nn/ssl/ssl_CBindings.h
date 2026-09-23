#pragma once

#include <nn/nn_Result.h>
#include <nn/ssl/ssl_Connection.h>
#include <nn/ssl/ssl_Context.h>

extern "C" {
nn::Result nnsslInitialize(void);
nn::Result nnsslInitializeWithConcurrencyLimit(uint32_t limit);
nn::Result nnsslFinialize(void);
nn::Result nnsslContextCreate(nn::ssl::Context* context, nn::ssl::Context::SslVersion version);
nn::Result nnsslContextDestroy(nn::ssl::Context* context);
nn::Result nnsslContextGetContextId(nn::ssl::Context* context, uint64_t* outId);
nn::Result nnsslConnectionCreate(nn::ssl::Connection* connection, nn::ssl::Context* context);
nn::Result nnsslConnectionDestroy(nn::ssl::Connection* connection);
nn::Result nnsslConnectionSetSocketDescriptor(nn::ssl::Connection* connection,
                                              int32_t socketDescriptor);
nn::Result nnsslConnectionSetHostName(nn::ssl::Connection* connection, const char* hostName,
                                      uint32_t hostNameSize);
nn::Result nnsslConnectionSetVerifyOption(nn::ssl::Connection* connection,
                                          nn::ssl::Connection::VerifyOption verifyOption);
nn::Result nnsslConnectionSetServerCertBuffer(nn::ssl::Connection* connection,
                                              const char* serverCertificateBuffer,
                                              uint32_t serverCertificateBufferSize);
nn::Result nnsslConnectionSetIoMode(nn::ssl::Connection* connection,
                                    nn::ssl::Connection::IoMode ioMode);
nn::Result
nnsslConnectionSetSessionCacheMode(nn::ssl::Connection* connection,
                                   nn::ssl::Connection::SessionCacheMode sessionCacheMode);
nn::Result nnsslConnectionGetSocketDescriptor(nn::ssl::Connection* connection,
                                              int32_t* outSocketDescriptor);
nn::Result nnsslConnectionGetHostName(nn::ssl::Connection* connection, const char* outHostName,
                                      uint32_t* outHostNameSize, uint32_t maxHostNameSize);
nn::Result nnsslConnectionGetVerifyOption(nn::ssl::Connection* connection,
                                          nn::ssl::Connection::VerifyOption* outVerifyOption);
nn::Result nnsslConnectionGetIoMode(nn::ssl::Connection* connection,
                                    nn::ssl::Connection::IoMode* outIoMode);
nn::Result nnsslConnectionDoHandshake(nn::ssl::Connection* connection);
nn::Result nnsslConnectionDoHandshakeWithCertBuffer(nn::ssl::Connection* connection,
                                                    uint32_t* outServerCertificateBufferSize,
                                                    uint32_t* outNumCertificates);
nn::Result nnsslConnectionDoHandshakeWithBuffer(nn::ssl::Connection* connection,
                                                uint32_t* outServerCertificateBufferSize,
                                                uint32_t* outNumCertificates,
                                                char* outServerCertificateBuffer,
                                                uint32_t serverCertificateBufferMaxSize);
nn::Result nnsslConnectionGetServerCertDetail(nn::ssl::Connection* connection,
                                              nn::ssl::Connection::ServerCertDetail*, const char*,
                                              uint32_t);
nn::Result nnsslConnectionRead(nn::ssl::Connection* connection, char* outBuffer,
                               int32_t* outBufferSize, uint32_t maxBufferSize);
nn::Result nnsslConnectionWrite(nn::ssl::Connection* connection, const char* buffer,
                                int32_t* outWrittenBufferSize, uint32_t maxBufferSize);
nn::Result nnsslConnectionPending(nn::ssl::Connection* connection, int32_t*);
nn::Result nnsslConnectionPeek(nn::ssl::Connection* connection, char* outBuffer,
                               int32_t* outBufferSize, uint32_t maxBufferSize);
nn::Result nnsslConnectionPoll(nn::ssl::Connection* connection, nn::ssl::Connection::PollEvent*,
                               nn::ssl::Connection::PollEvent*, uint32_t timeout);
nn::Result nnsslConnectionGetVerifyCertError(nn::ssl::Connection* connection,
                                             nn::Result* outErrorResult);
nn::Result nnsslConnectionGetContextId(nn::ssl::Connection* connection, uint64_t* outContextId);
nn::Result nnsslConnectionGetConnectionId(nn::ssl::Connection* connection,
                                          uint64_t* outConnectionId);
nn::Result nnsslConnectionSetOption(nn::ssl::Connection* connection,
                                    nn::ssl::Connection::OptionType option, bool value);
nn::Result nnsslConnectionGetOption(nn::ssl::Connection* connection, bool* outValue,
                                    nn::ssl::Connection::OptionType option);
}
