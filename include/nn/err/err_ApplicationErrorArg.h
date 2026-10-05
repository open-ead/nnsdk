#pragma once

#include <nn/settings.h>

namespace nn::err {
class ApplicationErrorArg {
public:
    ApplicationErrorArg();
    ApplicationErrorArg(std::uint32_t errorCode, const char* dialogMessage,
                        const char* fullScreenMessage, const settings::LanguageCode& languageCode);

    std::uint32_t GetApplicationErrorCodeNumber() const;
    const char* GetDialogMessage() const;
    const char* GetFullScreenMessage() const;
    settings::LanguageCode GetLanguageCode() const;

    void SetApplicationErrorCodeNumber(std::uint32_t errorCode);
    void SetDialogMessage(const char* message);
    void SetFullScreenMessage(const char* message);
    void SetLanguageCode(const settings::LanguageCode& languageCode);

private:
    std::int8_t _0 = 2;
    std::int8_t _1 = 1;
    std::int8_t padding[6];
    std::uint32_t m_ErrorCode = 0;
    settings::LanguageCode m_LanguageCode;
    char m_DialogMessage[2048];
    char m_FullScreenMessage[2048];
};
}  // namespace nn::err
