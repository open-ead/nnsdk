#pragma once

#include <nn/err/err_ErrorCode.h>
#include <nn/settings.h>

namespace nn::err {
class SystemErrorArg {
public:
    SystemErrorArg();
    SystemErrorArg(ErrorCode errorCode, const char* dialogMessage, const char* fullScreenMessage,
                   const settings::LanguageCode& languageCode);

    void SetErrorCode(ErrorCode errorCode);
    void SetDialogMessage(const char* message);
    void SetFullScreenMessage(const char* message);
    void SetLanguageCode(const settings::LanguageCode& languageCode);
    ErrorCode GetErrorCode() const;
    const char* GetDialogMessage() const;
    const char* GetFullScreenMessage() const;
    settings::LanguageCode GetLanguageCode() const;
    void GetStartupParam() const;

private:
    std::int8_t _0 = 1;
    std::int8_t _1 = 0;
    std::int8_t _2 = 0;
    std::int8_t _3 = 0;
    std::int8_t _4 = 0;
    std::int8_t _5 = 0;
    std::int8_t _6 = 0;
    std::int8_t _7 = 0;
    ErrorCode m_ErrorCode;
    settings::LanguageCode m_LanguageCode;
    char m_DialogMessage[2048];
    char m_FullScreenMessage[2048];
};
}  // namespace nn::err
