cmake_minimum_required(VERSION 3.15)

set(NN_GFX_TARGET "NVN" CACHE STRING "Set nn::gfx build target")
set_property(CACHE NN_GFX_TARGET PROPERTY STRINGS "" "NVN")

set(NN_GFX_HEADERS
  include/nn/gfx/detail/gfx_DataContainer.h
  include/nn/gfx/detail/gfx_Fwd.h
  include/nn/gfx/detail/gfx_Misc.h
  include/nn/gfx/detail/gfx_RequiredMemory.h
  include/nn/gfx/detail/gfx_ResShaderImpl.h
  include/nn/gfx/detail/gfx_RootSignature-api.common.h
  include/nn/gfx/util/gfx_PrimitiveShape.h

  include/nn/gfx/gfx_Buffer.h
  include/nn/gfx/gfx_BufferInfo.h
  include/nn/gfx/gfx_BufferInfoData.h
  include/nn/gfx/gfx_CommandBuffer.h
  include/nn/gfx/gfx_CommandBufferInfo.h
  include/nn/gfx/gfx_CommandBufferInfoData.h
  include/nn/gfx/gfx_Common.h
  include/nn/gfx/gfx_DescriptorPool.h
  include/nn/gfx/gfx_DescriptorPoolInfo.h
  include/nn/gfx/gfx_DescriptorPoolInfoData.h
  include/nn/gfx/gfx_DescriptorSlot.h
  include/nn/gfx/gfx_Device.h
  include/nn/gfx/gfx_DeviceInfo.h
  include/nn/gfx/gfx_DeviceInfoData.h
  include/nn/gfx/gfx_Enum.h
  include/nn/gfx/gfx_GpuAddress.h
  include/nn/gfx/gfx_MemoryPool.h
  include/nn/gfx/gfx_MemoryPoolInfo.h
  include/nn/gfx/gfx_MemoryPoolInfoData.h
  include/nn/gfx/gfx_Queue.h
  include/nn/gfx/gfx_QueueInfo.h
  include/nn/gfx/gfx_QueueInfoData.h
  include/nn/gfx/gfx_ResShader.h
  include/nn/gfx/gfx_ResShaderData.h
  include/nn/gfx/gfx_ResTexture.h
  include/nn/gfx/gfx_ResTextureData.h
  include/nn/gfx/gfx_ResUserData.h
  include/nn/gfx/gfx_ResUserDataData.h
  include/nn/gfx/gfx_RootSignatureData-api.common.h
  include/nn/gfx/gfx_RootSignatureInfo.h
  include/nn/gfx/gfx_RootSignatureInfoData.h
  include/nn/gfx/gfx_Sampler.h
  include/nn/gfx/gfx_SamplerInfo.h
  include/nn/gfx/gfx_SamplerInfoData.h
  include/nn/gfx/gfx_Shader.h
  include/nn/gfx/gfx_ShaderInfo.h
  include/nn/gfx/gfx_ShaderInfoData.h
  include/nn/gfx/gfx_State.h
  include/nn/gfx/gfx_StateInfo.h
  include/nn/gfx/gfx_StateInfoData.h
  include/nn/gfx/gfx_SwapChain.h
  include/nn/gfx/gfx_SwapChainInfo.h
  include/nn/gfx/gfx_SwapChainInfoData.h
  include/nn/gfx/gfx_Sync.h
  include/nn/gfx/gfx_SyncInfo.h
  include/nn/gfx/gfx_SyncInfoData.h
  include/nn/gfx/gfx_Texture.h
  include/nn/gfx/gfx_TextureInfo.h
  include/nn/gfx/gfx_TextureInfoData.h
  include/nn/gfx/gfx_Types.h
  include/nn/gfx/gfx_VariationBase.h
)

set(NN_GFX_SOURCES
  src/gfx/detail/gfx_CommonHelper.cpp
  src/gfx/detail/gfx_CommonHelper.h
  src/gfx/util/gfx_PrimitiveShape.cpp

  src/gfx/gfx_BufferInfo.cpp
  src/gfx/gfx_CommandBufferInfo.cpp
  src/gfx/gfx_DescriptorPoolInfo.cpp
  src/gfx/gfx_DeviceInfo.cpp
  src/gfx/gfx_MemoryPoolInfo.cpp
  src/gfx/gfx_QueueInfo.cpp
  src/gfx/gfx_ResShader.cpp
  src/gfx/gfx_ResTexture.cpp
  src/gfx/gfx_SamplerInfo.cpp
  src/gfx/gfx_ShaderInfo.cpp
  src/gfx/gfx_StateInfo.cpp
  src/gfx/gfx_SwapChainInfo.cpp
  src/gfx/gfx_SyncInfo.cpp
  src/gfx/gfx_TextureInfo.cpp
)

if(NN_GFX_TARGET STREQUAL "NVN")
  list(APPEND NN_GFX_HEADERS
    include/nn/gfx/detail/gfx_Buffer-api.nvn.8.h
    include/nn/gfx/detail/gfx_CommandBuffer-api.nvn.8.h
    include/nn/gfx/detail/gfx_Common-api.nvn.h
    include/nn/gfx/detail/gfx_DescriptorPool-api.nvn.8.h
    include/nn/gfx/detail/gfx_Device-api.nvn.8.h
    include/nn/gfx/detail/gfx_MemoryPool-api.nvn.8.h
    include/nn/gfx/detail/gfx_Pipeline-api.nvn.8.h
    include/nn/gfx/detail/gfx_Queue-api.nvn.8.h
    include/nn/gfx/detail/gfx_RootSignature-api.nvn.8.h
    include/nn/gfx/detail/gfx_Sampler-api.nvn.8.h
    include/nn/gfx/detail/gfx_Shader-api.nvn.8.h
    include/nn/gfx/detail/gfx_State-api.nvn.8.h
    include/nn/gfx/detail/gfx_SwapChain-api.nvn.8.h
    include/nn/gfx/detail/gfx_Sync-api.nvn.8.h
    include/nn/gfx/detail/gfx_Texture-api.nvn.8.h
    include/nn/gfx/gfx_BufferData-api.nvn.8.h
    include/nn/gfx/gfx_CommandBufferData-api.nvn.8.h
    include/nn/gfx/gfx_DescriptorPoolData-api.nvn.8.h
    include/nn/gfx/gfx_DeviceData-api.nvn.8.h
    include/nn/gfx/gfx_Interoperation-api.nvn.8.h
    include/nn/gfx/gfx_MemoryPoolData-api.nvn.8.h
    include/nn/gfx/gfx_PipelineData-api.nvn.8.h
    include/nn/gfx/gfx_QueueData-api.nvn.8.h
    include/nn/gfx/gfx_ResShaderData-api.nvn.h
    include/nn/gfx/gfx_SamplerData-api.nvn.8.h
    include/nn/gfx/gfx_ShaderData-api.nvn.8.h
    include/nn/gfx/gfx_StateData-api.nvn.8.h
    include/nn/gfx/gfx_SwapChainData-api.nvn.8.h
    include/nn/gfx/gfx_SyncData-api.nvn.8.h
    include/nn/gfx/gfx_TextureData-api.nvn.8.h
  )
  list(APPEND NN_GFX_SOURCES
    src/gfx/detail/gfx_Buffer-api.nvn.8.cpp
    src/gfx/detail/gfx_CommandBuffer-api.nvn.8.cpp
    src/gfx/detail/gfx_DescriptorPool-api.nvn.8.cpp
    src/gfx/detail/gfx_Device-api.nvn.8-os.horizon.cpp
    src/gfx/detail/gfx_GlslcFunction.cpp
    src/gfx/detail/gfx_MemoryPool-api.nvn.8.cpp
    src/gfx/detail/gfx_NvnHelper-os.horizon.cpp
    src/gfx/detail/gfx_NvnHelper.cpp
    src/gfx/detail/gfx_NvnHelper.h
    src/gfx/detail/gfx_ResShader-api.nvn.8.cpp
    src/gfx/detail/gfx_Sampler-api.nvn.8.cpp
    src/gfx/detail/gfx_Shader-api.nvn.8.cpp
    src/gfx/detail/gfx_State-api.nvn.8.cpp
    src/gfx/detail/gfx_Texture-api.nvn.8.cpp

    src/gfx/util/gfx_ObjectDebugLabel-api.nvn.8.cpp
    src/gfx/gfx_Interoperation-api.nvn.cpp
  )
endif()

add_library(nn_gfx OBJECT ${NN_GFX_SOURCES})

target_sources(nn_gfx PUBLIC
  FILE_SET HEADERS
  BASE_DIRS include/
  FILES ${NN_GFX_HEADERS}
)

set_target_properties(nn_gfx PROPERTIES
    LINKER_LANGUAGE CXX
    VERIFY_INTERFACE_HEADER_SETS ON
)

target_include_directories(nn_gfx PUBLIC include/)

target_link_libraries(nn_gfx PUBLIC nvn nnSdk)
