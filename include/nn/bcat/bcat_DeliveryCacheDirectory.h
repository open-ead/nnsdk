#pragma once

#include <nn/bcat/bcat_Util.h>
#include <nn/nn_Result.h>

namespace nn::bcat {

class DeliveryCacheDirectory {
public:
    DeliveryCacheDirectory();
    ~DeliveryCacheDirectory();
    Result Open(DirectoryName const&);
    Result GetCount();
    Result Close();
};

}  // namespace nn::bcat
