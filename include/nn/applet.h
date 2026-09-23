#pragma once

namespace nn::applet {

enum class ExitReason { Normal = 0, Canceled = 1, Abnormal = 2, Unexpected = 10 };

struct AppletResourceUserId;

extern nn::applet::ExitReason g_ExitReason;
nn::applet::ExitReason GetExitReason();

}  // namespace nn::applet
