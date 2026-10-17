#pragma once

#include <cstdint>

namespace nn::err::detail {
// What does Flv stand for?
enum class MessageKind : std::uint8_t { DialogueMessage, DialogueButton, FlvMessage, FlvButton };
}  // namespace nn::err::detail
