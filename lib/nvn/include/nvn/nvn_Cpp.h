#pragma once

// NOLINTNEXTLINE(modernize-deprecated-headers)
#include <stddef.h>
// NOLINTNEXTLINE(modernize-deprecated-headers)
#include <stdint.h>

// todo: verify ENUM and BITS' void ctor funcitonality
#define NVN_ENUM(CLASS)                                                                            \
private:                                                                                           \
    Enum m_value;                                                                                  \
                                                                                                   \
public:                                                                                            \
    CLASS() : m_value(static_cast<Enum>(-1)) {}                                                    \
    CLASS(const CLASS& c) : m_value(c.m_value) {}                                                  \
    CLASS(Enum e) : m_value(e) {}                                                                  \
    operator Enum() const {                                                                        \
        return m_value;                                                                            \
    }                                                                                              \
    bool operator==(const CLASS& c) const {                                                        \
        return m_value == c.m_value;                                                               \
    }                                                                                              \
    bool operator==(const Enum& e) const {                                                         \
        return m_value == e;                                                                       \
    }                                                                                              \
    bool operator!=(const CLASS& c) const {                                                        \
        return m_value != c.m_value;                                                               \
    }                                                                                              \
    bool operator!=(const Enum& e) const {                                                         \
        return m_value != e;                                                                       \
    }

#define NVN_BITS(CLASS)                                                                            \
private:                                                                                           \
    int m_value;                                                                                   \
                                                                                                   \
public:                                                                                            \
    CLASS() : m_value(-1) {}                                                                       \
    CLASS(const CLASS& c) : m_value(c.m_value) {}                                                  \
    CLASS(int i) : m_value(i) {}                                                                   \
    CLASS(Enum e) : m_value(e) {}                                                                  \
    operator int() const {                                                                         \
        return m_value;                                                                            \
    }                                                                                              \
    bool operator==(const CLASS& c) const {                                                        \
        return m_value == c.m_value;                                                               \
    }                                                                                              \
    bool operator==(const Enum& e) const {                                                         \
        return m_value == e;                                                                       \
    }                                                                                              \
    bool operator!=(const CLASS& c) const {                                                        \
        return m_value != c.m_value;                                                               \
    }                                                                                              \
    bool operator!=(const Enum& e) const {                                                         \
        return m_value != e;                                                                       \
    }                                                                                              \
    CLASS operator|(const CLASS& c) const {                                                        \
        return CLASS(m_value | c.m_value);                                                         \
    }                                                                                              \
    CLASS operator|(const Enum& e) const {                                                         \
        return CLASS(m_value | e);                                                                 \
    }                                                                                              \
    CLASS operator&(const CLASS& c) const {                                                        \
        return CLASS(m_value & c.m_value);                                                         \
    }                                                                                              \
    CLASS operator&(const Enum& e) const {                                                         \
        return CLASS(m_value & e);                                                                 \
    }                                                                                              \
    CLASS operator^(const CLASS& c) const {                                                        \
        return CLASS(m_value ^ c.m_value);                                                         \
    }                                                                                              \
    CLASS operator^(const Enum& e) const {                                                         \
        return CLASS(m_value ^ e);                                                                 \
    }                                                                                              \
    CLASS& operator|=(const CLASS& c) {                                                            \
        m_value |= c.m_value;                                                                      \
        return *this;                                                                              \
    }                                                                                              \
    CLASS& operator|=(const Enum& e) {                                                             \
        m_value |= e;                                                                              \
        return *this;                                                                              \
    }                                                                                              \
    CLASS& operator&=(const CLASS& c) {                                                            \
        m_value &= c.m_value;                                                                      \
        return *this;                                                                              \
    }                                                                                              \
    CLASS& operator&=(const Enum& e) {                                                             \
        m_value &= e;                                                                              \
        return *this;                                                                              \
    }                                                                                              \
    CLASS& operator^=(const CLASS& c) {                                                            \
        m_value ^= c.m_value;                                                                      \
        return *this;                                                                              \
    }                                                                                              \
    CLASS& operator^=(const Enum& e) {                                                             \
        m_value ^= e;                                                                              \
        return *this;                                                                              \
    }

typedef uint8_t NVNboolean;
typedef void* NVNnativeWindow;
typedef void* NVNsubroutineLinkageMapPtr;
typedef int NVNstorageClass;
typedef int NVNdebugDomainId;

namespace nvn {

// todo: find these types, not found in diablo3 or dark2
union QueueErrorInfo;
struct DrawTextureRegion;
struct ShaderDataExt;
struct MappingRequest;
struct TextureSparseTileLayout;
struct Rectangle;

typedef uint64_t BufferAddress;
typedef uint64_t CommandHandle;
typedef uint64_t TextureHandle;
typedef uint64_t ImageHandle;
typedef uint64_t TextureAddress;
struct SeparateSamplerHandle {
    uint64_t value;
};
struct SeparateTextureHandle {
    uint64_t value;
};

struct DeviceInfo {
    enum Enum {
        API_MAJOR_VERSION = 0,
        API_MINOR_VERSION = 1,
        UNIFORM_BUFFER_BINDINGS_PER_STAGE = 2,
        MAX_UNIFORM_BUFFER_SIZE = 3,
        UNIFORM_BUFFER_ALIGNMENT = 4,
        COLOR_BUFFER_BINDINGS = 5,
        VERTEX_BUFFER_BINDINGS = 6,
        TRANSFORM_FEEDBACK_BUFFER_BINDINGS = 7,
        SHADER_STORAGE_BUFFER_BINDINGS_PER_STAGE = 8,
        TEXTURE_BINDINGS_PER_STAGE = 9,
        COUNTER_ALIGNMENT = 10,
        TRANSFORM_FEEDBACK_BUFFER_ALIGNMENT = 11,
        TRANSFORM_FEEDBACK_CONTROL_ALIGNMENT = 12,
        INDIRECT_DRAW_ALIGNMENT = 13,
        VERTEX_ATTRIBUTES = 14,
        TEXTURE_DESCRIPTOR_SIZE = 15,
        SAMPLER_DESCRIPTOR_SIZE = 16,
        RESERVED_TEXTURE_DESCRIPTORS = 17,
        RESERVED_SAMPLER_DESCRIPTORS = 18,
        COMMAND_BUFFER_COMMAND_ALIGNMENT = 19,
        COMMAND_BUFFER_CONTROL_ALIGNMENT = 20,
        COMMAND_BUFFER_MIN_COMMAND_SIZE = 21,
        COMMAND_BUFFER_MIN_CONTROL_SIZE = 22,
        SHADER_SCRATCH_MEMORY_SCALE_FACTOR_MINIMUM = 23,
        SHADER_SCRATCH_MEMORY_SCALE_FACTOR_RECOMMENDED = 24,
        SHADER_SCRATCH_MEMORY_ALIGNMENT = 25,
        SHADER_SCRATCH_MEMORY_GRANULARITY = 26,
        MAX_TEXTURE_ANISOTROPY = 27,
        MAX_COMPUTE_WORK_GROUP_SIZE_X = 28,
        MAX_COMPUTE_WORK_GROUP_SIZE_Y = 29,
        MAX_COMPUTE_WORK_GROUP_SIZE_Z = 30,
        MAX_COMPUTE_WORK_GROUP_SIZE_THREADS = 31,
        MAX_COMPUTE_DISPATCH_WORK_GROUPS_X = 32,
        MAX_COMPUTE_DISPATCH_WORK_GROUPS_Y = 33,
        MAX_COMPUTE_DISPATCH_WORK_GROUPS_Z = 34,
        IMAGE_BINDINGS_PER_STAGE = 35,
        MAX_TEXTURE_POOL_SIZE = 36,
        MAX_SAMPLER_POOL_SIZE = 37,
        MAX_VIEWPORTS = 38,
        MEMPOOL_TEXTURE_OBJECT_PAGE_ALIGNMENT = 39,
        SUPPORTS_MIN_MAX_FILTERING = 40,
        SUPPORTS_STENCIL8_FORMAT = 41,
        SUPPORTS_ASTC_FORMATS = 42,
        L2_SIZE = 43,
        MAX_TEXTURE_LEVELS = 44,
        MAX_TEXTURE_LAYERS = 45,
        GLSLC_MAX_SUPPORTED_GPU_CODE_MAJOR_VERSION = 46,
        GLSLC_MIN_SUPPORTED_GPU_CODE_MAJOR_VERSION = 47,
        GLSLC_MAX_SUPPORTED_GPU_CODE_MINOR_VERSION = 48,
        GLSLC_MIN_SUPPORTED_GPU_CODE_MINOR_VERSION = 49,
        SUPPORTS_CONSERVATIVE_RASTER = 50,
        SUBPIXEL_BITS = 51,
        MAX_SUBPIXEL_BIAS_BITS = 52,
        INDIRECT_DISPATCH_ALIGNMENT = 53,
        ZCULL_SAVE_RESTORE_ALIGNMENT = 54,
        SHADER_SCRATCH_MEMORY_COMPUTE_SCALE_FACTOR_MINIMUM = 55,
        LINEAR_TEXTURE_STRIDE_ALIGNMENT = 56,
        LINEAR_RENDER_TARGET_STRIDE_ALIGNMENT = 57,
        MEMORY_POOL_PAGE_SIZE = 58,
        SUPPORTS_ZERO_FROM_UNMAPPED_VIRTUAL_POOL_PAGES = 59,
        UNIFORM_BUFFER_UPDATE_ALIGNMENT = 60,
        MAX_TEXTURE_SIZE = 61,
        MAX_BUFFER_TEXTURE_SIZE = 62,
        MAX_3D_TEXTURE_SIZE = 63,
        MAX_CUBE_MAP_TEXTURE_SIZE = 64,
        MAX_RECTANGLE_TEXTURE_SIZE = 65,
        SUPPORTS_PASSTHROUGH_GEOMETRY_SHADERS = 66,
        SUPPORTS_VIEWPORT_SWIZZLE = 67,
        SUPPORTS_SPARSE_TILED_PACKAGED_TEXTURES = 68,
        SUPPORTS_ADVANCED_BLEND_MODES = 69,
        MAX_PRESENT_INTERVAL = 70,
        SUPPORTS_DRAW_TEXTURE = 71,
        SUPPORTS_TARGET_INDEPENDENT_RASTERIZATION = 72,
        SUPPORTS_FRAGMENT_COVERAGE_TO_COLOR = 73,
        SUPPORTS_POST_DEPTH_COVERAGE = 74,
        SUPPORTS_IMAGES_USING_TEXTURE_HANDLES = 75,
        SUPPORTS_SAMPLE_LOCATIONS = 76,
        MAX_SAMPLE_LOCATION_TABLE_ENTRIES = 77,
        SHADER_CODE_MEMORY_POOL_PADDING_SIZE = 78,
        MAX_PATCH_SIZE = 79,
        QUEUE_COMMAND_MEMORY_GRANULARITY = 80,
        QUEUE_COMMAND_MEMORY_MIN_SIZE = 81,
        QUEUE_COMMAND_MEMORY_DEFAULT_SIZE = 82,
        QUEUE_COMPUTE_MEMORY_GRANULARITY = 83,
        QUEUE_COMPUTE_MEMORY_MIN_SIZE = 84,
        QUEUE_COMPUTE_MEMORY_DEFAULT_SIZE = 85,
        QUEUE_COMMAND_MEMORY_MIN_FLUSH_THRESHOLD = 86,
        SUPPORTS_FRAGMENT_SHADER_INTERLOCK = 87,
        MAX_TEXTURES_PER_WINDOW = 88,
        MIN_TEXTURES_PER_WINDOW = 89,
        SUPPORTS_DEBUG_LAYER = 90,
        QUEUE_CONTROL_MEMORY_MIN_SIZE = 91,
        QUEUE_CONTROL_MEMORY_DEFAULT_SIZE = 92,
        QUEUE_CONTROL_MEMORY_GRANULARITY = 93,
        SEPARATE_TEXTURE_BINDINGS_PER_STAGE = 94,
        SEPARATE_SAMPLER_BINDINGS_PER_STAGE = 95,
        DEBUG_GROUPS_MAX_DOMAIN_ID = 96,
        EVENTS_SUPPORT_REDUCTION_OPERATIONS = 97,
        NVN_DEVICE_INFO_LARGE = -1,
    };

    NVN_ENUM(DeviceInfo);
};

struct TextureTarget {
    enum Enum {
        TARGET_1D = 0,
        TARGET_2D = 1,
        TARGET_3D = 2,
        TARGET_1D_ARRAY = 3,
        TARGET_2D_ARRAY = 4,
        TARGET_2D_MULTISAMPLE = 5,
        TARGET_2D_MULTISAMPLE_ARRAY = 6,
        TARGET_RECTANGLE = 7,
        TARGET_CUBEMAP = 8,
        TARGET_CUBEMAP_ARRAY = 9,
        TARGET_BUFFER = 10,
        NVN_TEXTURE_TARGET_LARGE = -1,
    };

    NVN_ENUM(TextureTarget);
};

struct TextureSwizzle {
    enum Enum { ZERO = 0, ONE = 1, R = 2, G = 3, B = 4, A = 5, NVN_TEXTURE_SWIZZLE_LARGE = -1 };

    NVN_ENUM(TextureSwizzle);
};

struct TextureDepthStencilMode {
    enum Enum { DEPTH = 0, STENCIL = 1, NVN_TEXTURE_DEPTH_STENCIL_MODE_LARGE = -1 };

    NVN_ENUM(TextureDepthStencilMode);
};

struct Format {
    enum Enum {
        NONE = 0,
        R8 = 1,
        R8SN = 2,
        R8UI = 3,
        R8I = 4,
        R16F = 5,
        R16 = 6,
        R16SN = 7,
        R16UI = 8,
        R16I = 9,
        R32F = 10,
        R32UI = 11,
        R32I = 12,
        RG8 = 13,
        RG8SN = 14,
        RG8UI = 15,
        RG8I = 16,
        RG16F = 17,
        RG16 = 18,
        RG16SN = 19,
        RG16UI = 20,
        RG16I = 21,
        RG32F = 22,
        RG32UI = 23,
        RG32I = 24,
        RGB8 = 25,
        RGB8SN = 26,
        RGB8UI = 27,
        RGB8I = 28,
        RGB16F = 29,
        RGB16 = 30,
        RGB16SN = 31,
        RGB16UI = 32,
        RGB16I = 33,
        RGB32F = 34,
        RGB32UI = 35,
        RGB32I = 36,
        RGBA8 = 37,
        RGBA8SN = 38,
        RGBA8UI = 39,
        RGBA8I = 40,
        RGBA16F = 41,
        RGBA16 = 42,
        RGBA16SN = 43,
        RGBA16UI = 44,
        RGBA16I = 45,
        RGBA32F = 46,
        RGBA32UI = 47,
        RGBA32I = 48,
        STENCIL8 = 49,
        DEPTH16 = 50,
        DEPTH24 = 51,
        DEPTH32F = 52,
        DEPTH24_STENCIL8 = 53,
        DEPTH32F_STENCIL8 = 54,
        RGBX8_SRGB = 55,
        RGBA8_SRGB = 56,
        RGBA4 = 57,
        RGB5 = 58,
        RGB5A1 = 59,
        RGB565 = 60,
        RGB10A2 = 61,
        RGB10A2UI = 62,
        R11G11B10F = 63,
        RGB9E5F = 64,
        RGB_DXT1 = 65,
        RGBA_DXT1 = 66,
        RGBA_DXT3 = 67,
        RGBA_DXT5 = 68,
        RGB_DXT1_SRGB = 69,
        RGBA_DXT1_SRGB = 70,
        RGBA_DXT3_SRGB = 71,
        RGBA_DXT5_SRGB = 72,
        RGTC1_UNORM = 73,
        RGTC1_SNORM = 74,
        RGTC2_UNORM = 75,
        RGTC2_SNORM = 76,
        BPTC_UNORM = 77,
        BPTC_UNORM_SRGB = 78,
        BPTC_SFLOAT = 79,
        BPTC_UFLOAT = 80,
        R8_UI2F = 81,
        R8_I2F = 82,
        R16_UI2F = 83,
        R16_I2F = 84,
        R32_UI2F = 85,
        R32_I2F = 86,
        RG8_UI2F = 87,
        RG8_I2F = 88,
        RG16_UI2F = 89,
        RG16_I2F = 90,
        RG32_UI2F = 91,
        RG32_I2F = 92,
        RGB8_UI2F = 93,
        RGB8_I2F = 94,
        RGB16_UI2F = 95,
        RGB16_I2F = 96,
        RGB32_UI2F = 97,
        RGB32_I2F = 98,
        RGBA8_UI2F = 99,
        RGBA8_I2F = 100,
        RGBA16_UI2F = 101,
        RGBA16_I2F = 102,
        RGBA32_UI2F = 103,
        RGBA32_I2F = 104,
        RGB10A2SN = 105,
        RGB10A2I = 106,
        RGB10A2_UI2F = 107,
        RGB10A2_I2F = 108,
        RGBX8 = 109,
        RGBX8SN = 110,
        RGBX8UI = 111,
        RGBX8I = 112,
        RGBX16F = 113,
        RGBX16 = 114,
        RGBX16SN = 115,
        RGBX16UI = 116,
        RGBX16I = 117,
        RGBX32F = 118,
        RGBX32UI = 119,
        RGBX32I = 120,
        RGBA_ASTC_4x4 = 121,
        RGBA_ASTC_5x4 = 122,
        RGBA_ASTC_5x5 = 123,
        RGBA_ASTC_6x5 = 124,
        RGBA_ASTC_6x6 = 125,
        RGBA_ASTC_8x5 = 126,
        RGBA_ASTC_8x6 = 127,
        RGBA_ASTC_8x8 = 128,
        RGBA_ASTC_10x5 = 129,
        RGBA_ASTC_10x6 = 130,
        RGBA_ASTC_10x8 = 131,
        RGBA_ASTC_10x10 = 132,
        RGBA_ASTC_12x10 = 133,
        RGBA_ASTC_12x12 = 134,
        RGBA_ASTC_4x4_SRGB = 135,
        RGBA_ASTC_5x4_SRGB = 136,
        RGBA_ASTC_5x5_SRGB = 137,
        RGBA_ASTC_6x5_SRGB = 138,
        RGBA_ASTC_6x6_SRGB = 139,
        RGBA_ASTC_8x5_SRGB = 140,
        RGBA_ASTC_8x6_SRGB = 141,
        RGBA_ASTC_8x8_SRGB = 142,
        RGBA_ASTC_10x5_SRGB = 143,
        RGBA_ASTC_10x6_SRGB = 144,
        RGBA_ASTC_10x8_SRGB = 145,
        RGBA_ASTC_10x10_SRGB = 146,
        RGBA_ASTC_12x10_SRGB = 147,
        RGBA_ASTC_12x12_SRGB = 148,
        BGR565 = 149,
        BGR5 = 150,
        BGR5A1 = 151,
        A1BGR5 = 152,
        BGRX8 = 153,
        BGRA8 = 154,
        BGRX8_SRGB = 155,
        BGRA8_SRGB = 156,
        NVN_FORMAT_LARGE = -1,
    };

    NVN_ENUM(Format);
};

struct BlendFunc {
    enum Enum {
        ZERO = 1,
        ONE = 2,
        SRC_COLOR = 3,
        ONE_MINUS_SRC_COLOR = 4,
        SRC_ALPHA = 5,
        ONE_MINUS_SRC_ALPHA = 6,
        DST_ALPHA = 7,
        ONE_MINUS_DST_ALPHA = 8,
        DST_COLOR = 9,
        ONE_MINUS_DST_COLOR = 10,
        SRC_ALPHA_SATURATE = 11,
        SRC1_COLOR = 16,
        ONE_MINUS_SRC1_COLOR = 17,
        SRC1_ALPHA = 18,
        ONE_MINUS_SRC1_ALPHA = 19,
        CONSTANT_COLOR = 97,
        ONE_MINUS_CONSTANT_COLOR = 98,
        CONSTANT_ALPHA = 99,
        ONE_MINUS_CONSTANT_ALPHA = 100,
        NVN_BLEND_FUNC_LARGE = -1,
    };

    NVN_ENUM(BlendFunc);
};

struct BlendAdvancedMode {
    enum Enum {
        BLEND_NONE = 0,
        BLEND_ZERO = 5,
        BLEND_SRC = 6,
        BLEND_DST = 7,
        BLEND_SRC_OVER = 8,
        BLEND_DST_OVER = 9,
        BLEND_SRC_IN = 10,
        BLEND_DST_IN = 11,
        BLEND_SRC_OUT = 12,
        BLEND_DST_OUT = 13,
        BLEND_SRC_ATOP = 14,
        BLEND_DST_ATOP = 15,
        BLEND_XOR = 16,
        BLEND_PLUS = 17,
        BLEND_PLUS_CLAMPED = 18,
        BLEND_PLUS_CLAMPED_ALPHA = 19,
        BLEND_PLUS_DARKER = 20,
        BLEND_MULTIPLY = 21,
        BLEND_SCREEN = 22,
        BLEND_OVERLAY = 23,
        BLEND_DARKEN = 24,
        BLEND_LIGHTEN = 25,
        BLEND_COLORDODGE = 26,
        BLEND_COLORBURN = 27,
        BLEND_HARDLIGHT = 28,
        BLEND_SOFTLIGHT = 29,
        BLEND_DIFFERENCE = 30,
        BLEND_MINUS = 31,
        BLEND_MINUS_CLAMPED = 32,
        BLEND_EXCLUSION = 33,
        BLEND_CONTRAST = 34,
        BLEND_INVERT = 35,
        BLEND_INVERT_RGB = 36,
        BLEND_INVERT_OVG = 37,
        BLEND_LINEARDODGE = 38,
        BLEND_LINEARBURN = 39,
        BLEND_VIVIDLIGHT = 40,
        BLEND_LINEARLIGHT = 41,
        BLEND_PINLIGHT = 42,
        BLEND_HARDMIX = 43,
        BLEND_RED = 44,
        BLEND_GREEN = 45,
        BLEND_BLUE = 46,
        BLEND_HSL_HUE = 47,
        BLEND_HSL_SATURATION = 48,
        BLEND_HSL_COLOR = 49,
        BLEND_HSL_LUMINOSITY = 50,
        NVN_BLEND_ADVANCED_MODE_LARGE = -1,
    };

    NVN_ENUM(BlendAdvancedMode);
};

struct BlendAdvancedOverlap {
    enum Enum {
        UNCORRELATED = 0,
        DISJOINT = 1,
        CONJOINT = 2,
        NVN_BLEND_ADVANCED_OVERLAP_LARGE = -1,
    };

    NVN_ENUM(BlendAdvancedOverlap);
};

struct BlendEquation {
    enum Enum {
        ADD = 1,
        SUB = 2,
        REVERSE_SUB = 3,
        MIN = 4,
        MAX = 5,
        NVN_BLEND_EQUATION_LARGE = -1,
    };

    NVN_ENUM(BlendEquation);
};

struct LogicOp {
    enum Enum {
        CLEAR = 0,
        AND = 1,
        AND_REVERSE = 2,
        COPY = 3,
        AND_INVERTED = 4,
        NOOP = 5,
        XOR = 6,
        OR = 7,
        NOR = 8,
        EQUIV = 9,
        INVERT = 10,
        OR_REVERSE = 11,
        COPY_INVERTED = 12,
        OR_INVERTED = 13,
        NAND = 14,
        SET = 15,
        NVN_LOGIC_OP_LARGE = -1,
    };

    NVN_ENUM(LogicOp);
};

struct AlphaFunc {
    enum Enum {
        NEVER = 1,
        LESS = 2,
        EQUAL = 3,
        LEQUAL = 4,
        GREATER = 5,
        NOTEQUAL = 6,
        GEQUAL = 7,
        ALWAYS = 8,
        NVN_ALPHA_FUNC_LARGE = -1,
    };

    NVN_ENUM(AlphaFunc);
};

struct DrawPrimitive {
    enum Enum {
        POINTS = 0,
        LINES = 1,
        LINE_LOOP = 2,
        LINE_STRIP = 3,
        TRIANGLES = 4,
        TRIANGLE_STRIP = 5,
        TRIANGLE_FAN = 6,
        QUADS = 7,
        QUAD_STRIP = 8,
        POLYGON = 9,
        LINES_ADJACENCY = 10,
        LINE_STRIP_ADJACENCY = 11,
        TRIANGLES_ADJACENCY = 12,
        TRIANGLE_STRIP_ADJACENCY = 13,
        PATCHES = 14,
        NVN_DRAW_PRIMITIVE_LARGE = -1,
    };

    NVN_ENUM(DrawPrimitive);
};

struct IndexType {
    enum Enum {
        UNSIGNED_BYTE = 0,
        UNSIGNED_SHORT = 1,
        UNSIGNED_INT = 2,
        NVN_INDEX_TYPE_LARGE = -1,
    };

    NVN_ENUM(IndexType);
};

struct DepthFunc {
    enum Enum {
        NEVER = 1,
        LESS = 2,
        EQUAL = 3,
        LEQUAL = 4,
        GREATER = 5,
        NOTEQUAL = 6,
        GEQUAL = 7,
        ALWAYS = 8,
        NVN_DEPTH_FUNC_LARGE = -1,
    };

    NVN_ENUM(DepthFunc);
};

struct MagFilter {
    enum Enum { NEAREST = 0, LINEAR = 1, NVN_MAG_FILTER_LARGE = -1 };

    NVN_ENUM(MagFilter);
};

struct MinFilter {
    enum Enum {
        NEAREST = 0,
        LINEAR = 1,
        NEAREST_MIPMAP_NEAREST = 2,
        LINEAR_MIPMAP_NEAREST = 3,
        NEAREST_MIPMAP_LINEAR = 4,
        LINEAR_MIPMAP_LINEAR = 5,
        NVN_MIN_FILTER_LARGE = -1,
    };

    NVN_ENUM(MinFilter);
};

struct WrapMode {
    enum Enum {
        CLAMP = 0,
        REPEAT = 1,
        MIRROR_CLAMP = 2,
        MIRROR_CLAMP_TO_EDGE = 3,
        MIRROR_CLAMP_TO_BORDER = 4,
        CLAMP_TO_BORDER = 5,
        MIRRORED_REPEAT = 6,
        CLAMP_TO_EDGE = 7,
        NVN_WRAP_MODE_LARGE = -1,
    };

    NVN_ENUM(WrapMode);
};

struct CompareMode {
    enum Enum { NONE = 0, COMPARE_R_TO_TEXTURE = 1, NVN_COMPARE_MODE_LARGE = -1 };

    NVN_ENUM(CompareMode);
};

struct CompareFunc {
    enum Enum {
        NEVER = 1,
        LESS = 2,
        EQUAL = 3,
        LEQUAL = 4,
        GREATER = 5,
        NOTEQUAL = 6,
        GEQUAL = 7,
        ALWAYS = 8,
        NVN_COMPARE_FUNC_LARGE = -1,
    };

    NVN_ENUM(CompareFunc);
};

struct SamplerReduction {
    enum Enum { AVERAGE = 0, MIN = 1, MAX = 2, NVN_SAMPLER_REDUCTION_LARGE = -1 };

    NVN_ENUM(SamplerReduction);
};

struct Face {
    enum Enum { NONE = 0, FRONT = 1, BACK = 2, FRONT_AND_BACK = 3, NVN_FACE_LARGE = -1 };

    NVN_ENUM(Face);
};

struct StencilFunc {
    enum Enum {
        NEVER = 1,
        LESS = 2,
        EQUAL = 3,
        LEQUAL = 4,
        GREATER = 5,
        NOTEQUAL = 6,
        GEQUAL = 7,
        ALWAYS = 8,
        NVN_STENCIL_FUNC_LARGE = -1,
    };

    NVN_ENUM(StencilFunc);
};

struct StencilOp {
    enum Enum {
        KEEP = 1,
        ZERO = 2,
        REPLACE = 3,
        INCR = 4,
        DECR = 5,
        INVERT = 6,
        INCR_WRAP = 7,
        DECR_WRAP = 8,
        NVN_STENCIL_OP_LARGE = -1,
    };

    NVN_ENUM(StencilOp);
};

struct FrontFace {
    enum Enum { CW = 0, CCW = 1, NVN_FRONT_FACE_LARGE = -1 };

    NVN_ENUM(FrontFace);
};

struct PolygonMode {
    enum Enum { POINT = 0, LINE = 1, FILL = 2, NVN_POLYGON_MODE_LARGE = -1 };

    NVN_ENUM(PolygonMode);
};

struct PolygonOffsetEnable {
    enum Enum { NONE = 0, POINT = 1, LINE = 2, FILL = 4, NVN_POLYGON_OFFSET_ENABLE_LARGE = -1 };

    NVN_BITS(PolygonOffsetEnable);
};

struct SyncCondition {
    enum Enum {
        ALL_GPU_COMMANDS_COMPLETE = 0,
        GRAPHICS_WORLD_SPACE_COMPLETE = 1,
        NVN_SYNC_CONDITION_LARGE = -1,
    };

    NVN_ENUM(SyncCondition);
};

struct SyncWaitResult {
    enum Enum {
        ALREADY_SIGNALED = 0,
        CONDITION_SATISFIED = 1,
        TIMEOUT_EXPIRED = 2,
        FAILED = 3,
        NVN_SYNC_WAIT_RESULT_LARGE = -1,
    };

    NVN_ENUM(SyncWaitResult);
};

struct QueueAcquireTextureResult {
    enum Enum { SUCCESS = 0, NATIVE_ERROR = 1, NVN_QUEUE_ACQUIRE_TEXTURE_RESULT_LARGE = -1 };

    NVN_ENUM(QueueAcquireTextureResult);
};

struct WindowAcquireTextureResult {
    enum Enum { SUCCESS = 0, NATIVE_ERROR = 1, NVN_WINDOW_ACQUIRE_TEXTURE_RESULT_LARGE = -1 };

    NVN_ENUM(WindowAcquireTextureResult);
};

struct ShaderStage {
    enum Enum {
        VERTEX = 0,
        FRAGMENT = 1,
        GEOMETRY = 2,
        TESS_CONTROL = 3,
        TESS_EVALUATION = 4,
        COMPUTE = 5,
        NVN_SHADER_STAGE_LARGE = -1,
    };

    NVN_ENUM(ShaderStage);
};

struct TiledCacheAction {
    enum Enum {
        ENABLE = 1,
        DISABLE = 2,
        FLUSH = 3,
        FLUSH_NO_TILING = 4,
        ENABLE_RENDER_TARGET_BINNING = 5,
        DISABLE_RENDER_TARGET_BINNING = 6,
        NVN_TILED_CACHE_ACTION_LARGE = -1,
    };

    NVN_ENUM(TiledCacheAction);
};

struct ShaderStageBits {
    enum Enum {
        VERTEX = 1,
        FRAGMENT = 2,
        GEOMETRY = 4,
        TESS_CONTROL = 8,
        TESS_EVALUATION = 16,
        COMPUTE = 32,
        ALL_GRAPHICS_BITS = 31,
        NVN_SHADER_STAGE_BITS_LARGE = -1,
    };

    NVN_BITS(ShaderStageBits);
};

struct SyncFlagBits {
    enum Enum { FLUSH_FOR_CPU = 1, NVN_SYNC_FLAG_BITS_LARGE = -1 };

    NVN_BITS(SyncFlagBits);
};

struct DeviceFlagBits {
    enum Enum {
        DEBUG_ENABLE = 1,
        DEBUG_SKIP_CALLS_ON_ERROR = 2,
        DEBUG_DRAW_VALIDATION = 4,
        DEFERRED_FINALIZE = 8,
        DEBUG_DRAW_VALIDATION_HEAVY = 16,
        DEBUG_ENABLE_LEVEL_0 = 32,
        DEBUG_ENABLE_LEVEL_1 = 64,
        DEBUG_ENABLE_LEVEL_2 = 1,
        DEBUG_ENABLE_LEVEL_3 = 4,
        DEBUG_ENABLE_LEVEL_4 = 16,
        DEFERRED_FIRMWARE_MEMORY_RECLAIM = 128,
        ENABLE_SEPARATE_SAMPLER_TEXTURE_SUPPORT = 256,
        NVN_DEVICE_FLAG_BITS_LARGE = -1,
    };

    NVN_BITS(DeviceFlagBits);
};

struct ClearColorMask {
    enum Enum { R = 1, G = 2, B = 4, A = 8, RGBA = 15, NVN_CLEAR_COLOR_MASK_LARGE = -1 };

    NVN_BITS(ClearColorMask);
};

struct DebugCallbackSource {
    enum Enum { API = 0, NVN_DEBUG_CALLBACK_SOURCE_LARGE = -1 };

    NVN_ENUM(DebugCallbackSource);
};

struct DebugCallbackType {
    enum Enum { API_ERROR = 0, API_WARNING = 1, NVN_DEBUG_CALLBACK_TYPE_LARGE = -1 };

    NVN_ENUM(DebugCallbackType);
};

struct DebugCallbackSeverity {
    enum Enum {
        HIGH = 0,
        MEDIUM = 1,
        LOW = 2,
        NOTIFICATION = 3,
        NVN_DEBUG_CALLBACK_SEVERITY_LARGE = -1,
    };

    NVN_ENUM(DebugCallbackSeverity);
};

struct MemoryPoolFlags {
    enum Enum {
        CPU_NO_ACCESS = 1,
        CPU_UNCACHED = 2,
        CPU_CACHED = 4,
        GPU_NO_ACCESS = 8,
        GPU_UNCACHED = 16,
        GPU_CACHED = 32,
        SHADER_CODE = 64,
        COMPRESSIBLE = 128,
        PHYSICAL = 256,
        VIRTUAL = 512,
        NVN_MEMORY_POOL_FLAGS_LARGE = -1,
    };

    NVN_BITS(MemoryPoolFlags);
};

struct CounterType {
    enum Enum {
        TIMESTAMP = 0,
        SAMPLES_PASSED = 1,
        INPUT_VERTICES = 2,
        INPUT_PRIMITIVES = 3,
        VERTEX_SHADER_INVOCATIONS = 4,
        TESS_CONTROL_SHADER_INVOCATIONS = 5,
        TESS_EVALUATION_SHADER_INVOCATIONS = 6,
        GEOMETRY_SHADER_INVOCATIONS = 7,
        FRAGMENT_SHADER_INVOCATIONS = 8,
        TESS_EVALUATION_SHADER_PRIMITIVES = 9,
        GEOMETRY_SHADER_PRIMITIVES = 10,
        CLIPPER_INPUT_PRIMITIVES = 11,
        CLIPPER_OUTPUT_PRIMITIVES = 12,
        PRIMITIVES_GENERATED = 13,
        TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN = 14,
        ZCULL_STATS = 15,
        TIMESTAMP_TOP = 16,
        NVN_COUNTER_TYPE_LARGE = -1,
    };

    NVN_ENUM(CounterType);
};

struct CommandBufferMemoryEvent {
    enum Enum {
        OUT_OF_COMMAND_MEMORY = 0,
        OUT_OF_CONTROL_MEMORY = 1,
        NVN_COMMAND_BUFFER_MEMORY_EVENT_LARGE = -1,
    };

    NVN_ENUM(CommandBufferMemoryEvent);
};

struct ConditionalRenderMode {
    enum Enum {
        RENDER_IF_EQUAL = 0,
        RENDER_IF_NOT_EQUAL = 1,
        NVN_CONDITIONAL_RENDER_MODE_LARGE = -1,
    };

    NVN_ENUM(ConditionalRenderMode);
};

struct WindowOriginMode {
    enum Enum { LOWER_LEFT = 0, UPPER_LEFT = 1, NVN_WINDOW_ORIGIN_MODE_LARGE = -1 };

    NVN_ENUM(WindowOriginMode);
};

struct DepthMode {
    enum Enum { NEAR_IS_MINUS_W = 0, NEAR_IS_ZERO = 1, NVN_DEPTH_MODE_LARGE = -1 };

    NVN_ENUM(DepthMode);
};

struct TextureFlags {
    enum Enum {
        DISPLAY = 1,
        VIDEO_DECODE = 2,
        IMAGE = 4,
        COMPRESSIBLE = 8,
        LINEAR = 16,
        SPARSE = 32,
        LINEAR_RENDER_TARGET = 64,
        ADAPTIVE_ZCULL = 128,
        DEPTH16_PREFER_FAST_CLEAR = 256,
        MINIMAL_LAYOUT = 512,
        ZCULL_SUPPORT_STENCIL = 1024,
        NVN_TEXTURE_FLAGS_LARGE = -1,
    };

    NVN_BITS(TextureFlags);
};

struct BarrierBits {
    enum Enum {
        ORDER_PRIMITIVES = 1,
        ORDER_FRAGMENTS = 2,
        ORDER_FRAGMENTS_TILED = 4,
        ORDER_INDIRECT_DATA = 8,
        INVALIDATE_TEXTURE = 16,
        INVALIDATE_SHADER = 32,
        INVALIDATE_TEXTURE_DESCRIPTOR = 64,
        INVALIDATE_ZCULL = 128,
        INVALIDATE_L2_CACHE = 256,
        NVN_BARRIER_BITS_LARGE = -1,
    };

    NVN_BITS(BarrierBits);
};

struct CopyFlags {
    enum Enum {
        NONE = 0,
        LINEAR_FILTER = 1,
        ENGINE_2D = 2,
        MIRROR_X = 4,
        MIRROR_Y = 8,
        MIRROR_Z = 16,
        NVN_COPY_FLAGS_LARGE = -1,
    };

    NVN_BITS(CopyFlags);
};

struct ViewportSwizzle {
    enum Enum {
        POSITIVE_X = 0,
        NEGATIVE_X = 1,
        POSITIVE_Y = 2,
        NEGATIVE_Y = 3,
        POSITIVE_Z = 4,
        NEGATIVE_Z = 5,
        POSITIVE_W = 6,
        NEGATIVE_W = 7,
        NVN_VIEWPORT_SWIZZLE_LARGE = -1,
    };

    NVN_ENUM(ViewportSwizzle);
};

struct CoverageModulationMode {
    enum Enum { NONE = 0, RGB = 1, ALPHA = 2, RGBA = 3, NVN_COVERAGE_MODULATION_MODE_LARGE = -1 };

    NVN_ENUM(CoverageModulationMode);
};

struct QueueFlags {
    enum Enum { NO_FRAGMENT_INTERLOCK = 1, NO_ZCULL = 2, NONE = 0, NVN_QUEUE_FLAGS_LARGE = -1 };

    NVN_BITS(QueueFlags);
};

struct DebugObjectType {
    enum Enum {
        WINDOW = 0,
        QUEUE = 1,
        COMMAND_BUFFER = 2,
        MEMORY_POOL = 3,
        SYNC = 7,
        PROGRAM = 9,
        TEXTURE_POOL = 10,
        SAMPLER_POOL = 11,
        NVN_DEBUG_OBJECT_TYPE_LARGE = -1,
    };

    NVN_ENUM(DebugObjectType);
};

struct EventSignalMode {
    enum Enum { WRITE = 0, ADD = 1, NVN_EVENT_SIGNAL_MODE_LARGE = -1 };

    NVN_ENUM(EventSignalMode);
};

struct EventWaitMode {
    enum Enum { EQUAL = 0, GEQUAL_WRAP = 1, NVN_EVENT_WAIT_MODE_LARGE = -1 };

    NVN_ENUM(EventWaitMode);
};

struct EventSignalLocation {
    enum Enum { TOP = 0, VERTEX_PIPE = 1, BOTTOM = 2, NVN_EVENT_SIGNAL_LOCATION_LARGE = -1 };

    NVN_ENUM(EventSignalLocation);
};

struct EventSignalFlags {
    enum Enum { NO_WAIT_MEMORY = 1, NVN_EVENT_SIGNAL_FLAGS_LARGE = -1 };

    NVN_BITS(EventSignalFlags);
};

struct FormatClass {
    enum Enum {
        UNORM8 = 0,
        UNORM10 = 1,
        UNORM16 = 2,
        FP11 = 3,
        FP16 = 4,
        SRGB8 = 5,
        NVN_FORMAT_CLASS_LARGE = -1,
    };

    NVN_ENUM(FormatClass);
};

struct QueueGetErrorResult {
    enum Enum {
        GPU_NO_ERROR = 0,
        GPU_ERROR_UNKNOWN = 1,
        GPU_ERROR_MMU_FAULT = 2,
        GPU_ERROR_PBDMA_EXCEPTION = 3,
        GPU_ERROR_ENGINE_EXCEPTION = 4,
        GPU_ERROR_TIMEOUT = 5,
        NVN_QUEUE_GET_ERROR_RESULT_LARGE = -1,
    };

    NVN_ENUM(QueueGetErrorResult);
};

struct QueuePriority {
    enum Enum { LOW = 10, NORMAL = 100, HIGH = 1000, NVN_QUEUE_PRIORITY_LARGE = -1 };

    NVN_ENUM(QueuePriority);
};

struct RawStorageClass {
    enum Enum {
        NONE = 0,
        LINEAR = 1,
        COLOR_AND_ZF32 = 2,
        S8_AND_Z16 = 3,
        Z24_AND_Z24S8 = 4,
        ZF32S8 = 5,
        NVN_RAW_STORAGE_CLASS_LARGE = -1,
    };

    NVN_ENUM(RawStorageClass);
};

struct SampleShadingMode {
    enum Enum {
        DEFAULT_FRAGMENT = 0,
        FORCE_SAMPLE_SHADING_ON = 1,
        FORCE_SAMPLE_SHADING_OFF = 2,
        NVN_SAMPLE_SHADING_MODE_LARGE = -1,
    };

    NVN_ENUM(SampleShadingMode);
};

struct ShaderData {
    BufferAddress data;
    const void* control;
};

struct CounterData {
    uint64_t counter;
    uint64_t timestamp;
};

struct CopyRegion {
    int xoffset;
    int yoffset;
    int zoffset;
    int width;
    int height;
    int depth;
};

struct PackagedTextureLayout {
    char layout[8];
};

struct BufferRange {
    BufferAddress address;
    uint64_t size;
};

// forward declarations of nvn types
class CommandBuffer;
class Window;
class WindowBuilder;
class Sync;
class MemoryPool;
class BlendState;
class ChannelMaskState;
class ColorState;
class MultisampleState;
class PolygonState;
class DepthStencilState;
class VertexAttribState;
class VertexStreamState;
class Program;
class Texture;
class TextureBuilder;
class TextureView;
class TexturePool;
class Sampler;
class SamplerBuilder;
class SamplerPool;
class Event;

typedef void (*GenericFuncPtrFunc)();
typedef void (*DebugCallbackFunc)(DebugCallbackSource::Enum, DebugCallbackType::Enum, int,
                                  DebugCallbackSeverity::Enum, const char*, void*);
typedef void (*CommandBufferMemoryCallbackFunc)(CommandBuffer*, CommandBufferMemoryEvent::Enum,
                                                size_t, void*);
typedef void (*WalkDebugDatabaseCallbackFunc)(void*, void*);

class DeviceBuilder {
protected:
    char reserved[64];

public:
    void SetDefaults();
    void SetFlags(DeviceFlagBits);
    DeviceFlagBits GetFlags() const;
};

class Device {
protected:
    char reserved[12288];

    Device(const Device&) = delete;
    const Device& operator=(const Device&) = delete;

public:
    Device() {}

    NVNboolean Initialize(const DeviceBuilder*);
    void Finalize();
    void SetDebugLabel(const char*);
    GenericFuncPtrFunc GetProcAddress(const char*) const;
    void GetInteger(DeviceInfo, int*) const;
    uint64_t GetCurrentTimestampInNanoseconds() const;
    void SetIntermediateShaderCache(int);
    TextureHandle GetTextureHandle(int, int) const;
    TextureHandle GetTexelFetchHandle(int) const;
    ImageHandle GetImageHandle(int) const;
    void InstallDebugCallback(const DebugCallbackFunc, void*, NVNboolean);
    NVNdebugDomainId GenerateDebugDomainId(const char*) const;
    void SetWindowOriginMode(WindowOriginMode);
    void SetDepthMode(DepthMode);
    NVNboolean RegisterFastClearColor(const float*, Format);
    NVNboolean RegisterFastClearColori(const int*, Format);
    NVNboolean RegisterFastClearColorui(const uint32_t*, Format);
    NVNboolean RegisterFastClearDepth(float);
    WindowOriginMode GetWindowOriginMode() const;
    DepthMode GetDepthMode() const;
    uint64_t GetTimestampInNanoseconds(const CounterData*) const;
    void ApplyDeferredFinalizes(int);
    void FinalizeCommandHandle(CommandHandle);
    void WalkDebugDatabase(DebugObjectType, WalkDebugDatabaseCallbackFunc, void*) const;
    SeparateTextureHandle GetSeparateTextureHandle(int) const;
    SeparateTextureHandle getSeparateTextureHandle(int) const;
    SeparateSamplerHandle GetSeparateSamplerHandle(int) const;
    SeparateSamplerHandle getSeparateSamplerHandle(int) const;
    NVNboolean IsExternalDebuggerAttached() const;
};

class QueueBuilder {
protected:
    char reserved[64];

public:
    QueueBuilder& SetDevice(Device*);
    QueueBuilder& SetDefaults();
    QueueBuilder& SetFlags(QueueFlags);
    QueueBuilder& SetCommandMemorySize(size_t);
    QueueBuilder& SetComputeMemorySize(size_t);
    QueueBuilder& SetControlMemorySize(size_t);
    size_t GetQueueMemorySize() const;
    QueueBuilder& SetQueueMemory(void*, size_t);
    QueueBuilder& SetCommandFlushThreshold(size_t);
    /* from dark2
    QueueBuilder& SetQueuePriority(const QueuePriority);
    QueuePriority GetQueuePriority() const;
    */
    const Device* GetDevice() const;
    int GetFlags() const;
    NVNboolean GetCommandMemorySize(int*) const;
    NVNboolean GetComputeMemorySize(int*) const;
    NVNboolean GetControlMemorySize(int*) const;
    NVNboolean GetCommandFlushThreshold(int*) const;
    int GetMemorySize() const;
    void* GetMemory() const;
};

class Queue {
protected:
    char reserved[8192];

    Queue(const Queue&) = delete;
    const Queue& operator=(const Queue&) = delete;

public:
    Queue() {}

    QueueGetErrorResult GetError(QueueErrorInfo*);
    size_t GetTotalCommandMemoryUsed();
    size_t GetTotalControlMemoryUsed();
    size_t GetTotalComputeMemoryUsed();
    void ResetMemoryUsageCounts();
    NVNboolean Initialize(const QueueBuilder*);
    void Finalize();
    void SetDebugLabel(const char*);
    void SubmitCommands(int, const CommandHandle*);
    void Flush();
    void Finish();
    void PresentTexture(Window*, int);
    QueueAcquireTextureResult AcquireTexture(Window*, int*);
    void FenceSync(Sync*, SyncCondition, SyncFlagBits);
    NVNboolean WaitSync(const Sync*);
};

class CommandBuffer {
protected:
    char reserved[160];

    CommandBuffer(const CommandBuffer&) = delete;
    const CommandBuffer& operator=(const CommandBuffer&) = delete;

public:
    CommandBuffer() {}

    NVNboolean Initialize(Device*);
    void Finalize();
    void SetDebugLabel(const char*);
    void SetMemoryCallback(CommandBufferMemoryCallbackFunc);
    void SetMemoryCallbackData(void*);
    void AddCommandMemory(const MemoryPool*, ptrdiff_t, size_t);
    void AddControlMemory(void*, size_t);
    size_t GetCommandMemorySize() const;
    size_t GetCommandMemoryUsed() const;
    size_t GetCommandMemoryFree() const;
    size_t GetControlMemorySize() const;
    size_t GetControlMemoryUsed() const;
    size_t GetControlMemoryFree() const;
    void BeginRecording();
    CommandHandle EndRecording();
    void CallCommands(int, const CommandHandle*);
    void CopyCommands(int, const CommandHandle*);
    void BindBlendState(const BlendState*);
    void BindChannelMaskState(const ChannelMaskState*);
    void BindColorState(const ColorState*);
    void BindMultisampleState(const MultisampleState*);
    void BindPolygonState(const PolygonState*);
    void BindDepthStencilState(const DepthStencilState*);
    void BindVertexAttribState(int, const VertexAttribState*);
    void BindVertexStreamState(int, const VertexStreamState*);
    void BindProgram(const Program*, ShaderStageBits);
    void BindVertexBuffer(int, BufferAddress, size_t);
    void BindVertexBuffers(int, int, const BufferRange*);
    void BindUniformBuffer(ShaderStage, int, BufferAddress, size_t);
    void BindUniformBuffers(ShaderStage, int, int, const BufferRange*);
    void BindTransformFeedbackBuffer(int, BufferAddress, size_t);
    void BindTransformFeedbackBuffers(int, int, const BufferRange*);
    void BindStorageBuffer(ShaderStage, int, BufferAddress, size_t);
    void BindStorageBuffers(ShaderStage, int, int, const BufferRange*);
    void BindTexture(ShaderStage, int, TextureHandle);
    void BindTextures(ShaderStage, int, int, const TextureHandle*);
    void BindImage(ShaderStage, int, ImageHandle);
    void BindImages(ShaderStage, int, int, const ImageHandle*);
    void SetPatchSize(int);
    void SetInnerTessellationLevels(const float*);
    void SetOuterTessellationLevels(const float*);
    void SetPrimitiveRestart(NVNboolean, int);
    void BeginTransformFeedback(BufferAddress);
    void EndTransformFeedback(BufferAddress);
    void PauseTransformFeedback(BufferAddress);
    void ResumeTransformFeedback(BufferAddress);
    void DrawTransformFeedback(DrawPrimitive, BufferAddress);
    void DrawArrays(DrawPrimitive, int, int);
    void DrawElements(DrawPrimitive, IndexType, int, BufferAddress);
    void DrawElementsBaseVertex(DrawPrimitive, IndexType, int, BufferAddress, int);
    void DrawArraysInstanced(DrawPrimitive, int, int, int, int);
    void DrawElementsInstanced(DrawPrimitive, IndexType, int, BufferAddress, int, int, int);
    void DrawArraysIndirect(DrawPrimitive, BufferAddress);
    void DrawElementsIndirect(DrawPrimitive, IndexType, BufferAddress, BufferAddress);
    void MultiDrawArraysIndirectCount(DrawPrimitive, BufferAddress, BufferAddress, int, ptrdiff_t);
    void MultiDrawElementsIndirectCount(DrawPrimitive, IndexType, BufferAddress, BufferAddress,
                                        BufferAddress, int, ptrdiff_t);
    void ClearColor(int, const float*, ClearColorMask);
    void ClearColori(int, const int*, ClearColorMask);
    void ClearColorui(int, const uint32_t*, ClearColorMask);
    void ClearDepthStencil(float, NVNboolean, int, int);
    void DispatchCompute(int, int, int);
    void DispatchComputeIndirect(BufferAddress);
    void SetViewport(int, int, int, int);
    void SetViewports(int, int, const float*);
    void SetViewportSwizzles(int, int, const ViewportSwizzle*);
    void SetScissor(int, int, int, int);
    void SetScissors(int, int, const int*);
    void SetDepthRange(float, float);
    void SetDepthBounds(NVNboolean, float, float);
    void SetDepthRanges(int, int, const float*);
    void SetTiledCacheAction(TiledCacheAction);
    void SetTiledCacheTileSize(int, int);
    void BindSeparateTexture(ShaderStage, int, SeparateTextureHandle);
    void bindSeparateTexture(ShaderStage, int, SeparateTextureHandle);
    void BindSeparateSampler(ShaderStage, int, SeparateSamplerHandle);
    void bindSeparateSampler(ShaderStage, int, SeparateSamplerHandle);
    void BindSeparateTextures(ShaderStage, int, int, const SeparateTextureHandle*);
    void BindSeparateSamplers(ShaderStage, int, int, const SeparateSamplerHandle*);
    void SetStencilValueMask(Face, int);
    void SetStencilMask(Face, int);
    void SetStencilRef(Face, int);
    void SetBlendColor(const float*);
    void SetPointSize(float);
    void SetLineWidth(float);
    void SetPolygonOffsetClamp(float, float, float);
    void SetAlphaRef(float);
    void SetSampleMask(int);
    void SetRasterizerDiscard(NVNboolean);
    void SetDepthClamp(NVNboolean);
    void SetConservativeRasterEnable(NVNboolean);
    void SetConservativeRasterDilate(float);
    void SetSubpixelPrecisionBias(int, int);
    void CopyBufferToTexture(BufferAddress, const Texture*, const TextureView*, const CopyRegion*,
                             CopyFlags);
    void CopyTextureToBuffer(const Texture*, const TextureView*, const CopyRegion*, BufferAddress,
                             CopyFlags);
    void CopyTextureToTexture(const Texture*, const TextureView*, const CopyRegion*, const Texture*,
                              const TextureView*, const CopyRegion*, CopyFlags);
    void CopyBufferToBuffer(BufferAddress, BufferAddress, size_t, CopyFlags);
    void ClearBuffer(BufferAddress, size_t, uint32_t);
    void ClearTexture(const Texture*, const TextureView*, const CopyRegion*, const float*,
                      ClearColorMask);
    void ClearTexturei(const Texture*, const TextureView*, const CopyRegion*, const int*,
                       ClearColorMask);
    void ClearTextureui(const Texture*, const TextureView*, const CopyRegion*, const uint32_t*,
                        ClearColorMask);
    void UpdateUniformBuffer(BufferAddress, size_t, ptrdiff_t, size_t, const void*);
    void ReportCounter(CounterType, BufferAddress);
    void ResetCounter(CounterType);
    void ReportValue(uint32_t, BufferAddress);
    void SetRenderEnable(NVNboolean);
    void SetRenderEnableConditional(ConditionalRenderMode, BufferAddress);
    void SetRenderTargets(int, const Texture* const*, const TextureView* const*, const Texture*,
                          const TextureView*);
    void DiscardColor(int);
    void DiscardDepthStencil();
    void Downsample(const Texture*, const Texture*);
    void TiledDownsample(const Texture*, const Texture*);
    void DownsampleTextureView(const Texture*, const TextureView*, const Texture*,
                               const TextureView*);
    void TiledDownsampleTextureView(const Texture*, const TextureView*, const Texture*,
                                    const TextureView*);
    void Barrier(BarrierBits);
    void WaitSync(const Sync*);
    void FenceSync(Sync*, SyncCondition, SyncFlagBits);
    void SetTexturePool(const TexturePool*);
    void SetSamplerPool(const SamplerPool*);
    void SetShaderScratchMemory(const MemoryPool*, ptrdiff_t, size_t);
    void SaveZCullData(BufferAddress, size_t);
    void RestoreZCullData(BufferAddress, size_t);
    void SetCopyRowStride(ptrdiff_t);
    void SetCopyImageStride(ptrdiff_t);
    ptrdiff_t GetCopyRowStride() const;
    ptrdiff_t GetCopyImageStride() const;
    void DrawTexture(TextureHandle, const DrawTextureRegion*, const DrawTextureRegion*);
    void SetProgramSubroutines(Program*, ShaderStage, const int, const int, const int*);
    void BindCoverageModulationTable(const float*);
    void ResolveDepthBuffer();
    void SetColorReductionEnable(NVNboolean);
    void SetColorReductionThresholds(FormatClass, int, int);
    void PushDebugGroupStatic(uint32_t, const char*);
    void PushDebugGroupDynamic(uint32_t, const char*);
    void PushDebugGroup(const char*);
    void PopDebugGroup();
    void PopDebugGroupId(uint32_t);
    void InsertDebugMarkerStatic(uint32_t, const char*);
    void InsertDebugMarkerDynamic(uint32_t, const char*);
    void InsertDebugMarker(const char*);
    CommandBufferMemoryCallbackFunc GetMemoryCallback() const;
    void* GetMemoryCallbackData() const;
    NVNboolean IsRecording() const;
    void WaitEvent(const Event*, EventWaitMode, uint32_t);
    void SignalEvent(const Event*, EventSignalMode, EventSignalLocation, EventSignalFlags,
                     uint32_t);
    void SetStencilCullCriteria(StencilFunc, int, int);
};

class BlendState {
protected:
    char reserved[8];

public:
    BlendState& SetDefaults();
    BlendState& SetBlendTarget(int);
    BlendState& SetBlendFunc(BlendFunc, BlendFunc, BlendFunc, BlendFunc);
    BlendState& SetBlendEquation(BlendEquation, BlendEquation);
    BlendState& SetAdvancedMode(BlendAdvancedMode);
    BlendState& SetAdvancedOverlap(BlendAdvancedOverlap);
    BlendState& SetAdvancedPremultipliedSrc(NVNboolean);
    BlendState& SetAdvancedNormalizedDst(NVNboolean);
    int GetBlendTarget() const;
    void GetBlendFunc(BlendFunc*, BlendFunc*, BlendFunc*, BlendFunc*) const;
    void GetBlendEquation(BlendEquation*, BlendEquation*) const;
    BlendAdvancedMode GetAdvancedMode() const;
    BlendAdvancedOverlap GetAdvancedOverlap() const;
    NVNboolean GetAdvancedPremultipliedSrc() const;
    NVNboolean GetAdvancedNormalizedDst() const;
};

class ChannelMaskState {
protected:
    char reserved[4];

public:
    ChannelMaskState& SetDefaults();
    ChannelMaskState& SetChannelMask(int, NVNboolean, NVNboolean, NVNboolean, NVNboolean);
    void GetChannelMask(int, NVNboolean*, NVNboolean*, NVNboolean*, NVNboolean*) const;
};

class ColorState {
protected:
    char reserved[4];

public:
    ColorState& SetDefaults();
    ColorState& SetBlendEnable(int, NVNboolean);
    ColorState& SetLogicOp(LogicOp);
    ColorState& SetAlphaTest(AlphaFunc);
    NVNboolean GetBlendEnable(int) const;
    LogicOp GetLogicOp() const;
    AlphaFunc GetAlphaTest() const;
};

class DepthStencilState {
protected:
    char reserved[8];

public:
    DepthStencilState& SetDefaults();
    DepthStencilState& SetDepthTestEnable(NVNboolean);
    DepthStencilState& SetDepthWriteEnable(NVNboolean);
    DepthStencilState& SetDepthFunc(DepthFunc);
    DepthStencilState& SetStencilTestEnable(NVNboolean);
    DepthStencilState& SetStencilFunc(Face, StencilFunc);
    DepthStencilState& SetStencilOp(Face, StencilOp, StencilOp, StencilOp);
    NVNboolean GetDepthTestEnable() const;
    NVNboolean GetDepthWriteEnable() const;
    DepthFunc GetDepthFunc() const;
    NVNboolean GetStencilTestEnable() const;
    StencilFunc GetStencilFunc(Face) const;
    void GetStencilOp(Face, StencilOp*, StencilOp*, StencilOp*) const;
};

class MultisampleState {
protected:
    char reserved[24];

public:
    MultisampleState& SetDefaults();
    MultisampleState& SetMultisampleEnable(NVNboolean);
    MultisampleState& SetSamples(int);
    MultisampleState& SetAlphaToCoverageEnable(NVNboolean);
    MultisampleState& SetAlphaToCoverageDither(NVNboolean);
    NVNboolean GetMultisampleEnable() const;
    int GetSamples() const;
    NVNboolean GetAlphaToCoverageEnable() const;
    NVNboolean GetAlphaToCoverageDither() const;
    MultisampleState& SetRasterSamples(int);
    int GetRasterSamples();
    MultisampleState& SetCoverageModulationMode(CoverageModulationMode);
    CoverageModulationMode GetCoverageModulationMode() const;
    MultisampleState& SetCoverageToColorEnable(NVNboolean);
    NVNboolean GetCoverageToColorEnable() const;
    MultisampleState& SetCoverageToColorOutput(int);
    int GetCoverageToColorOutput() const;
    MultisampleState& SetSampleLocationsEnable(NVNboolean);
    NVNboolean GetSampleLocationsEnable() const;
    void GetSampleLocationsGrid(int*, int*);
    MultisampleState& SetSampleLocationsGridEnable(NVNboolean);
    NVNboolean GetSampleLocationsGridEnable() const;
    MultisampleState& SetSampleLocations(int, int, const float*);
};

class PolygonState {
protected:
    char reserved[4];

public:
    PolygonState& SetDefaults();
    PolygonState& SetCullFace(Face);
    PolygonState& SetFrontFace(FrontFace);
    PolygonState& SetPolygonMode(PolygonMode);
    PolygonState& SetPolygonOffsetEnables(PolygonOffsetEnable);
    Face GetCullFace() const;
    FrontFace GetFrontFace() const;
    PolygonMode GetPolygonMode() const;
    PolygonOffsetEnable GetPolygonOffsetEnables() const;
};

class VertexAttribState {
protected:
    char reserved[4];

public:
    VertexAttribState& SetDefaults();
    VertexAttribState& SetFormat(Format, ptrdiff_t);
    VertexAttribState& SetStreamIndex(int);
    void GetFormat(Format*, ptrdiff_t*) const;
    int GetStreamIndex() const;
};

class VertexStreamState {
protected:
    char reserved[8];

public:
    VertexStreamState& SetDefaults();
    VertexStreamState& SetStride(ptrdiff_t);
    VertexStreamState& SetDivisor(int);
    ptrdiff_t GetStride() const;
    int GetDivisor() const;
};

class Program {
protected:
    char reserved[192];

    Program(const Program&) = delete;
    const Program& operator=(const Program&) = delete;

public:
    Program() {}

    NVNboolean Initialize(Device*);
    void Finalize();
    void SetDebugLabel(const char*);
    NVNboolean SetShaders(int, const ShaderData*);
    /* from dark2
    NVNboolean SetShadersExt(int, const ShaderDataExt*);
    void SetSampleShading(SampleShadingMode);
    */
    NVNboolean SetSubroutineLinkage(int, const NVNsubroutineLinkageMapPtr*);
};

class MemoryPoolBuilder {
protected:
    char reserved[64];

public:
    MemoryPoolBuilder& SetDevice(Device*);
    MemoryPoolBuilder& SetDefaults();
    MemoryPoolBuilder& SetStorage(void*, size_t);
    MemoryPoolBuilder& SetFlags(MemoryPoolFlags);
    const Device* GetDevice() const;
    void* GetMemory() const;
    size_t GetSize() const;
    MemoryPoolFlags GetFlags() const;
};

class MemoryPool {
protected:
    char reserved[256];

    MemoryPool(const MemoryPool&) = delete;
    const MemoryPool& operator=(const MemoryPool&) = delete;

public:
    MemoryPool() {}

    NVNboolean Initialize(const MemoryPoolBuilder*);
    void SetDebugLabel(const char*);
    void Finalize();
    void* Map() const;
    void FlushMappedRange(ptrdiff_t, size_t) const;
    void InvalidateMappedRange(ptrdiff_t, size_t) const;
    BufferAddress GetBufferAddress() const;
    NVNboolean MapVirtual(int, const MappingRequest*);
    size_t GetSize() const;
    MemoryPoolFlags GetFlags() const;
};

class TexturePool {
protected:
    char reserved[32];

    TexturePool(const TexturePool&) = delete;
    const TexturePool& operator=(const TexturePool&) = delete;

public:
    TexturePool() {}

    NVNboolean Initialize(const MemoryPool*, ptrdiff_t, int);
    void SetDebugLabel(const char*);
    void Finalize();
    void RegisterTexture(int, const Texture*, const TextureView*) const;
    void RegisterImage(int, const Texture*, const TextureView*) const;
    const MemoryPool* GetMemoryPool() const;
    ptrdiff_t GetMemoryOffset() const;
    int GetSize() const;
};

class SamplerPool {
protected:
    char reserved[32];

    SamplerPool(const SamplerPool&) = delete;
    const SamplerPool& operator=(const SamplerPool&) = delete;

public:
    SamplerPool() {}

    NVNboolean Initialize(const MemoryPool*, ptrdiff_t, int);
    void SetDebugLabel(const char*);
    void Finalize();
    void RegisterSampler(int, const Sampler*) const;
    void RegisterSamplerBuilder(int, const SamplerBuilder*) const;
    const MemoryPool* GetMemoryPool() const;
    ptrdiff_t GetMemoryOffset() const;
    int GetSize() const;
};

class BufferBuilder {
protected:
    char reserved[64];

public:
    BufferBuilder& SetDevice(Device*);
    BufferBuilder& SetDefaults();
    BufferBuilder& SetStorage(MemoryPool*, ptrdiff_t, size_t);
    const Device* GetDevice() const;
    MemoryPool* GetMemoryPool() const;
    ptrdiff_t GetMemoryOffset() const;
    size_t GetSize() const;
};

class Buffer {
protected:
    char reserved[48];

    Buffer(const Buffer&) = delete;
    const Buffer& operator=(const Buffer&) = delete;

public:
    Buffer() {}

    NVNboolean Initialize(const BufferBuilder*);
    void SetDebugLabel(const char*);
    void Finalize();
    void* Map() const;
    BufferAddress GetAddress() const;
    void FlushMappedRange(ptrdiff_t, size_t) const;
    void InvalidateMappedRange(ptrdiff_t, size_t) const;
    MemoryPool* GetMemoryPool() const;
    ptrdiff_t GetMemoryOffset() const;
    size_t GetSize() const;
    uint64_t GetDebugID() const;
};

class Texture {
protected:
    char reserved[192];

    Texture(const Texture&) = delete;
    const Texture& operator=(const Texture&) = delete;

public:
    Texture() {}

    NVNboolean Initialize(const TextureBuilder*);
    size_t GetZCullStorageSize() const;
    void Finalize();
    void SetDebugLabel(const char*);
    NVNstorageClass GetStorageClass() const;
    ptrdiff_t GetViewOffset(const TextureView*) const;
    TextureFlags GetFlags() const;
    TextureTarget GetTarget() const;
    int GetWidth() const;
    int GetHeight() const;
    int GetDepth() const;
    int GetLevels() const;
    Format GetFormat() const;
    int GetSamples() const;
    void GetSwizzle(TextureSwizzle*, TextureSwizzle*, TextureSwizzle*, TextureSwizzle*) const;
    TextureDepthStencilMode GetDepthStencilMode() const;
    ptrdiff_t GetStride() const;
    TextureAddress GetTextureAddress() const;
    void GetSparseTileLayout(TextureSparseTileLayout*) const;
    void WriteTexels(const TextureView*, const CopyRegion*, const void*) const;
    void WriteTexelsStrided(const TextureView*, const CopyRegion*, const void*, ptrdiff_t,
                            ptrdiff_t) const;
    void ReadTexels(const TextureView*, const CopyRegion*, void*) const;
    void ReadTexelsStrided(const TextureView*, const CopyRegion*, void*, ptrdiff_t,
                           ptrdiff_t) const;
    void FlushTexels(const TextureView*, const CopyRegion*) const;
    void InvalidateTexels(const TextureView*, const CopyRegion*) const;
    MemoryPool* GetMemoryPool() const;
    ptrdiff_t GetMemoryOffset() const;
    int GetStorageSize() const;
    NVNboolean Compare(const Texture*) const;
    uint64_t GetDebugID() const;

    /* from dark2
    RawStorageClass GetRawStorageClass() const;
    */
};

class TextureBuilder {
protected:
    char reserved[128];

public:
    TextureBuilder& SetDevice(Device*);
    TextureBuilder& SetDefaults();
    TextureBuilder& SetFlags(TextureFlags);
    TextureBuilder& SetTarget(TextureTarget);
    TextureBuilder& SetWidth(int);
    TextureBuilder& SetHeight(int);
    TextureBuilder& SetDepth(int);
    TextureBuilder& SetSize1D(int);
    TextureBuilder& SetSize2D(int, int);
    TextureBuilder& SetSize3D(int, int, int);
    TextureBuilder& SetLevels(int);
    TextureBuilder& SetFormat(Format);
    TextureBuilder& SetSamples(int);
    TextureBuilder& SetSwizzle(TextureSwizzle, TextureSwizzle, TextureSwizzle, TextureSwizzle);
    TextureBuilder& SetDepthStencilMode(TextureDepthStencilMode);
    size_t GetStorageSize() const;
    size_t GetStorageAlignment() const;
    TextureBuilder& SetStorage(MemoryPool*, ptrdiff_t);
    TextureBuilder& SetPackagedTextureData(const void*);
    TextureBuilder& SetPackagedTextureLayout(const PackagedTextureLayout*);
    TextureBuilder& SetStride(ptrdiff_t);
    TextureBuilder& SetGLTextureName(uint32_t);
    NVNstorageClass GetStorageClass() const;
    const Device* GetDevice() const;
    TextureFlags GetFlags() const;
    TextureTarget GetTarget() const;
    int GetWidth() const;
    int GetHeight() const;
    int GetDepth() const;
    int GetLevels() const;
    Format GetFormat() const;
    int GetSamples() const;
    void GetSwizzle(TextureSwizzle*, TextureSwizzle*, TextureSwizzle*, TextureSwizzle*) const;
    TextureDepthStencilMode GetDepthStencilMode() const;
    const void* GetPackagedTextureData() const;
    NVNboolean GetPackagedTextureLayout(PackagedTextureLayout*) const;
    ptrdiff_t GetStride() const;
    void GetSparseTileLayout(TextureSparseTileLayout*) const;
    uint32_t GetGLTextureName() const;
    size_t GetZCullStorageSize() const;
    MemoryPool* GetMemoryPool() const;
    ptrdiff_t GetMemoryOffset() const;

    /* from dark2
    RawStorageClass GetRawStorageClass() const;
    */
};

class TextureView {
protected:
    char reserved[40];

public:
    TextureView& SetDefaults();
    TextureView& SetLevels(int, int);
    TextureView& SetLayers(int, int);
    TextureView& SetFormat(Format);
    TextureView& SetSwizzle(TextureSwizzle, TextureSwizzle, TextureSwizzle, TextureSwizzle);
    TextureView& SetDepthStencilMode(TextureDepthStencilMode);
    TextureView& SetTarget(TextureTarget);
    NVNboolean GetLevels(int*, int*) const;
    NVNboolean GetLayers(int*, int*) const;
    NVNboolean GetFormat(Format*) const;
    NVNboolean GetSwizzle(TextureSwizzle*, TextureSwizzle*, TextureSwizzle*, TextureSwizzle*) const;
    NVNboolean GetDepthStencilMode(TextureDepthStencilMode*) const;
    NVNboolean GetTarget(TextureTarget*) const;
    NVNboolean Compare(const TextureView*) const;
};

class SamplerBuilder {
protected:
    char reserved[96];

public:
    SamplerBuilder& SetDevice(Device*);
    SamplerBuilder& SetDefaults();
    SamplerBuilder& SetMinMagFilter(MinFilter, MagFilter);
    SamplerBuilder& SetWrapMode(WrapMode, WrapMode, WrapMode);
    SamplerBuilder& SetLodClamp(float, float);
    SamplerBuilder& SetLodBias(float);
    SamplerBuilder& SetCompare(CompareMode, CompareFunc);
    SamplerBuilder& SetBorderColor(const float*);
    SamplerBuilder& SetBorderColori(const int*);
    SamplerBuilder& SetBorderColorui(const uint32_t*);
    SamplerBuilder& SetMaxAnisotropy(float);
    SamplerBuilder& SetReductionFilter(SamplerReduction);
    SamplerBuilder& SetLodSnap(float);
    const Device* GetDevice() const;
    void GetMinMagFilter(MinFilter*, MagFilter*) const;
    void GetWrapMode(WrapMode*, WrapMode*, WrapMode*) const;
    void GetLodClamp(float*, float*) const;
    float GetLodBias() const;
    void GetCompare(CompareMode*, CompareFunc*) const;
    void GetBorderColor(float*) const;
    void GetBorderColori(int*) const;
    void GetBorderColorui(uint32_t*) const;
    float GetMaxAnisotropy() const;
    SamplerReduction GetReductionFilter() const;
    float GetLodSnap() const;
};

class Sampler {
protected:
    char reserved[96];

    Sampler(const Sampler&) = delete;
    const Sampler& operator=(const Sampler&) = delete;

public:
    Sampler() {}

    NVNboolean Initialize(const SamplerBuilder*);
    void Finalize();
    void SetDebugLabel(const char*);
    void GetMinMagFilter(MinFilter*, MagFilter*) const;
    void GetWrapMode(WrapMode*, WrapMode*, WrapMode*) const;
    void GetLodClamp(float*, float*) const;
    float GetLodBias() const;
    void GetCompare(CompareMode*, CompareFunc*) const;
    void GetBorderColor(float*) const;
    void GetBorderColori(int*) const;
    void GetBorderColorui(uint32_t*) const;
    float GetMaxAnisotropy() const;
    SamplerReduction GetReductionFilter() const;
    NVNboolean Compare(const Sampler*) const;
    uint64_t GetDebugID() const;
};

class Sync {
protected:
    char reserved[64];

    Sync(const Sync&) = delete;
    const Sync& operator=(const Sync&) = delete;

public:
    Sync() {}

    NVNboolean Initialize(Device*);
    void Finalize();
    void SetDebugLabel(const char*);
    SyncWaitResult Wait(uint64_t) const;
};

class Window {
protected:
    char reserved[384];

    Window(const Window&) = delete;
    const Window& operator=(const Window&) = delete;

public:
    Window() {}

    NVNboolean Initialize(const WindowBuilder*);
    void Finalize();
    void SetDebugLabel(const char*);
    WindowAcquireTextureResult AcquireTexture(Sync*, int*);
    NVNnativeWindow GetNativeWindow() const;
    int GetPresentInterval() const;
    void SetPresentInterval(int);
    void SetCrop(int, int, int, int);
    void GetCrop(Rectangle*) const;
};

class WindowBuilder {
protected:
    char reserved[64];

public:
    WindowBuilder& SetDevice(Device*);
    WindowBuilder& SetDefaults();
    WindowBuilder& SetNativeWindow(NVNnativeWindow);
    WindowBuilder& SetTextures(int, Texture* const*);
    WindowBuilder& SetPresentInterval(int);
    const Device* GetDevice() const;
    int GetNumTextures() const;
    const Texture* GetTexture(int) const;
    NVNnativeWindow GetNativeWindow() const;
    int GetPresentInterval() const;
};

class EventBuilder {
protected:
    char reserved[32];

public:
    EventBuilder& SetDefaults();
    EventBuilder& SetStorage(const MemoryPool*, int64_t);
    const MemoryPool* GetStorage(int64_t*) const;
};

class Event {
protected:
    char reserved[64];

    Event(const Event&) = delete;
    const Event& operator=(const Event&) = delete;

public:
    Event() {}

    NVNboolean Initialize(const EventBuilder*);
    void Finalize();
    uint32_t GetValue() const;
    void Signal(EventSignalMode, uint32_t);
};

typedef void (*DeviceBuilderSetDefaultsFunc)(DeviceBuilder*);
typedef void (*DeviceBuilderSetFlagsFunc)(DeviceBuilder*, int);
typedef int (*DeviceBuilderGetFlagsFunc)(const DeviceBuilder*);
typedef NVNboolean (*DeviceInitializeFunc)(Device*, const DeviceBuilder*);
typedef void (*DeviceFinalizeFunc)(Device*);
typedef void (*DeviceSetDebugLabelFunc)(Device*, const char*);
typedef GenericFuncPtrFunc (*DeviceGetProcAddressFunc)(const Device*, const char*);
typedef void (*DeviceGetIntegerFunc)(const Device*, DeviceInfo::Enum, int*);
typedef uint64_t (*DeviceGetCurrentTimestampInNanosecondsFunc)(const Device*);
typedef void (*DeviceSetIntermediateShaderCacheFunc)(Device*, int);
typedef TextureHandle (*DeviceGetTextureHandleFunc)(const Device*, int, int);
typedef TextureHandle (*DeviceGetTexelFetchHandleFunc)(const Device*, int);
typedef ImageHandle (*DeviceGetImageHandleFunc)(const Device*, int);
typedef void (*DeviceInstallDebugCallbackFunc)(Device*, const DebugCallbackFunc, void*, NVNboolean);
typedef NVNdebugDomainId (*DeviceGenerateDebugDomainIdFunc)(const Device*, const char*);
typedef void (*DeviceSetWindowOriginModeFunc)(Device*, WindowOriginMode::Enum);
typedef void (*DeviceSetDepthModeFunc)(Device*, DepthMode::Enum);
typedef NVNboolean (*DeviceRegisterFastClearColorFunc)(Device*, const float*, Format::Enum);
typedef NVNboolean (*DeviceRegisterFastClearColoriFunc)(Device*, const int*, Format::Enum);
typedef NVNboolean (*DeviceRegisterFastClearColoruiFunc)(Device*, const uint32_t*, Format::Enum);
typedef NVNboolean (*DeviceRegisterFastClearDepthFunc)(Device*, float);
typedef WindowOriginMode::Enum (*DeviceGetWindowOriginModeFunc)(const Device*);
typedef DepthMode::Enum (*DeviceGetDepthModeFunc)(const Device*);
typedef uint64_t (*DeviceGetTimestampInNanosecondsFunc)(const Device*, const CounterData*);
typedef void (*DeviceApplyDeferredFinalizesFunc)(Device*, int);
typedef void (*DeviceFinalizeCommandHandleFunc)(Device*, CommandHandle);
typedef void (*DeviceWalkDebugDatabaseFunc)(const Device*, DebugObjectType::Enum,
                                            WalkDebugDatabaseCallbackFunc, void*);
typedef SeparateTextureHandle (*DeviceGetSeparateTextureHandleFunc)(const Device*, int);
typedef SeparateSamplerHandle (*DeviceGetSeparateSamplerHandleFunc)(const Device*, int);
typedef NVNboolean (*DeviceIsExternalDebuggerAttachedFunc)(const Device*);
typedef QueueGetErrorResult::Enum (*QueueGetErrorFunc)(Queue*, QueueErrorInfo*);
typedef size_t (*QueueGetTotalCommandMemoryUsedFunc)(Queue*);
typedef size_t (*QueueGetTotalControlMemoryUsedFunc)(Queue*);
typedef size_t (*QueueGetTotalComputeMemoryUsedFunc)(Queue*);
typedef void (*QueueResetMemoryUsageCountsFunc)(Queue*);
typedef void (*QueueBuilderSetDeviceFunc)(QueueBuilder*, Device*);
typedef void (*QueueBuilderSetDefaultsFunc)(QueueBuilder*);
typedef void (*QueueBuilderSetFlagsFunc)(QueueBuilder*, int);
typedef void (*QueueBuilderSetCommandMemorySizeFunc)(QueueBuilder*, size_t);
typedef void (*QueueBuilderSetComputeMemorySizeFunc)(QueueBuilder*, size_t);
typedef void (*QueueBuilderSetControlMemorySizeFunc)(QueueBuilder*, size_t);
typedef size_t (*QueueBuilderGetQueueMemorySizeFunc)(const QueueBuilder*);
typedef void (*QueueBuilderSetQueueMemoryFunc)(QueueBuilder*, void*, size_t);
typedef void (*QueueBuilderSetCommandFlushThresholdFunc)(QueueBuilder*, size_t);
typedef const Device* (*QueueBuilderGetDeviceFunc)(const QueueBuilder*);
typedef int (*QueueBuilderGetFlagsFunc)(const QueueBuilder*);
typedef NVNboolean (*QueueBuilderGetCommandMemorySizeFunc)(const QueueBuilder*, int*);
typedef NVNboolean (*QueueBuilderGetComputeMemorySizeFunc)(const QueueBuilder*, int*);
typedef NVNboolean (*QueueBuilderGetControlMemorySizeFunc)(const QueueBuilder*, int*);
typedef NVNboolean (*QueueBuilderGetCommandFlushThresholdFunc)(const QueueBuilder*, int*);
typedef int (*QueueBuilderGetMemorySizeFunc)(const QueueBuilder*);
typedef void* (*QueueBuilderGetMemoryFunc)(const QueueBuilder*);
typedef NVNboolean (*QueueInitializeFunc)(Queue*, const QueueBuilder*);
typedef void (*QueueFinalizeFunc)(Queue*);
typedef void (*QueueSetDebugLabelFunc)(Queue*, const char*);
typedef void (*QueueSubmitCommandsFunc)(Queue*, int, const CommandHandle*);
typedef void (*QueueFlushFunc)(Queue*);
typedef void (*QueueFinishFunc)(Queue*);
typedef void (*QueuePresentTextureFunc)(Queue*, Window*, int);
typedef QueueAcquireTextureResult::Enum (*QueueAcquireTextureFunc)(Queue*, Window*, int*);
typedef void (*WindowBuilderSetDeviceFunc)(WindowBuilder*, Device*);
typedef void (*WindowBuilderSetDefaultsFunc)(WindowBuilder*);
typedef void (*WindowBuilderSetNativeWindowFunc)(WindowBuilder*, NVNnativeWindow);
typedef void (*WindowBuilderSetTexturesFunc)(WindowBuilder*, int, Texture* const*);
typedef void (*WindowBuilderSetPresentIntervalFunc)(WindowBuilder*, int);
typedef const Device* (*WindowBuilderGetDeviceFunc)(const WindowBuilder*);
typedef int (*WindowBuilderGetNumTexturesFunc)(const WindowBuilder*);
typedef const Texture* (*WindowBuilderGetTextureFunc)(const WindowBuilder*, int);
typedef NVNnativeWindow (*WindowBuilderGetNativeWindowFunc)(const WindowBuilder*);
typedef int (*WindowBuilderGetPresentIntervalFunc)(const WindowBuilder*);
typedef NVNboolean (*WindowInitializeFunc)(Window*, const WindowBuilder*);
typedef void (*WindowFinalizeFunc)(Window*);
typedef void (*WindowSetDebugLabelFunc)(Window*, const char*);
typedef WindowAcquireTextureResult::Enum (*WindowAcquireTextureFunc)(Window*, Sync*, int*);
typedef NVNnativeWindow (*WindowGetNativeWindowFunc)(const Window*);
typedef int (*WindowGetPresentIntervalFunc)(const Window*);
typedef void (*WindowSetPresentIntervalFunc)(Window*, int);
typedef void (*WindowSetCropFunc)(Window*, int, int, int, int);
typedef void (*WindowGetCropFunc)(const Window*, Rectangle*);
typedef NVNboolean (*ProgramInitializeFunc)(Program*, Device*);
typedef void (*ProgramFinalizeFunc)(Program*);
typedef void (*ProgramSetDebugLabelFunc)(Program*, const char*);
typedef NVNboolean (*ProgramSetShadersFunc)(Program*, int, const ShaderData*);
typedef void (*MemoryPoolBuilderSetDeviceFunc)(MemoryPoolBuilder*, Device*);
typedef void (*MemoryPoolBuilderSetDefaultsFunc)(MemoryPoolBuilder*);
typedef void (*MemoryPoolBuilderSetStorageFunc)(MemoryPoolBuilder*, void*, size_t);
typedef void (*MemoryPoolBuilderSetFlagsFunc)(MemoryPoolBuilder*, int);
typedef const Device* (*MemoryPoolBuilderGetDeviceFunc)(const MemoryPoolBuilder*);
typedef void* (*MemoryPoolBuilderGetMemoryFunc)(const MemoryPoolBuilder*);
typedef size_t (*MemoryPoolBuilderGetSizeFunc)(const MemoryPoolBuilder*);
typedef int (*MemoryPoolBuilderGetFlagsFunc)(const MemoryPoolBuilder*);
typedef NVNboolean (*MemoryPoolInitializeFunc)(MemoryPool*, const MemoryPoolBuilder*);
typedef void (*MemoryPoolSetDebugLabelFunc)(MemoryPool*, const char*);
typedef void (*MemoryPoolFinalizeFunc)(MemoryPool*);
typedef void* (*MemoryPoolMapFunc)(const MemoryPool*);
typedef void (*MemoryPoolFlushMappedRangeFunc)(const MemoryPool*, ptrdiff_t, size_t);
typedef void (*MemoryPoolInvalidateMappedRangeFunc)(const MemoryPool*, ptrdiff_t, size_t);
typedef BufferAddress (*MemoryPoolGetBufferAddressFunc)(const MemoryPool*);
typedef NVNboolean (*MemoryPoolMapVirtualFunc)(MemoryPool*, int, const MappingRequest*);
typedef size_t (*MemoryPoolGetSizeFunc)(const MemoryPool*);
typedef int (*MemoryPoolGetFlagsFunc)(const MemoryPool*);
typedef NVNboolean (*TexturePoolInitializeFunc)(TexturePool*, const MemoryPool*, ptrdiff_t, int);
typedef void (*TexturePoolSetDebugLabelFunc)(TexturePool*, const char*);
typedef void (*TexturePoolFinalizeFunc)(TexturePool*);
typedef void (*TexturePoolRegisterTextureFunc)(const TexturePool*, int, const Texture*,
                                               const TextureView*);
typedef void (*TexturePoolRegisterImageFunc)(const TexturePool*, int, const Texture*,
                                             const TextureView*);
typedef const MemoryPool* (*TexturePoolGetMemoryPoolFunc)(const TexturePool*);
typedef ptrdiff_t (*TexturePoolGetMemoryOffsetFunc)(const TexturePool*);
typedef int (*TexturePoolGetSizeFunc)(const TexturePool*);
typedef NVNboolean (*SamplerPoolInitializeFunc)(SamplerPool*, const MemoryPool*, ptrdiff_t, int);
typedef void (*SamplerPoolSetDebugLabelFunc)(SamplerPool*, const char*);
typedef void (*SamplerPoolFinalizeFunc)(SamplerPool*);
typedef void (*SamplerPoolRegisterSamplerFunc)(const SamplerPool*, int, const Sampler*);
typedef void (*SamplerPoolRegisterSamplerBuilderFunc)(const SamplerPool*, int,
                                                      const SamplerBuilder*);
typedef const MemoryPool* (*SamplerPoolGetMemoryPoolFunc)(const SamplerPool*);
typedef ptrdiff_t (*SamplerPoolGetMemoryOffsetFunc)(const SamplerPool*);
typedef int (*SamplerPoolGetSizeFunc)(const SamplerPool*);
typedef void (*BufferBuilderSetDeviceFunc)(BufferBuilder*, Device*);
typedef void (*BufferBuilderSetDefaultsFunc)(BufferBuilder*);
typedef void (*BufferBuilderSetStorageFunc)(BufferBuilder*, MemoryPool*, ptrdiff_t, size_t);
typedef const Device* (*BufferBuilderGetDeviceFunc)(const BufferBuilder*);
typedef MemoryPool* (*BufferBuilderGetMemoryPoolFunc)(const BufferBuilder*);
typedef ptrdiff_t (*BufferBuilderGetMemoryOffsetFunc)(const BufferBuilder*);
typedef size_t (*BufferBuilderGetSizeFunc)(const BufferBuilder*);
typedef NVNboolean (*BufferInitializeFunc)(Buffer*, const BufferBuilder*);
typedef void (*BufferSetDebugLabelFunc)(Buffer*, const char*);
typedef void (*BufferFinalizeFunc)(Buffer*);
typedef void* (*BufferMapFunc)(const Buffer*);
typedef BufferAddress (*BufferGetAddressFunc)(const Buffer*);
typedef void (*BufferFlushMappedRangeFunc)(const Buffer*, ptrdiff_t, size_t);
typedef void (*BufferInvalidateMappedRangeFunc)(const Buffer*, ptrdiff_t, size_t);
typedef MemoryPool* (*BufferGetMemoryPoolFunc)(const Buffer*);
typedef ptrdiff_t (*BufferGetMemoryOffsetFunc)(const Buffer*);
typedef size_t (*BufferGetSizeFunc)(const Buffer*);
typedef uint64_t (*BufferGetDebugIDFunc)(const Buffer*);
typedef void (*TextureBuilderSetDeviceFunc)(TextureBuilder*, Device*);
typedef void (*TextureBuilderSetDefaultsFunc)(TextureBuilder*);
typedef void (*TextureBuilderSetFlagsFunc)(TextureBuilder*, int);
typedef void (*TextureBuilderSetTargetFunc)(TextureBuilder*, TextureTarget::Enum);
typedef void (*TextureBuilderSetWidthFunc)(TextureBuilder*, int);
typedef void (*TextureBuilderSetHeightFunc)(TextureBuilder*, int);
typedef void (*TextureBuilderSetDepthFunc)(TextureBuilder*, int);
typedef void (*TextureBuilderSetSize1DFunc)(TextureBuilder*, int);
typedef void (*TextureBuilderSetSize2DFunc)(TextureBuilder*, int, int);
typedef void (*TextureBuilderSetSize3DFunc)(TextureBuilder*, int, int, int);
typedef void (*TextureBuilderSetLevelsFunc)(TextureBuilder*, int);
typedef void (*TextureBuilderSetFormatFunc)(TextureBuilder*, Format::Enum);
typedef void (*TextureBuilderSetSamplesFunc)(TextureBuilder*, int);
typedef void (*TextureBuilderSetSwizzleFunc)(TextureBuilder*, TextureSwizzle::Enum,
                                             TextureSwizzle::Enum, TextureSwizzle::Enum,
                                             TextureSwizzle::Enum);
typedef void (*TextureBuilderSetDepthStencilModeFunc)(TextureBuilder*,
                                                      TextureDepthStencilMode::Enum);
typedef size_t (*TextureBuilderGetStorageSizeFunc)(const TextureBuilder*);
typedef size_t (*TextureBuilderGetStorageAlignmentFunc)(const TextureBuilder*);
typedef void (*TextureBuilderSetStorageFunc)(TextureBuilder*, MemoryPool*, ptrdiff_t);
typedef void (*TextureBuilderSetPackagedTextureDataFunc)(TextureBuilder*, const void*);
typedef void (*TextureBuilderSetPackagedTextureLayoutFunc)(TextureBuilder*,
                                                           const PackagedTextureLayout*);
typedef void (*TextureBuilderSetStrideFunc)(TextureBuilder*, ptrdiff_t);
typedef void (*TextureBuilderSetGLTextureNameFunc)(TextureBuilder*, uint32_t);
typedef NVNstorageClass (*TextureBuilderGetStorageClassFunc)(const TextureBuilder*);
typedef const Device* (*TextureBuilderGetDeviceFunc)(const TextureBuilder*);
typedef int (*TextureBuilderGetFlagsFunc)(const TextureBuilder*);
typedef TextureTarget::Enum (*TextureBuilderGetTargetFunc)(const TextureBuilder*);
typedef int (*TextureBuilderGetWidthFunc)(const TextureBuilder*);
typedef int (*TextureBuilderGetHeightFunc)(const TextureBuilder*);
typedef int (*TextureBuilderGetDepthFunc)(const TextureBuilder*);
typedef int (*TextureBuilderGetLevelsFunc)(const TextureBuilder*);
typedef Format::Enum (*TextureBuilderGetFormatFunc)(const TextureBuilder*);
typedef int (*TextureBuilderGetSamplesFunc)(const TextureBuilder*);
typedef void (*TextureBuilderGetSwizzleFunc)(const TextureBuilder*, TextureSwizzle*,
                                             TextureSwizzle*, TextureSwizzle*, TextureSwizzle*);
typedef TextureDepthStencilMode::Enum (*TextureBuilderGetDepthStencilModeFunc)(
    const TextureBuilder*);
typedef const void* (*TextureBuilderGetPackagedTextureDataFunc)(const TextureBuilder*);
typedef NVNboolean (*TextureBuilderGetPackagedTextureLayoutFunc)(const TextureBuilder*,
                                                                 PackagedTextureLayout*);
typedef ptrdiff_t (*TextureBuilderGetStrideFunc)(const TextureBuilder*);
typedef void (*TextureBuilderGetSparseTileLayoutFunc)(const TextureBuilder*,
                                                      TextureSparseTileLayout*);
typedef uint32_t (*TextureBuilderGetGLTextureNameFunc)(const TextureBuilder*);
typedef size_t (*TextureBuilderGetZCullStorageSizeFunc)(const TextureBuilder*);
typedef MemoryPool* (*TextureBuilderGetMemoryPoolFunc)(const TextureBuilder*);
typedef ptrdiff_t (*TextureBuilderGetMemoryOffsetFunc)(const TextureBuilder*);
typedef void (*TextureViewSetDefaultsFunc)(TextureView*);
typedef void (*TextureViewSetLevelsFunc)(TextureView*, int, int);
typedef void (*TextureViewSetLayersFunc)(TextureView*, int, int);
typedef void (*TextureViewSetFormatFunc)(TextureView*, Format::Enum);
typedef void (*TextureViewSetSwizzleFunc)(TextureView*, TextureSwizzle::Enum, TextureSwizzle::Enum,
                                          TextureSwizzle::Enum, TextureSwizzle::Enum);
typedef void (*TextureViewSetDepthStencilModeFunc)(TextureView*, TextureDepthStencilMode::Enum);
typedef void (*TextureViewSetTargetFunc)(TextureView*, TextureTarget::Enum);
typedef NVNboolean (*TextureViewGetLevelsFunc)(const TextureView*, int*, int*);
typedef NVNboolean (*TextureViewGetLayersFunc)(const TextureView*, int*, int*);
typedef NVNboolean (*TextureViewGetFormatFunc)(const TextureView*, Format*);
typedef NVNboolean (*TextureViewGetSwizzleFunc)(const TextureView*, TextureSwizzle*,
                                                TextureSwizzle*, TextureSwizzle*, TextureSwizzle*);
typedef NVNboolean (*TextureViewGetDepthStencilModeFunc)(const TextureView*,
                                                         TextureDepthStencilMode*);
typedef NVNboolean (*TextureViewGetTargetFunc)(const TextureView*, TextureTarget*);
typedef NVNboolean (*TextureViewCompareFunc)(const TextureView*, const TextureView*);
typedef NVNboolean (*TextureInitializeFunc)(Texture*, const TextureBuilder*);
typedef size_t (*TextureGetZCullStorageSizeFunc)(const Texture*);
typedef void (*TextureFinalizeFunc)(Texture*);
typedef void (*TextureSetDebugLabelFunc)(Texture*, const char*);
typedef NVNstorageClass (*TextureGetStorageClassFunc)(const Texture*);
typedef ptrdiff_t (*TextureGetViewOffsetFunc)(const Texture*, const TextureView*);
typedef int (*TextureGetFlagsFunc)(const Texture*);
typedef TextureTarget::Enum (*TextureGetTargetFunc)(const Texture*);
typedef int (*TextureGetWidthFunc)(const Texture*);
typedef int (*TextureGetHeightFunc)(const Texture*);
typedef int (*TextureGetDepthFunc)(const Texture*);
typedef int (*TextureGetLevelsFunc)(const Texture*);
typedef Format::Enum (*TextureGetFormatFunc)(const Texture*);
typedef int (*TextureGetSamplesFunc)(const Texture*);
typedef void (*TextureGetSwizzleFunc)(const Texture*, TextureSwizzle*, TextureSwizzle*,
                                      TextureSwizzle*, TextureSwizzle*);
typedef TextureDepthStencilMode::Enum (*TextureGetDepthStencilModeFunc)(const Texture*);
typedef ptrdiff_t (*TextureGetStrideFunc)(const Texture*);
typedef TextureAddress (*TextureGetTextureAddressFunc)(const Texture*);
typedef void (*TextureGetSparseTileLayoutFunc)(const Texture*, TextureSparseTileLayout*);
typedef void (*TextureWriteTexelsFunc)(const Texture*, const TextureView*, const CopyRegion*,
                                       const void*);
typedef void (*TextureWriteTexelsStridedFunc)(const Texture*, const TextureView*, const CopyRegion*,
                                              const void*, ptrdiff_t, ptrdiff_t);
typedef void (*TextureReadTexelsFunc)(const Texture*, const TextureView*, const CopyRegion*, void*);
typedef void (*TextureReadTexelsStridedFunc)(const Texture*, const TextureView*, const CopyRegion*,
                                             void*, ptrdiff_t, ptrdiff_t);
typedef void (*TextureFlushTexelsFunc)(const Texture*, const TextureView*, const CopyRegion*);
typedef void (*TextureInvalidateTexelsFunc)(const Texture*, const TextureView*, const CopyRegion*);
typedef MemoryPool* (*TextureGetMemoryPoolFunc)(const Texture*);
typedef ptrdiff_t (*TextureGetMemoryOffsetFunc)(const Texture*);
typedef int (*TextureGetStorageSizeFunc)(const Texture*);
typedef NVNboolean (*TextureCompareFunc)(const Texture*, const Texture*);
typedef uint64_t (*TextureGetDebugIDFunc)(const Texture*);
typedef void (*SamplerBuilderSetDeviceFunc)(SamplerBuilder*, Device*);
typedef void (*SamplerBuilderSetDefaultsFunc)(SamplerBuilder*);
typedef void (*SamplerBuilderSetMinMagFilterFunc)(SamplerBuilder*, MinFilter::Enum,
                                                  MagFilter::Enum);
typedef void (*SamplerBuilderSetWrapModeFunc)(SamplerBuilder*, WrapMode::Enum, WrapMode::Enum,
                                              WrapMode::Enum);
typedef void (*SamplerBuilderSetLodClampFunc)(SamplerBuilder*, float, float);
typedef void (*SamplerBuilderSetLodBiasFunc)(SamplerBuilder*, float);
typedef void (*SamplerBuilderSetCompareFunc)(SamplerBuilder*, CompareMode::Enum, CompareFunc::Enum);
typedef void (*SamplerBuilderSetBorderColorFunc)(SamplerBuilder*, const float*);
typedef void (*SamplerBuilderSetBorderColoriFunc)(SamplerBuilder*, const int*);
typedef void (*SamplerBuilderSetBorderColoruiFunc)(SamplerBuilder*, const uint32_t*);
typedef void (*SamplerBuilderSetMaxAnisotropyFunc)(SamplerBuilder*, float);
typedef void (*SamplerBuilderSetReductionFilterFunc)(SamplerBuilder*, SamplerReduction::Enum);
typedef void (*SamplerBuilderSetLodSnapFunc)(SamplerBuilder*, float);
typedef const Device* (*SamplerBuilderGetDeviceFunc)(const SamplerBuilder*);
typedef void (*SamplerBuilderGetMinMagFilterFunc)(const SamplerBuilder*, MinFilter*, MagFilter*);
typedef void (*SamplerBuilderGetWrapModeFunc)(const SamplerBuilder*, WrapMode*, WrapMode*,
                                              WrapMode*);
typedef void (*SamplerBuilderGetLodClampFunc)(const SamplerBuilder*, float*, float*);
typedef float (*SamplerBuilderGetLodBiasFunc)(const SamplerBuilder*);
typedef void (*SamplerBuilderGetCompareFunc)(const SamplerBuilder*, CompareMode*, CompareFunc*);
typedef void (*SamplerBuilderGetBorderColorFunc)(const SamplerBuilder*, float*);
typedef void (*SamplerBuilderGetBorderColoriFunc)(const SamplerBuilder*, int*);
typedef void (*SamplerBuilderGetBorderColoruiFunc)(const SamplerBuilder*, uint32_t*);
typedef float (*SamplerBuilderGetMaxAnisotropyFunc)(const SamplerBuilder*);
typedef SamplerReduction::Enum (*SamplerBuilderGetReductionFilterFunc)(const SamplerBuilder*);
typedef float (*SamplerBuilderGetLodSnapFunc)(const SamplerBuilder*);
typedef NVNboolean (*SamplerInitializeFunc)(Sampler*, const SamplerBuilder*);
typedef void (*SamplerFinalizeFunc)(Sampler*);
typedef void (*SamplerSetDebugLabelFunc)(Sampler*, const char*);
typedef void (*SamplerGetMinMagFilterFunc)(const Sampler*, MinFilter*, MagFilter*);
typedef void (*SamplerGetWrapModeFunc)(const Sampler*, WrapMode*, WrapMode*, WrapMode*);
typedef void (*SamplerGetLodClampFunc)(const Sampler*, float*, float*);
typedef float (*SamplerGetLodBiasFunc)(const Sampler*);
typedef void (*SamplerGetCompareFunc)(const Sampler*, CompareMode*, CompareFunc*);
typedef void (*SamplerGetBorderColorFunc)(const Sampler*, float*);
typedef void (*SamplerGetBorderColoriFunc)(const Sampler*, int*);
typedef void (*SamplerGetBorderColoruiFunc)(const Sampler*, uint32_t*);
typedef float (*SamplerGetMaxAnisotropyFunc)(const Sampler*);
typedef SamplerReduction::Enum (*SamplerGetReductionFilterFunc)(const Sampler*);
typedef NVNboolean (*SamplerCompareFunc)(const Sampler*, const Sampler*);
typedef uint64_t (*SamplerGetDebugIDFunc)(const Sampler*);
typedef void (*BlendStateSetDefaultsFunc)(BlendState*);
typedef void (*BlendStateSetBlendTargetFunc)(BlendState*, int);
typedef void (*BlendStateSetBlendFuncFunc)(BlendState*, BlendFunc::Enum, BlendFunc::Enum,
                                           BlendFunc::Enum, BlendFunc::Enum);
typedef void (*BlendStateSetBlendEquationFunc)(BlendState*, BlendEquation::Enum,
                                               BlendEquation::Enum);
typedef void (*BlendStateSetAdvancedModeFunc)(BlendState*, BlendAdvancedMode::Enum);
typedef void (*BlendStateSetAdvancedOverlapFunc)(BlendState*, BlendAdvancedOverlap::Enum);
typedef void (*BlendStateSetAdvancedPremultipliedSrcFunc)(BlendState*, NVNboolean);
typedef void (*BlendStateSetAdvancedNormalizedDstFunc)(BlendState*, NVNboolean);
typedef int (*BlendStateGetBlendTargetFunc)(const BlendState*);
typedef void (*BlendStateGetBlendFuncFunc)(const BlendState*, BlendFunc*, BlendFunc*, BlendFunc*,
                                           BlendFunc*);
typedef void (*BlendStateGetBlendEquationFunc)(const BlendState*, BlendEquation*, BlendEquation*);
typedef BlendAdvancedMode::Enum (*BlendStateGetAdvancedModeFunc)(const BlendState*);
typedef BlendAdvancedOverlap::Enum (*BlendStateGetAdvancedOverlapFunc)(const BlendState*);
typedef NVNboolean (*BlendStateGetAdvancedPremultipliedSrcFunc)(const BlendState*);
typedef NVNboolean (*BlendStateGetAdvancedNormalizedDstFunc)(const BlendState*);
typedef void (*ColorStateSetDefaultsFunc)(ColorState*);
typedef void (*ColorStateSetBlendEnableFunc)(ColorState*, int, NVNboolean);
typedef void (*ColorStateSetLogicOpFunc)(ColorState*, LogicOp::Enum);
typedef void (*ColorStateSetAlphaTestFunc)(ColorState*, AlphaFunc::Enum);
typedef NVNboolean (*ColorStateGetBlendEnableFunc)(const ColorState*, int);
typedef LogicOp::Enum (*ColorStateGetLogicOpFunc)(const ColorState*);
typedef AlphaFunc::Enum (*ColorStateGetAlphaTestFunc)(const ColorState*);
typedef void (*ChannelMaskStateSetDefaultsFunc)(ChannelMaskState*);
typedef void (*ChannelMaskStateSetChannelMaskFunc)(ChannelMaskState*, int, NVNboolean, NVNboolean,
                                                   NVNboolean, NVNboolean);
typedef void (*ChannelMaskStateGetChannelMaskFunc)(const ChannelMaskState*, int, NVNboolean*,
                                                   NVNboolean*, NVNboolean*, NVNboolean*);
typedef void (*MultisampleStateSetDefaultsFunc)(MultisampleState*);
typedef void (*MultisampleStateSetMultisampleEnableFunc)(MultisampleState*, NVNboolean);
typedef void (*MultisampleStateSetSamplesFunc)(MultisampleState*, int);
typedef void (*MultisampleStateSetAlphaToCoverageEnableFunc)(MultisampleState*, NVNboolean);
typedef void (*MultisampleStateSetAlphaToCoverageDitherFunc)(MultisampleState*, NVNboolean);
typedef NVNboolean (*MultisampleStateGetMultisampleEnableFunc)(const MultisampleState*);
typedef int (*MultisampleStateGetSamplesFunc)(const MultisampleState*);
typedef NVNboolean (*MultisampleStateGetAlphaToCoverageEnableFunc)(const MultisampleState*);
typedef NVNboolean (*MultisampleStateGetAlphaToCoverageDitherFunc)(const MultisampleState*);
typedef void (*MultisampleStateSetRasterSamplesFunc)(MultisampleState*, int);
typedef int (*MultisampleStateGetRasterSamplesFunc)(MultisampleState*);
typedef void (*MultisampleStateSetCoverageModulationModeFunc)(MultisampleState*,
                                                              CoverageModulationMode::Enum);
typedef CoverageModulationMode::Enum (*MultisampleStateGetCoverageModulationModeFunc)(
    const MultisampleState*);
typedef void (*MultisampleStateSetCoverageToColorEnableFunc)(MultisampleState*, NVNboolean);
typedef NVNboolean (*MultisampleStateGetCoverageToColorEnableFunc)(const MultisampleState*);
typedef void (*MultisampleStateSetCoverageToColorOutputFunc)(MultisampleState*, int);
typedef int (*MultisampleStateGetCoverageToColorOutputFunc)(const MultisampleState*);
typedef void (*MultisampleStateSetSampleLocationsEnableFunc)(MultisampleState*, NVNboolean);
typedef NVNboolean (*MultisampleStateGetSampleLocationsEnableFunc)(const MultisampleState*);
typedef void (*MultisampleStateGetSampleLocationsGridFunc)(MultisampleState*, int*, int*);
typedef void (*MultisampleStateSetSampleLocationsGridEnableFunc)(MultisampleState*, NVNboolean);
typedef NVNboolean (*MultisampleStateGetSampleLocationsGridEnableFunc)(const MultisampleState*);
typedef void (*MultisampleStateSetSampleLocationsFunc)(MultisampleState*, int, int, const float*);
typedef void (*PolygonStateSetDefaultsFunc)(PolygonState*);
typedef void (*PolygonStateSetCullFaceFunc)(PolygonState*, Face::Enum);
typedef void (*PolygonStateSetFrontFaceFunc)(PolygonState*, FrontFace::Enum);
typedef void (*PolygonStateSetPolygonModeFunc)(PolygonState*, PolygonMode::Enum);
typedef void (*PolygonStateSetPolygonOffsetEnablesFunc)(PolygonState*, int);
typedef Face::Enum (*PolygonStateGetCullFaceFunc)(const PolygonState*);
typedef FrontFace::Enum (*PolygonStateGetFrontFaceFunc)(const PolygonState*);
typedef PolygonMode::Enum (*PolygonStateGetPolygonModeFunc)(const PolygonState*);
typedef int (*PolygonStateGetPolygonOffsetEnablesFunc)(const PolygonState*);
typedef void (*DepthStencilStateSetDefaultsFunc)(DepthStencilState*);
typedef void (*DepthStencilStateSetDepthTestEnableFunc)(DepthStencilState*, NVNboolean);
typedef void (*DepthStencilStateSetDepthWriteEnableFunc)(DepthStencilState*, NVNboolean);
typedef void (*DepthStencilStateSetDepthFuncFunc)(DepthStencilState*, DepthFunc::Enum);
typedef void (*DepthStencilStateSetStencilTestEnableFunc)(DepthStencilState*, NVNboolean);
typedef void (*DepthStencilStateSetStencilFuncFunc)(DepthStencilState*, Face::Enum,
                                                    StencilFunc::Enum);
typedef void (*DepthStencilStateSetStencilOpFunc)(DepthStencilState*, Face::Enum, StencilOp::Enum,
                                                  StencilOp::Enum, StencilOp::Enum);
typedef NVNboolean (*DepthStencilStateGetDepthTestEnableFunc)(const DepthStencilState*);
typedef NVNboolean (*DepthStencilStateGetDepthWriteEnableFunc)(const DepthStencilState*);
typedef DepthFunc::Enum (*DepthStencilStateGetDepthFuncFunc)(const DepthStencilState*);
typedef NVNboolean (*DepthStencilStateGetStencilTestEnableFunc)(const DepthStencilState*);
typedef StencilFunc::Enum (*DepthStencilStateGetStencilFuncFunc)(const DepthStencilState*,
                                                                 Face::Enum);
typedef void (*DepthStencilStateGetStencilOpFunc)(const DepthStencilState*, Face::Enum, StencilOp*,
                                                  StencilOp*, StencilOp*);
typedef void (*VertexAttribStateSetDefaultsFunc)(VertexAttribState*);
typedef void (*VertexAttribStateSetFormatFunc)(VertexAttribState*, Format::Enum, ptrdiff_t);
typedef void (*VertexAttribStateSetStreamIndexFunc)(VertexAttribState*, int);
typedef void (*VertexAttribStateGetFormatFunc)(const VertexAttribState*, Format*, ptrdiff_t*);
typedef int (*VertexAttribStateGetStreamIndexFunc)(const VertexAttribState*);
typedef void (*VertexStreamStateSetDefaultsFunc)(VertexStreamState*);
typedef void (*VertexStreamStateSetStrideFunc)(VertexStreamState*, ptrdiff_t);
typedef void (*VertexStreamStateSetDivisorFunc)(VertexStreamState*, int);
typedef ptrdiff_t (*VertexStreamStateGetStrideFunc)(const VertexStreamState*);
typedef int (*VertexStreamStateGetDivisorFunc)(const VertexStreamState*);
typedef NVNboolean (*CommandBufferInitializeFunc)(CommandBuffer*, Device*);
typedef void (*CommandBufferFinalizeFunc)(CommandBuffer*);
typedef void (*CommandBufferSetDebugLabelFunc)(CommandBuffer*, const char*);
typedef void (*CommandBufferSetMemoryCallbackFunc)(CommandBuffer*, CommandBufferMemoryCallbackFunc);
typedef void (*CommandBufferSetMemoryCallbackDataFunc)(CommandBuffer*, void*);
typedef void (*CommandBufferAddCommandMemoryFunc)(CommandBuffer*, const MemoryPool*, ptrdiff_t,
                                                  size_t);
typedef void (*CommandBufferAddControlMemoryFunc)(CommandBuffer*, void*, size_t);
typedef size_t (*CommandBufferGetCommandMemorySizeFunc)(const CommandBuffer*);
typedef size_t (*CommandBufferGetCommandMemoryUsedFunc)(const CommandBuffer*);
typedef size_t (*CommandBufferGetCommandMemoryFreeFunc)(const CommandBuffer*);
typedef size_t (*CommandBufferGetControlMemorySizeFunc)(const CommandBuffer*);
typedef size_t (*CommandBufferGetControlMemoryUsedFunc)(const CommandBuffer*);
typedef size_t (*CommandBufferGetControlMemoryFreeFunc)(const CommandBuffer*);
typedef void (*CommandBufferBeginRecordingFunc)(CommandBuffer*);
typedef CommandHandle (*CommandBufferEndRecordingFunc)(CommandBuffer*);
typedef void (*CommandBufferCallCommandsFunc)(CommandBuffer*, int, const CommandHandle*);
typedef void (*CommandBufferCopyCommandsFunc)(CommandBuffer*, int, const CommandHandle*);
typedef void (*CommandBufferBindBlendStateFunc)(CommandBuffer*, const BlendState*);
typedef void (*CommandBufferBindChannelMaskStateFunc)(CommandBuffer*, const ChannelMaskState*);
typedef void (*CommandBufferBindColorStateFunc)(CommandBuffer*, const ColorState*);
typedef void (*CommandBufferBindMultisampleStateFunc)(CommandBuffer*, const MultisampleState*);
typedef void (*CommandBufferBindPolygonStateFunc)(CommandBuffer*, const PolygonState*);
typedef void (*CommandBufferBindDepthStencilStateFunc)(CommandBuffer*, const DepthStencilState*);
typedef void (*CommandBufferBindVertexAttribStateFunc)(CommandBuffer*, int,
                                                       const VertexAttribState*);
typedef void (*CommandBufferBindVertexStreamStateFunc)(CommandBuffer*, int,
                                                       const VertexStreamState*);
typedef void (*CommandBufferBindProgramFunc)(CommandBuffer*, const Program*, int);
typedef void (*CommandBufferBindVertexBufferFunc)(CommandBuffer*, int, BufferAddress, size_t);
typedef void (*CommandBufferBindVertexBuffersFunc)(CommandBuffer*, int, int, const BufferRange*);
typedef void (*CommandBufferBindUniformBufferFunc)(CommandBuffer*, ShaderStage::Enum, int,
                                                   BufferAddress, size_t);
typedef void (*CommandBufferBindUniformBuffersFunc)(CommandBuffer*, ShaderStage::Enum, int, int,
                                                    const BufferRange*);
typedef void (*CommandBufferBindTransformFeedbackBufferFunc)(CommandBuffer*, int, BufferAddress,
                                                             size_t);
typedef void (*CommandBufferBindTransformFeedbackBuffersFunc)(CommandBuffer*, int, int,
                                                              const BufferRange*);
typedef void (*CommandBufferBindStorageBufferFunc)(CommandBuffer*, ShaderStage::Enum, int,
                                                   BufferAddress, size_t);
typedef void (*CommandBufferBindStorageBuffersFunc)(CommandBuffer*, ShaderStage::Enum, int, int,
                                                    const BufferRange*);
typedef void (*CommandBufferBindTextureFunc)(CommandBuffer*, ShaderStage::Enum, int, TextureHandle);
typedef void (*CommandBufferBindTexturesFunc)(CommandBuffer*, ShaderStage::Enum, int, int,
                                              const TextureHandle*);
typedef void (*CommandBufferBindImageFunc)(CommandBuffer*, ShaderStage::Enum, int, ImageHandle);
typedef void (*CommandBufferBindImagesFunc)(CommandBuffer*, ShaderStage::Enum, int, int,
                                            const ImageHandle*);
typedef void (*CommandBufferSetPatchSizeFunc)(CommandBuffer*, int);
typedef void (*CommandBufferSetInnerTessellationLevelsFunc)(CommandBuffer*, const float*);
typedef void (*CommandBufferSetOuterTessellationLevelsFunc)(CommandBuffer*, const float*);
typedef void (*CommandBufferSetPrimitiveRestartFunc)(CommandBuffer*, NVNboolean, int);
typedef void (*CommandBufferBeginTransformFeedbackFunc)(CommandBuffer*, BufferAddress);
typedef void (*CommandBufferEndTransformFeedbackFunc)(CommandBuffer*, BufferAddress);
typedef void (*CommandBufferPauseTransformFeedbackFunc)(CommandBuffer*, BufferAddress);
typedef void (*CommandBufferResumeTransformFeedbackFunc)(CommandBuffer*, BufferAddress);
typedef void (*CommandBufferDrawTransformFeedbackFunc)(CommandBuffer*, DrawPrimitive::Enum,
                                                       BufferAddress);
typedef void (*CommandBufferDrawArraysFunc)(CommandBuffer*, DrawPrimitive::Enum, int, int);
typedef void (*CommandBufferDrawElementsFunc)(CommandBuffer*, DrawPrimitive::Enum, IndexType::Enum,
                                              int, BufferAddress);
typedef void (*CommandBufferDrawElementsBaseVertexFunc)(CommandBuffer*, DrawPrimitive::Enum,
                                                        IndexType::Enum, int, BufferAddress, int);
typedef void (*CommandBufferDrawArraysInstancedFunc)(CommandBuffer*, DrawPrimitive::Enum, int, int,
                                                     int, int);
typedef void (*CommandBufferDrawElementsInstancedFunc)(CommandBuffer*, DrawPrimitive::Enum,
                                                       IndexType::Enum, int, BufferAddress, int,
                                                       int, int);
typedef void (*CommandBufferDrawArraysIndirectFunc)(CommandBuffer*, DrawPrimitive::Enum,
                                                    BufferAddress);
typedef void (*CommandBufferDrawElementsIndirectFunc)(CommandBuffer*, DrawPrimitive::Enum,
                                                      IndexType::Enum, BufferAddress,
                                                      BufferAddress);
typedef void (*CommandBufferMultiDrawArraysIndirectCountFunc)(CommandBuffer*, DrawPrimitive::Enum,
                                                              BufferAddress, BufferAddress, int,
                                                              ptrdiff_t);
typedef void (*CommandBufferMultiDrawElementsIndirectCountFunc)(CommandBuffer*, DrawPrimitive::Enum,
                                                                IndexType::Enum, BufferAddress,
                                                                BufferAddress, BufferAddress, int,
                                                                ptrdiff_t);
typedef void (*CommandBufferClearColorFunc)(CommandBuffer*, int, const float*, int);
typedef void (*CommandBufferClearColoriFunc)(CommandBuffer*, int, const int*, int);
typedef void (*CommandBufferClearColoruiFunc)(CommandBuffer*, int, const uint32_t*, int);
typedef void (*CommandBufferClearDepthStencilFunc)(CommandBuffer*, float, NVNboolean, int, int);
typedef void (*CommandBufferDispatchComputeFunc)(CommandBuffer*, int, int, int);
typedef void (*CommandBufferDispatchComputeIndirectFunc)(CommandBuffer*, BufferAddress);
typedef void (*CommandBufferSetViewportFunc)(CommandBuffer*, int, int, int, int);
typedef void (*CommandBufferSetViewportsFunc)(CommandBuffer*, int, int, const float*);
typedef void (*CommandBufferSetViewportSwizzlesFunc)(CommandBuffer*, int, int,
                                                     const ViewportSwizzle*);
typedef void (*CommandBufferSetScissorFunc)(CommandBuffer*, int, int, int, int);
typedef void (*CommandBufferSetScissorsFunc)(CommandBuffer*, int, int, const int*);
typedef void (*CommandBufferSetDepthRangeFunc)(CommandBuffer*, float, float);
typedef void (*CommandBufferSetDepthBoundsFunc)(CommandBuffer*, NVNboolean, float, float);
typedef void (*CommandBufferSetDepthRangesFunc)(CommandBuffer*, int, int, const float*);
typedef void (*CommandBufferSetTiledCacheActionFunc)(CommandBuffer*, TiledCacheAction::Enum);
typedef void (*CommandBufferSetTiledCacheTileSizeFunc)(CommandBuffer*, int, int);
typedef void (*CommandBufferBindSeparateTextureFunc)(CommandBuffer*, ShaderStage::Enum, int,
                                                     SeparateTextureHandle);
typedef void (*CommandBufferBindSeparateSamplerFunc)(CommandBuffer*, ShaderStage::Enum, int,
                                                     SeparateSamplerHandle);
typedef void (*CommandBufferBindSeparateTexturesFunc)(CommandBuffer*, ShaderStage::Enum, int, int,
                                                      const SeparateTextureHandle*);
typedef void (*CommandBufferBindSeparateSamplersFunc)(CommandBuffer*, ShaderStage::Enum, int, int,
                                                      const SeparateSamplerHandle*);
typedef void (*CommandBufferSetStencilValueMaskFunc)(CommandBuffer*, Face::Enum, int);
typedef void (*CommandBufferSetStencilMaskFunc)(CommandBuffer*, Face::Enum, int);
typedef void (*CommandBufferSetStencilRefFunc)(CommandBuffer*, Face::Enum, int);
typedef void (*CommandBufferSetBlendColorFunc)(CommandBuffer*, const float*);
typedef void (*CommandBufferSetPointSizeFunc)(CommandBuffer*, float);
typedef void (*CommandBufferSetLineWidthFunc)(CommandBuffer*, float);
typedef void (*CommandBufferSetPolygonOffsetClampFunc)(CommandBuffer*, float, float, float);
typedef void (*CommandBufferSetAlphaRefFunc)(CommandBuffer*, float);
typedef void (*CommandBufferSetSampleMaskFunc)(CommandBuffer*, int);
typedef void (*CommandBufferSetRasterizerDiscardFunc)(CommandBuffer*, NVNboolean);
typedef void (*CommandBufferSetDepthClampFunc)(CommandBuffer*, NVNboolean);
typedef void (*CommandBufferSetConservativeRasterEnableFunc)(CommandBuffer*, NVNboolean);
typedef void (*CommandBufferSetConservativeRasterDilateFunc)(CommandBuffer*, float);
typedef void (*CommandBufferSetSubpixelPrecisionBiasFunc)(CommandBuffer*, int, int);
typedef void (*CommandBufferCopyBufferToTextureFunc)(CommandBuffer*, BufferAddress, const Texture*,
                                                     const TextureView*, const CopyRegion*, int);
typedef void (*CommandBufferCopyTextureToBufferFunc)(CommandBuffer*, const Texture*,
                                                     const TextureView*, const CopyRegion*,
                                                     BufferAddress, int);
typedef void (*CommandBufferCopyTextureToTextureFunc)(CommandBuffer*, const Texture*,
                                                      const TextureView*, const CopyRegion*,
                                                      const Texture*, const TextureView*,
                                                      const CopyRegion*, int);
typedef void (*CommandBufferCopyBufferToBufferFunc)(CommandBuffer*, BufferAddress, BufferAddress,
                                                    size_t, int);
typedef void (*CommandBufferClearBufferFunc)(CommandBuffer*, BufferAddress, size_t, uint32_t);
typedef void (*CommandBufferClearTextureFunc)(CommandBuffer*, const Texture*, const TextureView*,
                                              const CopyRegion*, const float*, int);
typedef void (*CommandBufferClearTextureiFunc)(CommandBuffer*, const Texture*, const TextureView*,
                                               const CopyRegion*, const int*, int);
typedef void (*CommandBufferClearTextureuiFunc)(CommandBuffer*, const Texture*, const TextureView*,
                                                const CopyRegion*, const uint32_t*, int);
typedef void (*CommandBufferUpdateUniformBufferFunc)(CommandBuffer*, BufferAddress, size_t,
                                                     ptrdiff_t, size_t, const void*);
typedef void (*CommandBufferReportCounterFunc)(CommandBuffer*, CounterType::Enum, BufferAddress);
typedef void (*CommandBufferResetCounterFunc)(CommandBuffer*, CounterType::Enum);
typedef void (*CommandBufferReportValueFunc)(CommandBuffer*, uint32_t, BufferAddress);
typedef void (*CommandBufferSetRenderEnableFunc)(CommandBuffer*, NVNboolean);
typedef void (*CommandBufferSetRenderEnableConditionalFunc)(CommandBuffer*,
                                                            ConditionalRenderMode::Enum,
                                                            BufferAddress);
typedef void (*CommandBufferSetRenderTargetsFunc)(CommandBuffer*, int, const Texture* const*,
                                                  const TextureView* const*, const Texture*,
                                                  const TextureView*);
typedef void (*CommandBufferDiscardColorFunc)(CommandBuffer*, int);
typedef void (*CommandBufferDiscardDepthStencilFunc)(CommandBuffer*);
typedef void (*CommandBufferDownsampleFunc)(CommandBuffer*, const Texture*, const Texture*);
typedef void (*CommandBufferTiledDownsampleFunc)(CommandBuffer*, const Texture*, const Texture*);
typedef void (*CommandBufferDownsampleTextureViewFunc)(CommandBuffer*, const Texture*,
                                                       const TextureView*, const Texture*,
                                                       const TextureView*);
typedef void (*CommandBufferTiledDownsampleTextureViewFunc)(CommandBuffer*, const Texture*,
                                                            const TextureView*, const Texture*,
                                                            const TextureView*);
typedef void (*CommandBufferBarrierFunc)(CommandBuffer*, int);
typedef void (*CommandBufferWaitSyncFunc)(CommandBuffer*, const Sync*);
typedef void (*CommandBufferFenceSyncFunc)(CommandBuffer*, Sync*, SyncCondition::Enum, int);
typedef void (*CommandBufferSetTexturePoolFunc)(CommandBuffer*, const TexturePool*);
typedef void (*CommandBufferSetSamplerPoolFunc)(CommandBuffer*, const SamplerPool*);
typedef void (*CommandBufferSetShaderScratchMemoryFunc)(CommandBuffer*, const MemoryPool*,
                                                        ptrdiff_t, size_t);
typedef void (*CommandBufferSaveZCullDataFunc)(CommandBuffer*, BufferAddress, size_t);
typedef void (*CommandBufferRestoreZCullDataFunc)(CommandBuffer*, BufferAddress, size_t);
typedef void (*CommandBufferSetCopyRowStrideFunc)(CommandBuffer*, ptrdiff_t);
typedef void (*CommandBufferSetCopyImageStrideFunc)(CommandBuffer*, ptrdiff_t);
typedef ptrdiff_t (*CommandBufferGetCopyRowStrideFunc)(const CommandBuffer*);
typedef ptrdiff_t (*CommandBufferGetCopyImageStrideFunc)(const CommandBuffer*);
typedef void (*CommandBufferDrawTextureFunc)(CommandBuffer*, TextureHandle,
                                             const DrawTextureRegion*, const DrawTextureRegion*);
typedef NVNboolean (*ProgramSetSubroutineLinkageFunc)(Program*, int,
                                                      const NVNsubroutineLinkageMapPtr*);
typedef void (*CommandBufferSetProgramSubroutinesFunc)(CommandBuffer*, Program*, ShaderStage::Enum,
                                                       const int, const int, const int*);
typedef void (*CommandBufferBindCoverageModulationTableFunc)(CommandBuffer*, const float*);
typedef void (*CommandBufferResolveDepthBufferFunc)(CommandBuffer*);
typedef void (*CommandBufferSetColorReductionEnableFunc)(CommandBuffer*, NVNboolean);
typedef void (*CommandBufferSetColorReductionThresholdsFunc)(CommandBuffer*, FormatClass::Enum, int,
                                                             int);
typedef void (*CommandBufferPushDebugGroupStaticFunc)(CommandBuffer*, uint32_t, const char*);
typedef void (*CommandBufferPushDebugGroupDynamicFunc)(CommandBuffer*, uint32_t, const char*);
typedef void (*CommandBufferPushDebugGroupFunc)(CommandBuffer*, const char*);
typedef void (*CommandBufferPopDebugGroupFunc)(CommandBuffer*);
typedef void (*CommandBufferPopDebugGroupIdFunc)(CommandBuffer*, uint32_t);
typedef void (*CommandBufferInsertDebugMarkerStaticFunc)(CommandBuffer*, uint32_t, const char*);
typedef void (*CommandBufferInsertDebugMarkerDynamicFunc)(CommandBuffer*, uint32_t, const char*);
typedef void (*CommandBufferInsertDebugMarkerFunc)(CommandBuffer*, const char*);
typedef CommandBufferMemoryCallbackFunc (*CommandBufferGetMemoryCallbackFunc)(const CommandBuffer*);
typedef void* (*CommandBufferGetMemoryCallbackDataFunc)(const CommandBuffer*);
typedef NVNboolean (*CommandBufferIsRecordingFunc)(const CommandBuffer*);
typedef NVNboolean (*SyncInitializeFunc)(Sync*, Device*);
typedef void (*SyncFinalizeFunc)(Sync*);
typedef void (*SyncSetDebugLabelFunc)(Sync*, const char*);
typedef void (*QueueFenceSyncFunc)(Queue*, Sync*, SyncCondition::Enum, int);
typedef SyncWaitResult::Enum (*SyncWaitFunc)(const Sync*, uint64_t);
typedef NVNboolean (*QueueWaitSyncFunc)(Queue*, const Sync*);
typedef void (*EventBuilderSetDefaultsFunc)(EventBuilder*);
typedef void (*EventBuilderSetStorageFunc)(EventBuilder*, const MemoryPool*, int64_t);
typedef const MemoryPool* (*EventBuilderGetStorageFunc)(const EventBuilder*, int64_t*);
typedef NVNboolean (*EventInitializeFunc)(Event*, const EventBuilder*);
typedef void (*EventFinalizeFunc)(Event*);
typedef uint32_t (*EventGetValueFunc)(const Event*);
typedef void (*EventSignalFunc)(Event*, EventSignalMode::Enum, uint32_t);
typedef void (*CommandBufferWaitEventFunc)(CommandBuffer*, const Event*, EventWaitMode::Enum,
                                           uint32_t);
typedef void (*CommandBufferSignalEventFunc)(CommandBuffer*, const Event*, EventSignalMode::Enum,
                                             EventSignalLocation::Enum, int, uint32_t);
typedef void (*CommandBufferSetStencilCullCriteriaFunc)(CommandBuffer*, StencilFunc::Enum, int,
                                                        int);
}  // namespace nvn
