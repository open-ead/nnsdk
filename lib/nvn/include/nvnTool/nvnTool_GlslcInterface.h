#pragma once

#include <nvn/nvn.h>

#define GLSLC_PTR(type, var)                                                                       \
    union {                                                                                        \
        type var;                                                                                  \
        uint64_t ptr##var;                                                                         \
    }

enum GLSLCpiqUniformKind {
    GLSLC_PIQ_UNIFORM_KIND_PLAIN = 0,
    GLSLC_PIQ_UNIFORM_KIND_SAMPLER = 1,
    GLSLC_PIQ_UNIFORM_KIND_IMAGE = 2,
    GLSLC_PIQ_UNIFORM_KIND_TEXTURE = 3,
    GLSLC_PIQ_UNIFORM_KIND_INVALID = -1,
};

enum GLSLCpiqTypeEnum {
    GLSLC_PIQ_TYPE_BOOL = 0,
    GLSLC_PIQ_TYPE_BVEC2 = 1,
    GLSLC_PIQ_TYPE_BVEC3 = 2,
    GLSLC_PIQ_TYPE_BVEC4 = 3,
    GLSLC_PIQ_TYPE_INT = 4,
    GLSLC_PIQ_TYPE_INT_VEC2 = 5,
    GLSLC_PIQ_TYPE_INT_VEC3 = 6,
    GLSLC_PIQ_TYPE_INT_VEC4 = 7,
    GLSLC_PIQ_TYPE_INT8 = 8,
    GLSLC_PIQ_TYPE_INT8_VEC2 = 9,
    GLSLC_PIQ_TYPE_INT8_VEC3 = 10,
    GLSLC_PIQ_TYPE_INT8_VEC4 = 11,
    GLSLC_PIQ_TYPE_INT16 = 12,
    GLSLC_PIQ_TYPE_INT16_VEC2 = 13,
    GLSLC_PIQ_TYPE_INT16_VEC3 = 14,
    GLSLC_PIQ_TYPE_INT16_VEC4 = 15,
    GLSLC_PIQ_TYPE_INT64 = 16,
    GLSLC_PIQ_TYPE_INT64_VEC2 = 17,
    GLSLC_PIQ_TYPE_INT64_VEC3 = 18,
    GLSLC_PIQ_TYPE_INT64_VEC4 = 19,
    GLSLC_PIQ_TYPE_UINT = 20,
    GLSLC_PIQ_TYPE_UINT_VEC2 = 21,
    GLSLC_PIQ_TYPE_UINT_VEC3 = 22,
    GLSLC_PIQ_TYPE_UINT_VEC4 = 23,
    GLSLC_PIQ_TYPE_UINT8 = 24,
    GLSLC_PIQ_TYPE_UINT8_VEC2 = 25,
    GLSLC_PIQ_TYPE_UINT8_VEC3 = 26,
    GLSLC_PIQ_TYPE_UINT8_VEC4 = 27,
    GLSLC_PIQ_TYPE_UINT16 = 28,
    GLSLC_PIQ_TYPE_UINT16_VEC2 = 29,
    GLSLC_PIQ_TYPE_UINT16_VEC3 = 30,
    GLSLC_PIQ_TYPE_UINT16_VEC4 = 31,
    GLSLC_PIQ_TYPE_UINT64 = 32,
    GLSLC_PIQ_TYPE_UINT64_VEC2 = 33,
    GLSLC_PIQ_TYPE_UINT64_VEC3 = 34,
    GLSLC_PIQ_TYPE_UINT64_VEC4 = 35,
    GLSLC_PIQ_TYPE_FLOAT = 36,
    GLSLC_PIQ_TYPE_FLOAT_VEC2 = 37,
    GLSLC_PIQ_TYPE_FLOAT_VEC3 = 38,
    GLSLC_PIQ_TYPE_FLOAT_VEC4 = 39,
    GLSLC_PIQ_TYPE_FLOAT16 = 40,
    GLSLC_PIQ_TYPE_FLOAT16_VEC2 = 41,
    GLSLC_PIQ_TYPE_FLOAT16_VEC3 = 42,
    GLSLC_PIQ_TYPE_FLOAT16_VEC4 = 43,
    GLSLC_PIQ_TYPE_DOUBLE = 44,
    GLSLC_PIQ_TYPE_DOUBLE_VEC2 = 45,
    GLSLC_PIQ_TYPE_DOUBLE_VEC3 = 46,
    GLSLC_PIQ_TYPE_DOUBLE_VEC4 = 47,
    GLSLC_PIQ_TYPE_MAT2 = 48,
    GLSLC_PIQ_TYPE_MAT3 = 49,
    GLSLC_PIQ_TYPE_MAT4 = 50,
    GLSLC_PIQ_TYPE_MAT2X3 = 51,
    GLSLC_PIQ_TYPE_MAT2X4 = 52,
    GLSLC_PIQ_TYPE_MAT3X2 = 53,
    GLSLC_PIQ_TYPE_MAT3X4 = 54,
    GLSLC_PIQ_TYPE_MAT4X2 = 55,
    GLSLC_PIQ_TYPE_MAT4X3 = 56,
    GLSLC_PIQ_TYPE_DMAT2 = 57,
    GLSLC_PIQ_TYPE_DMAT3 = 58,
    GLSLC_PIQ_TYPE_DMAT4 = 59,
    GLSLC_PIQ_TYPE_DMAT2X3 = 60,
    GLSLC_PIQ_TYPE_DMAT2X4 = 61,
    GLSLC_PIQ_TYPE_DMAT3X2 = 62,
    GLSLC_PIQ_TYPE_DMAT3X4 = 63,
    GLSLC_PIQ_TYPE_DMAT4X2 = 64,
    GLSLC_PIQ_TYPE_DMAT4X3 = 65,
    GLSLC_PIQ_TYPE_SAMPLER_1D = 66,
    GLSLC_PIQ_TYPE_SAMPLER_2D = 67,
    GLSLC_PIQ_TYPE_SAMPLER_3D = 68,
    GLSLC_PIQ_TYPE_SAMPLER_CUBE = 69,
    GLSLC_PIQ_TYPE_SAMPLER_1D_SHADOW = 70,
    GLSLC_PIQ_TYPE_SAMPLER_2D_SHADOW = 71,
    GLSLC_PIQ_TYPE_SAMPLER_1D_ARRAY = 72,
    GLSLC_PIQ_TYPE_SAMPLER_2D_ARRAY = 73,
    GLSLC_PIQ_TYPE_SAMPLER_1D_ARRAY_SHADOW = 74,
    GLSLC_PIQ_TYPE_SAMPLER_2D_ARRAY_SHADOW = 75,
    GLSLC_PIQ_TYPE_SAMPLER_2D_MULTISAMPLE = 76,
    GLSLC_PIQ_TYPE_SAMPLER_2D_MULTISAMPLE_ARRAY = 77,
    GLSLC_PIQ_TYPE_SAMPLER_CUBE_SHADOW = 78,
    GLSLC_PIQ_TYPE_SAMPLER_BUFFER = 79,
    GLSLC_PIQ_TYPE_SAMPLER_2D_RECT = 80,
    GLSLC_PIQ_TYPE_SAMPLER_2D_RECT_SHADOW = 81,
    GLSLC_PIQ_TYPE_INT_SAMPLER_1D = 82,
    GLSLC_PIQ_TYPE_INT_SAMPLER_2D = 83,
    GLSLC_PIQ_TYPE_INT_SAMPLER_3D = 84,
    GLSLC_PIQ_TYPE_INT_SAMPLER_CUBE = 85,
    GLSLC_PIQ_TYPE_INT_SAMPLER_1D_ARRAY = 86,
    GLSLC_PIQ_TYPE_INT_SAMPLER_2D_ARRAY = 87,
    GLSLC_PIQ_TYPE_INT_SAMPLER_2D_MULTISAMPLE = 88,
    GLSLC_PIQ_TYPE_INT_SAMPLER_2D_MULTISAMPLE_ARRAY = 89,
    GLSLC_PIQ_TYPE_INT_SAMPLER_BUFFER = 90,
    GLSLC_PIQ_TYPE_INT_SAMPLER_2D_RECT = 91,
    GLSLC_PIQ_TYPE_UINT_SAMPLER_1D = 92,
    GLSLC_PIQ_TYPE_UINT_SAMPLER_2D = 93,
    GLSLC_PIQ_TYPE_UINT_SAMPLER_3D = 94,
    GLSLC_PIQ_TYPE_UINT_SAMPLER_CUBE = 95,
    GLSLC_PIQ_TYPE_UINT_SAMPLER_1D_ARRAY = 96,
    GLSLC_PIQ_TYPE_UINT_SAMPLER_2D_ARRAY = 97,
    GLSLC_PIQ_TYPE_UINT_SAMPLER_2D_MULTISAMPLE = 98,
    GLSLC_PIQ_TYPE_UINT_SAMPLER_2D_MULTISAMPLE_ARRAY = 99,
    GLSLC_PIQ_TYPE_UINT_SAMPLER_BUFFER = 100,
    GLSLC_PIQ_TYPE_UINT_SAMPLER_2D_RECT = 101,
    GLSLC_PIQ_TYPE_IMAGE_1D = 102,
    GLSLC_PIQ_TYPE_IMAGE_2D = 103,
    GLSLC_PIQ_TYPE_IMAGE_3D = 104,
    GLSLC_PIQ_TYPE_IMAGE_2D_RECT = 105,
    GLSLC_PIQ_TYPE_IMAGE_CUBE = 106,
    GLSLC_PIQ_TYPE_IMAGE_BUFFER = 107,
    GLSLC_PIQ_TYPE_IMAGE_1D_ARRAY = 108,
    GLSLC_PIQ_TYPE_IMAGE_2D_ARRAY = 109,
    GLSLC_PIQ_TYPE_IMAGE_CUBE_MAP_ARRAY = 110,
    GLSLC_PIQ_TYPE_IMAGE_2D_MULTISAMPLE = 111,
    GLSLC_PIQ_TYPE_IMAGE_2D_MULTISAMPLE_ARRAY = 112,
    GLSLC_PIQ_TYPE_INT_IMAGE_1D = 113,
    GLSLC_PIQ_TYPE_INT_IMAGE_2D = 114,
    GLSLC_PIQ_TYPE_INT_IMAGE_3D = 115,
    GLSLC_PIQ_TYPE_INT_IMAGE_2D_RECT = 116,
    GLSLC_PIQ_TYPE_INT_IMAGE_CUBE = 117,
    GLSLC_PIQ_TYPE_INT_IMAGE_BUFFER = 118,
    GLSLC_PIQ_TYPE_INT_IMAGE_1D_ARRAY = 119,
    GLSLC_PIQ_TYPE_INT_IMAGE_2D_ARRAY = 120,
    GLSLC_PIQ_TYPE_INT_IMAGE_CUBE_MAP_ARRAY = 121,
    GLSLC_PIQ_TYPE_INT_IMAGE_2D_MULTISAMPLE = 122,
    GLSLC_PIQ_TYPE_INT_IMAGE_2D_MULTISAMPLE_ARRAY = 123,
    GLSLC_PIQ_TYPE_UINT_IMAGE_1D = 124,
    GLSLC_PIQ_TYPE_UINT_IMAGE_2D = 125,
    GLSLC_PIQ_TYPE_UINT_IMAGE_3D = 126,
    GLSLC_PIQ_TYPE_UINT_IMAGE_2D_RECT = 127,
    GLSLC_PIQ_TYPE_UINT_IMAGE_CUBE = 128,
    GLSLC_PIQ_TYPE_UINT_IMAGE_BUFFER = 129,
    GLSLC_PIQ_TYPE_UINT_IMAGE_1D_ARRAY = 130,
    GLSLC_PIQ_TYPE_UINT_IMAGE_2D_ARRAY = 131,
    GLSLC_PIQ_TYPE_UINT_IMAGE_CUBE_MAP_ARRAY = 132,
    GLSLC_PIQ_TYPE_UINT_IMAGE_2D_MULTISAMPLE = 133,
    GLSLC_PIQ_TYPE_UINT_IMAGE_2D_MULTISAMPLE_ARRAY = 134,
    GLSLC_PIQ_TYPE_SAMPLER_CUBE_MAP_ARRAY = 135,
    GLSLC_PIQ_TYPE_INT_SAMPLER_CUBE_MAP_ARRAY = 136,
    GLSLC_PIQ_TYPE_UINT_SAMPLER_CUBE_MAP_ARRAY = 137,
    GLSLC_PIQ_TYPE_SAMPLER_CUBE_MAP_ARRAY_SHADOW = 138,
    GLSLC_PIQ_TYPE_SAMPLER = 139,
    GLSLC_PIQ_TYPE_TEXTURE_1D = 140,
    GLSLC_PIQ_TYPE_TEXTURE_2D = 141,
    GLSLC_PIQ_TYPE_TEXTURE_3D = 142,
    GLSLC_PIQ_TYPE_TEXTURE_CUBE = 143,
    GLSLC_PIQ_TYPE_TEXTURE_1D_SHADOW = 144,
    GLSLC_PIQ_TYPE_TEXTURE_2D_SHADOW = 145,
    GLSLC_PIQ_TYPE_TEXTURE_1D_ARRAY = 146,
    GLSLC_PIQ_TYPE_TEXTURE_2D_ARRAY = 147,
    GLSLC_PIQ_TYPE_TEXTURE_1D_ARRAY_SHADOW = 148,
    GLSLC_PIQ_TYPE_TEXTURE_2D_ARRAY_SHADOW = 149,
    GLSLC_PIQ_TYPE_TEXTURE_2D_MULTISAMPLE = 150,
    GLSLC_PIQ_TYPE_TEXTURE_2D_MULTISAMPLE_ARRAY = 151,
    GLSLC_PIQ_TYPE_TEXTURE_CUBE_SHADOW = 152,
    GLSLC_PIQ_TYPE_TEXTURE_BUFFER = 153,
    GLSLC_PIQ_TYPE_TEXTURE_2D_RECT = 154,
    GLSLC_PIQ_TYPE_TEXTURE_2D_RECT_SHADOW = 155,
    GLSLC_PIQ_TYPE_TEXTURE_CUBE_MAP_ARRAY = 156,
    GLSLC_PIQ_TYPE_TEXTURE_CUBE_MAP_ARRAY_SHADOW = 157,
    GLSLC_PIQ_TYPE_INT_TEXTURE_1D = 158,
    GLSLC_PIQ_TYPE_INT_TEXTURE_2D = 159,
    GLSLC_PIQ_TYPE_INT_TEXTURE_3D = 160,
    GLSLC_PIQ_TYPE_INT_TEXTURE_CUBE = 161,
    GLSLC_PIQ_TYPE_INT_TEXTURE_1D_ARRAY = 162,
    GLSLC_PIQ_TYPE_INT_TEXTURE_2D_ARRAY = 163,
    GLSLC_PIQ_TYPE_INT_TEXTURE_2D_MULTISAMPLE = 164,
    GLSLC_PIQ_TYPE_INT_TEXTURE_2D_MULTISAMPLE_ARRAY = 165,
    GLSLC_PIQ_TYPE_INT_TEXTURE_BUFFER = 166,
    GLSLC_PIQ_TYPE_INT_TEXTURE_2D_RECT = 167,
    GLSLC_PIQ_TYPE_INT_TEXTURE_CUBE_MAP_ARRAY = 168,
    GLSLC_PIQ_TYPE_UINT_TEXTURE_1D = 169,
    GLSLC_PIQ_TYPE_UINT_TEXTURE_2D = 170,
    GLSLC_PIQ_TYPE_UINT_TEXTURE_3D = 171,
    GLSLC_PIQ_TYPE_UINT_TEXTURE_CUBE = 172,
    GLSLC_PIQ_TYPE_UINT_TEXTURE_1D_ARRAY = 173,
    GLSLC_PIQ_TYPE_UINT_TEXTURE_2D_ARRAY = 174,
    GLSLC_PIQ_TYPE_UINT_TEXTURE_2D_MULTISAMPLE = 175,
    GLSLC_PIQ_TYPE_UINT_TEXTURE_2D_MULTISAMPLE_ARRAY = 176,
    GLSLC_PIQ_TYPE_UINT_TEXTURE_BUFFER = 177,
    GLSLC_PIQ_TYPE_UINT_TEXTURE_2D_RECT = 178,
    GLSLC_PIQ_TYPE_UINT_TEXTURE_CUBE_MAP_ARRAY = 179,
    GLSLC_PIQ_INVALID_TYPE = -1,
};

typedef enum GLSLCdebugInfoLevel_enum {
    GLSLC_DEBUG_LEVEL_NONE,
    GLSLC_DEBUG_LEVEL_G0,
    GLSLC_DEBUG_LEVEL_G1,
    GLSLC_DEBUG_LEVEL_G2,
} GLSLCdebugInfoLevelEnum;

typedef enum GLSLClanguageTypeEnum_enum {
    GLSLC_LANGUAGE_GLSL,
    GLSLC_LANGUAGE_GLES,
    GLSLC_LANGUAGE_SPIRV,
} GLSLClanguageTypeEnum;

typedef enum SpillControlEnum_enum { DEFAULT_SPILL, NO_SPILL } SpillControlEnum;

typedef enum GLSLCoptLevel_enum { GLSLC_OPTLEVEL_DEFAULT, GLSLC_OPTLEVEL_NONE } GLSLCoptLevelEnum;

typedef enum GLSLCunrollControl_enum {
    GLSLC_LOOP_UNROLL_DEFAULT,
    GLSLC_LOOP_UNROLL_NONE,
    GLSLC_LOOP_UNROLL_ALL,
} GLSLCunrollControlEnum;

typedef enum GLSLCwarnUninitControl_enum {
    GLSLC_WARN_UNINIT_DEFAULT,
    GLSLC_WARN_UNINIT_NONE,
    GLSLC_WARN_UNINIT_ALL,
} GLSLCwarnUninitControlEnum;

typedef enum GLSLCsectionTypeEnum_enum {
    GLSLC_SECTION_TYPE_GPU_CODE = 0,
    GLSLC_SECTION_TYPE_ASM_DUMP = 1,
    GLSLC_SECTION_TYPE_PERF_STATS = 2,
    GLSLC_SECTION_TYPE_REFLECTION = 3,
    GLSLC_SECTION_TYPE_DEBUG_INFO = 4,
    GLSLC_NUM_SECTION_TYPES = 5,
    GLSLC_SECTION_TYPE_ENUM_LARGE = -1,
} GLSLCsectionTypeEnum;

typedef struct GLSLCpiqName_rec {
    uint32_t nameOffset;
    uint32_t nameLength;
    uint8_t reserved[32];
} GLSLCpiqName;

typedef struct GLSLCuniformBlockInfo_rec {
    GLSLCpiqName nameInfo;
    uint32_t size;
    uint32_t numActiveVariables;
    NVNshaderStageBits stagesReferencedIn;
    int32_t bindings[6];
    uint8_t reserved[32];
} GLSLCuniformBlockInfo;

typedef struct GLSLCuniform_rec {
    GLSLCpiqName nameInfo;
    GLSLCpiqTypeEnum type;
    int32_t blockNdx;
    int32_t blockOffset;
    uint32_t sizeOfArray;
    uint32_t arrayStride;
    int32_t matrixStride;
    uint32_t isRowMajor;
    NVNshaderStageBits stagesReferencedIn;
    int32_t bindings[6];
    GLSLCpiqUniformKind kind;
    uint8_t isInUBO;
    uint8_t isArray;
    uint8_t reserved[62];
} GLSLCuniformInfo;

typedef struct GLSLCProgramInputInfo_rec {
    GLSLCpiqName nameInfo;
    GLSLCpiqTypeEnum type;
    uint32_t sizeOfArray;
    int32_t location;
    NVNshaderStageBits stagesReferencedIn;
    uint8_t isArray;
    uint8_t isPerPatch;
    uint8_t reserved[34];
} GLSLCProgramInputInfo;

typedef struct GLSLCProgramOutput_rec {
    GLSLCpiqName nameInfo;
    GLSLCpiqTypeEnum type;
    uint32_t sizeOfArray;
    int32_t location;
    int32_t locationNdx;
    NVNshaderStageBits stagesReferencedIn;
    uint8_t isArray;
    uint8_t isPerPatch;
    uint8_t reserved[30];
} GLSLCProgramOutputInfo;

typedef struct GLSLCssboInfo_rec {
    GLSLCpiqName nameInfo;
    uint32_t size;
    uint32_t numActiveVariables;
    int32_t bindings[6];
    NVNshaderStageBits stagesReferencedIn;
    uint8_t reserved[32];
} GLSLCssboInfo;

typedef struct GLSLCxfbInfo_rec {
    GLSLC_PTR(const char* const*, varyings);

    uint32_t numVaryings;
    uint8_t reserved[32];
} GLSLCxfbInfo;

typedef struct GLSLCincludeInfo_rec {
    GLSLC_PTR(const char* const*, paths);

    uint32_t numPaths;
    uint8_t reserved[32];
} GLSLCincludeInfo;

typedef struct GLSLCspecializationBatch_rec {
    // todo: reverse from nnSdk, type never used
} GLSLCspecializationBatch;

typedef struct GLSLCoptionFlags_rec {
    uint32_t glslSeparable : 1;
    uint32_t outputAssembly : 1;
    uint32_t outputGpuBinaries : 1;
    uint32_t outputPerfStats : 1;
    uint32_t outputShaderReflection : 1;
    GLSLClanguageTypeEnum language : 4;
    GLSLCdebugInfoLevelEnum outputDebugInfo : 4;
    SpillControlEnum spillControl : 4;
    uint32_t outputThinGpuBinaries : 1;
    uint32_t tessellationAndPassthroughGS : 1;
    uint32_t prioritizeConsecutiveTextureInstructions : 1;
    uint32_t enableFastMathMask : 6;
    GLSLCoptLevelEnum optLevel : 3;
    GLSLCunrollControlEnum unrollControl : 3;
    uint32_t errorOnScratchMemUsage : 1;
    uint32_t enableCBFOptimization : 1;
    uint32_t enableWarpCulling : 1;
    uint32_t enableMultithreadCompilation : 1;
    GLSLCwarnUninitControlEnum warnUninitControl : 3;
} GLSLCoptionFlags;

typedef struct GLSLCoptions_rec {
    GLSLC_PTR(const char*, forceIncludeStdHeader);

    GLSLCoptionFlags optionFlags;
    GLSLCincludeInfo includeInfo;
    GLSLCxfbInfo xfbVaryingInfo;
    uint8_t reserved[32];
} GLSLCoptions;

typedef struct GLSLCcompilationStatus_rec {
    GLSLC_PTR(const char*, infoLog);

    uint32_t infoLogLength;
    uint8_t success;
    uint8_t allocError;
    uint8_t usedMTSpecialization;
    uint8_t reserved[1];
    uint32_t numEntriesInBatch;
    uint8_t reserved2[24];
} GLSLCcompilationStatus;

typedef struct GLSLCspirvSpecializationInfo_rec {
    // todo: reverse from nnSdk, type never used
} GLSLCspirvSpecializationInfo;

typedef struct GLSLCinput_rec {
    GLSLC_PTR(const char* const*, sources);
    GLSLC_PTR(const NVNshaderStage*, stages);

    uint8_t count;
    uint8_t reserved[7];

    GLSLC_PTR(const char* const*, spirvEntryPointNames);
    GLSLC_PTR(const uint32_t*, spirvModuleSizes);
    GLSLC_PTR(const GLSLCspirvSpecializationInfo* const*, spirvSpecInfo);
} GLSLCinput;

typedef struct GLSLCsectionHeaderCommon_rec {
    uint32_t size;
    uint32_t dataOffset;
    GLSLCsectionTypeEnum type;
    uint8_t reserved[32];
} GLSLCsectionHeaderCommon;

typedef struct GLSLCshaderInfoCompute_rec {
    uint32_t workGroupSize[3];
    uint8_t reserved[32];
} GLSLCshaderInfoCompute;

typedef union GLSLCshaderInfoUnion_rec {
    GLSLCshaderInfoCompute compute;
} GLSLCshaderInfoUnion;

typedef struct GLSLCperStageShaderInfo_rec {
    GLSLCshaderInfoUnion shaderInfo[6];
} GLSLCperStageShaderInfo;

typedef struct GLSLCprogramReflectionHeader_rec {
    GLSLCsectionHeaderCommon common;
    uint32_t numUniformBlocks;
    uint32_t uniformBlockOffset;
    uint32_t numUniforms;
    uint32_t uniformOffset;
    uint32_t numProgramInputs;
    uint32_t programInputsOffset;
    uint32_t numProgramOutputs;
    uint32_t programOutputsOffset;
    uint32_t numSsbo;
    uint32_t ssboOffset;
    uint32_t numBufferVariables;
    uint32_t bufferVariableOffset;
    uint32_t numXfbVaryings;
    uint32_t xfbVaryingsOffset;
    uint32_t stringPoolSize;
    uint32_t stringPoolOffset;
    uint32_t shaderInfoOffset;
    uint32_t numSubroutines;
    uint32_t subroutineOffset;
    uint32_t numSubroutineUniforms;
    uint32_t subroutineUniformOffset;
    uint32_t subroutineCompatibleIndexPoolSize;
    uint32_t subroutineCompatibleIndexPoolOffset;
    uint8_t reserved[4];
} GLSLCprogramReflectionHeader;

typedef struct GLSLCgpuCodeHeader_rec {
    GLSLCsectionHeaderCommon common;
    NVNshaderStage stage;
    uint32_t controlOffset;
    uint32_t dataOffset;
    uint32_t dataSize;
    uint32_t controlSize;
    uint32_t scratchMemBytesPerWarp;
    uint32_t scratchMemBytesRecommended;
    uint32_t asmDumpSectionIdx;
    uint32_t perfStatsSectionNdx;
    uint32_t subroutineLinkageMapOffset;
    uint32_t subroutineLinkageMapSize;
    uint8_t reserved[56];
} GLSLCgpuCodeHeader;

typedef struct GLSLCasmDumpHeader_rec {
    GLSLCsectionHeaderCommon common;
    NVNshaderStage stage;
    uint8_t reserved[60];
} GLSLCasmDumpHeader;

typedef struct GLSLCgenericHeader_rec {
    GLSLCsectionHeaderCommon common;
    uint8_t reserved[32];
} GLSLCgenericHeader;

typedef struct GLSLCperfStatsHeader_rec {
    GLSLCsectionHeaderCommon common;
    uint8_t reserved[32];
} GLSLCperfStatsHeader;

typedef struct GLSLCdebugDataHash_rec {
    uint32_t buildId[4];
    uint32_t debugHashLo32;
    uint32_t debugHashHi32;
} GLSLCdebugDataHash;

typedef struct GLSLCdebugInfoHeader_rec {
    GLSLCsectionHeaderCommon common;
    GLSLCdebugDataHash debugDataHash;
    uint8_t reserved[40];
} GLSLCdebugInfoHeader;

typedef union GLSLCsectionHeaderUnion_rec {
    GLSLCgenericHeader genericHeader;
    GLSLCgpuCodeHeader gpuCodeHeader;
    GLSLCasmDumpHeader asmDumpHeader;
    GLSLCperfStatsHeader perfStatsHeader;
    GLSLCprogramReflectionHeader programReflectionHeader;
    GLSLCdebugInfoHeader debugInfoHeader;
} GLSLCsectionHeaderUnion;

typedef struct GLSLCversion_rec {
    uint32_t apiMajor;
    uint32_t apiMinor;
    uint32_t gpuCodeVersionMajor;
    uint32_t gpuCodeVersionMinor;
    uint32_t package;
    uint8_t reserved[32];
} GLSLCversion;

typedef struct GLSLCoutput_rec {
    uint32_t magic;
    uint32_t reservedBits;
    GLSLCoptionFlags optionFlags;
    GLSLCversion versionInfo;
    uint32_t size;
    uint32_t dataOffset;
    uint32_t numSections;
    uint8_t reserved[64];
    GLSLCsectionHeaderUnion headers[1];
} GLSLCoutput;

typedef struct GLSLCresults_rec {
    GLSLC_PTR(GLSLCcompilationStatus*, compilationStatus);
    GLSLC_PTR(GLSLCoutput*, glslcOutput);
    uint8_t reserved[32];
} GLSLCresults;

typedef enum GLSLCinitializationStatus_enum {
    GLSLC_INIT_ERROR_UNINITIALIZED,
    GLSLC_INIT_SUCCESS,
    GLSLC_INIT_ERROR_ALLOC_FAILURE,
    GLSLC_INIT_ERROR_NO_ALLOC_CALLBACKS_SET,
} GLSLCinitializationStatus;

typedef struct GLSLCcompileObject {
    GLSLC_PTR(GLSLCresults*, lastCompiledResults);
    GLSLC_PTR(GLSLCprogramReflectionHeader*, reflectionSection);
    GLSLC_PTR(void*, privateData);

    GLSLCoptions options;
    GLSLCinput input;
    GLSLCinitializationStatus initStatus;
    uint8_t reserved[28];
} GLSLCcompileObject;

typedef void* (*GLSLCallocateFunction)(size_t, size_t, void*);
typedef void (*GLSLCfreeFunction)(void*, void*);
typedef void* (*GLSLCreallocateFunction)(void*, size_t, void*);
