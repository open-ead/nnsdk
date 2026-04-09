#pragma once

namespace nn::applet {

enum class ExitReason { Normal = 0, Canceled = 1, Abnormal = 2, Unexpected = 10 };

typedef int LibraryAppletHandle;

struct AppletResourceUserId;

extern nn::applet::ExitReason g_ExitReason;

#if NN_SDK_VER < NN_MAKE_VER(4, 0, 0)
nn::applet::ExitReason GetExitReason();
#endif

}
