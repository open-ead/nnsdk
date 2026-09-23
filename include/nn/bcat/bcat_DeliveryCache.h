#pragma once

#include <nn/bcat/bcat_DeliveryCacheProgress.h>
#include <nn/bcat/bcat_Util.h>
#include <nn/nn_Result.h>

namespace nn::bcat {

Result MountDeliveryCacheStorage();
Result UnmountDeliveryCacheStorage();
Result EnumerateDeliveryCacheDirectory(int*, DirectoryName*, int);
Result RequestSyncDeliveryCache(DeliveryCacheProgress*);

}  // namespace nn::bcat
