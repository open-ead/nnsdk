#pragma once

#include <nn/err.h>
#include <nn/err/detail/err_MessageKind.h>
#include <nn/err/err_ErrorCode.h>
#include <nn/settings.h>

namespace nn::ns {
// TODO: move
class ApplicationErrorCodeCategory {
public:
    const char* GetCategory() const { return m_Category; }

private:
    char m_Category[8];
};
}  // namespace nn::ns

namespace nn::err {
class ErrorMessageDatabaseVersion;
}  // namespace nn::err

namespace nn::err::detail {
bool CategoryExists(std::uint32_t category);
bool DefaultErrorMessageDataExists(std::uint32_t category);
bool ErrorMessageDataExists(ErrorCode errorCode);
bool IsApplicationErrorCodeString(const char* errorCodeString);
void MakeApplicationErrorCodeString(
    char* outErrorCodeString, std::size_t errorCodeStringBufferSize,
    const ns::ApplicationErrorCodeCategory& applicationErrorCodeCategory,
    std::uint32_t errorCodeNumber);
void MakeErrorCodeString(char* outErrorCodeString, std::size_t errorCodeStringBufferSize,
                         ErrorCode errorCode);
void MakeErrorInfoCommonFilePath(char* outErrorInfoCommonFilePath,
                                 std::size_t errorInfoCommonFilePathBufferSize,
                                 ErrorCode errorCode);
void MakeErrorInfoDirectoryPath(char* outErrorInfoDirectoryPath,
                                std::size_t errorInfoDirectoryPathBufferSize, ErrorCode errorCode);
void MakeErrorInfoMessageFilePath(char* outErrorInfoMessageFilePath,
                                  std::size_t errorInfoMessageFilePathBufferSize,
                                  ErrorCode errorCode, settings::LanguageCode languageCode,
                                  MessageKind messageKind);
void MakeErrorInfoModuleDirectoryPath(char* outErrorInfoModuleDirectoryPath,
                                      std::size_t errorInfoModuleDirectoryPathBufferSize,
                                      std::uint32_t errorCodeCategory);
void ParseApplicationErrorCodeString(
    ns::ApplicationErrorCodeCategory* outApplicationErrorCodeCategory,
    std::uint32_t* outErrorCodeCategoryNumber, const char* errorCodeString);
void ParseErrorCodeString(ErrorCode* outErrorCode, const char* errorCodeString);
void* ReadMessageFile(char16_t* outBuffer, std::int32_t* outMessageLength,
                      std::size_t messageBufferSize, ErrorCode errorCode,
                      settings::LanguageCode languageCode, MessageKind messageKind);
void ReadMessageFile(char16_t* outBuffer, std::size_t bufferSize, const char* errorCodeString,
                     const settings::LanguageCode& languageCode);
void ReadVersion(ErrorMessageDatabaseVersion* outVersion);
bool TryParseApplicationErrorCodeString(
    ns::ApplicationErrorCodeCategory* outApplicationErrorCodeCategory,
    std::uint32_t* outErrorCodeCategoryNumber, const char* errorCodeString);
bool TryParseErrorCodeString(ErrorCode* outErrorCode, const char* errorCodeString);
}  // namespace nn::err::detail
